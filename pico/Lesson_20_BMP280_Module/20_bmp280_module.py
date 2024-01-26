from machine import I2C, Pin
import bmp280
import time

# Initialize I2C communication
i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=100000)

# Configure BMP280 sensor
bmp = bmp280.BMP280(i2c)
bmp.oversample(bmp280.BMP280_OS_HIGH)

while True:
    # Set sensor to weather monitoring mode
    bmp.use_case(bmp280.BMP280_CASE_WEATHER)

    # Print temperature and pressure data
    print("tempC: {}".format(bmp.temperature))
    print("pressure: {}Pa".format(bmp.pressure))

    # Read data every second
    time.sleep_ms(1000)
