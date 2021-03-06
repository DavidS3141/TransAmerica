/*
 * Board.cpp
 *
 *  Created on: 03.12.2013
 *      Author: David
 */

#include "../../hdr/game/Board.h"

Board::Board(bool abovePlayerLimit) :
		abovePlayerLimit(abovePlayerLimit), numberCities(
				NUMBER_CITYCOLORS
						* (abovePlayerLimit ? MAX_CITYNR : CITYNR_LIMIT)), cityList(
				constructCities()), grid(constructGrid()), edges(
				constructEdges()) {
}

Board::~Board() {
	delete[] cityList;
	for (int i = 0; i < MAX_X; i++) {
		for (int j = 0; j < MAX_Y; j++) {
			delete grid[i][j];
			for (int k = 0; k < 3; k++)
				delete edges[i][j][k];
			delete[] edges[i][j];
		}
		delete[] grid[i];
		delete[] edges[i];
	}
	delete[] grid;
	delete[] edges;
}

void Board::dump() const {
	for (int y = 0; y < 2 * MAX_Y - 1; y++) {
		for (int leerzeichen = 0; leerzeichen < 2 * MAX_Y - 2 - y;
				leerzeichen++)
			cout << " ";
		for (int x = 0; x < 2 * MAX_X - 1; x++) {
			if (x % 2 == 0 && y % 2 == 0) {
				if (this->grid[x / 2][y / 2] == 0)
					cout << " ";
				else if (this->grid[x / 2][y / 2]->vorOrt == 0)
					cout << "X";
				else
					cout << grid[x / 2][y / 2]->vorOrt->name[0];
				if (this->edges[x / 2][y / 2][0] != 0
						&& this->edges[x / 2][y / 2][0]->barrier)
					cout << "-";
				else
					cout << " ";
			} else if (x % 2 == 0 && y % 2 == 1) {
				if (this->edges[x / 2][(y - 1) / 2][1] != 0)
					if (this->edges[x / 2][(y - 1) / 2][1]->barrier)
						cout << "/ ";
					else
						cout << "  ";
				else
					cout << "  ";
			} else if (x % 2 == 1 && y % 2 == 0) {
				if (this->edges[(x - 1) / 2][y / 2][0] != 0)
					if (this->edges[(x - 1) / 2][y / 2][0]->barrier)
						cout << "--";
					else
						cout << "  ";
				else
					cout << "  ";
			} else {
				if (this->edges[(x - 1) / 2][(y - 1) / 2][2] != 0)
					if (this->edges[(x - 1) / 2][(y - 1) / 2][2]->barrier)
						cout << "\\ ";
					else
						cout << "  ";
				else
					cout << "  ";
			}
		}
		cout << endl;
	}
}

const City* const Board::lookForCity(short x, short y) const {
	for (int i = 0; i < numberCities; i++) {
		if (cityList[i]->x == x && cityList[i]->y == y) {
			return cityList[i];
		}
	}
	cout << "Eingabedaten passen nicht zusammen." << endl;
	cout << x << "," << y << endl;
	assert(true);
	return cityList[0];
}

Connection**** Board::constructEdges() const {
	//Verbindungen einzeichnen
	Connection**** testKanten = new Connection***[MAX_X];
	for (int i = 0; i < MAX_X; i++) {
		testKanten[i] = new Connection**[MAX_Y];
		for (int j = 0; j < MAX_Y; j++) {
			testKanten[i][j] = new Connection*[3];
			if (i + 1 < MAX_X)
				if (!grid[i][j] == 0 && !grid[i + 1][j] == 0)
					testKanten[i][j][0] = new Connection(grid[i][j],
							grid[i + 1][j], false);
				else
					testKanten[i][j][0] = 0;
			else
				testKanten[i][j][0] = 0;
			if (j + 1 < MAX_Y)
				if (!grid[i][j] == 0 && !grid[i][j + 1] == 0)
					testKanten[i][j][1] = new Connection(grid[i][j],
							grid[i][j + 1], false);
				else
					testKanten[i][j][1] = 0;
			else
				testKanten[i][j][1] = 0;
			if (j + 1 < MAX_Y && i + 1 < MAX_X)
				if (!grid[i][j] == 0 && !grid[i + 1][j + 1] == 0)
					testKanten[i][j][2] = new Connection(grid[i][j],
							grid[i + 1][j + 1], false);
				else
					testKanten[i][j][2] = 0;
			else
				testKanten[i][j][2] = 0;
		}
	}
	ifstream Verbindungsinput((BOARDNAME + "barriers.txt").data());
	string input;
	Vector pos(0, 0);
	while (true) {
		Verbindungsinput >> input;
		if (input[0] == 'X') {
			break;
			cout << "Ende" << endl;
		}
		if (input[0] == '#') {
			Verbindungsinput >> pos.x;
			Verbindungsinput >> pos.y;
		} else {
			switch (input[0]) {
			case '0':
				delete testKanten[pos.x][pos.y][0];
				testKanten[pos.x][pos.y][0] = new Connection(grid[pos.x][pos.y],
						grid[pos.x + 1][pos.y], true);
				pos = pos + Vector(1, 0);
				break;
			case '1':
				delete testKanten[pos.x][pos.y][1];
				testKanten[pos.x][pos.y][1] = new Connection(grid[pos.x][pos.y],
						grid[pos.x][pos.y + 1], true);
				pos = pos + Vector(0, 1);
				break;
			case '2':
				delete testKanten[pos.x][pos.y][2];
				testKanten[pos.x][pos.y][2] = new Connection(grid[pos.x][pos.y],
						grid[pos.x + 1][pos.y + 1], true);
				pos = pos + Vector(1, 1);
				break;
			case '3':
				delete testKanten[pos.x - 1][pos.y][0];
				testKanten[pos.x - 1][pos.y][0] = new Connection(
						grid[pos.x - 1][pos.y], grid[pos.x][pos.y], true);
				pos = pos + Vector(-1, 0);
				break;
			case '4':
				delete testKanten[pos.x][pos.y - 1][1];
				testKanten[pos.x][pos.y - 1][1] = new Connection(
						grid[pos.x][pos.y - 1], grid[pos.x][pos.y], true);
				pos = pos + Vector(0, -1);
				break;
			case '5':
				delete testKanten[pos.x - 1][pos.y - 1][2];
				testKanten[pos.x - 1][pos.y - 1][2] = new Connection(
						grid[pos.x - 1][pos.y - 1], grid[pos.x][pos.y], true);
				pos = pos + Vector(-1, -1);
				break;
			default:
				cout << "Brett::kantenAnelgen: fehlerhafter Input" << endl;
				break;
			}
		}
	}
	return testKanten;
}

City** Board::constructCities() const {
	ifstream Stadtinput((BOARDNAME + "cities.txt").data());
	City** testStadtliste = new City*[numberCities];
	int fillcounter = 0;
	for (int i = 0; i < MAX_CITYNR * NUMBER_CITYCOLORS; i++) {
		string name;
		short number;
		CITYCOLOR cityColor;
		Vector place(0, 0);
		Stadtinput >> name;
		Stadtinput >> place.x;
		Stadtinput >> place.y;
		Stadtinput >> cityColor;
		Stadtinput >> number;
		if (abovePlayerLimit || number <= CITYNR_LIMIT) {
			testStadtliste[fillcounter] = new City(name, cityColor, number,
					place);
			fillcounter++;
		}
	}
	assert(fillcounter == numberCities);
	return testStadtliste;
}

const Coordinate*** Board::constructGrid() const {
	const Coordinate*** testGitter = new const Coordinate**[MAX_X];
	for (int i = 0; i < MAX_X; i++) {
		testGitter[i] = new const Coordinate*[MAX_Y];
	}
	ifstream Koordinateninput((BOARDNAME + "coordinates.txt").data());
	for (int y = 0; y < MAX_Y; y++) {
		string input;
		Koordinateninput >> input;
		for (int x = 0; x < MAX_X; x++) {
			char inputletter = input[x];
			if (inputletter == 'c') {
				testGitter[x][y] = lookForCity(x, y);
			} else if (inputletter == 'v') { //v for village (only set, if enough players
				if (abovePlayerLimit)
					testGitter[x][y] = lookForCity(x, y);
				else
					testGitter[x][y] = new Coordinate(x, y);
			} else if (inputletter == 'x') {
				testGitter[x][y] = new Coordinate(x, y);
			} else if (inputletter == '-') {
				testGitter[x][y] = 0;
			}
		}
	}
	return testGitter;
}

const City* Board::getCity(CITYCOLOR farbe, short nr) const {
	for (int i = 0; i < numberCities; i++) {
		const City* aktStadt = this->cityList[i];
		if (aktStadt->cityColor == farbe && aktStadt->number == nr)
			return aktStadt;
	}
	assert(true);
	return cityList[0];
}

const Coordinate* Board::getCoordinate(Vector vector) const {
	if (vector.x >= 0 && vector.y >= 0 && vector.x < MAX_X && vector.y < MAX_Y)
		return grid[vector.x][vector.y];
	else
		return 0;
}

const Connection* Board::getConnection(const Coordinate* a,
		const Coordinate* b) const {
	if (a && b)
		return getConnection(*a, *b);
	else
		return 0;
}

const Connection* Board::getConnection(Vector a, Vector b) const {
	Vector eins = a;
	Vector zwei = b;
	const Connection* ruckgabe = 0;
	if ((b - a).x < 0 || (b - a).y < 0) {
		eins = b;
		zwei = a;
	}
	if (eins.x >= 0 && eins.y >= 0 && zwei.x >= 0 && zwei.y >= 0
			&& eins.x < MAX_X && eins.y < MAX_Y && zwei.x < MAX_X
			&& zwei.y < MAX_Y && (zwei - eins).direction() != UNDEFINED)
		ruckgabe = edges[eins.x][eins.y][(zwei - eins).direction()];
	return ruckgabe;
}
