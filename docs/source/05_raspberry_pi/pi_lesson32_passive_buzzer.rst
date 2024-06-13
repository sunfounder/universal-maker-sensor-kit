.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson32_passive_buzzer:

レッスン32: パッシブブザーモジュール
====================================

このレッスンでは、Raspberry Piを使用してトナルブザーで音楽の音を作成する方法を学びます。Pythonを使用して一連の音符を演奏するようにRaspberry Piをプログラムする方法を学びます。レッスンには、音符と持続時間のリストとしてメロディを定義し、ブザーを通じてこれらの音符を演奏する関数を書くことが含まれています。このプロジェクトは、音出力とPythonプログラミングの基本的な理解を提供し、Raspberry Piを使用して音楽アプリケーションを探求したい初心者にとって実践的な選択肢です。

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

配線
---------------------------

.. image:: img/Lesson_32_Passive_buzzer_Pi_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from gpiozero import TonalBuzzer
   from time import sleep

   # Initialize the TonalBuzzer on GPIO pin 17
   tb = TonalBuzzer(17)  # Change to the pin number your buzzer is connected to

   def play(tune):
      """
      Play a musical tune using the buzzer.
      :param tune: List of tuples, where each tuple contains a note and its duration.
      """
      for note, duration in tune:
         print(note)  # Print the current note being played
         tb.play(note)  # Play the note on the buzzer
         sleep(float(duration))  # Wait for the duration of the note
      tb.stop()  # Stop the buzzer after playing the tune

   # Define the musical tune as a list of notes and their durations
   tune = [('C#4', 0.2), ('D4', 0.2), (None, 0.2),
      ('Eb4', 0.2), ('E4', 0.2), (None, 0.6),
      ('F#4', 0.2), ('G4', 0.2), (None, 0.6),
      ('Eb4', 0.2), ('E4', 0.2), (None, 0.2),
      ('F#4', 0.2), ('G4', 0.2), (None, 0.2),
      ('C4', 0.2), ('B4', 0.2), (None, 0.2),
      ('F#4', 0.2), ('G4', 0.2), (None, 0.2),
      ('B4', 0.2), ('Bb4', 0.5), (None, 0.6),
      ('A4', 0.2), ('G4', 0.2), ('E4', 0.2),
      ('D4', 0.2), ('E4', 0.2)]

   # メロディを演奏
   play(tune) 

コード解析
---------------------------

#. ライブラリのインポート
   
   音の生成のために ``gpiozero`` から ``TonalBuzzer`` を、タイミング制御のために ``time`` から ``sleep`` をインポートします。

   .. code-block:: python

      from gpiozero import TonalBuzzer
      from time import sleep

#. トナルブザーの初期化
   
   GPIOピン17に接続された ``TonalBuzzer`` オブジェクトを作成します。

   .. code-block:: python

      tb = TonalBuzzer(17)

#. 再生関数の定義
   
   ``play``関数は、音符とその持続時間を表すタプルのリストを入力として受け取ります。各タプルを反復処理して音符を再生し、その持続時間だけ待機します。

   .. code-block:: python

      def play(tune):
          for note, duration in tune:
              print(note)
              tb.play(note)
              sleep(float(duration))
          tb.stop()

#. メロディの定義
   
   メロディはタプルのリストとして定義されます。各タプルには音符とその持続時間（秒）が含まれます。 ``None`` は休符を表します。

   .. code-block:: python

      tune = [('C#4', 0.2), ('D4', 0.2), (None, 0.2), ...]

#. メロディの再生
   
   ``play`` 関数に ``tune`` リストを渡して呼び出すことで、ブザーが定義された音符のシーケンスを再生します。

   .. code-block:: python

      play(tune) 