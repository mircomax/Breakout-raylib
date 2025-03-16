#include "game_functions.h"
#include "raylib.h"
#include <iostream>

//Muovere il paddle
void checkMovimentopaddle(float &paddleSpeed, float &paddleX) {
	//Muovere verso destra finchè è nello schermo
	if(IsKeyDown(KEY_RIGHT) && paddleX < GetScreenWidth()) { 
		paddleX += paddleSpeed;
	}
	//Muovere verso sinistra finchè è nello schermo
	else if(IsKeyDown(KEY_LEFT) && paddleX > 0){
		paddleX -= paddleSpeed;
	}
}
// Disegnare le scritte decorative sullo schermo
void disegnaScritte() {
	DrawFPS(15, 15);
}