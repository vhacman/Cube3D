# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

```bash
make        # Build cub3D executable
make bonus  # Build with bonus features
make re     # Full recompile (fclean + all)
make clean  # Remove object files
make fclean # Remove object files + executable
```

Run the game:
```bash
./cub3D maps/example.cub
```

The project uses strict compilation flags: `-Wall -Wextra -Werror`. `libft` (custom C library) is compiled first automatically. No test suite exists — validate manually by running the executable.

## Architecture

This is a 42 School raycasting engine (Wolfenstein-style 3D renderer) written in C, using MiniLibX (X11) for graphics.

### Data Flow

```
.cub file → Parser → t_game struct → Raycaster → Renderer → Screen
                                    ↑
                               Keyboard Events
```

### Core Struct: `t_game` (`include/structs.h`)

The single `t_game` instance is passed everywhere. It holds:
- `mlx` / `win` — MiniLibX context and window
- `img` — single render buffer (written pixel-by-pixel each frame)
- `textures[4]` — NO/SO/WE/EA wall textures (indexed by `TEX_NO/SO/WE/EA`)
- `map` — 2D char grid + player start position/direction
- `player` — position (double), direction vector, camera plane
- `keys` — bitmask-style flags for held keys (updated on press/release events)
- `floor_color`, `ceiling_color` — packed int RGB

### Module Responsibilities

| Directory | Role |
|-----------|------|
| `src/events/` | MiniLibX init, window/event hooks, game loop via `mlx_loop_hook` |
| `src/events/keys.c` | Key press/release updates `t_keys` flags; movement applied each frame |
| `src/raycaster/player_move.c` | Per-frame movement: translates key flags → position/rotation changes, with wall collision |
| `src/raycaster/raycaster.c` | **TODO** — main DDA raycasting loop (one ray per screen column) |
| `src/raycaster/dda.c` | **TODO** — DDA grid traversal to find wall hit distance/side |
| `src/render/render.c` | Clears image buffer, triggers raycaster, calls `mlx_put_image_to_window` |
| `src/render/draw_walls.c` | **TODO** — renders textured wall columns using ray hit data |
| `src/render/draw_floor_ceiling.c` | **TODO** — fills floor/ceiling pixels |
| `src/render/textures.c` | **TODO** — loads `.xpm` textures via `mlx_xpm_file_to_image` |
| `src/parser/` | **TODO** — parses `.cub` config file into `t_game` (textures, colors, map grid) |
| `src/utils/` | Error handling, memory cleanup, color/pixel helpers |

### Map File Format (`.cub`)

```
NO ./textures/north.xpm   # Wall texture paths
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0               # Floor RGB
C 225,30,0                # Ceiling RGB
                          # (blank line)
1111111111
100N000001                # N/S/E/W = player start + facing direction
1111111111
```

Map cells: `1` = wall, `0` = floor, `N/S/E/W` = player spawn. Map must be surrounded by walls (closed).

### Key Constants (`include/defines.h`)

- Screen: `SCREEN_WIDTH 1280`, `SCREEN_HEIGHT 720`
- Textures: `TEXTURE_WIDTH 64`, `TEXTURE_HEIGHT 64`
- Speed: `MOVE_SPEED 0.05`, `ROT_SPEED 0.03`
- Texture indices: `TEX_NO 0`, `TEX_SO 1`, `TEX_WE 2`, `TEX_EA 3`
- Keycodes are Linux X11 values (e.g., `KEY_W 119`, `KEY_ESC 65307`)

### Pixel Writing Pattern

MiniLibX renders via a pixel buffer. The pattern used throughout `render/`:
```c
// Get buffer address via mlx_get_data_addr, then write pixels:
*(int *)(img->addr + (y * img->line_length + x * (img->bpp / 8))) = color;
```

### Implementation Status

Complete: events, keyboard input, player movement, render loop, memory cleanup, utility functions.

**Not yet implemented** (the core work remaining): `src/main.c`, all of `src/parser/`, `src/raycaster/raycaster.c`, `src/raycaster/dda.c`, `src/render/draw_walls.c`, `src/render/draw_floor_ceiling.c`, `src/render/textures.c`.

The project cannot currently compile due to the empty `main.c`.

## 42 School Constraints

- Only allowed standard C functions: `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `calloc`, `perror`, `strerror`, `exit`, math functions, and MiniLibX functions
- **Use `calloc` instead of `malloc`** for all allocations — guarantees zero-initialization, prevents use of uninitialized memory
- Code must comply with the 42 Norm (enforced by `norminette`)
- No memory leaks (validate with Valgrind)
- All files compiled with `-Wall -Wextra -Werror`
