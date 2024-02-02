import PCF8591 as ADC  # Import the library for the PCF8591 module
import time  # Import the time library for adding delays

# Initialize the PCF8591 module at I2C address 0x48.
# This address is used for communication with the Raspberry Pi.
ADC.setup(0x48)

try:
    while True:  # Start an infinite loop to continuously monitor the sensor.
        # Read the analog value from the potentiometer connected to AIN0.
        # Channel range from 0 to 3 represents AIN0 to AIN3.
        # The potentiometer's rotation alters the voltage, which is read by the PCF8591.
        potentiometer_value = ADC.read(0)
        print(potentiometer_value)

        # Write the value back to AOUT. This will change the brightness of the D2 LED on the module.
        # LED won't light up below 80, so convert '0-255' to '80-255'
        # As the potentiometer is adjusted, the LED's brightness varies proportionally.
        tmp = potentiometer_value*(255-80)/255+80
        ADC.write(tmp)

        # Add a short delay of 0.2 seconds to make the loop more manageable.
        time.sleep(0.2)

except KeyboardInterrupt:
    # If a KeyboardInterrupt (CTRL+C) is detected, exit the loop and end the program.
    print("Exit")
