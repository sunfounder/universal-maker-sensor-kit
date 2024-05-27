 .. _cpn_jdy31:.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！



JDY-31 Bluetooth Module
=====================================

.. image:: img/36_JDY31_1.jpg
    :align: center

.. warning::
  This module **does not support Apple device** connections, so tutorials involving this module require an Android phone or tablet.

The JDY-31 Bluetooth module is a pin-compatible replacement for the HC-06 Bluetooth module. It is simpler and easier to use than the HC-06 and is often available at a slightly lower cost. 

The JDY-31 Bluetooth module is based on Bluetooth 3.0 SPP design and can support Windows, Linux, and Android data transmission. The working frequency of the JDY-31 Bluetooth module is 2.4 GHz with modulation mode GFSK. The maximum transmission power is 8 dB, and the maximum transmission distance is 30 meters. Users can modify the device name through AT command, baud rate, and other instructions.

Pins of JDY-31 and their functions:

.. image:: img/36_JDY31_2.jpg
    :align: center


.. list-table:: JDY-31 Pins
   :widths: 25 25 100
   :header-rows: 1

   * - Pin	
     - Name	
     - Description
   * - 1	
     - STATE
     - Connection status pin (not connected low level, output high level after connectio) 
   * - 2	
     - RXD	
     - Receiver pin, this pin must connect to TX pin of next device.
   * - 3	
     - TXD
     - Transmitter pin, this pin must connect to RX pin of next device.
   * - 4		
     - GND
     - GND
   * - 5	
     - VCC
     - Power Supply(1.8-3.6V, 3.3v recommended)
   * - 6	
     - EN
     - enable or disable the module. When this pin is held high, the module is enabled and begins transmitting and receiving data.

patch application: general application only need to connect VCC, GND, RXD, TXD 4 pins, if you need to actively disconnect in the connection state, send AT+DISC in the connection state.

AT Command Set
---------------------------

+------------+-------------------------------------+-------------+
|   Command  |               Function              |   Default   |
+============+=====================================+=============+
| AT+VERSION | Version Number                      | JDY-31-V1.2 |
+------------+-------------------------------------+-------------+
| AT+RESET   | Soft reset                          |             |
+------------+-------------------------------------+-------------+
| AT+DISC    | Disconnect (valid when connected)   |             |
+------------+-------------------------------------+-------------+
| AT+LADDR   | Query the MAC address of the module |             |
+------------+-------------------------------------+-------------+
| AT+PIN     | Set or query connection password    | 1234        |
+------------+-------------------------------------+-------------+
| AT+BAUD    | Set or query baud rate              | 9600        |
+------------+-------------------------------------+-------------+
| AT+NAME    | Set or query broadcast name         | JDY-31-SPP  |
+------------+-------------------------------------+-------------+
| AT+DEFAULT | Factory reset                       |             |
+------------+-------------------------------------+-------------+
| AT+ENLOG   | Serial port status output           | 1           |
+------------+-------------------------------------+-------------+

Example
---------------------------
* :ref:`uno_lesson36_bluetooth` (Arduino UNO)
* :ref:`uno_bluetooth_lcd` (Arduino UNO)
* :ref:`uno_bluetooth_traffic_light` (Arduino UNO)