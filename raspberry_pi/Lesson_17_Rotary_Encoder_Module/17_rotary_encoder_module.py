from gpiozero import RotaryEncoder, Button  
from time import sleep  

# Initialize the rotary encoder on GPIO pins 17(CLK) and 27(DT) with wrap-around at max_steps of 16
encoder = RotaryEncoder(a=17, b=27, wrap=True, max_steps=16)
# Initialize the rotary encoder's SW pin on GPIO pin 22
button = Button(22)

last_rotary_value = 0  # Variable to store the last value of rotary encoder

try:
    while True:  # Infinite loop to continuously monitor the encoder
        current_rotary_value = encoder.steps  # Read current step count from rotary encoder

        # Check if the rotary encoder value has changed
        if last_rotary_value != current_rotary_value:
            print("Result =", current_rotary_value)  # Print the current value
            last_rotary_value = current_rotary_value  # Update the last value

        # Check if the rotary encoder is pressed
        if button.is_pressed:
            print("Button pressed!")  # Print message on button press
            button.wait_for_release()  # Wait until button is released

        sleep(0.1)  # Short delay to prevent excessive CPU usage

except KeyboardInterrupt:
    print("Program terminated")  # Print message when program is terminated via keyboard interrupt
