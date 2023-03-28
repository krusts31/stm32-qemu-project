###### USES ESP8266 LOLINMINI D1
```sh
sudo apt-get install gcc git wget make libncurses-dev flex bison gperf python python-serial
git clone --recursive https://github.com/espressif/ESP8266_RTOS_SDK
export IDF_PATH=~/esp/ESP8266_RTOS_SDK
sudo chown $USER /dev/ttyUSB0
make flash
```
##### DEMO:
https://www.youtube.com/watch?v=0oKo1rDO5-0
