import serial
import time
import datetime
from subprocess import call

print("Start")
port="/dev/tty.ArduinoBLE_CD-DevB" 
bluetooth=serial.Serial(port, 9600)
print("Connected")
bluetooth.flushInput()

# This code is for test purpose, it pings the arduino through bluetooth
# for i in range(5):
#   print("Ping")
#   bluetooth.write(b"BOOP "+str.encode(str(i))) # byte not unicode (plus a number)
#   print("Written")
#   input_data=bluetooth.readline()
#   print(input_data.decode())
#   time.sleep(0.1)
# bluetooth.close()
# print("Done")

while(1) :
  input_data=bluetooth.readline()
  if(input_data) :
    print(input_data.decode())
    call(["curl", "-i", "-X", "POST", "-H", "Content-Type:application/json", "-d", "{\"date\":\"" + str(datetime.datetime.now()) + "\", \"count\":"+ str(input_data.decode()) +"}", "https://api.mlab.com/api/1/databases/presence_iot/collections/presences?apiKey=ZtfXpfvNfY99X41BE7DOwHLB8HXUyd-7"])
   