 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!


Einführung in MicroPython
======================================

MicroPython ist eine Softwareimplementierung einer Programmiersprache, die weitgehend mit Python 3 kompatibel ist und in C geschrieben wurde. Sie ist optimiert, um auf einem Mikrocontroller ausgeführt zu werden.

MicroPython besteht aus einem Python-Compiler, der Bytecode erzeugt, und einem Laufzeitinterpreter für diesen Bytecode. Dem Benutzer wird ein interaktiver Prompt (REPL) präsentiert, um unterstützte Befehle sofort ausführen zu können. Enthalten sind eine Auswahl von Kern-Python-Bibliotheken; MicroPython umfasst Module, die dem Programmierer Zugriff auf hardwarenahe Funktionen bieten.

* Referenz: `MicroPython - Wikipedia <https://en.wikipedia.org/wiki/MicroPython>`_

Die Geschichte beginnt hier
--------------------------------

2013 änderte sich einiges, als Damien George eine Crowdfunding-Kampagne (Kickstarter) startete.

Damien war Student an der Universität Cambridge und leidenschaftlicher Programmierer im Bereich Robotik. Er wollte die Welt von Python von einer Gigabyte-Maschine auf ein Kilobyte reduzieren. Seine Kickstarter-Kampagne sollte seine Entwicklung unterstützen, während er seinen Proof of Concept in eine fertige Implementierung umsetzte.

MicroPython wird von einer vielfältigen Pythonista-Community unterstützt, die ein großes Interesse daran hat, dass das Projekt erfolgreich ist.

Neben dem Testen und Unterstützen der Code-Basis stellten die Entwickler Tutorials, Code-Bibliotheken und Hardware-Portierungen bereit, sodass Damien sich auf andere Aspekte des Projekts konzentrieren konnte.

* Referenz: `realpython <https://realpython.com/micropython/>`_

Warum MicroPython？
--------------------------

Obwohl die ursprüngliche Kickstarter-Kampagne MicroPython als Entwicklungsplatine "pyboard" mit STM32F4 veröffentlichte, unterstützt MicroPython viele ARM-basierte Produktarchitekturen. Die offiziell unterstützten Ports sind ARM Cortex-M (viele STM32-Boards, TI CC3200/WiPy, Teensy-Boards, Nordic nRF-Serie, SAMD21 und SAMD51), ESP8266, ESP32, 16-Bit-PIC, Unix, Windows, Zephyr und JavaScript.
Zweitens ermöglicht MicroPython ein schnelles Feedback. Dies liegt daran, dass Sie REPL verwenden können, um Befehle interaktiv einzugeben und Antworten zu erhalten. Sie können sogar Code anpassen und sofort ausführen, anstatt den Code-Kompilierungs-Upload-Ausführungszyklus durchlaufen zu müssen.

Obwohl Python dieselben Vorteile bietet, sind einige Mikrocontrollerplatinen wie das Raspberry Pi Pico klein, einfach und haben nur wenig Speicher, um die Python-Sprache überhaupt auszuführen. Deshalb hat sich MicroPython weiterentwickelt, indem es die wichtigsten Python-Funktionen beibehält und eine Reihe neuer Funktionen hinzufügt, um mit diesen Mikrocontrollerplatinen zu arbeiten.

Als Nächstes lernen Sie, MicroPython auf dem Raspberry Pi Pico zu installieren.
