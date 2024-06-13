
.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！
.. _add_libraries_py:

ライブラリをPicoにアップロードする
===================================

いくつかのプロジェクトでは、追加のライブラリが必要になります。ここでは、これらのライブラリをRaspberry Pi Pico Wにアップロードし、後でコードを直接実行できるようにします。

#. 以下のリンクから関連コードをダウンロードします。

   * :download:`SunFounder Universal Maker Sensor Kit <https://codeload.github.com/sunfounder/universal-maker-sensor-kit/zip/refs/heads/main>`

#. Thonny IDEを開き、PicoをMicro USBケーブルでコンピュータに接続し、右下隅の「MicroPython (Raspberry Pi Pico).COMXX」インタープリタをクリックします。

   .. image:: img/sec_inter.png

#. 上部のナビゲーションバーで、 **表示** -> **ファイル** をクリックします。

   .. image:: img/th_files.png

#. ダウンロードした`コードパッケージ `code package <https://codeload.github.com/sunfounder/universal-maker-sensor-kit/zip/refs/heads/main>`_  のフォルダにパスを切り替え、 ``universal-maker-sensor-kit-main/pico/libs`` フォルダに移動します。

   .. image:: img/th_path.png

#. 「libs/」フォルダ内のすべてのファイルまたはフォルダを選択（Shiftキーを押しながらフォルダ内の最初と最後のファイルをクリック）し、右クリックして **/ にアップロード** を選択します。アップロードにはしばらく時間がかかります。

   .. image:: img/th_upload.png

#. アップロードが完了したら、ドライブ「Raspberry Pi Pico」の中に先ほどアップロードしたファイルが表示されます。

   .. image:: img/th_done.png
