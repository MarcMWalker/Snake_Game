#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <iostream>
#include <stdlib.h>
#include <time.h>

class GameManager{
private:
	int m_xMin;
	int m_yMin;
	int m_xMax;
	int m_yMax;
	int m_fruitX;
	int m_fruitY;
public:
	GameManager();
	int getXMin(int& m_xMin)const;
	int getYMin(int& m_yMin)const;
	int getXMax(int& m_xMax)const;
	int getYMax(int& m_yMax)const;
	void createMap();
	void randomiseFruitPlacement(GameManager);
	void placeRandomFruit();
};
#endif

