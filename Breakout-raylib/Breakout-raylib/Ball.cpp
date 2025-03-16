#include "raylib.h"
#include "ball_class.h"

// Costruttore
Ball::Ball() {
    speedX = -6.5;
    speedY = -6.5;
    radius = 12.0;
    pos.x = 800 / 2;
    pos.y = 300;
}

// Aggiorna la posizione della palla e controlla collisioni
void Ball::Update(Rectangle& Paddle) {
    pos.x += speedX;
    pos.y += speedY;
    checkCollisionsWall(); 
    checkCollisionsPaddle(Paddle);
}

// Disegnare palla
void Ball::DrawBall() {
    DrawCircle(pos.x, pos.y, radius, YELLOW); //Disegna la palla
    DrawCircleLines(pos.x, pos.y, radius, BLACK);
}

// Rimbalzo sul muro
void Ball::checkCollisionsWall() {
    if (pos.x <= 10 || pos.x >= (GetScreenWidth() - 10)) {
        speedX *= -1;
    } 
    if (pos.y <= 10 || pos.y >= (GetScreenHeight() - 10)) {
        speedY *= -1;
    }
}

// Rimbalzo sul paddle
void Ball::checkCollisionsPaddle(Rectangle paddle) {
    if (CheckCollisionCircleRec(pos, radius, paddle)) {
        speedY *= -1;
    }
}
