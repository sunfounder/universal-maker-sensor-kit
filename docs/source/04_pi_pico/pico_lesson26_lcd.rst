.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _pico_lesson26_lcd:

Lesson 26: I2C LCD 1602
==================================

In this lesson, you will learn to connect an I2C LCD 1602 display to a Raspberry Pi Pico W. You'll understand how to set up I2C communication, display and clear messages on the LCD using MicroPython. 


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

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. note:: 
   To ensure the LCD module operates normally, please power it using the VBUS pin on the Pico.

.. image:: img/Lesson_26_LCD1602_Module_pico_bb.png
    :width: 100%


Code
---------------------------

.. note::

    * Open the ``26_lcd1602_module.py`` file under the path of ``universal-maker-sensor-kit-main/pico/Lesson_26_I2C_LCD1602_Module`` or copy this code into Thonny, then click "Run Current Script" or simply press F5 to run it. For detailed tutorials, please refer to :ref:`open_run_code_py`. 

    * Here you need to use the ``lcd1602.py``, please check if it has been uploaded to Pico W, for a detailed tutorial refer to :ref:`add_libraries_py`.

    * Don't forget to click on the "MicroPython (Raspberry Pi Pico)" interpreter in the bottom right corner. 

.. code-block:: python

   from machine import I2C, Pin
   from lcd1602 import LCD
   import time
   
   # Initialize I2C communication;
   # Set SDA to pin 20, SCL to pin 21, and frequency to 400kHz
   i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=400000)
   
   # Create an LCD object for interfacing with the LCD1602 display
   lcd = LCD(i2c)
   
   # Display the first message on the LCD
   # Use '\n' to create a new line.
   string = "SunFounder\n    LCD Tutorial"
   lcd.message(string)
   # Wait for 2 seconds
   time.sleep(2)
   # Clear the display
   lcd.clear()
   
   # Display the second message on the LCD
   string = "Hello\n  World!"
   lcd.message(string)
   # Wait for 5 seconds
   time.sleep(5)
   # Clear the display before exiting
   lcd.clear()


Code Analysis
---------------------------

#. Setting up I2C Communication

   The ``machine`` module is used to set up I2C communication. SDA (Serial Data) and SCL (Serial Clock) pins are defined (pin 20 and 21 respectively), along with the I2C frequency (400kHz).

   .. code-block:: python
      
      from machine import I2C, Pin
      i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=400000)

#. Initializing the LCD Display

   The ``LCD`` class from the ``lcd1602`` module is instantiated. This class handles the communication with the LCD display through I2C. An ``LCD`` object is created using the ``i2c`` object.

   For more usage of the ``lcd1602`` library, please refer to ``lcd1602.py``.

   .. code-block:: python
      
      from lcd1602 import LCD
      lcd = LCD(i2c)

#. Displaying Messages on the LCD

   The ``message`` method of the ``LCD`` object is used to display text on the screen. The ``\n`` character creates a new line on the LCD. The ``time.sleep()`` function pauses execution for a specified number of seconds.

   .. code-block:: python
      
      string = "SunFounder\n    LCD Tutorial"
      lcd.message(string)
      time.sleep(2)
      lcd.clear()

#. Clearing the Display

   The ``clear`` method of the ``LCD`` object is called to clear the text from the display.

   .. code-block:: python
      
      lcd.clear()

#. Displaying a Second Message

   A new message is displayed, followed by a delay and then clearing the screen again.

   .. code-block:: python
      
      string = "Hello\n  World!"
      lcd.message(string)
      time.sleep(5)
      lcd.clear()