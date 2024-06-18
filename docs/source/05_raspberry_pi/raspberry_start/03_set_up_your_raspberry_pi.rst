.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _set_up_your_raspberry_pi:

Richten Sie Ihren Raspberry Pi ein
======================================

Wenn Sie einen Bildschirm haben
-----------------------------------

Wenn Sie einen Bildschirm haben, ist es einfach, auf dem Raspberry Pi zu arbeiten.

**Benötigte Komponenten**

* Any Raspberry Pi   
* 1 * Power Adapter
* 1 * Micro SD card
* 1 * Screen Power Adapter
* 1 * HDMI cable
* 1 * Screen
* 1 * Mouse
* 1 * Keyboard

#. Stecken Sie die SD-Karte, die Sie mit Raspberry Pi OS eingerichtet haben, in den Micro-SD-Kartensteckplatz an der Unterseite Ihres Raspberry Pi.

#. Schließen Sie die Maus und die Tastatur an.

#. Verbinden Sie den Bildschirm mit dem HDMI-Anschluss des Raspberry Pi und stellen Sie sicher, dass Ihr Bildschirm an eine Steckdose angeschlossen und eingeschaltet ist.

   .. note::
   
      Wenn Sie einen Raspberry Pi 4 verwenden, müssen Sie den Bildschirm an den HDMI0 (am nächsten am Stromanschluss) anschließen.

#. Verwenden Sie das Netzteil, um den Raspberry Pi mit Strom zu versorgen. Nach wenigen Sekunden wird der Desktop des Raspberry Pi OS angezeigt.

   .. image:: img/set_up_01.png
       :align: center
   
   .. raw:: html
   
       <br/>

#. Sie können einen Webbrowser auf Ihrem Raspberry Pi-System starten und diese Anleitung aufrufen. Dadurch können Sie Anweisungen bequem kopieren und im Terminal ausführen.

   .. image:: img/set_up_02.png
       :align: center
   
.. raw:: html
   
   <br/>

.. _no_screen:

Wenn Sie keinen Bildschirm haben
-------------------------------------

Wenn Sie keinen Monitor haben, können Sie sich remote bei Ihrem Raspberry Pi anmelden.

**Benötigte Komponenten**

* Jeder Raspberry Pi   
* 1 * Netzteil
* 1 * Micro-SD-Karte

Sie können das SSH-Kommando verwenden, um die Bash-Shell des Raspberry Pi zu öffnen, die die Standardoberfläche von Linux ist. Die Shell ermöglicht es Ihnen, die meisten Aufgaben mit einfachen Befehlen auf Unix/Linux-Systemen auszuführen.

Wenn Sie die Befehlszeile für Ihren Raspberry Pi lieber nicht verwenden möchten, können Sie die Remote-Desktop-Funktion nutzen, um die Desktop-Umgebung des Raspberry Pi ohne dedizierten Bildschirm zu bedienen.

Siehe unten für detaillierte Anleitungen für jedes System.


.. toctree::
   :maxdepth: 1

   03_a_remote_macosx
   03_b_remote_windows
   03_c_remote_linux

