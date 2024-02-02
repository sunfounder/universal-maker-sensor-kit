from gpiozero import DigitalInputDevice
from time import sleep

# Initialize the motion sensor as a digital input device on GPIO pin 17
motion_sensor = DigitalInputDevice(17)

# Continuously monitor the state of the motion sensor
while True:
    if motion_sensor.is_active:
        print("Somebody here!")
    else:
        print("Monitoring...")

    # Wait for 0.5 seconds before the next sensor check
    sleep(0.5)
