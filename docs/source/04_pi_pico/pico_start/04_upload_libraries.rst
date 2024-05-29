 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _add_libraries_py:

Bibliotheken auf den Pico hochladen
==============================================

In einigen Projekten werden zusätzliche Bibliotheken benötigt. Hier laden wir diese Bibliotheken zuerst auf den Raspberry Pi Pico W hoch, um den Code später direkt ausführen zu können.

#. Laden Sie den entsprechenden Code über den untenstehenden Link herunter.

   * :download:`SunFounder Universal Maker Sensor Kit <https://codeload.github.com/sunfounder/universal-maker-sensor-kit/zip/refs/heads/main>`

#. Öffnen Sie die Thonny-IDE und stecken Sie den Pico mit einem Micro-USB-Kabel an Ihren Computer an. Klicken Sie dann auf den Interpreter "MicroPython (Raspberry Pi Pico).COMXX" in der unteren rechten Ecke.

   .. image:: img/sec_inter.png

#. Klicken Sie in der oberen Navigationsleiste auf **Ansicht** -> **Dateien**.

   .. image:: img/th_files.png

#. Ändern Sie den Pfad zum Ordner, in dem Sie das `Code-Paket <https://codeload.github.com/sunfounder/universal-maker-sensor-kit/zip/refs/heads/main>`_ zuvor heruntergeladen haben, und gehen Sie dann zum Ordner ``universal-maker-sensor-kit-main/pico/libs``.

   .. image:: img/th_path.png

#. Wählen Sie alle Dateien oder Ordner im Ordner "libs/" aus (indem Sie Umschalt gedrückt halten und auf die erste und letzte Datei im Ordner klicken), klicken Sie dann mit der rechten Maustaste und wählen Sie **Hochladen nach /** aus. Es dauert eine Weile, bis der Upload abgeschlossen ist.

   .. image:: img/th_upload.png

#. Jetzt sehen Sie die Dateien, die Sie gerade auf Ihrem Laufwerk ``Raspberry Pi Pico`` hochgeladen haben.

   .. image:: img/th_done.png