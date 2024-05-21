.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

Arduino Program Structure
===========================

Let's take a look at the new sketch file. Although it has a few lines of code itself, it is actually an "empty" sketch. 
Uploading this sketch to the development board will cause nothing to happen.

.. code-block:: C

    void setup() {
    // put your setup code here, to run once:

    }

    void loop() {
    // put your main code here, to run repeatedly:

    }

If we remove ``setup()`` and ``loop()`` and make the sketch a real ``blank`` file, you will find that it does not pass the verification. 
They are the equivalent of the human skeleton, and they are indispensable.

During sketching, ``setup()`` is run first, and the code inside it (inside ``{}``) is run after the board is powered up or reset and only once. 
``loop()`` is used to write the main feature, and the code inside it will run in a loop after ``setup()`` is executed.

To better understand setup() and loop(), let's use four sketches. Their purpose is to make the on-board LED of the Arduino blink. Please run each experiment in turn and record their specific effects.

* Sketch 1: Make the on-board LED blink continuously.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Sketch 2: Make the on-board LED blink only once. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // put your main code here, to run repeatedly:
    }

* Sketch 3: Make the on-board LED blink slowly once and then blink quickly. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Sketch 4: Report an error.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // put your main code here, to run repeatedly:
    }    

With the help of these sketches, we can summarize several features of ``setup-loop``.

* ``loop()`` will be run repeatedly after the board is powered up. 
* ``setup()`` will run only once after the board is powered up. 
* After the board is powered up, ``setup()`` will run first, followed by ``loop()``. 
* The code needs to be written within the ``{}`` scope of ``setup()`` or ``loop()``, out of the framework will be an error.

.. note::  
    Statements such as ``digitalWrite(13,HIGH)`` are used to control the on-board LED, and we will talk about their usage in detail in later chapters.


