# OpenGL examples
some usefull OpenGL resources i found on the net

## Install freeglut
run
```
    git clone https://github.com/FreeGLUTProject/freeglut.git
    cd freeglut
    cmake .
    make
```
then copy freeglut/include and freeglut/lib contents to ./include and ./lib

## Build using g++
### Linux
`g++ -I./include -L./lib -lGL -lglut file.name -o filename`
### Windows
`g++ -I./include -L./lib -lopengl32 -lfreeglut file.name -o filename.exe`
<!-- -lopengl32 -lglew -lfreeglut -lgdi32 -luser32 -->

## sources
(This)[https://cs.lmu.edu/~ray/notes/openglexamples/]