# User Documentation

## Available services

| Service | Purpose | Access |
| --- | --- | --- |
| WordPress | Public website and administration dashboard | `https://youbella.42.fr` and `/wp-admin/` |
| Static site | Simple non-PHP site | `https://youbella.42.fr/static/` |
| Adminer | MariaDB administration | `http://VM_IP:8080` |
| Portainer | Docker management UI | `https://VM_IP:9443` |
| FTP | WordPress-files access | Port 21 and passive ports 10000-10100 |

Redis, MariaDB, and PHP-FPM are internal services and are not intended to be exposed directly in a browser.

## Starting and stopping

From the repository root:

```bash
make       # Build and start all services
make ps    # Check their status
make down  # Stop services while keeping persistent data
make clean # Remove project containers and its network, while keeping data
make fclean # Also remove this project's images and persistent volumes
```

## Website and administration

Open `https://youbella.42.fr`. Accept the self-signed certificate warning in the browser. Use the administrator username and password configured in `srcs/.env` to sign in at `https://youbella.42.fr/wp-admin/`.

The project creates a second non-administrator WordPress user using the `WP_USER`, `WP_USER_PASSWORD`, and `WP_USER_EMAIL` settings.

### Bonus-service access

- **Adminer:** open `http://VM_IP:8080`. Select MariaDB, use `mariadb` as the server, then enter the database user, password, and database name configured locally.
- **FTP:** connect to `VM_IP` on port `21` with the configured database user and password. Passive FTP uses ports `10000-10100`. If the client is outside the VM/Docker host, set the optional local `FTP_PASV_ADDRESS` value to the IP address or resolvable hostname the client uses to reach the VM, then recreate the FTP container.
- **Portainer:** open `https://VM_IP:9443`, accept its certificate warning, create its initial local administrator account, then select the local Docker environment.

## Credentials

Credentials are local configuration values in `srcs/.env`. They initialize MariaDB and WordPress when their persistent volumes are first created. To replace local demonstration credentials, use `make fclean && make`; this permanently deletes the local WordPress and database data. Never share this file or include real credentials in public repositories.

## Checking service health

```bash
make ps
docker logs nginx --tail 50
docker logs wordpress --tail 50
docker logs mariadb --tail 50
docker exec wordpress wp redis status --allow-root
docker exec redis redis-cli ping
```

All services should be `Up`; Redis should answer `PONG`, and WordPress should not be in a restart loop. You can verify persistence by creating a WordPress post, restarting the VM, launching the stack again, and confirming that the post remains available.
