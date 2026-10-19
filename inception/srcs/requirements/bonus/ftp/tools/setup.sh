#!/bin/bash
set -eu

: "${USER:?USER is required}"
: "${PASSWORD:?PASSWORD is required}"

if ! id "$USER" >/dev/null 2>&1; then
    useradd -M -d /var/www/html -s /bin/bash -g www-data "$USER"
fi
printf '%s:%s\n' "$USER" "$PASSWORD" | chpasswd

mkdir -p /var/run/vsftpd/empty
chmod 755 /var/run/vsftpd/empty

config_file=/tmp/vsftpd.conf
cp /etc/vsftpd.conf "$config_file"

# A client outside Docker needs the VM's reachable address in the PASV reply.
if [ -n "${FTP_PASV_ADDRESS:-}" ]; then
    printf '\npasv_address=%s\n' "$FTP_PASV_ADDRESS" >> "$config_file"
fi

exec vsftpd "$config_file"
