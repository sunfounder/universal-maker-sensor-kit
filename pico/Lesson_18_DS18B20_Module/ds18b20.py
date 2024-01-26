from machine import Pin
import onewire
import time, ds18x20

# Initialize the OneWire bus on GPIO pin 12
ow = onewire.OneWire(Pin(12))

# Create a DS18X20 instance using the OneWire bus
ds = ds18x20.DS18X20(ow)

# Scan for DS18X20 devices on the bus and print their addresses
roms = ds.scan()
print('found devices:', roms)

# Continuously read and print temperature data from the sensors
while True:
    # Start the temperature conversion process
    ds.convert_temp()
    # Wait for the conversion to complete (750 ms for DS18X20)
    time.sleep_ms(750)
    
    # Read and print the temperature from each sensor found on the bus
    for rom in roms:
        print(ds.read_temp(rom))
    
    # Wait for a short period before the next reading (1000 ms)
    time.sleep_ms(1000)
