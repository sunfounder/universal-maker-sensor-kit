.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _cpn_button:

ボタンモジュール
==========================

.. image:: img/01_button.png
    :width: 300
    :align: center

.. raw:: html

   <br/>

.. _btn_intro:

ボタンモジュールは、ボタンの状態を検出する電子デバイスです。通常、回路を接続または切断するスイッチとして使用されます。ボタンは、ドアベル、デスクランプ、リモコン、エレベーター、火災報知器など多くの場面で使用されます。

原理
---------------------------
ボタンモジュールはスイッチの原理で動作します。スイッチは、回路を開閉するために使用される電気部品です。

以下はボタンの内部構造です。右下のシンボルは、回路内でボタンを表すためによく使用されます。

.. image:: img/01_button_2.png
    :width: 400
    :align: center

ピン1がピン2に接続され、ピン3がピン4に接続されているため、ボタンを押すと4つのピンが接続され、回路が閉じます。

.. image:: img/01_button_3.png
    :width: 700
    :align: center

.. _cpn_button_sch:

回路図
---------------------------

.. image:: img/01_button_module_schematic.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>

例
---------------------------
* :ref:`uno_lesson01_button` (Arduino UNO)
* :ref:`eps32_lesson01_button` (ESP32)
* :ref:`pico_lesson01_button` (Raspberry Pi Pico)
* :ref:`pi_lesson01_button` (Raspberry Pi)
* :ref:`esp32_iot_mqtt` (ESP32)