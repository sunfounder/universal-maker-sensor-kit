import dht
import machine
import time

# Initialize DHT11 sensor on GPIO 16
d = dht.DHT11(machine.Pin(16))

# Continuously read and print temperature and humidity
while True: 
    d.measure()    
    print("Temperature:" ,d.temperature())  # Print temperature
    print("Humidity:" ,d.humidity())  # Print humidity
    time.sleep_ms(1000)  # Read every second
