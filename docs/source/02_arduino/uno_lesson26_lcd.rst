.. _uno_lesson26_lcd:

Lesson 26: I2C LCD 1602
==================================

In this lesson, you will learn how to set up and display messages on a 16x2 Liquid Crystal Display (LCD) with an I2C interface using Arduino. We'll cover the basics of using the LiquidCrystal I2C library to initialize the LCD, display text, and control the backlight. You'll see how to print "Hello world!" and "LCD Tutorial" on the display, providing a hands-on introduction to interfacing LCDs with Arduino. This tutorial is perfect for beginners as it offers a practical lesson in controlling electronic displays.


Required Components
---------------------------

* Arduino UNO R3 or R4
* :ref:`cpn_i2c_lcd1602`

Wiring
---------------------------

.. image:: img/Lesson_26_I2C_lcd_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/48a64786-bcfc-4497-a12d-495c283e09ce/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. Library Inclusion and LCD Initialization:
   The LiquidCrystal I2C library is included to provide functions and methods for LCD interfacing. Following that, an LCD object is created using the LiquidCrystal_I2C class, specifying the I2C address, number of columns, and number of rows.

   .. note:: 
      To install the library, use the Arduino Library Manager and search for **"LiquidCrystal I2C"** and install it.  

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. Setup Function:
   The ``setup()`` function is executed once when the Arduino starts. In this function, the LCD is initialized, cleared, and the backlight is turned on. Then, two messages are displayed on the LCD.

   .. code-block:: arduino

      void setup() {
        lcd.init();       // initialize the LCD
        lcd.clear();      // clear the LCD display
        lcd.backlight();  // Make sure backlight is on
      
        // Print a message on both lines of the LCD.
        lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
        lcd.print("Hello world!");
      
        lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
        lcd.print("LCD Tutorial");
      }