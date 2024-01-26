from machine import Pin
import time

# Initialize PIR sensor connected to pin 16 as input
pir_sensor = Pin(16, Pin.IN)

while True:
    # Check the PIR sensor value
    if pir_sensor.value() == 0:  
        print("Monitoring...")  # No motion detected
    else:
        print("Somebody here!")  # Motion detected

    time.sleep(0.1)  # Short delay of 0.1 seconds to reduce CPU usage
