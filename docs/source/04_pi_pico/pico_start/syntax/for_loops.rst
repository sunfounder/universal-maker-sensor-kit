 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _syntax_forloop:

For-Schleifen
==================

Die ``for``-Schleife kann eine beliebige Sequenz von Elementen durchlaufen, wie etwa eine Liste oder einen String.

Das Syntaxformat der for-Schleife lautet wie folgt:

.. code-block:: python

    for val in sequence:
        Body of for

Hier ist ``val`` eine Variable, die in jeder Iteration den Wert des Elements in der Sequenz erhält.

Die Schleife läuft weiter, bis wir das letzte Element in der Sequenz erreichen. Verwenden Sie Einrückungen, um den Körper der ``for``-Schleife vom restlichen Code zu trennen.

**Flussdiagramm der for-Schleife**

.. image:: img/for_loop.png




.. code-block:: python

    numbers = [1, 2, 3, 4]
    sum = 0

    for val in numbers:
        sum = sum+val
        
    print("The sum is", sum)

>>> %Run -c $EDITOR_CONTENT
The sum is 10

The break Statement
-------------------------

Mit der break-Anweisung können wir die Schleife stoppen, bevor sie alle Elemente durchlaufen hat:



.. code-block:: python

    numbers = [1, 2, 3, 4]
    sum = 0

    for val in numbers:
        sum = sum+val
        if sum == 6:
            break
    print("The sum is", sum)

>>> %Run -c $EDITOR_CONTENT
The sum is 6

Die continue-Anweisung
--------------------------------------------

Mit der ``continue``-Anweisung können wir die aktuelle Iteration der Schleife stoppen und mit der nächsten fortfahren:



.. code-block:: python

    numbers = [1, 2, 3, 4]

    for val in numbers:
        if val == 3:
            continue
        print(val)

>>> %Run -c $EDITOR_CONTENT
1
2
4

Die range() Funktion
--------------------------------------------

Wir können die range() Funktion verwenden, um eine Sequenz von Zahlen zu generieren. range(6) wird Zahlen zwischen 0 und 5 erzeugen (6 Zahlen).

Wir können auch Start, Stop und Schrittgröße wie range(start, stop, step_size) definieren. Wenn nicht angegeben, wird step_size auf 1 festgelegt.

Im Sinne von range ist das Objekt "träge", weil es beim Erstellen des Objekts nicht jede Zahl generiert, die es "enthält". Dies ist jedoch kein Iterator, da es die Operationen in, len und ``__getitem__`` unterstützt.

Diese Funktion wird nicht alle Werte im Speicher speichern; das wäre ineffizient. Es wird sich daher an den Start, das Ende, die Schrittgröße erinnern und die nächste Zahl auf der Reise generieren.

Um diese Funktion zu zwingen, alle Elemente auszugeben, können wir die Funktion list() verwenden.

print(range(6))

print(list(range(6)))

print(list(range(2, 6)))

print(list(range(2, 10, 2)))

>>> %Run -c $EDITOR_CONTENT
range(0, 6)
[0, 1, 2, 3, 4, 5]
[2, 3, 4, 5]
[2, 4, 6, 8]


Wir können ``range()`` in einer ``for``-Schleife verwenden, um über eine Sequenz von Zahlen zu iterieren. Es kann mit der len() Funktion kombiniert werden, um den Index zum Durchlaufen der Sequenz zu verwenden.



.. code-block:: python

    fruits = ['pear', 'apple', 'grape']

    for i in range(len(fruits)):
        print("I like", fruits[i])
        
>>> %Run -c $EDITOR_CONTENT
I like pear
I like apple
I like grape

Else in For Loop
--------------------------------

Die ``for``-Schleife kann auch einen optionalen ``else``-Block haben. Wenn die Elemente in der für die Schleife verwendeten Sequenz erschöpft sind, wird der ``else``-Teil ausgeführt.

Das Schlüsselwort ``break`` kann verwendet werden, um die ``for``-Schleife zu stoppen. In diesem Fall wird der ``else``-Teil ignoriert.

Daher wird, wenn keine Unterbrechung erfolgt, der ``else``-Teil der ``for``-Schleife ausgeführt.



.. code-block:: python

    for val in range(5):
        print(val)
    else:
        print("Finished")

>>> %Run -c $EDITOR_CONTENT
0
1
2
3
4
Fertig

Der else-Block wird NICHT ausgeführt, wenn die Schleife durch eine break-Anweisung gestoppt wird.



.. code-block:: python


    for val in range(5):
        if val == 2: break
        print(val)
    else:
        print("Finished")

>>> %Run -c $EDITOR_CONTENT
0
1


