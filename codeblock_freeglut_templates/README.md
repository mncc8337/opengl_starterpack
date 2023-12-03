# Using freeglut on Code::Blocks (Windows)
## Installation
### Preparing the binaries
- download the [windows binaries](https://www.transmissionzero.co.uk/software/freeglut-devel/) then unzip the contents it nto `freeglut`
- move folder `freeglut/include` to `C:\Program Files\CodeBlocks\MinGW`
- move folder `freeglut/lib` (`freeglut/lib/x64` if 64bit) contents to `C:\Program Files\CodeBlocks\MinGW`
- move `freeglut/bin/freeglut.dll` (`freeglut/bin/x64/freeglut.dll` if 64bit) to `C:\Windows`
### Setting up Code::Blocks
- copy `wizard.script` in repo folder to `C:\Program Files\CodeBlocks\share\CodeBlocks\templates\wizard\glut`
- copy `glut.cbp` in repo folder to `C:\Program Files\CodeBlocks\share\CodeBlocks\templates`
### Creating new project
- start up Code::Blocks
- choose `Create New Project` then choose `Glut project`
- use `C:\Program Files\CodeBlocks\MinGW` as GLUT's location