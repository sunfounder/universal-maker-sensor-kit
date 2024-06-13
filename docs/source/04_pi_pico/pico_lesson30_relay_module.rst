.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pico_lesson30_relay_module:

レッスン30: リレーモジュール
==================================

このレッスンでは、Raspberry Pi Pico W を使用してリレーモジュールを制御する方法を学びます。リレーを Pi に接続する基本的な回路をセットアップし、リレーを1秒間隔でオンとオフに切り替えるMicroPythonスクリプトを書きます。このプロジェクトは、リレーのような外部デバイスを制御することを紹介し、Raspberry Pi Pico W のGPIOピンを使用した実際の出力操作を示します。ホームオートメーションや他の高出力デバイスの管理に興味がある人にとって、このレッスンはマイクロコントローラーが外部ハードウェアとどのように相互作用し、制御できるかについての基本的な洞察を提供します。

必要なコンポーネント
--------------------------

このプロジェクトでは、次のコンポーネントが必要です。

全キットを購入するのが便利です。リンクはこちら：

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
    *   - :ref:`cpn_relay`
        - \-
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_30_Relay_Module_pico_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Replace this number with the GPIO pin number your relay is connected to
   relay_pin = Pin(16, Pin.OUT)
   
   def relay_on():
       relay_pin.value(1)  # Set relay to ON state
   
   def relay_off():
       relay_pin.value(0)  # Set relay to OFF state
   
   try:
       while True:
           relay_on()
           print("on....")
           time.sleep(1)  # Wait for 1 second
           relay_off()
           print("off....")
           time.sleep(1)  # Wait for 1 second
   except:
       relay_off()  # Ensure the relay is turned off in case of an exception
       print("Program interrupted, relay turned off.")


コード解析
---------------------------

#. ライブラリのインポート

   GPIOピンを操作し、時間関連の機能を扱うために ``machine`` ライブラリと ``time`` ライブラリをインポートします。

   .. code-block:: python

      from machine import Pin
      import time

#. リレーピンの初期化

   リレーを制御するためにGPIOピンを出力ピンとして設定します。 ``relay_pin`` 変数はリレーに接続されたGPIOピンを表します。

   .. code-block:: python

      relay_pin = Pin(16, Pin.OUT)

#. リレー制御関数の定義

   リレーをオンにする ``relay_on`` 関数と、リレーをオフにする ``relay_off`` 関数を定義します。これらの関数はGPIOピンの値を高（1）または低（0）に変更します。

   .. code-block:: python

      def relay_on():
          relay_pin.value(1)  # Set relay to ON state

      def relay_off():
          relay_pin.value(0)  # Set relay to OFF state

#. メインループと例外処理

   ``while True`` を使用して連続ループを作成します。このループ内で、リレーは1秒ごとにオンとオフが切り替わります。中断（キーボードによる中断など）が発生した場合、安全のためにリレーがオフにされ、メッセージが表示されます。

   .. code-block:: python

      try:
          while True:
              relay_on()
              print("on....")
              time.sleep(1)  # Wait for 1 second
              relay_off()
              print("off....")
              time.sleep(1)  # Wait for 1 second
      except:
          relay_off()  # Ensure the relay is turned off in case of an exception
          print("Program interrupted, relay turned off.")