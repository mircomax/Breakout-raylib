#include "raylib.h"
#include "ball_class.h"
#include <format>
#include <iostream>

const float speedX_iniziale = -4.5; // Velocità iniziale
const float speedY_iniziale = -4.5;

// Costruttore
Ball::Ball() {
    speedX = speedX_iniziale;
    speedY = speedY_iniziale;
    radius = 12.0;
    pos.x = 800 / 2;
    pos.y = 500;
}

// Aggiorna la posizione della palla e controlla collisioni
void Ball::Update(Rectangle& Paddle) {
    pos.x += speedX;
    pos.y += speedY;
    checkCollisionsWall(); 
    checkCollisionsPaddle(Paddle);
    checkBallOutOfBounds();
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

void Ball::checkBallOutOfBounds() {
    if (pos.y >= GetScreenHeight() - 10) {  // Controlla se la palla colpisce il muro
        pos.x = GetScreenWidth() / 2;
        pos.y = 500;
        speedX = speedX_iniziale; // Reset della velocità iniziale
        speedY = speedY_iniziale;
    }
}

Vector2 Ball::GetPosition() {
    return pos;
}

void Ball::InvertiVelocitaY()
{   
    float casualita = (float)(rand() % 4 + 9) / 10; // Casualità aggiunta alla velocità per rendere il gioco più dinamico
    speedY *= (-1 * casualita);
    std::cout << casualita << std::endl;
}

void Ball::InvertiVelocitaX()
{
    speedX *= -1;
}

