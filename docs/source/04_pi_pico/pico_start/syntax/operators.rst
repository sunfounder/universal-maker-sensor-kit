.. note:: 

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Obtenez un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des tirages au sort et à des promotions festives.

    👉 Prêts à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Opérateurs
============

Les opérateurs sont utilisés pour effectuer des opérations sur des variables et des valeurs.


Opérateurs arithmétiques
-----------------------------

Vous pouvez utiliser les opérateurs arithmétiques pour effectuer des opérations mathématiques courantes.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Opérateur
        - Nom
    *   - ``+``
        - Addition
    *   - ``-``
        - Soustraction
    *   - ``*``
        - Multiplication
    *   - ``/``
        - Division
    *   - ``%``
        - Modulo
    *   - ``**``
        - Exponentiation
    *   - ``//``
        - Division entière



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

Opérateurs d'assignation
------------------------------

Les opérateurs d'assignation peuvent être utilisés pour attribuer des valeurs aux variables.

.. list-table:: 
    :widths: 10 30 30
    :header-rows: 1

    *   - Opérateur
        - Exemple
        - Équivalent à
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

Opérateurs de comparaison
------------------------------
Les opérateurs de comparaison sont utilisés pour comparer deux valeurs.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Opérateur
        - Nom
    *   - ``==``
        - Égal
    *   - ``!=``
        - Différent
    *   - ``<``
        - Inférieur à
    *   - ``>``
        - Supérieur à
    *   - ``>=``
        - Supérieur ou égal à
    *   - ``<=``
        - Inférieur ou égal à




.. code-block:: python

    a = 6
    b = 8

    print(a>b)

>>> %Run test.py
False
>>> 

Retourne **False**, car **a** est inférieur à **b**.

Opérateurs logiques
-----------------------

Les opérateurs logiques sont utilisés pour combiner des déclarations conditionnelles.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Opérateur
        - Description
    *   - ``and``
        - Retourne True si les deux déclarations sont vraies
    *   - ``or``
        - Retourne True si l'une des déclarations est vraie
    *   - ``not``
        - Inverse le résultat, retourne False si le résultat est vrai

.. code-block:: python

    a = 6
    print(a > 2 and a < 8)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

Opérateurs d'identité
------------------------

Les opérateurs d'identité sont utilisés pour comparer les objets, non pas s'ils sont égaux, mais s'ils sont réellement le même objet, avec le même emplacement en mémoire.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Opérateur
        - Description
    *   - ``is``
        - Retourne True si les deux variables sont le même objet
    *   - ``is not``
        - Retourne True si les deux variables ne sont pas le même objet

.. code-block:: python

    a = ["hello", "welcome"]
    b = ["hello", "welcome"]
    c = a

    print(a is c)
    # retourne True car c est le même objet que a

    print(a is b)
    # retourne False car a n'est pas le même objet que b, même s'ils ont le même contenu

    print(a == b)
    # retourne True car a est égal à b

>>> %Run -c $EDITOR_CONTENT
True
False
True
>>> 

Opérateurs d'appartenance
-----------------------------
Les opérateurs d'appartenance sont utilisés pour tester si une séquence est présente dans un objet.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Opérateur
        - Description
    *   - ``in``
        - Retourne True si une séquence avec la valeur spécifiée est présente dans l'objet
    *   - ``not in``
        - Retourne True si une séquence avec la valeur spécifiée n'est pas présente dans l'objet

.. code-block:: python

    a = ["hello", "welcome", "Goodmorning"]

    print("welcome" in a)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

Opérateurs binaires
------------------------

Les opérateurs binaires sont utilisés pour comparer des nombres (binaires).

.. list-table:: 
    :widths: 10 20 50
    :header-rows: 1

    *   - Opérateur
        - Nom
        - Description
    *   - ``&``
        - ET
        - Met chaque bit à 1 si les deux bits sont à 1
    *   - ``|``
        - OU
        - Met chaque bit à 1 si l'un des deux bits est à 1
    *   - ``^``
        - XOR
        - Met chaque bit à 1 si seulement un des deux bits est à 1
    *   - ``~``
        - NOT
        - Inverse tous les bits
    *   - ``<<``
        - Décalage gauche avec remplissage de zéros
        - Décale à gauche en poussant des zéros depuis la droite et laisse tomber les bits les plus à gauche
    *   - ``>>``
        - Décalage droit signé
        - Décale à droite en poussant des copies du bit le plus à gauche depuis la gauche, et laisse tomber les bits les plus à droite

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