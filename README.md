# arduino-serial-bridge-for-pipper-model

code to pilot the EM-337A-PLI controler for accurator

- connect the relay card to the accurator on pin 5v, FW, BW
- connect the arduino by usb serial at 9600 baud
- send '1' to serial to bring up the accurator
- send '2' to lower the accurator 

!!! wait for the accurator have reached their position befor 
send a new order otherwise it will not take the new order !!!

pin high = relay off
pin low = relay on
