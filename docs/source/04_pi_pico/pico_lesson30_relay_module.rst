.. _pico_lesson30_relay_module:

Lesson 30: Relay Module
==================================

In this lesson, you will learn how to use the Raspberry Pi Pico W to control a relay module. We will set up a basic circuit connecting the relay to the Pi and write a MicroPython script to toggle the relay on and off at one-second intervals. This project introduces you to controlling external devices such as relays and demonstrates practical output operations using the GPIO pins on the Raspberry Pi Pico W. Ideal for those interested in delving into home automation or managing other high-power devices, this lesson offers fundamental insight into how microcontrollers can interact with and control external hardware.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_30_Relay_Module_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Replace this number with the GPIO pin number your relay is connected to
   relay_pin = Pin(16, Pin.OUT)
   
   def relay_on():
       relay_pin.value(1)  # Set relay to ON state
   
   def relay_off():
       relay_pin.value(0)  # Set relay to OFF state
   
   try:
       while True:
           relay_on()
           print("on....")
           time.sleep(1)  # Wait for 1 second
           relay_off()
           print("off....")
           time.sleep(1)  # Wait for 1 second
   except:
       relay_off()  # Ensure the relay is turned off in case of an exception
       print("Program interrupted, relay turned off.")


Code Analysis
---------------------------

#. Importing Libraries
   
   The ``machine`` and ``time`` libraries are imported to interact with GPIO pins and handle time-related functions, respectively.

   .. code-block:: python

      from machine import Pin
      import time

#. Initializing Relay Pin

   A GPIO pin is set up as an output pin to control the relay. The ``relay_pin`` variable represents the GPIO pin connected to the relay.

   .. code-block:: python

      relay_pin = Pin(16, Pin.OUT)

#. Defining Relay Control Functions
   
   Two functions, ``relay_on`` and ``relay_off``, are defined to turn the relay on and off, respectively. These functions change the GPIO pin's value to high (1) or low (0).

   .. code-block:: python

      def relay_on():
          relay_pin.value(1)  # Set relay to ON state

      def relay_off():
          relay_pin.value(0)  # Set relay to OFF state

#. Main Loop and Exception Handling
   
   A continuous loop is created using ``while True``. Inside this loop, the relay is turned on and off with a 1-second delay between each state. If an interruption occurs (like a keyboard interruption), the relay is turned off for safety, and a message is printed.

   .. code-block:: python

      try:
          while True:
              relay_on()
              print("on....")
              time.sleep(1)  # Wait for 1 second
              relay_off()
              print("off....")
              time.sleep(1)  # Wait for 1 second
      except:
          relay_off()  # Ensure the relay is turned off in case of an exception
          print("Program interrupted, relay turned off.")