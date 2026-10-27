FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y redis-server && rm -rf /var/lib/apt/lists/*

EXPOSE 6379

ENTRYPOINT ["redis-server", "--protected-mode", "no"]
