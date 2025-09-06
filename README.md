# Tic-Tac-Toe

A tic-tac-toe game built with C and the MLX graphics library. Features multiplayer support, randomization, and a clean graphical interface.

## 🚀 Quick Start

### Prerequisites
- Make
- MLX (MiniLibX)
- Standard C Library

### Installation & Running

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd tic_tac_toe
   ```

2. **Build the game**
   ```bash
   make
   ```

3. **Run the game**
   ```bash
   ./tic_tac_toe
   ```

That's it! The game window will open and you can start playing immediately.

## 🎮 How to Play

### Controls

**Player 1 (O - Circles):**
- `WASD` - Move cursor
- `SPACE` - Place piece

**Player 2 (X - Crosses):**
- `Arrow Keys` - Move cursor  
- `ENTER` - Place piece

**General Controls:**
- `Mouse Click` - Place piece (works for current player)
- `H` - Toggle help display
- `R` - Randomize cursor positions
- `ESC` - Quit game

### Game Features

- **Random Starting Player** - Each game randomly selects who goes first
- **Random Cursor Positioning** - Cursors start at random positions
- **Smart Cursor Movement** - Cursors automatically move to available positions after moves
- **Visual Feedback** - Green highlight shows valid moves
- **Win Detection** - Automatic win/draw detection with visual line highlighting
- **Auto-Restart** - Games automatically restart after 3 seconds when finished

## 🏗️ Project Structure

```
tic_tac_toe/
├── src/                    # Source code
│   ├── main.c             # Entry point and initialization
│   ├── game.c             # Core game logic
│   ├── hooks.c            # Input handling (keyboard/mouse)
│   ├── render.c           # Graphics rendering
│   ├── textures.c         # Image loading
│   ├── structures.c       # Data structure accessors
│   └── close.c            # Cleanup and exit
├── include/               # Header files
│   ├── game.h            # Main header
│   ├── structures.h      # Data structures
│   └── macros.h          # Constants and key codes
├── assets/               # Game assets
│   ├── PNG/             # PNG textures
│   └── XPM/             # XPM textures (used by MLX)
├── mlx_macos/           # MLX library for macOS
├── obj/                 # Compiled object files
└── Makefile            # Build configuration
```

## 🛠️ Technical Details

### Dependencies
- **MLX (MiniLibX)** - Graphics library for macOS
- **Core Graphics** - For display size detection
- **Standard C Library** - For basic functionality

### Build System
- Uses GNU Make
- Compiles with `-Wall -Wextra -Werror` for strict error checking
- Links with MLX and Core Graphics frameworks

### Architecture
- **Singleton Pattern** - Game state managed through singleton functions
- **Event-Driven** - Uses MLX event hooks for input handling
- **Modular Design** - Separated concerns (logic, rendering, input)

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

### Getting Started

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. **Make your changes**
4. **Test thoroughly**
5. **Submit a pull request**

### Development Guidelines

#### Code Style
- Follow the existing code style and formatting
- Use meaningful variable and function names
- Add documentation comments for new functions
- Keep functions focused and single-purpose

#### Documentation Format
```c
/**
 * * function_name
 * @brief	Brief description of what the function does
 * @param param1	Description of parameter 1
 * @param param2	Description of parameter 2
 * @return	Description of return value
 * @details	Detailed explanation of implementation
 */
```

#### Testing
- Test on macOS (primary platform)
- Verify all controls work correctly
- Test edge cases (game resets, window closing, etc.)
- Ensure no memory leaks or crashes

### Areas for Contribution

#### 🎯 High Priority
- **Linux Support** - Port MLX functionality to Linux
- **AI Player** - Add computer opponent with difficulty levels
- **Sound Effects** - Add audio feedback for moves and wins
- **Game Modes** - Tournament mode, best-of-series, etc.

#### 🎨 Medium Priority
- **Themes** - Different visual themes and color schemes
- **Animations** - Smooth piece placement and win line animations
- **Statistics** - Track wins, losses, and game history
- **Settings Menu** - Configurable game options

#### 🔧 Low Priority
- **Replay System** - Save and replay games
- **Custom Grid Sizes** - 4x4, 5x5 tic-tac-toe variants

### Bug Reports

When reporting bugs, please include:
- Steps to reproduce
- Expected vs actual behavior
- Any error messages or crashes

### Feature Requests

For new features:
- Describe the feature clearly
- Explain why it would be valuable
- Consider implementation complexity
- Check if it fits the project's scope

### Code Review Process

1. **Automated Checks** - Code must compile without warnings
2. **Style Review** - Consistent formatting and naming
3. **Functionality Test** - Feature works as intended
4. **Integration Test** - Doesn't break existing functionality

## 📝 License

This project is open source.

## 🙏 Acknowledgments

- **MLX Library** - For providing the graphics framework
- **42 School** - For the educational foundation
- **Contributors** - Thanks to all who have contributed to this project

## 📞 Support

- **Issues** - Use GitHub Issues for bug reports and feature requests
- **Discussions** - Use GitHub Discussions for questions and ideas
- **Documentation** - Check this README and code comments for help