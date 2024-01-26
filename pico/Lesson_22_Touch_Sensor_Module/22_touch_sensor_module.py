from machine import Pin
import time

# Set GPIO 16 as an input pin to read the touch sensor state
touch_sensor = Pin(16, Pin.IN)

# Initialize the onboard LED of the Raspberry Pi Pico W
led = Pin("LED", Pin.OUT)

while True:
    if touch_sensor.value() == 1:
        led.value(1)  # Turn on the LED
        print("Touch detected!")
    else:
        led.value(0)  # Turn off the LED
        print("No touch detected")

    time.sleep(0.1)  # Short delay to reduce CPU usage
