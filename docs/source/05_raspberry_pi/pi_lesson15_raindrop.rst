.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pi_lesson15_raindrop:

レッスン15: 雨滴検出モジュール
=======================================

このレッスンでは、Raspberry Piを使用してデジタル雨センサーで雨を検出する方法を学びます。雨センサーをRaspberry PiのGPIOピン17に接続する手順を説明します。Pythonを使用してセンサーを継続的に監視するプログラムの作成方法を学びます。このプログラムは、雨が降っているかどうかを判断し、適切なメッセージを表示します。この実践的なプロジェクトは、環境センサーの使用、GPIOインターフェース、およびPythonプログラミングの優れた導入となり、Raspberry Piを使用した天気関連のプロジェクトに興味のある初心者に最適です。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

全キットを購入するのが便利です。リンクはこちらです：

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

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_raindrop`
        - |link_raindrop_sensor_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_15_raindrop_detection_module_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import DigitalInputDevice  
   from time import sleep  

   # Initialize the sensor as a digital input device on GPIO pin 17
   rain_sensor = DigitalInputDevice(17)

   while True:  # Infinite loop to continuously check the sensor status
       if rain_sensor.is_active:  # Check if the sensor is active (no rain)
           print("No rain detected.")  # Print message for no rain detected
       else:
           print("Rain detected!")  # Print message for rain detected
       sleep(1)  # Wait for 1 second before next check


Code Analysis
---------------------------

#. ライブラリのインポート
   
   スクリプトは、gpiozeroから ``DigitalInputDevice`` をインポートして雨センサーとインターフェースし、timeモジュールから ``sleep`` をインポートして遅延を実装することから始まります。

   .. code-block:: python

      from gpiozero import DigitalInputDevice  
      from time import sleep  

#. 雨センサーの初期化
   
   GPIOピン17に接続された ``DigitalInputDevice`` オブジェクト ``rain_sensor`` が作成されます。この行は、雨センサーがこのGPIOピンを通じてRaspberry Piと通信するように設定します。

   .. code-block:: python

      rain_sensor = DigitalInputDevice(17)

#. 連続監視ループの実装
   
   - 無限ループ（ ``while True:`` ）が設定され、雨センサーを継続的に監視します。
   - ループ内で、 ``if`` 文が ``rain_sensor`` の ``is_active`` プロパティをチェックします。
   - ``is_active``が ``True`` の場合、雨が検出されていないことを示し、 "No rain detected."が表示されます。
   - ``is_active``が ``False`` の場合、雨が検出されたことを示し、"Rain detected!" が表示されます。
   - ``sleep(1)``は各チェックの間に1秒の遅延を挿入し、センサーポーリングの頻度を制御し、CPU使用率を減少させます。

   .. raw:: html

      <br/>

   .. code-block:: python

      while True:
          if rain_sensor.is_active:
              print("No rain detected.")
          else:
              print("Rain detected!")
          sleep(1)

