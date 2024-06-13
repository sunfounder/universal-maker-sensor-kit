.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _uno_lesson10_pcf8591:

レッスン 10: PCF8591 ADC DACコンバーターモジュール
==============================================

このレッスンでは、Arduino Uno R4（またはR3）とPCF8591 ADC DACコンバーターモジュールを接続する方法を学びます。入力AIN0からアナログ値を読み取り、これらの値をDAC（AOUT）に送信し、生の読み取り値と電圧変換された読み取り値の両方をシリアルモニターに表示する方法をカバーします。モジュールのポテンショメーターはジャンパーキャップを使用してAIN0に接続されており、モジュール上のD2 LEDはAOUTに接続されているため、ポテンショメーターを回すとD2 LEDの明るさが変わる様子を確認できます。

必要なコンポーネント
--------------------------

このプロジェクトには以下のコンポーネントが必要です。

キット全体を購入するのが便利です。こちらのリンクからどうぞ:

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

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_pcf8591`
        - |link_pcf8591_module_buy|


配線
---------------------------

.. image:: img/Lesson_10_PCF8591_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/217d04d3-2c19-44df-b66b-5c1582955260/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

#. **ライブラリのインクルードと定数の定義**

   .. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャを使用し、 **"Adafruit PCF8591"**を検索してインストールします。

   .. code-block:: arduino

      // Include Adafruit PCF8591 library
      #include <Adafruit_PCF8591.h>
      // Define the reference voltage for ADC conversion
      #define ADC_REFERENCE_VOLTAGE 5.0

   このセクションでは、PCF8591モジュールとの対話に必要なAdafruit PCF8591ライブラリをインクルードします。ADC基準電圧は5.0ボルトに設定されており、これはADCが測定できる最大電圧です。

#. **PCF8591モジュールのセットアップ**

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

   setup関数では、シリアル通信を開始し、PCF8591モジュールのインスタンスを作成します。 ``pcf.begin()`` 関数は、モジュールが正しく接続されているかどうかを確認します。接続されていない場合、エラーメッセージを表示し、プログラムを停止します。モジュールが見つかった場合、DACを有効にします。

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

   loop関数では、PCF8591モジュールのAIN0（アナログ入力0）からアナログ値を連続的に読み取り、この値をDACに書き戻します。また、AIN0の生の値と電圧変換された値をシリアルモニタに表示します。

   ジャンパーキャップはモジュールのポテンショメーターをAIN0にリンクし、D2 LEDはAOUTに接続されています。詳細については、PCF8591モジュールの :ref:`回路図 <cpn_pcf8591_sch>` を参照してください。ポテンショメーターを回すとLEDの明るさが変わります。

#. **デジタル値を電圧に変換する関数**

   .. code-block:: arduino

      float int_to_volts(uint16_t dac_value, uint8_t bits, float logic_level) {
        return (((float)dac_value / ((1 << bits) - 1)) * logic_level);
      }

   この関数は、デジタル値を対応する電圧に変換します。引数としてデジタル値（ ``dac_value`` ）、解像度のビット数（ ``bits`` ）、論理レベル電圧（ ``logic_level`` ）を取ります。この公式は、デジタル値をその等価電圧に変換するための標準的なアプローチです。
