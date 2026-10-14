import math
import os
import wave
import struct

# Generate simple procedural SFX for card placement, hit, and death.
# Output: card_place.wav, tower_hit.wav, unit_death.wav

OUT_DIR = os.getcwd()


def generate_tone(freq=440.0, duration=0.12, amplitude=0.6, sample_rate=44100):
    samples = []
    frames = int(sample_rate * duration)
    for i in range(frames):
        t = i / sample_rate
        s = math.sin(2 * math.pi * freq * t)
        envelope = max(0.0, 1.0 - (i / frames))
        samples.append(int(max(-1.0, min(1.0, amplitude * s * envelope)) * 32767.0))
    return samples


def save_wav(path, samples, sample_rate=44100):
    with wave.open(path, 'wb') as wf:
        wf.setnchannels(1)
        wf.setsampwidth(2)
        wf.setframerate(sample_rate)
        for s in samples:
            wf.writeframes(struct.pack('<h', s))


card_place = []
for i in range(0, 2205):
    t = i / 44100.0
    s = math.sin(2 * math.pi * 980 * t) * (1.0 - (i / 2205.0))
    card_place.append(int(s * 18000.0))

hit = []
for i in range(0, 800):
    t = i / 44100.0
    s = math.sin(2 * math.pi * 250 * t) * (1.0 - (i / 800.0))
    hit.append(int(s * 14000.0))

death = []
for i in range(0, 1800):
    t = i / 44100.0
    s = math.sin(2 * math.pi * (180 - (i / 1800.0) * 120) * t) * (1.0 - (i / 1800.0))
    death.append(int(s * 15000.0))

save_wav(os.path.join(OUT_DIR, 'card_place.wav'), card_place)
save_wav(os.path.join(OUT_DIR, 'tower_hit.wav'), hit)
save_wav(os.path.join(OUT_DIR, 'unit_death.wav'), death)

print('Generated SFX:')
print(os.path.join(OUT_DIR, 'card_place.wav'))
print(os.path.join(OUT_DIR, 'tower_hit.wav'))
print(os.path.join(OUT_DIR, 'unit_death.wav'))
