#include "block_class.h"
#include "raylib.h"
#include <iostream>

// Costruttore
Block::Block() {
    width = 50;
    height = 50;
    pos = { 0, 0 };
    blocco = {(float)pos.x, (float)pos.y, (float)width, (float)height};
}

void Block::CreaPosizione(int i) {
    pos.x = 50 * (i % 16);    // Calcola la colonna
    pos.y = 50 * (i / 16);    // Calcola la riga (cioè quante volte 16 è contenuto in i)
    blocco = { pos.x, pos.y, width, height }; // Aggiorna il rettangolo del blocco
}
