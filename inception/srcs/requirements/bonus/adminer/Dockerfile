FROM debian:bookworm-slim

ARG ADMINER_VERSION=6.1.1

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    php8.2-cli \
    php8.2-mysql \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/adminer \
    && curl -fsSL "https://www.adminer.org/static/download/${ADMINER_VERSION}/adminer-${ADMINER_VERSION}-mysql-en.php" \
      -o /var/www/adminer/index.php

EXPOSE 8080

CMD ["php", "-S", "0.0.0.0:8080", "-t", "/var/www/adminer"]
