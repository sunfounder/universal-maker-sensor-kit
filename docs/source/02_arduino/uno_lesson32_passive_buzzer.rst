.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson32_passive_buzzer:

Lektion 32: Passiver Summer Modul
====================================

In dieser Lektion lernen Sie, wie Sie mit einem passiven Summer-Modul und Arduino eine Melodie abspielen. Wir werden das Programmieren des Arduinos zur Steuerung des Summers und zur Erstellung verschiedener Notenlängen abdecken. Dieses Projekt ist ideal für Anfänger, da es praktische Erfahrungen im Erzeugen von Klängen und im Verständnis von Musiknoten innerhalb elektronischer Komponenten bietet. Außerdem erhalten Sie praktische Einblicke in die Verwendung des Arduino Uno-Boards und des passiven Summer-Moduls.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch einzeln über die folgenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_module_buy|


Verkabelung
---------------------------

.. image:: img/Lesson_32_passive_buzzer_module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/eebc46ab-2a9d-4731-8778-3c8f07b0003b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

1. Einbinden der Pitches-Bibliothek:
   Diese Bibliothek stellt die Frequenzwerte für verschiedene Musiknoten bereit, sodass Sie musikalische Notation in Ihrem Code verwenden können.

   .. code-block:: arduino
       
      #include "pitches.h"

2. Definition von Konstanten und Arrays:

   * ``buzzerPin`` ist der digitale Pin am Arduino, an den der Summer angeschlossen ist.

   * ``melody[]`` ist ein Array, das die Sequenz der zu spielenden Noten speichert.

   * ``noteDurations[]`` ist ein Array, das die Dauer jeder Note in der Melodie speichert.

   .. raw:: html
      
      <br/>

   .. code-block:: arduino
   
      const int buzzerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };


3. Die Melodie abspielen:

   * Die ``for``-Schleife iteriert über jede Note in der Melodie.

   * Die Funktion ``tone()`` spielt eine Note auf dem Summer für eine bestimmte Dauer.

   * Eine Verzögerung wird zwischen den Noten hinzugefügt, um sie zu unterscheiden.

   * Die Funktion ``noTone()`` stoppt den Ton.

   .. raw:: html
      
      <br/>

   .. code-block:: arduino
   
      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(buzzerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(buzzerPin);
        }
      }

4. Leere Loop-Funktion:
   Da die Melodie nur einmal im Setup abgespielt wird, gibt es keinen Code in der Loop-Funktion.

