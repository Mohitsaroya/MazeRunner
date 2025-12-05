# MazeRunner

A terminal-based maze game written in C using ncurses.

## Project Overview

**MazeRunner** is an interactive maze game where the player navigates through a maze, encounters obstacles, and attempts to reach the exit. The game features a full menu system, pause functionality, level progression, and retry mechanics-all implemented in the terminal using the ncurses library. In the maze you'll find trapped victims of evil person called Dave. Dave has trapped them for years, and if you dont get out, you'll meet the same fate as them; trapped for eternity is dave's mazes, going mad day by day.

The game is divided into 2 levels:

**Level 1**: players get to interact with 1 NPC, a poor trapped victim of Dave's sadistic nature. You'll have to get to the door with $ sign to reach the exit, but wait, Dave has other plans for you.

**Level 2**: After you complete level 1, dave will trap you in a separate maze. You will have to exit the maze through another door with $ on it before time runs out. If you don't, Dave will destroy the maze, but don't worry as you get unlimited retries to finish the level.


## Features

- **Title and Menu Screens**: ASCII-art splash screens and intuitive menu navigation.
- **Multi-Level Gameplay**: Multiple levels with increasing difficulty.
- **Player Movement**: Real-time keyboard input for movement (arrow keys).
- **Pause Menu**: In-game pause with options to resume, return to main menu, or quit.
- **Retry Mechanism**: Players can retry a level on failure.
- **Quit Confirmation**: Confirmation prompt before exiting the game.
- **Documented Codebase**: Comprehensive Doxygen documentation for all public interfaces and implementations.

## Requirements

- **C Compiler** (gcc or clang)
- **ncurses Development Library** (`libncurses-dev` on Debian/Ubuntu, `ncurses` on macOS via Homebrew)
- **GNU Make**
- **Doxygen** (optional, for generating HTML documentation)

### Installing Dependencies

**Ubuntu/Debian:**
```bash
sudo apt-get install build-essential libncurses-dev doxygen graphviz
```

**macOS (with Homebrew):**
```bash
brew install ncurses doxygen graphviz
```

## Running the Game

Go to bin folder and write the following to run the game
```bash
./appGame
```

Or from the `src` directory:
```bash
make run
```

## Building

From the repository root, type into the terminal:

```bash
cd src
make
```
This compiles the project and produces an executable.

## Project Structure

```
.
├── Doxyfile
├── README.md
├── bin
│   └── appGame
├── doc
│   ├── html/
│   └── latex/
└── src
    ├── Makefile
    ├── gameCards.c
    ├── gameCards.h
    ├── interface.c
    ├── interface.h
    ├── level1.c
    ├── level1.h
    ├── level2.c
    ├── level2.h
    ├── main.c
    ├── maze.c
    ├── maze.h
    ├── movement.c
    ├── movement.h
    ├── npc.c
    └── npc.h
```

## Game Controls

| Key | Action |
|-----|--------|
| **Arrow Keys** | Move Player (in-game) |
| **P** | Play / Start Game |
| **Q** | Quit (with confirmation) |
| **P** | Pause / Resume |
| **M** | Main Menu (from pause) |

## Code Documentation

All public interfaces and implementations include Doxygen-style documentation blocks. Key modules:

- `gameCards.h/c`: Rendering of title, menu, pause, and level screens
- `interface.h/c`: High-level UI helpers (window creation, menu handling, pause/retry flows)
- `level1.h/c`: Level 1 game loop and logic
- `level2.h/c`: level 2 game loop and logic
- `main.c`: The file that calls other files to keep the game flow simple
- `maze.h/c`: Maze drawing and layout logic
- `movement.h/c`: Player movement state and direction handling
- `npc.h/c`: The NPCs Dave and the lost players

## Building and Testing

To build and run tests or clean the build:

```bash
make clean      # Remove object files and executables
make run        # Compiles and runs the game
```

## Notes

- The game uses ncurses for terminal rendering; ensure your terminal supports ncurses.
- Doxygen configuration is optimized for C code (`OPTIMIZE_OUTPUT_FOR_C = YES`).
- The codebase includes inline comments and Doxygen docstrings for maintainability.


## Authors

- Mohit Saroya: UI, game logic, game flow
- Evan Wong: Maze design, movement logic