 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

If Else
=============

Entscheidungen sind erforderlich, wenn wir einen Code nur ausführen möchten, wenn eine bestimmte Bedingung erfüllt ist.

if
--------------------
.. code-block:: python

    if test expression:
        statement(s)

Hier bewertet das Programm den ``Testausdruck`` und führt die ``Anweisung`` nur aus, wenn der ``Testausdruck`` True ist.

Wenn ``Testausdruck`` False ist, werden ``Anweisung(en)`` nicht ausgeführt.

In MicroPython bedeutet Einrückung den Körper der ``if``-Anweisung. Der Körper beginnt mit einer Einrückung und endet mit der ersten nicht eingerückten Zeile.

Python interpretiert Nicht-Null-Werte als "True". None und 0 werden als "False" interpretiert.

**if-Anweisungsflussdiagramm**

.. image:: img/if_statement.png

**Beispiel**

.. code-block:: python

    num = 8
    if num > 0:
        print(num, "is a positive number.")
    print("End with this line")

>>> %Run -c $EDITOR_CONTENT
8 is a positive number.
End with this line



if...else
-----------------------

.. code-block:: python

    if test expression:
        Body of if
    else:
        Body of else

The ``if..else`` statement evaluates ``test expression`` and will execute the body of ``if`` only when the test condition is ``True``.

If the condition is ``False``, the body of ``else`` is executed. Indentation is used to separate the blocks.

**if...else-Anweisungsflussdiagramm**

.. image:: img/if_else.png

**Beispiel**

.. code-block:: python

    num = -8
    if num > 0:
        print(num, "is a positive number.")
    else:
        print(num, "is a negative number.")

>>> %Run -c $EDITOR_CONTENT
-8 is a negative number.



if...elif...else
--------------------

.. code-block:: python

    if test expression:
        Body of if
    elif test expression:
        Rumpf von elif
    else: 
        Body of else

``Elif`` ist die Abkürzung für ``else if``. Es ermöglicht uns, mehrere Ausdrücke zu überprüfen.

Wenn die Bedingung des ``if`` False ist, wird die Bedingung des nächsten elif-Blocks überprüft und so weiter.

Wenn alle Bedingungen ``False`` sind, wird der Rumpf von ``else`` ausgeführt.

Nur einer von mehreren ``if...elif...else``-Blöcken wird je nach Bedingungen ausgeführt.

Der ``if``-Block kann nur einen ``else``-Block haben. Aber er kann mehrere ``elif``-Blöcke haben.

**if...elif...else-Anweisungsflussdiagramm**

.. image:: img/if_elif_else.png

**Beispiel**

.. code-block:: python

    x = 10
    y = 9

    if x > y:
        print("x is greater than y")
    elif x == y:
        print("x and y are equal")
    else:
        print("x is greater than y")

>>> %Run -c $EDITOR_CONTENT
x is greater than y


Verschachteltes if
---------------------

Wir können eine if-Anweisung in eine andere if-Anweisung einbetten und sie dann als verschachtelte if-Anweisung bezeichnen.

**Beispiel**

.. code-block:: python

    x = 67

    if x > 10:
        print("Above ten,")
        if x > 20:
            print("and also above 20!")
        else:
            print("but not above 20.")

>>> %Run -c $EDITOR_CONTENT
Above ten,
and also above 20!