from machine import Pin
import time

# Set GPIO 16 as an input pin to read the speed sensor
speed_sensor = Pin(16, Pin.IN)

while True:
    if speed_sensor.value() == 1:
        print("Obstruction detected")
    else:
        print("Unobstructed")

    time.sleep(0.1)  # Short delay to reduce CPU usage
