FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y nginx openssl && rm -rf /var/lib/apt/lists/*

COPY conf/nginx.conf /etc/nginx/nginx.conf

COPY tools/ssl.sh /ssl.sh

RUN chmod +x /ssl.sh

ENTRYPOINT ["/ssl.sh"]
