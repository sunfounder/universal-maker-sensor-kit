.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

Install the ESP32 Board(Important)
===========================================

To program the ESP32 microcontroller, we need to install the ESP32 board package in the Arduino IDE. Follow the step-by-step guide below:

**Install the ESP32 Board**

#. Open the Arduino IDE. Go to **File** and select **Preferences** from the drop-down menu.

   .. image:: img/install_esp32_1.png

#. In the Preferences window, locate the **Additional Board Manager URLs** field. Click on it to activate the text box.

   .. image:: img/install_esp32_2.png

#. Add the following URL to the **Additional Board Manager URLs** field: https://espressif.github.io/arduino-esp32/package_esp32_index.json. This URL points to the package index file for the ESP32 boards. Click the **OK** button to save the changes.

   .. image:: img/install_esp32_3.png

#. In the **Boards Manager** window, type **ESP32** in the search bar. Click the **Install** button to start the installation process. This will download and install the ESP32 board package.

   .. image:: img/install_esp32_4.png

#. Congratulations! You have successfully installed the ESP32 board package in the Arduino IDE. 

**Upload the Code**

#. Now, connect the ESP32 WROOM 32E to your computer using a Micro USB cable. 

   .. image:: img/plugin_esp32.png
       :width: 80%
       :align: center

#. Then select the correct board, **ESP32 Dev Module**, by clicking on **Tools** -> **Board** -> **esp32**.

   .. image:: img/install_esp32_5.png
      :width: 100%

#. If your ESP32 is connected to the computer, you can choose the correct port by clicking on **Tools** -> **Port**.

   .. image:: img/install_esp32_6.png
      :width: 100%

#. Additionally, Arduino 2.0 introduced a new way to quickly select the board and port. For ESP32, it is usually not automatically recognized, so you need to click on **Select other board and port**.

   .. image:: img/install_esp32_7.png
      :width: 80%

#. In the search box, type **ESP32 Dev Module** and select it when it appears. Then, choose the correct port and click **OK**.

   .. image:: img/install_esp32_8.png
      :width: 90%

#. Afterward, you can select it through this quick access window. Note that during subsequent use, there may be times when ESP32 is not available in the quick access window, and you will need to repeat the above two steps.

   .. image:: img/install_esp32_9.png
      :width: 80%

#. Both methods allow you to select the correct board and port, so choose the one that suits you best. Now, everything is ready to upload the code to the ESP32.




