.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _pico_lesson16_ds1306:

レッスン16: リアルタイムクロックモジュール (DS1302)
==================================================

このレッスンでは、Raspberry Pi Pico Wを使用してDS1302リアルタイムクロックモジュールとやり取りする方法を学びます。まず、特定のGPIOピンを使用してDS1302をPico Wに接続する手順を説明します。さらに、DS1302で現在の日付と時刻を取得および設定する方法を学びます。また、コンソールに現在の日付と時刻を継続的に表示し、毎秒半ごとに更新する方法も探ります。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式購入するのが便利です。リンクはこちら：

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

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_rtc_ds1302`
        - |link_ds1302_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

配線
---------------------------

.. image:: img/Lesson_16_DS1302_module_bb.png
    :width: 100%

コード
---------------------------

.. note::

    * ``universal-maker-sensor-kit-main/pico/Lesson_16_DS1302_Module`` のパスにある ``16_ds1302_module.py`` ファイルを開くか、このコードを Thonny にコピーし、「現在のスクリプトを実行」をクリックするか、F5 キーを押して実行します。詳細なチュートリアルについては :ref:`open_run_code_py` を参照してください。

    * ここでは ``ds1302.py`` を使用する必要があります。Pico W にアップロードされているか確認してください。詳細なチュートリアルについては :ref:`add_libraries_py` を参照してください。
    * 右下隅にある「MicroPython (Raspberry Pi Pico)」インタープリタをクリックするのを忘れないでください。

.. code-block:: python

   from machine import Pin
   import ds1302
   import time
   
   # Initialize DS1302 RTC with specific GPIO pins
   ds = ds1302.DS1302(Pin(5), Pin(18), Pin(19))  # (clk, dio, cs)
   
   # Get current datetime from DS1302
   ds.date_time()
   
   # Set DS1302 datetime to 2024-01-01 Monday 00:00:00
   ds.date_time([2024, 1, 1, 1, 0, 0, 0])  # (year,month,day,weekday,hour,minute,second)
   
   # Set seconds to 10
   ds.second(10)
   
   # Continuously display current datetime every half second
   while True:
       print(ds.date_time())
       time.sleep(0.5)


Code Analysis
---------------------------

#. **ライブラリのインポート**

   このセクションでは、必要なライブラリをインポートします。 ``machine`` はGPIO制御用、 ``ds1302`` はRTCモジュール用、 ``time`` は遅延処理用です。

   ``ds1302``ライブラリの詳細については、 ``ds1302.py`` を参照してください。

   .. code-block:: python

      from machine import Pin
      import ds1302
      import time

#. **DS1302 RTCの初期化**

   ここでは、DS1302モジュールを初期化し、Raspberry Pi Pico WのGPIOピンを定義します。これにより、クロック（clk）、データ入出力（dio）、チップセレクト（cs）の各ピンが接続されます。

   .. code-block:: python

      ds = ds1302.DS1302(Pin(5), Pin(18), Pin(19))  # (clk, dio, cs)

#. **現在の日時の取得**

   DS1302から現在の日付と時刻を取得します。 ``date_time()`` メソッドは、年、月、日、曜日、時、分、秒を含むリストを返します。

   .. code-block:: python

      ds.date_time()

#. **DS1302の日時設定**

   DS1302の日付と時刻を2024年1月1日00:00:00に設定します。曜日（月曜日）は1で表されます。
   
   .. code-block:: python

      ds.date_time([2024, 1, 1, 1, 0, 0, 0])  # (year,month,day,weekday,hour,minute,second)

#. **秒の設定**

   DS1302の時間の秒の値を10に設定します。

   .. code-block:: python

      ds.second(10)

#. **現在の日時を継続的に表示**

   このループは、現在の日付と時刻を毎秒0.5秒ごとに継続的に表示します。 ``time.sleep(0.5)`` 関数は、各反復間に0.5秒の遅延を作成します。

   .. code-block:: python

      while True:
          print(ds.date_time())
          time.sleep(0.5)