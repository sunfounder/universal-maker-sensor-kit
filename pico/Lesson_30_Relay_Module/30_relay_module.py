from machine import Pin
import time

# Replace this number with the GPIO pin number your relay is connected to
relay_pin = Pin(16, Pin.OUT)

def relay_on():
    relay_pin.value(1)  # Set relay to ON state

def relay_off():
    relay_pin.value(0)  # Set relay to OFF state

try:
    while True:
        relay_on()
        print("on....")
        time.sleep(1)  # Wait for 1 second
        relay_off()
        print("off....")
        time.sleep(1)  # Wait for 1 second
except:
    relay_off()  # Ensure the relay is turned off in case of an exception
    print("Program interrupted, relay turned off.")
