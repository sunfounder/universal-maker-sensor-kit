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

RGB LEDモジュール
==========================

.. image:: img/28_rgb_module.png
    :width: 350
    :align: center

.. raw:: html
    
    <br/>

RGBフルカラ―LEDモジュールは、赤、緑、青の光を混ぜることで様々な色を発光します。各色はPWMを使用して調整されます。カラフルな照明効果を作成したり、ArduinoでPWM（パルス幅変調）の使い方を学んだりするのに使用できます。

ピン配置
---------------------------

* **GND**: 電源の共通グランド。
* **B**: 赤色LEDの明るさを制御します。このピンを流れる電流を調整することで、赤色光の強さを変えることができます。
* **R**: 緑色LEDの明るさを制御します。赤色ピンと同様に、このピンを流れる電流を調整することで、緑色光の強さを変えることができます。
* **G**: 青色LEDの明るさを制御します。このピンを流れる電流を調整することで、青色光の強さを変えることができます。

原理
---------------------------
RGBモジュールは、調整可能なPWM電圧入力を持つR、G、Bピンを使用するフルカラ―LEDを使用して動作します。
LEDからの色は組み合わせることができます。例えば、青色光と緑色光を混ぜるとシアン色になり、赤色光と緑色光を混ぜると黄色になります。これを「加法混色法」といいます。

* `加法混色 - Wikipedia <https://en.wikipedia.org/wiki/Additive_color>`_

.. image:: img/28_rgb_module_2.png
    :width: 200
    :align: center

この方法に基づき、異なる比率で三原色を混ぜて任意の色の可視光を作り出すことができます。例えば、オレンジは赤色を多く、緑色を少なくすることで生成できます。
三原色（赤、青、緑）の強度を調整することで、フルカラ―混色効果を実現します。PWMはデジタル信号のデューティサイクルを変更し、信号がアクティブな時間の割合を調整する技術です。デューティサイクルを変更することで、LEDの明るさを調整できます。

回路図
---------------------------

.. image:: img/28_rgb_module_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>


例
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