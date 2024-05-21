.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pi_lesson26_lcd:

Lesson 26: I2C LCD 1602
==================================

In this lesson, you will learn the basics of displaying text on an LCD screen using a Raspberry Pi. We'll start by showing you how to connect a standard LCD to the Raspberry Pi using the I2C interface. You'll learn how to set up the LCD with simple parameters like the Raspberry Pi model and I2C address. Then, we'll walk you through writing a basic Python script to display messages like "Hello World!" on the screen. This straightforward project is aimed at beginners, offering a foundational introduction to interfacing hardware with the Raspberry Pi and basic Python programming.

Required Components
--------------------------

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


Wiring
---------------------------

.. image:: img/Lesson_26_LCD1602_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import time
   from LCD import LCD

   # Initialize the LCD with specific parameters: Raspberry Pi revision, I2C address, and backlight status
   lcd = LCD(2, 0x27, True)  # Using Raspberry Pi revision 2, I2C address 0x27, backlight enabled

   # Display messages on the LCD
   lcd.message("Hello World!", 1)        # Display 'Hello World!' on line 1
   lcd.message("    - Sunfounder", 2)    # Display '    - Sunfounder' on line 2

   # Keep the messages displayed for 5 seconds
   time.sleep(5)

   # Clear the LCD display
   lcd.clear()


Code Analysis
---------------------------

#. Import Libraries
   
   Import the ``time`` module for creating delays and the ``LCD`` module for controlling the LCD.

   For more detail about the ``LCD`` library, please refer to |link_lcd1602_python_driver_pi|.

   .. code-block:: python

      import time
      from LCD import LCD

#. Initialize the LCD
   
   Create an ``LCD`` object with specific parameters: the Raspberry Pi revision, the I2C address of the LCD, and the backlight status. In this case, Raspberry Pi revision 2(and higher version), I2C address 0x27, and backlight enabled.

   .. code-block:: python

      lcd = LCD(2, 0x27, True)

#. Display Messages on the LCD
   
   Use the ``message`` method of the ``LCD`` object to display text on the LCD. The first argument is the text, and the second argument is the line number.

   .. code-block:: python

      lcd.message("Hello World!", 1)
      lcd.message("    - Sunfounder", 2)

#. Keep the Messages Displayed
   
   Pause the program for 5 seconds, keeping the messages on the LCD during this time.

   .. code-block:: python

      time.sleep(5)

#. Clear the LCD Display
   
   After the delay, clear the display using the ``clear`` method of the ``LCD`` object.

   .. code-block:: python

      lcd.clear()

