#!/bin/bash
set -e

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld /var/lib/mysql

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking &
pid=$!

sleep 5

mysql -u root << EOF
CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS '${USER}'@'%' IDENTIFIED BY '${PASSWORD}';
GRANT ALL PRIVILEGES ON wordpress.* TO '${USER}'@'%';
FLUSH PRIVILEGES;
EOF

mysqladmin shutdown
wait $pid

exec mysqld --user=mysql --datadir=/var/lib/mysql
