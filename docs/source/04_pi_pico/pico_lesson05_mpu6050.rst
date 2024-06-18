.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson05_mpu6050:

Lektion 05: Gyroskop- & Beschleunigungsmesser-Modul (MPU6050)
=============================================================================

In dieser Lektion lernen Sie, wie Sie den Raspberry Pi Pico W mit dem MPU6050-Modul verwenden, das ein Gyroskop und einen Beschleunigungsmesser kombiniert. Sie werden erfahren, wie Sie das MPU6050 mit dem Raspberry Pi Pico W verbinden und seine Beschleunigungs- und gyroskopischen Daten unter Verwendung von MicroPython lesen. Die Lektion wird Sie durch das Schreiben eines Skripts führen, um kontinuierlich die X-, Y- und Z-Werte sowohl des Beschleunigungsmessers als auch des Gyroskops anzuzeigen.

Erforderliche Komponenten
--------------------------------

Für dieses Projekt benötigen wir folgende Komponenten.

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

Sie können sie auch separat von den folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_mpu6050`
        - |link_mpu6050_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_05_mpu6050_circuit_bb.png
    :width: 100%


Code
---------------------------

.. note::

    * Öffnen Sie die Datei ``05_mpu6050_module.py`` im Pfad ``universal-maker-sensor-kit-main/pico/Lesson_05_MPU6050_Module`` oder kopieren Sie diesen Code in Thonny und klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie einfach F5, um es auszuführen. Für detaillierte Anleitungen lesen Sie bitte :ref:`open_run_code_py`.
    
    * Hier müssen Sie die Dateien ``imu.py`` und ``vector3d.py`` verwenden. Bitte überprüfen Sie, ob sie auf dem Pico W hochgeladen wurden. Für eine detaillierte Anleitung siehe :ref:`add_libraries_py`.
    
    * Vergessen Sie nicht, auf den Interpreter "MicroPython (Raspberry Pi Pico)" in der unteren rechten Ecke zu klicken.

.. code-block:: python

   # Import libraries
   from imu import MPU6050
   from machine import I2C, Pin
   import time
   
   # Initialize I2C for MPU6050
   i2c = I2C(1, sda=Pin(20), scl=Pin(21), freq=400000)  # I2C bus 1, SDA pin 20, SCL pin 21, 400kHz
   
   # Create MPU6050 object
   mpu = MPU6050(i2c)
   
   # Main loop to read and print sensor data
   while True:
       # Print accelerometer data (x, y, z)
       print("-" * 50)
       print("x: %s, y: %s, z: %s" % (mpu.accel.x, mpu.accel.y, mpu.accel.z))
       time.sleep(0.1)
       
       # Print gyroscope data (x, y, z)
       print("X: %s, Y: %s, Y: %s" % (mpu.gyro.x, mpu.gyro.y, mpu.gyro.z))
       time.sleep(0.1)
       
       # Delay between readings
       time.sleep(0.5)

Codeanalyse
---------------------------

#. Bibliotheken importieren und I2C initialisieren

   Der Code beginnt mit dem Importieren der benötigten Bibliotheken. Die ``imu``-Bibliothek wird verwendet, um die Werte des MPU6050-Sensors zu lesen, und ``machine`` ermöglicht die Steuerung der Hardwarefunktionen des Raspberry Pi Pico W. I2C wird unter Verwendung spezifischer Pins (SDA und SCL) für die Datenkommunikation initialisiert.

   Weitere Informationen zur ``imu``-Bibliothek finden Sie unter |link_imu|.

   .. code-block:: python

      from imu import MPU6050
      from machine import I2C, Pin
      import time

      i2c = I2C(1, sda=Pin(20), scl=Pin(21), freq=400000)

#. Erstellen des MPU6050-Objekts

   Ein Objekt des MPU6050-Sensors wird erstellt, indem das initialisierte I2C übergeben wird. Dieses Objekt wird verwendet, um auf Sensordaten zuzugreifen.

   .. code-block:: python

      mpu = MPU6050(i2c)

#. Lesen und Drucken der Sensordaten in einer Schleife

   Der Code tritt dann in eine Endlosschleife ein, in der er kontinuierlich die Beschleunigungsmesser- und Gyroskopdaten liest und druckt. ``time.sleep`` wird verwendet, um eine Verzögerung zwischen aufeinanderfolgenden Messungen zu erzeugen.

   .. code-block:: python

      while True:
          print("-" * 50)
          print("x: %s, y: %s, z: %s" % (mpu.accel.x, mpu.accel.y, mpu.accel.z))
          time.sleep(0.1)
          print("X: %s, Y: %s, Y: %s" % (mpu.gyro.x, mpu.gyro.y, mpu.gyro.z))
          time.sleep(0.1)
          time.sleep(0.5)