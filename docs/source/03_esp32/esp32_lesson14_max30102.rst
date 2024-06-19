.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson14_max30102:

レッスン14: パルスオキシメータと心拍センサーモジュール (MAX30102)
====================================================================

このレッスンでは、ESP32開発ボードとMAX30102パルスオキシメータおよび心拍センサーを使用して心拍数を測定する方法を学びます。センサーの設定、赤外線値の読み取り、および正確な1分間の心拍数（BPM）の計算方法について説明します。このプロジェクトは、ヘルスモニタリングシステムに興味がある人に最適で、ESP32を使用した生体医療センサーの取り扱いについての貴重な導入となります。

.. warning::
    このプロジェクトは光学的に心拍数を検出します。この方法は難しく、誤読を招きやすいです。したがって、実際の医療診断には使用しないでください。

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
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_max30102`
        - |link_max30102_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_14_MAX30102_esp32_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a59539a0-dab1-414e-a195-3d221a61c9a9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. **ライブラリのインクルードとグローバル変数の初期化**:

   必要なライブラリがインポートされ、センサーオブジェクトがインスタンス化され、データ管理のためのグローバル変数が設定されます。

   .. note:: 
      ライブラリをインストールするには、Arduino Library Managerを使用して **"SparkFun MAX3010x"** を検索し、インストールしてください。
   
   .. code-block:: arduino
    
      #include <Wire.h>
      #include "MAX30105.h"
      #include "heartRate.h"
      MAX30105 particleSensor;
      // ... (他のグローバル変数)

2. **セットアップ関数とセンサーの初期化**:

   シリアル通信が9600ボーで初期化されます。センサーの接続がチェックされ、成功すると初期化シーケンスが実行されます。センサーが検出されない場合はエラーメッセージが表示されます。
   
   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
          Serial.println("MAX30102 not found.");
          while (1) ;  // Infinite loop if sensor not detected.
        }
        // ... (further setup)

3. **IR値の読み取りと心拍の確認**:

   血流を示すIR値がセンサーから取得されます。この値に基づいて ``checkForBeat()``関数が心拍を検出するかどうかを評価します。

   .. code-block:: arduino

      long irValue = particleSensor.getIR();
      if (checkForBeat(irValue) == true) {
          // ... (heartbeat detected actions)
      }

4. **1分間の心拍数（BPM）の計算**:

   心拍が検出されると、最後に検出された心拍からの時間差に基づいてBPMが計算されます。コードはまた、BPMが現実的な範囲内であることを確認し、平均を更新します。

   .. code-block:: arduino

      long delta = millis() - lastBeat;
      beatsPerMinute = 60 / (delta / 1000.0);
      if (beatsPerMinute < 255 && beatsPerMinute > 20) {
          // ... (store and average BPM)
      }
      

5. **シリアルモニタへの値の表示**:

   IR値、現在のBPM、および平均BPMがシリアルモニタに表示されます。さらに、IR値が低すぎる場合、指がセンサー上にないことを示唆します。

   .. code-block:: arduino

      //Print the IR value, current BPM value, and average BPM value to the serial monitor
      Serial.print("IR=");
      Serial.print(irValue);
      Serial.print(", BPM=");
      Serial.print(beatsPerMinute);
      Serial.print(", Avg BPM=");
      Serial.print(beatAvg);

      if (irValue < 50000)
        Serial.print(" No finger?");