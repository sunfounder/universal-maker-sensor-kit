 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_adafruit_io:

Lesson 48: Temperatur- und Feuchtigkeitsüberwachung mit Adafruit IO
============================================================================

In diesem Projekt zeigen wir Ihnen, wie Sie eine beliebte IoT-Plattform nutzen können. Es gibt viele kostenlose (oder kostengünstige) Plattformen, die online für Programmierbegeisterte verfügbar sind. Einige Beispiele sind Adafruit IO, Blynk, Arduino Cloud, ThingSpeak und so weiter. Die Nutzung dieser Plattformen ist ziemlich ähnlich. Hier werden wir uns auf Adafruit IO konzentrieren.

Wir schreiben ein Arduino-Programm, das den DHT11-Sensor verwendet, um Temperatur- und Feuchtigkeitswerte an das Dashboard von Adafruit IO zu senden. Außerdem können Sie eine LED auf der Schaltung über einen Schalter auf dem Dashboard steuern.

**Benötigte Komponenten**

In diesem Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_rgb`
        - \-
    *   - :ref:`cpn_dht11`
        - |link_dht11_humiture_buy|

**Einrichtung des Dashboards**

#. Besuchen Sie |link_adafruit_io| und klicken Sie auf **Start for free**, um ein kostenloses Konto zu erstellen.

    .. image:: img/sp230516_102503.png

#. Füllen Sie das Formular aus, um ein Konto zu erstellen.

    .. image:: img/sp230516_102629.png

#. Nachdem Sie ein Adafruit-Konto erstellt haben, müssen Sie Adafruit IO erneut öffnen. Klicken Sie auf **Dashboards** und dann auf **New Dashboard**.

    .. image:: img/sp230516_103347.png

#. Erstellen Sie ein **New Dashboard**.

    .. image:: img/sp230516_103744.png

#. Geben Sie das neu erstellte **Dashboard** ein und erstellen Sie einen neuen Block.

    .. image:: img/sp230516_104234.png

#. Erstellen Sie einen **Toggle**-Block.

    .. image:: img/sp230516_105727.png
#. Als nächstes müssen Sie hier einen neuen Feed erstellen. Dieser Toggle wird verwendet, um die LED zu steuern, und wir nennen diesen Feed "LED".

    .. image:: img/sp230516_105641.png

#. Überprüfen Sie den **LED**-Feed und gehen Sie zum nächsten Schritt.

    .. image:: img/sp230516_105925.png

#. Vervollständigen Sie die Blockeinstellungen (hauptsächlich Blocktitel, Ein-Text und Aus-Text), und klicken Sie dann unten rechts auf die Schaltfläche **Create block**, um den Vorgang abzuschließen.

    .. image:: img/sp230516_110124.png

#. Als nächstes müssen wir zwei **Textblöcke** erstellen. Diese werden verwendet, um Temperatur und Luftfeuchtigkeit anzuzeigen. Erstellen Sie daher zwei Feeds mit den Namen **temperature** und **humidity**.

    .. image:: img/sp230516_110657.png

#. Nach der Erstellung sollte Ihr Dashboard ungefähr so aussehen:

    .. image:: img/sp230516_111134.png

#. Sie können das Layout mithilfe der Option **Edit Layout** auf dem Dashboard anpassen.

    .. image:: img/sp230516_111240.png

#. Klicken Sie auf **API KEY**, und Sie sehen Ihren Benutzernamen und den **API KEY**. Notieren Sie sich diese, da Sie sie für Ihren Code benötigen.

    .. image:: img/sp230516_111641.png

**Code ausführen**

#. Bauen Sie die Schaltung auf.

    .. image:: img/Lesson_48_iot_adafruitio_bb.png

#. Verbinden Sie dann das ESP32 mit dem USB-Kabel mit dem Computer.

#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``Lesson_48_Adafruit_IO.ino`` im Verzeichnis ``universal-maker-sensor-kit\esp32\Lesson_48_Adafruit_IO``, oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf die Schaltfläche **Upload**.
    * :ref:`unknown_com_port`
    * Die ``Adafruit_MQTT Library`` und die ``DHT sensor library`` werden hier verwendet, Sie können sie im **Library Manager** installieren.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/987fb2fd-47e9-4a73-9020-6b2111eadd9c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Finden Sie die folgenden Zeilen und ersetzen Sie ``<SSID>`` und ``<PASSWORD>`` durch die spezifischen Details Ihres WiFi-Netzwerks.

    .. code-block::  Arduino

        /************************* WiFi Access Point *********************************/

        #define WLAN_SSID "<SSID>"
        #define WLAN_PASS "<PASSWORD>"

#. Ersetzen Sie dann ``<YOUR_ADAFRUIT_IO_USERNAME>`` durch Ihren Adafruit IO Benutzernamen und ``<YOUR_ADAFRUIT_IO_KEY>`` durch den **API KEY**, den Sie gerade kopiert haben.

    .. code-block::  Arduino

        // Adafruit IO Account Configuration
        // (to obtain these values, visit https://io.adafruit.com and click on Active Key)
        #define AIO_USERNAME "<YOUR_ADAFRUIT_IO_USERNAME>"
        #define AIO_KEY      "<YOUR_ADAFRUIT_IO_KEY>"

#. Wählen Sie das richtige Board (ESP32 Dev Module) und den entsprechenden Port aus und klicken Sie auf die Schaltfläche **Upload**.

#. Sobald der Code erfolgreich hochgeladen wurde, sehen Sie die folgende Meldung im seriellen Monitor, die eine erfolgreiche Kommunikation mit Adafruit IO anzeigt.

    .. code-block::

        Adafruit IO MQTTS (SSL/TLS) Example

        Connecting to xxxxx
        WiFi connected
        IP address: 
        192.168.18.76
        Connecting to MQTT... MQTT Connected!
        Temperature: 27.10
        Humidity: 61.00

#. Navigieren Sie zurück zu Adafruit IO. Jetzt können Sie die Temperatur- und Luftfeuchtigkeitsmessungen auf dem Dashboard beobachten oder den LED-Umschalter verwenden, um den Ein-/Ausschaltzustand der externen LED zu steuern, die an die Schaltung angeschlossen ist.

    .. image:: img/sp230516_143220.png
