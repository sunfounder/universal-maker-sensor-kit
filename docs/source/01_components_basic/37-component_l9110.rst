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

L9110モータードライバーモジュール
==================================

L9110モータードライバーモジュールは、二つのモーターを同時に駆動するのに適しています。独立したL9110Sドライバーチップを二つ搭載しており、各チャンネルは最大800mAの安定した電流出力を誇ります。

電圧範囲は2.5Vから12Vにわたり、3.3Vおよび5Vのマイクロコントローラと容易にペアリングできます。

L9110モータードライバーモジュールは、さまざまなアプリケーションにおいてモーター制御を簡素化するソリューションです。デュアルチャンネルアーキテクチャのおかげで、二つのモーターを独立して制御することが可能で、デュアルモーター操作が重要なプロジェクトに最適です。

強力な連続電流出力により、このモジュールは小型から中型までのモーターを自信を持って駆動し、多様なロボティクス、自動化、モーター中心のプロジェクトに道を開きます。広い電圧範囲はさまざまな電源構成に対応し、適応性を高めます。

使いやすさを念頭に置いて設計されており、マイクロコントローラや類似の制御デバイスへの接続が簡単な直感的な入力および出力端子を提供します。さらに、過電流および過熱保護機能が組み込まれており、モーター操作の信頼性と安全性を強化します。

.. image:: img/37_l9110_module.jpg
    :width: 80%
    :align: center
    
* **B-1A & B-1B(B-2A)**: モーターBの回転方向を制御するための入力ピン。
* **A-1A & A-1B**: モーターAの回転方向を制御するための入力ピン。
* **0A & OB(A)**: モーターAの出力ピン。
* **0A & OB(B)**: モーターBの出力ピン。
* **VCC**: 電源入力ピン（2.5V-12V）。
* **GND**: グランドピン。

**特徴**

* オンボード2つのL9110Sモーター制御チップ
* デュアルチャンネルモーター制御
* 独立したモーター回転方向制御
* 高電流出力（各チャンネル800mA）
* 広い電圧範囲（2.5V-12V）
* コンパクトなデザイン
* 便利な入力および出力端子
* 内蔵保護機能
* 多用途のアプリケーション
* PCBサイズ: 29.2mm x 23mm
* 動作温度: -20°C ~ 80°C
* 電源オンLEDインジケータ

.. _cpn_l9110_principle:

**動作原理**

以下はモーターBの真理値表です：

この真理値表は、入力ピンB-1AおよびB-1B(B-2A)の値に基づくモーターBのさまざまな状態を示しています。回転方向（時計回りまたは反時計回り）、ブレーキ、または停止を示しています。

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

以下はモーターAの真理値表です：

この真理値表は、入力ピンA-1AおよびA-1Bの値に基づくモーターAのさまざまな状態を示しています。回転方向（時計回りまたは反時計回り）、ブレーキ、または停止を示しています。

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

例
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
