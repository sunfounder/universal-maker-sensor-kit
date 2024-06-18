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

ESP32 WROOM 32E
=================

Das ESP32 WROOM-32E ist ein vielseitiges und leistungsstarkes Modul, das auf dem ESP32-Chipsatz von Espressif basiert. Es bietet Dual-Core-Verarbeitung, integrierte Wi-Fi- und Bluetooth-Konnektivität und eine Vielzahl von Peripherieschnittstellen. Dank seines niedrigen Stromverbrauchs ist das Modul ideal für IoT-Anwendungen geeignet und ermöglicht intelligente Konnektivität und robuste Leistung in kompakten Formfaktoren.

.. image:: img/esp32_wroom_32e.png
    :width: 60%
    :align: center

Zu den wichtigsten Merkmalen gehören:

* **Verarbeitungsleistung**: Ausgestattet mit einem Dual-Core Xtensa® 32-Bit LX6 Mikroprozessor, der Skalierbarkeit und Flexibilität bietet.
* **Drahtlose Fähigkeiten**: Mit integriertem 2,4 GHz Wi-Fi und Dual-Mode-Bluetooth ist es perfekt für Anwendungen geeignet, die stabile drahtlose Kommunikation erfordern.
* **Speicher und Speicherung**: Es verfügt über reichlich SRAM und Hochleistungs-Flash-Speicher, um den Anforderungen an Benutzerprogramme und Datenspeicherung gerecht zu werden.
* **GPIO**: Mit bis zu 38 GPIO-Pins unterstützt es eine Vielzahl von externen Geräten und Sensoren.
* **Niedriger Stromverbrauch**: Verschiedene Energiesparmodi machen es ideal für batteriebetriebene oder energieeffiziente Szenarien.
* **Sicherheit**: Integrierte Verschlüsselungs- und Sicherheitsfunktionen gewährleisten den Schutz von Benutzerdaten und die Privatsphäre.
* **Vielseitigkeit**: Von einfachen Haushaltsgeräten bis hin zu komplexen industriellen Maschinen bietet das WROOM-32E konstante, effiziente Leistung.

Zusammenfassend lässt sich sagen, dass das ESP32 WROOM-32E nicht nur robuste Verarbeitungsfähigkeiten und vielfältige Konnektivitätsoptionen bietet, sondern auch eine Reihe von Funktionen, die es zu einer bevorzugten Wahl im IoT- und Smart-Device-Bereich machen.

* |link_esp32_datasheet|

.. _esp32_pinout:

Pinout Diagramm
-------------------------

Der ESP32 hat einige Pin-Nutzungsbeschränkungen, da verschiedene Funktionen bestimmte Pins gemeinsam nutzen. Bei der Projektplanung ist es ratsam, die Pin-Nutzung sorgfältig zu planen und mögliche Konflikte zu überprüfen, um ein einwandfreies Funktionieren zu gewährleisten und Probleme zu vermeiden.

.. image:: img/esp32_pinout.jpg
    :width: 100%
    :align: center

Hier sind einige der wichtigsten Einschränkungen und Überlegungen:

* **ADC1 und ADC2**: ADC2 kann nicht verwendet werden, wenn WiFi oder Bluetooth aktiv ist. ADC1 kann jedoch uneingeschränkt genutzt werden.
* **Bootstrap-Pins**: GPIO0, GPIO2, GPIO5, GPIO12 und GPIO15 werden während des Bootvorgangs zum Bootstrapping verwendet. Es ist darauf zu achten, keine externen Komponenten an diese Pins anzuschließen, die den Bootvorgang stören könnten.
* **JTAG-Pins**: GPIO12, GPIO13, GPIO14 und GPIO15 können als JTAG-Pins für Debugging-Zwecke verwendet werden. Wenn kein JTAG-Debugging erforderlich ist, können diese Pins als normale GPIOs genutzt werden.
* **Touch-Pins**: Einige Pins unterstützen Touch-Funktionen. Diese Pins sollten sorgfältig verwendet werden, wenn sie für die Touch-Erkennung vorgesehen sind.
* **Stromversorgungspins**: Einige Pins sind für strombezogene Funktionen reserviert und sollten entsprechend verwendet werden. Beispielsweise sollte kein übermäßiger Strom von Stromversorgungspins wie 3V3 und GND gezogen werden.
* **Nur-Eingabe-Pins**: Einige Pins sind nur als Eingänge konfiguriert und sollten nicht als Ausgänge verwendet werden.

.. _esp32_strapping:

Strapping Pins
--------------------------

Der ESP32 hat fünf Strapping-Pins:

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Strapping-Pins
        - Beschreibung
    *   - IO5
        - Standardmäßig Pull-up, die Spannung an IO5 und IO15 beeinflusst das Timing des SDIO-Slave.
    *   - IO0
        - Standardmäßig Pull-up, wenn auf Low gezogen, wechselt es in den Download-Modus.
    *   - IO2
        - Standardmäßig Pull-down, IO0 und IO2 schalten den ESP32 in den Download-Modus.
    *   - IO12(MTDI)
        - Standardmäßig Pull-down, wenn auf High gezogen, kann der ESP32 nicht normal starten.
    *   - IO15(MTDO)
        - Standardmäßig Pull-up, wenn auf Low gezogen, ist das Debug-Log nicht sichtbar. Außerdem beeinflusst die Spannung an IO5 und IO15 das Timing des SDIO-Slave.

Die Software kann die Werte dieser fünf Bits aus dem Register "GPIO_STRAPPING" auslesen. Während der Freigabe des System-Reset des Chips (Power-on-Reset, RTC-Watchdog-Reset und Brownout-Reset) erfassen die Latches der Strapping-Pins den Spannungspegel als Strapping-Bits "0" oder "1" und halten diese Bits, bis der Chip ausgeschaltet wird. Die Strapping-Bits konfigurieren den Boot-Modus des Geräts, die Betriebsspannung von VDD_SDIO und andere anfängliche Systemeinstellungen.

Jeder Strapping-Pin ist während des Chip-Reset mit seinem internen Pull-up/Pull-down verbunden. Wenn ein Strapping-Pin unverbunden ist oder die angeschlossene externe Schaltung hochohmig ist, bestimmt der interne schwache Pull-up/Pull-down den Standard-Eingangspegel der Strapping-Pins.

Um die Werte der Strapping-Bits zu ändern, können Benutzer externe Pull-down/Pull-up-Widerstände anlegen oder die GPIOs des Host-MCUs verwenden, um den Spannungspegel dieser Pins beim Einschalten des ESP32 zu steuern.

Nach der Freigabe des Resets funktionieren die Strapping-Pins als normale Funktionspins. Die folgende Tabelle zeigt eine detaillierte Boot-Modus-Konfiguration durch Strapping-Pins.

.. image:: img/esp32_strapping.png
   :width: 100%
   :align: center

* FE: fallende Flanke, RE: steigende Flanke
* Die Firmware kann Registerbits konfigurieren, um die Einstellungen von "Spannung des internen LDO (VDD_SDIO)" und "Timing des SDIO-Slave" nach dem Booten zu ändern.
* Das Modul integriert einen 3,3 V SPI-Flash, daher kann der Pin MTDI beim Einschalten des Moduls nicht auf 1 gesetzt werden.
