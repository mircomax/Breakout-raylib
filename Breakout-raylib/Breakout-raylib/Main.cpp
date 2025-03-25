#include "raylib.h"
#include <iostream>
#include "Game_functions.h"
#include "ball_class.h"
#include "block_class.h"

// Program main entry point


int main(void)
{
    srand(time(NULL));
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int numeroBlocchi = 96; // Numero tot dei blocchi nel livello

    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    InitWindow(screenWidth, screenHeight, "Breakout game!");

    Ball palla1;
    // Creazione dei blocchi
    Block* blocchi = new Block[numeroBlocchi]; // Alloca dinamicamente i blocchi

    int paddleWidth = 100, paddleY = screenHeight - 100, paddleHeight = 30;
    float paddleX = (screenWidth / 2) - 50, paddleSpeed = 7;

    for (int i = 0; i < numeroBlocchi; i++) {
        blocchi[i].CreaPosizione(i); // Creare tutti i blocchi iniziali
    }

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        Rectangle Paddle = { (float)paddleX, (float)paddleY,  (float)paddleWidth,  (float)paddleHeight};
        checkMovimentopaddle(paddleSpeed, paddleX); // Muovere il paddle

        //Aggiorna posizione della palla
        palla1.Update(Paddle);

        for (int i = 0; i < numeroBlocchi; i++) {
            blocchi[i].CheckCollisionsBall(palla1); // Controllare se la palla colpisce i blocchi
            if (blocchi[i].collisioneGestita) break; // Alla prima collisione interrompe il ciclo in modo da non prenderne una doppia
        }

        // Resetta la variabile della collisione e disattiva i blocchi colpiti
        for (int i = 0; i < numeroBlocchi; i++) {
            blocchi[i].collisioneGestita = false; 
            blocchi[i].UpdateBlocks();
        }
       
    BeginDrawing();

    ClearBackground(BLACK);
        // Disegnare i blocchi
        for (int i = 0; i < numeroBlocchi; i++) {
            DrawRectangleRec(blocchi[i].blocco, blocchi[i].coloreBlocco);
            DrawRectangleLinesEx(blocchi[i].blocco, 1, BLACK);
        }
            disegnaScritte();
        // Disegna Paddle giocatore 1 
            DrawRectangleRounded(Paddle, (float)0.8, 0, RAYWHITE);
            DrawRectangleRoundedLines(Paddle, (float)0.8, 0, 1, YELLOW);
        // Disegna palla
            palla1.DrawBall();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    delete[] blocchi; // Rilascia la memoria a fine programma
    // De-Initialization
    //-----------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //-----------------------------------------------------------------------------------

    return 0;
}
