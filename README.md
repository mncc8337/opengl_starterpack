# OpenGL notes
some usefull OpenGL resources and notes i found on the net

## Install freeglut
### Pre-built
- Windows pre-built binary are already on `./lib/` with name `*.a`
- Windows `libfreeglut.dll` file is included on `./`
- Linux pre-built binary are already on `./lib/` with name `*.o`
If for any reason the pre-built bin are not working then delete `./lib/` and `libfreeglut.dll` then see below to manually build it.
### manually build
- Install [cmake](https://cmake.org/) and `make`
- Run
```
    git clone https://github.com/FreeGLUTProject/freeglut.git
    cd freeglut
    cmake .
    make
```
- Copy `./freeglut/include/` and `./freeglut/lib/` contents to `./include/` and `./lib/`
#### Notes
- On Windows after run `make` you need to copy `./freeglut/bin/libfreeglut.dll` to `./` in order to run the executable file
- Remember to test demos on `./freeglut/bin/` to make sure freeglut was built correctly

## Build using g++
### Linux
`g++ file.name -I./include -L./lib -lGL -lglut -o filename`
### Windows
`g++ file.name -I./include -L./lib -lopengl32 -lfreeglut -o filename.exe`

## Examples sources
[This](https://cs.lmu.edu/~ray/notes/openglexamples/)
