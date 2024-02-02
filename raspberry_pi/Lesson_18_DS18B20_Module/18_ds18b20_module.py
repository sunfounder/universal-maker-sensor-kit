import glob
import time

# Path to the directory containing device files for 1-wire devices
base_dir = "/sys/bus/w1/devices/"

# Finds the first device folder that starts with "28", specific to DS18B20
device_folder = glob.glob(base_dir + "28*")[0]

# Device file containing the temperature data
device_file = device_folder + "/w1_slave"


def read_temp_raw():
    # Reads raw temperature data from the sensor
    f = open(device_file, "r")
    lines = f.readlines()
    f.close()
    return lines


def read_temp():
    # Parses the raw temperature data and converts it to Celsius and Fahrenheit
    lines = read_temp_raw()
    # Waits for a valid temperature reading
    while lines[0].strip()[-3:] != "YES":
        time.sleep(0.2)
        lines = read_temp_raw()
    equals_pos = lines[1].find("t=")
    if equals_pos != -1:
        temp_string = lines[1][equals_pos + 2 :]
        temp_c = float(temp_string) / 1000.0  # Convert to Celsius
        temp_f = temp_c * 9.0 / 5.0 + 32.0  # Convert to Fahrenheit
        return temp_c, temp_f


try:
    # Main loop to continuously read and print temperature
    while True:
        temp_c, temp_f = read_temp()
        formatted_output = f"Temperature: {temp_c:.2f}°C / {temp_f:.2f}°F"
        print(formatted_output)
        time.sleep(1)  # Wait for 1 second between readings
except KeyboardInterrupt:
    # Gracefully exit the program on CTRL+C
    print("Exit")
