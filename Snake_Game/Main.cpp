#include <iostream>
#include <Windows.h>
#include "GameManager.h"

int main() {

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 600, 900, TRUE);

	GameManager game;
	game.randomiseFruitPlacement(game);
	game.createMap();

	return 0;
}