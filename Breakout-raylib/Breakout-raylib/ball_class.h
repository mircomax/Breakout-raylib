#ifndef BALL_CLASS_H
#define BALL_CLASS_H

#include "raylib.h"

class Ball {
public:
    float radius;     // Raggio
    float speedX, speedY; // Velocità
    Vector2 pos; // Posizione
  
    // Costruttore
    Ball();

    // Metodi
    void DrawBall();
    void Update(Rectangle& Paddle);
    void checkCollisionsWall();
    void checkCollisionsPaddle(Rectangle paddle);
    void checkBallOutOfBounds(); // Controllare se la palla colpisce il muro basso
    Vector2 GetPosition();
    void InvertiVelocitaY();
    void InvertiVelocitaX();
};

#endif