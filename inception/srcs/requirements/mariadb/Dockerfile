FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

# 🔥 مهم: directory ديال socket
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

# 🔥 allow remote connections
RUN sed -i 's|bind-address.*|bind-address = 0.0.0.0|' /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/init.sh /init.sh
RUN chmod +x /init.sh

ENTRYPOINT ["/init.sh"]
