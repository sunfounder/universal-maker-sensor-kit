 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

 
Arduino Programmstruktur
===========================

Schauen wir uns die neue Sketch-Datei an. Obwohl sie nur wenige Zeilen Code enthält, ist es tatsächlich ein „leerer“ Sketch. 
Das Hochladen dieses Sketches auf das Entwicklungsboard führt dazu, dass nichts passiert.

.. code-block:: C

    void setup() {
    // Hier kommt Ihr Setup-Code hin, der einmal ausgeführt wird:

    }

    void loop() {
    // Hier kommt Ihr Hauptcode hin, der wiederholt ausgeführt wird:

    }

Wenn wir ``setup()`` und ``loop()`` entfernen und den Sketch zu einer echten ``blank`` Datei machen, werden Sie feststellen, dass er die Überprüfung nicht besteht. 
Sie sind das Äquivalent zum menschlichen Skelett und unverzichtbar.

Während des Sketchens wird zuerst ``setup()`` ausgeführt, und der Code darin (innerhalb von ``{}``) wird nach dem Einschalten oder Zurücksetzen des Boards einmal ausgeführt. 
``loop()`` wird verwendet, um die Hauptfunktion zu schreiben, und der Code darin wird in einer Schleife ausgeführt, nachdem ``setup()`` ausgeführt wurde.

Um setup() und loop() besser zu verstehen, verwenden wir vier Sketche. Ihr Zweck ist es, die On-Board-LED des Arduino zum Blinken zu bringen. Bitte führen Sie jedes Experiment nacheinander aus und notieren Sie deren spezifische Effekte.

* Sketch 1: Lässt die On-Board-LED kontinuierlich blinken.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // Hier kommt Ihr Setup-Code hin, der einmal ausgeführt wird:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // Hier kommt Ihr Hauptcode hin, der wiederholt ausgeführt wird:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Sketch 2: Lässt die On-Board-LED nur einmal blinken.

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // Hier kommt Ihr Setup-Code hin, der einmal ausgeführt wird:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // Hier kommt Ihr Hauptcode hin, der wiederholt ausgeführt wird:
    }

* Sketch 3: Lässt die On-Board-LED einmal langsam und dann schnell blinken.

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // Hier kommt Ihr Setup-Code hin, der einmal ausgeführt wird:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // Hier kommt Ihr Hauptcode hin, der wiederholt ausgeführt wird:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Sketch 4: Führt zu einem Fehler.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // Hier kommt Ihr Setup-Code hin, der einmal ausgeführt wird:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // Hier kommt Ihr Hauptcode hin, der wiederholt ausgeführt wird:
    }    

Mit Hilfe dieser Sketche können wir mehrere Merkmale von ``setup-loop`` zusammenfassen.

* ``loop()`` wird wiederholt ausgeführt, nachdem das Board eingeschaltet wurde.
* ``setup()`` wird nur einmal ausgeführt, nachdem das Board eingeschaltet wurde.
* Nach dem Einschalten des Boards wird zuerst ``setup()`` ausgeführt, gefolgt von ``loop()``.
* Der Code muss innerhalb des ``{}``-Bereichs von ``setup()`` oder ``loop()`` geschrieben werden, außerhalb des Rahmens führt zu einem Fehler.

.. note::  
    Anweisungen wie ``digitalWrite(13,HIGH)`` werden verwendet, um die On-Board-LED zu steuern. Wir werden ihre Verwendung in späteren Kapiteln ausführlich besprechen.

