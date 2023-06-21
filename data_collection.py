import serial
import csv

arduino_port = "/dev/cu.usbmodem21401" # Serial port of Arduino
baud = 9600 # Port runs at 9600 baud
fileName = "data.csv" # Name of .csv to append to / create

try:
    ser = serial.Serial(arduino_port, baud) # Open serial communication with Arduino device
    print("Connected to Arduino port: " + arduino_port);
    file = open(fileName, "a"); # Append to a new file. If file does not exist, create a new file
    print("Created file");
except Exception as e:
    print("ERROR: ", e)
    exit()

collected_data = [] # Memo of all data collected

print("Waiting for serial communication to begin...")

while True:
    try:
        getData=ser.readline() # Read incoming data from Arduino
        dataString = getData.decode('utf-8') # Convert to a readable format
        data=dataString[0:][:-2] # Copy string, remove newline
        print(data)

        readings = data.split(",") # Convert data string into list
        print(readings)

        collected_data.append(readings) # Add data into memo

    except: # if something happens or Arduino is disconnected, save collected data and end program
        with open(fileName, 'w', encoding='UTF8', newline='') as f:
            writer = csv.writer(f)
            writer.writerows(collected_data)
            file.close();
            exit()


