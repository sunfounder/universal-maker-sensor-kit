.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pi_lesson24_vibration_sensor:

レッスン24: 振動センサーモジュール (SW-420)
==============================================

このレッスンでは、振動センサーを使用してRaspberry Piと接続する方法を学びます。センサーをGPIOピン17に接続し、シンプルなPythonスクリプトを書く手順を説明します。このスクリプトはセンサーを監視し、振動が検出されたときにメッセージを表示します。このレッスンは、初心者に対して簡単なセンサーをRaspberry Piに接続し、それと対話するための簡単なスクリプトを書く実践的な体験を提供することに焦点を当てています。

必要なコンポーネント
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全てが揃ったキットを購入すると便利です。リンクはこちらです：

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
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_24_vibration_sensor_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import InputDevice
   import time
   
   # Connect the digital output of the vibration sensor to GPIO17 on the Raspberry Pi
   vibration_sensor = InputDevice(17)
   
   # Continuous loop to read from the sensor
   while True:
       # Check if the sensor is active (no vibration detected)
       if vibration_sensor.is_active:
           print("Vibration detected!")
       else:
           # When the sensor is inactive (vibration detected)
           print("...")
       # Wait for 1 second before reading the sensor again
       time.sleep(1)

コード解析
---------------------------

#. **ライブラリのインポート**

   まず、必要なライブラリをインポートします。GPIOピンと対話するための ``gpiozero`` と、時間関連の関数を扱うための ``time`` です。

   .. code-block:: python

      from gpiozero import InputDevice
      import time

#. **振動センサーのセットアップ**

   ``gpiozero``ライブラリから ``InputDevice`` のインスタンスを作成して振動センサーを初期化します。振動センサーはRaspberry PiのGPIOピン17に接続されています。

   .. code-block:: python

      vibration_sensor = InputDevice(17)

#. **連続監視ループ**

   ``while True``ループを使用して、連続監視を行います。このループはプログラムが手動で停止されるまで無期限に実行されます。

   .. code-block:: python

      while True:

#. **センサー状態のチェックと出力**

   - ループ内で、``if``文を使用して振動センサーの状態をチェックします。 ``vibration_sensor.is_active`` が ``True`` の場合、振動が検出されていないことを意味し、「Vibration detected!」が表示されます。
   - ``vibration_sensor.is_active``が ``False`` の場合は振動が検出されたことを示し、代わりに"..."が表示されます。
   - この区別は、コード内でセンサーの出力がどのように解釈されるかを理解するために重要です。

   .. code-block:: python

          if vibration_sensor.is_active:
              print("Vibration detected!")
          else:
              print("...")

#. **遅延**

   最後に、 ``time.sleep(1)`` はループの各反復の間に1秒の遅延を追加します。この遅延は、プログラムがCPUを過負荷にしないようにし、出力を読みやすくするために重要です。

   .. code-block:: python

          time.sleep(1)

