![](project_additional/wallpaper.png)

# mod1

The idea of this of the projection is simulate water movement on terrain, defined by a given file. \
I used an algorithm, called Pipe-method, it is used along with height-field model. It works like this : 
one creates a 2D array for storing water depth values, along with array for storing flow values.
(The flow is a water movement from given point to its neighbors.)
At each iteration of algorithm loop one updates flow values for each point and then updates depth according to new flow values.    

### Scenarios

* Rain
* Heavy rain
* Well
* Wave
* Four waves
* Flood

### Noise 

Noise is feature, that allows to generate better terrain.
Noise configuration is passed to binary file as second argument. 
You can template of the configuration in noise folder.
Generally every line of configuration file it looks like this :

```
[noise type] : [frequency] [range] (offset) (power) 
``` 

## Usage

Install some packages :
```
brew install glew
brew install glfw
brew install glm
brew install freetype
```
To compile program :
```
cd build
make
```

To run program pass terrain file and optionally noise file to binary

```
./build/mod1 [map file] (noise file)
``` 

## References

* [OpenGL 3D Game Tutorial](https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP) - OpenGL game engine
* [Equilinox - Game Menu](https://www.youtube.com/watch?v=TnWt31irobo&list=PLRIWtICgwaX1gcSZ8qj8Q473tz7PsNmpR&index=122) - GUI on OpenGL
* [Learn OpenGL](https://habr.com/ru/post/473990/) - Big OpenGL tutorial
* [OpenGL Low-Poly Terrain Tutorial](https://www.youtube.com/watch?v=l6PEfzQVpvM&list=PLRIWtICgwaX19nkYWDV-U1Ng2C2jnFFLt) - Tutorial on creating low-poly models
* [Tutorial: Simple start with OpenCL and C++](http://simpleopencl.blogspot.com/2013/06/tutorial-simple-start-with-opencl-and-c.html) -  Tutorial on OpenCL C++ Wrapper
* [Making maps with noise functions](https://www.redblobgames.com/maps/terrain-from-noise/) - Improving terrain model using Perlin noise
* ["Large-Scale Water Simulation in Games"](https://tutcris.tut.fi/portal/files/4312220/kellomaki_1354.pdf) - Book about water simulation
* ["Real-Time Fluid Simulation Using Height Fields"](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.138.5153&rep=rep1&type=pdf) - Thesis about water simulation
