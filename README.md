# OpenGL notes
some usefull OpenGL resources and notes i found on the net

## Install freeglut
### Pre-built
- Download Windows pre-built [here](https://www.transmissionzero.co.uk/software/freeglut-devel/)
### Manually build
- Install [cmake](https://cmake.org/), [git](https://git-scm.com/) and `make`
- Run
```
    git clone https://github.com/glfw/glfw.git
    cd freeglut
    cmake .
    make
```
- Copy `./freeglut/include/` and `./freeglut/lib/` contents to `./include/` and `./lib/`
#### Notes
- On Windows after run `make` you need to copy `./freeglut/bin/libfreeglut.dll` to `./` in order to run the executable file
- Remember to test demos on `./freeglut/bin/` to make sure freeglut was built correctly

## Install glfw
### Pre-built
- Download Windows pre-built [here](https://www.glfw.org/download.html)
### Manually build
Too lazy to write anything here

## Build using g++
**DO NOT change the order of parameters!**
### freeglut
#### Linux
`g++ file.name -I./include -lGL -lGLU -lglut -o filename`
#### Windows
`g++ file.name -I./include -lopengl32 -lglu32 -lfreeglut -o filename.exe`
### glfw
#### Linux
`g++ file.name -I./include -lGL -lGLU -lglfw -o filename`
#### Windows
`g++ file.name -I./include -lopengl32 -lglu32 -lglfw3 -o filename.exe`

## Examples sources
### glut
- [OpenGL Examples](https://cs.lmu.edu/~ray/notes/openglexamples/)
### glfw
- [GLFW example code](https://www.glfw.org/documentation.html)
