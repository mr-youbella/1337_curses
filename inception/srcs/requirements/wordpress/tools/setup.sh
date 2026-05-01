#!/bin/bash
set -e

cd /var/www/html

# Download WordPress only if empty
if [ ! -f "wp-config.php" ]; then

    echo "Downloading WordPress..."

    wget https://wordpress.org/latest.tar.gz -O /tmp/wp.tar.gz
    tar -xzf /tmp/wp.tar.gz -C /tmp

    cp -r /tmp/wordpress/* /var/www/html

    rm -rf /tmp/wp.tar.gz /tmp/wordpress

    # IMPORTANT: confirm file exists
    if [ ! -f "wp-config-sample.php" ]; then
        echo "WordPress files missing!"
        exit 1
    fi

    cp wp-config-sample.php wp-config.php

    sed -i "s/database_name_here/${MYSQL_DATABASE}/g" wp-config.php
    sed -i "s/username_here/${MYSQL_USER}/g" wp-config.php
    sed -i "s/password_here/${MYSQL_PASSWORD}/g" wp-config.php
    sed -i "s/localhost/mariadb/g" wp-config.php
fi

chown -R www-data:www-data /var/www/html

exec php-fpm8.2 -F
