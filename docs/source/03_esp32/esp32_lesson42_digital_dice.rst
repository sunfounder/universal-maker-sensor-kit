.. note::

   Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

   **Warum beitreten?**

   - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
   - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
   - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
   - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
   - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

   👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _esp32_digital_dice:

Lektion 42: Digitaler Würfel
=============================================================

Dieses Programm simuliert einen Würfelwurf mithilfe eines OLED-Displays. 
Die Simulation wird durch Schütteln des Vibrationssensors ausgelöst, wodurch das Display die Zahlen von 1 bis 6 durchläuft, 
ähnlich wie beim Würfeln. 
Das Display stoppt nach einer kurzen Zeit und zeigt eine zufällig ausgewählte Zahl an, die das Würfelergebnis darstellt.

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 & Development Board
        - |link_esp32_camera_pro_kit_buy|
    *   - :ref:`cpn_vibration`
        - |link_sw420_vibration_module_buy|
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
        

Verdrahtung
---------------------------

.. image:: img/Lesson_42_Digital_dice_esp32_bb.png
    :width: 100%


Code
---------------------------

.. note:: 
   Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager, suchen Sie nach **"Adafruit SSD1306"** und **"Adafruit GFX"** und installieren Sie sie.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f3c250f6-c5f6-4dc9-906a-a5a914741fe3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code-Analyse
---------------------------

Eine umfassende Analyse des Codes:

1. Initialisierung der Variablen:

    ``vibPin``: Digitaler Pin, der mit dem Vibrationssensor verbunden ist.

    .. code-block:: arduino

        const int vibPin = 35;    // The pin where the vib switch is connected

2. Volatile Variablen:

    ``rolling``: Ein volatiles Flag, das den Status des Würfelwurfs anzeigt. Es ist volatil, da es sowohl in der Interrupt-Service-Routine als auch im Hauptprogramm verwendet wird.

    .. code-block:: arduino

        volatile bool rolling = false;

3. ``setup()``:

    Konfiguriert den Eingang des Vibrationssensors.
    Weist dem Sensor einen Interrupt zu, um die Funktion rollDice bei einer Zustandsänderung auszulösen.
    Initialisiert das OLED-Display.

    .. code-block:: arduino

        void setup() {
            // Initialize pins
            pinMode(vibPin, INPUT);  

            // initialize the OLED object
            if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
                Serial.println(F("SSD1306 allocation failed"));
                for (;;)
                ;
            }

            // Attach an interrupt to the vibPin. When the vib switch is activated, the shakeDetected function will be called
            attachInterrupt(digitalPinToInterrupt(vibPin), rollDice, CHANGE);
        }



4. ``loop()``:

    Überprüft kontinuierlich, ob ``rolling`` wahr ist, und zeigt während dieses Zustands eine Zufallszahl zwischen 1 und 6 an. Das Rollen endet, wenn der Sensor länger als 500 Millisekunden geschüttelt wurde.

    .. code-block:: arduino

        void loop() {
            // Check if it's rolling
            if (rolling) {
                byte number = random(1, 7);  // Generate a random number between 1 and 6
                displayNumber(number);
                delay(80);  // Delay to make the rolling effect visible

                // Stop rolling after 1 second
                if ((millis() - lastShakeTime) > 1000) {
                    rolling = false;
                }
            }
        }

5. ``rollDice()``:

    Die Interrupt-Service-Routine für den Vibrationssensor. Sie initiiert den Würfelwurf, wenn der Sensor geschüttelt wird, indem die aktuelle Zeit aufgezeichnet wird.

    .. code-block:: arduino

        // Interrupt handler for shake detection
        void rollDice() {
            if (digitalRead(vibPin) == LOW) {
                lastShakeTime = millis();  // Record the time of shake
                rolling = true;            // Start rolling
            }
        }


6. ``displayNumber()``:

    Zeigt eine ausgewählte Zahl auf dem OLED-Bildschirm an.

    .. code-block:: arduino

        // Function to display a number on the 7-segment display
        void displayNumber(byte number) {
            display.clearDisplay();  // Clear the screen

            // Display Text
            display.setTextSize(4);       // Set text size
            display.setTextColor(WHITE);  // Set text color
            display.setCursor(54, 20);     // Set cursor position
            display.println(number);
            display.display();  // Display the content on the screen

        }
