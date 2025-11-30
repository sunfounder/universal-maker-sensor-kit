How to download and run the Code
=================================

Downloading Code to Your Raspberry Pi
-------------------------------------

Before downloading the code, please be aware that the example code has been tested **ONLY** on the latest version of **Raspberry Pi OS**. We offer two download methods:

If you're not accessing your Raspberry Pi with a direct screen connection, consider utilizing remote access options. For detailed guidance, refer to the instructions in :ref:`no_screen`.


**Method 1: Using Git Clone (Recommended)**

1. Log into your Raspberry Pi, open Terminal, and navigate to the home directory (``~``). (You can also access the terminal using SSH.)

   .. code-block:: bash

      cd ~

   .. image:: img/quick_guide_01.png
       :width: 100%

   .. note::

      Use the ``cd`` command to change directories. Here, ``~/`` denotes the home directory.

2. Clone the GitHub repository.

   .. code-block:: bash

      git clone https://github.com/sunfounder/universal-maker-sensor-kit.git

   .. image:: img/quick_guide_02.png
       :width: 100%
   
   .. raw:: html

      <br/><br/>

3. Use File Manager to access the downloaded code files.

   .. image:: img/quick_guide_03.png
       :width: 100%

**Method 2: Downloading Code Directly from GitHub**

1. Open a web browser and go to https://github.com/sunfounder/universal-maker-sensor-kit, then click on the download button.

   .. image:: img/quick_guide_04.png

2. Once downloaded, locate the code file in ``File Manager > Downloads`` and unzip it into the ``/home/pi`` directory.

   .. image:: img/quick_guide_05.png

3. Navigate to the ``/home/pi`` directory to access the extracted code files.

   .. image:: img/quick_guide_06.png


Opening and Running Code
------------------------

You can find the code for each project in its respective code section. Alternatively, you can locate the code in the provided code directory. For instance, in ``universal-maker-sensor-kit/raspberry_pi/``, you will find Lesson 1's code named ``01_button_module.py``.

There are two ways to run Python code below：

**Method 1: Using Geany**

1. Open the code file by double-clicking on it.

   .. image:: img/quick_guide_07.png

   Alternatively, right-click the file and select **Open With...**.

   .. image:: img/quick_guide_08.png

   Choose **Programming > Geany Programmer's Editor** and click **OK**.

   .. image:: img/quick_guide_09.png

   The code will be displayed for editing or review.

   .. image:: img/quick_guide_10.png

2. Click **Run** in the window and the following contents will appear.
   
   .. image:: img/quick_guide_11.png

3. To stop it from running, just click the X button in the top right corner to close it and you'll return to the code. Alternatively, you can terminate the program by typing ctrl+c.
   
   .. image:: img/quick_guide_12.png

**Method 2: Using Terminal**

1. Log into your Raspberry Pi, open Terminal, and navigate to the home directory (``~``). (You can also access the terminal using SSH.)

   .. code-block::

      cd ~/universal-maker-sensor-kit/raspberry_pi/

   .. image:: img/quick_guide_13.png

   .. note::
       Use the ``cd`` command to navigate to the experiment's code directory.

2. Execute the code:

   .. code-block::

      python3 Lesson_01_Button_Module/01_button_module.py

   .. image:: img/quick_guide_14.png


3. Upon running the code, the output will indicate whether the Button is pressed or not.

   .. image:: img/quick_guide_15.png

4. To edit the ``Lesson_01_Button_Module/01_button_module.py`` file, stop the code by pressing ``Ctrl + C``. Then, open the file with:

   .. code-block::

      nano Lesson_01_Button_Module/01_button_module.py

   .. image:: img/quick_guide_16.png


5. ``nano`` is a text editor. This command opens ``nano Lesson_01_Button_Module/01_button_module.py`` for editing.

   .. image:: img/quick_guide_17.png

6. To exit nano, press ``Ctrl+X``. If you've made changes, a prompt will ask whether to save them. Respond with ``Y`` (yes) to save or ``N`` (no) to discard. Press ``Enter`` to confirm and exit. Reopen the file with ``nano Lesson_01_Button_Module/nano 01_button_module.py`` to view your changes.

   .. image:: img/quick_guide_18.png