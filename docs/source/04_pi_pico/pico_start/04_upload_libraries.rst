
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

Upload the Libraries to Pico
===================================

In some projects, you will need additional libraries. So here we upload these libraries to Raspberry Pi Pico W first, and then we can run the code directly later.

#. Download the relevant code from the link below.

   * :download:`SunFounder Universal Maker Sensor Kit <https://codeload.github.com/sunfounder/universal-maker-sensor-kit/zip/refs/heads/main>`


#. Open Thonny IDE and plug the Pico into your computer with a micro USB cable and click on the "MicroPython (Raspberry Pi Pico).COMXX" interpreter in the bottom right corner.

   .. image:: img/sec_inter.png

#. In the top navigation bar, click **View** -> **Files**.

   .. image:: img/th_files.png

#. Switch the path to the folder where you downloaded the `code package <https://codeload.github.com/sunfounder/universal-maker-sensor-kit/zip/refs/heads/main>`_ before, and then go to the ``universal-maker-sensor-kit-main/pico/libs`` folder.

   .. image:: img/th_path.png

#. Select all the files or folders in the "libs/" folder (by holding down Shift and clicking on the first and last file in the folder), then right-click and select **Upload to /**, it will take a while to upload.

   .. image:: img/th_upload.png

#. Now you will see the files you just uploaded inside your drive ``Raspberry Pi Pico``.

   .. image:: img/th_done.png