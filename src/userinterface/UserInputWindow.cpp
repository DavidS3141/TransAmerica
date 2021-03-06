/*
 * UserInputWindow.cpp
 *
 *  Created on: 11.03.2014
 *      Author: David
 */

#include "UserInputWindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <QFormLayout>
#include <QEventLoop>

#include "../../hdr/game/Move.h"
#include "../../hdr/userinterface/DynamicState.h"
#include "../../hdr/userinterface/GUIBoard.h"
#include "../../hdr/game/Board.h"

UserInputWindow::UserInputWindow(const Board* board) :
    Window(board){
	enterMove = new QPushButton(tr("Enter Move"));
	toolLayout->addRow(enterMove);
}

UserInputWindow::~UserInputWindow() {
	// TODO Auto-generated destructor stub
}

const Coordinate* UserInputWindow::getPawnFromUser(AI* player,
		State& currentState, const City** hand) {
    enterMove->setText(QString("Set Pawn"));
    DynamicState* aZp = new DynamicState(currentState);
    spielbrett->setDynamicState(aZp);
	spielbrett->setHand(hand);
	this->spielbrett->update();
	this->update();
//	this->show();
	QEventLoop* pause = new QEventLoop;
	connect(enterMove, SIGNAL(clicked(bool)), pause, SLOT(quit()));
	spielbrett->selectCoordinates = true;
    emit requestDisplayOnStatusBar(tr("Select your position at the beginning"),0);
    pause->exec();
	spielbrett->selectCoordinates = false;
	Vector pos(0, 0);
	for (int i = 0; i < MAX_X; i++)
		for (int j = 0; j < MAX_Y; j++)
			if (aZp->getFromUserSelectedCoordinates()[i][j])
				pos = Vector(i, j);
	const Coordinate* retValue = aZp->board.grid[pos.x][pos.y];
	enterMove->setText(QString("Enter Move"));
	return retValue;
}

//* TODO @OEtzi: use the slot MainWindow::displayOnStatus to show instructions
Move UserInputWindow::getMoveFromUser(AI* player, State& currentState,
		const City** hand, vector<Move*> moveList) {
	DynamicState* aZp = new DynamicState(currentState);
	if (moveList.size() > 0)
		aZp->lastMove = moveList[moveList.size() - 1];
	spielbrett->setDynamicState(aZp);
    if (simLogger)
        spielbrett->setPlayerList(simLogger->getPlayerList());
//	spielbrett->setHand(hand);
	this->spielbrett->update();
	this->update();
    bool moveIsValid = false;
    Move returnMove (P_YELLOW, 0, 0);
    while (!moveIsValid){
	QEventLoop* pause = new QEventLoop;
	connect(enterMove, SIGNAL(clicked(bool)), pause, SLOT(quit()));
	spielbrett->selectConnections = true;

    emit requestDisplayOnStatusBar("Please select your rails on the board.", 0);
	pause->exec();
	spielbrett->selectConnections = false;
	const Connection* one = 0, *two = 0;
	int counter = 0;
	for (int i = 0; i < MAX_X; i++)
		for (int j = 0; j < MAX_Y; j++)
			for (int k = 0; k < 3; k++)
				if (aZp->getFromUserSelectedConnections()[i][j][k]) {
					counter++;
					if (counter == 1)
						one = aZp->board.edges[i][j][k];
					else
						two = aZp->board.edges[i][j][k];
				}
    returnMove = Move (P_YELLOW, one, two);
    moveIsValid = returnMove.valid(currentState, P_YELLOW);
    if(!moveIsValid)
        QMessageBox::warning(this, "Invalid Move", "Sorry, but your move is Invalid! \n"
                             "Please try another one or take a look in the Help-Section.",
                             QMessageBox::Ok);
    }
    emit requestDisplayOnStatusBar("... waiting for the AIs", 0);
    return returnMove; //TODO change P_YELLOW to something more dynamic
}

void UserInputWindow::showDataWidget() {
	return;
	//TODO NOTE probably not the best solution
}
void UserInputWindow::setSimLogger(SimulationLogger *sLogger){
    simLogger = sLogger;
}
