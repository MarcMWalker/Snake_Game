#include "Snake.h"

Snake::Snake() : m_headX{ 25 }, m_headY{ 20 }, m_direction{ '^' }, m_movingLeft{ false }, m_movingRight{ false }, m_movingUp{ false }, m_movingDown{false} {

}

void Snake::changeDirection() {
	m_direction;
}

void Snake::snakeMovement() {
	
	if (m_movingLeft == true) {
		m_headX -= 2;
	}

	if (m_movingRight == true) {
		m_headX += 2;
	}

	if (m_movingUp == true) {
		m_headY -= 1;
	}

	if (m_movingDown == true) {
		m_headY += 1;
	}

	if (GetAsyncKeyState(0x41) && m_movingLeft != true && m_movingRight != true) {
		m_movingLeft = true;
		m_movingRight = false;
		m_movingUp = false;
		m_movingDown = false;
		m_headX-=2;
		checkPosition();
		return;
	}
	if (GetAsyncKeyState(0x44) && m_movingRight != true && m_movingLeft != true) {
		m_movingLeft = false;
		m_movingRight = true;
		m_movingUp = false;
		m_movingDown = false;
		m_headX+=2;
		checkPosition();
		return;
	}
	if (GetAsyncKeyState(0x57) && m_movingUp != true && m_movingDown != true) {
		m_movingLeft = false;
		m_movingRight = false;
		m_movingUp = true;
		m_movingDown = false;
		m_headY-1;
		checkPosition();
		return;
	}
	if (GetAsyncKeyState(0x53) && m_movingDown != true && m_movingUp != true) {
		m_movingLeft = false;
		m_movingRight = false;
		m_movingUp = false;
		m_movingDown = true;
		m_headY+1;
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