.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _connect_blynk:

1.4 Verbinden des R4-Boards mit Blynk
========================================

#. Verbinden Sie das ESP8266-Modul und das R4-Board erneut. Hier wird die Software-Seriell-Schnittstelle verwendet, daher sind TX und RX mit den Pins 2 und 3 des R4-Boards verbunden.

  .. note::

       Das ESP8266-Modul benötigt einen hohen Strom, um eine stabile Betriebsumgebung zu gewährleisten. Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.

  .. image:: img/wiring_r4_quickstart.png

#. Öffnen Sie die Datei ``00-Blynk_quick_start.ino`` unter dem Pfad ``ultimate-sensor-kit\iot_project\wifi\00-Blynk_quick_start`` oder kopieren Sie diesen Code in die **Arduino IDE**.

   .. raw:: html
       
       <iframe src=https://create.arduino.cc/editor/sunfounder01/421997b2-aaa7-45d7-926a-f0aec50db99a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die folgenden drei Codezeilen, die Sie von der **Geräteinfo**-Seite Ihres Kontos kopieren können. Diese drei Codezeilen ermöglichen es Ihrem R4-Board, Ihr Blynk-Konto zu finden.

   .. code-block:: arduino

       #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
       #define BLYNK_DEVICE_NAME "Device"
       #define BLYNK_AUTH_TOKEN "YourAuthToken"
   
   .. image:: img/sp20220614174721.png

#. Füllen Sie die ``ssid`` und das ``password`` des von Ihnen verwendeten WiFi aus.

   .. code-block:: arduino

       char ssid[] = "ssid";
       char pass[] = "password";

#. Laden Sie den Code auf das R4-Board hoch, öffnen Sie dann den seriellen Monitor und stellen Sie die Baudrate auf 115200 ein. Wenn das R4-Board erfolgreich mit Blynk kommuniziert, zeigt der serielle Monitor das Zeichen ``ready`` an.

   .. image:: img/sp220607_170223.png

   .. note::
   
       Wenn beim Verbinden die Meldung ``ESP is not responding`` erscheint, befolgen Sie bitte diese Schritte:

       * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
       * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST für 1 Sekunde mit GND verbinden und dann trennen.
       * Drücken Sie die Reset-Taste auf dem R4-Board.

       Manchmal müssen Sie den obigen Vorgang 3-5 Mal wiederholen, bitte haben Sie Geduld.

#. Der Status von Blynk ändert sich von **offline** zu **online**.

    .. image:: img/sp220607_170326.png
