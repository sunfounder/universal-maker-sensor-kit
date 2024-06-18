
.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _uno_lesson35_esp8266:

Lektion 35: Einstieg in das ESP8266 Modul
===================================================

Das ESP8266-Modul, das mit dem Kit geliefert wird, ist bereits mit AT-Firmware vorprogrammiert, aber Sie müssen seine Konfiguration dennoch gemäß den folgenden Schritten ändern.


1. Bauen Sie die Schaltung auf.

   .. note::
      Um sicherzustellen, dass der ESP8266 eine stabile Spannung erhält, schließen Sie ihn bitte an eine externe Stromquelle wie die im Kit enthaltene 9V-Batterie an, indem Sie ihn mit dem Uno-Board verbinden.

   .. image:: img/Lesson_35_esp01_wiring_r3.png
       :width: 800

2. Öffnen Sie die ``.ino``-Datei unter dem Pfad ``universal-maker-sensor-kit\arduino_uno\Lesson_35_ESP8266``. Oder kopieren Sie diesen Code in die Arduino IDE und laden Sie den Code hoch.

   Der Code stellt eine Software-Seriell-Kommunikation mithilfe der SoftwareSerial-Bibliothek von Arduino her und ermöglicht es dem Arduino, über seine digitalen Pins 2 und 3 (als Rx und Tx) mit dem ESP8266-Modul zu kommunizieren. Er überprüft den Datentransfer zwischen ihnen und leitet empfangene Nachrichten mit einer Baudrate von 115200 weiter. **Mit diesem Code können Sie den seriellen Monitor von Arduino verwenden, um AT-Firmware-Befehle an das ESP8266-Modul zu senden und dessen Antworten zu empfangen.**

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


3. Klicken Sie auf das Lupensymbol (Serial Monitor) in der oberen rechten Ecke und stellen Sie die Baudrate auf **115200** ein. (Möglicherweise haben Sie einige gedruckte Informationen wie ich oder auch nicht. Das spielt keine Rolle, gehen Sie einfach zum nächsten Schritt.)

   .. image:: img/Lesson_35_esp01_configurie_1.png

   .. warning::
        
        * Wenn ``ready`` nicht erscheint, können Sie versuchen, das ESP8266-Modul zurückzusetzen (RST an GND anschließen) und den Serial Monitor erneut zu öffnen.

        * Wenn das Ergebnis ``OK`` ist, müssen Sie möglicherweise die Firmware neu brennen. Weitere Informationen finden Sie unter :ref:`burn_firmware`. Wenn Sie das Problem weiterhin nicht lösen können, machen Sie bitte einen Screenshot des Serial Monitors und senden Sie ihn an service@sunfounder.com. Wir werden Ihnen so schnell wie möglich helfen, das Problem zu lösen.

4. Klicken Sie auf das **NEWLINE DROPDOWN BOX**, wählen Sie ``both NL & CR`` in der Dropdown-Option, geben Sie ``AT`` ein. Wenn ``OK`` zurückgegeben wird, bedeutet dies, dass das ESP8266 erfolgreich eine Verbindung mit dem R4-Board hergestellt hat.

   .. image:: img/Lesson_35_esp01_configurie_2.png

   .. image:: img/Lesson_35_esp01_configurie_3.png

5. Geben Sie ``AT+CWMODE=3`` ein und der verwaltete Modus wird auf **Station und AP** geändert.

   .. image:: img/Lesson_35_esp01_configurie_4.png

.. 6. Um die Software-Seriell-Kommunikation später nutzen zu können, müssen Sie ``AT+UART=9600,8,1,0,0`` eingeben, um die Baudrate des ESP8266 auf 9600 zu ändern.

..    .. image:: img/esp01_configurie_5.png


**Referenz**

* |link_esp8266_at|