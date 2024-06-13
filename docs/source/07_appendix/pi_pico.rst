.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
    
.. _cpn_pico_w:

Raspberry Pi Pico W
=======================================

.. image:: img/pico_w_side.png
    :width: 60%
    :align: center

Raspberry Pi Pico Wは、ベストセラーのRaspberry Pi Pico製品ラインにワイヤレス接続をもたらします。RP2040シリコンプラットフォームを基盤とし、高性能、低コスト、使いやすさをマイクロコントローラー分野に提供します。

Raspberry Pi Pico Wは、2.4GHz 802.11 b/g/nワイヤレスLANサポート、オンボードアンテナ、およびモジュールコンプライアンス認証を提供します。ステーションモードとアクセスポイントモードの両方で動作可能です。ネットワーク機能へのフルアクセスは、CおよびMicroPython開発者の両方に利用可能です。

Raspberry Pi Pico Wは、RP2040と2MBのフラッシュメモリ、および1.8〜5.5Vの入力電圧をサポートする電源チップを組み合わせています。0.1インチピッチのスルーホールパッドとキャステレートエッジ上に26のGPIOピンを提供し、そのうち3つはアナログ入力として機能します。Raspberry Pi Pico Wは、個別のユニットとして、または自動組立用の480ユニットのリールとして入手可能です。

特徴
--------------

* 21 mm x 51 mmのフォームファクター
* 英国のRaspberry Piによって設計されたRP2040マイクロコントローラーチップ
* デュアルコアArm Cortex-M0+プロセッサ、最大133 MHzで動作する柔軟なクロック
* 264kBオンチップSRAM
* 2MBオンボードQSPIフラッシュ
* 2.4GHz 802.11nワイヤレスLAN
* 3つのアナログ入力を含む26の多機能GPIOピン
* 2 x UART、2 x SPIコントローラー、2 x I2Cコントローラー、16 x PWMチャンネル
* ホストおよびデバイスサポートを備えた1 x USB 1.1コントローラーおよびPHY
* カスタムペリフェラルサポート用の8 x プログラム可能I/O (PIO)ステートマシン
* 1.8-5.5V DCの入力電力をサポート
* 動作温度 -20°C〜+70°C
* キャステレートモジュールにより、キャリアボードへの直接はんだ付けが可能
* USB経由でのマスストレージを使用したドラッグアンドドロッププログラミング
* 低消費電力のスリープおよびドーマントモード
* 正確なオンチップクロック
* 温度センサー
* オンチップの整数および浮動小数点ライブラリのアクセラレーション

Picoのピン
------------

.. image:: img/pico_pin.jpg
    :width: 100%
    :align: center

.. raw:: html

    <br/>

.. list-table::
    :widths: 3 5 10
    :header-rows: 1

    *   - Name
        - Description
        - Function
    *   - GP0-GP28
        - 汎用入力/出力ピン
        - 入力または出力として機能し、特定の目的はありません
    *   - GND
        - 0ボルトのグラウンド
        - Pico Wの周りにいくつかのGNDピンがあり、配線を容易にします。
    *   - RUN
        - Picoの有効/無効を切り替え
        - 別のマイクロコントローラーからPico Wを起動および停止できます。
    *   - GPxx_ADCx
        - 汎用入力/出力またはアナログ入力
        - アナログ入力として使用されるだけでなく、デジタル入力または出力としても機能しますが、同時に使用することはできません。
    *   - ADC_VREF
        - アナログ-デジタルコンバータ(ADC)の電圧リファレンス
        - アナログ入力の基準電圧を設定する特別な入力ピンです。
    *   - AGND
        - アナログ-デジタルコンバータ(ADC)の0ボルトグラウンド
        - ADC_VREFピンと一緒に使用する特別なグラウンド接続です。
    *   - 3V3(O)
        - 3.3ボルトの電源
        - Pico W内部で生成される3.3V電力の供給源で、VSYS入力から生成されます。
    *   - 3v3(E)
        - 電源の有効/無効を切り替え
        - 3V3(O)電力をオンまたはオフにし、Pico Wをオフにすることもできます。
    *   - VSYS
        - 2-5ボルトの電源
        - Pico内部の電源に直接接続されているピンで、Pico Wをオフにしない限りオフにすることはできません。
    *   - VBUS
        - 5ボルトの電源
        - PicoのマイクロUSBポートから取り出された5V電力の供給源で、3.3V以上の電力を必要とするハードウェアに電力を供給します。

Raspberry Pi Pico Wの使用を始めるために必要なすべての情報は `こちら <https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html>`_ にあります。

または、以下のリンクをクリックしてください:

* `Raspberry Pi Pico W製品概要 <https://datasheets.raspberrypi.com/picow/pico-w-product-brief.pdf>`_
* `Raspberry Pi Pico Wデータシート <https://datasheets.raspberrypi.com/picow/pico-w-datasheet.pdf>`_
* `Raspberry Pi Picoの始め方: C/C++開発 <https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf>`_
* `Raspberry Pi Pico C/C++ SDK <https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-c-sdk.pdf>`_
* `Raspberry Pi Pico C/C++ SDKのAPIレベルドキュメント <https://raspberrypi.github.io/pico-sdk-doxygen/>`_
* `Raspberry Pi Pico Python SDK <https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-python-sdk.pdf>`_
* `Raspberry Pi RP2040データシート <https://datasheets.raspberrypi.org/rp2040/rp2040-datasheet.pdf>`_
* `RP2040を使用したハードウェア設計 <https://datasheets.raspberrypi.org/rp2040/hardware-design-with-rp2040.pdf>`_
* `Raspberry Pi Pico W設計ファイル <https://datasheets.raspberrypi.com/picow/RPi-PicoW-PUBLIC-20220607.zip>`_
* `Raspberry Pi Pico W STEPファイル <https://datasheets.raspberrypi.com/picow/PicoW-step.zip>`_
