#__code to test LDR sensor and turning on LED___

import RPi.GPIO as GPIO
import time

#__ To set GPIO pins as GPIO.BOARD__
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

#__ Assigning pins ___
led = 18
data = 7
lightRange = 160000 #__ Assigning light range as 160000 .You can change it as requirement
GPIO.setup(led,GPIO.OUT)

#__Function to read data from LDR sensor

def r_time(data):
  count = 0
  GPIO.setup(data,GPIO.OUT)
  GPIO.output(data,GPIO.LOW)
  time.sleep(0.1)
  GPIO.setup(data,GPIO.IN)
  while( GPIO.input(data)==GPIO.LOW ):
    count+=1
    if(count>160000):
      break
  return count
#__Main body of the program__
while True:
  print(r_time(data))
  if(r_time(data)>lightRange):
    GPIO.output(led,GPIO.HIGH)
  else:
    GPIO.output(led,GPIO.LOW)
GPIO.cleanup();
#__End of the program__
