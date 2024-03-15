.. _esp32_iot_bluetooth_app:

Lesson 50: Android Application - RGB LED Operation via Arduino and Bluetooth
==================================================================================

The objective of this project is to develop an Android application capable of manipulating the hue of an RGB LED through a smartphone using Bluetooth technology.

This Android application will be constructed utilizing a complimentary web-based platform known as MIT App Inventor 2. The project presents an excellent opportunity to gain familiarity with the interfacing of an Arduino with a smartphone.


**Required Components**

In this project, we need the following components. 


.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 Development Board
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_rgb`
        - \-

**1. Creation of the Android Application**

The Android application will be fashioned using a free web application known as |link_appinventor|. 
MIT App Inventor serves as an excellent starting point for Android development, owing to its intuitive drag-and-drop 
features allowing for the creation of simplistic applications.

Now, let's begin.

#. Here is the login page: http://ai2.appinventor.mit.edu. You will require a Google account to register with MIT App Inventor.

#. After logging in, navigate to **Projects** -> **Import project (.aia) from my computer**. Subsequently, upload the ``control_rgb_led.aia`` file located in the path ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor``.

   .. image:: img/10_ble_app_inventor1.png

#. Upon uploading the ``.aia`` file, you will see the application on the **MIT App Inventor** software. This is a pre-configured template. You can modify this template after you have familiarized yourself with **MIT App Inventor** through the following steps.

   .. image:: img/10_ble_app_inventor2.png

#. In **MIT App Inventor**, you have 2 primary sections: the **Designer** and the **Blocks**.

   .. image:: img/10_ble_app_inventor3.png

#. The **Designer** allows you to add buttons, text, screens, and modify the overall aesthetic of your application.

   .. image:: img/10_ble_app_inventor2.png
   

#. Subsequently, you have the **Blocks** section. The **Blocks** section facilitates the creation of bespoke functions for your application.

   .. image:: img/10_ble_app_inventor5.png

#. To install the application on a smartphone, navigate to the **Build** tab.

   .. image:: img/10_ble_app_inventor6.png

   * You can generate a ``.apk`` file. After selecting this option, a page will appear allowing you to choose between downloading a ``.apk`` file or scanning a QR code for installation. Follow the installation guide to complete the application installation.
   * If you wish to upload this app to **Google Play** or another app marketplace, you can generate a ``.aab`` file.


**2. Upload the code**

#. Build the circuit.

   .. image:: img/Lesson_28_RGB_LED_Module_esp32_bb.png

#. Subsequently, connect the ESP32 to your computer using a USB cable.


#. Open the ``Lesson_50_Bluetooth_app_inventor.ino`` file situated in the ``universal-maker-sensor-kit\esp32\Lesson_50_Bluetooth_app_inventor`` directory, or copy the code into the Arduino IDE.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/07622bb5-31eb-4a89-b6f2-085f3332051f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>





#. Upon selecting the appropriate board (**ESP32 Dev Module**) and port, click the **Upload** button.

**3. App and ESP32 Connection**

Ensure that the application created earlier is installed on your smartphone.

#. Initially, activate **Bluetooth** on your smartphone.

   .. image:: img/10_ble_mobile1.png
      :width: 500
      :align: center

#. Navigate to the **Bluetooth settings** on your smartphone and find **ESP32RGB**.

   .. image:: img/10_ble_mobile2.png
      :width: 500
      :align: center


#. After clicking it, agree to the **Pair** request in the pop-up window.

   .. image:: img/10_ble_mobile3.png
      :width: 500
      :align: center

#. Now open the recently installed **Control_RGB_LED** APP.

   .. image:: img/10_ble_mobile4.png
      :align: center

#. In the APP, click on **Connect Bluetooth** to establish a connection between the APP and ESP32.

   .. image:: img/10_ble_mobile5.png
      :width: 500
      :align: center

#. Select the ``xx.xx.xx.xx.xx.xx ESP32RGB`` that comes up. if you changed ``SerialBT.begin("ESP32RGB");`` in the code, then just select the name of your setting.

   .. image:: img/10_ble_mobile6.png
      :width: 500
      :align: center

#. If you have been waiting for a while and still can't see any device names, it may be that this APP is not allowed to scan surrounding devices. In this case, you need to adjust the settings manually.

   * Long press the APP icon and click on the resulting **APP Info**. If you have another method to access this page, follow that.

      .. image:: img/10_ble_mobile8.png
         :width: 500
         :align: center

   * Navigate to the **Permissions** page.

      .. image:: img/10_ble_mobile9.png
         :width: 500
         :align: center

   * Locate **Nearby devices**, and select **Always** to allow this APP to scan for nearby devices.

      .. image:: img/10_ble_mobile10.png
         :width: 500
         :align: center

   * Now, restart the APP and repeat steps 5 and 6 to successfully connect to Bluetooth.

#. Upon successful connection, you will automatically return to the main page, where it will display connected. Now you can adjust the RGB values and change the color of the RGB display by pressing the **Change Color** button.

   .. image:: img/10_ble_mobile7.png
      :width: 500
      :align: center
