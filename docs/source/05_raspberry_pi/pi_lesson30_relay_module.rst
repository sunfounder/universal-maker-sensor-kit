.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pi_lesson30_relay_module:

レッスン30: リレーモジュール
==================================

このレッスンでは、Raspberry Piを使用してリレーモジュールを制御する方法を学びます。リレーを1秒間隔でオンとオフにするシンプルなPythonスクリプトを書く方法を学びます。このプロジェクトは、外部デバイスを制御するためにGPIOピンを使用する実践的な入門編であり、電子回路でのリレーの働きについての基本的な理解を提供します。これは、Raspberry Piとハードウェア制御を始める初心者にとってわかりやすく有益な演習です。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全てが揃ったキットを購入すると便利です。リンクはこちらです：

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

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_30_Relay_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import OutputDevice
   from time import sleep

   # Replace with your GPIO pin number
   relay_pin = 17  # Example using GPIO17

   # Initialize relay object
   relay = OutputDevice(relay_pin)

   try:
      while True:
         # Turn on the relay
         relay.on()
         sleep(1)  # Relay remains on for 1 second

         # Turn off the relay
         relay.off()
         sleep(1)  # Relay remains off for 1 second

   except KeyboardInterrupt:
      # Capture Ctrl+C and safely close the program
      relay.off()
      print("Program interrupted by user")


コード解析
---------------------------

#. ライブラリのインポート
   
   GPIO制御のために ``gpiozero`` ライブラリを、遅延のために ``time`` ライブラリをインポートします。

   .. code-block:: python

      from gpiozero import OutputDevice
      from time import sleep

#. リレーの初期化
   
   リレーに接続されたGPIOピンを定義し、そのピンで ``OutputDevice`` オブジェクトを初期化します。

   .. code-block:: python

      relay_pin = 17  # Example using GPIO17
      relay = OutputDevice(relay_pin)

#. ループ内のリレー制御
   
   ``while True:``ループはリレーを継続的にトグルします。 ``relay.on()`` と ``relay.off()`` を使用してリレーを制御し、 ``sleep(1)`` は各状態の間に1秒の遅延を作成します。

   .. code-block:: python

      try:
          while True:
              relay.on()
              sleep(1)  # Relay remains on for 1 second
              relay.off()
              sleep(1)  # Relay remains off for 1 second

#. 例外処理
   
   ``except``ブロックは ``KeyboardInterrupt`` （Ctrl+C）をキャッチします。これにより、リレーがオフになり、プログラムが安全に終了することが保証されます。

   .. code-block:: python

      except KeyboardInterrupt:
          relay.off()
          print("Program interrupted by user")