.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_esp32_wroom_32e:

ESP32-Board
=================

Das ESP32 ist ein leistungsstarker und vielseitiger Mikrocontroller mit Dual-Core-Verarbeitung, integriertem WLAN und Bluetooth sowie umfangreicher Unterstützung für Peripheriegeräte. Dank seines stromsparenden Designs eignet es sich hervorragend für kompakte und leistungsstarke IoT-Anwendungen.

.. image:: img/esp32_board.png
    :align: center


Zu den wichtigsten Funktionen gehören:

* **Rechenleistung**: Ausgestattet mit einem Dual-Core Xtensa® 32-Bit LX6 Mikroprozessor für hohe Skalierbarkeit und Flexibilität.
* **Drahtlose Kommunikation**: Mit integriertem 2,4-GHz-WLAN und Dual-Mode-Bluetooth eignet es sich ideal für Anwendungen mit stabiler drahtloser Kommunikation.
* **Speicher & Speicherplatz**: Verfügt über ausreichend SRAM und leistungsstarken Flash-Speicher für Benutzerprogramme und Datenspeicherung.
* **GPIO**: Unterstützt mit bis zu 38 GPIO-Pins eine Vielzahl externer Geräte und Sensoren.
* **Niedriger Stromverbrauch**: Mehrere Energiesparmodi machen das Board ideal für batteriebetriebene oder energieeffiziente Anwendungen.
* **Sicherheit**: Integrierte Verschlüsselungs- und Sicherheitsfunktionen schützen Benutzerdaten und Privatsphäre.
* **Vielseitigkeit**: Von einfachen Haushaltsgeräten bis hin zu komplexen Industriemaschinen bietet das Board zuverlässige und effiziente Leistung.

Zusammenfassend bietet das ESP32-Board nicht nur starke Rechenleistung und vielseitige Konnektivitätsoptionen, sondern auch zahlreiche Funktionen, die es zu einer bevorzugten Wahl im Bereich IoT und Smart Devices machen.

.. * |link_esp32_datasheet|

.. _esp32_pinout:

Pinbelegungsdiagramm
-------------------------

Das ESP32 weist einige Einschränkungen bei der Pin-Nutzung auf, da verschiedene Funktionen bestimmte Pins gemeinsam verwenden. Beim Entwurf eines Projekts empfiehlt es sich daher, die Pinbelegung sorgfältig zu planen und mögliche Konflikte zu überprüfen, um eine einwandfreie Funktion sicherzustellen.


.. image:: img/esp32_pinout.jpg
    :width: 800
    :align: center

Hier sind einige der wichtigsten Einschränkungen und Hinweise:

* **ADC1 und ADC2**: ADC2 kann nicht verwendet werden, wenn WLAN oder Bluetooth aktiv ist. ADC1 kann dagegen ohne Einschränkungen genutzt werden.
* **Bootstrap-Pins**: GPIO0, GPIO2, GPIO5, GPIO12 und GPIO15 werden während des Bootvorgangs verwendet. Externe Komponenten sollten diese Pins nicht beeinflussen.
* **JTAG-Pins**: GPIO12, GPIO13, GPIO14 und GPIO15 können für JTAG-Debugging genutzt werden. Falls kein JTAG-Debugging erforderlich ist, können sie als normale GPIOs verwendet werden.
* **Touch-Pins**: Einige Pins unterstützen Touch-Funktionen. Diese sollten entsprechend berücksichtigt werden, wenn Touch-Eingaben genutzt werden sollen.
* **Versorgungspins**: Einige Pins sind für die Stromversorgung reserviert und sollten entsprechend verwendet werden. Beispielsweise sollte kein übermäßiger Strom über 3V3- oder GND-Pins gezogen werden.
* **Nur-Eingangs-Pins**: Einige Pins unterstützen ausschließlich Eingaben und dürfen nicht als Ausgänge verwendet werden.

.. _esp32_strapping:

**Strapping-Pins**
--------------------------

Das ESP32 verfügt über fünf Strapping-Pins:

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Strapping-Pins
        - Beschreibung
    *   - IO5
        - Standardmäßig Pull-up aktiviert. Der Spannungspegel von IO5 und IO15 beeinflusst das Timing des SDIO-Slave.
    *   - IO0
        - Standardmäßig Pull-up aktiviert. Wird der Pin auf LOW gezogen, wechselt das ESP32 in den Download-Modus.
    *   - IO2
        - Standardmäßig Pull-down aktiviert. Wenn IO0 und IO2 gleichzeitig LOW sind, startet das ESP32 im Download-Modus.
    *   - IO12(MTDI)
        - Standardmäßig Pull-down aktiviert. Wird der Pin auf HIGH gesetzt, kann das ESP32 nicht normal booten.
    *   - IO15(MTDO)
        - Standardmäßig Pull-up aktiviert. Wird der Pin auf LOW gezogen, werden keine Debug-Protokolle angezeigt. Zusätzlich beeinflusst der Spannungspegel von IO5 und IO15 das Timing des SDIO-Slave.


Die Software kann die Werte dieser fünf Bits aus dem Register „GPIO_STRAPPING“ auslesen.

Während der Freigabe des System-Resets des Chips (Power-on-Reset, RTC-Watchdog-Reset und Brownout-Reset) erfassen die Latches der Strapping-Pins den Spannungspegel als Strapping-Bits „0“ oder „1“ und halten diese Werte, bis der Chip ausgeschaltet wird.

Diese Strapping-Bits konfigurieren den Boot-Modus des Geräts, die Betriebsspannung von VDD_SDIO und weitere anfängliche Systemeinstellungen.

Jeder Strapping-Pin ist während des Chip-Resets mit einem internen Pull-up oder Pull-down verbunden. Wenn ein Strapping-Pin nicht verbunden ist oder die externe Schaltung hochohmig ist, bestimmt der interne schwache Pull-up/Pull-down den Standardpegel.

Um die Strapping-Bit-Werte zu ändern, können Benutzer externe Pull-up-/Pull-down-Widerstände verwenden oder die GPIOs eines Host-Mikrocontrollers nutzen, um die Spannungspegel dieser Pins beim Einschalten zu steuern.

Nach dem Reset arbeiten die Strapping-Pins wieder als normale Funktionspins.
Eine detaillierte Boot-Modus-Konfiguration über die Strapping-Pins zeigt die folgende Tabelle.

.. image:: img/esp32_strapping.png

* FE: fallende Flanke, RE: steigende Flanke
* Die Firmware kann Registerbits konfigurieren, um die Einstellungen für die „Spannung des internen LDO (VDD_SDIO)“ und das „Timing des SDIO-Slave“ nach dem Bootvorgang zu ändern.
* Das Modul integriert einen 3,3-V-SPI-Flash, daher darf der Pin MTDI beim Einschalten des Moduls nicht auf 1 gesetzt werden.