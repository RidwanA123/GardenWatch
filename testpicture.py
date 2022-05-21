import cv2
import serial
import time

arduino = serial.Serial('COM12',9600,timeout=0.1)
cam = cv2.VideoCapture(0)

cv2.namedWindow("test")

img_counter = 0

while True:
    trigger = arduino.readline().strip().decode("utf-8")
    ret, frame = cam.read()
    if not ret:
        print("failed to grab frame")
        break
    cv2.imshow("test", frame)

    k = cv2.waitKey(1)
    if k%256 == 27:
        # ESC pressed
        print("Escape hit, closing...")
        break
    elif trigger == "ANIMAL":
        img_name = "DETECTION_{}.png".format(img_counter)
        cv2.imwrite(img_name, frame)
        print("{} MOTION PICTURE TAKEN".format(img_name))
        img_counter += 1
        time.sleep(1)

cam.release()

cv2.destroyAllWindows()
