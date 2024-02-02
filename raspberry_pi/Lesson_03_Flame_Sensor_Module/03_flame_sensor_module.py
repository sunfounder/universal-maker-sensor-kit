from gpiozero import InputDevice
import time

# Connect the digital output of the flame sensor to GPIO17 on the Raspberry Pi
flame_sensor = InputDevice(17)

# Continuous loop to read from the sensor
while True:
    # Check if the sensor is active (no flame detected)
    if flame_sensor.is_active:
        print("No flame detected.")
    else:
        # When the sensor is inactive (flame detected)
        print("Flame detected!")
    # Wait for 1 second before reading the sensor again
    time.sleep(1)
