.. _pi_lesson28_rgb_module:

Lesson 28: RGB Module
==================================

In this lesson, you will learn how to control an RGB LED module with a Raspberry Pi. You'll learn how to use Python to change the LED's color to red, green, blue, and yellow, and then turn it off. This project is a straightforward introduction to working with RGB LEDs and GPIO interfacing, making it ideal for beginners starting with Raspberry Pi and Python programming.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_28_RGB_LED_Module_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import RGBLED  
   from time import sleep  
   from colorzero import Color  

   # GPIO pin assignments for the RGB LED
   red_pin = 22
   green_pin = 27
   blue_pin = 17

   # Initialize the RGB LED with red, green, and blue components connected to their respective GPIO pins
   led = RGBLED(red=red_pin, green=green_pin, blue=blue_pin)

   # Set the LED to red color (red: 100%, green: 0%, blue: 0%) and wait for 1 second
   led.color = (1, 0, 0)
   sleep(1)

   # Set the LED to green color (red: 0%, green: 100%, blue: 0%) and wait for 1 second
   led.color = (0, 1, 0)
   sleep(1)

   # Set the LED to blue color (red: 0%, green: 0%, blue: 100%) and wait for 1 second
   led.color = (0, 0, 1)
   sleep(1)

   # Set the LED to yellow color using the Color class and wait for 1 second
   led.color = Color('yellow')
   sleep(1)

   # Turn the LED off
   led.off()



Code Analysis
---------------------------

#. Importing Libraries
   
   The script starts with importing the ``RGBLED`` class from gpiozero for controlling the RGB LED and the ``sleep`` function from the time module for delays. It also imports the ``Color`` class from colorzero for color definitions.

   .. code-block:: python

      from gpiozero import RGBLED  
      from time import sleep  
      from colorzero import Color  

#. Initializing the RGB LED
   
   - GPIO pins for each color component of the RGB LED are defined. 
   - The RGB LED is initialized with its red, green, and blue components connected to GPIO pins 22, 27, and 17 respectively.

   .. code-block:: python

      red_pin = 22
      green_pin = 27
      blue_pin = 17
      led = RGBLED(red=red_pin, green=green_pin, blue=blue_pin)

#. Setting LED Colors
   
   - The color of the LED is set to red, green, and blue in sequence, each followed by a 1-second pause. 
   - Colors are represented by tuples (red, green, blue), where each value is between 0 and 1, indicating the intensity.

   .. code-block:: python

      led.color = (1, 0, 0)
      sleep(1)
      led.color = (0, 1, 0)
      sleep(1)
      led.color = (0, 0, 1)
      sleep(1)

#. Using the Color Class
   
   The script demonstrates how to use the ``Color`` class from colorzero to set the LED to a named color (``yellow``) and then waits for 1 second.

   In addition to using the pre-defined colors directly, you can also define colors in various ways. For more details, please refer to |link_gpiozero_color|.

   .. code-block:: python

      led.color = Color('yellow')
      sleep(1)

#. Turning the LED Off
   
   Finally, the script turns off the LED using ``led.off()``.

   .. code-block:: python

      led.off()
