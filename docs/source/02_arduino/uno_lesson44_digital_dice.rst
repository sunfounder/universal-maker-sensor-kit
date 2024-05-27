
.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_digital_dice:

Lesson 44: Digital Dice
=============================================================


This program simulates a dice roll using an OLED display. 
The simulation is triggered by shaking the vibration switch, causing the display to cycle through numbers 1 to 6, 
akin to rolling a dice. 
The display halts after a short duration, revealing a randomly selected number that represents the dice roll outcome.



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

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Wiring
---------------------------

.. image:: img/Lesson_44_Digital_dice_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/70e73ef9-2968-4845-befd-23185286fd93/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code Analysis
---------------------------

A comprehensive breakdown of the code:

1. Initialization of variables:

   ``vibPin``: Digital pin connected to the vibration sensor.

2. Volatile variables:

   ``rolling``: A volatile flag that indicates the dice's rolling status. It is volatile as it is accessed within both the interrupt service routine and the main program.

3. ``setup()``:

   Configures the vibration sensor's input mode.
   Assigns an interrupt to the sensor to trigger the rollDice function upon state change.
   Initializes the OLED display.

4. ``loop()``:

   Continuously checks if ``rolling`` is true, displaying a random number between 1 and 6 during this state. The rolling ceases if the sensor has been shaken for over 500 milliseconds.

5. ``rollDice()``:

   The interrupt service routine for the vibration sensor. It initiates the dice roll when the sensor is shaken by recording the current time.

6. ``displayNumber()``:

   Displays a selected number on the OLED screen.