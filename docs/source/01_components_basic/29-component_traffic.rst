.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _cpn_traffic:

信号機モジュール
==========================

.. image:: img/29_traffic_light.png
    :width: 400
    :align: center

.. raw:: html
    
    <br/>

信号機モジュールは、赤、黄、緑のライトを表示できる小型のデバイスで、実際の信号機のように動作します。交通信号システムモデルを作成したり、ArduinoでLEDを制御する方法を学んだりするのに使用できます。小型、簡単な配線、ターゲット、カスタムインストールが特徴です。PWMピンに接続してLEDの明るさを制御できます。


原理
---------------------------
信号機モジュールは、主に2つの方法で制御できます。簡単な方法は、Arduinoからのデジタル入力を使用し、HIGHまたはLOW信号で対応するLEDを直接オンまたはオフにする方法です。もう一つの方法は、PWM（パルス幅変調）を使用する方法で、特にLEDの明るさを調整する場合に適しています。PWMは、デジタル信号のデューティサイクルを変化させることでLEDの明るさを調整する技術です。デューティサイクルは、特定の期間内で信号がオンのままの時間の割合を示します。例えば、50%のデューティサイクルは、信号が半分の時間オンで、残りの時間オフであることを意味します。デューティサイクルを調整することで、LEDの明るさを調節できます。


回路図
---------------------------

.. image:: img/29_traffic_light_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

例
---------------------------
* :ref:`uno_lesson29_traffic_light_module` (Arduino UNO)
* :ref:`esp32_lesson29_traffic_light_module` (ESP32)
* :ref:`pico_lesson30_relay_module` (Raspberry Pi Pico)
* :ref:`pi_lesson30_relay_module` (Raspberry Pi)

* :ref:`uno_lesson30_relay_module` (Arduino UNO)

* :ref:`uno_touch_toggle_light` (Arduino UNO)
* :ref:`uno_bluetooth_traffic_light` (Arduino UNO)
* :ref:`esp32_touch_toggle_light` (ESP32)