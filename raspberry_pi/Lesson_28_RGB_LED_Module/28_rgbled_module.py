from gpiozero import RGBLED  
from time import sleep  
from colorzero import Color  

# GPIO pin assignments for the RGB LED
red_pin = 22
green_pin = 27
blue_pin = 17

# Initialize the RGB LED with red, green, and blue components connected to their respective GPIO pins
led = RGBLED(red=red_pin, green=green_pin, blue=blue_pin)

# Set the LED to red color (red: 100%, green: 0%, blue: 0%) and wait for 1 second
led.color = (1, 0, 0)
sleep(1)

# Set the LED to green color (red: 0%, green: 100%, blue: 0%) and wait for 1 second
led.color = (0, 1, 0)
sleep(1)

# Set the LED to blue color (red: 0%, green: 0%, blue: 100%) and wait for 1 second
led.color = (0, 0, 1)
sleep(1)

# Set the LED to yellow color using the Color class and wait for 1 second
led.color = Color('yellow')
sleep(1)

# Turn the LED off
led.off()
