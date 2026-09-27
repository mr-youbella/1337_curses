#!/bin/bash
set -e

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld /var/lib/mysql

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking &
    pid=$!

    database_ready=false
    for attempt in $(seq 1 30); do
        if mysqladmin ping --silent; then
            database_ready=true
            break
        fi
        sleep 1
    done

    if [ "$database_ready" != true ]; then
        echo "MariaDB initialization timed out." >&2
        exit 1
    fi

    mysql -u root << EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${USER}'@'%' IDENTIFIED BY '${PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${USER}'@'%';
FLUSH PRIVILEGES;
EOF

    mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
    wait "$pid"
fi

exec mysqld --user=mysql --datadir=/var/lib/mysql
