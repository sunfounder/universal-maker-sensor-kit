.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _set_up_your_raspberry_pi:

Set up Your Raspberry Pi
============================

If You Have a Screen
-------------------------

If you have a screen, it will be easy for you to operate on the Raspberry Pi.

**Required Components**

* Any Raspberry Pi   
* 1 * Power Adapter
* 1 * Micro SD card
* 1 * Screen Power Adapter
* 1 * HDMI cable
* 1 * Screen
* 1 * Mouse
* 1 * Keyboard

#. Insert the SD card you’ve set up with Raspberry Pi OS into the micro SD card slot on the underside of your Raspberry Pi.

#. Plug in the Mouse and Keyboard.

#. Connect the screen to Raspberry Pi’s HDMI port and make sure your screen is plugged into a wall socket and switched on.

   .. note::
   
      If you use a Raspberry Pi 4, you need to connect the screen to the HDMI0 (nearest the power in port).

#. Use the power adapter to power the Raspberry Pi. After a few seconds, the Raspberry Pi OS desktop will be displayed.

   .. image:: img/set_up_01.png
       :align: center
   
   .. raw:: html
   
       <br/>

#. You can launch a web browser on your Raspberry Pi system and access this tutorial page. This makes it convenient to copy instructions and execute them in the Terminal.

   .. image:: img/set_up_02.png
       :align: center
   
.. raw:: html
   
   <br/>

.. _no_screen:

If You Have No Screen
--------------------------

If you don't have a monitor, you can remotely log into your Raspberry Pi.

**Required Components**

* Any Raspberry Pi   
* 1 * Power Adapter
* 1 * Micro SD card

You can use the SSH command to access the Raspberry Pi's Bash shell, which is Linux's default interface. The shell lets you perform most tasks with simple commands on Unix/Linux systems.

If you'd rather not use the command line for your Raspberry Pi, you can utilize the remote desktop feature to operate the Raspberry Pi's desktop environment without a dedicated screen.

See below for detailed tutorials for each system.


.. toctree::
   :maxdepth: 1

   03_a_remote_macosx
   03_b_remote_windows
   03_c_remote_linux

