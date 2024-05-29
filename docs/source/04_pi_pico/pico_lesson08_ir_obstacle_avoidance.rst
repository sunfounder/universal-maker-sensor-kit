 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson08_ir_obstacle_avoidance:

Lektion 08: IR Hindernisvermeidungs-Sensor Modul
=====================================================

In dieser Lektion lernen Sie, wie Sie den Raspberry Pi Pico W mit einem IR-Hindernisvermeidungs-Sensor-Modul verwenden. Wir führen Sie durch die Einrichtung des Sensors und das Schreiben eines MicroPython-Skripts, das kontinuierlich dessen Wert liest, um Hindernisse zu erkennen. Durch die Überwachung von Änderungen der Sensordaten werden Sie verstehen, wie Sie ihn zur grundlegenden Hinderniserkennung verwenden können.

Erforderliche Komponenten
----------------------------

Für dieses Projekt benötigen wir folgende Komponenten:

Es ist auf jeden Fall praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

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
    *   - :ref:`cpn_ir_obstacle`
        - |link_obstacle_avoidance_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_08_Obstacle_Avoidance_Sensor_Module_bb.png
    :width: 100%

Code
---------------------------

.. code-block:: python

   from machine import Pin
   import time
   
   # Initialize obstacle avoidance sensor connected to pin 16 as input
   obstacle_avoidance_sensor = Pin(16, Pin.IN)
   
   while True:
       # Read and print the value of the obstacle avoidance sensor
       print(obstacle_avoidance_sensor.value())
   
       # Wait for 0.1 seconds before the next read
       time.sleep(0.1)


Code-Analyse
---------------------------

#. Importieren von Bibliotheken

   Das ``machine``-Modul wird importiert, um mit den GPIO-Pins zu interagieren, und das ``time``-Modul wird verwendet, um Verzögerungen hinzuzufügen.

   .. code-block:: python

      from machine import Pin
      import time

#. Einrichten des Sensors
   
   Der Hindernisvermeidungssensor wird als Eingabegerät am GPIO-Pin 16 konfiguriert. Der Parameter ``Pin.IN`` konfiguriert den Pin als Eingang.

   .. code-block:: python

      obstacle_avoidance_sensor = Pin(16, Pin.IN)

#. Lesen der Sensordaten in einer Schleife

   Die ``while True:``-Schleife überprüft kontinuierlich die Ausgabe des Sensors. Wenn der Sensor ein Hindernis erkennt, gibt er ``0`` zurück, was ausgegeben wird. Mit ``time.sleep(0.1)`` wird eine kleine Verzögerung hinzugefügt, um die Messungen handhabbarer zu machen.

   .. code-block:: python

      while True:
          print(obstacle_avoidance_sensor.value())
          time.sleep(0.1)

   .. note:: 
   
      Wenn der Sensor nicht ordnungsgemäß funktioniert, justieren Sie den IR-Sender und -Empfänger, um sie parallel zueinander auszurichten. Darüber hinaus können Sie den Erfassungsbereich mit dem eingebauten Potentiometer anpassen.

