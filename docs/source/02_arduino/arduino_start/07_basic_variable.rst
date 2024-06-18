.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

 
Variable
==========

Die Variable ist eines der mächtigsten und wichtigsten Werkzeuge in einem Programm. Sie hilft uns, Daten in unseren Programmen zu speichern und abzurufen.

Die folgende Sketch-Datei verwendet Variablen. Sie speichert die Pinnummern der Onboard-LED in der Variable ``ledPin`` und die Zahl "500" in der Variable ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Moment mal, ist das nicht ein Duplikat dessen, was ``#define`` tut? Die Antwort ist NEIN.

* Die Rolle von ``#define`` besteht darin, einfach und direkt Text zu ersetzen, es wird vom Compiler nicht als Teil des Programms betrachtet. 
* Eine ``Variable`` hingegen existiert innerhalb des Programms und wird verwendet, um Werte zu speichern und abzurufen. Eine Variable kann auch ihren Wert innerhalb des Programms ändern, etwas, das ein ``define`` nicht kann.

Die folgende Sketch-Datei addiert sich selbst zur Variablen und bewirkt, dass die Onboard-LED nach jedem Blinken länger blinkt.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime + 200; //Jede Ausführung erhöht den Wert um 200
    }

Eine Variable deklarieren
-----------------------------

Eine Variable zu deklarieren bedeutet, eine Variable zu erstellen. 

Um eine Variable zu deklarieren, benötigt man zwei Dinge: den Datentyp und den Variablennamen. Der Datentyp muss durch ein Leerzeichen von der Variablen getrennt sein, und die Variablendeklaration muss mit einem ``;`` beendet werden.

Verwenden wir diese Variable als Beispiel.

.. code-block:: C

    int delayTime;

**Datentyp**

Hier ist ``int`` ein Datentyp, der Ganzzahlen speichern kann, die von -32768 bis 32766 reichen. Es kann auch nicht verwendet werden, um Dezimalzahlen zu speichern.

Variablen können andere Arten von Daten außer Ganzzahlen halten. Die Arduino-Sprache (die, erinnern wir uns, C++ ist) unterstützt einige davon von Haus aus (hier sind nur die am häufigsten verwendeten und nützlichsten aufgeführt):

* ``float``: Speichert eine Dezimalzahl, zum Beispiel 3.1415926.
* ``byte``: Kann Zahlen von 0 bis 255 speichern.
* ``boolean``: Hält nur zwei mögliche Werte, ``True`` oder ``False``, obwohl es ein Byte im Speicher belegt.
* ``char``: Hält eine Zahl von -127 bis 127. Da es als ``char`` markiert ist, versucht der Compiler, es einem Zeichen aus der |link_ascii| zuzuordnen.
* ``string``: Kann eine Zeichenfolge speichern, z. B. ``Halloween``.


**Variablenname**

Sie können die Variable beliebig benennen, z. B. ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, aber es gibt einige grundlegende Regeln zu beachten.

1. Beschreiben Sie, wofür sie verwendet wird. Hier habe ich die Variable ``delayTime`` genannt, damit man leicht verstehen kann, wofür sie dient. Es wäre zwar auch möglich, die Variable ``barryAllen`` zu nennen, aber das würde denjenigen, der den Code liest, verwirren.

2. Verwenden Sie eine gängige Nomenklatur. Sie können CamelCase verwenden, wie ich es mit dem großen T in ``delayTime`` getan habe, damit leicht zu erkennen ist, dass die Variable aus zwei Wörtern besteht. Alternativ können Sie auch Unterstriche verwenden und die Variable als ``delay_time`` schreiben. Das beeinflusst die Ausführung des Programms nicht, aber es erleichtert das Lesen des Codes, wenn Sie eine einheitliche Nomenklatur verwenden.

3. Verwenden Sie keine Schlüsselwörter. Ähnlich wie beim Tippen von "int" färbt die Arduino IDE es ein, um Sie daran zu erinnern, dass es sich um ein Wort mit einer besonderen Funktion handelt und nicht als Variablenname verwendet werden kann. Ändern Sie den Namen der Variable, wenn sie eingefärbt wird.

4. Spezielle Symbole sind nicht erlaubt. Zum Beispiel Leerzeichen, #, $, /, +, %, usw. Die Kombination aus englischen Buchstaben (Groß- und Kleinschreibung), Unterstrichen und Zahlen (wobei Zahlen nicht als erstes Zeichen eines Variablennamens verwendet werden dürfen) ist ausreichend.


**Einen Wert einer Variablen zuweisen**

Sobald wir die Variable deklariert haben, ist es an der Zeit, Daten zu speichern. Wir verwenden den Zuweisungsoperator (d. h. ``=``), um der Variable einen Wert zuzuweisen.

Wir können der Variable beim Deklarieren sofort einen Wert zuweisen.

.. code-block:: C

    int delayTime = 500;

Es ist auch möglich, ihr zu einem späteren Zeitpunkt einen neuen Wert zuzuweisen.

.. code-block:: C

    int delayTime; // kein Wert
    delayTime = 500; // Wert ist 500
    delayTime = delayTime + 200; // Wert ist 700
