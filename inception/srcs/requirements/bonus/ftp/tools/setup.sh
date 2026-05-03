#!/bin/bash
set -e

if ! id "youbella" >/dev/null 2>&1; then
    useradd -m -d /var/www/html youbella
    echo "$USER:$PASSWORD" | chpasswd
fi
echo "$USER:$PASSWORD" | chpasswd

mkdir -p /var/run/vsftpd/empty
chmod 755 /var/run/vsftpd/empty

mkdir -p /var/www/html
chown -R $USER:$USER /var/www/html

exec vsftpd /etc/vsftpd.conf
