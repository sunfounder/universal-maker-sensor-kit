.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _esp32_lesson10_pcf8591:

レッスン10: PCF8591 ADC DAC コンバーターモジュール
==================================================

このレッスンでは、ESP32開発ボードをPCF8591 ADC DACコンバーターモジュールに接続する方法を学びます。入力AIN0からアナログ値を読み取り、これらの値をDAC（AOUT）に送信し、シリアルモニタに生の読み取り値と電圧変換後の値を表示する方法をカバーします。モジュールのポテンショメータはジャンパーキャップを使用してAIN0に接続され、モジュールのD2 LEDはAOUTに接続されているため、ポテンショメータを回すとD2 LEDの明るさが変わることがわかります。

必要な部品
--------------------------

このプロジェクトには以下の部品が必要です。

全ての部品が揃ったキットを購入すると便利です。リンクはこちら：

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
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_10_PCF8591_Module_esp32_bb.png
    :width: 100%


コード
---------------------------

.. note:: 
   ライブラリをインストールするには、Arduinoライブラリマネージャを使用して **"Adafruit PCF8591"** を検索し、インストールしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5f184da9-9ea5-4c8a-877e-a7a41abf8c15/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. **ライブラリのインクルードと定数の定義**

   .. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャを使用して **"Adafruit PCF8591"** を検索し、インストールしてください。

   .. code-block:: arduino

      // Include Adafruit PCF8591 library
      #include <Adafruit_PCF8591.h>
      // Define the reference voltage for ADC conversion
      #define ADC_REFERENCE_VOLTAGE 3.3

   このセクションでは、PCF8591モジュールと対話するための関数を提供するAdafruit PCF8591ライブラリをインクルードします。ADCの基準電圧は3.3ボルトに設定されており、これはADCが測定できる最大電圧です。

#. **PCF8591モジュールの設定**

   .. code-block:: arduino

      // Create an instance of the PCF8591 module
      Adafruit_PCF8591 pcf = Adafruit_PCF8591();
      void setup() {
        Serial.begin(9600);
        Serial.println("# Adafruit PCF8591 demo");
        if (!pcf.begin()) {
          Serial.println("# PCF8591 not found!");
          while (1) delay(10);
        }
        Serial.println("# PCF8591 found");
        pcf.enableDAC(true);
      }

   setup関数では、シリアル通信を開始し、PCF8591モジュールのインスタンスを作成します。 ``pcf.begin()`` 関数は、モジュールが正しく接続されているかを確認します。接続されていない場合、エラーメッセージを出力し、プログラムを停止します。モジュールが見つかった場合、DACを有効にします。

#. **ADCからの読み取りとDACへの書き込み**

   .. code-block:: arduino

      void loop() {
        AIN0 = pcf.analogRead(0);
        pcf.analogWrite(AIN0);
        Serial.print("AIN0: ");
        Serial.print(AIN0);
        Serial.print(", ");
        Serial.print(int_to_volts(AIN0, 8, ADC_REFERENCE_VOLTAGE));
        Serial.println("V");
        delay(500);
      }

   loop関数では、PCF8591モジュールのAIN0（アナログ入力0）からアナログ値を連続的に読み取り、その値をDACに書き戻します。また、AIN0の生の値と電圧変換後の値をシリアルモニタに出力します。

   ジャンパーキャップはモジュールのポテンショメータをAIN0に接続し、D2 LEDはAOUTに接続されています。PCF8591モジュールの :ref:`schematic <cpn_pcf8591_sch>` を参照してください。ポテンショメータを回すと、LEDの明るさが変わります。

#. **デジタル値を電圧に変換する関数**

   .. code-block:: arduino

      float int_to_volts(uint16_t dac_value, uint8_t bits, float logic_level) {
        return (((float)dac_value / ((1 << bits) - 1)) * logic_level);
      }
 
   この関数は、デジタル値を対応する電圧に変換します。引数にはデジタル値（ ``dac_value`` ）、解像度のビット数（ ``bits`` ）、および論理レベルの電圧（ ``logic_level`` ）が含まれます。この公式は、デジタル値を対応する電圧に変換するための標準的なアプローチです。
