.. _pi_lesson14_max30102:

Lesson 14: Pulse Oximeter and Heart Rate Sensor Module (MAX30102)
====================================================================

In this tutorial, you'll learn to operate the MAX30102 sensor using a Raspberry Pi, streamlined through the use of the open-source MAX30102 Python driver available on GitHub. This approach makes it easier to interface with the module, allowing you to focus on understanding the basics of sensor data collection and analysis. Ideal for novices, the project provides hands-on experience with sensor implementation and Python coding on the Raspberry Pi platform.

Required Components
--------------------------

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Universal Maker Sensor Kit
        - 94
        - |link_umsk|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 10
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_max30102`
        - |link_max30102_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_14_MAX30102_pi_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   from heartrate_monitor import HeartRateMonitor
   import time
   
   # Print a message indicating the sensor is starting
   print('sensor starting...')
   
   # Set the duration for which the sensor data will be read (in seconds)
   duration = 30
   
   # Initialize the HeartRateMonitor object
   # Set print_raw to False to avoid printing raw data
   # Set print_result to True to print the calculated results
   hrm = HeartRateMonitor(print_raw=False, print_result=True)
   
   # Start the heart rate sensor
   hrm.start_sensor()
   
   try:
       time.sleep(duration)
   except KeyboardInterrupt:
       print('keyboard interrupt detected, exiting...')
   
   # Stop the sensor after the duration has elapsed
   hrm.stop_sensor()
   
   # Print a message indicating the sensor has stopped
   print('sensor stopped!')



Code Analysis
---------------------------

#. Importing Modules

   - The ``heartrate_monitor`` module is used to interface with the sensor. For more information about the ``heartrate_monitor`` library, please visit |link_max30102_python_driver| .
   - The ``time`` module helps in managing the duration of the sensor data collection.

   .. raw:: html

      <br/>

   .. code-block:: python

      from heartrate_monitor import HeartRateMonitor
      import time

#. Initializing the Heart Rate Monitor

   - A ``HeartRateMonitor`` object is created with specific print options.
   - ``print_raw`` controls whether raw sensor data is printed.
   - ``print_result`` controls the printing of processed results (heart rate and SpO2).

   .. raw:: html

      <br/>

   .. code-block:: python

      hrm = HeartRateMonitor(print_raw=False, print_result=True)

#. Starting the Sensor

   The ``start_sensor`` method activates the heart rate sensor.

   .. code-block:: python

      hrm.start_sensor()

#. Running the Sensor for a Set Duration

   - The program sleeps for a specified duration, during which the sensor collects data.
   - ``time.sleep(duration)`` halts the program for the given number of seconds.

   .. raw:: html

      <br/>

   .. code-block:: python

      try:
          time.sleep(duration)
      except KeyboardInterrupt:
          print('keyboard interrupt detected, exiting...')

#. Stopping the Sensor

   After the duration, the ``stop_sensor`` method is called to stop data collection.

   .. code-block:: python

      hrm.stop_sensor()

#. Finalizing the Program

   Prints a message when the sensor stops.

   .. code-block:: python

      print('sensor stopped!')