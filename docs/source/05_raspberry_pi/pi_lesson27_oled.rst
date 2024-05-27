.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pi_lesson27_oled:

Lesson 27: OLED Display Module (SSD1306)
============================================

In this lesson, you will learn how to connect a Raspberry Pi with an OLED Display Module (SSD1306) using Python. You'll learn how to establish I2C communication between the Raspberry Pi and the OLED display, and use the Python Imaging Library (PIL) for creating graphics and text. The lesson will guide you through drawing shapes and text on the OLED screen, providing a practical example with the message "Hello World!".

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
    *   - :ref:`cpn_oled`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_27_oled_pi_bb.png
    :width: 100%


Install Library
---------------------------

.. note::
    The adafruit-circuitpython-ssd1306 library relies on Blinka, so please ensure that Blinka has been installed. To install libraries, refer to :ref:`install_blinka`.

Before installing the library, please make sure that the virtual Python environment is activated:

.. code-block:: bash

   source ~/env/bin/activate

Install adafruit-circuitpython-ssd1306 library:

.. code-block:: bash

   pip install adafruit-circuitpython-ssd1306

Run the Code
---------------------------

.. note::
   - Please ensure that you have installed the Python library required for running the code according to the "Install Library" steps.
   - Before running the code, please make sure that you have activated the virtual Python environment with blinka installed. You can activate the virtual environment using a command like this:

     .. code-block:: bash
  
        source ~/env/bin/activate

   - Find the code for this lesson in ``universal-maker-sensor-kit-main/pi/`` directory, or directly copy and paste the code below. Execute the code by running the following commands in terminal:

     .. code-block:: bash
  
        python 27_ssd1306_oled_module.py

.. code-block:: python

   import board
   import digitalio
   from PIL import Image, ImageDraw, ImageFont
   import adafruit_ssd1306
   
   # Initialize OLED display dimensions
   WIDTH = 128
   HEIGHT = 64
   
   # Set up I2C communication with the OLED display
   i2c = board.I2C()  # Utilizes board's SCL and SDA pins
   oled = adafruit_ssd1306.SSD1306_I2C(WIDTH, HEIGHT, i2c, addr=0x3C)
   
   # Clear the OLED display
   oled.fill(0)
   oled.show()
   
   # Create a new image with 1-bit color for drawing
   image = Image.new("1", (oled.width, oled.height))
   
   # Obtain a drawing object to manipulate the image
   draw = ImageDraw.Draw(image)
   
   # Draw a filled white rectangle as the background
   draw.rectangle((0, 0, oled.width, oled.height), outline=255, fill=255)
   
   # Define border size for an inner rectangle
   BORDER = 5
   # Draw a smaller black rectangle inside the larger one
   draw.rectangle(
       (BORDER, BORDER, oled.width - BORDER - 1, oled.height - BORDER - 1),
       outline=0,
       fill=0,
   )
   
   # Load the default font for text
   font = ImageFont.load_default()
   
   def getfontsize(font, text):
       # Calculate the size of the text in pixels
       left, top, right, bottom = font.getbbox(text)
       return right - left, bottom - top
   
   # Define the text to be displayed
   text = "Hello World!"
   # Get the width and height of the text in pixels
   (font_width, font_height) = getfontsize(font, text)
   # Draw the text, centered on the display
   draw.text(
       (oled.width // 2 - font_width // 2, oled.height // 2 - font_height // 2),
       text,
       font=font,
       fill=255,
   )
   
   # Send the image to the OLED display
   oled.image(image)
   oled.show()


Code Analysis
---------------------------

#. Importing Necessary Libraries

   Here, we import the libraries needed for the project. ``board`` is for interfacing with the Raspberry Pi hardware, ``PIL`` for image processing, and ``adafruit_ssd1306`` for controlling the OLED display.

   For more detail about the ``adafruit_ssd1306`` library, please refer to |Adafruit_Adafruit_CircuitPython_SSD1306|.

   .. code-block:: python

      import board
      import digitalio
      from PIL import Image, ImageDraw, ImageFont
      import adafruit_ssd1306

#. Initializing the OLED Display

   The OLED display dimensions are set, and I2C communication is established. The ``adafruit_ssd1306.SSD1306_I2C`` object is created to interact with the OLED.

   .. code-block:: python

      # Initialize OLED display dimensions
      WIDTH = 128
      HEIGHT = 64

      # Set up I2C communication with the OLED display
      i2c = board.I2C()
      oled = adafruit_ssd1306.SSD1306_I2C(WIDTH, HEIGHT, i2c, addr=0x3C)

#. Clearing the Display

   The OLED display is cleared by filling it with zeros (black).

   .. code-block:: python

      # Clear the OLED display
      oled.fill(0)
      oled.show()

#. Creating an Image Buffer

   An image buffer is created using PIL. This is where the graphics are drawn before being displayed on the screen.

   The PIL(Python Imaging Library) adds image processing capabilities to your Python interpreter. For more detail, please refer to |link_pil_handbook|.

   .. code-block:: python

      # Create a new image with 1-bit color for drawing
      image = Image.new("1", (oled.width, oled.height))

      # Obtain a drawing object to manipulate the image
      draw = ImageDraw.Draw(image)

#. Drawing Graphics

   Here, a white rectangle (background) and a smaller black rectangle (border effect) are drawn on the image buffer.

   .. code-block:: python

      # Draw a filled white rectangle as the background
      draw.rectangle((0, 0, oled.width, oled.height), outline=255, fill=255)

      # Define border size for an inner rectangle
      BORDER = 5
      # Draw a smaller black rectangle inside the larger one
      draw.rectangle(
          (BORDER, BORDER, oled.width - BORDER - 1, oled.height - BORDER - 1),
          outline=0,
          fill=0,
      )

#. Adding Text

   The default font is loaded, and a function to calculate the text size is defined. Then, "Hello World!" is centered and drawn on the image buffer.

   .. code-block:: python

      # Load the default font for text
      font = ImageFont.load_default()

      def getfontsize(font, text):
          # Calculate the size of the text in pixels
          left, top, right, bottom = font.getbbox(text)
          return right - left, bottom - top

      # Define the text to be displayed
      text = "Hello World!"
      # Get the width and height of the text in pixels
      (font_width, font_height) = getfontsize(font, text)
      # Draw the text, centered on the display
      draw.text(
          (oled.width // 2 - font_width // 2, oled.height // 2 - font_height // 2),
          text,
          font=font,
          fill=255,
      )

#. Displaying the Image

   Finally, the image buffer is sent to the OLED display for visualization.

   .. code-block:: python

      # Send the image to the OLED display
      oled.image(image)
      oled.show()