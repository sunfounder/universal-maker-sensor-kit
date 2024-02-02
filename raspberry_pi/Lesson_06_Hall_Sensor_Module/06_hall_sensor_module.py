import PCF8591 as ADC  # Import PCF8591 module
import time  # Import time for delay

ADC.setup(0x48)  # Initialize PCF8591 at address 0x48

try:
    while True:  # Continuously read and print
        sensor_value = ADC.read(1) # Read from hall sensor module at AIN1
        print(sensor_value,end="")  # Print the sensor raw data

        # Determine the polarity of the magnet
        if sensor_value >= 180:
            print(" - South pole detected")   # Determined as South pole.
        elif sensor_value <= 80:
            print(" - North pole detected")   # Determined as North pole.

        time.sleep(0.2)  # Wait for 0.2 seconds before the next read

except KeyboardInterrupt:
    print("Exit")  # Exit on CTRL+C
