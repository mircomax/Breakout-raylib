#include "block_class.h"
#include "raylib.h"
#include "ball_class.h"
#include <iostream>

// Costruttore
Block::Block() {
    width = 50;
    height = 50;
    pos = { 0, 0 };
    blocco = {(float)pos.x, (float)pos.y, (float)width, (float)height};
    active = true;
}

void Block::CreaPosizione(int i) {
    if(active){
        pos.x = 50 * (i % 16);    // Calcola la colonna
        pos.y = 50 * (i / 16);    // Calcola la riga (cioè quante volte 16 è contenuto in i)
        blocco = { pos.x, pos.y, width, height }; // Aggiorna il rettangolo del blocco
    }
    else {
        blocco.width = 0; // Non disegna il blocco nel caso sia stato colpito dalla palla
    }
}

// Quando la palla colpisce un blocco la velocità si inverte e il blocco si disattiva
void Block::CheckCollisionsBall(Ball& palla1) {
    if (active && CheckCollisionCircleRec(palla1.GetPosition(), 10.0f, blocco)) {
        active = false; 
        palla1.InvertiVelocitaY();
        if ((palla1.pos.y < (blocco.y + blocco.height))) {
           palla1.InvertiVelocitaX();
           palla1.InvertiVelocitaY();
        }
    }
        // Espressione strana per fare in modo di invertire la velocità in X,
        // una volta che la palla colpisce un lato del blocco
        
    
}






