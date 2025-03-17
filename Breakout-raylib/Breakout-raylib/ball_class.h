#ifndef BALL_CLASS_H
#define BALL_CLASS_H

#include "raylib.h"

class Ball {
private:
    float radius;     // Raggio
    float speedX, speedY; // Velocit�
    Vector2 pos; // Posizione
public:  
    // Costruttore
    Ball();

    // Metodi
    void DrawBall();
    void Update(Rectangle& Paddle);
    void checkCollisionsWall();
    void checkCollisionsPaddle(Rectangle paddle);
};

#endif