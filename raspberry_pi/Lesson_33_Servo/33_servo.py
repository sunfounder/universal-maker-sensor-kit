from gpiozero import Servo
from time import sleep
 
# GPIO pin for the servo
myGPIO = 17
 
# Correction factor for the servo
myCorrection = 0.45
maxPW = (2.0 + myCorrection) / 1000  # Maximum pulse width
minPW = (1.0 - myCorrection) / 1000  # Minimum pulse width
 
# Initialize the servo with adjusted pulse width range
servo = Servo(myGPIO, min_pulse_width=minPW, max_pulse_width=maxPW)
 
# Continuously move servo between positions
while True:
    # Move servo to middle position
    servo.mid()
    print("mid")
    sleep(0.5)

    # Move servo to minimum position
    servo.min()
    print("min")
    sleep(1)

    # Move servo to middle position
    servo.mid()
    print("mid")
    sleep(0.5)

    # Move servo to maximum position
    servo.max()
    print("max")
    sleep(1)
