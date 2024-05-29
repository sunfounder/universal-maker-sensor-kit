 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _burn_firmware:

Wie brennt man die AT-Firmware für das ESP8266-Modul neu?
==============================================================

Firmware mit R3 neu brennen
----------------------------------

**1. Schaltung aufbauen**

  Verbinden Sie das ESP8266 mit dem SunFounder R3 Board.

  .. image:: img/esp8266_connect_esp8266.png
      :width: 800

**2. Firmware brennen**

* Folgen Sie den untenstehenden Schritten, um die Firmware zu brennen, wenn Sie **Windows** verwenden.

  #. Laden Sie die Firmware und das Brennwerkzeug herunter.

     * :download:`ESP8266 Firmware <https://raw.githubusercontent.com/sunfounder/ultimate-sensor-kit/main/iot_project/esp8266_firmware.zip>`

  #. Nach dem Entpacken sehen Sie vier Dateien.

     .. .. image:: img/bat_firmware.png
 
     * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul gebrannt werden soll.
     * ``esptool.exe``: Ein Kommandozeilenprogramm für Windows.
     * ``install_r3.bat``: Das Befehls-Paket für Windows-Systeme, ein Doppelklick auf diese Datei führt alle Befehle im Inneren aus.
     * ``install_r4.bat``: Das gleiche wie ``install_r3.bat``, aber für das UNO R4 Board.

  #. Doppelklicken Sie auf ``install_r3.bat``, um das Firmware-Brennen zu starten. Wenn Sie die folgende Aufforderung sehen, wurde die Firmware erfolgreich installiert.

     .. image:: img/esp8266_install_firmware.png

     .. note::
         Wenn das Brennen fehlschlägt, überprüfen Sie bitte die folgenden Punkte.

         * Setzen Sie das ESP8266-Modul zurück, indem Sie den RST auf dem ESP8266-Adapter an GND anschließen und dann abziehen.
         * Überprüfen Sie, ob die Verdrahtung korrekt ist.
         * Stellen Sie sicher, dass der Computer Ihr Board richtig erkannt hat und der Port nicht belegt ist.
         * Öffnen Sie die install.bat-Datei erneut.

* Folgen Sie diesen Schritten, um die Firmware zu brennen, wenn Sie ein **Mac OS**-System verwenden.

  #. Verwenden Sie die folgenden Befehle, um Esptool zu installieren. Esptool ist ein Python-basiertes, plattformunabhängiges Open-Source-Programm, das mit dem ROM-Bootloader in Espressif-Chips kommuniziert.

     .. code-block::

         python3 -m pip install --upgrade pip
         python3 -m pip install esptool

  #. Wenn Esptool ordnungsgemäß installiert ist, wird eine Meldung wie [usage: esptool] ausgegeben, wenn Sie ``python3 -m esptool`` ausführen.

  #. Laden Sie die Firmware herunter.

     * :download:`ESP8266 Firmware <https://raw.githubusercontent.com/sunfounder/ultimate-sensor-kit/main/iot_project/esp8266_firmware.zip>`

  #. Nach dem Entpacken sehen Sie drei Dateien.

     .. image:: img/esp8266_bat_firmware.png

     * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul gebrannt werden soll.
     * ``esptool.exe``: Ein Kommandozeilenprogramm für Windows.
     * ``install_r3.bat``: Das Befehls-Paket für Windows-Systeme.
     * ``install_r4.bat``: Das gleiche wie ``install_r3.bat``, aber für das UNO R4 Board.

#. Öffnen Sie ein Terminal und verwenden Sie den ``cd``-Befehl, um in den gerade heruntergeladenen Firmware-Ordner zu wechseln. Führen Sie dann den folgenden Befehl aus, um die vorhandene Firmware zu löschen und die neue Firmware zu brennen.

   .. code-block::

      python3 -m esptool --chip esp8266 --before default_reset erase_flash
      python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

#. Wenn Sie die folgende Meldung sehen, wurde die Firmware erfolgreich installiert.

   .. image:: img/esp8266_install_firmware_macos.png

   .. note::
       Wenn das Brennen fehlschlägt, überprüfen Sie bitte die folgenden Punkte.

       * Setzen Sie das ESP8266-Modul zurück, indem Sie den RST auf dem ESP8266-Adapter an GND anschließen und dann abziehen.
       * Überprüfen Sie, ob die Verdrahtung korrekt ist.
       * Stellen Sie sicher, dass der Computer Ihr Board richtig erkannt hat und der Port nicht belegt ist.
       * Öffnen Sie die install.bat-Datei erneut.

**3. Testen**

#. Verbinden Sie IO1 mit 3V3 auf der Grundlage der ursprünglichen Verdrahtung.

   .. image:: img/esp8266_connect_esp826612.png
       :width: 800

#. Sie können Informationen über das ESP8266-Modul sehen, wenn Sie auf das Lupensymbol (Serial Monitor) in der oberen rechten Ecke klicken und die Baudrate auf **115200** einstellen.

   .. image:: img/esp8266_test_firmware_1.png

   .. note::

       * Wenn ``ready`` nicht erscheint, können Sie versuchen, das ESP8266-Modul zurückzusetzen (RST an GND anschließen) und den Serial Monitor erneut zu öffnen.

#. Klicken Sie auf **NEWLINE DROPDOWN BOX**, wählen Sie ``both NL & CR`` in der Dropdown-Option aus und geben Sie ``AT`` ein. Wenn ``OK`` zurückgegeben wird, bedeutet dies, dass das ESP8266 erfolgreich eine Verbindung mit dem R3-Board hergestellt hat.

   .. image:: img/esp8266_test_firmware_2.png

Nun können Sie dem Abschnitt :ref:`config_esp8266` folgen, um den Arbeitsmodus und die Baudrate des ESP8266-Moduls einzustellen.


Firmware mit R4 neu brennen
----------------------------------

**1. Schaltung aufbauen**

Verbinden Sie das ESP8266 mit dem Arduino UNO R4 Board.

    .. image:: img/esp8266_faq_at_burn_bb.jpg
        :width: 800

**2. Laden Sie den folgenden Code auf R4 hoch**

.. code-block:: Arduino

    void setup() {
        Serial.begin(115200);
        Serial1.begin(115200);
    }

    void loop() {
        if (Serial.available()) {      // If anything comes in Serial (USB),
            Serial1.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
        }
            if (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
            Serial.write(Serial1.read());   // read it and send it out Serial (USB)
        }
    }

**3. Firmware aufspielen**

* Folgen Sie den unten stehenden Schritten, um die Firmware auf einem **Windows**-System aufzuspielen.

  #. Laden Sie die Firmware und das Brennwerkzeug herunter.

     * :download:`ESP8266 Firmware <https://raw.githubusercontent.com/sunfounder/ultimate-sensor-kit/main/iot_project/esp8266_firmware.zip>`

  #. Nach dem Entpacken sehen Sie vier Dateien.

     .. .. image:: img/bat_firmware.png
 
     * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul aufgespielt wird.
     * ``esptool.exe``: Ein Kommandozeilenprogramm für Windows.
     * ``install_r3.bat``: Ein Befehlsprogramm für Windows. Ein Doppelklick auf diese Datei führt alle darin enthaltenen Befehle aus.
     * ``install_r4.bat``: Ähnlich wie ``install_r3.bat``, jedoch für das UNO R4-Board.

  #. Doppelklicken Sie auf ``install_r4.bat``, um das Firmware-Brennen zu starten. Wenn Sie die folgende Meldung sehen, wurde die Firmware erfolgreich installiert.

     .. image:: img/esp8266_install_firmware.png

     .. note::
         Wenn das Brennen fehlschlägt, überprüfen Sie bitte folgende Punkte:

         * Setzen Sie das ESP8266-Modul zurück, indem Sie den RST-Anschluss am ESP8266-Adapter auf GND setzen und dann trennen.
         * Überprüfen Sie, ob die Verdrahtung korrekt ist.
         * Stellen Sie sicher, dass Ihr Computer das Board richtig erkannt hat und der Port nicht belegt ist.
         * Öffnen Sie die install.bat-Datei erneut.

* Folgen Sie diesen Schritten, um die Firmware auf einem **Mac OS**-System aufzuspielen.

  #. Verwenden Sie die folgenden Befehle, um Esptool zu installieren. Esptool ist ein plattformunabhängiges, Python-basiertes Open-Source-Programm zur Kommunikation mit dem ROM-Bootloader in Espressif-Chips.

     .. code-block::

         python3 -m pip install --upgrade pip
         python3 -m pip install esptool

  #. Wenn Esptool korrekt installiert ist, wird eine Nachricht wie [usage: esptool] angezeigt, wenn Sie ``python3 -m esptool`` ausführen.

  #. Laden Sie die Firmware herunter.

     * :download:`ESP8266 Firmware <https://raw.githubusercontent.com/sunfounder/ultimate-sensor-kit/main/iot_project/esp8266_firmware.zip>`

  #. Nach dem Entpacken sehen Sie vier Dateien.

     .. .. image:: img/bat_firmware.png

     * ``BAT_AT_V1.7.1.0_1M.bin``: Die Firmware, die auf das ESP8266-Modul aufgespielt wird.
     * ``esptool.exe``: Ein Kommandozeilenprogramm für Windows.
     * ``install_r3.bat``: Ein Befehlsprogramm für Windows.
     * ``install_r4.bat``: Ähnlich wie ``install_r3.bat``, jedoch für das UNO R4-Board.

  #. Öffnen Sie ein Terminal und navigieren Sie mit dem ``cd``-Befehl in den Ordner, in dem sich die heruntergeladene Firmware befindet. Führen Sie dann die folgenden Befehle aus, um die bestehende Firmware zu löschen und die neue Firmware aufzuspielen.

     .. code-block::

         python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
         python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

  #. Wenn Sie die folgende Meldung sehen, wurde die Firmware erfolgreich installiert.

     .. image:: img/esp8266_install_firmware_macos.png

     .. note::
         Wenn das Brennen fehlschlägt, überprüfen Sie bitte folgende Punkte:

         * Setzen Sie das ESP8266-Modul zurück, indem Sie den RST-Anschluss am ESP8266-Adapter auf GND setzen und dann trennen.
         * Überprüfen Sie, ob die Verdrahtung korrekt ist.
         * Stellen Sie sicher, dass Ihr Computer das Board richtig erkannt hat und der Port nicht belegt ist.
         * Öffnen Sie die install.bat-Datei erneut.

**4. Test**

#. Verbinden Sie IO1 mit 3V3, basierend auf der ursprünglichen Verdrahtung.

   .. image:: img/esp8266_faq_at_burn_check_bb.jpg
       :width: 800

#. Wenn Sie auf das Lupensymbol (Serial Monitor) in der oberen rechten Ecke klicken und die Baudrate auf **115200** einstellen, können Sie Informationen über das ESP8266-Modul sehen.

   .. image:: img/esp8266_test_firmware_1.png

   .. note::

       * Wenn ``ready`` nicht erscheint, können Sie versuchen, das ESP8266-Modul zurückzusetzen (RST mit GND verbinden) und den Serial Monitor erneut zu öffnen.

#. Klicken Sie auf das **NEULINIEN-DROPDOWN-FELD**, wählen Sie im Dropdown-Menü ``both NL & CR`` aus, geben Sie ``AT`` ein. Wenn es mit OK antwortet, bedeutet das, dass das ESP8266 erfolgreich eine Verbindung mit dem R4-Board hergestellt hat.

   .. image:: img/esp8266_test_firmware_2.png

Jetzt können Sie mit :ref:`esp8266_start` fortfahren, um den Betriebsmodus und die Baudrate des ESP8266-Moduls einzustellen.
