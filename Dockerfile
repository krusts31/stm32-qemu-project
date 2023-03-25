# Dockerfile
FROM ubuntu:latest

# Install dependencies
RUN apt-get update && \
    apt-get install -y git build-essential gcc-avr avr-libc gdb-multiarch python3-pip

# Clone the simavr repository and install
RUN git clone https://github.com/buserror/simavr.git /simavr && \
    cd /simavr && \
    make && \
    make install

# Set up a working directory
WORKDIR /workspace
