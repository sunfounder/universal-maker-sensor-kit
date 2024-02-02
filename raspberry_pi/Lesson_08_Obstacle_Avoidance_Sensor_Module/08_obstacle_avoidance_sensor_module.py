from gpiozero import InputDevice
from time import sleep

# Initialize the sensor as a digital input device on GPIO 17
sensor = InputDevice(17)

while True:
    if sensor.is_active:
        print("No obstacle detected")  # Prints when no obstacle is detected
    else:
        print("Obstacle detected")     # Prints when an obstacle is detected
    sleep(0.5)
