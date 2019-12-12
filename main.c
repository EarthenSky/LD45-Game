#ifndef RAYLIB
    #define RAYLIB
    #include "raylib.h"
#endif

//#define PLATFORM_WEB  // i dont need this for some reason
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "oper.h"

// Global Variables Definition
int screenWidth = 640;
int screenHeight = 640;

static Texture2D player;
static Texture2D grid;

int health;

// Module Functions Declaration
void InitGame();

void UpdateDrawFrame();     // Update and Draw one frame
void Update();
void Draw();

//----------------------------------------------------------------------------------
// Main Entry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    InitWindow(screenWidth, screenHeight, "arena game");

    // Load images (Textures MUST be loaded after Window init)
    player = LoadTexture("res/fox.png");
    grid = LoadTexture("res/grid.png");
    //background = ConstructBackground(&grid);

    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);

    // De-Initialization
    CloseWindow();  // Close window and OpenGL context

    UnloadTexture(player);
    UnloadTexture(grid);
    //UnloadTexture(background);

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void InitGame() {
    health=5;
}

void UpdateDrawFrame() {
    Update();
    
    BeginDrawing();
        Draw();
    EndDrawing();
}

// Update your variables here
void Update() {

}

void Draw() {
    ClearBackground(RAYWHITE);
    DrawTexture(player, screenWidth/2 - player.width/2, screenHeight/2 - player.height/2, WHITE);
    DrawTexture(grid, 0, 0, WHITE);
    DrawText(FormatText("Health: %d", health), 16, 16, 20, LIGHTGRAY);
}