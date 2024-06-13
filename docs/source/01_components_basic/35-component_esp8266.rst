.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _cpn_esp8266:

ESP8266モジュール
====================

.. image:: img/35_esp8266.jpg
    :align: center

ESP8266は、低コストのWi-Fiマイクロチップで、TCP/IPネットワーキングソフトウェアとマイクロコントローラ機能が内蔵されています。
上海のEspressif Systemsによって製造されています。

このチップは、2014年8月にサードパーティメーカーのAi-Thinkerが製造したESP-01モジュールとともに西洋のメイカーの注目を集めました。
この小さなモジュールは、マイクロコントローラがWi-Fiネットワークに接続し、Hayesスタイルのコマンドを使用して簡単なTCP/IP接続を行うことを可能にします。
しかし、最初はチップとその受け入れるコマンドに関する英語のドキュメントがほとんどありませんでした。
非常に低価格であり、モジュール上に外部コンポーネントがほとんどないため、大量生産されると非常に安価になることが示唆され、多くのハッカーがモジュール、チップ、およびソフトウェアを探索し、中国語のドキュメントを翻訳することに興味を持ちました。

ESP8266のピンとその機能：

.. image:: img/35_ESP8266_pinout.png


.. list-table:: ESP8266-01 Pins
   :widths: 25 25 100
   :header-rows: 1

   * - Pin	
     - Name	
     - Description
   * - 1
     - TXD
     - UART_TXD, sending; General Purpose Input/Output: GPIO1; Pull-down is not allowed when startup.
   * - 2
     - GND
     - GND
   * - 3
     - CU_PD
     - Working at high level; Power off when low level is supplied.
   * - 4
     - GPIO2
     - It should be high level when power on, hardware pull-down is not allowed; Pull-up by default;
   * - 5
     - RST
     - External Reset signal, reset when low level is supplied; work when high level is supplied (high level by default);
   * - 6
     - GPIO0
     - WiFi Status indicator; Operation mode selection: Pull-up: Flash Boot, operation mode; Pull-down: UART Download, download mode
   * - 7
     - VCC
     - Power Supply(3.3V)
   * - 8
     - RXD
     - UART_RXD，Receiving; General Purpose Input/Output: GPIO3;


* `ESP8266 - Espressif <https://www.espressif.com/en/products/socs/esp8266>`_
* |link_esp8266_at|

ESP8266アダプター
-----------------------

.. image:: img/35_esp8266_adapter.png
    :width: 300
    :align: center

ESP8266アダプターは、ESP8266モジュールをブレッドボードで使用できるようにする拡張ボードです。

ESP8266自体のピンに完全に一致し、Arduinoボードからの電圧を受け取るための5Vピンも追加されています。統合されたAMS1117チップは、電圧を3.3Vに下げてからESP8266モジュールを駆動します。

回路図は以下の通りです：

.. image:: img/35_sch_esp8266adapter.png

例
---------------------------
* :ref:`uno_lesson35_esp8266` (Arduino UNO)
* :ref:`uno_iot_weather_monito` (Arduino UNO)
* :ref:`uno_iot_vib_alert_system` (Arduino UNO)
* :ref:`uno_iot_flame` (Arduino UNO)
* :ref:`uno_iot_intrusion_alert_system` (Arduino UNO)