.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pi_lesson33_servo:

レッスン33: サーボモーター (SG90)
==================================

このレッスンでは、Raspberry Piを使用してサーボモーターを制御する方法を学びます。サーボのパルス幅設定を調整して精密に制御し、Pythonスクリプトを作成してサーボを最小、中間、最大の位置に移動させる方法を学びます。

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


配線
---------------------------

.. image:: img/Lesson_33_Servo_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import Servo
   from time import sleep
   
   # GPIO pin for the servo
   myGPIO = 17
   
   # Correction factor for the servo
   myCorrection = 0.45
   maxPW = (2.0 + myCorrection) / 1000  # Maximum pulse width
   minPW = (1.0 - myCorrection) / 1000  # Minimum pulse width
   
   # Initialize the servo with adjusted pulse width range
   servo = Servo(myGPIO, min_pulse_width=minPW, max_pulse_width=maxPW)
   
   # Continuously move servo between positions
   while True:
      # Move servo to middle position
      servo.mid()
      print("mid")
      sleep(0.5)

      # Move servo to minimum position
      servo.min()
      print("min")
      sleep(1)

      # Move servo to middle position
      servo.mid()
      print("mid")
      sleep(0.5)

      # Move servo to maximum position
      servo.max()
      print("max")
      sleep(1)


コード解析
---------------------------

#. ライブラリのインポート
   
   ``gpiozero``からサーボ制御用の ``Servo`` クラスと、タイミング用の ``time`` から ``sleep`` をインポートします。

   .. code-block:: python

      from gpiozero import Servo
      from time import sleep

#. GPIOピンとサーボ補正係数の設定
   
   サーボに接続されたGPIOピンを定義し、サーボのパルス幅範囲をキャリブレーションするための補正係数を設定します。

   .. code-block:: python

      myGPIO = 17
      myCorrection = 0.45
      maxPW = (2.0 + myCorrection) / 1000
      minPW = (1.0 - myCorrection) / 1000

#. サーボの初期化
   
   指定されたGPIOピンと調整されたパルス幅範囲を使用して ``Servo`` オブジェクトを作成します。

   .. code-block:: python

      servo = Servo(myGPIO, min_pulse_width=minPW, max_pulse_width=maxPW)

#. サーボを連続的に移動
   
   ``while True``ループを使用して、サーボを最小、中間、および最大の位置間で移動させ、現在の位置を表示し、移動間にポーズを入れます。

   .. code-block:: python

      while True:
          servo.mid()
          print("mid")
          sleep(0.5)

          servo.min()
          print("min")
          sleep(1)

          servo.mid()
          print("mid")
          sleep(0.5)

          servo.max()
          print("max")
          sleep(1)