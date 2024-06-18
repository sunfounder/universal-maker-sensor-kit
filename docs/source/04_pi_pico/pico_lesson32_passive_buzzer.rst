 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _pico_lesson32_passive_buzzer:

Lektion 32: Passives Summermodul
==================================

In dieser Lektion lernen Sie, wie Sie den passiven Summer auf dem Raspberry Pi Pico W verwenden, um einzelne Noten abzuspielen und Musik auszuführen. Sie erfahren, wie Sie PWM (Pulsweitenmodulation) verwenden, um den Summer am GPIO 16 einzurichten, und die Musikklasse in der Buzzer-Musik-Bibliothek, um vollständige Lieder abzuspielen. Dieser Kurs führt Sie Schritt für Schritt durch das Abspielen einzelner Noten und führt dann weitere vollständige Melodien wie "Happy Birthday" aus. Dieses Projekt ist sehr gut für Anfänger geeignet und bietet einen praktischen Weg, um Musiknoten zu verstehen und externe Bibliotheken in MicroPython auf dem Raspberry Pi Pico W zu integrieren.

Erforderliche Komponenten
--------------------------

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

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
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_32_Passive_buzzer_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine
   import time
   
   # Initialize the PWM on GPIO 16 for the buzzer
   buzzer = machine.PWM(machine.Pin(16))
   
   def tone(pin, frequency, duration):
       """Play a tone on the given pin at the specified frequency and duration."""
       pin.freq(frequency)
       pin.duty_u16(30000)
       time.sleep_ms(duration)
       pin.duty_u16(0)
   
   # Play individual notes
   tone(buzzer, 440, 250)  # A4
   time.sleep(0.5)
   tone(buzzer, 494, 250)  # B4
   time.sleep(0.5)
   tone(buzzer, 523, 250)  # C5
   time.sleep(1)
   
   
   
   # Import the music class from the buzzer_music module for easy song playback.
   from buzzer_music import music
   
   # Find some music on onlinesequencer.net, click edit, select all notes with CTRL + A and then copy them with CTRL + C
   # Paste the string to song, making sure to remove the "Online Sequencer:120233:" from the start and the ";:" from the end
   # https://onlinesequencer.net/2474257 Happy Birthday (by Sudirth)
   song = "0 G4 3 0;3 G4 1 0;4 A4 4 0;8 G4 4 0;12 C5 4 0;16 B4 8 0;24 G4 3 0;27 G4 1 0;28 A4 4 0;32 G4 4 0;36 D5 4 0;40 C5 8 0;48 G4 3 0;51 G4 1 0;52 G5 4 0;56 E5 4 0;60 C5 4 0;64 B4 4 0;68 A4 4 0;72 F5 3 0;75 F5 1 0;76 E5 4 0;80 C5 4 0;84 D5 4 0;88 C5 8 0"
   
   # Initialize the music class with the song and set the buzzer pin
   mySong = music(song, pins=[machine.Pin(16)])
   
   # Play music using the music class.
   while True:
       print(mySong.tick())
       time.sleep(0.04)



Code-Analyse
---------------------------

#. Initialisierung

   Importieren Sie die erforderlichen Module und initialisieren Sie die PWM an einem bestimmten GPIO-Pin, um den Summer zu steuern.

   .. code-block:: python

       import machine
       import time

       # Initialize the PWM on GPIO 16 for the buzzer
       buzzer = machine.PWM(machine.Pin(16))

#. Definition der Tonfunktion

   Diese Funktion ermöglicht das Abspielen einer einzelnen Note mit einer festgelegten Frequenz und Dauer. Sie legt die Frequenz und den Tastgrad (Lautstärke) des PWM-Signals fest.

   .. code-block:: python

       def tone(pin, frequency, duration):
           """Play a tone on the given pin at the specified frequency and duration."""
           pin.freq(frequency)
           pin.duty_u16(30000)
           time.sleep_ms(duration)
           pin.duty_u16(0)

#. Abspielen einzelner Noten

   Hier wird die Funktion "ton" verwendet, um einzelne Noten abzuspielen. Die Parameter umfassen die Frequenz der Note (in Hz) und ihre Dauer (in Millisekunden).

   .. code-block:: python

       # Play individual notes
       tone(buzzer, 440, 250)  # A4
       time.sleep(0.5)
       tone(buzzer, 494, 250)  # B4
       time.sleep(0.5)
       tone(buzzer, 523, 250)  # C5
       time.sleep(1)

#. Verwendung der Bibliothek "buzzer_music"

   Die Bibliothek ``buzzer_music`` wird importiert, und ein Lied-String wird vorbereitet.

   Sie können einige Musikstücke auf onlinesequencer.net finden, auf Bearbeiten klicken, alle Noten mit STRG + A auswählen und dann mit STRG + C kopieren. Fügen Sie den String in ``song`` ein und stellen Sie sicher, dass Sie "Online Sequencer:120233:" am Anfang und ";:" am Ende entfernen.

   Für weitere Informationen zur Bibliothek ``buzzer_music`` besuchen Sie bitte |link_buzzer_music|.

   .. code-block:: python

       # Import the music class from the buzzer_music module for easy song playback.
       from buzzer_music import music

       # https://onlinesequencer.net/2474257 Happy Birthday (by Sudirth)
       song = "0 G4 3 0;3 G4 1 0;4 A4 4 0;8 G4 4 0;12 C5 4 0;16 B4 8 0;24 G4 3 0;27 G4 1 0;28 A4 4 0;32 G4 4 0;36 D5 4 0;40 C5 8 0;48 G4 3 0;51 G4 1 0;52 G5 4 0;56 E5 4 0;60 C5 4 0;64 B4 4 0;68 A4 4 0;72 F5 3 0;75 F5 1 0;76 E5 4 0;80 C5 4 0;84 D5 4 0;88 C5 8 0"

#. Initialisierung und Abspielen des Liedes

   Die Klasse ``music`` wird mit dem Lied-String und dem GPIO-Pin für den Summer initialisiert. Die Musik wird in einer Schleife mit der Methode ``tick`` der Klasse ``music`` abgespielt.

   .. code-block:: python

       # Initialize the music class with the song and set the buzzer pin
       mySong = music(song, pins=[machine.Pin(16)])

       # Play music using the music class.
       while True:
           print(mySong.tick())
           time.sleep(0.04)
