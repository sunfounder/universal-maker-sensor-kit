.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

Sketch Writing Rule
================================


If you ask a friend to turn on the lights for you, you can say "Turn on the lights.", or "Lights on, bro.", you can use any tone of voice you want.

However, if you want the Arduino board to do something for you, you need to follow the Arduino program writing rules to type in the commands.

This chapter contains the basic rules of the Arduino language and will help you understand how to translate natural language into code.

Of course, this is a process that takes time to get familiar with, and it is also the most error-prone part of the process for newbies, so if you make mistakes often, it's okay, just try a few more times.


Semicolon ``;``
---------------

Just like writing a letter, where you write a period at the end of each sentence as the end, the Arduino language requires you to use ``;`` to tell the board the end of the command.

Take the familiar "onboard LED blinking" example. A healthy sketch should look like this.

Example:

.. code-block:: C

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

Next, let's take a look at the following two sketches and guess if they can be correctly recognized by Arduino before running them.

Sketch A:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Sketch B:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

The result is that **Sketch A** reports an error and **Sketch B** runs.

* The errors in **Sketch A** are missing ``;`` and although it looks normal, the Arduino can't read it.
* **Sketch B**, looks anti-human, but in fact, indentation, line breaks and spaces in statements are things that do not exist in Arduino programs, so to the Arduino compiler, it looks the same as in the example.

However, please don't write your code as **Sketch B**, because it is usually natural people who write and view the code, so don't get yourself into trouble.


Curlybraces ``{}``
------------------

``{}`` is the main component of the Arduino programming language, and they must appear in pairs. 
A better programming convention is to insert a structure that requires curly braces by typing the right curly brace directly after typing the left curly brace, and then moving the cursor between the curly braces to insert the statement.



Comment ``//``
---------------

Comment is the part of the sketch that the compiler ignores. They are usually used to tell others how the program works.

If we write two adjacent slashes in a line of code, the compiler will ignore anything up to the end of the line.

If we create a new sketch, it comes with two comments, and if we remove these two comments, the sketch will not be affected in any way.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }


Comment is very useful in programming, and several common uses are listed below.

* Usage A: Tell yourself or others what this section of code does.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Set pin 13 to output mode, it controls the onboard LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Activate the onboard LED by setting pin 13 high
        delay(500); // Status quo for 500 ms
        digitalWrite(13,LOW); // Turn off the onboard LED
        delay(500);// Status quo for 500 ms
    }

* Usage B: Temporarily invalidate some statements (without deleting them) and uncomment them when you need to use them, so you don't have to rewrite them. This is very useful when debugging code and trying to locate program errors.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    Use the shortcut ``Ctrl+/`` to help you quickly comment or uncomment your code.

Comment ``/**/``
------------------

Same as ``//`` for comments. This type of comment can be more than one line long, and once the compiler reads ``/*``, it ignores anything that follows until it encounters ``*/``.

Example 1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        The following code will blink the onboard LED
        You can modify the number in delay() to change the blinking frequency
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

This is a useful C++ tool.

.. code-block:: C

    #define identifier token-string

The compiler automatically replaces ``identifier`` with ``token-string`` when it reads it, which is usually used for constant definitions.

As an example, here is a sketch that uses define, which improves the readability of the code.

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

To the compiler, it actually looks like this.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

We can see that the ``identifier`` is replaced and does not exist inside the program.
Therefore, there are several caveats when using it.

1. A ``token-string`` can only be modified manually and cannot be converted into other values by arithmetic in the program.

2. Avoid using symbols such as ``;``. For example.

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

The compiler will recognize it as the following, which is what will be reported as an error.

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    A naming convention for ``#define`` is to capitalize ``identifier`` to avoid confusion with variables.