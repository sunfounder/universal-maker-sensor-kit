.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _install_os:

Write Raspberry Pi OS to SD Card
========================================

**Step 1**

The Raspberry Pi team offers a user-friendly graphical SD card writing tool compatible with Mac OS, Ubuntu 18.04, and Windows. This is the most convenient option for most users, as it automatically downloads and installs the OS image to the SD card.

Visit the download page: https://www.raspberrypi.org/software/. Choose the **Raspberry Pi Imager** for your operating system. Once downloaded, open it to begin the installation.

.. image:: img/installing_01.png
    :align: center

.. raw:: html

    <br/>

**Step 2**

Upon launching the installer, your OS might prompt a security warning. For instance, Windows may show this message:

.. image:: img/installing_02.png
    :align: center

.. raw:: html

    <br/>

If you see this warning, click on **More info** and then choose **Run anyway**. Continue by following the instructions on your screen to complete the installation of the Raspberry Pi Imager.


**Step 3**

After installing the Imager, open the application by clicking the **Raspberry Pi Imager** icon or executing ``rpi-imager``.

.. image:: img/installing_03.png
    :align: center

.. raw:: html

    <br/>

**Step 4**

Click **Choose device** and select your Raspberry Pi model from the list.

.. image:: img/installing_04.png
    :align: center

.. raw:: html

    <br/>

**Step 5**

Next, click **Choose OS** and pick an operating system to install. 

.. image:: img/installing_05.png
    :align: center

.. raw:: html

    <br/>

**Step 6**

Insert your preferred storage medium, such as a microSD card, into an external or integrated SD card reader. Next, click "Choose Storage" and select your device.

.. note:: 

   **Ensure you select the correct storage device when multiple devices are connected**; they can often be distinguished by their capacity. If uncertain, disconnect the other devices. **Be aware that installing the system on the chosen storage device will erase all data on it.**

.. image:: img/installing_06.png
    :align: center

.. raw:: html

    <br/>

**Step 7**

Press the **NEXT** button and choose **EDIT SETTINGS** to access the OS Customization page.

.. image:: img/installing_07.png
    :align: center

.. raw:: html

    <br/>

**Step 8**

Set the **hostname**.

.. note::

   The hostname option defines the hostname your Raspberry Pi broadcasts to the network using mDNS. By connecting your Raspberry Pi to the network, it allows other devices to interact with it using ``<hostname>.local`` or ``<hostname>.lan``.

.. image:: img/installing_08.png
    :align: center

.. raw:: html

    <br/>

Set the **username** and **password** for the Raspberry Pi's administrator account.

.. note::
   The Raspberry Pi does not come with a default password, making it crucial to set one. Additionally, you have the option to personalize the username.

.. image:: img/installing_09.png
    :align: center

.. raw:: html

    <br/>

Configure wireless LAN by entering your network's **SSID** and **password**.

.. note::

   Configure the "Wireless LAN country" using your nation's two-letter |link_alpha2_code|.

.. image:: img/installing_10.png
    :align: center

.. raw:: html

    <br/>

**Step 9**

Navigate to the **SERVICES** page, choose **Enable SSH option** to turn on SSH, and select “Use password authentication” (recommended for beginners). Click **Save** to apply your changes.

.. image:: img/installing_11.png
    :align: center

.. raw:: html

    <br/>

**Step 10**

Click the **Yes** button.

.. image:: img/installing_12.png
    :align: center

.. raw:: html

    <br/>

**Step 11**

If your SD card contains files, consider backing them up to avoid permanent loss. If no backup is needed, click **Yes**.

.. image:: img/installing_13.png
    :align: center

.. raw:: html

    <br/>

**Step 12**

The window below will appear once the writing process is complete. Writing process takes some time and varies based on the SD card's read-write performance; please be patient.

.. image:: img/installing_14.png
    :align: center

.. raw:: html

    <br/>

