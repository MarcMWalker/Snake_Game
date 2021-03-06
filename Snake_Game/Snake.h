#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <iostream>
#include <Windows.h>

class Snake{
private:
	int m_headX;
	int m_headY;
	bool m_movingLeft;
	bool m_movingRight;
	bool m_movingUp;
	bool m_movingDown;
	int m_previousX;
	int m_previousY;
public:
	Snake();
	void snakeMovement();
	void checkPosition();
	int getX()const;
	int getY()const;
	void setX(int x);
	void setY(int y);
	void increaseBody(Snake &snake, int &increment);
	std::vector<Snake> m_snakeBody;
	size_t getSnakeLength() const;
	void updateSnakePlacement(Snake& snake);
	int newXcord;
	int newYcord;
	void printBody(std::vector<Snake>& m_snakeBody)const;
	~Snake();
};

#endif

