import sounddevice as sd
import wavio
import datetime

freq = 44100
duration = 5

print('Recording')

while True:
    ts = datetime.datetime.now()
    filename = ts.strftime("%Y-%m-%d %H_%M_%S")
    recording = sd.rec(int(duration * freq), samplerate=freq, channels=1)
    sd.wait()
    wavio.write(f"C:/Users/snipp/Desktop/polihack/recordings/{filename}.wav", recording, freq, sampwidth=2)
