COMPOSE = docker compose -f srcs/docker-compose.yml

all: up

up:
	mkdir -p /home/youbella/data/mariadb
	mkdir -p /home/youbella/data/wordpress
	mkdir -p /home/youbella/data/portainer
	$(COMPOSE) up --build -d

down:
	$(COMPOSE) down

clean:
	$(COMPOSE) down --volumes --remove-orphans

fclean: clean
	docker system prune -af

re: fclean all

ps:
	$(COMPOSE) ps

logs:
	$(COMPOSE) logs -f

.PHONY: up down clean ps logs
