from machine import Pin
import time

# Set GPIO 19 as an input pin to read the button state
button = Pin(19, Pin.IN)

# Initialize the onboard LED of the Raspberry Pi Pico W
led = Pin('LED', Pin.OUT)

while True:
    if button.value() == 0:  # Check if the button is pressed
        led.value(1)  # Turn on the LED
    else:
        led.value(0)  # Turn off the LED

    time.sleep(0.1)  # Short delay to reduce CPU usage

