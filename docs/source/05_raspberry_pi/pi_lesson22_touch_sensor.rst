.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson22_touch_sensor:

レッスン22: タッチセンサーモジュール
==================================

このレッスンでは、Raspberry Piを使用してタッチセンサーを接続し、Pythonでプログラムする方法を学びます。GPIOピン17にセンサーを設定し、タッチおよびリリースイベントを検出して応答する簡単なスクリプトを作成することに焦点を当てます。この実践的なセッションは、Pythonでのセンサー統合とイベント処理の基本を教えることを目的としており、より高度なセンサーを使用したプロジェクトに必要なスキルを提供します。電子機器やRaspberry Piの作業に不慣れな方にとって理想的なスタート地点です。

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
    *   - :ref:`cpn_touch`
        - |link_touch_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_22_touch_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import Button
   from signal import pause

   # Function called when the sensor is touched
   def touched():
       # Print a message indicating the sensor is touched
       print("Touched!")  

   # Function called when the sensor is not touched
   def not_touched():
       # Print a message indicating the sensor is not touched
       print("Not touched!")  

   # Initialize a Button object for the touch sensor
   # GPIO 17: pin connected to the sensor
   # pull_up=None: disable internal pull-up/pull-down resistors
   # active_state=True: high voltage is considered the active state
   touch_sensor = Button(17, pull_up=None, active_state=True)

   # Assign functions to sensor events
   touch_sensor.when_pressed = touched
   touch_sensor.when_released = not_touched

   pause()  # Keep the program running to detect touch events



コード解析
---------------------------

#. ライブラリのインポート
   
   スクリプトは、タッチセンサーとのインターフェースのためにgpiozeroから ``Button`` クラスを、プログラムを実行し続けてイベントに応答させるためにsignalモジュールから ``pause`` をインポートすることから始まります。

   .. code-block:: python

      from gpiozero import Button
      from signal import pause

#. コールバック関数の定義
   
   センサーのタッチとリリースイベントを処理するために、 ``touched`` と ``not_touched`` という2つの関数が定義されます。それぞれの関数は、センサーの状態を示すメッセージを表示します。

   .. code-block:: python

      def touched():
          print("Touched!")  

      def not_touched():
          print("Not touched!")  

#. タッチセンサーの初期化
   
   GPIOピン17にタッチセンサー用の ``Button`` オブジェクト ``touch_sensor`` が作成されます。 ``pull_up`` パラメータは内部プルアップ/プルダウン抵抗を無効にするために ``None`` に設定され、 ``active_state`` は高電圧をアクティブ状態と見なすために ``True`` に設定されます。

   .. code-block:: python

      touch_sensor = Button(17, pull_up=None, active_state=True)

#. センサーイベントへの関数の割り当て
   
   ``touch_sensor``の ``when_pressed`` イベントが ``touched`` 関数にリンクされ、 ``when_released`` イベントが ``not_touched`` 関数にリンクされます。この設定により、スクリプトはセンサーのタッチとリリースイベントに応答することができます。

   .. code-block:: python

      touch_sensor.when_pressed = touched
      touch_sensor.when_released = not_touched

#. プログラムを実行し続ける
   
   プログラムを無期限に実行し続けるために ``pause()`` 関数が呼び出されます。これは、タッチセンサーイベントを継続的に監視して応答するために必要です。

   .. code-block:: python

      pause()