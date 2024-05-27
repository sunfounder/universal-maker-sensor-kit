.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson33_servo:

Lesson 33: Servo Motor (SG90)
==================================

In this lesson, you will learn how to control a servo motor using a Raspberry Pi. You'll learn how to adjust the servo's pulse width settings for precise control and write a Python script to move the servo to different positions: minimum, middle, and maximum.

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


Wiring
---------------------------

.. image:: img/Lesson_33_Servo_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import Servo
   from time import sleep
   
   # GPIO pin for the servo
   myGPIO = 17
   
   # Correction factor for the servo
   myCorrection = 0.45
   maxPW = (2.0 + myCorrection) / 1000  # Maximum pulse width
   minPW = (1.0 - myCorrection) / 1000  # Minimum pulse width
   
   # Initialize the servo with adjusted pulse width range
   servo = Servo(myGPIO, min_pulse_width=minPW, max_pulse_width=maxPW)
   
   # Continuously move servo between positions
   while True:
      # Move servo to middle position
      servo.mid()
      print("mid")
      sleep(0.5)

      # Move servo to minimum position
      servo.min()
      print("min")
      sleep(1)

      # Move servo to middle position
      servo.mid()
      print("mid")
      sleep(0.5)

      # Move servo to maximum position
      servo.max()
      print("max")
      sleep(1)


Code Analysis
---------------------------

#. Import Libraries
   
   Import the ``Servo`` class from ``gpiozero`` for servo control and ``sleep`` from ``time`` for timing.

   .. code-block:: python

      from gpiozero import Servo
      from time import sleep

#. GPIO Pin and Servo Correction Factor
   
   Define the GPIO pin connected to the servo and set a correction factor to calibrate the servo's pulse width range.

   .. code-block:: python

      myGPIO = 17
      myCorrection = 0.45
      maxPW = (2.0 + myCorrection) / 1000
      minPW = (1.0 - myCorrection) / 1000

#. Initialize the Servo
   
   Create a ``Servo`` object with the specified GPIO pin and adjusted pulse width range.

   .. code-block:: python

      servo = Servo(myGPIO, min_pulse_width=minPW, max_pulse_width=maxPW)

#. Move the Servo Continuously
   
   Use a ``while True`` loop to move the servo between its minimum, middle, and maximum positions, printing the current position and pausing between movements.

   .. code-block:: python

      while True:
          servo.mid()
          print("mid")
          sleep(0.5)

          servo.min()
          print("min")
          sleep(1)

          servo.mid()
          print("mid")
          sleep(0.5)

          servo.max()
          print("max")
          sleep(1)