from machine import Pin
import time

# Initialize raindrop sensor connected to pin 16 as input
raindrop_sensor = Pin(16, Pin.IN)

while True:
    # Check the Raindrop sensor value
    if raindrop_sensor.value() == 0:  
        print("Raindrop detected!")  # Raindrop detected
    else:
        print("Monitoring...")  # No raindrop detected

    time.sleep(0.1)  # Short delay of 0.1 seconds to reduce CPU usage
