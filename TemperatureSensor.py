#__ To read data from Temparature sensor __
import os
import time
# __ 1- wired sensor interfacing with gpio BCM mode __ 
os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')
#__ Reading data from directory /sys/bus/w1/devices/
#__ but here 28-0000073f4155 is my sensor serial no .
#__ May be you have another one
tempSensedData = '/sys/bus/w1/devices/28-0000073f4155/w1_slave'
#__ Reading the raw data from the directory __
def rawDataFromFile():
    File = open(tempSensedData, 'r')
    lines = File.readlines()
    File.close()
    return lines
#__ Taking meaningful data from String operation .
def readRawData():
    lines = rawDataFromFile()
    while lines[0].strip()[-3:] != 'YES':
            time.sleep(0.2)
            lines = temp_raw()
    checkLine = lines[1].find('t=') # __ checkLine is data string __
    if checkLine != -1:
            string = lines[1].strip()[checkLine + 2:]
            celcious = float(string)/1000.0 # __ Data is to be divided by 1000.0
            print (celcious)
while True:
    readRawData()
    time.sleep(1)
#__ End of the program __
