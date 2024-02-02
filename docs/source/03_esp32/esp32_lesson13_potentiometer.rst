.. _esp32_lesson13_potentiometer:

Lesson 13: Potentiometer Module
==================================

In this lesson, you'll learn how to read the analog value of a potentiometer with the ESP32 development board. We'll connect a potentiometer module to pin 25 and observe the changing analog values (0-4095) in the serial monitor. This project provides hands-on experience in understanding analog inputs and serial communication, making it an excellent exercise for beginners to explore the capabilities of the ESP32 board.

Required Components
---------------------------

* ESP32 Development Board
* :ref:`cpn_potentiometer`
* :ref:`cpn_breadboard`

Wiring
---------------------------

.. image:: img/Lesson_13_Potentiometer_Module_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/80644221-74b4-4df5-804e-236fdc4ab30e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. This line of code defines the pin number to which the potentiometer is connected on the ESP32 Development Board.

   .. code-block:: arduino

      const int sensorPin = 25;

#. The ``setup()`` function is a special function in Arduino that is executed only once when the ESP32 Development Board is powered on or reset. In this project, the ``Serial.begin(9600)`` command initiates serial communication at a baud rate of 9600.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);  
      }

#. The ``loop()`` function is the main function where the program runs repeatedly. In this function, the ``analogRead()`` function reads the analog value from the potentiometer and prints it to the serial monitor using ``Serial.println()``. The ``delay(50)`` command makes the program wait for 50 milliseconds before taking the next reading.

   .. code-block:: arduino

      void loop() {
        Serial.println(analogRead(sensorPin));  
        delay(50);
      }
