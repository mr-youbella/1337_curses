NAME = inception
COMPOSE = docker compose -f srcs/docker-compose.yml
DATA_DIR = /home/$(USER)/data

all: up

up: prepare
	$(COMPOSE) up --build -d

prepare:
	mkdir -p $(DATA_DIR)/wordpress $(DATA_DIR)/mariadb $(DATA_DIR)/portainer

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

.PHONY: up prepare down clean ps logs
