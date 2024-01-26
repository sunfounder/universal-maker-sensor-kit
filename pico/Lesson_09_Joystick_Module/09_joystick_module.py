import machine  # Import hardware control module
import time  # Import time module

# Initialize X and Y axes of the joystick
x_joystick = machine.ADC(27)
y_joystick = machine.ADC(26)

# Initialize joystick switch with pull-up resistor
z_switch = machine.Pin(22, machine.Pin.IN, machine.Pin.PULL_UP)

while True:  # Continuous reading loop
    x_value = x_joystick.read_u16()  # Read X-axis value
    y_value = y_joystick.read_u16()  # Read Y-axis value
    z_value = z_switch.value()  # Read switch state

    # Print joystick values and switch state
    print("X: ", x_value, " Y: ", y_value)
    print("SW: ", z_value)

    time.sleep_ms(200)  # Loop every 200 milliseconds
