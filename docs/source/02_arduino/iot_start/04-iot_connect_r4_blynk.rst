.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _connect_blynk:

1.4 R4ボードをBlynkに接続する
========================================

#. ESP8266モジュールとR4ボードを再接続します。ここではソフトウェアシリアルを使用するため、TXとRXをR4ボードのピン2および3にそれぞれ接続します。

  .. note::

       ESP8266モジュールには安定した動作環境を提供するために高電流が必要ですので、9Vバッテリーが接続されていることを確認してください。

  .. image:: img/wiring_r4_quickstart.png

#. ``ultimate-sensor-kit\iot_project\wifi\00-Blynk_quick_start``のパスにある ``00-Blynk_quick_start.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

   .. raw:: html
       
       <iframe src=https://create.arduino.cc/editor/sunfounder01/421997b2-aaa7-45d7-926a-f0aec50db99a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. アカウントの **Device info** ページからコピーできる以下の3行のコードを置き換えます。これらのコードは、R4ボードがあなたのBlynkアカウントを見つけるために必要です。

   .. code-block:: arduino

       #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
       #define BLYNK_DEVICE_NAME "Device"
       #define BLYNK_AUTH_TOKEN "YourAuthToken"
   
   .. image:: img/sp20220614174721.png

#. 使用しているWiFiの ``ssid`` と ``password`` を入力します。

   .. code-block:: arduino

       char ssid[] = "ssid";
       char pass[] = "password";

#. コードをR4ボードにアップロードし、シリアルモニターを開いてボーレートを115200に設定します。R4ボードがBlynkと正常に通信すると、シリアルモニターに ``ready`` という文字が表示されます。

   .. image:: img/sp220607_170223.png

   .. note::
   
       接続時に ``ESP is not responding`` というメッセージが表示された場合、次の手順に従ってください。

       * 9Vバッテリーが接続されていることを確認してください。
       * ピンRSTをGNDに1秒間接続してESP8266モジュールをリセットし、その後接続を解除します。
       * R4ボードのリセットボタンを押します。

       時には、上記の操作を3〜5回繰り返す必要があるかもしれませんので、忍耐強く行ってください。

#. Blynkのステータスが**offline**から**online**に変わります。

    .. image:: img/sp220607_170326.png
