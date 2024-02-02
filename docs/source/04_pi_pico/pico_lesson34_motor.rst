.. _pico_lesson34_motor:

Lesson 34: TT Motor
==================================

In this lesson, you will learn how to operate a TT motor using the Raspberry Pi Pico W and an L9110 motor control board. We'll guide you through the process of configuring two PWM (Pulse Width Modulation) pins to control the motor. You'll set up the motor to run for 5 seconds and then turn off. This practical exercise offers a valuable opportunity to delve into motor control mechanisms and PWM signals, crucial in microcontroller programming. 

Required Components
---------------------------

* Raspberry Pi Pico W
* :ref:`cpn_ttmotor`
* :ref:`cpn_l9110`
* :ref:`cpn_breadboard`

Wiring
---------------------------

.. image:: img/Lesson_34_Motor_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin, PWM
   import time
   
   motor_a = PWM(Pin(26), freq=1000)
   motor_b = PWM(Pin(27), freq=1000)
   
   # turn on motor
   motor_a.duty_u16(0)
   motor_b.duty_u16(65535)  # speed(0-65535)
   
   time.sleep(5)
   
   # turn off motor
   motor_a.duty_u16(0)
   motor_b.duty_u16(0)

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

   - Two PWM objects, ``motor_a`` and ``motor_b``, are created. They correspond to GPIO pins 26 and 27, respectively.
   - The frequency for PWM is set to 1000 Hz, a common frequency for motor control.

   .. raw:: html

      <br/>

   .. code-block:: python

      motor_a = PWM(Pin(26), freq=1000)
      motor_b = PWM(Pin(27), freq=1000)

#. Turning on the Motor

   - ``motor_a.duty_u16(0)`` sets the duty cycle of ``motor_a`` pin to 0, while ``motor_b.duty_u16(65535)`` sets the duty cycle of ``motor_b`` pin to 65535, running the motor at full speed. For more details, please refer to :ref:`the working principle of L9110 <cpn_l9110_principle>`.
   - The motor runs for 5 seconds, controlled by ``time.sleep(5)``.

   .. raw:: html

      <br/>

   .. code-block:: python

      # turn on motor
      motor_a.duty_u16(0)
      motor_b.duty_u16(65535)  # speed(0-65535)
      time.sleep(5)

#. Turning off the Motor

   Both ``motor_a`` and ``motor_b`` are set to a duty cycle of 0, stopping the motor.

   .. code-block:: python

      # turn off motor
      motor_a.duty_u16(0)
      motor_b.duty_u16(0)