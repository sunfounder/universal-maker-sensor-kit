 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson21_vl53l0x:

Lektion 21: Time-of-Flight Micro-LIDAR Entfernungssensor (VL53L0X)
======================================================================

In dieser Lektion lernen Sie, wie Sie den Raspberry Pi verwenden, um einen Time-of-Flight Micro-LIDAR Entfernungssensor (VL53L0X) anzuschließen. Sie werden durch die Einrichtung des Sensors, die Initialisierung der I2C-Kommunikation und die Echtzeitmessung von Entfernungen geführt. Dieses Projekt verbessert Ihr Verständnis für die Verbindung von Hardware mit dem Raspberry Pi und die Nutzung von Python für praktische Anwendungen. Zusätzlich werden Sie lernen, Messparameter anzupassen, um unterschiedliche Anforderungen an Genauigkeit und Geschwindigkeit zu erfüllen.

Erforderliche Komponenten
-----------------------------

In diesem Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_VL53L0X`
        - |link_vl53l0x_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verkabelung
---------------------------

.. image:: img/Lesson_21_vl53l0x_pi_bb.png
    :width: 100%

Bibliothek installieren
---------------------------

.. note::
    Die adafruit-circuitpython-vl53l0x-Bibliothek hängt von Blinka ab, stellen Sie also sicher, dass Blinka installiert ist. Um Bibliotheken zu installieren, siehe :ref:`install_blinka`.

Bevor Sie die Bibliothek installieren, stellen Sie bitte sicher, dass die virtuelle Python-Umgebung aktiviert ist:

.. code-block:: bash

   source ~/env/bin/activate

Installieren Sie die adafruit-circuitpython-vl53l0x-Bibliothek:

.. code-block:: bash

   pip3 install adafruit-circuitpython-vl53l0x

Code
---------------------------

.. note::
   - Stellen Sie sicher, dass die Python-Bibliothek gemäß den Schritten in "Bibliothek installieren" installiert ist.
   - Bevor Sie den Code ausführen, aktivieren Sie bitte die virtuelle Python-Umgebung mit installiertem Blinka. Sie können die virtuelle Umgebung mit folgendem Befehl aktivieren:

     .. code-block:: bash
  
        source ~/env/bin/activate

   - Sie finden den Code für diese Lektion im Verzeichnis ``universal-maker-sensor-kit-main/pi/`` oder kopieren Sie den untenstehenden Code direkt und führen Sie ihn im Terminal mit folgenden Befehlen aus:

     .. code-block:: bash
  
        python 21_vl53l0x_module.py


.. code-block:: python

   # SPDX-FileCopyrightText: 2021 ladyada for Adafruit Industries
   # SPDX-License-Identifier: MIT
   
   # Simple demo of the VL53L0X distance sensor.
   # Will print the sensed range/distance every second.
   import time
   
   import board
   import busio
   
   import adafruit_vl53l0x
   
   # Initialize I2C bus and sensor.
   i2c = busio.I2C(board.SCL, board.SDA)
   vl53 = adafruit_vl53l0x.VL53L0X(i2c)
   
   # Optionally adjust the measurement timing budget to change speed and accuracy.
   # See the example here for more details:
   #   https://github.com/pololu/vl53l0x-arduino/blob/master/examples/Single/Single.ino
   # For example a higher speed but less accurate timing budget of 20ms:
   # vl53.measurement_timing_budget = 20000
   # Or a slower but more accurate timing budget of 200ms:
   # vl53.measurement_timing_budget = 200000
   # The default timing budget is 33ms, a good compromise of speed and accuracy.
   
   try:
       # Main loop will read the range and print it every second.
       while True:
           print("Range: {0}mm".format(vl53.range))
           time.sleep(1.0)
   except KeyboardInterrupt:
       print("Exit")  # Exit on CTRL+C

Code-Analyse
---------------------------

#. **Bibliotheken importieren**

   .. code-block:: python
   
       import time
       import board
       import busio
       import adafruit_vl53l0x

   - ``time``: Wird für die Implementierung von Verzögerungen verwendet.
   - ``board``: Bietet Zugriff auf die physischen Pins des Raspberry Pi.
   - ``busio``: Verwalten die I2C-Kommunikation zwischen dem Pi und dem Sensor.
   - ``adafruit_vl53l0x``: Die spezifische Bibliothek für den VL53L0X-Sensor. Weitere Informationen zur ``adafruit_vl53l0x``-Bibliothek finden Sie unter |link_Adafruit_CircuitPython_VL53L0X|.

   .. raw:: html
      
      <br/>

#. **Sensor initialisieren**

   .. code-block:: python
   
       # Initialize I2C bus and sensor.
       i2c = busio.I2C(board.SCL, board.SDA)
       vl53 = adafruit_vl53l0x.VL53L0X(i2c)

   - Dies richtet die I2C-Kommunikation über die SCL (Taktleitung) und SDA (Datenleitung) Pins ein.
   - Der VL53L0X-Sensor wird dann mit diesem I2C-Bus initialisiert.

   .. raw:: html
      
      <br/>

#. **Konfiguration (Optional)**

   .. code-block:: python
   
       # Optionally adjust the measurement timing budget...
       # vl53.measurement_timing_budget = 20000
       # ...

   Dieser Teil des Codes, der auskommentiert ist, ermöglicht die Anpassung des Messzeitbudgets des Sensors, was das Gleichgewicht zwischen Geschwindigkeit und Genauigkeit beeinflusst.

#. **Hauptschleife**

   .. code-block:: python
      
       try:
           while True:
               print("Range: {0}mm".format(vl53.range))
               time.sleep(1.0)
       except KeyboardInterrupt:
           print("Exit")
- In an infinite loop, the sensor's range is read and printed every second.
   - The loop can be exited with a CTRL+C interrupt, which is handled by the KeyboardInterrupt exception.