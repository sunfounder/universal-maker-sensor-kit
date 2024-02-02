from gpiozero import Button
from signal import pause

# Function called when the sensor is touched
def touched():
    # Print a message indicating the sensor is touched
    print("Touched!")  

# Function called when the sensor is not touched
def not_touched():
    # Print a message indicating the sensor is not touched
    print("Not touched!")  

# Initialize a Button object for the touch sensor
# GPIO 17: pin connected to the sensor
# pull_up=None: disable internal pull-up/pull-down resistors
# active_state=True: high voltage is considered the active state
touch_sensor = Button(17, pull_up=None, active_state=True)

# Assign functions to sensor events
touch_sensor.when_pressed = touched
touch_sensor.when_released = not_touched

pause()  # Keep the program running to detect touch events
