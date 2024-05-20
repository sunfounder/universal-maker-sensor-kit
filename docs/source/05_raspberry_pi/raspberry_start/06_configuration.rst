.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

Configuring Your Raspberry Pi
=================================

.. _pi_enable_i2c:

I2C Configuration
-----------------------

To enable the I2C port on your Raspberry Pi, follow these steps (skip if already enabled; if unsure, proceed with the instructions).

1. Log into your Raspberry Pi, open the Terminal, and enter the command below to access the Raspberry Pi Software Configuration Tool. (You can also access the terminal using SSH.)

   .. code-block:: 

       sudo raspi-config

   .. image:: img/configuration_01.png
       :width: 100%

   .. raw:: html

       <br/><br/>

2. Go to **Interfacing options**.

   .. note::
      Use the ``up`` and ``down`` arrow keys to move the highlighted selection between the options available. Pressing the ``right`` arrow key will jump out of the Options menu and take you to the ``<Select>`` and ``<Finish>`` buttons. Pressing ``left`` will take you back to the options. Alternatively, you can use the ``Tab`` key to switch between these.

   .. image:: img/configuration_02.png
       :width: 100%

   .. raw:: html

       <br/><br/>

3. Select **I2C**.

   .. image:: img/configuration_03.png
       :width: 100%

   .. raw:: html

       <br/><br/>

4. Choose **<Yes>** to activate the I2C interface, then choose **<Ok>**.

   .. image:: img/configuration_04.png
       :width: 100%

   .. raw:: html

       <br/><br/>

5. Select **<Finish>** to exit the Raspberry Pi Software Configuration Tool.

   .. image:: img/configuration_05.png
       :width: 100%

   .. raw:: html

       <br/><br/>

6. Verify the address of the connected I2C device using the following command.

   .. code-block:: 

       i2cdetect -y 1      

   .. image:: img/configuration_06.png
       :width: 100%

   Addresses of any connected I2C devices will be shown.

   .. image:: img/configuration_07.png
       :width: 100%

   .. raw:: html

       <br/><br/>



.. _pi_enable_1wire:

1-Wire Configuration
-----------------------

To enable the 1-Wire port on your Raspberry Pi, follow these steps (skip if already enabled; if unsure, proceed with the instructions).


1. Log into your Raspberry Pi, open the Terminal, and enter this command to access the Raspberry Pi Software Configuration Tool. (You can also access the terminal using SSH.)

   .. code-block:: 

       sudo raspi-config

   .. image:: img/configuration_08.png
       :width: 100%

   .. raw:: html

       <br/><br/>

2. Go to **Interfacing options**.

   .. note::
      Use the ``up`` and ``down`` arrow keys to move the highlighted selection between the options available. Pressing the ``right`` arrow key will jump out of the Options menu and take you to the ``<Select>`` and ``<Finish>`` buttons. Pressing ``left`` will take you back to the options. Alternatively, you can use the ``Tab`` key to switch between these.

   .. image:: img/configuration_09.png
       :width: 100%

   .. raw:: html

       <br/><br/>

3. Select **1-Wire**.

   .. image:: img/configuration_10.png
       :width: 100%

   .. raw:: html

       <br/><br/>

4. Choose **<Yes>** to activate the 1-Wire interface, then choose **<Ok>**.

   .. image:: img/configuration_11.png
       :width: 100%

   .. raw:: html

       <br/><br/>

5. Select **<Finish>** to exit the Raspberry Pi Software Configuration Tool.

   .. image:: img/configuration_12.png
       :width: 100%

   .. raw:: html

       <br/><br/>

6. Select **<yes>** to reboot the Raspberry Pi.

   .. image:: img/configuration_13.png
       :width: 100%

   .. raw:: html

       <br/><br/>

