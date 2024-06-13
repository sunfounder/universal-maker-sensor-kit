.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _install_micropython_on_pico:

PicoにMicroPythonをインストールする
==========================================

次に、Raspberry Pi PicoにMicroPythonをインストールします。Thonny IDEはワンクリックで非常に便利にインストールできます。

.. note::
    また、Raspberry Pi公式が提供する |link_micropython_pi| を使用して、 ``rp2_pico_xxxx.uf2`` ファイルをRaspberry Pi Picoにドラッグ＆ドロップする方法もあります。

#. Thonny IDEを開きます。

   .. image:: img/set_pico1.png

#. **BOOTSEL** ボタンを押し続けながら、PicoをMicro USBケーブルでコンピュータに接続します。Picoが **RPI-RP2** というマスストレージデバイスとしてマウントされたら **BOOTSEL** ボタンを離します。

   .. image:: img/bootsel_onboard.png
      :width: 70%
      :align: center

   .. raw:: html

      <br/>

#. 右下隅のインタープリタ選択ボタンをクリックし、 **Install Micropython**  を選択します。

   .. note::
      Thonnyにこのオプションがない場合は、最新バージョンに更新してください。

   .. image:: img/set_pico2.png

#. **Target volume** セクションでは、先ほど接続したPicoのボリュームが自動的に表示されます。 **variant** セクションで **Raspberry Pi.Pico/Pico H** を選択します。バージョンドロップダウンメニューで最新バージョンを選択します。

   .. image:: img/set_pico3.png

#. **Install** ボタンをクリックし、インストールが完了するのを待ちます。

   .. image:: img/set_pico4.png

#. おめでとうございます。これでRaspberry Pi Picoの準備が整いました。

   .. image:: img/set_pico5.png