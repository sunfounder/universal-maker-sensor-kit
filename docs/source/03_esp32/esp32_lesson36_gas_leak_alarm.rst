.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_gas_leak_alarm:

レッスン36: ガス漏れ警報
==================================

このプロジェクトは、ESP32ボードを使用したガス漏れ検知シナリオのシミュレーションに関するものです。
MQ-2ガスセンサーとRGB LEDを組み込むことで、このデモはガス濃度を継続的に読み取ります。
もしこの濃度があらかじめ設定された閾値を超えた場合、
アラーム（ブザー）を作動させ、RGB LEDを赤色に点灯させます。
逆に、濃度がこの閾値を下回った場合、
アラームは作動せず、LEDは緑色に点灯します。
このデモはあくまで参考用であり、実際のガス漏れ検知システムの代わりにはなりません。

必要なコンポーネント
--------------------------

このプロジェクトには以下のコンポーネントが必要です。

すべてのキットを購入するのが便利です、こちらのリンクからどうぞ：

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
    *   - :ref:`cpn_gas`
        - |link_mq2_gas_sensor_module_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_module_buy|
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

配線
---------------------------

.. image:: img/Lesson_36_Gas_leak_alarm_esp32_bb.png
    :width: 100%

Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/3c24f636-7411-4d3d-8d2e-ac4400084a93/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Code Analysis
---------------------------

このプロジェクトの核心は、ガス濃度を継続的に監視することです。検出されたガス濃度が一定の閾値を超えると、アラームが鳴り、LEDの色が赤に変わります。これは潜在的に危険な状態を示す警告メカニズムのシミュレーションです。濃度が閾値を下回ると、アラームは解除され、LEDは緑色に変わり、安全な環境を示します。

1. 定数と変数の定義

    これらの行は、さまざまなコンポーネントのピン番号を宣言し、初期化します。 ``sensorPin`` は、MQ-2ガスセンサーが接続されているアナログピンを示します。 ``sensorValue`` は、センサーのアナログ出力を格納する整数変数です。 ``buzzerPin`` は、ブザーが接続されているデジタルピンを示します。最後に、 ``RPin`` と ``GPin`` は、RGB LEDの赤と緑のチャンネルのピン番号です。

    .. code-block:: arduino
   
        // Define the pin numbers for the Gas Sensor
        const int sensorPin = 35;
        int sensorValue;

        // Define the pin number for the buzzer
        const int buzzerPin = 19;

        // Define pin numbers for the RGB LED
        const int RPin = 25;  // R channel of RGB LED
        const int GPin = 26;  // G channel of RGB LED


2. ``setup()``での初期化

    ``setup()``関数は、必要な設定を初期化します。シリアル通信は9600ボーの速度で開始され、センサーの読み取り値をシリアルモニターで確認できるようにします。ブザーとRGB LEDのピンは``OUTPUT``として設定され、外部コンポーネントに信号を送信します。

    .. code-block:: arduino
   
        void setup() {
            Serial.begin(9600);  // Start serial communication at 9600 baud rate
    
            // Initialize the buzzer and RGB LED pins as output
            pinMode(buzzerPin, OUTPUT);
            pinMode(RPin, OUTPUT);
            pinMode(GPin, OUTPUT);
        }

3. メインループ：センサーの読み取りとアラームのトリガー

    ``loop()``関数はガスセンサーの出力を継続的に読み取ります。読み取り値はシリアルモニターに表示されます。センサー値に応じて、次の2つのシナリオが発生します：
    
    - 値が3000を超えると、 ``tone()`` を使用してブザーが作動し、RGB LEDが赤に点灯します。
    - 値が3000未満の場合、 ``noTone()`` を使用してブザーを停止し、LEDが緑に点灯します。
    
    最後に、次のループの反復まで50ミリ秒の遅延を導入し、読み取り頻度を管理し、CPU負荷を軽減します。

    .. code-block:: arduino
   
        void loop() {
            // Read the analog value of the gas sensor
            sensorValue = analogRead(sensorPin);

            // Print the sensor value to the serial monitor
            Serial.print("Analog output: ");
            Serial.println(sensorValue);

            // If the sensor value exceeds the threshold, trigger the alarm and make the RGB LED red
            if (sensorValue > 3000) {
                tone(buzzerPin, 500, 300);
                digitalWrite(GPin, LOW);
                digitalWrite(RPin, HIGH);
                delay(500);
                // stop the tone playing:
                noTone(buzzerPin);
            } else {
                // If the sensor value is below the threshold, turn off the alarm and make the RGB LED green
                noTone(buzzerPin);
                digitalWrite(RPin, LOW);
                digitalWrite(GPin, HIGH);
            }
            
            // Wait for 50 milliseconds before the next loop iteration
            delay(50);
        }

    

