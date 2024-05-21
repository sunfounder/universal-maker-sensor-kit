.. _pico_lesson27_oled:

Lesson 27: OLED Display Module (SSD1306)
============================================

In this lesson, you will learn how to connect and display text and graphics on an OLED display module (SSD1306) using the Raspberry Pi Pico W. You'll set up the I2C communication, use MicroPython to program the Pico W to control the OLED display, and practice displaying simple text messages.

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
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. note:: 
   To ensure the OLED module operates normally, please power it using the VBUS pin on the Pico.

.. image:: img/Lesson_27_oled_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin, I2C
   import ssd1306
   import time
   
   # setup the I2C communication
   i2c = I2C(0, sda=Pin(20), scl=Pin(21))
   
   # Set up the OLED display (128x64 pixels) on the I2C bus
   # SSD1306_I2C is a subclass of FrameBuffer. FrameBuffer provides support for graphics primitives.
   # http://docs.micropython.org/en/latest/pyboard/library/framebuf.html
   oled = ssd1306.SSD1306_I2C(128, 64, i2c)
   
   # Clear the display by filling it with white and then showing the update
   oled.fill(1)
   oled.show()
   time.sleep(1)  # Wait for 1 second
   
   # Clear the display again by filling it with black
   oled.fill(0)
   oled.show()
   time.sleep(1)  # Wait for another second
   
   # Display text on the OLED screen
   oled.text('Hello,', 0, 0)  # Display "Hello," at position (0, 0)
   oled.text('sunfounder.com', 0, 16)  # Display "sunfounder.com" at position (0, 16)
   
   # The following line sends what to show to the display
   oled.show()

Code Analysis
---------------------------

#. Initializing the I2C communication:

   This code segment sets up the I2C communication protocol. I2C is a standard protocol for communication between devices. It uses two lines: SDA (data line) and SCL (clock line).
   
   .. code-block:: python

      from machine import Pin, I2C
      i2c = I2C(0, sda=Pin(20), scl=Pin(21))

#. Setting up the OLED display:

   Here, we initialize the SSD1306 OLED display with the I2C protocol. The parameters 128 and 64 define the width and height of the display in pixels, respectively.

   For more information about the ``ssd1306`` library, please visit |link_micropython_ssd1306_driver|.

   .. code-block:: python

      import ssd1306
      oled = ssd1306.SSD1306_I2C(128, 64, i2c)

#. Clearing the display:

   The display is cleared by filling it with white (1) and then updating the display with ``oled.show()``. The ``time.sleep(1)`` command adds a one-second delay. Then, the display is cleared again by filling it with black (0).

   SSD1306_I2C is a subclass of FrameBuffer, which supports graphics primitives. If you want to display other patterns, please refer to |link_FrameBuffer_doc|.

   .. code-block:: python
      
      oled.fill(1)
      oled.show()
      time.sleep(1)
      oled.fill(0)
      oled.show()
      time.sleep(1)

#. Displaying text:

   The ``oled.text`` method is used to display text on the screen. The parameters are the text to display and the x, y coordinates on the screen. Finally, ``oled.show()`` updates the display to show the text.

   .. code-block:: python

      oled.text('Hello,', 0, 0)
      oled.text('sunfounder.com', 0, 16)
      oled.show()