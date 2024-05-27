.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson04_mq2:

Lesson 04: Gas Sensor Module (MQ-2)
============================================

In this lesson, you will learn to use the MQ2 gas sensor with Raspberry Pi for gas detection. The course covers connecting the MQ2 sensor to the GPIO17 pin and programming the Raspberry Pi in Python to read the sensor output. You'll understand how to detect gas presence, with a low signal from the sensor indicating the detection of gas. This project offers a practical introduction to sensor usage and Python scripting on the Raspberry Pi, ideal for beginners interested in environmental monitoring and safety applications.

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
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_04_mq2_sensor_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import DigitalInputDevice
   import time
 
   # Initialize MQ2 sensor on GPIO17
   mq2 = DigitalInputDevice(17)
 
   while True:
      # Detect gas presence (LOW signal indicates gas)
      if mq2.value == 0:
         print("Gas detected!")
      else:
         print("No gas detected.")
 
      # Delay between readings
      time.sleep(1)
 

Code Analysis
---------------------------

#. Importing Libraries

   .. code-block:: python
      
      from gpiozero import DigitalInputDevice
      import time

   This section imports necessary libraries. ``gpiozero`` is used for interacting with the GPIO pins of the Raspberry Pi, and ``time`` is used for handling time-related tasks such as delays.

#. Initializing the MQ2 Sensor

   .. code-block:: python

      mq2 = DigitalInputDevice(17)

   Here, the MQ2 sensor is initialized as a digital input device on GPIO pin 17 of the Raspberry Pi. The ``DigitalInputDevice`` class from gpiozero is used for this purpose.

#. Infinite Loop for Sensor Reading

   .. code-block:: python

      while True:
         if mq2.value == 0:
            print("Gas detected!")
         else:
            print("No gas detected.")
         time.sleep(1)

   In this segment:

   .. note::
      The DO pin on the MQ-2 sensor module indicates the presence of combustible gases. When the gas concentration exceeds the threshold value (as set by the potentiometer on the module), D0 becomes LOW; otherwise, it remains HIGH.
   
   - An infinite loop is created using ``while True``. This loop will continue to run until the program is manually stopped.
   - Inside the loop, the value of the MQ2 sensor is checked using ``mq2.value``. If the value is 0, it indicates the presence of gas, and "Gas detected!" is printed. Otherwise, "No gas detected." is printed.
   - ``time.sleep(1)`` creates a delay of 1 second between each reading, reducing the frequency of the sensor checks and the output messages.