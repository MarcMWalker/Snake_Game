#include "Snake.h"

Snake::Snake() : m_headX{ 25 }, m_headY{ 20 }, m_movingLeft{ false }, m_movingRight{ false }, 
m_movingUp{ false }, m_movingDown{ false }, m_previousX{0}, m_previousY{0} {}

void Snake::snakeMovement() {
	
	if (m_movingLeft == true) {
		m_previousX = m_headX;
		m_previousY = m_headY;
		m_headX -= 1;
	}

	if (m_movingRight == true) {
		m_previousX = m_headX;
		m_previousY = m_headY;
		m_headX += 1;
	}

	if (m_movingUp == true) {
		m_previousX = m_headX;
		m_previousY = m_headY;
		m_headY -= 1;
	}

	if (m_movingDown == true) {
		m_previousX = m_headX;
		m_previousY = m_headY;
		m_headY += 1;
	}

	if (GetAsyncKeyState(0x41) && m_movingLeft != true && m_movingRight != true) {
		m_movingLeft = true;
		m_movingRight = false;
		m_movingUp = false;
		m_movingDown = false;
		m_previousX = m_headX;
		m_previousY = m_headY;
		m_headX-=1;
		checkPosition();
		return;
	}
	if (GetAsyncKeyState(0x44) && m_movingRight != true && m_movingLeft != true) {
		m_movingLeft = false;
		m_movingRight = true;
		m_movingUp = false;
		m_movingDown = false;
		m_previousX = m_headX;
		m_previousY = m_headY;
		m_headX+=1;
		checkPosition();
		return;
	}
	if (GetAsyncKeyState(0x57) && m_movingUp != true && m_movingDown != true) {
		m_movingLeft = false;
		m_movingRight = false;
		m_movingUp = true;
		m_movingDown = false;
		m_previousX = m_headX;
		m_previousY = m_headY;
		m_headY-=1;
		checkPosition();
		return;
	}
	if (GetAsyncKeyState(0x53) && m_movingDown != true && m_movingUp != true) {
		m_movingLeft = false;
		m_movingRight = false;
		m_movingUp = false;
		m_movingDown = true;
		m_previousX = m_headX;
		m_previousY = m_headY;
		m_headY+=1;
		checkPosition();
		return;
	}
}

void Snake::checkPosition() {
	if (m_headX < 1) {
		m_headX = 53;
		return;
	}
	if (m_headX > 53) {
		m_headX = 1;
		return;
	}
	if (m_headY < 1) {
		m_headY = 39;
		return;
	}
	if (m_headY > 39) {
		m_headY = 1;
		return;
	}
}

int Snake::getX() {
	return m_headX;
}

int Snake::getY() {
	return m_headY;
}

void Snake::increaseBody(Snake& snake, int increment){
	if (increment <= 0) {
		Snake newPart;
		newPart.m_headX = (snake.getX() + 1);
		newPart.m_headY = (snake.getY());
		snake.m_snakeBody.push_back(newPart);
	}
	else {
		Snake newPart;
		snake.m_snakeBody.push_back(newPart);
		snake.m_snakeBody.at(increment).m_headX = (snake.m_snakeBody.at(static_cast<__int64>(increment) - 1).m_headX) + 1;
		snake.m_snakeBody.at(increment).m_headY = (snake.m_snakeBody.at(static_cast<__int64>(increment) - 1).m_headY);
	}
}

void Snake::setX(int x) {
	m_headX = x;
}

void Snake::setY(int y) {
	m_headY = y;
}

size_t Snake::getSnakeLength()const {
	return static_cast<size_t>(m_snakeBody.size());
}

void Snake::updateSnakePlacement(std::vector<Snake>& m_snakeBody, Snake& snake) {
	m_snakeBody.at(0).m_previousX = m_snakeBody.at(0).getX();
	m_snakeBody.at(0).m_previousY = m_snakeBody.at(0).getY();
	m_snakeBody.at(0).setX(snake.m_previousX);
	m_snakeBody.at(0).setY(snake.m_previousY);

	if (snake.getSnakeLength() > 0) {
		for (int i{ 1 }; i < m_snakeBody.size(); i++) {
			m_snakeBody.at(i).setX(m_snakeBody.at((static_cast<__int64>(i) - 1)).m_previousX);
			m_snakeBody.at(i).setY(m_snakeBody.at((static_cast<__int64>(i) - 1)).m_previousY);
		}
	}
}