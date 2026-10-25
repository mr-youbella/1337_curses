# Developer Documentation

This guide covers setup, container management, and data storage. Run the commands
from the project directory containing the Makefile.

## Set up the environment

Use a Linux VM for evaluation. Install Docker Engine, the Docker Compose plugin,
Make, and Git. Your user must be able to use Docker and write to
`/home/youbella/data/`.

Clone the repository and open the Inception project directory. The main files are:

```text
Makefile
srcs/docker-compose.yml
srcs/.env
srcs/requirements/
```

Each service directory contains its Dockerfile and any configuration or setup
scripts it needs. Bonus services are under `srcs/requirements/bonus/`.

### Local configuration

Create `srcs/.env` before starting. Define these settings with your own local values:

| Variable | Purpose |
| --- | --- |
| `DOMAIN_NAME` | Set to `youbella.42.fr` |
| `MYSQL_DATABASE` | WordPress database name |
| `USER` | Database user, WordPress administrator, and FTP username |
| `PASSWORD` | Password used for those accounts at setup |
| `MYSQL_ROOT_PASSWORD` | MariaDB root password |
| `WP_USER` | Second WordPress username |
| `WP_USER_PASSWORD` | Second WordPress user's password |
| `WP_USER_EMAIL` | Second WordPress user's email address |
| `WORDPRESS_VERSION` | WordPress version to download |
| `WP_CLI_VERSION` | WP-CLI version to download |

Optional settings are `WP_ADMIN_EMAIL` and `FTP_PASV_ADDRESS`. Without an admin
email setting, the script uses `admin@youbella.42.fr`. The administrator username
must not contain `admin` or `Admin`. Use nonempty passwords. This implementation
uses `.env`; no Docker secrets are configured.

On the browser's machine, add `VM_IP youbella.42.fr` to `/etc/hosts`, replacing
`VM_IP` with the VM's actual address.

For local macOS tests, use `127.0.0.1` for the domain and matching paths such as
`/Users/youbella/data/` in both Makefile and Compose. Restore the Linux paths for
evaluation. Changing a volume's device path does not move existing data.

## Build and launch

```bash
make
```

The Makefile creates the data directories and runs Compose with `up --build -d`.
For the same start without Makefile, first create the directories:

```bash
mkdir -p /home/youbella/data/wordpress /home/youbella/data/mariadb /home/youbella/data/portainer
docker compose -f srcs/docker-compose.yml up --build -d
```

WordPress waits for the Redis healthcheck and then checks MariaDB authentication
up to 30 times, with two seconds between attempts. WP-CLI downloads WordPress and
creates its configuration when missing. It installs the database tables and creates
the second user only when needed. The Redis plugin is activated during startup.

## Manage containers

```bash
make ps
make logs
make down
make fclean
make re
```

`down` removes containers and the project network. `fclean` also removes the
project's images and named volumes. `re` runs `fclean` and starts the project again.
The host data directories remain with the current driver options.

Useful Compose commands:

```bash
docker compose -f srcs/docker-compose.yml ps
docker compose -f srcs/docker-compose.yml logs --tail 50 wordpress
docker compose -f srcs/docker-compose.yml restart wordpress
docker compose -f srcs/docker-compose.yml up -d --build wordpress
docker compose -f srcs/docker-compose.yml exec wordpress bash
docker compose -f srcs/docker-compose.yml exec static nginx -t
```

To inspect a container or log in to MariaDB:

```bash
docker inspect wordpress
docker exec -it mariadb mariadb -uroot -p
```

Enter the root password from the local configuration when prompted.

## Network and volumes

All services use the `inception` bridge network. NGINX sends PHP requests to
`wordpress:9000` and forwards `/static/` to `static:80`. WordPress reaches MariaDB
at `mariadb:3306` and Redis at `redis:6379`.

```bash
docker network ls
docker network inspect inception
docker volume ls
docker volume inspect wordpress_data mariadb_data portainer_data
```

The data locations are:

| Named volume | Host directory | Container directory |
| --- | --- | --- |
| `wordpress_data` | `/home/youbella/data/wordpress` | `/var/www/html` |
| `mariadb_data` | `/home/youbella/data/mariadb` | `/var/lib/mysql` |
| `portainer_data` | `/home/youbella/data/portainer` | `/data` |

These are named volumes using the local driver with `type: none`, `o: bind`, and a
`device` path. In `docker volume inspect`, check `Options.device` for the host
directory. Docker's `Mountpoint` may still show its normal internal volume path.

Removing containers, running `fclean`, or rebooting does not erase these host
directories. Back up the WordPress files and database before any deliberate reset
or migration. No global Docker data-root change is needed.

NGINX and FTP share the WordPress files volume. Portainer stores its own account
and settings in its volume and uses `/var/run/docker.sock` to access Docker.
The static site's HTML is copied into its image, so rebuild the static service
after editing its files. Redis is used as a cache and has no persistent volume.

## Change credentials

WordPress account passwords are stored in its database. Use the dashboard to
change them; changing `.env` does not update accounts that already exist.

MariaDB applies the configured database user and root passwords at startup. If you
change `PASSWORD`, also update `DB_PASSWORD` in the existing WordPress
`wp-config.php`, and recreate the affected containers to load the new `.env`.
The same `PASSWORD` also sets the FTP password. Changing it does not change the
existing WordPress administrator's login password.

Plan these changes together and back up first. Changing database names or usernames
also requires updating WordPress configuration and handling the existing database.

## Basic checks

```bash
docker exec nginx nginx -t
docker exec wordpress wp core is-installed --allow-root
docker exec wordpress wp user list --allow-root
docker exec redis redis-cli ping
docker exec wordpress wp redis status --allow-root
curl -k https://youbella.42.fr
curl http://youbella.42.fr
```

HTTPS should show the installed site. HTTP port 80 should refuse the connection.
Check the bonus services using the addresses in USER_DOC.md.

For persistence, edit a WordPress page, restart the project, and check the edit.
Repeat after rebooting the VM. A simple configuration exercise is to change FPM's
`listen` port in `wordpress/conf/www.conf` and the matching `fastcgi_pass` in
`nginx/conf/nginx.conf`, then rebuild both services and check the website again.
