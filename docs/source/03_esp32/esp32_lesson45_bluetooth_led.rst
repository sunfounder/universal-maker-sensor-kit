.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_bluetooth_led:


レッスン45: Bluetoothで制御するRGB LED
===============================================

このプロジェクトは前のプロジェクト(:ref:`esp32_bluetooth`)の拡張版で、RGB LEDの設定と、「led_off」、「red」、「green」などのカスタムコマンドを追加します。これらのコマンドを使用して、LightBlueを使ったモバイルデバイスからRGB LEDを制御することができます。

**必要な部品**

このプロジェクトで必要な部品は以下の通りです。

便利なキットを購入するには、こちらのリンクをご利用ください:

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

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_rgb`
        - \-

**操作手順**

#. 回路を組み立てます。

    .. image:: img/Lesson_28_RGB_LED_Module_esp32_bb.png

#. ``universal-maker-sensor-kit\esp32\Lesson_45_Bluetooth_RGB`` ディレクトリにある``Lesson_45_Bluetooth_RGB.ino``ファイルを開くか、Arduino IDEにコードをコピーします。

    .. raw:: html
         
        <iframe src=https://create.arduino.cc/editor/sunfounder01/714bacdf-4ee6-4f6e-8ac3-04e328154d7a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. UUIDの競合を避けるために、Bluetooth SIGによって提供される|link_uuid|を使用してランダムに3つの新しいUUIDを生成し、次のコード行に記入します。

    .. note::
        :ref:`esp32_bluetooth` プロジェクトですでに3つの新しいUUIDを生成した場合は、それを引き続き使用できます。


    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png

#. 正しいボードとポートを選択し、 **アップロード** ボタンをクリックします。

#. コードが正常にアップロードされたら、モバイルデバイスで **Bluetooth** をオンにし、 **LightBlue** アプリを開きます。

    .. image:: img/bluetooth_open.png

#. **スキャン**ページで **ESP32-Bluetooth** を見つけて **接続** をクリックします。表示されない場合は、ページを数回更新してみてください。「 **デバイスに接続されました！**」と表示されたら、Bluetooth接続は成功です。コードで設定された3つのUUIDを確認するには、下にスクロールします。

    .. image:: img/bluetooth_connect.png
        :width: 800

#. 送信UUIDをタップし、データ形式を「UTF-8 String」に設定します。これで、「led_off」、「red」、「green」、「blue」、「yellow」、「purple」などのコマンドを書き込んで、RGB LEDがこれらの指示に応答するか確認できます。

    .. image:: img/bluetooth_send_rgb.png
    
**仕組み**

このコードは、前のプロジェクト(:ref:`esp32_bluetooth`)の拡張版で、RGB LEDの設定と「led_off」、「red」、「green」などのカスタムコマンドを追加します。これらのコマンドを使用して、LightBlueを使ったモバイルデバイスからRGB LEDを制御することができます。

コードをステップごとに解説します。

* RGB LEDのピン、PWMチャネル、周波数、および解像度の新しいグローバル変数を追加します。

    .. code-block:: arduino

        ...

        // Define RGB LED pins
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        // Define PWM channels
        const int redChannel = 0;
        const int greenChannel = 1;
        const int blueChannel = 2;

        ...

* ``setup()`` 関数内で、PWMチャネルを事前定義された周波数と解像度で初期化します。次に、RGB LEDピンをそれぞれのPWMチャネルに接続します。

    .. code-block:: arduino
        
        void setup() {
            ...

            // Set up PWM channels
            ledcSetup(redChannel, freq, resolution);
            ledcSetup(greenChannel, freq, resolution);
            ledcSetup(blueChannel, freq, resolution);
            
            // Attach pins to corresponding PWM channels
            ledcAttachPin(redPin, redChannel);
            ledcAttachPin(greenPin, greenChannel);
            ledcAttachPin(bluePin, blueChannel);

        }

* ``MyCharacteristicCallbacks``クラスの ``onWrite`` メソッドを修正します。この関数は、Bluetooth接続からのデータをリッスンします。受信した文字列（例： ``"led_off"`` 、 ``"red"`` 、 ``"green"`` など）に基づいて、RGB LEDを制御します。

    .. code-block:: arduino

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                std::string value = pCharacteristic->getValue();
                if (value == "led_off") {
                    setColor(0, 0, 0); // turn the RGB LED off
                    Serial.println("RGB LED turned off");
                } else if (value == "red") {
                    setColor(255, 0, 0); // Red
                    Serial.println("red");
                }
                else if (value == "green") {
                    setColor(0, 255, 0); // green
                    Serial.println("green");
                }
                else if (value == "blue") {
                    setColor(0, 0, 255); // blue
                    Serial.println("blue");
                }
                else if (value == "yellow") {
                    setColor(255, 150, 0); // yellow
                    Serial.println("yellow");
                }
                else if (value == "purple") {
                    setColor(80, 0, 80); // purple
                    Serial.println("purple");
                }
            }
        };

* 最後に、RGB LEDの色を設定する関数を追加します。

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // For common-anode RGB LEDs, use 255 minus the color value
            ledcWrite(redChannel, red);
            ledcWrite(greenChannel, green);
            ledcWrite(blueChannel, blue);
        }

要約すると、このスクリプトは、リモートコントロールのインタラクションモデルを実現します。ESP32はBluetooth Low Energy（BLE）サーバーとして動作します。

接続されたBLEクライアント（スマートフォンなど）は、文字列コマンドを送信してRGB LEDの色を変更できます。ESP32は、受信した文字列をクライアントに送信することで、どの操作が実行されたかをクライアントに知らせます。
