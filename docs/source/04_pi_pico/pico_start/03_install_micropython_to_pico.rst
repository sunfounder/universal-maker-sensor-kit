.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _install_micropython_on_pico:

MicroPython auf Ihrem Pico installieren
=====================================================


Jetzt kommt die Installation von MicroPython auf den Raspberry Pi Pico. Die Thonny-IDE bietet Ihnen eine sehr bequeme Möglichkeit, es mit einem Klick zu installieren.

.. note::
    Sie können auch das |link_micropython_pi| verwenden, das von der offiziellen Raspberry Pi bereitgestellt wird, indem Sie eine ``rp2_pico_xxxx.uf2``-Datei per Drag & Drop auf den Raspberry Pi Pico ziehen und ablegen.



#. Öffnen Sie die Thonny-IDE.

   .. image:: img/set_pico1.png

#. Drücken und halten Sie die **BOOTSEL**-Taste und verbinden Sie dann den Pico über ein Micro-USB-Kabel mit dem Computer. Lassen Sie die **BOOTSEL**-Taste los, nachdem Ihr Pico als Massenspeichergerät namens **RPI-RP2** eingebunden ist.

   .. image:: img/bootsel_onboard.png
      :width: 70%
      :align: center

   .. raw:: html

      <br/>

#. Klicken Sie in der unteren rechten Ecke auf die Schaltfläche für die Interpreterauswahl und wählen Sie **Micropython installieren** aus.

   .. note::
      Wenn Ihre Thonny diese Option nicht hat, aktualisieren Sie bitte auf die neueste Version.

   .. image:: img/set_pico2.png

#. Im Abschnitt **Zielvolume** erscheint automatisch das Volume des gerade eingesteckten Pico. Wählen Sie im Abschnitt **Variante** **Raspberry Pi.Pico/Pico H** aus. Wählen Sie im Dropdown-Menü die neueste Version aus.

   .. image:: img/set_pico3.png

#. Klicken Sie auf die Schaltfläche **Installieren** und warten Sie, bis die Installation abgeschlossen ist.

   .. image:: img/set_pico4.png


#. Herzlichen Glückwunsch, Ihr Raspberry Pi Pico ist jetzt einsatzbereit.

   .. image:: img/set_pico5.png
