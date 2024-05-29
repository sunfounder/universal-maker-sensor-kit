 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _install_blinka:

Installation von ``Adafruit_Blinka`` (CircuitPython) - Optional
====================================================================

Für ein verbessertes Erlebnis mit fortschrittlichen Modulen empfehlen wir die Verwendung der ``Adafruit_Blinka``-Bibliothek, einem zentralen Bestandteil der CircuitPython-Umgebung. Das Besondere an Blinka ist die Fähigkeit, Code, der für CircuitPython geschrieben wurde, nahtlos und mühelos auf Linux-Computern wie dem Raspberry Pi auszuführen.

Diese Bibliothek vereinfacht die Nutzung komplexer Module wie BMP280, VL53L0X und OLED und erleichtert somit den Entwicklungsprozess Ihrer Projekte. Mit CircuitPython wird das Programmieren zugänglicher, sodass Sie sich auf die Erstellung robuster Anwendungen konzentrieren können, ohne umfangreiche Hardwarekenntnisse zu benötigen.

Zusätzlich profitieren Sie von einer großen Support-Community und einer Vielzahl an Ressourcen, die Ihnen beim Lernen und Entwickeln helfen.

Wir werden Sie durch den einfachen Prozess der Installation von Adafruit_Blinka führen und Ihnen den Einstieg in Ihre Projekte erleichtern.


Aktualisierung Ihres Raspberry Pi und Python
-----------------------------------------------

Bevor Sie Blinka installieren, verwenden Sie bitte die folgenden Befehle, um sicherzustellen, dass Ihr Raspberry Pi und die Python-Versionen auf dem neuesten Stand sind:

.. code-block:: bash

   sudo apt-get update
   sudo apt-get upgrade


Einrichtung der virtuellen Umgebung
------------------------------------

Ab der Bookworm (OS-Version) müssen Pakete, die mit ``pip`` installiert werden, in einer Python-virtuellen Umgebung mittels ``venv`` installiert werden. Eine virtuelle Umgebung ist ein sicherer Container, in dem Sie Drittanbieter-Module installieren können, ohne das Python-System Ihrer Umgebung zu beeinträchtigen.

Der folgende Befehl erstellt ein Verzeichnis namens "env" in Ihrem Benutzerverzeichnis (``~``) für die virtuelle Python-Umgebung.

.. code-block:: bash
   
   cd ~
   python -m venv env --system-site-packages

Sie müssen die virtuelle Umgebung jedes Mal aktivieren, wenn der Pi neu gestartet wird. Um sie zu aktivieren:

.. code-block:: bash

   source env/bin/activate

Sie werden sehen, dass Ihr Prompt nun mit (env) versehen ist, um anzuzeigen, dass Sie nicht mehr das System-Python verwenden. Stattdessen nutzen Sie die Python-Version innerhalb Ihrer virtuellen Umgebung. Alle Änderungen, die Sie hier vornehmen, werden keine Probleme für Ihr System-Python verursachen, und alle neuen Module, die Sie in Ihre Umgebung installieren, werden isoliert.

.. image:: img/07_activate_env.png

Um die Umgebung zu deaktivieren, können Sie ``deactivate`` verwenden, lassen Sie sie jedoch vorerst aktiv.


Automatische Installation
-------------------------

Wenn die virtuelle Umgebung aktiviert ist (Sie sehen ``(env)`` am Anfang des Terminalbefehls), führen Sie die folgenden Befehle nacheinander aus. Dieser Code führt das von Adafruit bereitgestellte Installationsskript aus und schließt die restlichen Installationsschritte automatisch ab.

.. code-block:: bash

   pip3 install --upgrade adafruit-python-shell
   wget https://raw.githubusercontent.com/adafruit/Raspberry-Pi-Installer-Scripts/master/raspi-blinka.py
   sudo -E env PATH=$PATH python3 raspi-blinka.py

Es kann einige Minuten dauern, bis der Vorgang abgeschlossen ist. Wenn es fertig ist, werden Sie gefragt, ob Sie neu starten möchten. Drücken Sie direkt Enter, um neu zu starten, oder wenn Sie später neu starten möchten, geben Sie "n" ein und drücken dann Enter. Wenn Sie bereit sind, starten Sie Ihren Raspberry Pi manuell neu.

.. image:: img/07_after_install_blinka.png

Nach dem Neustart wird die Verbindung geschlossen. Nach ein paar Minuten können Sie sich erneut verbinden.

Blinka-Test
-----------------------

Erstellen Sie eine neue Datei namens ``blinkatest.py`` mit nano oder Ihrem bevorzugten Texteditor und fügen Sie Folgendes ein:

.. code-block:: python

   import board
   import digitalio
   import busio
   
   print("Hello blinka!")
   
   # Try to great a Digital input
   pin = digitalio.DigitalInOut(board.17)
   print("Digital IO ok!")
   
   # Try to create an I2C device
   i2c = busio.I2C(board.SCL, board.SDA)
   print("I2C ok!")
   
   # Try to create an SPI device
   spi = busio.SPI(board.SCLK, board.MOSI, board.MISO)
   print("SPI ok!")
   
   print("done!")

Bevor Sie den Code ausführen, stellen Sie bitte sicher, dass Sie die virtuelle Python-Umgebung mit installiertem Blinka aktiviert haben:

.. code-block:: bash

   source ~/env/bin/activate

Führen Sie dann den folgenden Befehl in der Befehlszeile aus:

.. code-block:: bash

   python blinkatest.py

Sie sollten Folgendes sehen, was darauf hinweist, dass Digital I/O, I2C und SPI alle funktionieren.

.. image:: img/07_check_blinka.png


Referenz
-----------------------

- |link_adafruit_blinka_guide|

- |link_python_on_raspberry_pi|