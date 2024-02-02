from rotary_irq_rp2 import RotaryIRQ
import time
from machine import Pin

# Set GPIO 20 as an input pin for reading the button(sw)'s state
button_pin = Pin(20, Pin.IN, Pin.PULL_UP)

# Initialize the rotary encoder with specific GPIO pins and settings
rotary_encoder = RotaryIRQ(
    pin_num_clk=18,
    pin_num_dt=19,
    min_val=0,
    max_val=14,
    reverse=False,
    range_mode=RotaryIRQ.RANGE_WRAP,
)

# Store the initial value of the rotary encoder and button state
last_rotary_value = rotary_encoder.value()
last_button_state = button_pin.value()

# Main loop
while True:
    # Read the current value of the rotary encoder and button state
    current_rotary_value = rotary_encoder.value()
    current_button_state = button_pin.value()

    # Check if the rotary encoder's value has changed
    if last_rotary_value != current_rotary_value:
        last_rotary_value = current_rotary_value
        print("result =", current_rotary_value)

    # Check if the button's state changed from not pressed to pressed
    if last_button_state and not current_button_state:
        print("Button pressed!")

    # Update the previous state of the button for the next loop iteration
    last_button_state = current_button_state

    # Short delay to prevent debouncing issues
    time.sleep_ms(50)
