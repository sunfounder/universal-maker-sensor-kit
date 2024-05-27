.. note::

    こんにちは、SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Communityへようこそ！Facebook上で、仲間と一緒にRaspberry Pi、Arduino、ESP32をさらに深く探求しましょう。

    **なぜ参加するのか？**

    - **専門的なサポート**：購入後の問題や技術的な課題をコミュニティやチームの助けを借りて解決。
    - **学びと共有**：スキルを向上させるためのヒントやチュートリアルを交換。
    - **限定プレビュー**：新製品発表や予告編に早期アクセス。
    - **特別割引**：最新製品の特別割引を楽しむ。
    - **フェスティブプロモーションとプレゼント**：プレゼントやホリデープロモーションに参加。

    👉 私たちと一緒に探索と創造を始める準備はできましたか？[|link_sf_facebook|]をクリックして、今すぐ参加しましょう！

.. _pico_lesson32_passive_buzzer:

Lesson 32: Passive Buzzer Module
==================================

In this lesson, you will learn how to use the passive buzzer on Raspberry Pi Pico W to play single notes and perform music. You will understand how to use PWM (Pulse Width Modulation) to set up the buzzer on GPIO 16 and use the music class in the buzzer_music library to play complete songs. This course will guide you step by step through playing single notes, and then further execute full melodies such as "Happy Birthday". This project is very suitable for beginners, providing a practical way to understand musical tones and integrate external libraries in MicroPython on Raspberry Pi Pico W.

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

    *   - Raspberry Pi Pico W
        - \-
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_module_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|


Wiring
---------------------------

.. image:: img/Lesson_32_Passive_buzzer_pico_bb.png
    :width: 100%


Code
---------------------------

.. code-block:: python

   import machine
   import time
   
   # Initialize the PWM on GPIO 16 for the buzzer
   buzzer = machine.PWM(machine.Pin(16))
   
   def tone(pin, frequency, duration):
       """Play a tone on the given pin at the specified frequency and duration."""
       pin.freq(frequency)
       pin.duty_u16(30000)
       time.sleep_ms(duration)
       pin.duty_u16(0)
   
   # Play individual notes
   tone(buzzer, 440, 250)  # A4
   time.sleep(0.5)
   tone(buzzer, 494, 250)  # B4
   time.sleep(0.5)
   tone(buzzer, 523, 250)  # C5
   time.sleep(1)
   
   
   
   # Import the music class from the buzzer_music module for easy song playback.
   from buzzer_music import music
   
   # Find some music on onlinesequencer.net, click edit, select all notes with CTRL + A and then copy them with CTRL + C
   # Paste the string to song, making sure to remove the "Online Sequencer:120233:" from the start and the ";:" from the end
   # https://onlinesequencer.net/2474257 Happy Birthday (by Sudirth)
   song = "0 G4 3 0;3 G4 1 0;4 A4 4 0;8 G4 4 0;12 C5 4 0;16 B4 8 0;24 G4 3 0;27 G4 1 0;28 A4 4 0;32 G4 4 0;36 D5 4 0;40 C5 8 0;48 G4 3 0;51 G4 1 0;52 G5 4 0;56 E5 4 0;60 C5 4 0;64 B4 4 0;68 A4 4 0;72 F5 3 0;75 F5 1 0;76 E5 4 0;80 C5 4 0;84 D5 4 0;88 C5 8 0"
   
   # Initialize the music class with the song and set the buzzer pin
   mySong = music(song, pins=[machine.Pin(16)])
   
   # Play music using the music class.
   while True:
       print(mySong.tick())
       time.sleep(0.04)



Code Analysis
---------------------------

#. Initialization

   Import necessary modules and initialize the PWM on a specific GPIO pin to control the buzzer.

   .. code-block:: python

       import machine
       import time

       # Initialize the PWM on GPIO 16 for the buzzer
       buzzer = machine.PWM(machine.Pin(16))

#. Defining the tone function

   This function allows playing a single tone at a specified frequency and duration. It sets the frequency and duty cycle (volume) of the PWM signal.

   .. code-block:: python

       def tone(pin, frequency, duration):
           """Play a tone on the given pin at the specified frequency and duration."""
           pin.freq(frequency)
           pin.duty_u16(30000)
           time.sleep_ms(duration)
           pin.duty_u16(0)

#. Playing individual notes

   Here, the ``tone`` function is used to play individual notes. The parameters include the note's frequency (in Hz) and its duration (in milliseconds).

   .. code-block:: python

       # Play individual notes
       tone(buzzer, 440, 250)  # A4
       time.sleep(0.5)
       tone(buzzer, 494, 250)  # B4
       time.sleep(0.5)
       tone(buzzer, 523, 250)  # C5
       time.sleep(1)

#. Using the buzzer_music library

   The ``buzzer_music`` library is imported, and a song string is prepared. 

   You can find some music on onlinesequencer.net, click edit, select all notes with CTRL + A and then copy them with CTRL + C. Paste the string to ``song``, making sure to remove the "Online Sequencer:120233:" from the start and the ";:" from the end.

   For more information about the ``buzzer_music`` library, please visit |link_buzzer_music|.

   .. code-block:: python

       # Import the music class from the buzzer_music module for easy song playback.
       from buzzer_music import music

       # https://onlinesequencer.net/2474257 Happy Birthday (by Sudirth)
       song = "0 G4 3 0;3 G4 1 0;4 A4 4 0;8 G4 4 0;12 C5 4 0;16 B4 8 0;24 G4 3 0;27 G4 1 0;28 A4 4 0;32 G4 4 0;36 D5 4 0;40 C5 8 0;48 G4 3 0;51 G4 1 0;52 G5 4 0;56 E5 4 0;60 C5 4 0;64 B4 4 0;68 A4 4 0;72 F5 3 0;75 F5 1 0;76 E5 4 0;80 C5 4 0;84 D5 4 0;88 C5 8 0"

#. Initializing and playing the song

   The ``music`` class is initialized with the song string and the GPIO pin for the buzzer. The music is played in a loop using the ``tick`` method of the ``music`` class.

   .. code-block:: python

       # Initialize the music class with the song and set the buzzer pin
       mySong = music(song, pins=[machine.Pin(16)])

       # Play music using the music class.
       while True:
           print(mySong.tick())
           time.sleep(0.04)
