.. _uno_lesson30_relay_module:

Lesson 30: Relay Module
==================================

In this lesson, you will learn how to use a relay and an Arduino Uno to control a traffic light module. We'll demonstrate how to turn the red light of the traffic module on and off using the relay. This project is ideal for beginners in Arduino, providing hands-on experience in controlling external modules and gaining a fundamental understanding of relay operations.

Required Components
---------------------------

* Arduino UNO R3 or R4
* :ref:`cpn_breadboard`
* :ref:`cpn_relay`
* :ref:`cpn_traffic`


Wiring
---------------------------

.. image:: img/Lesson_30_relay_module_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/304bb1cc-7b9e-4290-b63a-baec5ed90521/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. Setting up the relay pin:

   - The relay module is connected to pin 6 of the Arduino. This pin is defined as ``relayPin`` for ease of reference in the code.

   .. raw:: html

      <br/>

   .. code-block:: arduino
    
      const int relayPin = 6;

#. Configuring the relay pin as an output:

   - In the ``setup()`` function, the relay pin is set as an OUTPUT using the ``pinMode()`` function. This means the Arduino will send signals (either HIGH or LOW) to this pin.

   .. raw:: html

      <br/>

   .. code-block:: arduino

      void setup() {
        pinMode(relayPin, OUTPUT);
      }

#. Toggling the relay ON and OFF:

   - In the ``loop()`` function, the relay is first set to the OFF state using ``digitalWrite(relayPin, LOW)``. It remains in this state for 3 seconds (``delay(3000)``).
   - Then, the relay is set to the ON state using ``digitalWrite(relayPin, HIGH)``. Again, it remains in this state for 3 seconds.
   - This cycle repeats indefinitely.

   .. raw:: html

      <br/>

   .. code-block:: arduino

      void loop() {
        digitalWrite(relayPin, LOW);
        delay(3000);

        digitalWrite(relayPin, HIGH);
        delay(3000);
      }