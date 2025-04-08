FROM mfisherman/openmpi

WORKDIR /app

USER root

RUN apk add --update --no-cache openssh-server

RUN apk add openssh

RUN apk add openrc

RUN rc-update add sshd

COPY .  .

EXPOSE 22
