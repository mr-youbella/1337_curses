#!/bin/bash
set -eu

: "${MYSQL_DATABASE:?MYSQL_DATABASE is required}"
: "${MYSQL_ROOT_PASSWORD:?MYSQL_ROOT_PASSWORD is required}"
: "${USER:?USER is required}"
: "${PASSWORD:?PASSWORD is required}"

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld /var/lib/mysql

if [ ! -d "/var/lib/mysql/mysql" ]; then
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db
fi

sql_escape()
{
	printf '%s' "$1" | sed -e 's/\\/\\\\/g' -e "s/'/''/g"
}

db_name="$(printf '%s' "${MYSQL_DATABASE}" | sed 's/`/``/g')"
root_password="$(sql_escape "${MYSQL_ROOT_PASSWORD}")"
wp_user="$(sql_escape "${USER}")"
wp_password="$(sql_escape "${PASSWORD}")"
init_file="/run/mysqld/inception-init.sql"

umask 077
cat > "$init_file" <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${root_password}';
CREATE DATABASE IF NOT EXISTS \`${db_name}\`;
CREATE USER IF NOT EXISTS '${wp_user}'@'%' IDENTIFIED BY '${wp_password}';
ALTER USER '${wp_user}'@'%' IDENTIFIED BY '${wp_password}';
GRANT ALL PRIVILEGES ON \`${db_name}\`.* TO '${wp_user}'@'%';
FLUSH PRIVILEGES;
EOF

chown mysql:mysql "$init_file"
chmod 600 "$init_file"

exec mysqld --user=mysql --datadir=/var/lib/mysql --console --init-file="$init_file"
