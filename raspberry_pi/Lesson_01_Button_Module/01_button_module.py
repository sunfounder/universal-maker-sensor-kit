from gpiozero import Button

# Initialize button connected to GPIO pin 17
button = Button(17)

# Continuously check the button state
while True:
    if button.is_pressed:
        print("Button is pressed")  # Print when button is pressed
    else:
        print("Button is not pressed")  # Print when button is not pressed
