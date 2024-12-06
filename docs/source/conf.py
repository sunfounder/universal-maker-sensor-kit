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

# -- sphinx_rtd_theme Theme options -----------------------------------------------------
html_theme_options = {
    'flyout_display': 'attached'
}

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx.ext.autosectionlabel',
    'sphinx_copybutton',
    'sphinx_rtd_theme'
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

# SunFounder logo

html_js_files = [
    'https://ezblock.cc/readDocFile/custom.js',
    './lang.js',
]
html_css_files = [
    'https://ezblock.cc/readDocFile/custom.css',
]


# Multi-language

language = 'de' # Before running make html, set the language.
locale_dirs = ['locale/'] # .po files for other languages are placed in the locale/ folder.

gettext_compact = False # Support for generating the contents of the folders inside source/ into other languages.



# open link in a new window

rst_epilog = """


.. |link_sf_facebook| raw:: html

    <a href="https://bit.ly/3wGTU0R" target="_blank">hier</a>

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

    <a href="../_static/pdf/esp8266_at_instruction_set_en.pdf" target="_blank">ESP8266 AT Instruction Set</a>

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

.. |link_uuid| raw:: html

    <a href="https://www.uuidgenerator.net/version4" target="_blank">Online UUID Generator</a>

.. |link_openweather| raw:: html

    <a href="https://openweathermap.org/" target="_blank">OpenWeather</a>


.. |link_hivemq| raw:: html

    <a href="https://www.hivemq.com/demos/websocket-client/" target="_blank">HiveMQ Web Client</a>

.. |link_adafruit_io| raw:: html

    <a href="https://io.adafruit.com/" target="_blank">Adafruit IO</a>


"""


# Purchase links of components

rst_epilog += """

.. |link_Universal_Maker_Sensor_Kit| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-universal-maker-sensor-kit?_pos=1&_sid=0cf649641&_ss=r" target="_blank">Purchase Link for Universal Maker Sensor Kit</a>

.. |link_Universal_kit| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-universal-maker-sensor-kit?_pos=1&_sid=0cf649641&_ss=r" target="_blank">Universal Maker Sensor Kit</a>

.. |link_Uno_R3_buy| raw:: html

    <a href="https://www.sunfounder.com/products/arduino-unor3-control-board" target="_blank">BUY</a>

.. |link_esp8266_buy| raw:: html

    <a href="https://www.sunfounder.com/products/esp01-esp-01s-programmer-adapter-serial-high-speed-esp8266-ch340g-usb-to-esp8266-serial-wireless-wifi-developent-board" target="_blank">BUY</a>

.. |link_picow_buy| raw:: html

    <a href="https://www.sunfounder.com/products/raspberry-pi-pico-w" target="_blank">BUY</a>

.. |link_wires_buy| raw:: html

    <a href="https://www.sunfounder.com/products/560pcs-jumper-wire-kit-with-14-lengths" target="_blank">BUY</a>

.. |link_breadboard_buy| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-breadboard-kit" target="_blank">BUY</a>

.. |link_i2clcd1602_buy| raw:: html

    <a href="https://www.sunfounder.com/products/i2c-lcd1602-module" target="_blank">BUY</a>

.. |link_servo_buy| raw:: html

    <a href="https://www.sunfounder.com/products/sf0180-servo-motor" target="_blank">BUY</a>

.. |link_ultrasonic_buy| raw:: html

    <a href="https://www.sunfounder.com/products/5pcs-hc-sr04-ultrasonic-module-distance-sensor" target="_blank">BUY</a>

.. |link_pir_buy| raw:: html

    <a href="https://www.sunfounder.com/products/hcsr501-infrared-sensor" target="_blank">BUY</a>

.. |link_touch_buy| raw:: html

    <a href="https://www.sunfounder.com/products/ttp223-touch-sensor-module" target="_blank">BUY</a>

.. |link_rotary_encoder_buy| raw:: html

    <a href="https://www.sunfounder.com/products/rotary-encoder-module" target="_blank">BUY</a>

.. |link_dht11_humiture_buy| raw:: html

    <a href="https://www.sunfounder.com/products/dht11-temperature-and-humidity-sensor-module" target="_blank">BUY</a>

.. |link_obstacle_avoidance_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/ir-obstacle-avoidance-sensor-module" target="_blank">BUY</a>

.. |link_mpu6050_buy| raw:: html

    <a href="https://www.sunfounder.com/products/3pcs-gy-521-mpu-6050-mpu6050-3-axis-accelerometer-gyroscope-module-6-dof-6-axis-accelerometer-gyroscope-sensor-module-16-bit-ad-converter-data-output-iic-i2c-for-arduino" target="_blank">BUY</a>

.. |link_soil_moisture_buy| raw:: html

    <a href="https://www.sunfounder.com/products/capacitive-soil-moisture-sensor-module" target="_blank">BUY</a>       

.. |link_oled_buy| raw:: html

    <a href="https://www.sunfounder.com/products/0-96-oled-display-module-ssd1306-128x64-blue-display" target="_blank">BUY</a>   

.. |link_joystick_buy| raw:: html

    <a href="https://www.sunfounder.com/products/dual-axis-button-joystick-module-ps2-game" target="_blank">BUY</a>

.. |link_flame_sensor_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/flame-sensor-module-1" target="_blank">BUY</a>

.. |link_mq2_gas_sensor_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/mq-2-gas-sensor-module" target="_blank">BUY</a>

.. |link_speed_sensor_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/h2010-speed-ir-measuring-sensor-module" target="_blank">BUY</a>

.. |link_pcf8591_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/pcf8591-converter-module" target="_blank">BUY</a>


.. |link_photoresistor_sensor_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/photoresistor-sensor-module-1" target="_blank">BUY</a>

.. |link_potentiometer_sensor_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/potentiometer-sensor-module" target="_blank">BUY</a>

.. |link_max30102_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/max30102-heart-rate-sensor-module-pulse-detection-blood-oxygen-concentration-module" target="_blank">BUY</a>

.. |link_raindrop_sensor_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/raindrop-detection-sensor-module" target="_blank">BUY</a>

.. |link_ds1302_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/ds1302-rtc-real-time-clock-module" target="_blank">BUY</a>

.. |link_bmp280_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/bmp280-high-precision-digital-atmospheric-barometric-pressure-module" target="_blank">BUY</a>

.. |link_vl53l0x_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/vl53l0x-time-of-flight-distance-sensor-laser-ranging-module" target="_blank">BUY</a>

.. |link_sw420_vibration_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/sw-420-vibration-switch-sensor-module" target="_blank">BUY</a>

.. |link_traffic_light_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/mini-traffic-light-led-5v-8mm-module" target="_blank">BUY</a>

.. |link_passive_buzzer_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/3-3-5v-passive-low-level-trigger-buzzer-alarm-sound-module" target="_blank">BUY</a>

.. |link_jdy31_bluetooth_module_buy| raw:: html

    <a href="https://www.sunfounder.com/products/jdy-31-bluetooth-wireless-communication-serial-pass-through-module-replace-hc-05-hc-06" target="_blank">BUY</a>

.. |link_esp32_camera_pro_kit_buy| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-esp32-camera-pro-kit" target="_blank">BUY</a>    

.. |link_umsk| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-universal-maker-sensor-kit?_pos=2&_sid=c060003fa&_ss=r" target="_blank">Universal Maker Sensor Kit</a>    
    

"""

