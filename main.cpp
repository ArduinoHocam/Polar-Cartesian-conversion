#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#define SCR_WDT 640
#define SCR_HGT 480

const int SCR_CEN_X = SCR_WDT / 2;
const int SCR_CEN_Y = SCR_HGT / 2;

void DrawCircle(SDL_Renderer *r, int red, int green, int blue, int rad){
    int radius = rad;
    int new_x = 0;
    int new_y = 0;
    int old_x = SCR_CEN_X + radius;
    int old_y = SCR_CEN_Y;
    float step = (M_PI * 2) / 50;

    SDL_SetRenderDrawColor(r, red, green, blue, 255);

    for (float theta = 0; theta <= (M_PI * 2); theta += step)
    {
        new_x = SCR_CEN_X + (radius * cos(theta));
        new_y = SCR_CEN_Y - (radius * sin(theta));

        SDL_RenderDrawLine(r, old_x, old_y, new_x, new_y);

        old_x = new_x;
        old_y = new_y;
    }

    new_x = SCR_CEN_X + (radius * cos(0));
    new_y = SCR_CEN_Y - (radius * sin(0));
    SDL_RenderDrawLine(r, old_x, old_y, new_x, new_y);
}


constexpr float degreeToRadians(int degree){
    return static_cast<float>(degree*M_PI/180.0);
}


int center_x = SCR_CEN_X;
int center_y = SCR_CEN_Y;
int theta = 0;
int radius = 60;
int end_x = center_x;
int end_y = center_y;
int main(int argc, char *argv[])
{

    if (SDL_Init(SDL_INIT_VIDEO) == 0){
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        if (SDL_CreateWindowAndRenderer(SCR_WDT, SCR_HGT, 0, &window, &renderer) == 0){
            SDL_bool done = SDL_FALSE;
            while (!done){
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                DrawCircle(renderer, 255, 255, 255, 60);
                end_x = radius*cos(degreeToRadians(theta)) + center_x;
                end_y = -radius*sin(degreeToRadians(theta)) + center_y;
                SDL_RenderDrawLine(renderer, center_x, center_y, end_x, end_y);
                SDL_RenderPresent(renderer);
                theta++;
                SDL_Delay(10);
                while (SDL_PollEvent(&event)){
                    if (event.type == SDL_QUIT){
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer){
            SDL_DestroyRenderer(renderer);
        }
        if (window){
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}
