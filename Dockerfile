FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y debconf-utils && \
    echo "tzdata tzdata/Areas select Etc" | debconf-set-selections && \
    echo "tzdata tzdata/Zones/Etc select UTC" | debconf-set-selections && \
    apt-get install -y tzdata

RUN DEBIAN_FRONTEND=noninteractive apt-get update && \
    apt-get install -y git build-essential gcc-avr avr-libc gdb-multiarch python3-pip simavr x11-apps python3-tk

WORKDIR /workspace
