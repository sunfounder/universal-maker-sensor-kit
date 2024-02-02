.. _uno_lesson16_ds1306:

Lesson 16: Real Time Clock Module (DS1302)
==================================================

In this lesson, you will learn how to set up and use a Real Time Clock (RTC) module with an Arduino. We'll cover initializing the RTC DS1302 module, displaying the current date and time on the serial monitor, and ensuring accurate timekeeping. This session is ideal for those interested in time-based operations in embedded systems, offering hands-on experience with managing date and time settings, using RTC libraries, and troubleshooting common issues. This project is suitable for intermediate learners familiar with Arduino basics.

Required Components
---------------------------

* Arduino UNO R3 or R4
* :ref:`cpn_rtc_ds1302`

Wiring
---------------------------

.. image:: img/Lesson_16_DS1302_module_circuit_uno_bb.png
    :width: 100%


Code
---------------------------

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9b509afa-545f-4fb6-b8f0-0d87b7cf4992/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Code Analysis
---------------------------

#. Initialization and library inclusion

   .. note:: 
      To install the library, use the Arduino Library Manager and search for **"Rtc by Makuna"** and install it. 

   Here, necessary libraries are included for the DS1302 RTC module.

   .. code-block:: arduino

      #include <ThreeWire.h>
      #include <RtcDS1302.h>

#. Define pins and create RTC instance

   Pins for communication are defined and an instance of the RTC is created.

   .. code-block:: arduino

      const int IO = 4;    // DAT
      const int SCLK = 5;  // CLK
      const int CE = 2;    // RST

      ThreeWire myWire(4, 5, 2);  // IO, SCLK, CE
      RtcDS1302<ThreeWire> Rtc(myWire);


#. ``setup()`` function

   This function initializes the serial communication and sets up the RTC module. Various checks are made to ensure the RTC is running correctly.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
      
        Serial.print("compiled: ");
        Serial.print(__DATE__);
        Serial.println(__TIME__);
      
        Rtc.Begin();
      
        RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
        printDateTime(compiled);
        Serial.println();
      
        if (!Rtc.IsDateTimeValid()) {
          // Common Causes:
          //    1) first time you ran and the device wasn't running yet
          //    2) the battery on the device is low or even missing
      
          Serial.println("RTC lost confidence in the DateTime!");
          Rtc.SetDateTime(compiled);
        }
      
        if (Rtc.GetIsWriteProtected()) {
          Serial.println("RTC was write protected, enabling writing now");
          Rtc.SetIsWriteProtected(false);
        }
      
        if (!Rtc.GetIsRunning()) {
          Serial.println("RTC was not actively running, starting now");
          Rtc.SetIsRunning(true);
        }
      
        RtcDateTime now = Rtc.GetDateTime();
        if (now < compiled) {
          Serial.println("RTC is older than compile time!  (Updating DateTime)");
          Rtc.SetDateTime(compiled);
        } else if (now > compiled) {
          Serial.println("RTC is newer than compile time. (this is expected)");
        } else if (now == compiled) {
          Serial.println("RTC is the same as compile time! (not expected but all is fine)");
        }
      }


#. ``loop()`` function

   This function periodically fetches the current date and time from the RTC and prints it on the serial monitor. It also checks if the RTC is still maintaining a valid date and time.

   .. code-block:: arduino

      void loop() {
        RtcDateTime now = Rtc.GetDateTime();
      
        printDateTime(now);
        Serial.println();
      
        if (!now.IsValid()) {
          // Common Causes:
          //    1) the battery on the device is low or even missing and the power line was disconnected
          Serial.println("RTC lost confidence in the DateTime!");
        }
      
        delay(5000);  // five seconds
      }


#. Date and time printing function

   A helper function that takes a ``RtcDateTime`` object and prints the formatted date and time to the serial monitor.

   .. code-block:: arduino

      void printDateTime(const RtcDateTime& dt) {
        char datestring[20];
      
        snprintf_P(datestring,
                   countof(datestring),
                   PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
                   dt.Month(),
                   dt.Day(),
                   dt.Year(),
                   dt.Hour(),
                   dt.Minute(),
                   dt.Second());
        Serial.print(datestring);
      }