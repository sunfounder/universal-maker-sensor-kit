 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Wie lädt man ein Sketch auf das Board hoch?
=============================================

In diesem Abschnitt lernen Sie, wie Sie das zuvor erstellte Sketch auf das Arduino-Board hochladen und einige wichtige Überlegungen dazu.

**1. Board und Port auswählen**

Arduino-Entwicklungsboards werden normalerweise mit einem USB-Kabel geliefert. Sie können es verwenden, um das Board mit Ihrem Computer zu verbinden.

Wählen Sie das richtige **Board** und den **Port** in der Arduino IDE aus. Normalerweise werden Arduino-Boards vom Computer automatisch erkannt und einem Port zugewiesen, sodass Sie es hier auswählen können.

    .. image:: img/board_port.png
        :width: 90%

Wenn Ihr Board bereits angeschlossen ist, aber nicht erkannt wird, überprüfen Sie, ob das **INSTALLED** Logo im Abschnitt **Arduino AVR Boards** des **Boards Managers** erscheint. Wenn nicht, scrollen Sie bitte etwas nach unten und klicken auf **INSTALL**.

    .. image:: img/upload1.png
        :width: 90%

Speziell für UNO R4 suchen Sie im **Boards Manager** nach **"UNO R4"** und überprüfen, ob die entsprechende Bibliothek installiert ist.

    .. image:: img/install_uno_r4_lib.png
        :width: 90%

Das erneute Öffnen der Arduino IDE und das erneute Anschließen des Arduino-Boards behebt die meisten Probleme. Sie können auch auf **Werkzeuge** -> **Board** oder **Port** klicken, um diese auszuwählen.

**2. Sketch überprüfen**

Nach dem Klicken auf die Schaltfläche **Überprüfen** wird das Sketch kompiliert, um zu sehen, ob Fehler vorliegen.

    .. image:: img/sp221014_174532.png
        :width: 90%

Sie können es verwenden, um Fehler zu finden, wenn Sie einige Zeichen löschen oder versehentlich einige Buchstaben eingeben. In der Nachrichtenleiste können Sie sehen, wo und welche Art von Fehlern aufgetreten sind.

    .. image:: img/sp221014_175307.png
        :width: 90%

Wenn keine Fehler vorliegen, sehen Sie eine Nachricht wie die folgende.

    .. image:: img/sp221014_175512.png
        :width: 90%

**3. Sketch hochladen**

Nach Abschluss der obigen Schritte klicken Sie auf die Schaltfläche **Hochladen**, um dieses Sketch auf das Board hochzuladen.

    .. image:: img/sp221014_175614.png
        :width: 90%

Wenn der Upload erfolgreich war, sehen Sie die folgende Aufforderung.

    .. image:: img/sp221014_175654.png
        :width: 90%

Gleichzeitig blinkt die On-Board-LED.

.. image:: img/1_led.jpg
    :width: 400
    :align: center

.. raw:: html
    
    <br/>

Das Arduino-Board führt das Sketch automatisch aus, nachdem die Stromversorgung angelegt wurde. Das laufende Programm kann durch das Hochladen eines neuen Sketches überschrieben werden.
