.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_lesson34_motor:

レッスン34: TT Motor
==================================

このレッスンでは、Arduino Uno R3またはR4とL9110モーター制御ボードを使用してモーターを制御する方法を学びます。モーターピンを定義し、プログラミングを通じてその速度を設定する方法を説明します。このチュートリアルでは、モーターの接続と制御のプロセスを段階的に説明し、Arduinoプロジェクトにおけるモーターの基本的な操作と制御の原理を示します。初心者向けに設計されており、Arduinoプラットフォームでの出力操作を理解するための実践的なアプローチを提供します。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

一式を購入するのが便利です。リンクはこちら：

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
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-


配線
---------------------------

.. image:: img/Lesson_34_tt_motor_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/89894de5-2114-4056-a064-0c495c6de447/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. コードの最初の部分では、モーター制御ピンが定義されています。これらはL9110モーター制御ボードに接続されています。

   .. code-block:: arduino
   
      // Define the motor pins
      const int motorB_1A = 9;
      const int motorB_2A = 10;

2. ``setup()``関数は、 ``pinMode()`` 関数を使用してモーター制御ピンを出力として初期化します。その後、 ``analogWrite()`` を使用してモーターの速度を設定します。 ``analogWrite()`` に渡される値は0（オフ）から255（全速）までの範囲です。その後、 ``delay()`` 関数を使用してコードを5000ミリ秒（5秒）一時停止し、その後モーター速度を0（オフ）に設定します。

   .. code-block:: arduino
   
      void setup() {
        pinMode(motorB_1A, OUTPUT);  // set motor pin 1 as output
        pinMode(motorB_2A, OUTPUT);  // set motor pin 2 as output
   
        analogWrite(motorB_1A, 255);  // set motor speed (0-255)
        analogWrite(motorB_2A, 0);
   
        delay(5000);
   
        analogWrite(motorB_1A, 0);  
        analogWrite(motorB_2A, 0);
      }
