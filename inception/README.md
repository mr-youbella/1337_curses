*This project has been created as part of the 42 curriculum by youbella.*

# Inception

## Description

Inception is a small Docker Compose infrastructure running on a Debian virtual machine.
It provides a TLS-only NGINX entrypoint, a WordPress site served by PHP-FPM, and a
MariaDB database. Persistent WordPress files and database data are managed through
Docker volumes. The stack also includes Redis object caching, FTP access to the
WordPress files, a static website, Adminer, and Portainer.

## Services

- **nginx**: the public HTTPS entrypoint on port 443.
- **wordpress**: WordPress and PHP-FPM, listening only on the internal Docker network.
- **mariadb**: persistent SQL database for WordPress.
- **redis**: WordPress object cache.
- **ftp**: FTP access to the WordPress files volume.
- **adminer**: database administration interface on port 8080.
- **portainer**: container-management interface on port 9443.

## Instructions

### Prerequisites

- Debian Linux virtual machine
- Docker Engine with the Docker Compose plugin
- GNU Make and Git
- A local DNS/hosts entry mapping `youbella.42.fr` to the VM IP address
- Docker daemon data root configured as `/home/youbella/data/docker` so named-volume data is stored under `/home/youbella/data`

Create `srcs/.env` locally before launching the stack. It contains the domain,
database settings, WordPress accounts, and pinned WordPress/WP-CLI versions. Do not
publish real credentials.

```bash
make
make ps
```

Open `https://youbella.42.fr`. The certificate is self-signed, so the browser will
show a warning on the first visit. The WordPress dashboard is available at
`https://youbella.42.fr/wp-admin/`.

Useful commands:

```bash
make down     # Stop the stack
make clean    # Stop it and remove its Docker volumes
make logs     # Follow service logs
make ps       # Show service status
```

See [USER_DOC.md](USER_DOC.md) for operational instructions and [DEV_DOC.md](DEV_DOC.md)
for development and troubleshooting details.

## Design choices

### Docker and virtual machines

A virtual machine emulates an entire operating system and has a larger resource cost.
Docker containers share the host kernel, start quickly, and isolate each service with
its own filesystem, process, and network configuration. This project uses a Debian VM
as the host and Docker containers for the application services.

### Secrets and environment variables

Environment variables make configuration available to containers without hard-coding
values in Dockerfiles. Docker secrets are better for sensitive production values because
they are mounted as protected files rather than exposed through the container environment.
This educational stack uses a local `.env` file for configuration; credentials must be
kept private and never embedded in source files.

### Docker networks and host networking

The dedicated `inception` bridge network lets services resolve each other by service
name, such as `wordpress` reaching `mariadb`. Host networking would remove that
isolation and can cause port conflicts, so it is not used.

### Docker volumes and bind mounts

Docker named volumes are managed by Docker and persist independently from container lifetimes. They are used for the WordPress files, MariaDB data, and Portainer state. Bind mounts expose a host path directly; this project uses them only for the read-only static-site source and the Portainer Docker socket.

## Resources

- [Docker documentation](https://docs.docker.com/)
- [Docker Compose reference](https://docs.docker.com/compose/)
- [WordPress documentation](https://wordpress.org/documentation/)
- [MariaDB documentation](https://mariadb.com/kb/en/documentation/)
- [NGINX documentation](https://nginx.org/en/docs/)

## AI usage

AI assistance was used to review the Compose configuration, diagnose container startup failures, improve shell-script error handling, and draft the documentation. All changes were reviewed by the author and must be tested on the Debian VM before submission.
