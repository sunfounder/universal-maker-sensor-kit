.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson34_motor:

レッスン34: TTモーター
==================================

このレッスンでは、ESP32開発ボードとL9110モーター制御ボードを使用してモーターを制御する方法を学びます。モーターピンの定義と初期化、それらを出力として設定する方法、およびanalogWrite関数を使用してモーターの速度を調整する方法をカバーします。このプロジェクトは、ESP32プラットフォーム上でのモーター制御とパルス幅変調（PWM）を理解しようとする人々に最適で、マイクロコントローラー環境での出力操作の実践的なデモンストレーションを提供します。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのが便利です。こちらがリンクです：

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

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_34_Motor_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c1d4e7f5-140c-4ed4-a149-1af81df5dc0b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. コードの最初の部分では、モーター制御ピンを定義します。これらはL9110モーター制御ボードに接続されています。

   .. code-block:: arduino
   
      // Define the motor pins
      const int motorB_1A = 26;
      const int motorB_2A = 25;

2. ``setup()``関数では、 ``pinMode()``関数を使用してモーター制御ピンを出力として初期化します。次に、 ``analogWrite()``を使用してモーターの速度を設定します。 ``analogWrite()``に渡される値は0（オフ）から255（全速）までの範囲です。 ``delay()``関数を使用してコードを5000ミリ秒（5秒）間一時停止し、その後モーター速度を0（オフ）に設定します。

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
