.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _cpn_buzzer:

パッシブブザーモジュール
==========================

.. image:: img/32_passive_buzzer_module.png
    :width: 350
    :align: center

.. raw:: html
    
    <br/>

パッシブブザーは、電気信号が加えられると音を生成するデバイスです。内部に音を生成するためのオシレータを持たないため、パッシブと呼ばれています。代わりに、Arduinoのようなマイクロコントローラーからの外部信号に依存して音を生成します。パッシブブザーモジュールは、パッシブブザーとArduinoとの連携を容易にする追加の回路を含む小型の電子部品です。

ピン配置
---------------------------
* **VCC**: メインコントロールからの正電源入力。
* **GND**: 接地接続。
* **I/O**: このピンを通じて制御信号を送信し、ブザーの音色と周波数を制御できます。

回路図
---------------------------

.. image:: img/32_passive_buzzer_module_schematic.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>

例
---------------------------
* :ref:`uno_lesson32_passive_buzzer` (Arduino UNO)
* :ref:`esp32_lesson32_passive_buzzer` (ESP32)
* :ref:`pico_lesson32_passive_buzzer` (Raspberry Pi Pico)
* :ref:`pi_lesson32_passive_buzzer` (Raspberry Pi)

* :ref:`uno_lesson38_gas_leak_alarm` (Arduino UNO)
* :ref:`esp32_gas_leak_alarm` (ESP32)