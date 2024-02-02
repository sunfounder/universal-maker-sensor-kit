from gpiozero import DigitalInputDevice
from time import time

# Initialize the sensor
sensor = DigitalInputDevice(17)  # Assuming the sensor is connected to GPIO17

def calculate_rps(sample_time=1, steps_per_revolution=20):
    """
    Calculate Revolutions Per Second (RPS)

    :param sample_time: Sampling time in seconds
    :param steps_per_revolution: Number of steps in each complete revolution
    :return: Revolutions per second
    """
    start_time = time()
    end_time = start_time + sample_time
    steps = 0
    last_state = False

    while time() < end_time:
        current_state = sensor.is_active
        if current_state and not last_state:
            # Detect a transition from inactive to active state
            steps += 1
        last_state = current_state

    # Calculate RPS
    rps = steps / steps_per_revolution
    return rps

# Example usage
print("Measuring RPS...")

try:
    while True:
        rps = calculate_rps()  # Default sampling for 1 second
        print(f"RPS: {rps}")
except KeyboardInterrupt:
    # Safely exit the program when a keyboard interrupt is detected
    pass