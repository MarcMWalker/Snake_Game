#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <iostream>
#include <Windows.h>

class Snake{
private:
	int m_headX;
	int m_headY;
	char m_direction;
	bool m_movingLeft;
	bool m_movingRight;
	bool m_movingUp;
	bool m_movingDown;

	//std::vector<direction> m_snakeBody{};
public:
	Snake();
	void changeDirection();
	void snakeMovement();
	void checkPosition();
	int getX();
	int getY();
	//std::vector<direction> printSnake();
};

#endif

