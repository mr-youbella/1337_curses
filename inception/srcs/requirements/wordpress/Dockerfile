FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y php8.2 php8.2-fpm php8.2-mysql wget curl tar mariadb-client && rm -rf /var/lib/apt/lists/*

RUN sed -i 's|listen = .*|listen = 0.0.0.0:9000|' /etc/php/8.2/fpm/pool.d/www.conf

RUN mkdir -p /var/www/html

COPY tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

WORKDIR /var/www/html

ENTRYPOINT ["/setup.sh"]
