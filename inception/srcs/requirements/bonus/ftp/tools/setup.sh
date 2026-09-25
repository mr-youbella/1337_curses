#!/bin/bash
set -e

if ! id "$USER" >/dev/null 2>&1; then
    useradd -m -d /var/www/html -s /usr/sbin/nologin "$USER"
fi
printf '%s:%s\n' "$USER" "$PASSWORD" | chpasswd

mkdir -p /var/run/vsftpd/empty
chmod 755 /var/run/vsftpd/empty

mkdir -p /var/www/html
chown -R "$USER:$USER" /var/www/html

exec vsftpd /etc/vsftpd.conf
