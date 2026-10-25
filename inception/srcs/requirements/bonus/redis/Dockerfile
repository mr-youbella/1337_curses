FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y redis-server && rm -rf /var/lib/apt/lists/*

ENTRYPOINT ["redis-server", "--protected-mode", "no"]
