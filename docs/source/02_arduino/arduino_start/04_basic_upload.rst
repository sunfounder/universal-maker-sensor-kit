.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

How to upload Sketch to the Board?
=============================================

In this section, you will learn how to upload the sketch created previously to the Arduino board, as well as learn about some considerations.

**1. Choose Board and port**

Arduino development boards usually come with a USB cable. You can use it to connect the board to your computer.

Select the correct **Board** and **Port** in the Arduino IDE. Normally, Arduino boards are recognized automatically by the computer and assigned a port, so you can select it here.

    .. image:: img/board_port.png
        :width: 90%


If your board is already plugged in, but not recognized, check if the **INSTALLED** logo appears in the **Arduino AVR Boards** section of the **Boards Manager**, if not, please scroll down a bit and click on **INSTALL**.

    .. image:: img/upload1.png
        :width: 90%

Specifically, for UNO R4, search **"UNO R4"** in **Boards Manager** and check if the corresponding library is installed.

    .. image:: img/install_uno_r4_lib.png
        :width: 90%

Reopening the Arduino IDE and re-plugging the Arduino board will fix most of the problems. You can also click **Tools** -> **Board** or **Port** to select them.


**2. Verify the Sketch**

After clicking the Verify button, the sketch will be compiled to see if there are any errors.

    .. image:: img/sp221014_174532.png
        :width: 90%

You can use it to find mistakes if you delete some characters or type a few letters by mistake. From the message bar, you can see where and what type of errors occurred. 

    .. image:: img/sp221014_175307.png
        :width: 90%

If there are no errors, you will see a message like the one below.

    .. image:: img/sp221014_175512.png
        :width: 90%


**3. Upload sketch**

After completing the above steps, click the **Upload** button to upload this sketch to the board.

    .. image:: img/sp221014_175614.png
        :width: 90%

If successful, you will be able to see the following prompt.

    .. image:: img/sp221014_175654.png
        :width: 90%

At the same time, the on-board LED blink.

.. image:: img/1_led.jpg
    :width: 400
    :align: center

.. raw:: html
    
    <br/>

The Arduino board will automatically run the sketch after power is applied after the sketch is uploaded. The running program can be overwritten by uploading a new sketch.




