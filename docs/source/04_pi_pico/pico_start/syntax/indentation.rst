 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Einrückung
=============

Einrückung bezieht sich auf die Leerzeichen am Anfang einer Codezeile.
Wie bei Standard-Python-Programmen laufen MicroPython-Programme normalerweise von oben nach unten:
Es durchläuft jede Zeile nacheinander, führt sie im Interpreter aus und fährt dann mit der nächsten Zeile fort,
genau wie wenn Sie sie Zeile für Zeile in der Shell eingeben würden.
Ein Programm, das einfach die Anweisungsliste Zeile für Zeile durchgeht, ist jedoch nicht sehr intelligent - daher hat MicroPython, wie Python auch, seine eigene Methode, um die Reihenfolge seiner Programmabläufe zu steuern: Einrückung.

Sie müssen mindestens ein Leerzeichen vor print() setzen, sonst erscheint eine Fehlermeldung "Ungültige Syntax". Es wird normalerweise empfohlen, die Leerzeichen durch gleichmäßiges Drücken der Tabulatortaste zu standardisieren.



.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

Sie müssen in demselben Codeblock dieselbe Anzahl von Leerzeichen verwenden, sonst gibt Ihnen Python einen Fehler.


.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")
            print("Eight is greater than Five")
            
>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

