from machine import Pin, PWM
import time

# Initialize pins for LEDs
red = PWM(Pin(26), freq=1000)  #  red LED
yellow = PWM(Pin(27), freq=1000)  #  yellow LED
green = PWM(Pin(28), freq=1000)  # green LED


# Function to set the brightness of an LED (0-100%)
def set_brightness(led, brightness):
    if brightness < 0 or brightness > 100:
        raise ValueError("Brightness should be between 0 and 100")
    led.duty_u16(int(brightness / 100 * 65535))


try:
    # Example sequence
    while True:
        
        # Green light for 5 seconds
        set_brightness(green, 100)
        time.sleep(5)
        set_brightness(green, 0)

        # Blink Yellow light
        set_brightness(yellow, 100)
        time.sleep(0.5)
        set_brightness(yellow, 0)
        time.sleep(0.5)
        set_brightness(yellow, 100)
        time.sleep(0.5)
        set_brightness(yellow, 0)
        time.sleep(0.5)
        set_brightness(yellow, 100)
        time.sleep(0.5)
        set_brightness(yellow, 0)
        time.sleep(0.5)
        
        # Red light for 5 seconds
        set_brightness(red, 100)
        time.sleep(5)
        set_brightness(red, 0)
        
except KeyboardInterrupt:
    # Turn off RGB LED on interrupt
    set_brightness(red, 0)
    set_brightness(yellow, 0)
    set_brightness(green, 0)
