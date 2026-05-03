#!/bin/bash

set -e

mkdir -p /etc/nginx/ssl

openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=MA/ST=KH/L=KH/O=42/OU=student/CN=${DOMAIN_NAME}"

exec nginx -g "daemon off;"
