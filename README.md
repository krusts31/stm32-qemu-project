###### USES ESP8266 LOLINMINI D1
```sh
#find your connected ESP8266
sudo dmesg | grep tty
#find the path to it
ls /dev/
sudo docker build -t ESP8266 .
#--device give the path to ESP8266
sudo docker run -ti --device=/dev/ttyUSB0 test bash
#that is it
```
##### DEMO:
https://www.youtube.com/watch?v=0oKo1rDO5-0
