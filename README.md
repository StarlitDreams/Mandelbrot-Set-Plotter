# Mandelbrot Set Plotter

This project is a simple Mandelbrot set plotter written in C++ using SDL2. The Mandelbrot set is a famous fractal defined by iterating a complex function. This program generates a visual representation of the Mandelbrot set by calculating the number of iterations it takes for each point in the complex plane to escape a given radius.

## Features

- Computes and visualizes the Mandelbrot set.
- Uses SDL2 for rendering.
- Custom linear interpolation function for coordinate mapping.
- Adjustable color scheme based on the iteration count.

## Example
![image](https://github.com/StarlitDreams/Mandelbrot-Set-Plotter/assets/40852436/d95ac0bc-7ef1-40ff-90c6-9ec4e92b29ab)

## Prerequisites

- SDL2 library
- C++ compiler (e.g., g++)

## Building and Running the Program

### Windows

1. Ensure you have the SDL2 library installed. You can download it from [SDL2 Downloads](https://www.libsdl.org/download-2.0.php) or using MSYS
   ```sh
   pacman -S mingw-w64-x86_64-SDL2
3. Clone this repository or download the source code.
4. Open a terminal or command prompt and navigate to the directory containing the source code.
5. Compile the code using the following command:

   ```sh
   g++ -fdiagnostics-color=always -g path_to_your_source_code/mandelbrot.cpp -o path_to_your_output_directory/mandelbrot.exe -Ipath_to_sdl2_include -Lpath_to_sdl2_lib -lmingw32 -lSDL2main -lSDL2 -mconsole

## License

This project is licensed under the MIT License. See the LICENSE file for details.
