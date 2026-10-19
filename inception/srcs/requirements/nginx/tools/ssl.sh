#!/bin/bash
set -eu

: "${DOMAIN_NAME:?DOMAIN_NAME is required}"

mkdir -p /etc/nginx/ssl

openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=MA/ST=KH/L=KH/O=42/OU=student/CN=${DOMAIN_NAME}"

exec nginx -g "daemon off;"
