import string

import whisper
import os, glob
import serial,time
import string
arduino = serial.Serial(port='COM8', baudrate=115200, timeout=.1)

def save_command(input_string, command_word):
    # Remove punctuation from input_string
    translator = str.maketrans("", "", string.punctuation)
    input_string = input_string.translate(translator)

    words = input_string.lower().split()

    try:
        command_index = words.index(command_word)

        if command_index < len(words) - 1:
            if words[command_index + 1] == "thumbs" and command_index + 1 < len(words) - 1:
                # arduino.write(words[command_index + 2].encode())
                print(words[command_index + 2])
            else:
                print(words[command_index + 1])
                arduino.write(words[command_index + 1].encode())

    except ValueError as e:
        pass
    return None

recordings_dir = os.path.join('C:/Users/snipp/Desktop/polihack/recordings', '*')

model = whisper.load_model("tiny")

transcribed = []

while True:
    files = sorted(glob.iglob(recordings_dir), key=os.path.getctime, reverse=True)
    if len(files) < 1:
        continue

    latest_recording = files[0]
    latest_recording_filename = os.path.basename(latest_recording)


    if os.path.exists(latest_recording) and not latest_recording in transcribed:
        audio = whisper.load_audio(latest_recording)
        audio = whisper.pad_or_trim(audio)
        mel = whisper.log_mel_spectrogram(audio).to(model.device)
        options = whisper.DecodingOptions(language= 'en', fp16=False)

        result = whisper.decode(model, mel, options)

        if result.no_speech_prob < 0.3:
            print(result.text)
            transcribed.append(latest_recording)
        command="easy"
        save_command(result.text,command)