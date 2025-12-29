# Bongo Cat for osu! - Voice Enhanced Edition 🎤🐱

An osu! Bongo Cat overlay with **voice-activated mouth movement**, smooth paw animations, and simple skinning ability.

![Bongo Cat](img/osu/mousebg.png)

## ✨ Features

### 🎤 Voice Detection & Mouth Movement

- The cat's mouth opens when you speak!
- Automatic detection of headphone/headset microphones
- Low-latency voice animation (no noticeable delay)
- Works independently of keyboard/mouse input

### 🎮 Gaming Streamer Ready

- Tracks keyboard and mouse input
- Customizable key bindings
- Perfect for streaming overlays
- Christmas theme included! 🎄

---

## 🚀 Quick Start (No Build Required!)

### Windows

1. Download `release/bongocat-osu-windows.zip`
2. Extract the zip file
3. Run `bongo.exe`
4. Position the window on your stream overlay

### Linux

1. Download `release/bongocat-osu-linux.tar.gz`
2. Extract: `tar -xzvf bongocat-osu-linux.tar.gz`
3. Run: `./bin/bongo`
4. Position the window on your stream overlay

---

## ⌨️ Controls

| Key | Action |
|-----|--------|
| `Ctrl + R` | Reload config (while window is focused) |
| `Ctrl + D` | Toggle debug panel |

---

## ⚙️ Configuration

Edit `config.json` to customize:

### Mode

```json
"mode": 1
```

- `1` = osu! (keyboard + mouse) ✅ **Best for gaming**
- `2` = Taiko
- `3` = Catch
- `4` = Mania
- `5` = Custom

### Key Bindings (for mode 1)

```json
"osu": {
    "key1": [87, 65, 83, 68],           // WASD - left paw
    "key2": [32, 16, 17, 69, 82],       // Space, Shift, Ctrl, E, R - right paw
    "smoke": [89]                        // Y key - smoke effect
}
```

### Common Key Codes

| Key | Code | Key | Code |
|-----|------|-----|------|
| W | 87 | Space | 32 |
| A | 65 | Shift | 16 |
| S | 83 | Ctrl | 17 |
| D | 68 | Alt | 18 |
| E | 69 | Tab | 9 |
| R | 82 | Esc | 27 |
| Q | 81 | Enter | 13 |
| F | 70 | 1-9 | 49-57 |

### Christmas Theme 🎄

To use the Christmas background, open `config.json` in a text editor (Notepad) and make these changes:

**Step 1:** Change mode from `1` to `5`:

```json
"mode": 5,
```

**Step 2:** Make sure the custom section looks like this:

```json
"custom": {
    "background": "img/osu/xmas.png",
    "mouse": true,
    "mouseImage": "img/osu/mouse.png",
    "mouseOnTop": true,
    "offsetX": 0,
    "offsetY": 0,
    "scalar": 1.0,
    "paw": [255, 255, 255],
    "pawEdge": [0, 0, 0],
    "keyContainers": [
        {
            "defaultImage": "img/osu/up.png",
            "keys": [
                {
                    "keyCodes": [87, 65, 83, 68, 32, 16, 17, 69, 82, 81, 70],
                    "image": "img/osu/left.png"
                }
            ]
        }
    ]
}
```

**Step 3:** Save the file and restart `bongo.exe`

> **Note:** In custom mode (mode 5), you need to configure `keyContainers` for the keyboard paw to work. The example above includes WASD, Space, Shift, Ctrl, E, R, Q, F keys.

---

## 🔊 Voice Detection Tips

- **Microphone**: Works best with headset/headphone mics
- **Sensitivity**: Auto-calibrated, no setup needed
- **Latency**: Optimized for minimal delay (~30ms)

---

## 📝 Original README

### Description

An osu! Bongo Cat overlay with smooth paw movement and simple skinning ability, written in C++. Originally created by [HamishDuncanson](https://github.com/HamishDuncanson).

You can find how to configure the application in our [wiki](https://github.com/kuroni/bongocat-osu/wiki/Settings).

Hugs and kisses to [CSaratakij](https://github.com/CSaratakij) for creating the Linux port for this project!

[Original post](https://www.reddit.com/r/osugame/comments/9hrkte/i_know_bongo_cat_is_getting_old_but_heres_a_nicer/) by [Kuvster](https://github.com/Kuvster).

### Further Information

- In order to play with fullscreen on Windows 10, run both osu! and this application in Windows 7 compatibility mode.
- Press `Ctrl + R` to reload configuration and images (only works when window is focused).

### Supported Operating Systems

- ✅ Windows (64-bit)
- ✅ Linux (tested with Arch Linux with WINE Staging 5)

_Notice_: If you're using WINE on Linux, make sure that osu! and this application run in the same `WINEPREFIX`.

---

## 🛠️ Building from Source

### Linux

```bash
# Install dependencies
sudo apt install g++ libxdo-dev libsdl2-dev libsfml-dev libx11-dev libxrandr-dev

# Build
make

# Run
./bin/bongo
```

### Windows (Cross-compile from Linux)

```bash
# Install MinGW
sudo apt install mingw-w64

# Download SFML for Windows
mkdir build-deps && cd build-deps
wget https://www.sfml-dev.org/files/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit.zip
unzip SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit.zip
cd ..

# Build
make -f Makefile.cross-win

# Output: bin/bongo.exe
```

---

## 📜 License

MIT License - See [LICENSE](LICENSE) for details.

---

Made with ❤️ for streamers and osu! players
