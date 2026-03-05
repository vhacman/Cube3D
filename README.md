*This project has been created as part of the 42 curriculum by vhacman, ilnassi.*

---

# cub3D - Cyber Escape

## Description

cub3D is a first-person 3D maze game built using ray-casting technology, inspired by the classic Wolfenstein 3D. This implementation, titled "Cyber Escape," puts players in the role of an awakened resistance fighter trapped inside the Matrix—a virtual prison created by the NeoCorp corporation.

The player must navigate through a three-level virtual labyrinth, avoiding enemy Glitches and Security IA units, to reach the Core and destroy the Matrix generator, freeing humanity from digital captivity.

### Core Features

- **Ray-casting engine**: Real-time 3D rendering using DDA algorithm
- **Wall textures**: Different textures for N/S/E/W facing walls
- **Floor and ceiling colors**: Configurable RGB colors
- **First-person movement**: WASD controls with rotation via arrow keys
- **.cub file parser**: Scene configuration via text files

### Controls

| Key | Action |
|-----|--------|
| W | Move forward |
| S | Move backward |
| A | Strafe left |
| D | Strafe right |
| ← | Rotate left |
| → | Rotate right |
| ESC | Quit game |

## Instructions

### Compilation

```bash
# Clone the repository
git clone https://github.com/vhacman/Cube3D.git
cd Cube3D

# Compile the project
make

# Run with a map
./cub3D maps/test.cub
```

### Map File Format

The game uses `.cub` files with the following structure:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

1111111111
1000000001
100N000001
1111111111
```

- **NO/SO/WE/EA**: Texture paths for each wall direction
- **F**: Floor color (R,G,B)
- **C**: Ceiling color (R,G,B)
- **Map**: 0 = empty, 1 = wall, N/S/E/W = player start position

### Makefile Rules

| Rule | Description |
|------|-------------|
| `make` | Compile the game |
| `make clean` | Remove object files |
| `make fclean` | Remove all generated files |
| `make re` | Clean and recompile |
| `make bonus` | Compile with bonus features |

### Bonus Features

When the mandatory part is complete, bonus features can be enabled:

- Wall collision detection
- Minimap system
- Interactive doors
- Animated sprites
- Mouse rotation

## Resources

### Ray-casting Theory

- [Lodev Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Comprehensive guide to ray-casting algorithms
- [DDA Algorithm Explained](https://en.wikipedia.org/wiki/Digital_Differential_Analyzer) - Grid traversal mathematics

### MiniLibX Documentation

- [42 MiniLibX Docs](https://harm-smits.github.io/42docs/libs/minilibx) - Official documentation
- [MiniLibX GitHub](https://github.com/42Paris/minilibx-linux) - Source code and examples

### 42 School Resources

- [Libft](https://github.com/42-Student/Libft) - Custom C library
- [Norminette](https://github.com/42School/norminette) - Code style checker

### External References

- [Wolfenstein 3D History](http://users.atw.hu/wolf3d/) - Original game
- [Game Programming Patterns - Component](https://gameprogrammingpatterns.com/component.html) - Architecture patterns

---

## AI Usage

AI tools were used to assist with the following tasks:

- **Code structure planning**: Helped design the modular architecture (parser, raycasting, render, events, utils)
- **Algorithm research**: Explained DDA algorithm and ray-casting mathematics
- **Documentation**: Generated README and code comments
- **Debug assistance**: Helped identify potential edge cases in the parser

All AI-generated code was reviewed, understood, and modified as needed by the authors. The team maintains full understanding and responsibility for all implemented functionality.

---

## Project Structure

```
Cube3D/
├── Makefile           # Build system
├── include/          # Header files
│   ├── cub3d.h
│   ├── structs.h
│   └── defines.h
├── src/
│   ├── main.c        # Entry point
│   ├── parser/       # .cub file parsing
│   ├── raycasting/  # Ray-casting engine
│   ├── render/      # Image rendering
│   ├── events/      # Input handling
│   └── utils/       # Utility functions
├── libft/            # Custom C library
└── maps/            # Test maps
```

---

## Technical Details

- **Language**: C
- **Graphics**: MiniLibX
- **Algorithm**: DDA Ray-casting
- **Standards**: Norminette (42 school norm)
- **Compilation**: `cc -Wall -Wextra -Werror -lmlx -lXext -lX11 -lm`

---

*Project for 42 School - 2026*
