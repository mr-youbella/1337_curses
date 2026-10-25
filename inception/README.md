*This project has been created as part of the 42 curriculum by youbella.*

# Inception

## Description

Inception is a system administration project where I run a WordPress website with
Docker. It helped me understand how to set up services, connect containers, and
keep data when containers are removed.

The main services are NGINX, WordPress with PHP-FPM, and MariaDB. Each one has its
own container and Dockerfile. Docker Compose manages the stack, and the Makefile
provides simple commands to build, start, and stop it.

## Project description

All images start from `debian:bookworm-slim`. The Dockerfiles install the required
packages and copy the configuration files and setup scripts.

- **NGINX** serves HTTPS on port 443 with a self-signed certificate. It allows
  TLS 1.2 and TLS 1.3, and sends PHP requests to `wordpress:9000`.
- **WordPress** runs with PHP-FPM. WP-CLI downloads and installs the site and
  creates two users: an administrator and an editor.
- **MariaDB** stores the WordPress database. Its port is not published to the host.

The files are organised under `srcs/`. The Compose file defines the services,
network, and volumes. `srcs/requirements/` contains each service's Dockerfile,
configuration, and scripts. Bonus services are in `srcs/requirements/bonus/`.
WordPress is downloaded from WordPress.org using WP-CLI. Adminer and Portainer
come from their official releases.

All services use the `inception` bridge network. They run in the foreground through
`ENTRYPOINT` and have a restart policy. WordPress files and database data are kept
in named volumes mapped to `/home/youbella/data/`.

### Virtual Machines vs Docker

A virtual machine runs its own operating system and kernel. Containers share the
Docker host's kernel and isolate applications, so they usually use fewer resources.
The evaluation setup uses Docker inside a Linux VM.

### Secrets vs Environment Variables

Environment variables pass settings to containers. This project reads them from
`srcs/.env`. They are simple to use, but sensitive values can be visible through
container inspection. Docker secrets pass sensitive values as files to selected
services. This implementation uses `.env` and does not use Docker secrets.

### Docker Network vs Host Network

A bridge network gives containers their own network and lets them use service
names to communicate. Host networking shares the host's network namespace.
This project uses a bridge network and publishes the ports needed by the website
and bonus services.

### Docker Volumes vs Bind Mounts

A named volume is a Docker resource that survives container removal. A bind mount
connects a host path directly to a container. Here, services mount named volumes,
and local driver options place their data under `/home/youbella/data/`.
Portainer also mounts the Docker socket to communicate with Docker.

## Instructions

### Requirements and setup

Use a Linux VM with Docker Engine, the Docker Compose plugin, Make, and Git.
Your user needs permission to use Docker and create `/home/youbella/data/`.

Clone the repository and open the directory containing the Makefile. Create
`srcs/.env` with the domain, database settings, account details, and WordPress and
WP-CLI versions. Set `DOMAIN_NAME` to `youbella.42.fr`.

On the machine running your browser, add this line to `/etc/hosts`:

```text
VM_IP youbella.42.fr
```

Replace `VM_IP` with the VM's actual IP address. For local Docker Desktop tests,
use `127.0.0.1` and adjust the data paths in Makefile and Compose for your machine.

### Build and run

```bash
make
```

This builds and starts all services, including the bonus. WordPress waits for the
Redis healthcheck and checks its connection to MariaDB during startup.

Open `https://youbella.42.fr`. Accept the browser warning for the self-signed
certificate. The WordPress dashboard is at `https://youbella.42.fr/wp-admin/`.
The website is not available over HTTP port 80.

### Commands

```bash
make up      # Build and start
make ps      # Show container status
make logs    # Follow logs
make down    # Stop and remove containers and the network
make fclean  # Also remove project images and named volumes
make re      # Run fclean, then build and start again
```

With the current volume driver options, `fclean` does not delete the host data
directories. `re` therefore rebuilds the stack without resetting the saved site.

See [USER_DOC.md](USER_DOC.md) for daily use and [DEV_DOC.md](DEV_DOC.md) for setup,
container commands, and data storage.

## Bonus

Each bonus service has its own Dockerfile and container.

| Service | Purpose | Access |
| --- | --- | --- |
| Redis | WordPress object cache | Internal port 6379 |
| FTP | Access to WordPress files | VM IP, port 21; passive ports 10000-10100 |
| Static website | An HTML/CSS page served by a separate NGINX container | `https://youbella.42.fr/static/` |
| Adminer | Database administration | `http://VM_IP:8080` |
| Portainer | Docker management | `https://VM_IP:9443` |

In Adminer, use `mariadb` as the database server. FTP uses `USER` and `PASSWORD`
from `.env`. On the first Portainer visit, create its administrator account and
add the local Docker environment. Its `/data` volume keeps the account and settings.

## Resources

- [Docker](https://docs.docker.com/)
- [NGINX](https://nginx.org/en/docs/)
- [WP-CLI](https://developer.wordpress.org/cli/commands/)
- [MariaDB](https://mariadb.com/docs/)
- [Redis Object Cache](https://wordpress.org/plugins/redis-cache/)
- [Adminer](https://www.adminer.org/) and [Portainer](https://docs.portainer.io/)

### AI usage

AI helped explain Docker concepts, review the Compose file and setup scripts,
and prepare configuration changes and documentation.
