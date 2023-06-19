import serial
import csv

arduino_port = "/dev/cu.usbmodem21401" # serial port of Arduino
baud = 9600 # port runs at 9600 baud
fileName = "data.csv"

ser = serial.Serial(arduino_port, baud)
print("Connected to Arduino port: " + arduino_port);
file = open(fileName, "a");
print("Created file");

collected_data = []

while True:
    try:
        getData=ser.readline()
        dataString = getData.decode('utf-8')
        data=dataString[0:][:-2]
        print(data)

        readings = data.split(",")
        print(readings)

        collected_data.append(readings)
    except: # if something happens or Arduino is disconnected, save collected data and end program
        with open(fileName, 'w', encoding='UTF8', newline='') as f:
            writer = csv.writer(f)
            writer.writerows(collected_data)
        file.close();
        exit()


