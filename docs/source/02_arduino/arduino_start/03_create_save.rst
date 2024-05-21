.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

How to create, open or Save the Sketch?
=======================================


#. When you open the Arduino IDE for the first time or create a new sketch, you will see a page like this, where the Arduino IDE creates a new file for you, which is called a "sketch".

   .. image:: img/sp221014_173458.png

   These sketch files have a regular temporary name, from which you can tell the date the file was created. ``sketch_oct14a.ino`` means October 14th first sketch, ``.ino`` is the file format of this sketch.

#. Now let's try to create a new sketch. Copy the following code into the Arduino IDE to replace the original code.


   .. image:: img/create1.png

   .. code-block:: Arduino

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

#. Press ``Ctrl+S`` or click **File** -> **Save**. The Sketch is saved in: ``C:\Users\{your_user}\Documents\Arduino`` by default, you can rename it or find a new path to save it.

   .. image:: img/create2.png

#. After successful saving, you will see that the name in the Arduino IDE has been updated.

   .. image:: img/create3.png

Please continue with the next section to learn how to upload this created sketch to your Arduino board.