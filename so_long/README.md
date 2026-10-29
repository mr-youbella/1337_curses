# so_long

A Minecraft-themed tile game: collect every item, then reach the exit.

[Repository](../README.md) · **C / MiniLibX** · **Score: 125**

## Playing the map

The game loads a `.ber` file and draws 64-pixel tiles using the XPM assets in [img/](img/). Walls block movement, collectibles disappear when picked up, and the exit becomes usable after the last collectible. The mandatory version prints successful move counts to the terminal.

| Map character | Meaning |
| --- | --- |
| `1` | Wall |
| `0` | Open tile |
| `P` | Player start; exactly one |
| `C` | Collectible; at least one |
| `E` | Exit; exactly one |
| `Z` | Bonus-only zombie hazard; the bonus map requires at least one |

Maps must be rectangular and enclosed by walls. Validation runs two flood fills on copies of the map: one checks reachability of collectibles and the exit, and the other treats the exit as blocked so collectibles cannot depend on walking through it. Bonus validation also treats zombie tiles as blocked.

## Build and run

The Makefile targets **macOS** and links the original MiniLibX with OpenGL and AppKit. It expects `<mlx.h>` and `libmlx` to be installed in the compiler/linker search paths; MiniLibX is not bundled here. A C compiler and Make are also required.

Run from this directory so relative `img/` paths resolve:

```bash
make
./so_long mandatory/maps/map.ber
```

The bonus adds an on-screen move count and two-frame zombie animation. Stepping onto a zombie ends the game; the hazards stay on their map tiles.

```bash
make bonus
./so_long_bonus bonus/maps/map.ber
```

| Control | Action |
| --- | --- |
| W / A / S / D or arrow keys | Move one tile |
| Escape or window close | Exit |

## Code organization

Both [mandatory/](mandatory/) and [bonus/](bonus/) separate map loading, validation, movement, and drawing. `check_map2*` and `check_map3*` contain the flood-fill passes; `control*` handles collisions and input; `draw_map*` chooses sprites. Each version includes two sample maps under its `maps/` directory.

## Manual checks

Play a supplied map, check that walls block movement, collect every item, and approach the exit before and after collection. For validation checks, use copies of maps with an open border, an extra player, or an unreachable collectible. The graphics session has to be checked interactively; no automated game test is bundled.

`make clean`, `make fclean`, and `make re` remove objects, remove binaries, and rebuild the mandatory game respectively.

[Project subject](../Subjects/so_long.subject.pdf) · [Back to 1337 Curses](../README.md)
