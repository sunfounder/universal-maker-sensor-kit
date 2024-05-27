.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _cpn_water_level:

Water Level Sensor Module
=====================================

.. image:: img/25_water_leve_module.png
    :width: 450
    :align: center

.. raw:: html

   <br/>

The water level sensor is an affordable, user-friendly device that is compact and lightweight. It uses exposed parallel wire traces to measure the size of water droplets or volume, thus determining the water level. This sensor effortlessly converts water levels into analog signals, which can be readily utilized by program functions for triggering water level alarms. Its low power consumption and high sensitivity are also notable features.

Specification
---------------------------
* Supply Voltage: 3.3V or 5V
* PCB size: 22 x 60mm
* Working temperature range: 10℃ - 30℃
* Working humidity range: 10% - 90%

Pinout
---------------------------
* **V**: This is the positive power supply input from the main control. 
* **G**: Ground connection.
* **A**: Analog output. The higher the water level, the greater the output voltage.

Schematic diagram
---------------------------

.. image:: img/25_water_leve_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

Example
---------------------------
* :ref:`uno_lesson25_water_level` (Arduino UNO)
* :ref:`esp32_lesson25_water_level` (ESP32)
* :ref:`pico_lesson25_water_level` (Raspberry Pi Pico)
* :ref:`pi_lesson25_water_level` (Raspberry Pi)
