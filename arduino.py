import serial
import time
import requests
import time

serialComm = serial.Serial('/dev/cu.usbmodem1101')
serialComm.timeout = 1

#gm => glass and metal (hazardous materials)
materials = {
    'plastic': 'trash', 
    'glass': 'gm', 
    'cardboard': 'recycling', 
    'metal': 'gm', 
    'paper': 'recycling', 
    'trash': 'trash'
}
temp = None; seen=set()


while True:
    # inp = input("Enter input [on/off]: ").strip()
    # if inp == "done":
    #     print("terminated program")
    #     break
    time.sleep(3)
    query = requests.get('https://intelligf.herokuapp.com/')
    temp = materials.get(query.text,'material not changed')
    # if temp not in seen: 
    seen.add(temp); print(query.text,temp)
    serialComm.write(temp.encode())
    # else: 
    #     print('material not changed')
    time.sleep(0.5) # buffer time apparently
    # print(serialComm.readline().decode('ascii'))

serialComm.close()
