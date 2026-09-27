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

    # Separate commands make an initialization failure visible immediately.
    mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
    mysql -u root -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
    mysql -u root -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE USER IF NOT EXISTS '${USER}'@'%' IDENTIFIED BY '${PASSWORD}';"
    mysql -u root -p"${MYSQL_ROOT_PASSWORD}" -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${USER}'@'%';"
    mysql -u root -p"${MYSQL_ROOT_PASSWORD}" -e "FLUSH PRIVILEGES;"

    if ! mysql -u root -p"${MYSQL_ROOT_PASSWORD}" -Nse "SELECT 1 FROM mysql.user WHERE User = '${USER}' AND Host = '%';" | grep -qx '1'; then
        echo "MariaDB did not create the WordPress database user." >&2
        exit 1
    fi

    mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
    wait "$pid"
fi

exec mysqld --user=mysql --datadir=/var/lib/mysql
