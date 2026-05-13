.. note::

    Ciao, benvenuto nella Comunità di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Immergiti più a fondo in Raspberry Pi, Arduino e ESP32 con altri entusiasti.

    **Perché Unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per arricchire le tue competenze.
    - **Anteprime Esclusive**: Ottieni un accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

Operatori
==============

Gli operatori vengono utilizzati per eseguire operazioni su variabili e valori.

Operatori Aritmetici
------------------------

Puoi utilizzare gli operatori aritmetici per eseguire alcune operazioni matematiche comuni.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operatore
        - Nome
    *   - ``+``
        - Somma
    *   - ``-``
        - Sottrazione
    *   - ``*``
        - Moltiplicazione
    *   - ``/``
        - Divisione
    *   - ``%``
        - Modulo
    *   - ``**``
        - Esponenziazione
    *   - ``//``
        - Divisione intera



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

Operatori di Assegnazione
-------------------------------

Gli operatori di assegnazione sono utilizzati per assegnare valori alle variabili.

.. list-table:: 
    :widths: 10 30 30
    :header-rows: 1

    *   - Operatore
        - Esempio
        - Equivalente A
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

Operatori di Confronto
---------------------------
Gli operatori di confronto sono usati per confrontare due valori.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operatore
        - Nome
    *   - ``==``
        - Uguale
    *   - ``!=``
        - Diverso
    *   - ``<``
        - Minore di
    *   - ``>``
        - Maggiore di
    *   - ``>=``
        - Maggiore o uguale a
    *   - ``<=``
        - Minore o uguale a




.. code-block:: python

    a = 6
    b = 8

    print(a>b)

>>> %Run test.py
False
>>> 

Ritorna **False**, perché **a** è minore di **b**.

Operatori Logici
-----------------------

Gli operatori logici sono usati per combinare affermazioni condizionali.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operatore
        - Descrizione
    *   - ``and``
        - Ritorna True se entrambe le affermazioni sono vere
    *   - ``or``
        - Ritorna True se una delle affermazioni è vera
    *   - ``not``
        - Inverte il risultato, ritorna False se il risultato è vero

.. code-block:: python

    a = 6
    print(a > 2 and a < 8)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

Operatori di Identità
------------------------

Gli operatori di identità sono usati per confrontare gli oggetti, non per verificare se sono uguali, ma per vedere se sono effettivamente lo stesso oggetto con la stessa locazione di memoria.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operatore
        - Descrizione
    *   - ``is``
        - Ritorna True se entrambe le variabili sono lo stesso oggetto
    *   - ``is not``
        - Ritorna True se entrambe le variabili non sono lo stesso oggetto

.. code-block:: python

    a = ["hello", "welcome"]
    b = ["hello", "welcome"]
    c = a

    print(a is c)
    # ritorna True perché z è lo stesso oggetto di x

    print(a is b)
    # ritorna False perché x non è lo stesso oggetto di y, anche se hanno lo stesso contenuto

    print(a == b)
    # ritorna True perché x è uguale a y

>>> %Run -c $EDITOR_CONTENT
True
False
True
>>> 

Operatori di Appartenenza
-------------------------------
Gli operatori di appartenenza sono usati per testare se una sequenza è presente in un oggetto.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operatore
        - Descrizione
    *   - ``in``
        - Ritorna True se una sequenza con il valore specificato è presente nell'oggetto
    *   - ``not in``
        - Ritorna True se una sequenza con il valore specificato non è presente nell'oggetto

.. code-block:: python

    a = ["hello", "welcome", "Goodmorning"]

    print("welcome" in a)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

Operatori Bitwise
------------------------

Gli operatori bitwise sono usati per confrontare numeri (binari).

.. list-table:: 
    :widths: 10 20 50
    :header-rows: 1

    *   - Operatore
        - Nome
        - Descrizione
    *   - ``&``
        - AND
        - Imposta ogni bit a 1 se entrambi i bit sono 1
    *   - ``|``
        - OR
        - Imposta ogni bit a 1 se uno dei due bit è 1
    *   - ``^``
        - XOR
        - Imposta ogni bit a 1 se solo uno dei due bit è 1
    *   - ``~``
        - NOT
        - Inverte tutti i bit
    *   - ``<<``
        - Spostamento a sinistra con riempimento di zero
        - Sposta a sinistra inserendo zeri da destra e lasciando cadere i bit più a sinistra
    *   - ``>>``
        - Spostamento a destra con segno
        - Sposta a destra inserendo copie del bit più a sinistra da sinistra, e lasciando cadere i bit più a destra

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