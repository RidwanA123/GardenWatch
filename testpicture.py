import cv2
import serial
import time
import os
from twilio.rest import Client
import base64
import requests
import asyncio
import imgbbpy
Fimage = ""

def pic(img):
    global Fimage
    client = imgbbpy.SyncClient('5f7062449d9d5de38c9baba23b812663')
    image =  client.upload(file=img)
    Fimage = image.url
    print(Fimage)


def send_sms(img):
    text = ("Motion Detected in Garden! Photo taken: {}".format(Fimage))
    account_sid = "AC1d20c171fb735b195dadb5144e1c7cfe"
    auth_token = "8aaa35cba7f748e63b8df36836743996"
    client = Client(account_sid, auth_token)

    message = client.messages \
        .create(
            body=text,
            from_='+16108903881',
            to='+12262200398'
        )

arduino = serial.Serial('COM12',9600,timeout=0.1)
cam = cv2.VideoCapture(0)

cv2.namedWindow("test")

img_counter = 0


while True:
    trigger = arduino.readline().strip().decode("utf-8")
    ret, frame = cam.read()
    if not ret:
        print("failed to get picture")
        break
    cv2.imshow("test", frame)

    k = cv2.waitKey(1)
    if k%256 == 27:
        # ESC pressed
        break
    elif trigger == "ANIMAL":
        
        img_name = "DETECTION_{}.png".format(img_counter)
        cv2.imwrite(img_name, frame)
        pic(img_name)
        send_sms(Fimage)
        
        print("{} MOTION PICTURE TAKEN".format(img_name))
        img_counter += 1
        time.sleep(5)

cam.release()

cv2.destroyAllWindows()
