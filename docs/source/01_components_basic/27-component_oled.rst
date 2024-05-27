.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _cpn_oled:

OLED Display Module (SSD1306)
=================================

.. image:: img/27_OLED.png
    :width: 300
    :align: center

.. raw:: html
    
    <br/>

An OLED (Organic Light-Emitting Diode) display module is a device that can display text, graphics and images on a thin and flexible screen using organic materials that emit light when electric current is applied.

The SSD1306 I2C OLED display module operates by controlling an OLED (Organic Light-Emitting Diode) display using the powerful single-chip CMOS OLED driver controller, the SSD1306. This controller manages all RAM buffering and demands minimal effort from the connected microcontroller, such as an Arduino. OLED displays are renowned for their extremely light and potentially flexible nature, producing brighter and crisper images compared to traditional displays due to being almost paper-thin.

The main advantage of an OLED Display is that it emits its own light and doesn’t need another source of backlight. Due to this, OLED Displays often have better contrast, brightness and viewing angles when compared to LCD displays.

Another important feature of OLED Displays is deep black levels. Since each pixel emits its own light in an OLED Display, to produce black color, the individual pixel can be turned OFF.

Due to lower power consumption (only pixels which are lit up draw current), OLED displays are also popular in battery operated devices like Smart Watches, Health Trackers and other wearables.

Pinout
---------------------------
* **VIN**: This is the power pin. 
* **GND**: Common ground for power and logic.
* **SCL**: The serial clock pin for the I2C interface.
* **SDA**: The serial data pin for the I2C interface.


Example
---------------------------
* :ref:`uno_lesson27_oled` (Arduino UNO)
* :ref:`esp32_lesson27_oled` (ESP32)
* :ref:`pico_lesson27_oled` (Raspberry Pi Pico)
* :ref:`pi_lesson27_oled` (Raspberry Pi)

* :ref:`uno_lesson41_heartrate_monitor` (Arduino UNO)
* :ref:`uno_digital_dice` (Arduino UNO)
* :ref:`esp32_heartrate_monitor` (ESP32)
* :ref:`esp32_digital_dice` (ESP32)