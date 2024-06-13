.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _config_esp8266:

1.1 ESP8266の設定
===============================

キットに付属するESP8266モジュールには、既にATファームウェアが書き込まれていますが、以下の手順に従ってその設定を変更する必要があります。

1. 回路を組み立てます。

   .. image:: img/wiring_r4_configure.png
       :width: 800

2. ``ultimate-sensor-kit\iot_project\wifi\00-Set_software_serial``のパスにある ``00-Set_software_serial.ino`` ファイルを開くか、このコードをArduino IDEにコピーしてアップロードします。

   このコードはArduinoのSoftwareSerialライブラリを使用してソフトウェアシリアル通信を確立し、Arduinoがデジタルピン2と3（RxおよびTx）を介してESP8266モジュールと通信できるようにします。115200のボーレートでデータ転送をチェックし、一方の受信メッセージを他方に転送します。 **このコードを使用すると、Arduinoのシリアルモニターを使用してESP8266モジュールにATファームウェアコマンドを送信し、その応答を受け取ることができます。**

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


3. 右上の虫眼鏡アイコン（シリアルモニター）をクリックし、ボーレートを**115200**に設定します。（私のように印刷情報が表示されるかもしれませんし、されないかもしれませんが、次のステップに進んでください。）

   .. image:: img/esp01_configurie_1.png

   .. warning::
        
        * ``ready``が表示されない場合、ESP8266モジュールをリセットして（RSTをGNDに接続）シリアルモニターを再度開いてみてください。

        * また、結果が ``OK`` の場合、ファームウェアの再書き込みが必要な場合があります。詳細は :ref:`burn_firmware` を参照してください。それでも解決しない場合は、シリアルモニターのスクリーンショットをservice@sunfounder.comに送信してください。早急に問題を解決いたします。

4. **NEWLINE DROPDOWN BOX**をクリックし、ドロップダウンオプションから ``both NL & CR`` を選択し、 ``AT`` を入力します。OKと返ってきた場合、ESP8266がR4ボードと正常に接続されたことを意味します。

   .. image:: img/esp01_configurie_2.png

   .. image:: img/esp01_configurie_3.png

5. ``AT+CWMODE=3``を入力し、管理モードを **Station and AP** の共存モードに変更します。

   .. image:: img/esp01_configurie_4.png

.. 6. 後でソフトウェアシリアルを使用するために、``AT+UART=9600,8,1,0,0``を入力して、ESP8266のボーレートを9600に変更します。

..    .. image:: img/esp01_configurie_5.png


**参考**

* |link_esp8266_at|
