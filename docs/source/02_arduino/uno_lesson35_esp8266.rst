.. _uno_lesson35_esp8266:

.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _esp8266_start:

Lesson 35: ESP8266モジュールの始め方
===================================================

このキットに付属しているESP8266モジュールには既にATファームウェアがプリインストールされていますが、以下の手順に従って設定を変更する必要があります。

1. 回路を組み立てます。

   .. note::
      ESP8266が安定した電圧を得られるように、キットに付属の9Vバッテリーを使って外部電源に接続し、Unoボードに接続してください。

   .. image:: img/Lesson_35_esp01_wiring_r3.png
       :width: 800

2. ``universal-maker-sensor-kit\arduino_uno\Lesson_35_ESP8266``のパスにある ``.ino`` ファイルを開くか、このコードをArduino IDEにコピーしてアップロードします。

   このコードはArduinoのSoftwareSerialライブラリを使用してソフトウェアシリアル通信を確立し、Arduinoがデジタルピン2と3（RxとTx）を介してESP8266モジュールと通信できるようにします。データ転送をチェックし、受信したメッセージを互いに転送し、115200のボーレートで通信します。 **このコードを使うことで、Arduinoのシリアルモニターを使用してESP8266モジュールにATファームウェアコマンドを送信し、その応答を受信することができます **。

   .. code-block:: Arduino

       #include <SoftwareSerial.h>
       SoftwareSerial espSerial(2, 3); //Rx,Tx

       void setup() {
           // put your setup code here, to run once:
           Serial.begin(115200);
           espSerial.begin(115200);
       }

       void loop() {
           if (espSerial.available()) {
               Serial.write(espSerial.read());
           }
           if (Serial.available()) {
               espSerial.write(Serial.read());
           }
       }

3. 右上の虫眼鏡アイコン（シリアルモニター）をクリックし、ボーレートを **115200** に設定します。（私のようにいくつかの情報が表示されるかもしれませんし、されないかもしれませんが、次のステップに進んでください。）

   .. image:: img/Lesson_35_esp01_configurie_1.png

   .. warning::
        
        * ``ready``と表示されない場合は、ESP8266モジュールをリセット（RSTをGNDに接続）して、シリアルモニターを再度開いてみてください。

        * さらに、結果が ``OK`` であれば、ファームウェアを再度書き込む必要があるかもしれません。詳細については :ref:`burn_firmware` を参照してください。それでも解決しない場合は、シリアルモニターのスクリーンショットを service@sunfounder.com に送信してください。できるだけ早く問題を解決いたします。

4. **NEWLINE DROPDOWN BOX**をクリックし、ドロップダウンオプションから ``both NL & CR`` を選択し、 ``AT`` を入力します。OKと返された場合、ESP8266はR4ボードと正常に接続されています。

   .. image:: img/Lesson_35_esp01_configurie_2.png

   .. image:: img/Lesson_35_esp01_configurie_3.png

5. ``AT+CWMODE=3``を入力すると、モードが **StationとAP** の共存に変更されます。

   .. image:: img/Lesson_35_esp01_configurie_4.png

.. 6. 後でソフトウェアシリアルを使用するために、``AT+UART=9600,8,1,0,0``を入力してESP8266のボーレートを9600に変更する必要があります。

..    .. image:: img/esp01_configurie_5.png


**参考**

* |link_esp8266_at|
