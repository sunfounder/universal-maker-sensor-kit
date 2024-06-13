.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _uno_lesson32_passive_buzzer:

レッスン32: パッシブブザーモジュール
====================================

このレッスンでは、Arduinoを使用してパッシブブザーモジュールでメロディを演奏する方法を学びます。Arduinoをプログラムしてブザーを制御し、さまざまな音符の長さを作成する方法を説明します。このプロジェクトは、音を出す方法と電子部品内の音符の理解に関する実践的な経験を提供するため、初心者に最適です。また、Arduino Unoボードとパッシブブザーモジュールの使用に関する実践的な洞察を得ることもできます。

必要なコンポーネント
---------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

キット全体を購入するのが便利です。リンクはこちら：

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_module_buy|

配線
---------------------------

.. image:: img/Lesson_32_passive_buzzer_module_uno_bb.png
    :width: 100%


コード
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/eebc46ab-2a9d-4731-8778-3c8f07b0003b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コード解析
---------------------------

1. ピッチライブラリのインクルード:
   このライブラリは、さまざまな音符の周波数値を提供し、コード内で音楽記号を使用できるようにします。
.. code-block:: arduino
       
      #include "pitches.h"

2. 定数と配列の定義:

   * ``buzzerPin``はブザーが接続されているArduinoのデジタルピンです。

   * ``melody[]``は演奏する音符のシーケンスを格納する配列です。

   * ``noteDurations[]``はメロディの各音符の持続時間を格納する配列です。

   .. raw:: html
      
      <br/>

   .. code-block:: arduino
   
      const int buzzerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. メロディの演奏:

   * ``for``ループはメロディの各音符を反復処理します。

   * ``tone()``関数は特定の期間ブザーで音符を演奏します。

   * 音符を区別するために音符間に遅延が追加されます。

   * ``noTone()``関数は音を停止します。

   .. raw:: html
      
      <br/>

   .. code-block:: arduino
   
      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(buzzerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(buzzerPin);
        }
      }

4. 空のループ関数:
   メロディはセットアップ内で一度だけ再生されるため、ループ関数にはコードがありません。

