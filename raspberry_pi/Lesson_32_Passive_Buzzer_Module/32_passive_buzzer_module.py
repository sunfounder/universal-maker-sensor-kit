from gpiozero import TonalBuzzer
from time import sleep

# Initialize the TonalBuzzer on GPIO pin 17
tb = TonalBuzzer(17)  # Change to the pin number your buzzer is connected to

def play(tune):
    """
    Play a musical tune using the buzzer.
    :param tune: List of tuples, where each tuple contains a note and its duration.
    """
    for note, duration in tune:
        print(note)  # Print the current note being played
        tb.play(note)  # Play the note on the buzzer
        sleep(float(duration))  # Wait for the duration of the note
    tb.stop()  # Stop the buzzer after playing the tune

# Define the musical tune as a list of notes and their durations
tune = [('C#4', 0.2), ('D4', 0.2), (None, 0.2),
    ('Eb4', 0.2), ('E4', 0.2), (None, 0.6),
    ('F#4', 0.2), ('G4', 0.2), (None, 0.6),
    ('Eb4', 0.2), ('E4', 0.2), (None, 0.2),
    ('F#4', 0.2), ('G4', 0.2), (None, 0.2),
    ('C4', 0.2), ('B4', 0.2), (None, 0.2),
    ('F#4', 0.2), ('G4', 0.2), (None, 0.2),
    ('B4', 0.2), ('Bb4', 0.5), (None, 0.6),
    ('A4', 0.2), ('G4', 0.2), ('E4', 0.2),
    ('D4', 0.2), ('E4', 0.2)]

# Play the tune
play(tune) 