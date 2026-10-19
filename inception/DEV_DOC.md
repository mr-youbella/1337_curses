# Developer Documentation

## Prerequisites

Develop on a Debian VM with Docker Engine, the Docker Compose plugin, GNU Make, and Git. The active user must be allowed to run Docker commands. Configure a local hosts/DNS entry for `youbella.42.fr` to point to the VM IP address. Configure the Docker daemon data root under `/home/youbella/data/docker` before creating project volumes.

## Local configuration

Create `srcs/.env` with these settings before the first build:

```text
DOMAIN_NAME
MYSQL_DATABASE
USER
PASSWORD
MYSQL_ROOT_PASSWORD
WP_USER
WP_USER_PASSWORD
WP_USER_EMAIL
WORDPRESS_VERSION
WP_CLI_VERSION
FTP_PASV_ADDRESS (optional; required for passive FTP from outside the Docker host)
```

Use distinct WordPress administrator and secondary-user email addresses. Do not put passwords in Dockerfiles or commit production credentials.

## Build and launch

```bash
make
make ps
make logs
```

`make` runs `docker compose -f srcs/docker-compose.yml up --build -d`.

## Managing the stack

```bash
make down    # Stop containers, retain data
make clean   # Remove project containers and its network, retain data
make fclean  # Also remove this project's images and Compose volumes
make re      # Run fclean, then rebuild all images and services
make ps      # List services
make logs    # Stream service logs
```

For an individual service:

```bash
docker compose -f srcs/docker-compose.yml logs --tail 100 wordpress
docker compose -f srcs/docker-compose.yml restart wordpress
docker compose -f srcs/docker-compose.yml exec mariadb mysql -uroot -p
```

## Persistence and data

`wordpress_data` stores `/var/www/html`; `mariadb_data` stores `/var/lib/mysql`; and `portainer_data` stores Portainer state. They are Docker named volumes, not bind mounts. To keep their data under `/home/youbella/data`, configure Docker before the first launch:

```bash
sudo install -d -m 0711 /home/youbella/data/docker
sudo mkdir -p /etc/docker
sudo nano /etc/docker/daemon.json
```

Put this JSON in `daemon.json` (merge it with existing JSON if the file already contains settings):

```json
{
  "data-root": "/home/youbella/data/docker"
}
```

Then restart Docker and verify it:

```bash
sudo systemctl restart docker
docker info --format "{{.DockerRootDir}}"
```

The final command must print `/home/youbella/data/docker`. Use `docker volume ls` and `docker volume inspect <volume-name>` to inspect volume data. Removing containers does not remove data; `make fclean` removes the project volumes. If volumes were created before this configuration, run `make fclean` once before rebuilding so Docker recreates them with the current setup.

## Architecture and troubleshooting

NGINX is the public TLS endpoint and sends PHP requests to `wordpress:9000`. WordPress connects to MariaDB using the internal `inception` network and enables Redis caching. MariaDB initializes its system tables only on a new volume, then idempotently ensures that the database and application user match the local configuration at each startup.

If WordPress is restarting, first inspect `docker logs wordpress --tail 100`. Check that MariaDB is up and that `USER`, `PASSWORD`, and `MYSQL_DATABASE` match in `srcs/.env`. For a clean development reset that removes local demonstration data:

```bash
make fclean
make
```

This deletes Docker-managed demonstration data. Do not use it when preserving a real site.
