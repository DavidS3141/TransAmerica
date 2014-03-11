/*
 * ShowSimulationWindow.h
 *
 *  Created on: 11.03.2014
 *      Author: David
 */

//==============================
// include guard
#ifndef SHOWSIMULATIONWINDOW_H_
#define SHOWSIMULATIONWINDOW_H_
//==============================
// forward declared dependencies
class QSPinBox;
//==============================
// included dependencies
#include "../../hdr/userinterface/Window.h"

//==============================
// the actual class

class ShowSimulationWindow: public Window {
	friend class Spielbrett;
	friend class UIEXEC;
	friend class MainWindow;
public:
	ShowSimulationWindow(SimulationLogger* simulationp);
	virtual ~ShowSimulationWindow();
	void setsimulationp(SimulationLogger* game);
private:
	SimulationLogger* simulationp;
	int gameCounter;
	int roundCounter;
	int moveCounter;
	QSpinBox* moveSpinBox;
	QSpinBox* roundSpinBox;
	QSpinBox* gameSpinBox;
	void updateSpinBoxes();
	bool setGameCounter(int i);
	bool setRoundCounter(int i);
	bool setMoveCounter(int i);
	void setZp();
private slots:
	void gameSpinChanged(int i);
	void roundSpinChanged(int i);
	void moveSpinChanged(int i);
};

#endif /* SHOWSIMULATIONWINDOW_H_ */