.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson34_motor:

Lesson 34: TT Motor
==================================

In this lesson, you will learn how to control the speed and direction of a motor using a Raspberry Pi. You'll learn how to program the Raspberry Pi to run the motor at different speeds and in both forward and backward directions. The project will involve setting the motor speed, running it for a specified duration, and then stopping it. This exercise is a practical introduction to motor control with the Raspberry Pi, offering a clear and straightforward experience in hardware control and Python programming, suitable for beginners.

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
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-


Wiring
---------------------------

.. image:: img/Lesson_34_Motor_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import Motor
   from time import sleep

   # Define motor pins
   motor = Motor(forward=17, backward=27)  # Using Raspberry Pi GPIO pin numbers

   # Run the motor forward at half speed
   motor.forward(speed=0.5)  # Set motor speed, range is 0 to 1
   sleep(5)                  # Run the motor for 5 seconds

   # Increase to full speed forward
   motor.forward(speed=1)    # Set motor speed, range is 0 to 1
   sleep(5)                  # Run the motor for 5 seconds

   # Run the motor backward at full speed
   motor.backward(speed=1)   # Set motor speed, range is 0 to 1
   sleep(5)                  # Run the motor for 5 seconds

   # Stop the motor
   motor.stop()


Code Analysis
---------------------------

#. Import Libraries
   
   Import the ``Motor`` class from ``gpiozero`` for motor control, and ``sleep`` from ``time`` for timing control.

   .. code-block:: python

      from gpiozero import Motor
      from time import sleep

#. Define Motor Pins
   
   Create a ``Motor`` object to control a motor connected to GPIO pins 17 and 27 for forward and backward movements, respectively.

   .. code-block:: python

      motor = Motor(forward=17, backward=27)

#. Run the Motor Forward at Half Speed
   
   The motor is run forward at half speed (``speed=0.5``) for 5 seconds. The speed range is between 0 (stopped) and 1 (full speed).

   .. code-block:: python

      motor.forward(speed=0.5)
      sleep(5)

#. Increase to Full Speed Forward
   
   Increase the motor speed to full speed (``speed=1``) in the forward direction, running for another 5 seconds.

   .. code-block:: python

      motor.forward(speed=1)
      sleep(5)

#. Run the Motor Backward at Full Speed
   
   The motor is then run backward at full speed for 5 seconds.

   .. code-block:: python

      motor.backward(speed=1)
      sleep(5)

#. Stop the Motor
   
   Finally, stop the motor using the ``stop`` method.

   .. code-block:: python

      motor.stop()


