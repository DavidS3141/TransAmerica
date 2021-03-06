/*
 * RoundLogger.cpp
 *
 *  Created on: 17.01.2014
 *      Author: David
 */

#include "../../hdr/logger/RoundLogger.h"

RoundLogger::RoundLogger(const PlayingOrder& playingOrder,
		const vector<AI*> playerList, const Board& board,
		const AI* roundStartingPlayer) :
		playingOrder(playingOrder), playerList(playerList), board(board), roundStartingPlayer(
				roundStartingPlayer), lostPoints(0), pawnList(0), playerStatus(
				0) {
	pawnList = new const Pawn*[MAX_PLAYER];
	playerStatus = new BANNED_STATUS[MAX_PLAYER];
	for (int i = 0; i < MAX_PLAYER; i++) {
		pawnList[i] = 0;
		playerStatus[i] = NOT_BANNED;
	}
	playingCards = new const City**[MAX_PLAYER];
	for (int i = 0; i < MAX_PLAYER; i++) {
		playingCards[i] = new const City*[NUMBER_CITYCOLORS];
		for (int j = 0; j < NUMBER_CITYCOLORS; j++)
			playingCards[i][j] = 0;
	}
}

const Board& RoundLogger::getBoard() const {
	return board;
}

const Counter& RoundLogger::getLostPoints() const {
	return lostPoints;
}

const vector<Move*>& RoundLogger::getMoveList() const {
	return moveList;
}

const Pawn** RoundLogger::getPawnList() const {
	return pawnList;
}

const vector<AI*>& RoundLogger::getPlayerList() const {
	return playerList;
}

const City*** RoundLogger::getPlayingCards() const {
	return playingCards;
}

const PlayingOrder& RoundLogger::getPlayingOrder() const {
	return playingOrder;
}

const AI* RoundLogger::getRoundStartingPlayer() const {
	return roundStartingPlayer;
}
const BANNED_STATUS RoundLogger::getPlayerStatus(const AI *player) const{
    //TODO @OEtzi007 change  the implementation
    for (int i=0; i<playerList.size();i++){
        if (player == playerList[i])
            return playerStatus[i];
    }
}

RoundLogger::~RoundLogger() {
	// TODO Auto-generated destructor stub
}

