.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _esp32_iot_owm:

レッスン46: @OpenWeatherMapによるリアルタイム天気
====================================================

IoT Open Weather Displayプロジェクトは、ESP32ボードとI2C LCD1602モジュールを利用して、OpenWeatherMap APIからデータを取得する天気情報表示装置を作成します。

このプロジェクトは、APIの操作、Wi-Fi接続、およびESP32ボードを使用したLCDモジュールでのデータ表示の優れた入門編です。IoT Open Weather Displayを使用すると、自宅やオフィス環境でリアルタイムの天気情報を簡単にアクセスできるようになります。

**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのが便利です。リンクはこちらです：

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**OpenWeather APIキーを取得する**

|link_openweather|は、OpenWeather Ltdが所有するオンラインサービスで、APIを通じてグローバルな天気データを提供します。これには、現在の天気データ、予報、ナウキャスト、および任意の地理的場所の過去の天気データが含まれます。

#. |link_openweather|にアクセスしてログイン/アカウント作成を行います。

    .. image:: img/OWM-1.png

#. ナビゲーションバーからAPIページに移動します。

    .. image:: img/OWM-2.png

#. **Current Weather Data**を見つけて、Subscribeをクリックします。

    .. image:: img/OWM-3.png

#. **Current weather and forecasts collection**の下で、適切なサービスにサブスクライブします。このプロジェクトでは、Freeプランで十分です。

    .. image:: img/OWM-4.png

#. **API keys**ページからキーをコピーします。

    .. image:: img/OWM-5.png

**デバイスの完成**

#. 回路を構築します。

    .. image:: img/Lesson_26_LCD1602_esp32_bb.png
        :width: 800
#. コードを開く

    * ``universal-maker-sensor-kit\esp32\Lesson_46_OpenWeatherMap``ディレクトリにある ``Lesson_46_OpenWeatherMap.ino``ファイルを開くか、Arduino IDEにコードをコピーします。
    * ボード（ESP32 Dev Module）と適切なポートを選択した後、 **Upload** ボタンをクリックします。
    * :ref:`unknown_com_port`
    * ここでは ``LiquidCrystal I2C`` と ``Arduino_JSON`` ライブラリが使用されますので、 **Library Manager** からインストールしてください。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/5e262afa-97ca-45ba-807b-adf7650b30e8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
         

#. 以下の行を見つけて、 ``<SSID>`` と ``<PASSWORD>`` で修正します。

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. 前にコピーしたAPIキーを ``openWeatherMapApiKey`` に入力します。

    .. code-block::  Arduino

        // Your Domain name with URL path or IP address with path
        String openWeatherMapApiKey = "<openWeatherMapApiKey>";

#. 国コードと都市名を置き換えます。

    .. code-block::  Arduino

        // Replace with your country code and city
        // Fine the country code by https://openweathermap.org/find
        String city = "<CITY>";
        String countryCode = "<COUNTRY CODE>";

#. コードが実行されると、I2C LCD1602に現在地の時間と天気情報が表示されます。

.. note::
   コードが実行されているときに画面が空白の場合は、モジュールの裏側にあるポテンショメータを回してコントラストを調整してください。

