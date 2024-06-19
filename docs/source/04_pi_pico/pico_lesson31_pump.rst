.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson31_pump:

レッスン31: 遠心ポンプ
==================================

このレッスンでは、Raspberry Pi Pico WとL9110モーター制御ボードを使用して遠心ポンプを操作する方法を学びます。モーターを制御するために2つのPWM（パルス幅変調）ピンを設定する手順を説明します。ポンプを5秒間動作させ、その後停止させる設定を行います。この実践的な演習は、マイクロコントローラープログラミングにおいて重要なモーター制御メカニズムとPWM信号に触れる貴重な機会を提供します。

必要な部品
--------------------------

このプロジェクトでは、以下の部品が必要です。

以下のリンクからキット全体を購入すると便利です：

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
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


配線
---------------------------

.. image:: img/Lesson_31_Pump_pico_bb.png
    :width: 100%


コード
---------------------------

.. code-block:: python

   from machine import Pin, PWM
   import time
   
   pump_a = PWM(Pin(26), freq=1000)
   pump_b = PWM(Pin(27), freq=1000)
   
   # turn on pump
   pump_a.duty_u16(0)
   pump_b.duty_u16(65535)  # speed(0-65535)
   
   time.sleep(5)
   
   # turn off pump
   pump_a.duty_u16(0)
   pump_b.duty_u16(0)


コード解析
---------------------------

#. ライブラリのインポート

   - ``machine`` モジュールは、Raspberry Pi Pico WのGPIOピンおよびPWM機能を操作するためにインポートされます。
   - ``time`` モジュールは、コード内で遅延を作成するために使用されます。

   .. raw:: html

      <br/>

   .. code-block:: python

      from machine import Pin, PWM
      import time

#. PWMオブジェクトの初期化

   - 2つのPWMオブジェクト、 ``pump_a`` と ``pump_b`` が作成されます。それぞれGPIOピン26および27に対応します。
   - PWMの周波数は1000Hzに設定されており、これはモーター制御に一般的な周波数です。

   .. raw:: html

      <br/>

   .. code-block:: python

      pump_a = PWM(Pin(26), freq=1000)
      pump_b = PWM(Pin(27), freq=1000)

#. ポンプをオンにする

   - ``pump_a.duty_u16(0)`` は ``pump_a`` ピンのデューティサイクルを0に設定し、 ``pump_b.duty_u16(65535)`` は ``pump_b`` ピンのデューティサイクルを65535に設定し、モーターを全速で動作させます。詳細については、:ref:`L9110の動作原理 <cpn_l9110_principle>` を参照してください。
   - ポンプは ``time.sleep(5)`` によって制御され、5秒間動作します。

   .. raw:: html

      <br/>

   .. code-block:: python

      # turn on pump
      pump_a.duty_u16(0)
      pump_b.duty_u16(65535)  # speed(0-65535)
      time.sleep(5)

#. ポンプをオフにする

   ``pump_a`` と ``pump_b`` の両方のデューティサイクルを0に設定し、モーターを停止させます。

   .. code-block:: python

      # turn off pump
      pump_a.duty_u16(0)
      pump_b.duty_u16(0)