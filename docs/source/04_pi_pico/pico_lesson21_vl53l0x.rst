.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Lesson 21: Time-of-Flight-Mikro-LIDAR-Entfernungssensor (VL53L0X)
====================================================================

In diesem Unterricht lernen Sie, wie Sie den Raspberry Pi Pico W verwenden, um Entfernungen mit dem VL53L0X Time-of-Flight-Mikro-LIDAR-Entfernungssensor zu messen. Wir führen Sie durch die Einrichtung der I2C-Kommunikation zwischen dem Raspberry Pi Pico W und dem Sensor, und dann werden wir die Konfiguration der Sensoreinstellungen für optimale Leistung erkunden. Sie lernen auch, wie Sie das Messzeitbudget und die VCSEL-Pulsperioden anpassen, um Genauigkeit und Reichweite zu verbessern.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten:

Es ist definitiv bequem, ein ganzes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch separat über die folgenden Links kaufen.

.. list-table::
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_VL53L0X`
        - |link_vl53l0x_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verdrahtung
---------------------------

.. image:: img/Lesson_21_vl53l0x_bb.png
    :width: 100%


Code
---------------------------

.. note::

    * Öffnen Sie die Datei ``21_vl53l0x_module.py`` im Pfad ``universal-maker-sensor-kit-main/pico/Lesson_21_VL53L0X_Module`` oder kopieren Sie diesen Code in Thonny und klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie einfach F5, um es auszuführen. Für detaillierte Anleitungen lesen Sie bitte :ref:`open_run_code_py`.
    
    * Hier müssen Sie die Dateien ``vl53l0x.py`` verwenden. Bitte überprüfen Sie, ob sie auf dem Pico W hochgeladen wurden. Für eine detaillierte Anleitung siehe :ref:`add_libraries_py`.
    
    * Vergessen Sie nicht, auf den Interpreter "MicroPython (Raspberry Pi Pico)" in der unteren rechten Ecke zu klicken.

.. code-block:: python

   import time
   from machine import Pin, I2C
   from vl53l0x import VL53L0X
   
   print("setting up i2c")
   id = 0
   sda = Pin(20)
   scl = Pin(21)
   
   i2c = I2C(id=id, sda=sda, scl=scl)
   
   print(i2c.scan())
   
   # print("creating vl53lox object")
   # Create a VL53L0X object
   tof = VL53L0X(i2c)
   
   # Pre: 12 to 18 (initialized to 14 by default)
   # Final: 8 to 14 (initialized to 10 by default)
   
   # the measuting_timing_budget is a value in ms, the longer the budget, the more accurate the reading.
   budget = tof.measurement_timing_budget_us
   print("Budget was:", budget)
   tof.set_measurement_timing_budget(40000)
   
   # Sets the VCSEL (vertical cavity surface emitting laser) pulse period for the
   # given period type (VL53L0X::VcselPeriodPreRange or VL53L0X::VcselPeriodFinalRange)
   # to the given value (in PCLKs). Longer periods increase the potential range of the sensor.
   # Valid values are (even numbers only):
   
   # tof.set_Vcsel_pulse_period(tof.vcsel_period_type[0], 18)
   tof.set_Vcsel_pulse_period(tof.vcsel_period_type[0], 12)
   
   # tof.set_Vcsel_pulse_period(tof.vcsel_period_type[1], 14)
   tof.set_Vcsel_pulse_period(tof.vcsel_period_type[1], 8)
   
   while True:
       # Start ranging
       print(tof.ping() - 50, "mm")
   
       time.sleep_ms(100)  # Short delay of 0.1 seconds to reduce CPU usage


Codeanalyse
---------------------------

#. **Einrichten der I2C-Schnittstelle**:

   Der Code beginnt mit dem Importieren erforderlicher Module und der Initialisierung der I2C-Kommunikation. Das ``machine``-Modul wird verwendet, um I2C mit den richtigen Pins des Raspberry Pi Pico W einzurichten.

   Weitere Informationen über die ``vl53l0x``-Bibliothek finden Sie unter |link_micropython_vl53l0x_driver|.

   .. code-block:: python

      import time
      from machine import Pin, I2C
      from vl53l0x import VL53L0X

      print("setting up i2c")
      id = 0
      sda = Pin(20)
      scl = Pin(21)
      i2c = I2C(id=id, sda=sda, scl=scl)
      print(i2c.scan())

#. **Erstellen des VL53L0X-Objekts**:

   Es wird ein Objekt der Klasse ``VL53L0X`` erstellt. Dieses Objekt wird verwendet, um mit dem VL53L0X-Sensor zu interagieren.

   .. code-block:: python

      tof = VL53L0X(i2c)

#. **Konfiguration des Messzeitbudgets**:

   Das Messzeitbudget wird festgelegt. Dies bestimmt, wie lange der Sensor benötigt, um eine Messung durchzuführen. Ein längeres Zeitbudget ermöglicht genauere Messungen.

   .. code-block:: python

      budget = tof.measurement_timing_budget_us
      print("Budget was:", budget)
      tof.set_measurement_timing_budget(40000)

#. **Einstellen der VCSEL-Pulsperioden**:

   Hier werden die Pulsperioden für den VCSEL (Vertical Cavity Surface Emitting Laser) festgelegt. Dies beeinflusst die Reichweite und Genauigkeit des Sensors.

   .. code-block:: python

      tof.set_Vcsel_pulse_period(tof.vcsel_period_type[0], 12)
      tof.set_Vcsel_pulse_period(tof.vcsel_period_type[1], 8)

#. **Kontinuierliche Messschleife**:

   Der Sensor misst kontinuierlich die Entfernung und gibt sie aus. Die Methode ``ping()`` der Klasse ``VL53L0X`` wird verwendet, um die Entfernung in Millimetern zu erhalten. Eine kleine Verzögerung wird hinzugefügt, um die CPU-Auslastung zu reduzieren.

   .. code-block:: python

      while True:
          print(tof.ping() - 50, "mm")
          time.sleep_ms(100)