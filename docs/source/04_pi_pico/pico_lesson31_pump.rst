.. _pico_lesson31_pump:

Lesson 31: Centrifugal Pump
==================================

In this lesson, you will learn how to operate a centrifugal pump using the Raspberry Pi Pico W and an L9110 motor control board. We'll guide you through the process of configuring two PWM (Pulse Width Modulation) pins to control the motor. You'll set up the pump to run for 5 seconds and then turn off. This practical exercise offers a valuable opportunity to delve into motor control mechanisms and PWM signals, crucial in microcontroller programming. 

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_31_Pump_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin, PWM
   import time
   
   pump_a = PWM(Pin(26), freq=1000)
   pump_b = PWM(Pin(27), freq=1000)
   
   # turn on pump
   pump_a.duty_u16(0)
   pump_b.duty_u16(65535)  # speed(0-65535)
   
   time.sleep(5)
   
   # turn off pump
   pump_a.duty_u16(0)
   pump_b.duty_u16(0)


Code Analysis
---------------------------

#. Importing Libraries

   - The ``machine`` module is imported to interact with the GPIO pins and PWM functionalities of the Raspberry Pi Pico W.
   - The ``time`` module is used for creating delays in the code.

   .. raw:: html

      <br/>

   .. code-block:: python

      from machine import Pin, PWM
      import time

#. Initializing PWM Objects

   - Two PWM objects, ``pump_a`` and ``pump_b``, are created. They correspond to GPIO pins 26 and 27, respectively.
   - The frequency for PWM is set to 1000 Hz, a common frequency for motor control.

   .. raw:: html

      <br/>

   .. code-block:: python

      pump_a = PWM(Pin(26), freq=1000)
      pump_b = PWM(Pin(27), freq=1000)

#. Turning on the Pump

   - ``pump_a.duty_u16(0)`` sets the duty cycle of ``pump_a`` pin to 0, while ``pump_b.duty_u16(65535)`` sets the duty cycle of ``pump_b`` pin to 65535, running the motor at full speed. For more details, please refer to :ref:`the working principle of L9110 <cpn_l9110_principle>`.
   - The pump runs for 5 seconds, controlled by ``time.sleep(5)``.

   .. raw:: html

      <br/>

   .. code-block:: python

      # turn on pump
      pump_a.duty_u16(0)
      pump_b.duty_u16(65535)  # speed(0-65535)
      time.sleep(5)

#. Turning off the Pump

   Both ``pump_a`` and ``pump_b`` are set to a duty cycle of 0, stopping the motor.

   .. code-block:: python

      # turn off pump
      pump_a.duty_u16(0)
      pump_b.duty_u16(0)