.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _esp32_adafruit_io:

レッスン48: Adafruit IOを使った温度と湿度の監視
===========================================================================

このプロジェクトでは、人気のあるIoTプラットフォームの使い方を紹介します。オンラインでプログラミング愛好家向けの無料（または低コスト）のプラットフォームは多数あります。例として、Adafruit IO、Blynk、Arduino Cloud、ThingSpeakなどがあります。これらのプラットフォームの使用方法は非常に似ています。ここでは、Adafruit IOに焦点を当てます。

Arduinoプログラムを作成し、DHT11センサーを使用して温度と湿度の読み取り値をAdafruit IOのダッシュボードに送信します。また、ダッシュボードのスイッチを通じて回路上のLEDを制御することもできます。

**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

全セットを購入するのが便利です。こちらのリンクをご利用ください:

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
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_dht11`
        - |link_dht11_humiture_buy|

**ダッシュボードの設定**

#. |link_adafruit_io| にアクセスし、 **Start for free** をクリックして無料アカウントを作成します。

   .. image:: img/sp230516_102503.png

#. フォームに記入してアカウントを作成します。

   .. image:: img/sp230516_102629.png

#. Adafruitアカウントを作成した後、Adafruit ioを再度開く必要があります。 **Dashboards** をクリックし、次に **New Dashboard** をクリックします。

   .. image:: img/sp230516_103347.png

#. **New Dashboard** を作成します。

   .. image:: img/sp230516_103744.png

#. 新しく作成した **Dashboard** に入り、新しいブロックを作成します。

   .. image:: img/sp230516_104234.png

#. **Toggle** ブロックを1つ作成します。

   .. image:: img/sp230516_105727.png

#. 次に、新しいフィードをここで作成する必要があります。このトグルはLEDを制御するために使用され、フィードの名前を「LED」とします。

   .. image:: img/sp230516_105641.png

#. **LED** フィードをチェックし、次のステップに進みます。

   .. image:: img/sp230516_105925.png

#. ブロック設定（主にブロックタイトル、オンテキスト、およびオフテキスト）を完了し、右下の **Create block** ボタンをクリックして完了します。

   .. image:: img/sp230516_110124.png

#. 次に、温度と湿度を表示するために2つの **Text Blocks** を作成する必要があります。したがって、 **temperature** および **humidity** という名前の2つのフィードを作成します。

   .. image:: img/sp230516_110657.png

#. ダッシュボードを作成すると、次のようになります：

   .. image:: img/sp230516_111134.png

#. ダッシュボードの **Edit Layout** オプションを使用してレイアウトを調整できます。

   .. image:: img/sp230516_111240.png

#. **API KEY** をクリックすると、ユーザー名と **API KEY** が表示されます。これをメモしておきます。コードで使用する必要があります。

   .. image:: img/sp230516_111641.png

**コードの実行**

.. |dht11_module| image:: img/Lesson_19_dht11_module.png 
   :width: 100px

.. |dht11_module_circuit| image:: img/Lesson_48_iot_adafruitio_bb.png
   :width: 500px

.. |dht11_module_withLED| image:: img/Lesson_19_dht11_module_withLED.png
   :width: 150px
   
.. |dht11_module_withLED_circuit| image:: img/Lesson_48_iot_adafruitio_new_bb.png
   :width: 500px

#. 回路を組み立てます。

   .. note:: 
      このキットには異なるバージョンのDHT11モジュールが含まれている場合があります。お持ちのモジュールに応じて配線方法を確認してください。
   
   .. csv-table:: 
      :header: "module", "diagram"
      :widths: 25, 75
   
      |dht11_module|, |dht11_module_circuit|
      |dht11_module_withLED|, |dht11_module_withLED_circuit|

#. 次に、USBケーブルを使用してESP32をコンピュータに接続します。

#. コードを開きます。

   * ``universal-maker-sensor-kit\esp32\Lesson_48_Adafruit_IO`` ディレクトリにある ``Lesson_48_Adafruit_IO.ino`` ファイルを開くか、Arduino IDEにコードをコピーします。
   * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **Upload** ボタンをクリックします。
   * :ref:`unknown_com_port`
   * ここでは ``Adafruit_MQTT Library`` と ``DHT sensor library`` が使用されているため、 **Library Manager** からインストールできます。

   .. raw:: html

       <iframe src=https://create.arduino.cc/editor/sunfounder01/987fb2fd-47e9-4a73-9020-6b2111eadd9c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 次の行を見つけて、 ``<SSID>`` と ``<PASSWORD>`` をWiFiネットワークの詳細に置き換えます。

   .. code-block::  Arduino

       /************************* WiFi Access Point *********************************/

       #define WLAN_SSID "<SSID>"
       #define WLAN_PASS "<PASSWORD>"

#. 次に、 ``<YOUR_ADAFRUIT_IO_USERNAME>`` をAdafruit IOのユーザー名に、 ``<YOUR_ADAFRUIT_IO_KEY>`` を先ほどコピーした **API KEY** に置き換えます。

   .. code-block::  Arduino

       // Adafruit IO Account Configuration
       // (to obtain these values, visit https://io.adafruit.com and click on Active Key)
       #define AIO_USERNAME "<YOUR_ADAFRUIT_IO_USERNAME>"
       #define AIO_KEY      "<YOUR_ADAFRUIT_IO_KEY>"

#. 正しいボード（ESP32 Dev Module）とポートを選択した後、 **Upload** ボタンをクリックします。

#. コードが正常にアップロードされると、シリアルモニターに次のメッセージが表示され、Adafruit IOとの通信が成功したことを示します。
    
   .. code-block::

       Adafruit IO MQTTS (SSL/TLS) Example

       Connecting to xxxxx
       WiFi connected
       IP address: 
       192.168.18.76
       Connecting to MQTT... MQTT Connected!
       Temperature: 27.10
       Humidity: 61.00

#. Adafruit IOに戻ります。ここで、ダッシュボードに温度と湿度の読み取り値を表示したり、外部LEDに接続されたLEDトグルスイッチを使用してオン/オフ状態を制御することができます。

   .. image:: img/sp230516_143220.png
