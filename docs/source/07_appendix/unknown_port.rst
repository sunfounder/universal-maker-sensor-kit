.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _unknown_com_port:

Always displaying "Unknown COMxx"?
======================================

When plugging the ESP32 into the computer, the Arduino IDE often displays ``Unknown COMxx``. Why does this happen?

.. image:: img/unknown_device.png

This is because the USB driver for ESP32 is different from the regular Arduino Boards. The Arduino IDE can't automatically recognize this board. 

In such a scenario, you need to manually select the correct board by following these steps:

#. Click on **"Select the other board and port"**.

    .. image:: img/unknown_select.png

#. In the search, type **"esp32 dev module"**, then select the board that appears. Afterward, select the correct port and click **OK**.

    .. image:: img/unknown_board.png

#. Now, you should be able to see your board and port in this quick view window.

    .. image:: img/unknown_correct.png