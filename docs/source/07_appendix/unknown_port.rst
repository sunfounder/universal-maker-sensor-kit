.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _unknown_com_port:

常に「Unknown COMxx」が表示される場合
======================================

ESP32をコンピュータに接続すると、Arduino IDEがしばしば ``Unknown COMxx`` と表示します。なぜこのようなことが起こるのでしょうか？

.. image:: img/unknown_device.png

これは、ESP32のUSBドライバーが通常のArduinoボードとは異なるためです。Arduino IDEはこのボードを自動的に認識できません。

このような場合は、次の手順に従って正しいボードを手動で選択する必要があります：

#. **「Select the other board and port」をクリックします。**

    .. image:: img/unknown_select.png

#. 検索ボックスに **"esp32 dev module"** と入力し、表示されるボードを選択します。その後、正しいポートを選択して **OK** をクリックします。

    .. image:: img/unknown_board.png

#. これで、クイックビューウィンドウにボードとポートが表示されるはずです。

    .. image:: img/unknown_correct.png
