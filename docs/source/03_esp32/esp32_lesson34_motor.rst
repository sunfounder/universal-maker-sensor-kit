.. _esp32_lesson34_motor:

Lesson 34: TT Motor
==================================

In this lesson, you'll learn how to control a motor with the ESP32 Development Board and an L9110 motor control board. We'll cover defining and initializing motor pins, setting them as outputs, and adjusting the motor's speed using the analogWrite function. This project is ideal for those seeking to grasp motor control and pulse-width modulation (PWM) on the ESP32 platform, providing a hands-on demonstration of output operations in a microcontroller environment.

Required Components
---------------------------

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - ESP32 Development Board
        - \-
    *   - :ref:`cpn_ttmotor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_34_Motor_esp32_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c1d4e7f5-140c-4ed4-a149-1af81df5dc0b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. The first part of the code defines the motor control pins. These are connected to the L9110 motor control board.

   .. code-block:: arduino
   
      // Define the motor pins
      const int motorB_1A = 26;
      const int motorB_2A = 25;

2. The ``setup()`` function initializes the motor control pins as output using the ``pinMode()`` function. Then it uses ``analogWrite()`` to set the speed of the motor. The value passed to ``analogWrite()`` can range from 0 (off) to 255 (full speed). A ``delay()`` function is then used to pause the code for 5000 milliseconds (or 5 seconds), after which the motor speed is set to 0 (off).

   .. code-block:: arduino
   
      void setup() {
        pinMode(motorB_1A, OUTPUT);  // set motor pin 1 as output
        pinMode(motorB_2A, OUTPUT);  // set motor pin 2 as output
   
        analogWrite(motorB_1A, 255);  // set motor speed (0-255)
        analogWrite(motorB_2A, 0);
   
        delay(5000);
   
        analogWrite(motorB_1A, 0);  
        analogWrite(motorB_2A, 0);
      }
