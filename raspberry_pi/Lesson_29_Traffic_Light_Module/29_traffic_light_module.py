from gpiozero import LED
from time import sleep

# Initialize LED pins
red = LED(22)    # Red LED connected to GPIO pin 22
yellow = LED(27) # Yellow LED connected to GPIO pin 27
green = LED(17)  # Green LED connected to GPIO pin 17

# LED control in a continuous loop
try:
    while True:
        # Red LED cycle
        red.on()     # Turn on red LED
        sleep(3)     # Red LED on for 3 seconds
        red.off()    # Turn off red LED

        # Yellow LED blinking pattern
        yellow.on()  # Turn on yellow LED
        sleep(0.5)   # Yellow LED on for 0.5 second
        yellow.off() # Turn off yellow LED
        sleep(0.5)   # Off for 0.5 second
        yellow.on()  # Repeat blinking
        sleep(0.5)   # Yellow LED on for 0.5 second
        yellow.off() # Turn off yellow LED
        sleep(0.5)   # Off for 0.5 second
        yellow.on()  # Repeat blinking
        sleep(0.5)   # Yellow LED on for 0.5 second
        yellow.off() # Turn off yellow LED
        sleep(0.5)   # Off for 0.5 second

        # Green LED cycle
        green.on()   # Turn on green LED
        sleep(3)     # Green LED on for 3 seconds
        green.off()  # Turn off green LED

except KeyboardInterrupt:
    # Turn off all LEDs and exit safely on keyboard interrupt
    red.off()
    yellow.off()
    green.off()
