.. _pi_lesson18_ds18b20:

Lesson 18: Temperature Sensor Module (DS18B20)
================================================

In this lesson, you will learn how to use a Raspberry Pi to read temperature data from a DS18B20 temperature sensor. You will understand how to locate the sensor's device file, read and parse its raw data, and convert this data into Celsius and Fahrenheit readings. 

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
    :widths: 30 20
    :header-rows: 1

    *   - Component Introduction
        - Purchase Link

    *   - Raspberry Pi 5
        - \-
    *   - :ref:`cpn_ds18b20`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_18_DS18B20_pi_bb.png
    :width: 100%


Code
---------------------------

.. note::
   The DS18B20 module communicates with the Raspberry Pi using the onewire protocol. Before running the code, you need to enable the onewire function of the Raspberry Pi. You can refer to this tutorial: :ref:`pi_enable_1wire`. 

.. code-block:: python

   import glob
   import time
   
   # Path to the directory containing device files for 1-wire devices
   base_dir = "/sys/bus/w1/devices/"
   
   # Finds the first device folder that starts with "28", specific to DS18B20
   device_folder = glob.glob(base_dir + "28*")[0]
   
   # Device file containing the temperature data
   device_file = device_folder + "/w1_slave"
   
   
   def read_temp_raw():
       # Reads raw temperature data from the sensor
       f = open(device_file, "r")
       lines = f.readlines()
       f.close()
       return lines
   
   
   def read_temp():
       # Parses the raw temperature data and converts it to Celsius and Fahrenheit
       lines = read_temp_raw()
       # Waits for a valid temperature reading
       while lines[0].strip()[-3:] != "YES":
           time.sleep(0.2)
           lines = read_temp_raw()
       equals_pos = lines[1].find("t=")
       if equals_pos != -1:
           temp_string = lines[1][equals_pos + 2 :]
           temp_c = float(temp_string) / 1000.0  # Convert to Celsius
           temp_f = temp_c * 9.0 / 5.0 + 32.0  # Convert to Fahrenheit
           return temp_c, temp_f
   
   
   try:
       # Main loop to continuously read and print temperature
       while True:
           temp_c, temp_f = read_temp()
           formatted_output = f"Temperature: {temp_c:.2f}°C / {temp_f:.2f}°F"
           print(formatted_output)
           time.sleep(1)  # Wait for 1 second between readings
   except KeyboardInterrupt:
       # Gracefully exit the program on CTRL+C
       print("Exit")




Code Analysis
---------------------------

#. Importing Necessary Libraries

   The ``glob`` library is used to search for the temperature sensor's device folder. The ``time`` library is used for implementing delays in the program.

   .. code-block:: python

      import glob
      import time

#. Locating the Temperature Sensor Device File

   The code searches for the directory of the DS18B20 sensor by looking for a folder name starting with "28". The device file ``w1_slave`` contains the temperature data.

   .. code-block:: python

      base_dir = "/sys/bus/w1/devices/"
      device_folder = glob.glob(base_dir + "28*")[0]
      device_file = device_folder + "/w1_slave"

#. Reading Raw Temperature Data

   This function opens the device file and reads its content. It returns the raw temperature data as a list of strings.

   .. code-block:: python

      def read_temp_raw():
          f = open(device_file, "r")
          lines = f.readlines()
          f.close()
          return lines

#. Parsing and Converting Temperature Data

   The ``read_temp`` function calls ``read_temp_raw`` to get the raw data. It waits for a valid temperature reading and then extracts, parses, and converts the temperature to Celsius and Fahrenheit.

   .. code-block:: python

      def read_temp():
          lines = read_temp_raw()
          while lines[0].strip()[-3:] != "YES":
              time.sleep(0.2)
              lines = read_temp_raw()
          equals_pos = lines[1].find("t=")
          if equals_pos != -1:
              temp_string = lines[1][equals_pos + 2 :]
              temp_c = float(temp_string) / 1000.0
              temp_f = temp_c * 9.0 / 5.0 + 32.0
              return temp_c, temp_f

#. Main Program Loop and Graceful Exit

   The ``try`` block contains an infinite loop to continuously read and display the temperature. The ``except`` block catches a KeyboardInterrupt to exit the program gracefully.

   .. code-block:: python

      try:
          while True:
              temp_c, temp_f = read_temp()
              formatted_output = f"Temperature: {temp_c:.2f}°C / {temp_f:.2f}°F"
              print(formatted_output)
              time.sleep(1)
      except KeyboardInterrupt:
          print("Exit")