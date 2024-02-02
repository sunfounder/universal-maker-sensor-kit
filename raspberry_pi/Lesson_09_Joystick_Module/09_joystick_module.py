import PCF8591 as ADC  # Import ADC module for analog input
import time  # Import time module for creating delay
from gpiozero import Button  # Import Button for button input

ADC.setup(0x48)  # Set up PCF8591 module at I2C address 0x48

button = Button(17)  # Initialize button connected to GPIO 17

try:
    while True:  # Loop continuously
        print("x:", ADC.read(0))  # Read analog value from channel AIN0
        print("y:", ADC.read(1))  # Read analog value from channel AIN1
        print("sw:", button.is_active)  # Check if button is pressed
        time.sleep(0.2)  # Wait for 0.2 seconds before next loop
except KeyboardInterrupt:
    print("Exit")  # End program on keyboard interrupt
