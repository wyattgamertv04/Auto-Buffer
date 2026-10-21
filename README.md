# Auto Buffer ⚡

A Geode mod for Geometry Dash that automatically buffs levels to increase difficulty!

![Geode Version](https://img.shields.io/badge/Geode-v5.7.1-blue)
![GD Version](https://img.shields.io/badge/GD-v2.2081-green)

---

## 📖 About
**Auto Buffer** automatically modifies level objects upon loading to make gameplay tighter, faster, or more precise. 

### Features
* **Automatic Level Buffing:** Intercepts level data on load and adjusts hazard hitboxes/positions.
* **Toggleable Settings:** Turn the buffing mechanics on or off directly inside the Geode mod menu.

---

## 🛠️ Installation

1. Make sure you have **Geode** installed on Geometry Dash (v2.2081).
2. Download the latest `.geode` file from the [Releases](../../releases) page.
3. Place the `.geode` file into your `geode/mods` folder (or drag and drop it into the in-game Geode menu).
4. Restart your game!

---

## 🏗️ Building from Source

To compile this mod locally using the Geode CLI:

```bash
# Clone the repository
git clone [https://github.com/wyattgamertv04/auto-buffer.git](https://github.com/wyattgamertv04/auto-buffer.git)
cd auto-buffer

# Setup build directory and build
geode build
