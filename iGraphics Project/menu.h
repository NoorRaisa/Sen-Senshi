#ifndef MENU_INCLUDED
#define MENU_INCLUDED
void resetGame();
struct menuButton{
	int x, y;
}menu_buttons[5];
void menu(int mx, int my){
	for (int i = 0; i < 5; i++){
		if (mx >= menu_buttons[i].x && mx <= menu_buttons[i].x + 255 && my >= menu_buttons[i].y && my <= menu_buttons[i].y + 155){
			gameState = i;
		}
	}

}
#endif