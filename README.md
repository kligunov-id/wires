# Wires

Wires is a graphical [WireWorld](https://en.wikipedia.org/wiki/Wireworld) cellular automaton simulator written in C++.

## Building and running

#### SDL2 Installation

On Linux you should just install `libsdl2` using your packet manager, this should work without any extra effort.

On Windows download official devel package from [here](https://github.com/libsdl-org/SDL/releases/). Unzip that under `C:\Program Files\SDL2`.

#### Building 

Create `build` folder and run `cmake --build` from it.

#### Running

You should find your executable ready in `\build\wires` folder.

With some setups (notably when compiling with MSVC)the executable will fail to locate the library. In such case you can just manually copy `SDL.dll` from your SDL distribution (`C:\Program Files\SDL2\lib\x64\SDL.dll`). This is probably due to the poor CMake setup or it can be fixed by running CMake installation process.

## Controls


#### Indication

Currently there is  unfortunately no indication of application status, settings or brush color.

#### Drawing

Keys `0`, `1`, `2`, `3` choose `empty`, `wire`, `head` and `tail` cell type to draw with. Left mouse click draws places them.

#### Suspending

The `space` key can be used to pause/unpause simulation.

#### Navigation

Arrow keys can be used to move around the field

#### Saving

Field state is automatically saved and loaded on closing and startup. You can find it in `.save` file next to the executable

## Future plans


Some of the features to implement:

- Graphical indication
- Smooth drawing
- Copy-paste, bank of snapshots
- Screen resizing
