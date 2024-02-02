from gpiozero import Motor
from time import sleep

# Define pump pins
pump = Motor(forward=17, backward=27)  # Using Raspberry Pi GPIO pin numbers

# Activate the pump
pump.forward(speed=1)  # Set pump speed, range is 0 to 1
sleep(5)               # Run the pump for 5 seconds

# Deactivate the pump
pump.stop()            # Stop the pump
