from machine import Pin
import time

# Initialize GPIO 16 as an input pin for the vibration sensor
vibration_sensor = Pin(16, Pin.IN)

# Continuously check the vibration sensor's state
while True:
    # If the sensor detects vibration (value is 1), print a message
    if vibration_sensor.value() == 1:
        print("Vibration detected!")
    # If no vibration is detected, print ellipses
    else:
        print("...")

    # Pause for 0.1 seconds to lower the demand on the CPU
    time.sleep(0.1)
