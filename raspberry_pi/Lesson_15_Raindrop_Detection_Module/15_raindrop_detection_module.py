from gpiozero import DigitalInputDevice  
from time import sleep  

# Initialize the sensor as a digital input device on GPIO pin 17
rain_sensor = DigitalInputDevice(17)

while True:  # Infinite loop to continuously check the sensor status
    if rain_sensor.is_active:  # Check if the sensor is active (no rain)
        print("No rain detected.")  # Print message for no rain detected
    else:
        print("Rain detected!")  # Print message for rain detected
    sleep(1)  # Wait for 1 second before next check
