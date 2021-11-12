#include "Position.h"
#include "Piece.h"
#include <vector>


vector<Position*> Piece::getAvaliablePlace(int width, int height)
{
	return vector<Position*>();
}

bool Piece::onBoard(Position* pos)
{
	if (pos->getX() < 0 || pos->getX() > 8 || pos->getY() < 0 || pos->getY() > 9) {
		return false;
	}
	else {
		return true;
	}
}

void Piece::draw()
{
}


vector<Position*> General::getAvaliablePlace(int width, int height)
{
	vector<Position*> avaliablePlace;
	for (auto step : steps) {
		Position* dest;
		dest->setX(pos->getX() + step[0]);
		dest->setY(pos->getY() + step[1]);
		if (!onBoard(dest)) {
			continue;
		}
		avaliablePlace.push_back(dest);
	}
	return avaliablePlace;
}

bool General::onBoard(Position* pos)
{
	if (playerIndex == 0) {
		if (pos->getX() < 3 || pos->getX() > 5 || pos->getY() < 0 || pos->getY() > 2) {
			return false;
		} 
	}
	else {
		if (pos->getX() < 3 || pos->getX() > 5 || pos->getY() < 7 || pos->getY() > 9) {
			return false;
		}
	}
	return true;
}

bool Advisor::onBoard(Position* pos)
{
	if (playerIndex == 0) {
		if (pos->getX() < 3 || pos->getX() > 5 || pos->getY() < 0 || pos->getY() > 2) {
			return false;
		}
	}
	else {
		if (pos->getX() < 3 || pos->getX() > 5 || pos->getY() < 7 || pos->getY() > 9) {
			return false;
		}
	}
	return true;
}

vector<Position*> Advisor::getAvaliablePlace(int width, int height)
{
	vector<Position*> avaliablePlace;
	for (auto step : steps) {
		Position* dest;
		dest->setX(pos->getX() + step[0]);
		dest->setY(pos->getY() + step[1]);
		if (!onBoard(dest)) {
			continue;
		}
		avaliablePlace.push_back(dest);
	}
	return avaliablePlace;
}

bool Elephant::onBoard(Position* pos)
{
	if (playerIndex == 0) {
		if (pos->getX() < 0 || pos->getX() > 8 || pos->getY() < 0 || pos->getY() > 4) {
			return false;
		}
	}
	else {
		if (pos->getX() < 0 || pos->getX() > 8 || pos->getY() < 4 || pos->getY() > 9) {
			return false;
		}
	}
	return true;
}

vector<Position*> Elephant::getAvaliablePlace(int width, int height)
{
	vector<Position*> avaliablePlace;
	for (auto step : steps) {
		Position* dest;
		dest->setX(pos->getX() + step[0]);
		dest->setY(pos->getY() + step[1]);
		if (!onBoard(dest)) {
			continue;
		}
		avaliablePlace.push_back(dest);
	}

	return avaliablePlace;
}

vector<Position*> Horse::getAvaliablePlace(int width, int height)
{
	vector<Position*> avaliablePlace;
	for (auto step : steps) {
		Position* dest;
		dest->setX(pos->getX() + step[0]);
		dest->setY(pos->getY() + step[1]);
		if (!onBoard(dest)) {
			continue;
		}
		avaliablePlace.push_back(dest);
	}

	return avaliablePlace;
}

vector<Position*> Chariot::getAvaliablePlace(int width, int height)
{
	vector<Position*> avaliablePlace;
	for (int i = 0; i < width; i++) {
		Position* dest;
		if (i == pos->getY()) {
			continue;
		}
		dest->setX(pos->getX());
		dest->setY(i);
		avaliablePlace.push_back(dest);
	}

	for (int j = 0; j < height; j++) {
		Position* dest;
		if (j == pos->getX()) {
			continue;
		}
		dest->setX(j);
		dest->setY(pos->getY());
		avaliablePlace.push_back(dest);
	}
	return avaliablePlace;
}

vector<Position*> Cannon::getAvaliablePlace(int width, int height)
{
	vector<Position*> avaliablePlace;


	return avaliablePlace;
}

vector<Position*> Soldier::getAvaliablePlace(int width, int height)
{
	vector<Position*> avaliablePlace;
	if (isCrossRiver) {
		for (auto step : steps) {
			Position* dest;
			if (playerIndex == 0) {
				dest->setX(pos->getX() + step[0]);
				dest->setY(pos->getY() + step[1]);
			}
			else {
				dest->setX(pos->getX() - step[0]);
				dest->setY(pos->getY() - step[1]);
			}
			
			if (!onBoard(dest)) {
				continue;
			}
			avaliablePlace.push_back(dest);
		}
	}
	else {
		Position* dest;
		if (playerIndex == 0) {
			dest->setX(pos->getX() + steps[0][0]);
			dest->setY(pos->getY() + steps[0][1]);
		}
		else {
			dest->setX(pos->getX() - steps[0][0]);
			dest->setY(pos->getY() - steps[0][1]);
		}
		
		if (onBoard(dest)) {
			avaliablePlace.push_back(dest);
		}
	}
	return avaliablePlace;
}