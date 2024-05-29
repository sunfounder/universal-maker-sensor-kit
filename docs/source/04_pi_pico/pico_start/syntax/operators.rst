 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Operatoren
=================
Operatoren werden verwendet, um Operationen auf Variablen und Werten durchzuführen.

* :ref:`Arithmetische Operatoren`

* :ref:`Zuweisungsoperatoren`

* :ref:`Vergleichsoperatoren`

* :ref:`Logische Operatoren`

* :ref:`Identitätsoperatoren`

* :ref:`Zugehörigkeitsoperatoren`

* :ref:`Bitweise Operatoren`

Arithmetische Operatoren
----------------------------------
Mit arithmetischen Operatoren können Sie einige gängige mathematische Operationen durchführen.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Name
    *   - ``+``
        - Addition
    *   - ``-``
        - Subtraction
    *   - ``*``
        - Multiplication
    *   - ``/``
        - Division
    *   - ``%``
        - Modulus
    *   - ``**``
        - Exponentiation
    *   - ``//``
        - Floor division



.. code-block:: python

    x = 5
    y = 3

    a = x + y
    b = x - y
    c = x * y
    d = x / y
    e = x % y
    f = x ** y
    g = x // y

    print(a)
    print(b)
    print(c)
    print(d)
    print(e)
    print(f)
    print(g)

>>> %Run -c $EDITOR_CONTENT
8
2
15
1.666667
2
125
1
8
2
15
>>> 

Zuweisungsoperatoren
---------------------

Zuweisungsoperatoren können verwendet werden, um Werte Variablen zuzuweisen.

.. list-table:: 
    :widths: 10 30 30
    :header-rows: 1

    *   - Operator
        - Example
        - Same As
    *   - ``=``
        - a = 6
        - a =6
    *   - ``+=``
        - a += 6
        - a = a + 6
    *   - ``-=``
        - a -= 6
        - a = a - 6
    *   - ``*=``
        - a \*= 6
        - a = a * 6
    *   - ``/=``
        - a /= 6
        - a = a / 6
    *   - ``%=``
        - a %= 6
        - a = a % 6
    *   - ``**=``
        - a \*\*= 6
        - a = a ** 6
    *   - ``//=``
        - a //= 6
        - a = a // 6
    *   - ``&=``
        - a &= 6
        - a = a & 6
    *   - ``|=``
        - a \|= 6
        - a = a | 6
    *   - ``^=``
        - a ^= 6
        - a = a ^ 6
    *   - ``>>=``
        - a >>= 6
        - a = a \>\> 6
    *   - ``<<=``
        - a <<= 6
        - a = a << 6



.. code-block:: python

    a = 6

    a *= 6
    print(a)

>>> %Run test.py
36
>>> 

Vergleichsoperatoren
------------------------
Vergleichsoperatoren werden verwendet, um zwei Werte zu vergleichen.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Name
    *   - ``==``
        - Equal
    *   - ``!=``
        - Not equal
    *   - ``<``
        - Less than
    *   - ``>``
        - Greater than
    *   - ``>=``
        - Greater than or equal to
    *   - ``<=``
        - Less than or equal to




.. code-block:: python

    a = 6
    b = 8

    print(a>b)

>>> %Run test.py
False
>>> 

Gibt **False** zurück, da **a** kleiner als **b** ist.

Logische Operatoren
-----------------------

Logische Operatoren werden verwendet, um bedingte Aussagen zu kombinieren.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Description
    *   - ``and``
        - Returns True if both statements are true
    *   - ``or``
        - Returns True if one of the statements is true
    *   - ``not``
        - Reverse the result, returns False if the result is true

.. code-block:: python

    a = 6
    print(a > 2 and a < 8)

>>> %Run -c $EDITOR_CONTENT
True
>>> 
Identitätsoperatoren
------------------------

Identitätsoperatoren werden verwendet, um die Objekte zu vergleichen, nicht ob sie gleich sind, sondern ob sie tatsächlich dasselbe Objekt sind, mit derselben Speicherposition.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Description
    *   - ``is``
        - Returns True if both variables are the same object
    *   - ``is not``
        - Returns True if both variables are not the same object

.. code-block:: python

    a = ["hello", "welcome"]
    b = ["hello", "welcome"]
    c = a

    print(a is c)
    # returns True because z is the same object as x

    print(a is b)
    # returns False because x is not the same object as y, even if they have the same content

    print(a == b)
    # returns True because x is equal to y

>>> %Run -c $EDITOR_CONTENT
True
False
True
>>> 

Mitgliedschaftsoperatoren
--------------------------------
Mitgliedschaftsoperatoren werden verwendet, um zu testen, ob eine Sequenz in einem Objekt vorhanden ist.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Description
    *   - ``in``
        - Returns True if a sequence with the specified value is present in the object
    *   - ``not in``
        - Returns True if a sequence with the specified value is not present in the object

.. code-block:: python

    a = ["hello", "welcome", "Goodmorning"]

    print("welcome" in a)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

Bitweise Operatoren
------------------------

Bitweise Operatoren werden verwendet, um (binäre) Zahlen zu vergleichen.

.. list-table:: 
    :widths: 10 20 50
    :header-rows: 1

    *   - Operator
        - Name
        - Description
    *   - ``&``
        - AND
        - Sets each bit to 1 if both bits are 1
    *   - ``|``
        - OR
        - Sets each bit to 1 if one of two bits is 1
    *   - ``^``
        - XOR
        - Sets each bit to 1 if only one of two bits is 1
    *   - ``~``
        - NOT
        - Inverts all the bits
    *   - ``<<``
        - Zero fill left shift
        - Shift left by pushing zeros in from the right and let the leftmost bits fall off
    *   - ``>>``
        - Signed right shift
        - Shift right by pushing copies of the leftmost bit in from the left, and let the rightmost bits fall off

.. code-block:: python

    num = 2

    print(num & 1)
    print(num | 1)
    print(num << 1)

>>> %Run -c $EDITOR_CONTENT
0
3
4
>>>