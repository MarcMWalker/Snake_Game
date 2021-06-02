#include "GameManager.h"

GameManager::GameManager() : m_xMin{ 0 }, m_yMin{ 0 }, m_xMax{ 55 }, m_yMax{ 40 }, m_fruitX{ 0 }, m_fruitY{ 0 }, m_score{ 0 }, m_increment{0}{
}

Snake snake;

int GameManager::getXMin(int& m_xMin) const{
	return m_xMin;
}

int GameManager::getYMin(int& m_yMin) const{
	return m_yMin;
}

int GameManager::getXMax(int& m_xMax) const{
	return m_xMax;
}

int GameManager::getYMax(int& m_yMax) const{
	return m_yMax;
}

void GameManager::createMap(bool& fruitPicked){
	snake.snakeMovement();
	snake.checkPosition();

	if (fruitPicked == true) {
		randomiseFruitPlacement(fruitPicked);
		fruitPicked = false;
	}

	for (int y{ 0 }; y < getYMax(GameManager::m_yMax); ++y) {
		if (y <= 0) {
			for (int x{ 0 }; x < getXMax(GameManager::m_xMax); ++x) {
				std::cout << "*";
			}
		}
		//Printing of snake must be within here
		//////////////////
		if(y > 0 && y < getYMax(GameManager::m_yMax)) {
			for (int x{ 0 }; x < getXMax(GameManager::m_xMax); ++x) {
				if (x == 0 || x == getXMax(GameManager::m_xMax) - 1) {
					std::cout << "*";
				}
				else if (x > 0 && x < GameManager::m_xMax && x == GameManager::m_fruitX && y == GameManager::m_fruitY) {
					std::cout << "$";
				}
				else if (x == snake.getX() && y == snake.getY()) {
					std::cout << "O";
				}
				//Trying to iterate through snake body here to print on screen
				else if (snake.getSnakeLength() > 0) {
					snake.updateSnakePlacement(snake.m_snakeBody, snake);
					if (iterateSnake(snake, x, y) == true) {
						std::cout << "+";
					}
					else {
						std::cout << " ";
					}
				}
				else {
					std::cout << " ";
				}
			}
		}
		/////////////////////////////////////////
		
		if (y >= getYMax(GameManager::m_yMax)-1) {
			std::cout << "\n";
			for (int x{ 0 }; x < getXMax(GameManager::m_xMax); ++x) {
				std::cout << "*";
			}
		}
		std::cout << "\n";
	}
	
	if (m_fruitX == snake.getX() && m_fruitY == snake.getY()) {
		fruitPicked = true;
		snake.increaseBody(snake, m_increment);
		m_increment++;
		increaseScore();
	}
	//std::cout << "Snake x:" << snake.getX();
	//std::cout << "\nSnake y:" << snake.getY();
}

void GameManager::randomiseFruitPlacement(bool& fruit){
	srand(time(NULL));
	m_fruitX = rand() % 53 + 1;
	m_fruitY = rand() % 39 + 1;
	//std::cout << "X: " << m_fruitX << "\n";
	//std::cout << "Y: " << m_fruitY << "\n";
}

void GameManager::increaseScore() {
	m_score += 100;
}

int GameManager::getScore()const{
	return GameManager::m_score;
}

bool GameManager::iterateSnake(Snake& snake, int x, int y) {
	bool isThere{};
	for (auto i : snake.m_snakeBody) {
		if (i.getX() == x && i.getY() == y) {
			isThere = true;
			return isThere;
		}
		else {
			isThere = false;
		}
	}
	return isThere;
}

