.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson13_potentiometer:

Lesson 13: Potentiometer Module
==================================

このレッスンでは、Raspberry Pi Pico Wを使用してポテンショメータでアナログ値を測定する方法を学びます。ポテンショメータは可変抵抗器であり、Raspberry Pi Pico Wのアナログ入力ピンの1つで読み取る電圧を調整できます。ポテンショメータのつまみを回すことで、入力値の変化を観察します。このプロジェクトは、アナログ入力とその電子プロジェクトへの応用に関する基本的な理解を提供し、電子工学とMicroPythonプログラミングの初心者にとって理想的な入門点となります。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

キット全体を購入するのが便利です。リンクはこちら：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_13_potentiometer_module_bb.png
    :width: 100%
コード
---------------------------

.. code-block:: python

   import machine  # Hardware control library
   import time  # Time control library
   
   potentiometer = machine.ADC(26)  # Initialize ADC on pin 26
   
   while True:
       value = potentiometer.read_u16()  # Read analog value
       print(value)  # Print the value
   
       time.sleep_ms(200)  # Delay of 200 ms between reads


コード解析
---------------------------

#. ライブラリのインポート

   最初に、必要なライブラリをインポートします。 ``machine`` はハードウェア制御用で、 ``time`` は遅延管理用です。

   .. code-block:: python

      import machine  # Hardware control library
      import time     # Time control library

#. ADC（アナログ-デジタルコンバータ）の初期化

   ポテンショメータはPico Wのピン26に接続されています。このピンは、アナログ値を読み取るためにADCピンとして初期化されます。

   .. code-block:: python

      potentiometer = machine.ADC(26)  # Initialize ADC on pin 26

#. アナログ値の読み取りと表示

   コードは無限ループ（ ``while True:`` ）に入り、 ``potentiometer.read_u16()`` を使用してポテンショメータから継続的にアナログ値を読み取り、それを表示します。

   .. code-block:: python

      while True:
          value = potentiometer.read_u16()  # Read analog value
          print(value)                      # Print the value

#. 遅延の追加

   ループが速く動きすぎるのを防ぐために、 ``time.sleep_ms(200)`` を使用して200ミリ秒の遅延を追加します。これにより、読みやすい出力が得られ、プロセッサの負荷が軽減されます。

   .. code-block:: python

      time.sleep_ms(200)                # Delay of 200 ms between reads