#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
#include "Snake.h"
using namespace std::chrono_literals;

class GameManager{
private:
	int m_xMin;
	int m_yMin;
	int m_xMax;
	int m_yMax;
	int m_fruitX;
	int m_fruitY;
	int m_score;
	int m_increment;
public:
	GameManager();
	int getXMin(int& m_xMin)const;
	int getYMin(int& m_yMin)const;
	int getXMax(int& m_xMax)const;
	int getYMax(int& m_yMax)const;
	void createMap(bool &fruit);
	void randomiseFruitPlacement(bool& fruitPicked);
	void increaseScore();
	int getScore()const;
	Snake snake;
	bool iterateSnake(Snake &snake, int x, int y);
};
#endif

