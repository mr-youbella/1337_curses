# User Documentation

This guide explains how to start the project, use its services, and check that
everything is working. Run the commands from the directory containing the Makefile.

## Services

NGINX serves the website over HTTPS. WordPress and PHP-FPM handle the pages, and
MariaDB stores the site's content and users. Each service runs in its own container.

The bonus adds Redis for caching, FTP for file access, a static website, Adminer
for database management, and Portainer for Docker management.

## Start and stop

Build and start all services:

```bash
make
```

`make up` does the same thing. To stop and remove the containers while keeping data:

```bash
make down
```

To remove the project containers, images, and named volumes, use `make fclean`.
To do that and then rebuild, use `make re`.

With the current setup, the host directories under `/home/youbella/data/` are not
deleted by these commands. `make re` does not reset the website or database.

## Website and dashboard

The machine running your browser needs a hosts entry pointing the domain to the VM:

```text
VM_IP youbella.42.fr
```

Replace `VM_IP` with the VM's IP address. Use `127.0.0.1` for a local Docker Desktop
setup. Then open:

- Website: `https://youbella.42.fr`
- WordPress dashboard: `https://youbella.42.fr/wp-admin/`
- Static website: `https://youbella.42.fr/static/`

Accept the self-signed certificate warning. The main website does not use HTTP.
Sign in to WordPress with the administrator account configured in `.env`.

## Bonus services

Replace `VM_IP` below with the address of the Docker host.

| Service | How to use it |
| --- | --- |
| Redis | Used internally by WordPress; there is no separate website to open. |
| FTP | Connect an FTP client to `VM_IP:21` using `USER` and `PASSWORD` from `.env`. Passive ports are 10000-10100. |
| Adminer | Open `http://VM_IP:8080`. Select MySQL/MariaDB, set the server to `mariadb`, and enter the database credentials from `.env`. |
| Portainer | Open `https://VM_IP:9443`. Create its administrator account on the first visit, then add the local Docker environment. |

If passive FTP cannot transfer files from outside the Docker host, set
`FTP_PASV_ADDRESS` in `.env` to the reachable VM address and recreate the FTP
container. Portainer has its own account; it does not use the WordPress password.

If Portainer asks for a setup token, find it in `docker logs portainer` and keep it
private. If the first setup has timed out, restart it and try again:

```bash
docker compose -f srcs/docker-compose.yml restart portainer
```

## Credentials

Local configuration is stored in `srcs/.env`:

| Setting | Used for |
| --- | --- |
| `USER` and `PASSWORD` | Database user, WordPress administrator, and FTP account |
| `MYSQL_ROOT_PASSWORD` | MariaDB root account |
| `WP_USER` and `WP_USER_PASSWORD` | Second WordPress account, with the editor role |

Keep this file private and do not share its passwords.

Change WordPress passwords from **Users** in the dashboard. Editing `.env` alone
does not update an existing WordPress account. Keep the local configuration in
sync with account changes.

Database password changes also need an update to WordPress's saved database
configuration. Follow the credential notes in DEV_DOC.md before changing them.
Portainer account changes are made inside Portainer, and its volume preserves them.

## Check the services

```bash
make ps
make logs
```

Containers should stay `Up` or `running`, and Redis should be `healthy`. A container
that keeps restarting needs attention. Check its logs, for example:

```bash
docker logs --tail 50 nginx
docker logs --tail 50 wordpress
docker logs --tail 50 mariadb
```

Check Redis and its connection to WordPress:

```bash
docker exec redis redis-cli ping
docker exec wordpress wp redis status --allow-root
```

Redis should answer `PONG`, and WordPress should report `Connected`. Open the
website, sign in, and edit a page to check the main services together.

To check persistence, save a page change, run `make down` followed by `make`, and
confirm that the change is still there. Also repeat the check after rebooting the VM.
Do not delete the data directories when you want to keep the site.
