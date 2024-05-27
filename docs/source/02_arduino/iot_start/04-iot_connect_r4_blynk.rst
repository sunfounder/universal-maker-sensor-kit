.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _connect_blynk:

1.4 Connecting the R4 board to Blynk
========================================

#. Reconnect the ESP8266 module and R4 board, here the software serial is used, so TX and RX are connected to pins 2 and 3 of R4 board respectively.

  .. note::

       The ESP8266 module requires a high current to provide a stable operating environment, so make sure the 9V battery is plugged in.

  .. image:: img/wiring_r4_quickstart.png

#. Open the ``00-Blynk_quick_start.ino`` file under the path of ``ultimate-sensor-kit\iot_project\wifi\00-Blynk_quick_start``. Or copy this code into **Arduino IDE**.

   .. raw:: html
       
       <iframe src=https://create.arduino.cc/editor/sunfounder01/421997b2-aaa7-45d7-926a-f0aec50db99a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Replace the following three lines of code that you can copy from your account's **Device info** page. These three lines of code will allow your R4 board to find your blynk account.

   .. code-block:: arduino

       #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
       #define BLYNK_DEVICE_NAME "Device"
       #define BLYNK_AUTH_TOKEN "YourAuthToken"
   
   .. image:: img/sp20220614174721.png

#. Fill in the ``ssid`` and ``password`` of the WiFi you are using.

   .. code-block:: arduino

       char ssid[] = "ssid";
       char pass[] = "password";

#. Upload the code to the R4 board, then open the serial monitor and set the baud rate to 115200. when the R4 board communicates with Blynk successfully, the serial monitor will show the ``ready`` character.

   .. image:: img/sp220607_170223.png

   .. note::
   
       If the message ``ESP is not responding`` appears when you connect, please follow these steps.

       * Make sure the 9V battery is plugged in.
       * Reset the ESP8266 module by connecting the pin RST to GND for 1 second, then unplug it.
       * Press the reset button on the R4 board.

       Sometimes, you may need to repeat the above operation 3-5 times, please be patient.

#. The status of Blynk will change from **offline** to **online**.

    .. image:: img/sp220607_170326.png
