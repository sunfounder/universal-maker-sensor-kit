.. _uno_lesson28_rgb_module:

Lesson 28: RGB LED Module
==================================

In this lesson, you will learn how to control an RGB LED with Arduino. We'll cover setting up the LED and then delve into displaying primary colors and creating a vibrant rainbow spectrum. This hands-on project is ideal for beginners, providing practical experience with output operations and color mixing in the Arduino environment.

Required Components
---------------------------

* Arduino UNO R3 or R4
* :ref:`cpn_rgb`

Wiring
---------------------------

.. image:: img/Lesson_28_rgb_module_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/69d51b96-ad16-4c16-aa97-6dab559929d3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

1. The first segment of the code declares and initializes the pins to which each color channel of the RGB LED module is connected.

   .. code-block:: arduino
       
      const int rledPin = 9;  // pin connected to the red color channel
      const int gledPin = 10;   // pin connected to the green color channel
      const int bledPin = 11;  // pin connected to the blue color channel

2. The ``setup()`` function initializes these pins as OUTPUT. This means we are sending signals OUT from these pins to the RGB LED module.

   .. code-block:: arduino
   
      void setup() {
        pinMode(rledPin, OUTPUT);
        pinMode(gledPin, OUTPUT);
        pinMode(bledPin, OUTPUT);
      }

3. In the ``loop()`` function, the ``setColor()`` function is called with different parameters to display different colors. The ``delay()`` function is used after setting each color to pause for 1000 milliseconds (or 1 second) before moving on to the next color.

   .. code-block:: arduino
   
      void loop() {
        setColor(255, 0, 0);  // Set RGB LED color to red
        delay(1000);
        setColor(0, 255, 0);  // Set RGB LED color to green
        delay(1000);
        // The rest of the color sequence...
      }

4. The ``setColor()`` function uses the ``analogWrite()`` function to adjust the brightness of each color channel on the RGB LED module. The ``analogWrite()`` function employs Pulse Width Modulation (PWM) to simulate varying voltage outputs. By controlling the PWM duty cycle (the percentage of time a signal is HIGH within a fixed period), the brightness of each color channel can be controlled, allowing the mixing of various colors.

   .. code-block:: arduino

      void setColor(int R, int G, int B) {
        analogWrite(rledPin, R);  // Use PWM to control the brightness of the red color channel
        analogWrite(gledPin, G);  // Use PWM to control the brightness of the green color channel
        analogWrite(bledPin, B);  // Use PWM to control the brightness of the blue color channel
      }