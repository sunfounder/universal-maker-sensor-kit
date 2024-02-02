from gpiozero import DigitalInputDevice
import time

# Initialize MQ2 sensor on GPIO17
mq2 = DigitalInputDevice(17)

while True:
    # Detect gas presence (LOW signal indicates gas)
    if mq2.value == 0:
        print("Gas detected!")
    else:
        print("No gas detected.")

    # Delay between readings
    time.sleep(1)
