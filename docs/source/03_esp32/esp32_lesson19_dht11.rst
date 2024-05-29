 .. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_lesson19_dht11:

Lektion 19: Temperatur- und Feuchtigkeitssensormodul (DHT11)
====================================================================

In dieser Lektion lernen Sie, wie Sie Temperatur und Feuchtigkeit mit einem DHT11-Sensor und einem ESP32-Entwicklungsboard auslesen. Wir werden auch besprechen, wie diese Messwerte interpretiert und der Hitzeindex sowohl in Celsius als auch in Fahrenheit berechnet werden. Dieses Projekt eignet sich ideal für Anfänger im Bereich der Umweltsensorik und bietet praktische Erfahrung im Erfassen von Sensordaten sowie grundlegende Konzepte der Klimamessung auf der ESP32-Plattform.

Benötigte Komponenten
--------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

Sie können sie auch einzeln über die unten stehenden Links kaufen.

.. list-table::
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_dht11`
        - |link_dht11_humiture_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|

Verdrahtung
---------------------------

.. image:: img/Lesson_19_DHT11_esp32_bb.png
    :width: 100%

Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **"DHT sensor library"** und installieren Sie sie.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/926830ca-9421-4852-ad72-ff75c1f10174/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

#. Einbindung der notwendigen Bibliotheken und Definition der Konstanten.
   Dieser Teil des Codes beinhaltet die DHT-Sensorbibliothek und definiert die verwendete Pinnummer und den Sensortyp für dieses Projekt.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **"DHT sensor library"** und installieren Sie sie.

   .. code-block:: arduino
    
      #include <DHT.h>
      #define DHTPIN 25       // Define the pin used to connect the sensor
      #define DHTTYPE DHT11  // Define the sensor type

#. Erstellung des DHT-Objekts.
   Hier erstellen wir ein DHT-Objekt mit der definierten Pinnummer und dem Sensortyp.

   .. code-block:: arduino

      DHT dht(DHTPIN, DHTTYPE);  // Create a DHT object

#. Diese Funktion wird einmal ausgeführt, wenn das ESP32-Entwicklungsboard startet. Wir initialisieren die serielle Kommunikation und den DHT-Sensor in dieser Funktion.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        Serial.println(F("DHT11 test!"));
        dht.begin();  // Initialize the DHT sensor
      }

#. Hauptschleife.
   Die ``loop()``-Funktion läuft kontinuierlich nach der Setup-Funktion. Hier lesen wir die Feuchtigkeits- und Temperaturwerte aus, berechnen den Hitzeindex und geben diese Werte im seriellen Monitor aus. Wenn das Auslesen des Sensors fehlschlägt (NaN zurückgibt), wird eine Fehlermeldung ausgegeben.

   .. note::
    
      Der |link_heat_index| ist eine Methode zur Messung, wie heiß es draußen durch die Kombination von Lufttemperatur und Feuchtigkeit ist. Er wird auch als "gefühlte Temperatur" oder "scheinbare Temperatur" bezeichnet.

   .. code-block:: arduino

      void loop() {
        delay(2000);
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        float f = dht.readTemperature(true);
        if (isnan(h) || isnan(t) || isnan(f)) {
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
        }
        float hif = dht.computeHeatIndex(f, h);
        float hic = dht.computeHeatIndex(t, h, false);
        Serial.print(F("Humidity: "));
        Serial.print(h);
        Serial.print(F("%  Temperature: "));
        Serial.print(t);
        Serial.print(F("°C "));
        Serial.print(f);
        Serial.print(F("°F  Heat index: "));
        Serial.print(hic);
        Serial.print(F("°C "));
        Serial.print(hif);
        Serial.println(F("°F"));
      }