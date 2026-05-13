.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Approfondissez vos connaissances sur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'expert** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Obtenez un accès anticipé aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

Variable
========

La variable est l'un des outils les plus puissants et essentiels dans un programme. Elle nous permet de stocker et de rappeler des données dans nos programmes.

Le fichier de sketch suivant utilise des variables. Il stocke les numéros des broches de la LED embarquée dans la variable ``ledPin`` et un nombre "500" dans la variable ``delayTime``.

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

Attendez, cela ne fait-il pas double emploi avec ce que fait ``#define`` ? La réponse est NON.

* Le rôle de ``#define`` est simplement de remplacer directement le texte, il n'est pas considéré par le compilateur comme faisant partie du programme.
* Une ``variable``, en revanche, existe dans le programme et sert à stocker et à rappeler des valeurs. Une variable peut également modifier sa valeur au sein du programme, ce qu'un define ne peut pas faire.

Le fichier de sketch ci-dessous ajoute lui-même à la variable et cela provoquera un clignotement plus long de la LED embarquée après chaque clignotement.

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
        delayTime = delayTime+200; // Chaque exécution augmente la valeur de 200
    }

Déclarer une variable
------------------------------------------

Déclarer une variable signifie créer une variable.

Pour déclarer une variable, vous avez besoin de deux choses : le type de données et le nom de la variable. Le type de données doit être séparé du nom de la variable par un espace, et la déclaration de la variable doit se terminer par un ``;``.

Prenons cette variable en exemple.

.. code-block:: C

    int delayTime;

**Type de données**

Ici ``int`` est un type de données appelé type entier, qui peut être utilisé pour stocker des entiers de -32768 à 32766. Il ne peut pas être utilisé pour stocker des décimales.

Les variables peuvent contenir différents types de données autres que les entiers. Le langage Arduino (qui est, rappelons-le, du C++) prend en charge quelques-uns d'entre eux (seuls les plus fréquemment utilisés et utiles sont répertoriés ici) :

* ``float`` : Stocke un nombre décimal, par exemple 3.1415926.
* ``byte`` : Peut contenir des nombres de 0 à 255.
* ``boolean`` : Ne contient que deux valeurs possibles, ``True`` ou ``False``, même s'il occupe un octet en mémoire.
* ``char`` : Contient un nombre de -127 à 127. Comme il est marqué comme un ``char``, le compilateur essaiera de le faire correspondre à un caractère de |link_ascii|.
* ``string`` : Peut stocker une chaîne de caractères, par exemple ``Halloween``.


**Nom de la variable**


Vous pouvez donner à la variable le nom que vous souhaitez, comme ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, mais il y a quelques règles de base à suivre.

1. décrire à quoi elle sert. Ici, j'ai nommé la variable delayTime, afin que vous puissiez facilement comprendre ce qu'elle fait. Ça irait si je nommais la variable ``barryAllen``, mais cela confondrait la personne qui regarde le code.

2. Utilisez une nomenclature régulière. Vous pouvez utiliser le CamelCase comme je l'ai fait, avec le T initial de ``delayTime`` pour qu'il soit facile de voir que la variable est composée de deux mots. Vous pouvez également utiliser le UnderScoreCase pour écrire la variable comme ``delay_time``. Cela n'affecte pas l'exécution du programme, mais cela aiderait le programmeur à lire le code si vous utilisez la nomenclature que vous préférez.

3. N'utilisez pas de mots-clés. De la même manière que lorsque nous tapons "int", l'IDE Arduino le colore pour vous rappeler que c'est un mot à usage spécial et qu'il ne peut pas être utilisé comme nom de variable. Changez le nom de la variable si elle est colorée.

4. Les symboles spéciaux ne sont pas autorisés. Par exemple, l'espace, #, $, /, +, %, etc. La combinaison de lettres anglaises (sensible à la casse), de soulignés et de chiffres (mais les chiffres ne peuvent pas être utilisés comme premier caractère d'un nom de variable) est assez riche.


**Attribuer une valeur à une variable**

Une fois que nous avons déclaré la variable, il est temps de stocker les données. Nous utilisons l'opérateur d'affectation (c'est-à-dire ``=``) pour mettre la valeur dans la variable.

Nous pouvons attribuer des valeurs à la variable dès que nous la déclarons.


.. code-block:: C

    int delayTime = 500;

Il est également possible de lui attribuer une nouvelle valeur à un moment donné.

.. code-block:: C

    int delayTime; // sans valeur
    delayTime = 500; // la valeur est 500
    delayTime = delayTime +200; // la valeur est 700
