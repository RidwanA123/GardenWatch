import serial
import time
import os
from datetime import datetime










arduino = serial.Serial('COM12',9600,timeout=0.1)


while True:
    trigger = arduino.readline().strip().decode("utf-8")
    if trigger == "B":
        date = datetime.now()
        dateformat = date.strftime("%d/%m/%Y %H:%M:%S")
        print("Motion from outside detection station detected (Radio received at",date,")")
