.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pi_lesson34_motor:

レッスン34: TTモーター
==================================

このレッスンでは、Raspberry Piを使用してモーターの速度と方向を制御する方法を学びます。Raspberry Piをプログラムして、モーターを異なる速度で前後方向に動かす方法を学びます。このプロジェクトでは、モーターの速度を設定し、指定された時間だけ動作させた後に停止することが含まれます。この演習は、Raspberry Piを用いたモーター制御の実践的な入門編であり、ハードウェア制御とPythonプログラミングの明確で簡単な体験を提供し、初心者に適しています。

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
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-


配線
---------------------------

.. image:: img/Lesson_34_Motor_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import Motor
   from time import sleep

   # Define motor pins
   motor = Motor(forward=17, backward=27)  # Using Raspberry Pi GPIO pin numbers

   # Run the motor forward at half speed
   motor.forward(speed=0.5)  # Set motor speed, range is 0 to 1
   sleep(5)                  # Run the motor for 5 seconds

   # Increase to full speed forward
   motor.forward(speed=1)    # Set motor speed, range is 0 to 1
   sleep(5)                  # Run the motor for 5 seconds

   # Run the motor backward at full speed
   motor.backward(speed=1)   # Set motor speed, range is 0 to 1
   sleep(5)                  # Run the motor for 5 seconds

   # Stop the motor
   motor.stop()


コード解析
---------------------------

#. ライブラリのインポート
   
   モーター制御のために ``gpiozero`` から ``Motor`` クラスを、タイミング制御のために ``time`` から ``sleep`` をインポートします。

   .. code-block:: python

      from gpiozero import Motor
      from time import sleep

#. モーターピンの定義
   
   GPIOピン17と27に接続されたモーターを制御するために ``Motor`` オブジェクトを作成します。GPIOピン17は前進、27は後退用です。

   .. code-block:: python

      motor = Motor(forward=17, backward=27)

#. モーターを半速で前進させる
   
   モーターを半速（ ``speed=0.5`` ）で5秒間前進させます。速度範囲は0（停止）から1（全速）までです。

   .. code-block:: python

      motor.forward(speed=0.5)
      sleep(5)

#. 前進速度を全速に増加
   
   モーターの速度を全速（ ``speed=1`` ）に増加させ、さらに5秒間前進させます。

   .. code-block:: python

      motor.forward(speed=1)
      sleep(5)

#. モーターを全速で後退させる
   
   モーターを全速で5秒間後退させます。

   .. code-block:: python

      motor.backward(speed=1)
      sleep(5)

#. モーターを停止
   
   最後に、 ``stop`` メソッドを使用してモーターを停止させます。

   .. code-block:: python

      motor.stop()


