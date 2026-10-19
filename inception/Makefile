COMPOSE = docker compose -f srcs/docker-compose.yml

all: up

up:
	mkdir -p /home/youbella/data/mariadb
	mkdir -p /home/youbella/data/wordpress
	mkdir -p /home/youbella/data/portainer
	$(COMPOSE) up --build -d

down:
	$(COMPOSE) down -remove-orphans

clean: down

fclean:
	$(COMPOSE) down --volumes --rmi all --remove-orphans

re: fclean all

ps:
	$(COMPOSE) ps

logs:
	$(COMPOSE) logs -f

.PHONY: all up down clean fclean re ps logs
