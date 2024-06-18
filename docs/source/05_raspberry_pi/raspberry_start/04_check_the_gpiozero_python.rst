.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Überprüfen Sie das ``GPIO Zero``
=====================================

``GPIO Zero`` ist ein Modul zur Steuerung der GPIO-Pins des Raspberry Pi. Dieses Paket bietet eine Reihe benutzerfreundlicher Klassen und Funktionen zur Steuerung der GPIO auf einem Raspberry Pi. Für Beispiele und Dokumentation besuchen Sie: https://gpiozero.readthedocs.io/en/latest/.

Das neueste Raspberry Pi OS enthält standardmäßig GPIO Zero. Um die Installation zu überprüfen, öffnen Sie das Terminal und geben Sie ein:

.. code-block::

    python

.. image:: img/zero_01.png
    :width: 100%


Geben Sie anschließend ``import gpiozero`` innerhalb der Python-CLI ein. Wenn keine Fehlermeldungen erscheinen, ist GPIO Zero erfolgreich installiert.

.. code-block::

    import gpiozero

.. image:: img/zero_02.png
    :width: 100%


Wenn Sie die Python-CLI beenden möchten, geben Sie ein:

.. code-block::

    exit()

.. image:: img/zero_03.png
    :width: 100%


