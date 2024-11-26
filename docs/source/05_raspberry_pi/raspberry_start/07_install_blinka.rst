.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _install_blinka:

Insatll ``Adafruit_Blinka`` (CircuitPython) - Optional
=======================================================

For an enhanced experience with advanced modules, we recommend using the ``Adafruit_Blinka`` library, a key component of the CircuitPython environment. The unique feature of Blinka is its ability to enable code written for CircuitPython to run seamlessly and effortlessly on Linux computers like the Raspberry Pi.

This library makes it simpler to use complex modules like BMP280, VL53L0X, and OLED, streamlining your project development process. With CircuitPython, programming becomes more accessible, allowing you to focus on creating robust applications without needing extensive hardware knowledge.

Additionally, you’ll gain the benefit of a large support community and a variety of resources to aid your learning and development.

We will guide you through the straightforward process of installing Adafruit_Blinka, setting the stage for you to quickly start working on your projects.


Update your Raspberry Pi and Python
----------------------------------------------

Before installing Blinka, please use the following commands to ensure that your Raspberry Pi and Python versions are up to date:

.. code-block:: bash

   sudo apt-get update
   sudo apt-get upgrade


Setup Virtual Environment
----------------------------------------------

Starting from Bookworm (OS version), packages installed using ``pip`` must be installed into a Python virtual environment using ``venv``. A virtual environment is a secure container where you can install third-party modules without affecting or disrupting your system's Python.

The following command will create an "env" directory in your user directory (``~``) for the virtual Python environment.

.. code-block:: bash
   
   cd ~
   python -m venv env --system-site-packages

You will need to activate the virtual environment every time the Pi is rebooted. To activate it:

.. code-block:: bash

   source env/bin/activate

You’ll see that your prompt is now prepended with (env) to indicate that you’re no longer using the system Python. Instead, you’re using the version of Python contained inside your virtual environment. Any changes you make here won’t cause problems for your system Python; nor will any new modules you install into your environment.

.. image:: img/07_activate_env.png

To deactivate, you can use ``deactivate``, but leave it active for now.

Automatic Installation
-----------------------

When activated in the virtual environment (you will see ``(env)`` at the beginning of the terminal command), run the following code in order. This code will execute the installation script provided by adafruit and automatically complete the remaining installation steps.

.. code-block:: bash

   pip3 install --upgrade adafruit-python-shell
   pip3 install rpi-lgpio
   wget https://raw.githubusercontent.com/adafruit/Raspberry-Pi-Installer-Scripts/master/raspi-blinka.py
   sudo -E env PATH=$PATH python3 raspi-blinka.py

It may take a few minutes to run. When it finishes, it will ask you if you would like to reboot. Press Enter directly to reboot, or if you want to reboot later, enter "n" and then press Enter. When you are ready, manually reboot your raspberry pi.

.. image:: img/07_after_install_blinka.png

Once it reboots, the connection will close. After a couple of minutes, you can reconnect.


Blinka Test
-----------------------

Create a new file called ``blinkatest.py`` with nano or your favorite text editor and put the following in:

.. code-block:: python

   import board
   import digitalio
   import busio
   
   print("Hello blinka!")
   
   # Try to great a Digital input
   pin = digitalio.DigitalInOut(board.D17)
   print("Digital IO ok!")
   
   # Try to create an I2C device
   i2c = busio.I2C(board.SCL, board.SDA)
   print("I2C ok!")
   
   # Try to create an SPI device
   spi = busio.SPI(board.SCLK, board.MOSI, board.MISO)
   print("SPI ok!")
   
   print("done!")

Before running the code, please make sure that you have activated the virtual python environment with blinka installed:

.. code-block:: bash

   source ~/env/bin/activate

Then run the following command in the command line:

.. code-block:: bash

   python blinkatest.py

You should see the following, indicating digital i/o, I2C and SPI all worked.

.. image:: img/07_check_blinka.png


Reference
-----------------------

- |link_adafruit_blinka_guide|

- |link_python_on_raspberry_pi|
