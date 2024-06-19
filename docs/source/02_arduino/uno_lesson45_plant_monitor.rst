
.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _uno_plant_monitor:

レッスン45: プラントモニター
=============================================================

このプロジェクトは、土壌の湿度が事前に設定されたしきい値を下回ると、水ポンプを作動させて植物に水を自動的に供給します。
また、LCDディスプレイに温度、湿度、および土壌湿度レベルを表示し、ユーザーに植物の環境条件に関する貴重な洞察を提供します。


必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式キットを購入するのが便利です。こちらのリンクをご覧ください:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

以下のリンクから別々に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_power_module`
        - \-
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_soil`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_dht11`
        - \-

配線
---------------------------

.. image:: img/Lesson_45_Plant_monitor_uno_bb.png
    :width: 100%

コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/700a51fb-6bb3-46c0-b0eb-5b03a6eb681e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

コードは環境パラメータを監視しながら、植物への水供給をシームレスに管理するように構成されています：

1. ライブラリのインクルードと定数/変数の宣言:

   ``Wire.h``, ``LiquidCrystal_I2C.h``, ``DHT.h``ライブラリを機能のためにインクルードします。
   DHT11センサー、土壌湿度センサー、水ポンプのピン割り当てと設定を指定します。

2. ``setup()``:

   湿度センサーとポンプのピンモードを設定します。
   最初にポンプをオフにします。
   LCDを初期化し、バックライトをオンにします。
   DHTセンサーを有効にします。

3. ``loop()``:

   DHTセンサーを介して湿度と温度を測定します。
   土壌湿度センサーを通じて土壌湿度を測定します。
   温度と湿度をLCDに表示し、その後土壌湿度レベルを表示します。
   土壌湿度を評価して水ポンプの作動を判断します。土壌湿度が500（調整可能なしきい値）以下の場合、ポンプを1秒間作動させます。



