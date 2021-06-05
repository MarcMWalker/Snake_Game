#include "Snake.h"

Snake::Snake() : m_headX{ 25 }, m_headY{ 20 }, m_movingLeft{ false }, m_movingRight{ false }, 
m_movingUp{ false }, m_movingDown{ false }, m_previousX{ 0 }, m_previousY{ 0 }, m_snakeBody{}, newXcord{ 0 }, newYcord{0} {}

void Snake::snakeMovement() {
	
	if (m_movingLeft == true) {
		m_previousX = m_headX;
		m_previousY = m_headY;
		Snake::m_headX -= 1;
	}

	if (m_movingRight == true) {
		m_previousX = m_headX;
		m_previousY = m_headY;
		Snake::m_headX += 1;
	}

	if (m_movingUp == true) {
		m_previousX = m_headX;
		m_previousY = m_headY;
		Snake::m_headY -= 1;
	}

	if (m_movingDown == true) {
		m_previousX = m_headX;
		m_previousY = m_headY;
		Snake::m_headY += 1;
	}

	if (GetAsyncKeyState(0x41) && m_movingLeft != true && m_movingRight != true) {
		m_movingLeft = true;
		m_movingRight = false;
		m_movingUp = false;
		m_movingDown = false;
		//m_previousX = m_headX;
		//m_previousY = m_headY;
		m_headX-=1;
		checkPosition();
		return;
	}
	if (GetAsyncKeyState(0x44) && m_movingRight != true && m_movingLeft != true) {
		m_movingLeft = false;
		m_movingRight = true;
		m_movingUp = false;
		m_movingDown = false;
		//m_previousX = m_headX;
		//m_previousY = m_headY;
		m_headX+=1;
		checkPosition();
		return;
	}
	if (GetAsyncKeyState(0x57) && m_movingUp != true && m_movingDown != true) {
		m_movingLeft = false;
		m_movingRight = false;
		m_movingUp = true;
		m_movingDown = false;
		//m_previousX = m_headX;
		//m_previousY = m_headY;
		m_headY-=1;
		checkPosition();
		return;
	}
	if (GetAsyncKeyState(0x53) && m_movingDown != true && m_movingUp != true) {
		m_movingLeft = false;
		m_movingRight = false;
		m_movingUp = false;
		m_movingDown = true;
		//m_previousX = m_headX;
		//m_previousY = m_headY;
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

int Snake::getX()const {
	return m_headX;
}

int Snake::getY()const {
	return m_headY;
}

void Snake::increaseBody(Snake& snake, int& increment){
	if (increment <= 0) {
		Snake newPart;
		//newPart.m_headX = (snake.getX());
		//newPart.m_headY = (snake.getY());
		snake.m_snakeBody.push_back(newPart);
		snake.updateSnakePlacement(snake);
	}
	else {
		Snake newPart;
		snake.m_snakeBody.push_back(newPart);
		//snake.m_snakeBody.at(increment).m_headX = (snake.m_snakeBody.at(static_cast<__int64>(increment) - 1).m_headX) + 1;
		//snake.m_snakeBody.at(increment).m_headY = (snake.m_snakeBody.at(static_cast<__int64>(increment) - 1).m_headY);
		snake.updateSnakePlacement(snake);
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

void Snake::updateSnakePlacement(Snake& snake) {
	snake.m_snakeBody.at(0).setX(snake.m_previousX);
	snake.m_snakeBody.at(0).setY(snake.m_previousY);
	//snake.m_snakeBody.at(0).newXcord = snake.m_snakeBody.at(0).m_headX;
	//snake.m_snakeBody.at(0).newYcord = snake.m_snakeBody.at(0).m_headY;
	

	snake.m_snakeBody.at(0).m_previousX = m_previousX;
	snake.m_snakeBody.at(0).m_previousY = m_previousY;
	

	//Sure this should be working fine now as logic suggests, but something else affecting it
	if (snake.getSnakeLength() > 1) {
		
		snake.m_snakeBody.at(1).setX(snake.m_snakeBody.at(0).m_previousX);
		snake.m_snakeBody.at(1).setY(snake.m_snakeBody.at(0).m_previousY);
		

		snake.m_snakeBody.at(1).m_previousX = m_snakeBody.at(0).m_previousX+=1;
		snake.m_snakeBody.at(1).m_previousY = m_snakeBody.at(0).m_previousY;
		

		//for (int i{ 1 }; i <= snake.m_snakeBody.size()-1; i++) {
			
		//}
	}
}

void Snake::printBody(std::vector<Snake>& m_snakeBody)const {
	
	std::cout << "\nMain X: " << m_headX;
	std::cout << "\nMain Y: " << m_headY;
	std::cout << "\n ";

	for (auto i : m_snakeBody) {
		std::cout <<"\n X cord: " << i.m_previousX;
		std::cout <<"\n Y cord: " << i.m_previousY;
		std::cout << "\n ";
	}
}

Snake::~Snake() {

}