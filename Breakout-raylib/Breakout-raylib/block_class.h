#ifndef BLOCK_CLASS_H
#define BLOCK_CLASS_H

#include "raylib.h"

class Block {
public:
    float width, height; // Dimensioni del blocco
    Vector2 pos; // Posizione
    Rectangle blocco; // Rettangolo effettivo da disegnare

    // Costruttore
    Block();

    // Metodi
    void CreaPosizione(int i);
};

#endif