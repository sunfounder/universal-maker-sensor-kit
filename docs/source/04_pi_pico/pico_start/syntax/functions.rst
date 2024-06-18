.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Functions
==============

In MicroPython ist eine Funktion eine Gruppe von zusammenhängenden Anweisungen, die eine spezifische Aufgabe ausführen.

Funktionen helfen dabei, unser Programm in kleinere modulare Blöcke zu unterteilen. Wenn unser Plan größer und größer wird, machen Funktionen ihn organisierter und leichter zu handhaben.

Darüber hinaus vermeiden sie Duplizierung und machen den Code wiederverwendbar.

Funktion erstellen
------------------

.. code-block::

    def function_name(parameters): 
        """docstring"""
        statement(s)

* Eine Funktion wird mit dem Schlüsselwort ``def`` definiert.

* Ein Funktionsname, um die Funktion eindeutig zu identifizieren. Die Funktionsbenennung ist identisch mit der Variablenbenennung und folgt beiden folgenden Regeln.
    
   * Kann nur Zahlen, Buchstaben und Unterstriche enthalten.
   * Das erste Zeichen muss ein Buchstabe oder Unterstrich sein.
   * Groß- und Kleinschreibung beachten.

* Parameter (Argumente), durch die wir Werte an eine Funktion übergeben. Sie sind optional.

* Der Doppelpunkt (:) markiert das Ende des Funktionsheaders.

* Optionaler Docstring, der verwendet wird, um die Funktion der Funktion zu beschreiben. Normalerweise verwenden wir dreifache Anführungszeichen, damit der Docstring auf mehrere Zeilen erweitert werden kann.

* Eine oder mehrere gültige Micropython-Anweisungen, die den Funktionskörper ausmachen. Die Anweisungen müssen auf der gleichen Einzugsebene stehen (normalerweise 4 Leerzeichen).

* Jede Funktion benötigt mindestens eine Anweisung. Wenn aus irgendeinem Grund eine Funktion vorhanden ist, die keine Anweisung enthält, setzen Sie bitte die Anweisung ``pass`` ein, um Fehler zu vermeiden.

* Eine optionale ``return``-Anweisung, um einen Wert aus der Funktion zurückzugeben.


Aufrufen einer Funktion
-------------------------------

Um eine Funktion aufzurufen, fügen Sie nach dem Funktionsnamen Klammern hinzu.



.. code-block:: python

    def my_function():
        print("Your first function")

    my_function()

>>> %Run -c $EDITOR_CONTENT
Your first function

Die return-Anweisung
-----------------------

Die return-Anweisung wird verwendet, um eine Funktion zu beenden und an die Stelle zurückzukehren, an der sie aufgerufen wurde.

**Syntax von return**

.. code-block:: python

    return [expression_list]

Die Anweisung kann einen Ausdruck enthalten, der ausgewertet und einen Wert zurückgibt. Wenn in der Anweisung kein Ausdruck vorhanden ist oder die ``return``-Anweisung selbst in der Funktion nicht vorhanden ist, gibt die Funktion ein ``None``-Objekt zurück.



.. code-block:: python

    def my_function():
            print("Your first function")

    print(my_function())

>>> %Run -c $EDITOR_CONTENT
Your first function
None

Hier ist ``None`` der Rückgabewert, weil die ``return``-Anweisung nicht verwendet wird.
Argumente
-------------

Informationen können der Funktion als Argumente übergeben werden.

Geben Sie Argumente in Klammern nach dem Funktionsnamen an. Sie können so viele Argumente hinzufügen, wie Sie benötigen, trennen Sie sie einfach mit Kommas.



.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!


Anzahl der Argumente
*************************

Standardmäßig muss eine Funktion mit der richtigen Anzahl von Argumenten aufgerufen werden. Das bedeutet, dass wenn Ihre Funktion 2 Parameter erwartet, Sie die Funktion mit 2 Argumenten aufrufen müssen, nicht mehr und nicht weniger.



.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

Hier hat die Funktion willkommen() 2 Parameter.

Da wir diese Funktion mit zwei Argumenten aufgerufen haben, läuft die Funktion reibungslos und ohne Fehler.

Wenn sie mit einer anderen Anzahl von Argumenten aufgerufen wird, zeigt der Interpreter eine Fehlermeldung an.

Im Folgenden finden Sie den Aufruf dieser Funktion, der jeweils ein und kein Argument enthält, sowie die entsprechenden Fehlermeldungen.

.. code-block::

    willkommen("Lily")＃Nur ein Argument

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 1 were given

.. code-block::

    welcome()＃No arguments

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 0 were given


Standardargumente
*************************

In MicroPython können wir den Zuweisungsoperator (=) verwenden, um einen Standardwert für den Parameter bereitzustellen.

Wenn wir die Funktion ohne Argument aufrufen, verwendet sie den Standardwert.

.. code-block:: python

    def welcome(name, msg = "Welcome to China!"):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)
    welcome("Lily")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!


In dieser Funktion hat der Parameter ``name`` keinen Standardwert und ist erforderlich (obligatorisch) während des Aufrufs.

Auf der anderen Seite ist der Standardwert des Parameters ``msg`` "Willkommen in China!". Daher ist es beim Aufruf optional. Wenn ein Wert bereitgestellt wird, überschreibt er den Standardwert.

In der Funktion können eine beliebige Anzahl von Argumenten einen Standardwert haben. Sobald jedoch ein Standardargument vorhanden ist, müssen auch alle Argumente rechts davon Standardwerte haben.

Dies bedeutet, dass Nicht-Standardargumente nicht auf Standardargumente folgen können. 

Wenn wir beispielsweise den obigen Funktionsheader wie folgt definieren:

.. code-block:: python

    def welcome(name = "Lily", msg):

We will receive the following error message:

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
SyntaxError: non-default argument follows default argument


Schlüsselwortargumente
**************************

Wenn wir eine Funktion mit bestimmten Werten aufrufen, werden diesen Werten Argumente basierend auf ihrer Position zugewiesen.

Beispielsweise in der obigen Funktion willkommen(), als wir sie als willkommen("Lily", "Willkommen in China") aufgerufen haben, wird der Wert "Lily" dem ``name`` zugewiesen und ähnlich "Willkommen in China" dem Parameter ``msg``.

MicroPython ermöglicht den Aufruf von Funktionen mit Schlüsselwortargumenten. Wenn wir die Funktion auf diese Weise aufrufen, kann die Reihenfolge (Position) der Argumente geändert werden. 

.. code-block:: python

    # keyword arguments
    welcome(name = "Lily",msg = "Welcome to China!")

    # keyword arguments (out of order)
    welcome(msg = "Welcome to China！",name = "Lily") 

    #1 positional, 1 keyword argument
    welcome("Lily", msg = "Welcome to China!")

Wie wir sehen können, können wir positionale Argumente und Schlüsselwortargumente während der Funktionsaufrufe mischen. Wir müssen jedoch beachten, dass die Schlüsselwortargumente nach den positionalen Argumenten kommen müssen.

Ein positionales Argument nach einem Schlüsselwortargument führt zu einem Fehler. 

Wenn beispielsweise der Funktionsaufruf wie folgt erfolgt:

.. code-block:: python

    welcome(name="Lily","Welcome to China!")

Will result in an error:

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 5, in <module>
SyntaxError: non-keyword arg after keyword arg


Beliebige Argumente
********************

Manchmal weiß man im Voraus nicht, wie viele Argumente an die Funktion übergeben werden sollen.

In der Funktionsdefinition können wir einen Asterisk (*) vor dem Parameternamen hinzufügen.



.. code-block:: python

    def welcome(*names):
        """This function welcomes all the person
        in the name tuple"""
        #names is a tuple with arguments
        for name in names:
            print("Welcome to China!", name)
            
    welcome("Lily","John","Wendy")

>>> %Run -c $EDITOR_CONTENT
Welcome to China! Lily
Welcome to China! John
Welcome to China! Wendy

Hier haben wir die Funktion mit mehreren Argumenten aufgerufen. Diese Argumente werden zuerst in ein Tupel verpackt, bevor sie an die Funktion übergeben werden.

Innerhalb der Funktion verwenden wir eine Schleife, um alle Argumente abzurufen.

Rekursion
----------------
In Python wissen wir, dass eine Funktion andere Funktionen aufrufen kann. Es ist sogar möglich, dass die Funktion sich selbst aufruft. Diese Art von Konstruktion wird als rekursive Funktionen bezeichnet.

Dies hat den Vorteil, dass Sie Daten durchlaufen können, um zu einem Ergebnis zu gelangen.

Der Entwickler sollte sehr vorsichtig mit Rekursion sein, da es recht einfach ist, eine Funktion zu schreiben, die niemals terminiert, oder eine, die übermäßige Mengen an Speicher oder Prozessorleistung verwendet. Wenn jedoch korrekt geschrieben, kann Rekursion ein sehr effizienter und mathematisch eleganter Ansatz zur Programmierung sein.



.. code-block:: python

    def rec_func(i):
        if(i > 0):
            result = i + rec_func(i - 1)
            print(result)
        else:
            result = 0
        return result

    rec_func(6)

>>> %Run -c $EDITOR_CONTENT
1
3
6
10
15
21
In diesem Beispiel ist rekursive_funktion() eine Funktion, die wir definiert haben, um sich selbst aufzurufen ("Rekursion"). Wir verwenden die Variable ``i`` als Daten, und sie wird jedes Mal um eins (-1) dekrementiert, wenn wir rekursiv sind. Wenn die Bedingung nicht größer als 0 ist (das heißt, 0), endet die Rekursion.

Für neue Entwickler kann es einige Zeit dauern, herauszufinden, wie es funktioniert, und der beste Weg, es zu testen und zu ändern.

**Vorteile der Rekursion**

* Rekursive Funktionen machen den Code sauber und elegant.
* Eine komplexe Aufgabe kann mit Rekursion in einfachere Teilprobleme aufgeteilt werden.
* Die Sequenzgenerierung ist einfacher mit Rekursion als mit einigen verschachtelten Iterationen.

**Nachteile der Rekursion**

* Manchmal ist die Logik hinter der Rekursion schwer nachzuvollziehen.
* Rekursive Aufrufe sind teuer (ineffizient), da sie viel Speicher und Zeit beanspruchen.
* Rekursive Funktionen sind schwer zu debuggen.
