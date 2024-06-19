.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson33_servo:

レッスン33: サーボモーター (SG90)
==================================

このレッスンでは、Raspberry Pi Pico Wを使用してサーボモーター（SG90）を制御する方法を学びます。サーボモーターの角度を制御するためのパルス幅変調（PWM）の概念を紹介します。このレッスンには、サーボを0度から180度までスムーズに動かし、再び戻すためのMicroPythonスクリプトの作成が含まれます。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全キットを購入すると便利です。リンクはこちら：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

以下のリンクから別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_33_Servo_pico_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   import machine
   import time
   
   # Initialize PWM on pin 16 for servo control
   servo = machine.PWM(machine.Pin(16))
   servo.freq(50)  # Set PWM frequency to 50Hz, common for servo motors
   
   
   def interval_mapping(x, in_min, in_max, out_min, out_max):
       """
       Maps a value from one range to another.
       This function is useful for converting servo angle to pulse width.
       """
       return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

   
   def servo_write(pin, angle):
    """
       Moves the servo to a specific angle.
       The angle is converted to a suitable duty cycle for the PWM signal.
    """
    pulse_width = interval_mapping(
        angle, 0, 180, 0.5, 2.5
       )  # Map angle to pulse width in ms
    duty = int(
        interval_mapping(pulse_width, 0, 20, 0, 65535)
       )  # Map pulse width to duty cycle
       pin.duty_u16(duty)  # Set PWM duty cycle


   # Main loop to continuously move the servo
while True:
       # Sweep the servo from 0 to 180 degrees
    for angle in range(180):
        servo_write(servo, angle)
           time.sleep_ms(20)  # Short delay for smooth movement

       # Sweep the servo back from 180 to 0 degrees
    for angle in range(180, -1, -1):
        servo_write(servo, angle)
           time.sleep_ms(20)  # Short delay for smooth movement


コード解析
---------------------------

#. モジュールのインポートとサーボの初期化:

   ``machine`` モジュールはサーボを制御するためのPWM機能にアクセスするために重要であり、 ``time`` は遅延を実装するために使用されます。サーボはRaspberry Pi Pico Wのピン16に初期化され、その周波数はサーボ制御に一般的な50Hzに設定されます。

   .. code-block:: python

      import machine
      import time
      servo = machine.PWM(machine.Pin(16))
      servo.freq(50)

#. マッピングとサーボ制御の関数:

   ``interval_mapping`` 関数は、希望するサーボ角度をPWMパルス幅に変換します。 ``servo_write`` 関数はこのパルス幅をデューティサイクルに変換し、サーボの位置を設定します。これらの関数は、角度位置を適切なPWM信号に変換するための中心的な役割を果たします。

   サーボのワークパルスについての情報は :ref:`Work Pulse <cpn_servo_pulse>` を参照してください。

   .. code-block:: python

      def interval_mapping(x, in_min, in_max, out_min, out_max):
          return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

      def servo_write(pin, angle):
          pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5)
          duty = int(interval_mapping(pulse_width, 0, 20, 0, 65535))
          pin.duty_u16(duty)

#. 連続的な動きのためのメインループ:

   メインループでは、サーボを0度から180度までスイープし、再び戻す制御を行います。これは角度の範囲をループし、各角度に対して ``servo_write`` を呼び出し、スムーズな動きのために短い遅延を設定することで実現します。

   .. code-block:: python

      while True:
          for angle in range(180):
              servo_write(servo, angle)
              time.sleep_ms(20)
          for angle in range(180, -1, -1):
              servo_write(servo, angle)
              time.sleep_ms(20)