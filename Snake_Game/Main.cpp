#include <iostream>
#include <Windows.h>
#include "GameManager.h"
#include "Snake.h"

void ShowConsoleCursor(bool showFlag){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 500, 800, TRUE);

	GameManager game;
	bool end{};
	bool fruitPicked{false};
	game.randomiseFruitPlacement(fruitPicked);
	while (end != true) {
		ShowConsoleCursor(false);
		game.createMap(fruitPicked);
		std::cout << "Score: " << game.getScore();
		std::cout << "\nLength: " << game.snake.getSnakeLength();
		std::this_thread::sleep_for(0.0166s);
		//std::this_thread::sleep_for(0.25s); //Slower refresh for testing
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}
	return 0;
}