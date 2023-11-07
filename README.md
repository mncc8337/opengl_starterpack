# OpenGL notes
some usefull OpenGL resources and notes i found on the net

## Install freeglut
### Pre-built
- Windows pre-built binaries are already on `./lib/` with name `libfreeglut.*`
- Windows `libfreeglut.dll` file is included on `./`
- Linux pre-built binaries are already on `./lib/` with name `libglut.*`  
If for any reason the pre-built binaries are not working then delete the contents of `./lib/` and `libfreeglut.dll` and see below to manually build it.
### Manually build
- Install [cmake](https://cmake.org/), [git](https://git-scm.com/) and `make`
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
**DO NOT change the order of parameters!**
### Linux
`g++ file.name -I./include -L./lib -lGL -lGLU -lglut -o filename`
### Windows
`g++ file.name -I./include -L./lib -lopengl32 -lfreeglut -o filename.exe`

## Examples sources
[This](https://cs.lmu.edu/~ray/notes/openglexamples/)
