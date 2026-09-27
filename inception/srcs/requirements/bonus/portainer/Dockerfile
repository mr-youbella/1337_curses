FROM debian:bookworm-slim

ARG PORTAINER_VERSION=2.45.1

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    tar \
    && rm -rf /var/lib/apt/lists/*

RUN architecture="$(dpkg --print-architecture)" \
    && curl -fsSL "https://github.com/portainer/portainer/releases/download/${PORTAINER_VERSION}/portainer-${PORTAINER_VERSION}-linux-${architecture}.tar.gz" \
      -o /tmp/portainer.tar.gz \
    && tar -xzf /tmp/portainer.tar.gz -C /opt \
    && rm /tmp/portainer.tar.gz

EXPOSE 9443

CMD ["/opt/portainer/portainer"]
