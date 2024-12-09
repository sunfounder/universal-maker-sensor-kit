.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pi_lesson19_dht11:

Lektion 19: Temperatur- und Feuchtigkeitssensor-Modul (DHT11)
====================================================================

In dieser Lektion lernen Sie, wie Sie einen DHT11 Temperatur- und Feuchtigkeitssensor mit einem Raspberry Pi verbinden und Daten auslesen. Sie lernen, wie Sie den Sensor einrichten, die Temperatur in Celsius und Fahrenheit auslesen und Feuchtigkeitswerte erhalten. Dieses Projekt führt Sie in die Arbeit mit externen Sensoren, die Handhabung von Echtzeitdaten und grundlegendes Exception-Handling in Python ein.

Erforderliche Komponenten
--------------------------

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_humiture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verkabelung
---------------------------

.. note:: 
   Das Kit kann unterschiedliche Versionen des DHT11-Moduls enthalten. Bitte überprüfen Sie die Verdrahtungsmethode entsprechend dem Modul, das Sie haben.

.. image:: img/Lesson_19_dht11_module_pi_bb_bb.png
    :width: 100%

.. image:: img/Lesson_19_dht11_module_pi_new_bb.png
    :width: 100%

Bibliothek installieren
---------------------------

.. note::
    Die adafruit-circuitpython-dht-Bibliothek hängt von Blinka ab, stellen Sie also sicher, dass Blinka installiert ist. Um Bibliotheken zu installieren, siehe :ref:`install_blinka`.

Bevor Sie die Bibliothek installieren, stellen Sie bitte sicher, dass die virtuelle Python-Umgebung aktiviert ist:

.. code-block:: bash

   source ~/env/bin/activate

Installieren Sie die adafruit-circuitpython-dht-Bibliothek:

.. code-block:: bash

   pip install adafruit-circuitpython-dht

Code
---------------------------

.. note::
   - Stellen Sie sicher, dass Sie die Python-Bibliothek installiert haben, die für die Ausführung des Codes gemäß den Schritten in "Bibliothek installieren" erforderlich ist.
   - Bevor Sie den Code ausführen, stellen Sie bitte sicher, dass die virtuelle Python-Umgebung mit installiertem Blinka aktiviert ist. Sie können die virtuelle Umgebung mit einem Befehl wie diesem aktivieren:

     .. code-block:: bash
  
        source ~/env/bin/activate

   - Finden Sie den Code für diese Lektion im Verzeichnis ``universal-maker-sensor-kit-main/pi/`` oder kopieren Sie den unten stehenden Code direkt und führen Sie ihn mit den folgenden Befehlen im Terminal aus:

     .. code-block:: bash
  
        python 19_dht11_module.py


.. code-block:: python

   import time
   import board
   import adafruit_dht
   
   # Initial the dht device, with data pin connected to:
   dhtDevice = adafruit_dht.DHT11(board.D17)
   
   while True:
       try:
           # Print the values to the serial port
           temperature_c = dhtDevice.temperature
           temperature_f = temperature_c * (9 / 5) + 32
           humidity = dhtDevice.humidity
           print(
               "Temp: {:.1f} F / {:.1f} C    Humidity: {}% ".format(
                   temperature_f, temperature_c, humidity
               )
           )
   
       except RuntimeError as error:
           # Errors happen fairly often, DHT's are hard to read, just keep going
           print(error.args[0])
           time.sleep(2.0)
           continue
       except Exception as error:
           dhtDevice.exit()
           raise error
   
       time.sleep(2.0)

Code-Analyse
---------------------------

#. Bibliotheken importieren:

   Der Code beginnt mit dem Import der notwendigen Bibliotheken: ``time`` für die Verwaltung von Verzögerungen, ``board`` für den Zugriff auf die GPIO-Pins des Raspberry Pi und ``adafruit_dht`` für die Interaktion mit dem DHT11-Sensor. Weitere Details zur ``adafruit_dht``-Bibliothek finden Sie unter |Adafruit_CircuitPython_DHT|.

   .. code-block:: python
    
      import time
      import board
      import adafruit_dht

#. Initialisierung des Sensors:

   Der DHT11-Sensor wird mit dem Datenpin an GPIO 17 des Raspberry Pi initialisiert. Diese Konfiguration ist entscheidend, damit der Sensor mit dem Raspberry Pi kommunizieren kann.

   .. code-block:: python

      dhtDevice = adafruit_dht.DHT11(board.D17)

#. Lesen der Sensordaten in einer Schleife:

   Die ``while True``-Schleife ermöglicht es dem Programm, kontinuierlich nach neuen Daten vom Sensor zu prüfen.

   .. code-block:: python

      while True:

#. Try-Except-Blöcke:

   Innerhalb der Schleife wird ein Try-Except-Block verwendet, um potenzielle Laufzeitfehler zu behandeln. Das Lesen von DHT-Sensoren kann oft zu Fehlern führen, die auf Timing-Probleme oder Sensoreigenheiten zurückzuführen sind.

   .. code-block:: python

      try:
          # Sensor data reading code here
      except RuntimeError as error:
          # Handling common sensor reading errors
          print(error.args[0])
          time.sleep(2.0)
          continue
      except Exception as error:
          # Handling other exceptions and exiting
          dhtDevice.exit()
          raise error

#. Lesen und Ausgeben der Sensordaten:

   Die Temperatur und die Luftfeuchtigkeit werden vom Sensor ausgelesen und in ein menschenlesbares Format umgewandelt. Die Temperatur wird auch von Celsius in Fahrenheit umgerechnet.

   .. code-block:: python

      temperature_c = dhtDevice.temperature
      temperature_f = temperature_c * (9 / 5) + 32
      humidity = dhtDevice.humidity
      print("Temp: {:.1f} F / {:.1f} C    Humidity: {}% ".format(temperature_f, temperature_c, humidity))

#. Behandeln von Lesefehlern:

   Der DHT11-Sensor kann oft Fehler zurückgeben, daher verwendet der Code einen Try-Except-Block, um diese zu behandeln. Wenn ein Fehler auftritt, wartet das Programm 2 Sekunden, bevor es erneut versucht, vom Sensor zu lesen.

   .. code-block:: python

      except RuntimeError as error:
          print(error.args[0])
          time.sleep(2.0)
          continue

#. Allgemeine Ausnahmebehandlung:

   Andere auftretende Ausnahmen werden behandelt, indem der Sensor sicher beendet und der Fehler erneut ausgelöst wird. Dies stellt sicher, dass das Programm nicht in einem instabilen Zustand weiterläuft.

   .. code-block:: python

      except Exception as error:
          dhtDevice.exit()
          raise error

#. Verzögerung zwischen den Messungen:

   Am Ende der Schleife wird eine Verzögerung von 2 Sekunden hinzugefügt, um ein ständiges Abfragen des Sensors zu vermeiden, was zu fehlerhaften Messwerten führen kann.

   .. code-block:: python

      time.sleep(2.0)