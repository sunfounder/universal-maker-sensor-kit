.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _pico_lesson34_motor:

レッスン34: TTモーター
==================================

このレッスンでは、Raspberry Pi Pico WとL9110モータ制御ボードを使用してTTモーターを操作する方法を学びます。モーターを制御するために2つのPWM（パルス幅変調）ピンを設定するプロセスをガイドします。モーターを5秒間動作させ、その後停止するように設定します。この実践的な演習は、マイクロコントローラープログラミングにおけるモーター制御メカニズムとPWM信号に関する貴重な機会を提供します。

Required Components
--------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

一式キットを購入すると非常に便利です。リンクはこちら：

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
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_34_Motor_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import Pin, PWM
   import time
   
   motor_a = PWM(Pin(26), freq=1000)
   motor_b = PWM(Pin(27), freq=1000)
   
   # turn on motor
   motor_a.duty_u16(0)
   motor_b.duty_u16(65535)  # speed(0-65535)
   
   time.sleep(5)
   
   # turn off motor
   motor_a.duty_u16(0)
   motor_b.duty_u16(0)

Code Analysis
---------------------------

#. ライブラリのインポート

   - ``machine`` モジュールは、Raspberry Pi Pico WのGPIOピンとPWM機能を操作するためにインポートされます。
   - ``time`` モジュールは、コード内で遅延を作成するために使用されます。

   .. raw:: html

      <br/>

   .. code-block:: python

      from machine import Pin, PWM
      import time

#. PWMオブジェクトの初期化

   - 2つのPWMオブジェクト、 ``motor_a`` と ``motor_b`` を作成します。これらはそれぞれGPIOピン26と27に対応しています。
   - PWMの周波数はモーター制御によく使われる1000 Hzに設定されます。

   .. raw:: html

      <br/>

   .. code-block:: python

      motor_a = PWM(Pin(26), freq=1000)
      motor_b = PWM(Pin(27), freq=1000)

#. モーターのオン

   - ``motor_a.duty_u16(0)`` は ``motor_a`` ピンのデューティサイクルを0に設定し、 ``motor_b.duty_u16(65535)`` は ``motor_b`` ピンのデューティサイクルを65535に設定し、モーターを全速で動作させます。詳細については :ref:`L9110の動作原理 <cpn_l9110_principle>` を参照してください。
   - モーターは ``time.sleep(5)`` によって制御され、5秒間動作します。

   .. raw:: html

      <br/>

   .. code-block:: python

      # turn on motor
      motor_a.duty_u16(0)
      motor_b.duty_u16(65535)  # speed(0-65535)
      time.sleep(5)

#. モーターのオフ

   ``motor_a`` と ``motor_b`` は両方ともデューティサイクルを0に設定し、モーターを停止させます。

   .. code-block:: python

      # turn off motor
      motor_a.duty_u16(0)
      motor_b.duty_u16(0)