.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_syntax_while:


While-Schleifen
====================

Die ``while``-Anweisung wird verwendet, um ein Programm in einer Schleife auszuführen, das heißt, ein Programm unter bestimmten Bedingungen in einer Schleife auszuführen, um dieselbe Aufgabe zu verarbeiten, die wiederholt bearbeitet werden muss.

Ihre grundlegende Form ist:

.. code-block:: python

    while test expression:
        Body of while


In der ``while``-Schleife wird zuerst der ``Testausdruck`` überprüft. Nur wenn der ``Testausdruck`` als ``True`` ausgewertet wird, tritt der Schleifenkörper ein. Nach einer Iteration wird der ``Testausdruck`` erneut überprüft. Dieser Vorgang wird fortgesetzt, bis der ``Testausdruck`` als ``False`` ausgewertet wird.

In MicroPython wird der Körper der ``while``-Schleife durch Einrückung bestimmt.

Der Körper beginnt mit einer Einrückung und endet mit der ersten nicht eingerückten Zeile.

Python interpretiert jeden nicht-null-Wert als ``True``. None und 0 werden als ``False`` interpretiert.

**Flussdiagramm der while-Schleife**

.. image:: img/while_loop.png



.. code-block:: python

    x = 10

    while x > 0:
        print(x)
        x -= 1

>>> %Run -c $EDITOR_CONTENT
10
9
8
7
6
5
4
3
2
1


Break-Anweisung
--------------------

Mit der Break-Anweisung können wir die Schleife stoppen, auch wenn die Bedingung der while-Schleife wahr ist:



.. code-block:: python

    x = 10

    while x > 0:
        print(x)
        if x == 6:
            break
        x -= 1

>>> %Run -c $EDITOR_CONTENT
10
9
8
7
6

While-Schleife mit Else
---------------------------
Wie bei der ``if``-Schleife kann die ``while``-Schleife auch einen optionalen ``else``-Block haben.

Wenn die Bedingung in der ``while``-Schleife als ``False`` ausgewertet wird, wird der ``else``-Teil ausgeführt.



.. code-block:: python

    x = 10

    while x > 0:
        print(x)
        x -= 1
    else:
        print("Game Over")

>>> %Run -c $EDITOR_CONTENT
10
9
8
7
6
5
4
3
2
1
Game Over