# arduino-serial-bridge-for-pipper-model


--------------------------V1
code to pilot the EM-337A-PLI controler for accurator

- connect the relay card to the accurator on pin 5v, FW, BW
- connect the arduino by usb serial at 9600 baud
- send '1' to serial to bring up the accurator
- send '2' to lower the accurator 

!!! wait for the accurator have reached their position befor 
send a new order otherwise it will not take the new order !!!

pin high = relay off
pin low = relay on


--------------------------V2
code to pilot the EM-337A-PLI controler for accurator

- h --> help
- i --> info
- 1 --> up model
- 2 --> down model
- r --> reset accurator (steel in test, do not use in production!!!
- U+value --> set a new 'up time' in millisecond (ex: U30000 = up time 30s)
when update the up time the new down time is auto compute (down time = up time + 2s)
- D+value --> set a new 'down time' in millisecond (ex: U30000 =  time 30s)
the down time MUST be higher than the up time!(to be shure that the model goes down properly)

!!! wait for the accurator have reached their position befor 
send a new order otherwise it will not take the new order !!!

-pin high = relay off
-pin low = relay on

-pin 9 = up
-pin 10 = down
