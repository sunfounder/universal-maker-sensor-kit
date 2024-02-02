# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------
import sphinx_rtd_theme
import time

project = 'SunFounder Universal Maker Sensor Kit'
copyright = f'{time.localtime().tm_year}, SunFounder'
author = 'www.sunfounder.com'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = ['sphinx.ext.autosectionlabel'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_static_path = ['_static']
html_theme = 'sphinx_rtd_theme'
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]

# html_theme = 'shibuya'

# SunFounder logo

html_js_files = [
    'https://ezblock.cc/readDocFile/custom.js',
    './lang.js',
]
html_css_files = [
    'https://ezblock.cc/readDocFile/custom.css',
]


# Multi-language

language = 'en' # Before running make html, set the language.
locale_dirs = ['locale/'] # .po files for other languages are placed in the locale/ folder.

gettext_compact = False # Support for generating the contents of the folders inside source/ into other languages.



# open link in a new window

rst_epilog = """

.. |link_german_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/ultimate-sensor-kit/de/latest/" target="_blank">Deutsch Online-Kurs</a>

.. |link_jp_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/ultimate-sensor-kit/ja/latest/" target="_blank">日本語オンライン教材</a>

.. |link_en_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/" target="_blank">English Online-tutorials</a>

.. |link_download_arduino| raw:: html

    <a href="https://www.arduino.cc/en/software" target="_blank">Arduino IDE 2.0.0 Page</a>

.. |link_install_arduino_linux| raw:: html

    <a href="https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux" target="_blank"> Installing the Arduino IDE 2 - Linux </a>
    
.. |link_ascii| raw:: html

    <a href="https://www.asciitable.com/" target="_blank">ASCII table of characters</a>

.. |link_esp8266_at| raw:: html

    <a href="/_static/pdf/esp8266_at_instruction_set_en.pdf" target="_blank">ESP8266 AT Instruction Set</a>

.. |link_blynk_lib| raw:: html

    <a href="https://github.com/blynkkk/blynk-library/releases" target="_blank">HERE</a>

.. |link_r4_datasheet| raw:: html

    <a href="https://docs.arduino.cc/resources/datasheets/ABX00080-datasheet.pdf" target="_blank">Arduino UNO R4 Minima Datasheet</a> 

.. |link_ra4m1_datasheet| raw:: html

    <a href="https://docs.arduino.cc/resources/datasheets/ra4m1-datasheet.pdf" target="_blank">Renesas RA4M1 Group Datasheet</a> 

.. |link_uno_r4| raw:: html

    <a href="https://docs.arduino.cc/hardware/uno-r4-minima" target="_blank">Arduino UNO R4 Minima</a> 

.. |link_blynk_logEvent| raw:: html

    <a href="https://docs.blynk.io/en/getting-started/events-tutorial#use-blynk.logevent-firmware-api" target="_blank">Blynk.logEvent()</a> 

.. |link_blynk_virtualWrite| raw:: html

    <a href="https://docs.blynk.io/en/blynk-library-firmware-api/virtual-pins#blynk.virtualwrite-vpin-value" target="_blank">Blynk.virtualWrite()</a> 

.. |link_blynk_timer_intro| raw:: html

    <a href="https://docs.blynk.io/en/legacy-platform/legacy-articles/keep-your-void-loop-clean" target="_blank">Why we use Blynk timer?</a> 

.. |link_blynk_quickstart| raw:: html

    <a href="https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/quickstart-device-code-overview" target="_blank">Blynk Quickstart</a> 

.. |link_blynk_doc| raw:: html

    <a href="https://docs.blynk.io/" target="_blank">Blynk Documentation</a> 

.. |link_blynk_syncing| raw:: html

    <a href="https://docs.blynk.io/en/blynk-library-firmware-api/state-syncing#for-hardware" target="_blank">Blynk - State Syncing</a> 

.. |link_blynk_write| raw:: html

    <a href="https://docs.blynk.io/en/getting-started/using-virtual-pins-to-control-physical-devices#the-blynk_write-vpin-function" target="_blank">Blynk - BLYNK_WRITE()</a>    

.. |link_blynk_LED_color| raw:: html

    <a href="https://docs.blynk.io/en/blynk.apps/widgets-displays/led#set-widget-color" target="_blank">Blynk - LED</a>  

.. |link_blynk_displays| raw:: html

    <a href="https://docs.blynk.io/en/blynk.apps/widgets-displays" target="_blank">Blynk - Widgets Displays</a>  

.. |link_blynk_timer| raw:: html

    <a href="https://docs.blynk.io/en/blynk-library-firmware-api/blynk-timer" target="_blank">Blynk - Timers</a>  

.. |link_ifttt| raw:: html

    <a href="https://ifttt.com/" target="_blank">IFTTT</a>  

.. |link_ifttt_welcome| raw:: html

    <a href="https://ifttt.com/explore/welcome_to_ifttt" target="_blank">IFTTT - Welcome to IFTTT</a> 

.. |link_ifttt_webhook_faq| raw:: html

    <a href="https://help.ifttt.com/hc/en-us/articles/115010230347-Webhooks-service-FAQ" target="_blank">IFTTT - Webhooks service FAQ</a> 

.. |link_thingspeak| raw:: html

    <a href="https://thingspeak.com/" target="_blank">ThingSpeak</a> 

.. |link_appinventor| raw:: html

    <a href="http://appinventor.mit.edu/" target="_blank">MIT App Inventor</a>

.. |link_appinventor_login| raw:: html

    <a href="http://appinventor.mit.edu/explore/get-started" target="_blank">Get Started with MIT App Inventor</a>

.. |link_heat_index| raw:: html

    <a href="https://en.wikipedia.org/wiki/Heat_index" target="_blank">heat index</a>

.. |link_PCF8574_Datasheet| raw:: html

    <a href="https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204" target="_blank">PCF8574 Datasheet</a>

.. |link_image2cpp| raw:: html

    <a href="http://javl.github.io/image2cpp/" target="_blank">image2cpp</a>

.. |link_arduino-songs| raw:: html

    <a href="https://github.com/robsoncouto/arduino-songs" target="_blank">robsoncouto/arduino-songs</a>    

.. |link_speech_recognition| raw:: html

    <a href="https://play.google.com/store/apps/details?id=com.google.android.tts" target="_blank">Speech Recognition & Synthesis</a>  

.. |link_language_tag| raw:: html

    <a href="https://en.wikipedia.org/wiki/List_of_ISO_639-1_codes" target="_blank">List of ISO 639-1 codes</a>  

.. |link_serial_bluetooth_terminal| raw:: html

    <a href="https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal" target="_blank">Serial Bluetooth Terminal</a>  

.. |link_blynk| raw:: html

    <a href="https://blynk.io/" target="_blank">Blynk</a> 

.. |link_hall_effect| raw:: html

    <a href="https://en.wikipedia.org/wiki/Hall_effect" target="_blank">Hall effect</a> 
    
.. |link_breadboard_tutorials| raw:: html

    <a href="https://www.sciencebuddies.org/science-fair-projects/references/how-to-use-a-breadboard" target="_blank">How to Use a Breadboard - Science Buddies</a>

.. |link_esp32_datasheet| raw:: html

    <a href="https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf" target="_blank">ESP32-WROOM-32E Datasheet</a> 
    
.. |link_pi_pico| raw:: html

    <a href="https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html" target="_blank">Raspberry Pi Pico and Pico W.</a> 

.. |link_thonny| raw:: html

    <a href="https://thonny.org/" target="_blank">Thonny</a>
    

.. |link_micropython_pi| raw:: html

    <a href="https://www.raspberrypi.com/documentation/microcontrollers/micropython.html#drag-and-drop-micropython" target="_blank">method</a>

.. |link_imu| raw:: html

    <a href="https://github.com/micropython-IMU/micropython-mpu9x50" target="_blank">micropython-IMU/micropython-mpu9x50</a>

.. |link_PCF8591_micropython_library| raw:: html

    <a href="https://github.com/xreef/PCF8591_micropython_library" target="_blank">xreef/PCF8591_micropython_library</a>

.. |link_rotary_irq_rp2_library| raw:: html

    <a href="https://github.com/MikeTeachman/micropython-rotary" target="_blank">MikeTeachman/micropython-rotary</a>

.. |link_micropython_onewire_driver| raw:: html

    <a href="https://docs.micropython.org/en/latest/rp2/quickref.html#onewire-driver" target="_blank">OneWire driver</a>

.. |link_micropython_bmp280_driver| raw:: html

    <a href="https://github.com/dafvid/micropython-bmp280" target="_blank">dafvid/micropython-bmp280</a>

.. |link_micropython_vl53l0x_driver| raw:: html

    <a href="https://github.com/kevinmcaleer/vl53l0x" target="_blank">kevinmcaleer/vl53l0x</a>

.. |link_micropython_ssd1306_driver| raw:: html

    <a href="https://github.com/stlehmann/micropython-ssd1306" target="_blank">stlehmann/micropython-ssd1306</a>

.. |link_FrameBuffer_doc| raw:: html

    <a href="https://docs.micropython.org/en/latest/library/framebuf.html" target="_blank">framebuf — frame buffer manipulation</a>

.. |link_buzzer_music| raw:: html

    <a href="https://github.com/james1236/buzzer_music" target="_blank">james1236/buzzer_music</a>
    
.. |link_micropython_max30102_driver| raw:: html

    <a href="https://github.com/n-elia/MAX30102-MicroPython-driver" target="_blank">n-elia/MAX30102-MicroPython-driver</a>
    
.. |link_buy_pi_case| raw:: html

    <a href="https://www.sunfounder.com/search?type=product&q=CASE" target="_blank">here</a>

.. |link_set_up_pi| raw:: html

    <a href="https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up" target="_blank">Setting up your Raspberry Pi</a>

.. |link_alpha2_code| raw:: html

    <a href="https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2#Officially_assigned_code_elements" target="_blank">ISO/IEC alpha2 code</a>

.. |link_mpu6050_python_driver| raw:: html

    <a href="https://github.com/m-rtijn/mpu6050" target="_blank">m-rtijn/mpu6050</a>

.. |link_max30102_python_driver| raw:: html

    <a href="https://github.com/doug-burrell/max30102" target="_blank">doug-burrell/max30102</a>

.. |link_adafruit_blinka_guide| raw:: html

    <a href="https://learn.adafruit.com/circuitpython-on-raspberrypi-linux/overview" target="_blank">CircuitPython Libraries on Linux and Raspberry Pi - Adafruit</a>
    
.. |link_python_on_raspberry_pi| raw:: html

    <a href="https://www.raspberrypi.com/documentation/computers/os.html#python-on-raspberry-pi" target="_blank">Python on Raspberry Pi - Raspberry Pi Documentation</a>

.. |link_Adafruit_CircuitPython_BMP280| raw:: html

    <a href="https://github.com/adafruit/Adafruit_CircuitPython_BMP280" target="_blank">adafruit/Adafruit_CircuitPython_BMP280</a>

.. |link_Adafruit_CircuitPython_VL53L0X| raw:: html

    <a href="https://github.com/adafruit/Adafruit_CircuitPython_VL53L0X" target="_blank">adafruit/Adafruit_CircuitPython_VL53L0X</a>

.. |Adafruit_CircuitPython_DHT| raw:: html

    <a href="https://github.com/adafruit/Adafruit_CircuitPython_DHT" target="_blank">adafruit/Adafruit_CircuitPython_DHT</a>
    
.. |Adafruit_Adafruit_CircuitPython_SSD1306| raw:: html

    <a href="https://github.com/adafruit/Adafruit_CircuitPython_SSD1306" target="_blank">adafruit/Adafruit_CircuitPython_SSD1306</a>

.. |link_pil_handbook| raw:: html

    <a href="https://pillow.readthedocs.io/en/stable/handbook/overview.html" target="_blank">Pillow Handbook</a>

.. |link_lcd1602_python_driver_pi| raw:: html

    <a href="https://github.com/sterlingbeason/LCD-1602-I2C" target="_blank">sterlingbeason/LCD-1602-I2C</a>


.. |link_gpiozero_color| raw:: html

    <a href="https://colorzero.readthedocs.io/en/latest/api_color.html#colorzero.Color" target="_blank">colorzero.Color</a>

    

"""
