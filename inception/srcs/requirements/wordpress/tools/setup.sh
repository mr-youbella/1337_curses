#!/bin/bash
set -eu

: "${DOMAIN_NAME:?DOMAIN_NAME is required}"
: "${MYSQL_DATABASE:?MYSQL_DATABASE is required}"
: "${USER:?USER is required}"
: "${PASSWORD:?PASSWORD is required}"

cd /var/www/html
files_created=false

if ! command -v wp >/dev/null 2>&1; then
	curl -fsSL "https://github.com/wp-cli/wp-cli/releases/download/v${WP_CLI_VERSION:-2.12.0}/wp-cli-${WP_CLI_VERSION:-2.12.0}.phar" -o /usr/local/bin/wp
	chmod +x /usr/local/bin/wp
fi

if [ ! -f "wp-load.php" ]; then
	echo "Downloading WordPress..."

	wp core download \
		--version="${WORDPRESS_VERSION:-7.1.2}" \
		--allow-root
	files_created=true
fi

if [ ! -f "wp-config.php" ]; then
	wp config create \
		--dbname="${MYSQL_DATABASE}" \
		--dbuser="${USER}" \
		--dbpass="${PASSWORD}" \
		--dbhost=mariadb \
		--skip-check \
		--allow-root

	# Bonus Redis
	wp config set WP_REDIS_HOST redis --allow-root
	wp config set WP_REDIS_PORT 6379 --raw --allow-root
	files_created=true
fi

database_ready=false
for attempt in $(seq 1 30); do
	if mysql -h mariadb -u"${USER}" -p"${PASSWORD}" -e "SELECT 1;" >/dev/null 2>&1; then
		database_ready=true
		break
	fi
	echo "Waiting for MariaDB auth (${attempt}/30)..."
	sleep 2
done

if [ "$database_ready" != true ]; then
	echo "MariaDB did not become available in time." >&2
	exit 1
fi

wp_admin_email="${WP_ADMIN_EMAIL:-admin@${DOMAIN_NAME}}"

if ! wp core is-installed --allow-root; then
	wp core install \
		--url="https://${DOMAIN_NAME}" \
		--title="Inception" \
		--admin_user="${USER}" \
		--admin_password="${PASSWORD}" \
		--admin_email="${wp_admin_email}" \
		--skip-email \
		--allow-root
fi

if ! wp user get "${WP_USER:-editor}" --field=ID --allow-root >/dev/null 2>&1; then
	wp_user_email="${WP_USER_EMAIL:-editor@${DOMAIN_NAME}}"
	if wp user get "${wp_user_email}" --field=ID --allow-root >/dev/null 2>&1; then
		wp_user_email="${WP_USER:-editor}@${DOMAIN_NAME}"
	fi
	wp user create "${WP_USER:-editor}" "${wp_user_email}" \
		--user_pass="${WP_USER_PASSWORD:-$PASSWORD}" \
		--role=editor \
		--allow-root
fi

if wp core is-installed --allow-root; then
	if ! wp plugin is-installed redis-cache --allow-root; then
		wp plugin install redis-cache --activate --allow-root
		files_created=true
	else
		wp plugin activate redis-cache --allow-root
	fi
	wp redis enable --allow-root
fi

if [ "$files_created" = true ]; then
	chown -R www-data:www-data /var/www/html
	chmod -R g+rwX /var/www/html
fi

exec php-fpm8.2 -F
