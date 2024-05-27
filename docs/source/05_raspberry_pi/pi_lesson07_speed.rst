.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson07_speed:

Lesson 07: Infrared Speed Sensor Module
==========================================

In this lesson, you will learn how to measure rotational speed using a Raspberry Pi and a simple sensor. We'll connect a digital input sensor to GPIO pin 17 and use Python to monitor its state changes. The focus will be on calculating revolutions per second by counting the sensor activations over a specific time period. You'll write a Python function to accurately capture this data and convert it into a measurable speed. This hands-on project is a straightforward yet practical introduction to real-world data collection and analysis with Raspberry Pi, ideal for beginners interested in applied Python programming and hardware interaction.

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
    *   - :ref:`cpn_speed`
        - |link_speed_sensor_module_buy|
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_07_Speed_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import DigitalInputDevice
   from time import time

   # Initialize the sensor
   sensor = DigitalInputDevice(17)  # Assuming the sensor is connected to GPIO17

   def calculate_rps(sample_time=1, steps_per_revolution=20):
       """
       Calculate Revolutions Per Second (RPS)

       :param sample_time: Sampling time in seconds
       :param steps_per_revolution: Number of steps in each complete revolution
       :return: Revolutions per second
       """
       start_time = time()
       end_time = start_time + sample_time
       steps = 0
       last_state = False

       while time() < end_time:
           current_state = sensor.is_active
           if current_state and not last_state:
               # Detect a transition from inactive to active state
               steps += 1
           last_state = current_state

       # Calculate RPS
       rps = steps / steps_per_revolution
       return rps

   # Example usage
   print("Measuring RPS...")

   try:
       while True:
           rps = calculate_rps()  # Default sampling for 1 second
           print(f"RPS: {rps}")
   except KeyboardInterrupt:
       # Safely exit the program when a keyboard interrupt is detected
       pass



Code Analysis
---------------------------


#. Importing Libraries
   
   The script starts by importing ``DigitalInputDevice`` from gpiozero for sensor interaction and ``time`` for time management.

   .. code-block:: python

      from gpiozero import DigitalInputDevice
      from time import time

#. Initializing the Sensor
   
   A ``DigitalInputDevice`` object named ``sensor`` is created, connected to GPIO pin 17. This setup assumes that the digital sensor is connected to GPIO17.

   .. code-block:: python

      sensor = DigitalInputDevice(17)

#. Defining the ``calculate_rps`` Function
   
   - This function calculates the Revolutions Per Second (RPS) of a rotating object.
   - ``sample_time`` is the duration in seconds for which the sensor's output is sampled.
   - ``steps_per_revolution`` represents the number of sensor activations per complete revolution.
   - The function uses a while loop to count the number of steps (sensor activations) within the sample time.
   - It detects transitions from inactive to active states and increments the ``steps`` count accordingly.
   - RPS is calculated as the number of steps divided by ``steps_per_revolution``.

   .. raw:: html

      <br/>

   .. code-block:: python

      def calculate_rps(sample_time=1, steps_per_revolution=20):
          """
          Calculate Revolutions Per Second (RPS)
      
          :param sample_time: Sampling time in seconds
          :param steps_per_revolution: Number of steps in each complete revolution
          :return: Revolutions per second
          """
          start_time = time()
          end_time = start_time + sample_time
          steps = 0
          last_state = False
      
          while time() < end_time:
              current_state = sensor.is_active
              if current_state and not last_state:
                  # Detect a transition from inactive to active state
                  steps += 1
              last_state = current_state
      
          # Calculate RPS
          rps = steps / steps_per_revolution
          return rps

#. Running the Main Loop
   
   - The script then enters a continuous loop where it calls ``calculate_rps`` to calculate and print the RPS.
   - The loop runs indefinitely until a keyboard interrupt (Ctrl+C) is detected.
   - A ``try-except`` block is used to handle the interrupt gracefully, allowing for a safe exit.

   .. code-block:: python

      try:
          while True:
              rps = calculate_rps()  # Default sampling for 1 second
              print(f"RPS: {rps}")
      except KeyboardInterrupt:
          pass

