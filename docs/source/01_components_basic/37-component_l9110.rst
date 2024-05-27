.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _cpn_l9110:

L9110 Motor Driver Module
=============================

The L9110 motor driver module is adept at driving two motors in tandem. It houses a pair of independent L9110S driver chips, each channel boasting a steady current output of up to 800mA.

Spanning a voltage range from 2.5V to 12V, the module comfortably pairs with both 3.3V and 5V microcontrollers.

Serving as a streamlined solution, the L9110 motor driver module facilitates motor control across a spectrum of applications. 
Thanks to its dual-channel architecture, it enables the independent orchestration of two motors—ideal for projects where dual motor operations are paramount.

Given its potent continuous current output, this module confidently powers motors from the petite to the moderately sized, paving the way for diverse robotic, automation, and motor-centric endeavors. Its expansive voltage range further injects adaptability, aligning with varied power supply setups.

Designed with user-friendliness in mind, the module offers intuitive input and output terminals, simplifying connections to microcontrollers or akin control devices. Plus, it doesn't skimp on safety—integrated overcurrent and overtemperature safeguards bolster the trustworthiness and security of motor operations.

.. image:: img/37_l9110_module.jpg
    :width: 80%
    :align: center
    
* **B-1A & B-1B(B-2A)**: Input pins for controlling the spinning direction of Motor B.
* **A-1A & A-1B**: Input pins for controlling the spinning direction of Motor A.
* **0A & OB(A)**: Output pins of Motor A.
* **0A & OB(B)**: Output pins of Motor B.
* **VCC**: Power input pin (2.5V-12V).
* **GND**: Ground pin.

**Features**

* On-board 2 L9110S motor control chip
* Dual-channel motor control.
* Independent motor spinning direction control.
* High current output (800mA per channel).
* Wide voltage range (2.5V-12V).
* Compact design.
* Convenient input and output terminals.
* Built-in protective features.
* Versatile applications.
* PCB Size: 29.2mm x 23mm
* Operating Temperature: -20°C ~ 80°C
* Power-On LED indicator

.. _cpn_l9110_principle:

**Operating Principle**

Here is the truth table of Motor B:

This truth table shows the different states of Motor B based on the values of input pins B-1A and B-1B(B-2A). It indicates the direction of rotation (clockwise or counterclockwise), braking, or stopping of Motor B.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - The state of Motor B
    * - 1
      - 0
      - Rotate clockwise
    * - 0
      - 1
      - Rotate counterclockwise
    * - 0
      - 0
      - Brake
    * - 1
      - 1
      - Stop

Here is the truth table of Motor A:

This truth table shows the different states of Motor A based on the values of input pins A-1A and A-1B. It indicates the direction of rotation (clockwise or counterclockwise), braking, or stopping of Motor A.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - The state of Motor B
    * - 1
      - 0
      - Rotate clockwise
    * - 0
      - 1
      - Rotate counterclockwise
    * - 0
      - 0
      - Brake
    * - 1
      - 1
      - Stop

Example
---------------------------
* :ref:`uno_lesson31_pump` (Arduino UNO)
* :ref:`esp32_lesson31_pump` (ESP32)
* :ref:`pico_lesson31_pump` (Raspberry Pi Pico)
* :ref:`pi_lesson31_pump` (Raspberry Pi)

* :ref:`uno_lesson34_motor` (Arduino UNO)
* :ref:`esp32_lesson34_motor` (ESP32)
* :ref:`pico_lesson34_motor` (Raspberry Pi Pico)
* :ref:`pi_lesson34_motor` (Raspberry Pi)

* :ref:`uno_lesson07_speed` (Arduino UNO)
* :ref:`pi_lesson07_speed` (Raspberry Pi)

* :ref:`uno_lesson39_soap_dispenser` (Arduino UNO)
* :ref:`uno_plant_monitor` (Arduino UNO)
* :ref:`esp32_soap_dispenser` (ESP32)
* :ref:`esp32_plant_monitor` (ESP32)
