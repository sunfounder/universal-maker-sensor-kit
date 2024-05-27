.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson33_servo:

Lesson 33: Servo Motor (SG90)
==================================

In this lesson, you will learn how to control a servo motor (SG90) using the Raspberry Pi Pico W. You will be introduced to the concepts of Pulse Width Modulation (PWM) for controlling the angle of the servo motor. The lesson includes writing a MicroPython script to make the servo sweep smoothly through its entire range of motion, from 0 to 180 degrees and back. 

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_33_Servo_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine
   import time
   
   # Initialize PWM on pin 16 for servo control
   servo = machine.PWM(machine.Pin(16))
   servo.freq(50)  # Set PWM frequency to 50Hz, common for servo motors
   
   
   def interval_mapping(x, in_min, in_max, out_min, out_max):
       """
       Maps a value from one range to another.
       This function is useful for converting servo angle to pulse width.
       """
       return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
   
   
   def servo_write(pin, angle):
       """
       Moves the servo to a specific angle.
       The angle is converted to a suitable duty cycle for the PWM signal.
       """
       pulse_width = interval_mapping(
           angle, 0, 180, 0.5, 2.5
       )  # Map angle to pulse width in ms
       duty = int(
           interval_mapping(pulse_width, 0, 20, 0, 65535)
       )  # Map pulse width to duty cycle
       pin.duty_u16(duty)  # Set PWM duty cycle
   
   
   # Main loop to continuously move the servo
   while True:
       # Sweep the servo from 0 to 180 degrees
       for angle in range(180):
           servo_write(servo, angle)
           time.sleep_ms(20)  # Short delay for smooth movement
   
       # Sweep the servo back from 180 to 0 degrees
       for angle in range(180, -1, -1):
           servo_write(servo, angle)
           time.sleep_ms(20)  # Short delay for smooth movement


Code Analysis
---------------------------

#. Importing Modules and Initializing Servo:

   The ``machine`` module is crucial for accessing the PWM functionality needed to control the servo, and ``time`` is used for implementing delays. The servo is initialized on pin 16 of the Raspberry Pi Pico W, setting its frequency to 50Hz, a typical value for servo control.

   .. code-block:: python

      import machine
      import time
      servo = machine.PWM(machine.Pin(16))
      servo.freq(50)

#. Mapping and Servo Control Functions:

   The ``interval_mapping`` function translates the desired servo angle into a PWM pulse width. The ``servo_write`` function then converts this pulse width into a duty cycle, which is used to set the servo's position. These functions are central to converting the angular position into an appropriate PWM signal.

   Please refer to :ref:`Work Pulse <cpn_servo_pulse>` for information about the work pulse of the servo.

   .. code-block:: python

      def interval_mapping(x, in_min, in_max, out_min, out_max):
          return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

      def servo_write(pin, angle):
          pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5)
          duty = int(interval_mapping(pulse_width, 0, 20, 0, 65535))
          pin.duty_u16(duty)

#. Main Loop for Continuous Movement:

   The main loop is where the servo is controlled to sweep from 0 to 180 degrees and back. This is achieved by looping through the range of angles and calling ``servo_write`` for each angle, with a short delay to ensure smooth movement.

   .. code-block:: python

      while True:
          for angle in range(180):
              servo_write(servo, angle)
              time.sleep_ms(20)
          for angle in range(180, -1, -1):
              servo_write(servo, angle)
              time.sleep_ms(20)