 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Datentypen
===========

Eingebaute Datentypen
---------------------
MicroPython hat folgende Datentypen:

* Texttyp: str
* Numerische Typen: int, float, complex
* Sequenztypen: list, tuple, range
* Zuordnungstyp: dict
* Mengentypen: set, frozenset
* Boolescher Typ: bool
* Binäre Typen: bytes, bytearray, memoryview

Abrufen des Datentyps
-----------------------------
Sie können den Datentyp eines beliebigen Objekts mit der Funktion ``type()`` erhalten:



.. code-block:: python

    a = 6.8
    print(type(a))

>>> %Run -c $EDITOR_CONTENT
<class 'float'>

Festlegen des Datentyps
---------------------------
MicroPython muss den Datentyp nicht speziell festlegen, er wird bestimmt, wenn Sie einen Wert der Variable zuweisen.



.. code-block:: python

    x = "welcome"
    y = 45
    z = ["apple", "banana", "cherry"]

    print(type(x))
    print(type(y))
    print(type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'str'>
<class 'int'>
<class 'list'>
>>> 

Bestimmten des spezifischen Datentyps
-----------------------------------------

Wenn Sie den Datentyp angeben möchten, können Sie die folgenden Konstruktoren verwenden:

.. list-table:: 
    :widths: 25 10
    :header-rows: 1

    *   - Example
        - Date Type
    *   - x = int(20)
        - int
    *   - x = float(20.5)
        - float
    *   - x = complex(1j)
        - complex
    *   - x = str("Hello World")
        - str
    *   - x = list(("apple", "banana", "cherry"))
        - list
    *   - x = tuple(("apple", "banana", "cherry"))
        - tuple
    *   - x = range(6)
        - range
    *   - x = dict(name="John", age=36)
        - dict
    *   - x = set(("apple", "banana", "cherry"))
        - set
    *   - x = frozenset(("apple", "banana", "cherry"))
        - frozenset
    *   - x = bool(5)
        - bool
    *   - x = bytes(5)
        - bytes
    *   - x = bytearray(5)
        - bytearray
    *   - x = memoryview(bytes(5))
        - memoryview

Sie können einige davon ausdrucken, um das Ergebnis zu sehen.

.. code-block:: python

    a = float(20.5)
    b = list(("apple", "banana", "cherry"))
    c = bool(5)

    print(a)
    print(b)
    print(c)

>>> %Run -c $EDITOR_CONTENT
20.5
['apple', 'banana', 'cherry']
True
>>> 

Typumwandlung
----------------
Sie können von einem Typ in einen anderen mit den Methoden int(), float() und complex() konvertieren:
Das Umwandeln in Python erfolgt daher unter Verwendung von Konstruktorfunktionen:

* int() - konstruiert eine ganze Zahl aus einer ganzen Zahlen-Literal, einer Fließkommazahlen-Literal (indem alle Dezimalstellen entfernt werden) oder einer Zeichenfolgen-Literal (sofern die Zeichenfolge eine ganze Zahl darstellt)
* float() - konstruiert eine Fließkommazahl aus einer ganzen Zahlen-Literal, einer Fließkommazahlen-Literal oder einer Zeichenfolgen-Literal (sofern die Zeichenfolge eine Fließkommazahl oder eine ganze Zahl darstellt)
* str() - konstruiert eine Zeichenfolge aus einer Vielzahl von Datentypen, einschließlich Zeichenfolgen, ganzen Zahlen-Literalen und Fließkommazahlen-Literalen



.. code-block:: python

    a = float("5")
    b = int(3.7)
    c = str(6.0)

    print(a)
    print(b)
    print(c)

Hinweis: Sie können komplexe Zahlen nicht in einen anderen Zahlentyp konvertieren.
