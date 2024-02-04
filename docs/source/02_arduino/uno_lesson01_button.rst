.. _uno_lesson01_button:

Lesson 01: Button Module
==================================

In this lesson, you will learn how a button interacts with an LED using Arduino. We'll see how pressing the button lights up the LED and releasing it turns off the LED. This project is ideal for beginners as it provides a practical understanding of input and output operations on the Arduino platform.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Arduino UNO R3 or R4
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_button`
        - \-
        

Wiring
---------------------------

.. image:: img/Lesson_01_Button_Module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2249707e-73aa-400b-8141-15424c291f44/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. Initialization of Pins

   The pins for the button and LED are defined and initialized. The ``buttonPin`` is set as an input to read the button's state, and ``ledPin`` is set as an output to control the LED.

   .. note::
      Most Arduino boards have a pin connected to an on-board LED in series with a resistor. The constant ``LED_BUILTIN`` is the number of the pin to which the on-board LED is connected. Most boards have this LED connected to digital pin 13.
   
   .. code-block:: arduino

      const int buttonPin = 12;        // Pin number for the button
      const int ledPin = LED_BUILTIN;  // Pin number for the LED
      int buttonState = 0;  // Variable to hold the current state of the button

#. Setup Function

   This function runs once and sets up the pin modes. ``pinMode(buttonPin, INPUT)`` configures the button pin as an input. ``pinMode(ledPin, OUTPUT)`` sets the LED pin as an output.
   
   .. code-block:: arduino

      void setup() {
        pinMode(buttonPin, INPUT);  // Initialize buttonPin as an input pin
        pinMode(ledPin, OUTPUT);    // Initialize ledPin as an output pin
      }

#. Main Loop Function

   This is the core of the program where the button state is continuously read and the LED state is controlled. ``digitalRead(buttonPin)`` reads the button's state. If the button is pressed (state is LOW), the LED is turned on by ``digitalWrite(ledPin, HIGH)``. If not pressed, the LED is turned off (``digitalWrite(ledPin, LOW)``).

   The :ref:`button module<cpn_button>` used in this project has an internal pull-up resistor (see its :ref:`schematic diagram<cpn_button_sch>`), causing the button to be at a low level when pressed and remain at a high level when released.
   
   .. code-block:: arduino

      void loop() {
        // Read the current state of the button
        buttonState = digitalRead(buttonPin);

        // Check if the button is pressed (LOW)
        if (buttonState == LOW) {
          digitalWrite(ledPin, HIGH);  // Turn the LED on
        } else {
          digitalWrite(ledPin, LOW);  // Turn the LED off
        }
      }
