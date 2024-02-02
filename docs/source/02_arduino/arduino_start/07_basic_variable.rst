Variable
========

The variable is one of the most powerful and critical tools in a program. It helps us to store and call data in our programs.

The following sketch file uses variables. It stores the pin numbers of the on-board LED in the variable ``ledPin`` and a number "500" in the variable ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Wait, is this a duplicate of what ``#define`` does? The answer is NO.

* The role of ``#define`` is to simply and directly replace text, it is not considered by the compiler as part of the program. 
* A ``variable``, on the other hand, exists within the program and is used to store and call value. A variable can also modify its value within the program, something that a define cannot do.

The sketch file below self-adds to the variable and it will cause the on-board LED to blink longer after each blink.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime+200; //Each execution increments the value by 200
    }

Declare a variable
-------------------

Declaring a variable means creating a variable. 

To declare a variable, you need two things: the data type, and the variable name. The data type needs to be separated from the variable by a space, and the variable declaration needs to be terminated by a ``;``.

Let's use this variable as an example.

.. code-block:: C

    int delayTime;

**Data Type**

Here ``int`` is a data type called integer type, which can be used to store integers from -32768 to 32766. It can also not be used to store decimals.

Variables can hold different kinds of data other than integers. The Arduino language (which, remember, is C++) has built-in support for a few of them (only the most frequently used and useful are listed here):

* ``float``: Store a decimal number, for example 3.1415926.
* ``byte``: Can hold numbers from 0 to 255.
* ``boolean``: Holds only two possible values, ``True`` or ``False``, even though it occupies a byte in memory.
* ``char``: Holds a number from -127 to 127. Because it is marked as a ``char`` the compiler will try to match it to a character from the |link_ascii|.
* ``string``: Can stores a string of characters, e.g. ``Halloween``.


**Variable Name**


You can set the variable to any name you want, such as ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, but there are some basic rules to follow.

1. describe what it is used for. Here, I named the variable delayTime, so you can easily understand what it does. It works fine if I name the variable ``barryAllen``, but it confuses the person looking at the code.

2. Use regular nomenclature. You can use CamelCase like I did, with the initial T in ``delayTime`` so that it is easy to see that the variable consists of two words. Also, you can use UnderScoreCase to write the variable as ``delay_time``. It doesn't affect the program's running, but it would help the programmer to read the code if you use the nomenclature you prefer.

3. Don't use keywords. Similar to what happens when we type "int", the Arduino IDE will color it to remind you that it is a word with a special purpose and cannot be used as a variable name. Change the name of the variable if it is colored. 

4. Special symbols are not allowed. For example, space, #, $, /, +, %, etc. The combination of English letters (case sensitive), underscores, and numbers (but numbers cannot be used as the first character of a variable name) is rich enough.


**Assign a value to a variable**

Once we have declared the variable, it is time to store the data. We use the assignment operator (i.e. ``=``) to put value into the variable.

We can assign values to the variable as soon as we declare it.


.. code-block:: C

    int delayTime = 500;

It is also possible to assign a new value to it at some time.

.. code-block:: C

    int delayTime; // no value
    delayTime = 500; // value is 500
    delayTime = delayTime +200; // value is 700