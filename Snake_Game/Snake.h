#ifndef SNAKE_H
#define SNAKE_H
#include <vector>

class Snake{
private:
	int m_headX;
	int m_headY;
	char m_direction;

	//std::vector<direction> m_snakeBody{};
public:
	Snake();
	void changeDirection();
	//std::vector<direction> printSnake();
};

#endif

