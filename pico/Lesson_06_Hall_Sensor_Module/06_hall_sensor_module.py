import machine
import utime

# Initialize an ADC on GPIO pin 26 for Hall effect sensor readings.
hall_sensor = machine.ADC(26)

# Continuously monitor and process Hall sensor data.
while True:
    # Read the analog value from the sensor and convert to a 16-bit integer.
    value = hall_sensor.read_u16()
    print(value, end="")  # Output the raw sensor value.

    # Detect and print the type of magnetic pole based on the sensor reading.
    if value >= 48000:
        print(" - South pole detected", end="")
    elif value <= 18000:
        print(" - North pole detected", end="")

    print()

    # Wait 200 milliseconds before the next sensor reading
    utime.sleep_ms(200)
