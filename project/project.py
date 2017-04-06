import serial
import time

print("Start")
port="/dev/tty.ArduinoBLE_CD-DevB" 
bluetooth=serial.Serial(port, 9600)
print("Connected")
bluetooth.flushInput()
for i in range(5):
  print("Ping")
  bluetooth.write(b"BOOP "+str.encode(str(i))) # byte not unicode (plus a number)
  print("Written")
  input_data=bluetooth.readline()
  print(input_data.decode())
  time.sleep(0.1)
bluetooth.close()
print("Done")
