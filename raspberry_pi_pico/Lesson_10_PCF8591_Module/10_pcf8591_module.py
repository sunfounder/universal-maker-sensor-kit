from machine import I2C, Pin
import time
from PCF8591 import PCF8591

# Setup I2C connection on pins 20 (SDA) and 21 (SCL)
i2c = I2C(0, sda=Pin(20), scl=Pin(21))

# Initialize the PCF8591 module at address 0x48
pcf8591 = PCF8591(0x48, i2c)  # Adjust the address if needed

# Check if the PCF8591 module is connected
if pcf8591.begin():
    print("PCF8591 found")

# Main loop to read analog values
while True:
    # Read and print the analog value from channel AIN0
    AIN0 = pcf8591.analog_read(PCF8591.AIN0)
    print("AIN0 ", AIN0)  # PCF8591.CHANNEL_0 can also be used
    # Additional channels can be read by uncommenting the following lines
    # print("AIN1 ", pcf8591.analog_read(PCF8591.AIN1))
    # print("AIN2 ", pcf8591.analog_read(PCF8591.AIN2))
    # print("AIN3 ", pcf8591.analog_read(PCF8591.AIN3))

    # Write the value back to AOUT. This will change the brightness of the D2 LED on the module.
    pcf8591.analog_write(AIN0)

    # Wait for 0.2 seconds before the next read
    time.sleep(0.2)
