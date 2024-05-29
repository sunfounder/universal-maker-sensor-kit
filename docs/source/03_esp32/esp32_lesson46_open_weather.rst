 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_iot_owm:

Lesson 46: Echtzeit-Wetter von @OpenWeatherMap
====================================================

Das IoT Open Weather Display-Projekt nutzt das ESP32-Board und ein I2C LCD1602-Modul, um eine Wetterinformationsanzeige zu erstellen, die Daten von der OpenWeatherMap-API abruft.

Dieses Projekt ist eine hervorragende Einführung in die Arbeit mit APIs, Wi-Fi-Konnektivität und der Datenanzeige auf einem LCD-Modul mit dem ESP32-Board. Mit dem IoT Open Weather Display können Sie bequem in Echtzeit Wetteraktualisierungen auf einen Blick abrufen, was es zu einer idealen Lösung für Zuhause oder Büro macht.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten. 

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**OpenWeather API-Schlüssel erhalten**

|link_openweather| ist ein Online-Dienst von OpenWeather Ltd., der globale Wetterdaten über eine API bereitstellt, einschließlich aktueller Wetterdaten, Vorhersagen, Nowcasts und historischer Wetterdaten für jeden geografischen Standort.

#. Besuchen Sie |link_openweather|, um sich anzumelden oder ein Konto zu erstellen.

    .. image:: img/OWM-1.png

#. Klicken Sie in der Navigationsleiste auf die API-Seite.

    .. image:: img/OWM-2.png

#. Finden Sie **Aktuelle Wetterdaten** und klicken Sie auf Abonnieren.

    .. image:: img/OWM-3.png

#. Unter **Aktuelle Wetter- und Vorhersagesammlung** abonnieren Sie den entsprechenden Dienst. Für unser Projekt reicht das kostenlose Angebot aus.

    .. image:: img/OWM-4.png

#. Kopieren Sie den Schlüssel von der **API-Schlüssel**-Seite.

    .. image:: img/OWM-5.png

**Vervollständigen Sie Ihr Gerät**

#. Bauen Sie die Schaltung auf.

    .. image:: img/Lesson_26_LCD1602_esp32_bb.png
        :width: 800

#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``Lesson_46_OpenWeatherMap.ino`` im Verzeichnis ``universal-maker-sensor-kit\esp32\Lesson_46_OpenWeatherMap`` oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf die Schaltfläche **Upload**.
    * :ref:`unknown_com_port`
    * Die Bibliotheken ``LiquidCrystal I2C`` und ``Arduino_JSON`` werden hier verwendet und können über den **Library Manager** installiert werden.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/5e262afa-97ca-45ba-807b-adf7650b30e8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Suchen Sie die folgenden Zeilen und ändern Sie sie mit Ihrem ``<SSID>`` und ``<PASSWORD>``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "<SSID>";
        const char* password = "<PASSWORD>";

#. Fügen Sie die zuvor kopierten API-Schlüssel in ``openWeatherMapApiKey`` ein.

    .. code-block::  Arduino

        // Your Domain name with URL path or IP address with path
        String openWeatherMapApiKey = "<openWeatherMapApiKey>";

#. Ersetzen Sie dies durch Ihren Ländercode und Ihre Stadt.

    .. code-block::  Arduino

        // Replace with your country code and city
        // Fine the country code by https://openweathermap.org/find
        String city = "<CITY>";
        String countryCode = "<COUNTRY CODE>";

#. Nach dem Ausführen des Codes sehen Sie die Uhrzeit und Wetterinformationen Ihres Standorts auf dem I2C LCD1602.

.. note::
   Wenn der Code läuft und der Bildschirm leer bleibt, können Sie das Potentiometer auf der Rückseite des Moduls drehen, um den Kontrast zu erhöhen.
