# 42_cub3d

Cub3D is the first 3D graphics project in 42’s Cursus. It emulates a Wolfenstein 3D–style game by raycasting a 2D map into a real-time 3D view. This hands-on project introduces us to graphics concepts like field-of-view, raycasting, and texture mapping. As a team we built a simple maze engine with MiniLibX where the player can navigate walls and doors. It’s a foundational step in learning how 2D information is projected into a convincing 3D scene.

<details>
<summary>Table of Contents</summary>

- [🎯 Overview](#overview-)  
- [✨ Features](#features-)  
- [📦 Installation](#installation-)  
- [🕹️ Controls](#controls-)  
- [🗺️ Map Format](#map-format-)  
- [⚙️ Project Structure](#project-structure-)  
- [🧪 Testing](#testing-)  
- [🖼️ Showcase](#showcase-)  
- [🤝 Contributors](#contributors-)  
- [📄 License](#license-)  

</details>

## 🎯 Overview

Cub3D’s purpose is to teach basic 3D rendering using the raycasting technique. The engine casts a ray from the player’s point of view for each vertical slice of the screen, detects wall intersections with a simple DDA algorithm, and draws textured strips based on distance. The result is a pseudo-3D first-person view inside a maze. In our implementation the maze walls are always axis-aligned, and we add a flat-colored floor and ceiling. This project bridges the gap between 2D and 3D: by the end, students grasp how a 2D map becomes an immersive 3D environment in real time.

## ✨ Features

### Mandatory  
- **Raycasting engine** with textured walls: north, south, east, west walls have separate textures.  
- **Configuration file parsing**: reads a `.cub` file for textures and colors (see [Map Format](#map-format-)).  
- **Movement and rendering**: smooth first-person movement (forward/back, strafing, rotation) with collision against walls.  
- **Flat floor/ceiling**: floor and ceiling are drawn in a solid color from the config.  
- **Field of View (FOV)** and correct perspective: no fisheye distortion.  
- **Error handling**: proper exit on bad input or file format (e.g. missing textures, invalid map).

### Bonus  
- **Doors (D)**: open and close doors in the map with collision detection.
- **Animated Sprites**: door opening and other visual elements include sprite animations.
- **Animated Introduction**: an intro animation runs before entering the game.
- **Mouse Hook Handling**: rotate view using mouse movement for smoother gameplay.
- **Minimap Display**: toggleable minimap showing walls, player position, and surroundings.

## 📦 Installation

Clone and compile the project with:

```bash
git clone https://github.com/m3irel3s/42_Cub3d.git
cd cub3d
make            # compile mandatory part
make bonus      # (optional) compile bonus features if implemented
```

## ▶️ Running the Game

Make sure you have **MiniLibX installed and linked** (typically provided in 42’s environment).  
To run the game, pass a `.cub` map file:

```bash
./cub3D maps/valid_maps/example.cub
./cub3D_bonus maps_bonus/valid_maps/example.cub
```
## 🕹️ Controls

| Key         | Action                          |
|-------------|---------------------------------|
| `W`     | Move forward                    |
| `S`     | Move backward                   |
| `A`     | Strafe left                     |
| `D`     | Strafe right                    |
| `← / →`     | Rotate view (look left/right)   |
| `ESC` or `Q`| Quit the game                   |
| `E`     | Open/close door *(bonus)*       |
| `Tab`     | Display minimap *(bonus)*       |

> 💡 Supports both **WASD** and **ZQSD** layouts (for AZERTY keyboards). Arrow keys also rotate the view.

---

## 🗺️ Map Format

Cub3D uses a text-based `.cub` configuration file. It consists of two sections:

1. **Configuration**: Textures and colors  
2. **Map Grid**: 2D map layout

### 📄 Example `.cub` file:

```text
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F  220,100,  0   # Floor color (R,G,B)
C  225, 30,  0   # Ceiling color (R,G,B)

111111
1N0D01
100001
111111
```

### 🔍 Details

#### 🧱 Textures
- `NO`, `SO`, `WE`, `EA` – Wall texture paths for each direction.

#### 🎨 Colors
- `F R,G,B` – Floor color.  
- `C R,G,B` – Ceiling color.

#### 🗺️ Map Layout
- `1` = wall  
- `0` = empty space  
- `N`, `S`, `E`, `W` = player start + orientation  
- `D` = door *(bonus)*

> ⚠️ The map must be **completely surrounded by walls (`1`)** and contain **exactly one** player starting position.

### 🧪 Testing

#### ✅ Parsing
- Validate texture paths (`NO`, `SO`, `WE`, `EA`)
- Validate color format (`F`, `C`)
- Handle malformed configs and wrong file extensions

#### ✅ Map Validity
- Must be enclosed by walls
- Must have one player start position

#### ✅ Rendering
- Check correct wall textures per orientation
- Floor/ceiling colors should change properly
- Correct fisheye distortion

#### ✅ Movement & Collision
- Smooth player movement
- Proper collision with walls and doors

#### ✅ Doors *(Bonus)*
- Doors should open/close with space
- Player can’t move through closed doors

#### ✅ Input Handling
- All keys work (ESC quits, movement keys, etc.)
- View updates with multiple key presses
- Window redraws on minimize/restore

#### ✅ Reliability
- No crashes with bad input
- Clean memory (use `valgrind` to check)

---

### 🤝 Contributors
This project was completed collaboratively by our 42 team.  
All members contributed to parsing, the game engine, and testing.  

---

### 📄 License
This project is licensed under the **MIT License**.  
See the `LICENSE` file for more information.
