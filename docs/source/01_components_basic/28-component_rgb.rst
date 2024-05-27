.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _cpn_rgb:

RGB LED Module
==========================

.. image:: img/28_rgb_module.png
    :width: 350
    :align: center

.. raw:: html
    
    <br/>

The RGB Full Color LED module emits a range of colors by mixing red, green, and blue light. Each color is adjusted by using PWM.It can be used to create colorful lighting effects or to learn how to use PWM (pulse-width modulation) with Arduino.

Pinout
---------------------------

* **GND**: Common ground for power.
* **B**: Controls the brightness of the red LED. By adjusting the current flowing through this pin, the intensity of the red light can be varied.
* **R**: Controls the brightness of the green LED. Similarly to the red pin, adjusting the current flow through this pin changes the intensity of the green light.
* **G**: Controls the brightness of the blue LED. By adjusting the current flowing through this pin, the intensity of the blue light can be altered.

Principle
---------------------------
The RGB MODULE works by using a full-color LED that uses R, G, and B pins with adjustable PWM voltage input. 
Colors from the LED can be combined. For example, mix blue light and green light give cyan light, red light and green light give yellow light. This is called "The additive method of color mixing".

* `Additive color - Wikipedia <https://en.wikipedia.org/wiki/Additive_color>`_

.. image:: img/28_rgb_module_2.png
    :width: 200
    :align: center

Based on this method, we can use the three primary colors to mix the visible light of any color according to different proportions. For example, orange can be produced by more red and less green.
The strength of the primary colors (red, blue, green) is adjusted in order to achieve full color mixing effect.PWM is a technique where the duty cycle of a digital signal is modified, adjusting the percentage of time that the signal remains active within a given period. By changing the duty cycle, we can make the LED appear brighter or dimmer.

Schematic diagram
---------------------------

.. image:: img/28_rgb_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>


Example
---------------------------
* :ref:`uno_lesson28_rgb_module` (Arduino UNO)
* :ref:`esp32_lesson28_rgb_module` (ESP32)
* :ref:`pico_lesson28_rgb_module` (Raspberry Pi Pico)
* :ref:`pi_lesson28_rgb_module` (Raspberry Pi)

* :ref:`esp32_lesson30_relay_module` (ESP32)
* :ref:`pico_lesson30_relay_module` (Raspberry Pi Pico)
* :ref:`pi_lesson30_relay_module` (Raspberry Pi)

* :ref:`uno_lesson38_gas_leak_alarm` (Arduino UNO)
* :ref:`uno_lesson40_motion_triggered_relay` (Arduino UNO)
* :ref:`esp32_gas_leak_alarm` (ESP32)
* :ref:`esp32_motion_triggered_relay` (ESP32)
* :ref:`esp32_bluetooth_led` (ESP32)
* :ref:`esp32_iot_mqtt` (ESP32)
* :ref:`esp32_adafruit_io` (ESP32)
* :ref:`esp32_iot_bluetooth_app` (ESP32)