
 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson14_max30102:
Lektion 14: Pulsoximeter- und Herzfrequenzsensor-Modul (MAX30102)
========================================================================

In dieser Lektion lernen Sie, wie Sie den Raspberry Pi Pico W mit dem MAX30102-Pulsoximeter- und Herzfrequenzsensor verbinden. Sie erhalten Informationen zur Einrichtung der I2C-Kommunikation, zur Konfiguration des Sensors und zum Lesen von Rohdaten aus dem Sensor. Durch Beobachtung der Datenänderungen können Sie Informationen über den Herzschlag erhalten.

Erforderliche Komponenten
------------------------------

Für dieses Projekt benötigen wir folgende Komponenten. 

Es ist definitiv praktisch, ein ganzes Set zu kaufen. Hier ist der Link: 

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
    *   - :ref:`cpn_max30102`
        - |link_max30102_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_14_MAX30102_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from machine import SoftI2C, Pin
   from time import ticks_diff, ticks_us, sleep
   
   from max30102 import MAX30102, MAX30105_PULSE_AMP_MEDIUM
   
   
   def main():
       # I2C software instance
       i2c = SoftI2C(sda=Pin(20),  # Here, use your I2C SDA pin
                     scl=Pin(21),  # Here, use your I2C SCL pin
                     freq=400000)  # Fast: 400kHz, slow: 100kHz
   
       # Sensor instance
       sensor = MAX30102(i2c=i2c)  # An I2C instance is required
   
       # Scan I2C bus to ensure that the sensor is connected
       if sensor.i2c_address not in i2c.scan():
           print("Sensor not found.")
           return
       elif not (sensor.check_part_id()):
           # Check that the targeted sensor is compatible
           print("I2C device ID not corresponding to MAX30102 or MAX30105.")
           return
       else:
           print("Sensor connected and recognized.")
   
       # It's possible to set up the sensor at once with the setup_sensor() method.
       # If no parameters are supplied, the default config is loaded:
       # Led mode: 2 (RED + IR)
       # ADC range: 16384
       # Sample rate: 400 Hz
       # Led power: maximum (50.0mA - Presence detection of ~12 inch)
       # Averaged samples: 8
       # pulse width: 411
       print("Setting up sensor with default configuration.", '\n')
       sensor.setup_sensor()
   
       # It is also possible to tune the configuration parameters one by one.
       # Set the sample rate to 400: 400 samples/s are collected by the sensor
       sensor.set_sample_rate(400)
       # Set the number of samples to be averaged per each reading
       sensor.set_fifo_average(8)
       # Set LED brightness to a medium value
       sensor.set_active_leds_amplitude(MAX30105_PULSE_AMP_MEDIUM)
   
       sleep(1)
   
       # The readTemperature() method allows to extract the die temperature in °C    
       print("Reading temperature in °C.", '\n')
       print(sensor.read_temperature())
   
       print("Starting data acquisition from RED & IR registers...", '\n')
       sleep(1)
   
       while True:
           # The check() method has to be continuously polled, to check if
           # there are new readings into the sensor's FIFO queue. When new
           # readings are available, this function will put them into the storage.
           sensor.check()
   
           # Check if the storage contains available samples
           if sensor.available():
               # Access the storage FIFO and gather the readings (integers)
               red_reading = sensor.pop_red_from_storage()
               ir_reading = sensor.pop_ir_from_storage()
   
               # Print the acquired data (so that it can be plotted with a Serial Plotter)
               print("red_reading",red_reading, "ir_reading", ir_reading)
   
   if __name__ == '__main__':
       main()

Code-Analyse
---------------------------

#. Einrichten der I2C-Schnittstelle

   Die ``SoftI2C`` wird mit den SDA- und SCL-Pins initialisiert, und eine Frequenz von 400 kHz wird für die Kommunikation festgelegt.

   .. code-block:: python

      from machine import SoftI2C, Pin
      i2c = SoftI2C(sda=Pin(20), scl=Pin(21), freq=400000)

#. Initialisierung des Sensors

   Der MAX30102-Sensor wird unter Verwendung der I2C-Schnittstelle initialisiert.
   Es wird ein Scan des I2C-Busses durchgeführt, um sicherzustellen, dass der Sensor verbunden und erkannt wird.

   Weitere Informationen zur ``max30102``-Bibliothek finden Sie unter |link_micropython_max30102_driver|.

   .. code-block:: python

      from max30102 import MAX30102
      sensor = MAX30102(i2c=i2c)

#. Sensor-Konfiguration

   Der Sensor wird mit den Standardeinstellungen für LED-Modus, ADC-Bereich, Abtastrate, LED-Leistung, gemittelte Proben und Impulsbreite konfiguriert.
   Zusätzliche Konfigurationen wie Abtastrate, FIFO-Durchschnitt und LED-Amplitude werden festgelegt.

   .. code-block:: python

      sensor.setup_sensor()
      sensor.set_sample_rate(400)
      sensor.set_fifo_average(8)
      sensor.set_active_leds_amplitude(MAX30105_PULSE_AMP_MEDIUM)

#. Temperaturmessung

   Die Temperatur des Sensors wird ausgelesen und gedruckt.

   .. code-block:: python

      print(sensor.read_temperature())

#. Datenerfassung

   Eine Schleife wird eingerichtet, um kontinuierlich Daten vom Sensor zu erfassen.
   Die Methode ``check()`` wird abgefragt, um zu sehen, ob neue Messwerte verfügbar sind.
   Rote und IR-Messwerte werden aus dem Speicher des Sensors abgerufen und gedruckt.

   .. code-block:: python

      while True:
          sensor.check()
          if sensor.available():
              red_reading = sensor.pop_red_from_storage()
              ir_reading = sensor.pop_ir_from_storage()
              print("red_reading",red_reading, "ir_reading", ir_reading)

   Öffnen Sie den Plotter in Thonny, um die Herzfrequenzdaten zu beobachten.

   .. image:: img/Lesson_14_max30102_plotter.png
      :width: 60%
