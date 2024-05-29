 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _install_arduino:

Installation der Arduino IDE (Wichtig)
==============================================

Die Arduino IDE, bekannt als Arduino Integrated Development Environment, bietet alle Softwareunterstützungen, die für die Durchführung eines Arduino-Projekts erforderlich sind. Es handelt sich um eine speziell für Arduino entwickelte Programmiersoftware, die von dem Arduino-Team bereitgestellt wird und es uns ermöglicht, Programme zu schreiben und sie auf das Arduino-Board hochzuladen.

Die Arduino IDE 2.0 ist ein Open-Source-Projekt. Sie ist ein großer Schritt gegenüber ihrem soliden Vorgänger, der Arduino IDE 1.x, und kommt mit einer überarbeiteten Benutzeroberfläche, einem verbesserten Board- und Bibliotheksmanager, Debugger, Autovervollständigungsfunktion und vielem mehr.

In diesem Tutorial zeigen wir, wie man die Arduino IDE 2.0 auf einem Windows-, Mac- oder Linux-Computer herunterlädt und installiert.

Anforderungen
-------------------

* Windows - Win 10 and newer, 64 bits
* Linux - 64 bits
* Mac OS X - Version 10.14: "Mojave" or newer, 64 bits

Download der Arduino IDE 2.0
-------------------------------

#. Besuchen Sie |link_download_arduino|.

#. Laden Sie die IDE für Ihre Betriebssystemversion herunter.

   .. image:: img/install_ide_01.png

Installation
------------------------------

Windows
^^^^^^^^^^^^^

#. Doppelklicken Sie auf die heruntergeladene Datei ``arduino-ide_xxxx.exe``, um sie auszuführen.

#. Lesen Sie die Lizenzvereinbarung und stimmen Sie dieser zu.

   .. image:: img/install_ide_02.png

#. Wählen Sie die Installationsoptionen aus.

   .. image:: img/install_ide_03.png

#. Wählen Sie den Installationsort aus. Es wird empfohlen, die Software auf einem anderen Laufwerk als dem Systemlaufwerk zu installieren.

   .. image:: img/install_ide_04.png

#. Klicken Sie auf "Finish".

   .. image:: img/install_ide_05.png

macOS
^^^^^^^^^^^^^^^^

Doppelklicken Sie auf die heruntergeladene Datei ``arduino_ide_xxxx.dmg`` und folgen Sie den Anweisungen, um die **Arduino IDE.app** in den **Applications**-Ordner zu kopieren. Nach einigen Sekunden sehen Sie, dass die Arduino IDE erfolgreich installiert wurde.

.. image:: img/install_ide_macos.png
    :width: 100%

Linux
^^^^^^^^^^^^

Für das Tutorial zur Installation der Arduino IDE 2.0 auf einem Linux-System besuchen Sie bitte: https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux

Öffnen der IDE
-----------------

#. Beim ersten Öffnen der Arduino IDE 2.0 werden automatisch die Arduino AVR Boards, integrierte Bibliotheken und andere erforderliche Dateien installiert.

   .. image:: img/install_ide_06.png

#. Zusätzlich kann es vorkommen, dass Ihre Firewall oder Ihr Sicherheitscenter mehrmals fragt, ob Sie einige Gerätetreiber installieren möchten. Bitte installieren Sie alle.

   .. image:: img/install_ide_07.png

#. Jetzt ist Ihre Arduino IDE einsatzbereit!

   .. note::
       Falls einige Installationen aufgrund von Netzwerkproblemen oder anderen Gründen nicht funktioniert haben, können Sie die Arduino IDE erneut öffnen, und sie wird den Rest der Installation abschließen. Das Ausgabefenster wird nach Abschluss aller Installationen nicht automatisch geöffnet, es sei denn, Sie klicken auf "Verify" oder "Upload".
