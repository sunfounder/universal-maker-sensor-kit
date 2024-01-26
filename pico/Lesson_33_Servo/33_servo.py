import machine
import time

# Initialize PWM on pin 16 for servo control
servo = machine.PWM(machine.Pin(16))
servo.freq(50)  # Set PWM frequency to 50Hz, common for servo motors


def interval_mapping(x, in_min, in_max, out_min, out_max):
    """
    Maps a value from one range to another.
    This function is useful for converting servo angle to pulse width.
    """
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min


def servo_write(pin, angle):
    """
    Moves the servo to a specific angle.
    The angle is converted to a suitable duty cycle for the PWM signal.
    """
    pulse_width = interval_mapping(
        angle, 0, 180, 0.5, 2.5
    )  # Map angle to pulse width in ms
    duty = int(
        interval_mapping(pulse_width, 0, 20, 0, 65535)
    )  # Map pulse width to duty cycle
    pin.duty_u16(duty)  # Set PWM duty cycle


# Main loop to continuously move the servo
while True:
    # Sweep the servo from 0 to 180 degrees
    for angle in range(180):
        servo_write(servo, angle)
        time.sleep_ms(20)  # Short delay for smooth movement

    # Sweep the servo back from 180 to 0 degrees
    for angle in range(180, -1, -1):
        servo_write(servo, angle)
        time.sleep_ms(20)  # Short delay for smooth movement
