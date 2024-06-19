.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson31_pump:

レッスン31: 遠心ポンプ
==================================

このレッスンでは、Raspberry Piを使用してポンプを制御する方法を学びます。Pythonスクリプトを作成してポンプを作動させ、その速度を制御し、設定した期間後に停止させる方法を学びます。このプロジェクトは、GPIOインターフェースとPythonプログラミングを通じてポンプ制御の基本的な理解を提供し、Raspberry Piとシンプルなポンプアプリケーションに興味のある初心者に適した出発点となります。

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
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-


配線
---------------------------

.. image:: img/Lesson_31_Pump_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import Motor
   from time import sleep
   
   # Define pump pins
   pump = Motor(forward=17, backward=27)  # Using Raspberry Pi GPIO pin numbers
   
   # Activate the pump
   pump.forward(speed=1)  # Set pump speed, range is 0 to 1
   sleep(5)               # Run the pump for 5 seconds
   
   # Deactivate the pump
   pump.stop()            # Stop the pump


コード解析
---------------------------

#. ライブラリのインポート
   
   ``gpiozero``ライブラリはモーター制御に使用され、 ``time`` ライブラリの ``sleep`` 関数は遅延に使用されます。

   .. code-block:: python

      from gpiozero import Motor
      from time import sleep

#. ポンプピンの定義
   
   2つのGPIOピンを使用して ``Motor`` オブジェクトを作成します。一つは前進操作用、もう一つは後退操作用です。この例ではGPIO 17と27が使用されています。

   .. code-block:: python

      pump = Motor(forward=17, backward=27)

#. ポンプの作動
   
   ``pump.forward(speed=1)``を使用して、指定された速度で前進方向にモーターを作動させます。速度パラメータは0（停止）から1（全速）までの範囲です。モーターは ``sleep(5)`` で定義された5秒間作動します。

   .. code-block:: python

      pump.forward(speed=1)
      sleep(5)

#. ポンプの停止
   
   ``pump.stop()`` を使用してモーターを停止させます。これは、必要な期間の後にモーターの動作を安全に停止するために不可欠です。

   .. code-block:: python

      pump.stop()