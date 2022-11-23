import serial
import time
import serial.tools.list_ports

# ports = serial.tools.list_ports.comports()
# print(ports)

serialComm = serial.Serial('/dev/cu.usbmodem1101')
serialComm.timeout = 1
# r
# c
# g
while True:
    inp = input("Enter input [on/off]: ").strip()
    if inp == "done":
        print("terminated program")
        break
    serialComm.write(inp.encode())
    time.sleep(0.5) # buffer time apparently
    print(serialComm.readline().decode('ascii'))

serialComm.close()