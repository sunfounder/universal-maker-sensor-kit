.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

Quick Guide on Thonny
==================================

.. _open_run_code_py:

Open and Run Code Directly
---------------------------------------------

In each project we provide, the specific code used is clearly identified. You can find the corresponding code for each project in the ``universal-maker-sensor-kit-main/pico/`` directory.

However, you must first download the package and upload the library, as described in :ref:`add_libraries_py`.

#. Open code.

   For example, ``Lesson_01_Button_Module\01_button_module.py``.

   If you double click on it, a new window will open on the right. You can open more than one code at the same time.

   .. image:: img/05_open_code.png

#. Select correct interpreter

   Use a micro USB cable to connect the Pico W to your computer and select the "MicroPython (Raspberry Pi Pico)" interpreter.

   .. image:: img/05_sec_inter.png

#. Run the code

   To run the script, click the **Run current script** button or press F5.

   .. image:: img/05_run_it.png

   If the code contains any information that needs to be printed, it will appear in the Shell; otherwise, only the following information will appear.

   .. code-block:: shell

      >>> %Run -c $EDITOR_CONTENT

   Click **View** -> **Shell** to open the Shell window if it doesn't appear on your Thonny.

   * ``%Run -c $EDITOR_CONTENT`` is a command from Thonny telling the MicroPython interpreter on your Pico W to run the contents of the script area - "EDITOR_CONTENT".
   * If there is any message after that, it is usually the message that you tell MicroPython to print, or an error message for the code.

   .. raw:: html

      <br/>

#. Stop running

   .. image:: img/05_stop_it.png

   To stop the running code, click the **Stop/Restart backend** button. The **%RUN -c $EDITOR_CONTENT** command will disappear after stopping.

#. Save or save as

   You can save changes made to the open example by pressing **Ctrl+S** or clicking the **Save** button on Thonny.

   The code can be saved as a separate file within the Raspberry Pi Pico W by clicking on **File** -> **Save As**.

   .. image:: img/05_save_as.png

   Select **Raspberry Pi Pico**.

   .. image:: img/05_sec_pico.png

   Then click **OK** after entering the file name and extension **.py**. On the Raspberry Pi Pico W drive, you will see your saved file.

   .. image:: img/05_sec_name.png

   .. note::
       Regardless of what name you give your code, it's best to describe what type of code it is, and not give it a meaningless name like ``abc.py``.
       When you save the code as ``main.py``, it will run automatically when the power is turned on.


Create File and Run it
---------------------------


The code is shown directly in the code section. You can copy it to Thonny and run it as follows.

#. Create a new file

   Open Thonny IDE, click **New** button to create a new blank file.

   .. image:: img/new_file.png

#. Copy code

   Copy the code from the project to the Thonny IDE.

   For example:

   .. code:: python

      import machine
      import utime
      
      led = machine.Pin("LED", machine.Pin.OUT)
      while True:
          led.value(1)
          utime.sleep(2)
          led.value(0)
          utime.sleep(2)

   .. image:: img/05_2_copy_file.png

#. Select correct interpreter

   Plug the Pico W into your computer with a micro USB cable and select the "MicroPython (Raspberry Pi Pico)" interpreter in the bottom right corner.

   .. image:: img/05_2_sec_inter.png

#. Run the code

   You can click **Run Current Script** or simply press F5 to run it. 

   This code is designed to toggle the onboard LED of the Pico on and off every two seconds, creating a blinking effect. Once the code is executed, you will observe the corresponding blinking phenomenon.

   .. image:: img/05_2_run_it.png

#. Stop running

   To stop the code, click the **Stop/Restart backend** button. 
   
   .. image:: img/05_2_stop_it.png

#. Save the code

   You can click the **Save** button to save the code.

   .. image:: img/05_2_save_code.png

   Next, Thonny will ask you where to save the code. You can choose to save the code directly to Pico.

   .. image:: img/05_sec_pico.png

   Then click OK after entering the file name and extension .py. 

   .. image:: img/05_2_save_code_2.png

   .. note::
       Regardless of what name you give your code, it's best to describe what type of code it is, and not give it a meaningless name like ``abc.py``.
       When you save the code as ``main.py``, it will run automatically when the power is turned on.

#. Open file

   Here are two ways to open a saved code file.

   * The first method is to click the open icon on the Thonny toolbar, just like when you save a program, you will be asked if you want to open it from **this computer** or **Raspberry Pi Pico**, for example, click **Raspberry Pi Pico** and you will see a list of all the programs you have saved on the Pico W.

     .. image:: img/05_2_open_file.png

   * The second is to open the file preview directly by clicking **View**-> **File**-> and then double-clicking on the corresponding ``.py`` file to open it.

     .. image:: img/05_2_file_view.png

