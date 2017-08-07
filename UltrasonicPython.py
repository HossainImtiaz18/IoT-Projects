#__ Code to read data from Ultrasonic sensor and turning on LED

import RPi.GPIO as GPIO
import time  

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

#__ Definfing pin number
Trig=7
Echo=12
Led=18
#__ To set up GPIO pin
GPIO.setup(Trig,GPIO.OUT)
GPIO.output(Trig,0)
GPIO.setup(Echo,GPIO.IN)
GPIO.setup(Led,GPIO.OUT)
time.sleep(0.1)
print("Starting reading data...........")
loop=1

#__ To read data continously

while loop==1:                 
        GPIO.output(Trig,1)
        time.sleep(0.00001)
        GPIO.output(Trig,0)
        while GPIO.input(Echo)== 0 :
            pass
        start = time.time()

        while GPIO.input(Echo)==1:
            pass
        stop = time.time()
        dis = (stop-start)*17000
        print dis
        time.sleep(.2)
#__ To turn on LED if the distance be less than 10.0

        if dis<10.0:
            GPIO.output(Led,GPIO.HIGH)
        else:
            GPIO.output(Led,GPIO.LOW)
        time.sleep(.1)
GPIO.cleanup()
#__ End of the program
