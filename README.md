# GardenWatch®
A small gadget that monitors your vegetable and other corps from pests and other animals using sensors, then takes a picture and sends it over to you using SMS (with Twilio) and to the house notification station using Radio.
<br>

<br>
<br>
The sensors consist of a Passive Infrared Motion Sensor to detect movement of animals, and a Sound Sensor to enhance accuracy and confirm that in fact an animal is detected. 
<br>
Once detected, GardenWatch will send a Radio signal over to a receiver station that consists of a buzzer and connects to your computer to give you a data/time of the detection. Then a SMS message will be sent that gives you a link to the picture taken by the camera.
<br>
<br>
The files are seperated into two folders, Arduino and src. The Arduino folder deals with the hardware portion of this project (the Transmitter file is for the actual GardenWatch unit, and the Reciever file is for the house unit). Under src, you will find Python files where the MainApp file will be the one for the GardenWatch unit.



