 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Installation des ESP32-Boards (Wichtig)
=============================================

Um den ESP32-Mikrocontroller zu programmieren, müssen wir das ESP32-Board-Paket in der Arduino-IDE installieren. Folgen Sie der Schritt-für-Schritt-Anleitung unten:

**Installation des ESP32-Boards**

#. Öffnen Sie die Arduino-IDE. Gehen Sie zu **Datei** und wählen Sie **Voreinstellungen** aus dem Dropdown-Menü.

   .. image:: img/install_esp32_1.png

#. Im Voreinstellungsfenster finden Sie das Feld **Zusätzliche Boardverwalter-URLs**. Klicken Sie darauf, um das Textfeld zu aktivieren.

   .. image:: img/install_esp32_2.png

#. Fügen Sie die folgende URL in das Feld **Zusätzliche Boardverwalter-URLs** ein: https://espressif.github.io/arduino-esp32/package_esp32_index.json. Diese URL verweist auf die Paketindexdatei für die ESP32-Boards. Klicken Sie auf die **OK**-Schaltfläche, um die Änderungen zu speichern.

   .. image:: img/install_esp32_3.png

#. Geben Sie im **Boardverwalter**-Fenster **ESP32** in die Suchleiste ein. Klicken Sie auf die **Installieren**-Schaltfläche, um den Installationsprozess zu starten. Dies wird das ESP32-Board-Paket herunterladen und installieren.

   .. image:: img/install_esp32_4.png

#. Herzlichen Glückwunsch! Sie haben das ESP32-Board-Paket erfolgreich in der Arduino-IDE installiert. 

**Hochladen des Codes**

#. Verbinden Sie nun das ESP32 WROOM 32E mit Ihrem Computer über ein Micro-USB-Kabel.

   .. image:: img/plugin_esp32.png
       :width: 80%
       :align: center

#. Wählen Sie dann das richtige Board, **ESP32 Dev Module**, indem Sie auf **Werkzeuge** -> **Board** -> **esp32** klicken.

   .. image:: img/install_esp32_5.png
      :width: 100%

#. Wenn Ihr ESP32 mit dem Computer verbunden ist, können Sie den richtigen Port auswählen, indem Sie auf **Werkzeuge** -> **Port** klicken.

   .. image:: img/install_esp32_6.png
      :width: 100%

#. Zusätzlich hat Arduino 2.0 eine neue Methode eingeführt, um Board und Port schnell auszuwählen. Für ESP32 wird es normalerweise nicht automatisch erkannt, daher müssen Sie auf **Anderes Board und anderen Port auswählen** klicken.

   .. image:: img/install_esp32_7.png
      :width: 80%

#. Geben Sie im Suchfeld **ESP32 Dev Module** ein und wählen Sie es aus, wenn es erscheint. Wählen Sie dann den richtigen Port und klicken Sie auf **OK**.

   .. image:: img/install_esp32_8.png
      :width: 90%

#. Danach können Sie es über dieses Schnellzugriffsfenster auswählen. Beachten Sie, dass es bei der späteren Nutzung vorkommen kann, dass ESP32 im Schnellzugriffsfenster nicht verfügbar ist und Sie die oben genannten zwei Schritte wiederholen müssen.

   .. image:: img/install_esp32_9.png
      :width: 80%

#. Beide Methoden ermöglichen es Ihnen, das richtige Board und den richtigen Port auszuwählen, also wählen Sie die Methode, die Ihnen am besten passt. Nun ist alles bereit, um den Code auf den ESP32 hochzuladen.
