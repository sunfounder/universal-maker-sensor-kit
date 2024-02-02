from gpiozero import Motor
from time import sleep

# Define motor pins
motor = Motor(forward=17, backward=27)  # Using Raspberry Pi GPIO pin numbers

# Run the motor forward at half speed
motor.forward(speed=0.5)  # Set motor speed, range is 0 to 1
sleep(5)                  # Run the motor for 5 seconds

# Increase to full speed forward
motor.forward(speed=1)    # Set motor speed, range is 0 to 1
sleep(5)                  # Run the motor for 5 seconds

# Run the motor backward at full speed
motor.backward(speed=1)   # Set motor speed, range is 0 to 1
sleep(5)                  # Run the motor for 5 seconds

# Stop the motor
motor.stop()
