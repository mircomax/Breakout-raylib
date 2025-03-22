#ifndef BLOCK_CLASS_H
#define BLOCK_CLASS_H
#include "ball_class.h"
#include "raylib.h"

class Block {
public:
    float width, height; // Dimensioni del blocco
    Vector2 pos; // Posizione
    Rectangle blocco; // Rettangolo effettivo da disegnare
    bool active; // Capire se il blocco è attivo o no

    // Costruttore
    Block();

    // Metodi
    void CreaPosizione(int i);
    void CheckCollisionsBall(Ball& palla1);
};

#endif