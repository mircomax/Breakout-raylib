#include "block_class.h"
#include "raylib.h"
#include "ball_class.h"
#include <iostream>

const int real_width = 50;
const int real_height = 50;

// Costruttore
Block::Block() {
    width = real_width;
    height = real_height;
    pos = { 0, 0 };
    blocco = {(float)pos.x, (float)pos.y, (float)width, (float)height};
    active = true; // Blocchi inizializzati come attivi
    collisioneGestita = false; // Per gestire possibile multiple collisioni in un unico frame
    coloreBlocco = CreaColore(); // Creare il colore
}

void Block::CreaPosizione(int i) {
     pos.x = (real_width) * (i % 16);    // Calcola la colonna
     pos.y = (real_height) * (i / 16);    // Calcola la riga (cioè quante volte 16 è contenuto in i)
     blocco = { pos.x, pos.y, width, height }; // Aggiorna il rettangolo del blocco
}

// Quando la palla colpisce un blocco la velocità si inverte e il blocco si disattiva
void Block::CheckCollisionsBall(Ball& palla1) {
    if (active && CheckCollisionCircleRec(palla1.GetPosition(), 10.0f, blocco)) {
        active = false; // Se colpito il blocco si disattiva
        palla1.InvertiVelocitaY(); // Invertita velocità quando viene colpito

        // Espressione strana per fare in modo di invertire la velocità in X,
        // una volta che la palla colpisce un lato del blocco  
        if ((palla1.pos.y < (blocco.y + blocco.height))) {
           palla1.InvertiVelocitaX();
           palla1.InvertiVelocitaY();          
        }
        collisioneGestita = true; // Fondamentale per gestire una collisione al frame
    }
}

void Block::UpdateBlocks() {
    if (!active) {
        blocco = { 0, 0, 0, 0 };  // Rende il blocco invisibile quando colpito
    }
}

// Generare casualmente il colore del blocco sulla base di multipli colori
Color Block::CreaColore()
{
    int NumeroColore = rand() % 8 + 1; 
    switch(NumeroColore) {
    case 1:
        return Color(RED);
    case 2:
        return Color(BLUE);
    case 3:
        return Color(GREEN);
    case 4:
        return Color(PINK);
    case 5:
        return Color(WHITE);
    case 6:
        return Color(PURPLE);
    case 7:
        return Color(ORANGE);
    case 8:
        return Color(LIME);
    default:
        return Color(WHITE);
    }
}







