/*
 * Coordinate.h
 *
 *  Created on: 18.11.2013
 *      Author: David
 */

#ifndef KONSTANT_FLYEUROPE_H_
#define KONSTANT_FLYEUROPE_H_

#include<string>
#include<fstream>
#include<vector>

using std::vector;
using std::string;
using std::ifstream;

namespace flyeurope {
//Board
//name der Brettdateien
const string BOARDNAME = "hdr/game/boardSettings/flyeurope/";
//string BOARDNAME = "FlyEurope";

//Koordinatenwerte
const short NULL_COORDINATE_VALUE = -1;
const short MAX_X = 19; /**< The maximum possible x-value on the board.*/
const short MAX_Y = 14;

//stadtfarben
//positiv von 1 bis n, mit n=NUMBER_CITYCOLORS Anzahl der Farben
const short NUMBER_CITYCOLORS = 5;
enum CITYCOLOR {
	C_BLUE, C_GREY, C_ORANGE, C_RED, C_WHITE, C_NULLCOLOR
};
const CITYCOLOR CITYCOLOR_LIST[] = { C_BLUE, C_GREY, C_ORANGE, C_RED, C_WHITE };
CITYCOLOR operator>>(ifstream &infile, CITYCOLOR &citycolor);

//stadtnummern
//von 1 bis k, mit k=MAX_STADTNR
//ab SPIELER_GRENZE wird mit allen Staedten gespielt, sonst nur mit den ersten STADTNR_GRENZE
const short MAX_CITYNR = 7;
const short PLAYER_LIMIT = 3;
const short CITYNR_LIMIT = 5;

//spielerfarben
//negativ von -1 bis -n mit MAX_PLAYER=n
enum PLAYERCOLOR {
	P_BLUE, P_GREEN, P_ORANGE, P_VIOLET, P_WHITE, P_YELLOW, NORAILS
};
const PLAYERCOLOR PLAYERCOLOR_LIST[] = { P_BLUE, P_GREEN, P_ORANGE, P_VIOLET,
		P_WHITE, P_YELLOW };
const short MAX_PLAYER = 6;
}

using namespace flyeurope;

#endif /* KONSTANT_FLYEUROPE_H_ */
