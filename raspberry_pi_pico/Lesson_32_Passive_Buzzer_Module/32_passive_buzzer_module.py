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
