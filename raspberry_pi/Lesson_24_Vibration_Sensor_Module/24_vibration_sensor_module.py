from gpiozero import InputDevice
import time

# Connect the digital output of the vibration sensor to GPIO17 on the Raspberry Pi
vibration_sensor = InputDevice(17)

# Continuous loop to read from the sensor
while True:
    # Check if the sensor is active (no vibration detected)
    if vibration_sensor.is_active:
        print("Vibration detected!")
    else:
        # When the sensor is inactive (vibration detected)
        print("...")
    # Wait for 1 second before reading the sensor again
    time.sleep(1)