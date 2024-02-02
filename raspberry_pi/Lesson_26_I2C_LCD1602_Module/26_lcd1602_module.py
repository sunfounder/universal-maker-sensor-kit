import time
from LCD import LCD

# Initialize the LCD with specific parameters: Raspberry Pi revision, I2C address, and backlight status
lcd = LCD(2, 0x27, True)  # Using Raspberry Pi revision 2 and above, I2C address 0x27, backlight enabled

# Display messages on the LCD
lcd.message("Hello World!", 1)        # Display 'Hello World!' on line 1
lcd.message("    - Sunfounder", 2)    # Display '    - Sunfounder' on line 2

# Keep the messages displayed for 5 seconds
time.sleep(5)

# Clear the LCD display
lcd.clear()
