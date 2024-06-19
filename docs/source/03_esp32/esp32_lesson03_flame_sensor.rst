.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson03_flame:

レッスン03: 炎センサーモジュール
==================================

このレッスンでは、ESP32開発ボードに炎センサーを接続して火災を検知する方法を学びます。センサーが火に反応し、警告メッセージを発する仕組みを調べます。このプロジェクトは、センサーとESP32を使用する初心者に最適で、基本的な電子部品を使用して環境要因を監視する実践的な経験を提供します。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

一式キットを購入すると便利です。リンクはこちら:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

または、以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_flame`
        - |link_flame_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_03_Flame_Sensor_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/82f965f6-4213-4c23-88db-4257cf12d920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. **センサーピンの定義**:

   炎センサーが接続されているピンを整数定数として定義します。
 
   .. code-block:: arduino

      const int sensorPin = 25;

#. **セットアップ関数**:

   この関数はESP32が起動すると一度だけ実行されます。センサーピンを入力として初期化し、出力のために9600ボーのシリアル通信を開始します。
 
   .. code-block:: arduino

      void setup() {
        pinMode(sensorPin, INPUT);
        Serial.begin(9600);
      }

#. **ループ関数**:

   プログラムの核心部分で、炎センサーの状態を連続的にチェックします。センサーが炎を検知した場合（0を返す）、火災警告メッセージを表示します。そうでない場合は、火災が検知されていないことを示します。このチェックは100ミリ秒ごとに行われます。
 
   .. code-block:: arduino

      void loop() {
        if (digitalRead(sensorPin) == 0) {
          Serial.println("** Fire detected!!! **");
        } else {
          Serial.println("No Fire detected");
        }
        delay(100);
      }
