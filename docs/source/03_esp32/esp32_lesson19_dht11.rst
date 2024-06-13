.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson19_dht11:

Lesson 19: 温湿度センサーモジュール (DHT11)
====================================================================

このレッスンでは、ESP32開発ボードを使用してDHT11センサーから温度と湿度を読み取る方法を学びます。これらの読み取り値の解釈と摂氏および華氏での熱指数の計算についても説明します。このプロジェクトは、環境センサーの初心者に最適で、ESP32プラットフォームでのセンサーデータ取得と気候モニタリングの基本概念について実践的な経験を提供します。

必要な部品
--------------------------

このプロジェクトには以下の部品が必要です。

すべての部品が揃ったキットを購入すると便利です。リンクはこちら：

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
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_dht11`
        - |link_dht11_humiture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_19_DHT11_esp32_bb.png
    :width: 100%


コード
---------------------------

.. note::
   ライブラリをインストールするには、Arduino Library Managerを使用して**"DHT sensor library"**を検索し、インストールしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/926830ca-9421-4852-ad72-ff75c1f10174/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. 必要なライブラリのインクルードと定数の定義
   このコード部分では、DHTセンサーライブラリがインクルードされ、このプロジェクトで使用するピン番号とセンサータイプが定義されます。

   .. note::
      ライブラリをインストールするには、Arduino Library Managerを使用して **"DHT sensor library"**を検索し、インストールしてください。

   .. code-block:: arduino
    
      #include <DHT.h>
      #define DHTPIN 25       // Define the pin used to connect the sensor
      #define DHTTYPE DHT11  // Define the sensor type

#. DHTオブジェクトの作成
   ここでは、定義されたピン番号とセンサータイプを使用してDHTオブジェクトを作成します。

   .. code-block:: arduino

      DHT dht(DHTPIN, DHTTYPE);  // Create a DHT object

#. この関数は、ESP32開発ボードが起動すると一度だけ実行されます。この関数でシリアル通信とDHTセンサーを初期化します。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        Serial.println(F("DHT11 test!"));
        dht.begin();  // Initialize the DHT sensor
      }

#. メインループ
   ``loop()``関数は、セットアップ関数の後に連続して実行されます。ここでは、湿度と温度の値を読み取り、熱指数を計算し、これらの値をシリアルモニタに表示します。センサーの読み取りに失敗した場合（NaNが返される）、エラーメッセージを表示します。

   .. note::
    
      |link_heat_index| は、気温と湿度を組み合わせることで、外気がどれだけ暑く感じるかを測定する方法です。「体感温度」や「見かけの温度」とも呼ばれます。

   .. code-block:: arduino

      void loop() {
        delay(2000);
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        float f = dht.readTemperature(true);
        if (isnan(h) || isnan(t) || isnan(f)) {
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
        }
        float hif = dht.computeHeatIndex(f, h);
        float hic = dht.computeHeatIndex(t, h, false);
        Serial.print(F("Humidity: "));
        Serial.print(h);
        Serial.print(F("%  Temperature: "));
        Serial.print(t);
        Serial.print(F("°C "));
        Serial.print(f);
        Serial.print(F("°F  Heat index: "));
        Serial.print(hic);
        Serial.print(F("°C "));
        Serial.print(hif);
        Serial.println(F("°F"));
      }