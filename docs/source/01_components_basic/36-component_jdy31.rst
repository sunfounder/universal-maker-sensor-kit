 .. _cpn_jdy31: .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

 


JDY-31 Bluetooth-Modul
=====================================

.. image:: img/36_JDY31_1.jpg
    :align: center

.. warning::
  Dieses Modul **unterstützt keine Apple-Geräte**-Verbindungen, daher erfordern Tutorials, die dieses Modul beinhalten, ein Android-Telefon oder -Tablet.

Das JDY-31 Bluetooth-Modul ist ein pin-kompatibler Ersatz für das HC-06 Bluetooth-Modul. Es ist einfacher und benutzerfreundlicher als das HC-06 und oft zu einem etwas günstigeren Preis erhältlich.

Das JDY-31 Bluetooth-Modul basiert auf dem Bluetooth 3.0 SPP-Design und kann die Datenübertragung unter Windows, Linux und Android unterstützen. Die Arbeitsfrequenz des JDY-31 Bluetooth-Moduls beträgt 2,4 GHz mit Modulationsmodus GFSK. Die maximale Sendeleistung beträgt 8 dB, und die maximale Übertragungsdistanz beträgt 30 Meter. Benutzer können den Gerätenamen, die Baudrate und andere Anweisungen über den AT-Befehl ändern.

Pins des JDY-31 und deren Funktionen:

.. image:: img/36_JDY31_2.jpg
    :align: center


.. list-table:: JDY-31 Pins
   :widths: 25 25 100
   :header-rows: 1

   * - Pin	
     - Name	
     - Beschreibung
   * - 1	
     - STATE
     - Verbindungsstatus-Pin (nicht verbunden niedriger Pegel, Ausgang hoher Pegel nach Verbindung) 
   * - 2	
     - RXD	
     - Empfangspin, dieser Pin muss mit dem TX-Pin des nächsten Geräts verbunden werden.
   * - 3	
     - TXD
     - Sendepin, dieser Pin muss mit dem RX-Pin des nächsten Geräts verbunden werden.
   * - 4		
     - GND
     - GND
   * - 5	
     - VCC
     - Stromversorgung (1,8-3,6V, 3,3V empfohlen)
   * - 6	
     - EN
     - Modul aktivieren oder deaktivieren. Wenn dieser Pin auf High gehalten wird, wird das Modul aktiviert und beginnt mit dem Senden und Empfangen von Daten.

Patsch-Anwendung: Für die allgemeine Anwendung müssen nur die Pins VCC, GND, RXD und TXD angeschlossen werden. Wenn Sie die Verbindung im Verbindungszustand aktiv trennen möchten, senden Sie AT+DISC im Verbindungszustand.

AT-Befehlssatz
---------------------------

+------------+-------------------------------------+-------------+
|   Befehl   |               Funktion              |   Standard  |
+============+=====================================+=============+
| AT+VERSION | Versionsnummer                      | JDY-31-V1.2 |
+------------+-------------------------------------+-------------+
| AT+RESET   | Software-Reset                      |             |
+------------+-------------------------------------+-------------+
| AT+DISC    | Trennen (gültig bei Verbindung)     |             |
+------------+-------------------------------------+-------------+
| AT+LADDR   | Abfrage der MAC-Adresse des Moduls  |             |
+------------+-------------------------------------+-------------+
| AT+PIN     | Verbindungspasswort setzen/abfragen | 1234        |
+------------+-------------------------------------+-------------+
| AT+BAUD    | Baudrate setzen/abfragen            | 9600        |
+------------+-------------------------------------+-------------+
| AT+NAME    | Broadcast-Name setzen/abfragen      | JDY-31-SPP  |
+------------+-------------------------------------+-------------+
| AT+DEFAULT | Werkseinstellungen                  |             |
+------------+-------------------------------------+-------------+
| AT+ENLOG   | Statusausgabe des seriellen Ports   | 1           |
+------------+-------------------------------------+-------------+

Beispiel
---------------------------
* :ref:`uno_lesson36_bluetooth` (Arduino UNO)
* :ref:`uno_bluetooth_lcd` (Arduino UNO)
* :ref:`uno_bluetooth_traffic_light` (Arduino UNO)
