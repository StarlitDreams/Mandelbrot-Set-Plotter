#include <SDL2/SDL.h>
#include <numeric>
#include <complex>
#include <cmath>

int is_in_set(std::complex<double> c) {
    std::complex<double> z(0, 0);

    for (int i{0}; i < 1000; i++) {
        z = std::pow(z, 2) + c;
        if (std::norm(z) > 40) {
            return i;
        }
    }
    return 0;
}

double custom_lerp(double a, double b, double f) {
    return a + f * (b - a);
}

void get_colour(int iters, Uint8& r,Uint8& g,Uint8& b){
    if(iters==0){
        r = g = b =0;
    }else{
        double t =  static_cast<double>(iters)/1000.0;

        r = static_cast<Uint8>(255 * (1 - t)); 
        g = static_cast<Uint8>(255 * (0.5 * (1 - t))); 
        b = static_cast<Uint8>(255); 
    }
}
int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if (SDL_CreateWindowAndRenderer(2000, 2000, 0, &window, &renderer) != 0) {
        SDL_Quit();
        return 1;
    }

    SDL_RenderSetScale(renderer, 2, 2);

    for (double x{0.0}; x < 1.0; x += 0.001) {
        for (double y{0.0}; y < 1.0; y += 0.001) {
            double point_x = custom_lerp(-2.0, 2.0, x);
            double point_y = custom_lerp(-2.0, 2.0, y);
            int iters = is_in_set(std::complex<double>(point_x , point_y));
            Uint8 r, g, b;
            get_colour(iters, r, g, b);
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
        }
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(1000000000);


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


// g++ -fdiagnostics-color=always -g C:\Github\Mandelbrot-Set-Plotter\mandelbrot.cpp -o C:\Github\Mandelbrot-Set-Plotter\mandelbrot.exe -IC:/msys64/mingw64/include/SDL2 -LC:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -mconsole