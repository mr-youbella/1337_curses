NAME = inception
COMPOSE = docker compose -f srcs/docker-compose.yml

all: up

up:
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
