FROM ubuntu:latest

ENV IDF_PATH=/stm32-qemu-project/ESP8266_RTOS_SDK

RUN apt-get update && \
  apt-get install -y git make python2 flex bison gperf libncurses5-dev libncursesw5-dev python-pip

RUN ln -s /usr/bin/python2 /usr/bin/python

RUN git clone --recursive https://github.com/krusts31/stm32-qemu-project
