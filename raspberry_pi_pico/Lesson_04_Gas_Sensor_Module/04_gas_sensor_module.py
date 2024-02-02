import machine
import time

# Initialize an ADC object on GPIO pin 26.
# This is typically used for reading analog signals.
mq2_AO = machine.ADC(26)

# Continuously read and print sensor data.
while True:
    value = mq2_AO.read_u16()  # Read and convert analog value to 16-bit integer
    print("AO:", value)  # Print the analog value

    time.sleep_ms(200)  # Wait for 200 milliseconds before the next read
