from machine import Pin
import time

# Initialize obstacle avoidance sensor connected to pin 16 as input
obstacle_avoidance_sensor = Pin(16, Pin.IN)

while True:
    # Read and print the value of the obstacle avoidance sensor
    print(obstacle_avoidance_sensor.value())

    # Wait for 0.1 seconds before the next read
    time.sleep(0.1)
