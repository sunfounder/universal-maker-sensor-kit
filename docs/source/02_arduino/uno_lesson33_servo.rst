.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_lesson33_servo:

レッスン33: サーボモーター (SG90)
==================================

このレッスンでは、Arduinoを使用してサーボモーターを制御し、0度から180度まで回転させ、再び戻す方法を学びます。Servoライブラリの使用法、サーボ制御のための変数の定義と使用、さらには段階的な動きを実現するためのforループの実装について説明します。このプロジェクトは初心者に最適で、モーター制御とArduinoの基本的なプログラミング原則を実践的に学ぶことができます。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全キットを購入するのが便利です。こちらのリンクをご覧ください。

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

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

配線
---------------------------

.. image:: img/Lesson_33_servo_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/12bb5427-6260-4b46-88a7-4b98f9db3ace/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. ここでは、サーボモーターを簡単に制御できるようにするために「Servo」ライブラリをインクルードしています。サーボに接続されているピンと、サーボの初期角度も定義されています。

   .. code-block:: arduino

      #include <Servo.h>
      const int servoPin = 9;  // Define the servo pin
      int angle = 0;           // Initialize the angle variable to 0 degrees
      Servo servo;             // Create a servo object

2. ``setup()``関数はArduinoが起動すると一度だけ実行されます。サーボは ``attach()`` 関数を使用して定義されたピンに接続されます。

   .. code-block:: arduino

      void setup() {
        servo.attach(servoPin);
      }

3. メインループには2つの ``for`` ループがあります。最初のループは角度を0度から180度に増加させ、2つ目のループは角度を180度から0度に減少させます。 ``servo.write(angle)`` コマンドはサーボを指定された角度に設定します。 ``delay(15)`` は次の角度に移動する前にサーボが15ミリ秒待機することを意味し、スキャンの速度を制御します。

   .. code-block:: arduino

      void loop() {
        // scan from 0 to 180 degrees
        for (angle = 0; angle < 180; angle++) {
          servo.write(angle);
          delay(15);
        }
        // now scan back from 180 to 0 degrees
        for (angle = 180; angle > 0; angle--) {
          servo.write(angle);
          delay(15);
        }
      }