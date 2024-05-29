 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Schreibregeln für Sketche
================================


Wenn Sie einen Freund bitten, das Licht für Sie einzuschalten, können Sie sagen: "Mach das Licht an.", oder "Licht an, Kumpel.", Sie können jede beliebige Tonlage verwenden.

Wenn Sie jedoch möchten, dass das Arduino-Board etwas für Sie tut, müssen Sie die Schreibregeln für das Arduino-Programm befolgen, um die Befehle einzugeben.

Dieses Kapitel enthält die grundlegenden Regeln der Arduino-Sprache und hilft Ihnen zu verstehen, wie Sie natürliche Sprache in Code übersetzen.

Natürlich ist dies ein Prozess, der Zeit benötigt, um sich daran zu gewöhnen, und es ist auch der fehleranfälligste Teil des Prozesses für Anfänger. Wenn Sie also oft Fehler machen, ist das in Ordnung, versuchen Sie es einfach ein paar Mal mehr.


Semikolon ``;``
------------------

Genau wie beim Schreiben eines Briefes, bei dem Sie am Ende jedes Satzes einen Punkt als Abschluss setzen, müssen Sie in der Arduino-Sprache ``;`` verwenden, um dem Board das Ende des Befehls mitzuteilen.

Nehmen Sie das bekannte Beispiel "Onboard-LED blinkt". Ein korrekter Sketch sollte so aussehen.

Beispiel:

.. code-block:: C

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

Schauen wir uns als Nächstes die folgenden beiden Sketche an und raten Sie, ob sie von Arduino korrekt erkannt werden können, bevor Sie sie ausführen.

Sketch A:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // Hier kommt Ihr Setup-Code hin, der einmal ausgeführt wird:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // Hier kommt Ihr Hauptcode hin, der wiederholt ausgeführt wird:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Sketch B:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // Hier kommt Ihr Setup-Code hin, der einmal ausgeführt wird:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // Hier kommt Ihr Hauptcode hin, der wiederholt ausgeführt wird:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

Das Ergebnis ist, dass **Sketch A** einen Fehler meldet und **Sketch B** funktioniert.

* Die Fehler in **Sketch A** sind fehlende ``;`` und obwohl es normal aussieht, kann Arduino es nicht lesen.
* **Sketch B** sieht unübersichtlich aus, aber in der Tat sind Einrückungen, Zeilenumbrüche und Leerzeichen in Anweisungen Dinge, die in Arduino-Programmen keine Rolle spielen. Für den Arduino-Compiler sieht es genauso aus wie im Beispiel.

Bitte schreiben Sie Ihren Code jedoch nicht wie **Sketch B**, da normalerweise Menschen den Code schreiben und lesen. Vermeiden Sie also unnötige Schwierigkeiten.

Geschweifte Klammern ``{}``
------------------

``{}`` sind der Hauptbestandteil der Arduino-Programmiersprache und müssen paarweise auftreten. 
Eine bessere Programmierkonvention ist es, eine Struktur, die geschweifte Klammern erfordert, einzufügen, indem man die rechte geschweifte Klammer direkt nach der linken geschweiften Klammer eingibt und dann den Cursor zwischen die geschweiften Klammern bewegt, um die Anweisung einzufügen.

Kommentare ``//``
---------------

Kommentare sind der Teil des Sketches, den der Compiler ignoriert. Sie werden normalerweise verwendet, um anderen zu erklären, wie das Programm funktioniert.

Wenn wir zwei aufeinanderfolgende Schrägstriche in eine Codezeile schreiben, ignoriert der Compiler alles bis zum Ende der Zeile.

Wenn wir einen neuen Sketch erstellen, enthält er zwei Kommentare, und wenn wir diese beiden Kommentare entfernen, wird der Sketch in keiner Weise beeinflusst.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // Hier kommt Ihr Setup-Code hin, der einmal ausgeführt wird:

    }

    void loop() {
        // Hier kommt Ihr Hauptcode hin, der wiederholt ausgeführt wird:

    }

Kommentare sind sehr nützlich beim Programmieren. Im Folgenden sind einige gängige Verwendungszwecke aufgeführt.


* Verwendung A: Erklären Sie sich selbst oder anderen, was dieser Abschnitt des Codes macht.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); // Setze Pin 13 auf Ausgangsmodus, er steuert die Onboard-LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Aktiviere die Onboard-LED, indem Pin 13 auf HIGH gesetzt wird
        delay(500); // Status für 500 ms beibehalten
        digitalWrite(13,LOW); // Schalte die Onboard-LED aus
        delay(500);// Status für 500 ms beibehalten
    }

* Verwendung B: Vorübergehendes Deaktivieren einiger Anweisungen (ohne sie zu löschen) und deren Auskommentierung, wenn Sie sie benötigen, sodass Sie sie nicht neu schreiben müssen. Dies ist sehr nützlich beim Debuggen von Code und beim Lokalisieren von Programmfehlern.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    Verwenden Sie die Tastenkombination ``Ctrl+/``, um Ihren Code schnell zu kommentieren oder zu entkommentieren.

Kommentar ``/**/``
------------------------

Genauso wie ``//`` für Kommentare. Diese Art von Kommentar kann über mehrere Zeilen gehen, und sobald der Compiler ``/*`` liest, ignoriert er alles, was folgt, bis er auf ``*/`` stößt.

Beispiel 1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        Der folgende Code lässt die Onboard-LED blinken.
        Sie können die Zahl in delay() ändern, um die Blinkfrequenz zu ändern.
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

Dies ist ein nützliches C++-Werkzeug.

.. code-block:: C

    #define identifier token-string

Der Compiler ersetzt automatisch ``identifier`` durch ``token-string``, wenn er ihn liest. Dies wird normalerweise für Konstantendefinitionen verwendet.

Als Beispiel hier ein Sketch, der define verwendet, um die Lesbarkeit des Codes zu verbessern.

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

Für den Compiler sieht es tatsächlich so aus.


.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

Wir können sehen, dass der ``identifier`` ersetzt wurde und im Programm nicht existiert.
Deshalb gibt es einige wichtige Punkte, die beim Einsatz zu beachten sind.

1. Ein ``token-string`` kann nur manuell geändert werden und kann nicht durch arithmetische Operationen im Programm in andere Werte umgewandelt werden.

2. Vermeiden Sie die Verwendung von Symbolen wie ``;``. Zum Beispiel:

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

Der Compiler wird dies wie folgt erkennen, was als Fehler gemeldet wird.

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    Eine Namenskonvention für ``#define`` besteht darin, ``identifier`` zu kapitalisieren, um Verwechslungen mit Variablen zu vermeiden.
