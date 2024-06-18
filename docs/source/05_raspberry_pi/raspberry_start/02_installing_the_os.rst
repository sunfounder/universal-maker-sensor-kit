 
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _install_os:

Raspberry Pi OS auf SD-Karte schreiben
========================================

**Schritt 1**

Das Raspberry Pi-Team bietet ein benutzerfreundliches grafisches SD-Karten-Schreibprogramm an, das mit Mac OS, Ubuntu 18.04 und Windows kompatibel ist. Dies ist die bequemste Option für die meisten Benutzer, da es das Betriebssystemabbild automatisch herunterlädt und auf die SD-Karte installiert.

Besuchen Sie die Download-Seite: https://www.raspberrypi.org/software/. Wählen Sie den **Raspberry Pi-Imager** für Ihr Betriebssystem aus. Sobald heruntergeladen, öffnen Sie es, um mit der Installation zu beginnen.

.. image:: img/installing_01.png
    :align: center

.. raw:: html

    <br/>

**Schritt 2**

Beim Starten des Installationsprogramms kann Ihr Betriebssystem eine Sicherheitswarnung anzeigen. Zum Beispiel zeigt Windows möglicherweise diese Meldung an:

.. image:: img/installing_02.png
    :align: center

.. raw:: html

    <br/>

Wenn Sie diese Warnung sehen, klicken Sie auf **Weitere Informationen** und wählen Sie dann **Trotzdem ausführen**. Fahren Sie fort, indem Sie den Anweisungen auf Ihrem Bildschirm folgen, um die Installation des Raspberry Pi-Imagers abzuschließen.


**Schritt 3**

Nach der Installation des Imagers öffnen Sie die Anwendung, indem Sie auf das Symbol **Raspberry Pi-Imager** klicken oder ``rpi-imager`` ausführen.

.. image:: img/installing_03.png
    :align: center

.. raw:: html

    <br/>

**Schritt 4**

Klicken Sie auf **Gerät auswählen** und wählen Sie Ihr Raspberry Pi-Modell aus der Liste aus.

.. image:: img/installing_04.png
    :align: center

.. raw:: html

    <br/>

**Schritt 5**

Klicken Sie anschließend auf **Betriebssystem auswählen** und wählen Sie ein Betriebssystem zur Installation aus.

.. image:: img/installing_05.png
    :align: center

.. raw:: html

    <br/>

**Schritt 6**

Legen Sie Ihr bevorzugtes Speichermedium, wie z. B. eine microSD-Karte, in ein externes oder integriertes SD-Kartenlesegerät ein. Klicken Sie anschließend auf "Speicher auswählen" und wählen Sie Ihr Gerät aus.

.. note:: 

   Stellen Sie sicher, dass Sie das richtige Speichergerät auswählen, wenn mehrere Geräte verbunden sind; sie können oft anhand ihrer Kapazität unterschieden werden. Wenn Sie unsicher sind, trennen Sie die anderen Geräte. Seien Sie sich bewusst, dass das Installieren des Systems auf dem ausgewählten Speichergerät alle Daten darauf löschen wird.

.. image:: img/installing_06.png
    :align: center

.. raw:: html

    <br/>

**Schritt 7**

Drücken Sie die **WEITER**-Taste und wählen Sie **EINSTELLUNGEN BEARBEITEN**, um auf die OS-Anpassungsseite zuzugreifen.

.. image:: img/installing_07.png
    :align: center

.. raw:: html

    <br/>

**Schritt 8**

Legen Sie den **Hostname** fest.

.. note::

   Die Hostname-Option definiert den Hostnamen, den Ihr Raspberry Pi über mDNS im Netzwerk aussendet. Durch die Verbindung Ihres Raspberry Pi mit dem Netzwerk ermöglicht es anderen Geräten, über ``<hostname>.local`` oder ``<hostname>.lan`` mit ihm zu interagieren.

.. image:: img/installing_08.png
    :align: center

.. raw:: html

    <br/>

Legen Sie den **Benutzernamen** und das **Passwort** für das Administrator-Konto des Raspberry Pi fest.

.. note::
   Das Raspberry Pi wird ohne Standardpasswort geliefert, daher ist es wichtig, eins festzulegen. Außerdem haben Sie die Möglichkeit, den Benutzernamen zu personalisieren.

.. image:: img/installing_09.png
    :align: center

.. raw:: html

    <br/>
    
Konfigurieren Sie das drahtlose LAN, indem Sie den **SSID** und das **Passwort** Ihres Netzwerks eingeben.

.. note::

   Konfigurieren Sie das "Land des drahtlosen LAN" mit dem Zwei-Buchstaben-|link_alpha2_code| Ihres Landes.

.. image:: img/installing_10.png
    :align: center

.. raw:: html

    <br/>

**Schritt 9**

Navigieren Sie zur **DIENSTE**-Seite, wählen Sie die Option **SSH aktivieren**, um SSH einzuschalten, und wählen Sie "Passwortauthentifizierung verwenden" (empfohlen für Anfänger). Klicken Sie auf **Speichern**, um Ihre Änderungen anzuwenden.

.. image:: img/installing_11.png
    :align: center

.. raw:: html

    <br/>

**Schritt 10**

Klicken Sie auf die Schaltfläche **Ja**.

.. image:: img/installing_12.png
    :align: center

.. raw:: html

    <br/>

**Schritt 11**

Wenn sich Dateien auf Ihrer SD-Karte befinden, sollten Sie in Betracht ziehen, diese zu sichern, um einen dauerhaften Verlust zu vermeiden. Wenn kein Backup erforderlich ist, klicken Sie auf **Ja**.

.. image:: img/installing_13.png
    :align: center

.. raw:: html

    <br/>

**Schritt 12**

Das folgende Fenster wird angezeigt, sobald der Schreibvorgang abgeschlossen ist. Der Schreibvorgang dauert einige Zeit und variiert je nach Lese-Schreib-Leistung der SD-Karte; bitte haben Sie Geduld.

.. image:: img/installing_14.png
    :align: center

.. raw:: html

    <br/>

