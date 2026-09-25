#!/bin/bash
set -e

cd /var/www/html

if [ ! -f "wp-config.php" ]; then

	echo "Downloading WordPress..."

	wget "https://wordpress.org/wordpress-${WORDPRESS_VERSION:-7.1.2}.tar.gz" -O /tmp/wp.tar.gz
	tar -xzf /tmp/wp.tar.gz -C /tmp

	cp -r /tmp/wordpress/* /var/www/html
	rm -rf /tmp/wp.tar.gz /tmp/wordpress

	cp wp-config-sample.php wp-config.php

	sed -i "s/database_name_here/${MYSQL_DATABASE}/g" wp-config.php
	sed -i "s/username_here/${USER}/g" wp-config.php
	sed -i "s/password_here/${PASSWORD}/g" wp-config.php
	sed -i "s/localhost/mariadb/g" wp-config.php

	# Bonus Redis
	sed -i "/<?php/a define('WP_REDIS_HOST', 'redis');" wp-config.php
	sed -i "/<?php/a define('WP_REDIS_PORT', 6379);" wp-config.php
fi

chown -R www-data:www-data /var/www/html

# Bonus Redis
if ! command -v wp >/dev/null 2>&1; then
	curl -fsSL "https://github.com/wp-cli/wp-cli/releases/download/v${WP_CLI_VERSION:-2.12.0}/wp-cli-${WP_CLI_VERSION:-2.12.0}.phar" -o /usr/local/bin/wp
	chmod +x /usr/local/bin/wp
fi

until mysql -h mariadb -u${USER} -p${PASSWORD} -e "SELECT 1;" >/dev/null 2>&1; do
	echo "Waiting for MariaDB auth..."
	sleep 2
done

if ! wp core is-installed --allow-root; then
	wp core install \
		--url="https://${DOMAIN_NAME}" \
		--title="Inception" \
		--admin_user="${USER}" \
		--admin_password="${PASSWORD}" \
		--admin_email="younesoubllal@gmail.com" \
		--skip-email \
		--allow-root
fi

if ! wp user get "${WP_USER:-editor}" --field=ID --allow-root >/dev/null 2>&1; then
	wp user create "${WP_USER:-editor}" "${WP_USER_EMAIL:-editor@example.invalid}" \
		--user_pass="${WP_USER_PASSWORD:-$PASSWORD}" \
		--role=editor \
		--allow-root
fi

if wp core is-installed --allow-root; then
	wp plugin install redis-cache --activate --allow-root || true
	wp redis enable --allow-root || true
fi

exec php-fpm8.2 -F
