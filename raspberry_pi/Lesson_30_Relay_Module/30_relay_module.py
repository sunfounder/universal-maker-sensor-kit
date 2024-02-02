from gpiozero import OutputDevice
from time import sleep

# Replace with your GPIO pin number
relay_pin = 17  # Example using GPIO17

# Initialize relay object
relay = OutputDevice(relay_pin)

try:
    while True:
        # Turn on the relay
        relay.on()
        sleep(1)  # Relay remains on for 1 second

        # Turn off the relay
        relay.off()
        sleep(1)  # Relay remains off for 1 second

except KeyboardInterrupt:
    # Capture Ctrl+C and safely close the program
    relay.off()
    print("Program interrupted by user")
