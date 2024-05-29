 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Kommentare
=============

Kommentare im Code helfen uns, den Code zu verstehen, machen den gesamten Code lesbarer und ermöglichen das Auskommentieren von Teilen des Codes während des Testens, sodass dieser Teil des Codes nicht ausgeführt wird.

Einzeilige Kommentare
----------------------------

Einzeilige Kommentare in MicroPython beginnen mit #, und der folgende Text wird bis zum Ende der Zeile als Kommentar betrachtet. Kommentare können vor oder nach dem Code platziert werden.

.. code-block:: python

    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

Kommentare müssen nicht unbedingt Text sein, der den Code erklärt. Sie können auch Teile des Codes auskommentieren, um zu verhindern, dass MicroPython den Code ausführt.

.. code-block:: python

    #print("Can't run it！")
    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

Mehrzeilige Kommentare
------------------------------

Wenn Sie mehrere Zeilen kommentieren möchten, können Sie mehrere # Zeichen verwenden.

.. code-block:: python

    #This is a comment
    #written in
    #more than just one line
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

Oder Sie können mehrzeilige Zeichenketten verwenden.

Da MicroPython Zeichenfolgenliterale ignoriert, die nicht Variablen zugewiesen sind, können Sie mehrere Zeilen Zeichenketten (dreifache Anführungszeichen) zum Code hinzufügen und Kommentare darin schreiben:

.. code-block:: python

    """
    This is a comment
    written in
    more than just one line
    """
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

Solange die Zeichenkette nicht einer Variablen zugewiesen wird, ignoriert MicroPython sie nach dem Einlesen des Codes und behandelt sie, als hätten Sie einen mehrzeiligen Kommentar gemacht.
