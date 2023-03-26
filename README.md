# stm32-qemu-project
`run to add display to `
xhost +local:docker
sudo docker run -e  DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -it --rm --cpus=0.1 -v ./:/workspace simavr-container



TODO
git clone --recursive https://github.com/espressif/esp-idf.git
sudo apt-get install gcc git wget make libncurses-dev flex bison gperf python python-serial
