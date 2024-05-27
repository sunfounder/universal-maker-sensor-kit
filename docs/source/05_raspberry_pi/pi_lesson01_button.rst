.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson01_button:

Lesson 01: Button Module
==================================

In this lesson, you will learn the basics of using a button with Raspberry Pi. We will show you how to connect a button to GPIO pin 17 and write a simple Python script to monitor its state. You'll learn how to program the Raspberry Pi to detect when the button is pressed and released, and respond with appropriate messages. This introductory project is an excellent way to get familiar with GPIO interaction and basic Python scripting, making it well-suited for beginners starting their journey in Raspberry Pi and hardware programming.

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
    *   - :ref:`cpn_button`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_01_Button_Module_Pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from gpiozero import Button

   # Initialize button connected to GPIO pin 17
   button = Button(17)

   # Continuously check the button state
   while True:
      if button.is_pressed:
         print("Button is pressed")  # Print when button is pressed
      else:
         print("Button is not pressed")  # Print when button is not pressed


Code Analysis
---------------------------

#. Import Library
   
   Import the ``Button`` class from the ``gpiozero`` library for button control.

   .. code-block:: python

      from gpiozero import Button

#. Initialize the Button
   
   Create a ``Button`` object connected to GPIO pin 17.

   .. code-block:: python

      button = Button(17)

#. Monitor Button State Continuously
   
   Use a ``while True`` loop to continuously check the state of the button. If the button is pressed (``button.is_pressed``), it prints "Button is pressed". Otherwise, it prints "Button is not pressed".

   .. code-block:: python

      while True:
          if button.is_pressed:
              print("Button is pressed")
          else:
              print("Button is not pressed")