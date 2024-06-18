.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _config_esp8266:

1.1 Konfiguration des ESP8266
===============================

Das ESP8266-Modul, das mit dem Kit geliefert wird, ist bereits mit der AT-Firmware vorgeflasht, aber Sie müssen die Konfiguration dennoch gemäß den folgenden Schritten ändern.

1. Bauen Sie die Schaltung auf.

   .. image:: img/wiring_r4_configure.png
       :width: 800

2. Öffnen Sie die Datei ``00-Set_software_serial.ino`` unter dem Pfad ``ultimate-sensor-kit\iot_project\wifi\00-Set_software_serial`` oder kopieren Sie diesen Code in die Arduino IDE und laden Sie den Code hoch.

   Der Code stellt eine Software-Serielle Kommunikation mithilfe der SoftwareSerial-Bibliothek von Arduino her, wodurch der Arduino über die digitalen Pins 2 und 3 (als Rx und Tx) mit dem ESP8266-Modul kommunizieren kann. Es überprüft den Datentransfer zwischen ihnen und leitet empfangene Nachrichten vom einen zum anderen mit einer Baudrate von 115200 weiter. **Mit diesem Code können Sie den seriellen Monitor von Arduino verwenden, um AT-Firmware-Befehle an das ESP8266-Modul zu senden und dessen Antworten zu empfangen.**

   .. code-block:: Arduino

       #include <SoftwareSerial.h>
       SoftwareSerial espSerial(2, 3); //Rx,Tx

       void setup() {
           // put your setup code here, to run once:
           Serial.begin(115200);
           espSerial.begin(115200);
       }

       void loop() {
           if (espSerial.available()) {
               Serial.write(espSerial.read());
           }
           if (Serial.available()) {
               espSerial.write(Serial.read());
           }
       }

3. Klicken Sie auf das Lupensymbol (Serial Monitor) in der oberen rechten Ecke und stellen Sie die Baudrate auf **115200** ein. (Es kann sein, dass einige gedruckte Informationen wie bei mir erscheinen oder auch nicht, das spielt keine Rolle, gehen Sie einfach zum nächsten Schritt.)

   .. image:: img/esp01_configurie_1.png

   .. warning::
        
        * Wenn ``ready`` nicht erscheint, können Sie versuchen, das ESP8266-Modul zurückzusetzen (RST mit GND verbinden) und den Serial Monitor erneut zu öffnen.

        * Wenn das Ergebnis ``OK`` lautet, müssen Sie möglicherweise die Firmware neu flashen. Weitere Informationen finden Sie unter :ref:`burn_firmware`. Wenn das Problem weiterhin besteht, machen Sie einen Screenshot des Serial Monitors und senden Sie ihn an service@sunfounder.com. Wir werden Ihnen so schnell wie möglich helfen.

4. Klicken Sie auf das **NEWLINE DROPDOWN BOX**, wählen Sie im Dropdown-Menü die Option ``both NL & CR``, geben Sie ``AT`` ein, und wenn es ``OK`` zurückgibt, bedeutet dies, dass das ESP8266 erfolgreich eine Verbindung zum R4-Board hergestellt hat.

   .. image:: img/esp01_configurie_2.png

   .. image:: img/esp01_configurie_3.png

5. Geben Sie ``AT+CWMODE=3`` ein, und der Betriebsmodus wird auf **Station und AP**-Koexistenz geändert.

   .. image:: img/esp01_configurie_4.png

.. 6. Um die Software-Serielle später verwenden zu können, müssen Sie ``AT+UART=9600,8,1,0,0`` eingeben, um die Baudrate des ESP8266 auf 9600 zu ändern.

..   .. image:: img/esp01_configurie_5.png


**Referenz**

* |link_esp8266_at|
