/*
 * UserInputWindow.h
 *
 *  Created on: 11.03.2014
 *      Author: David
 */

//==============================
// include guard
#ifndef USERINPUTWINDOW_H_
#define USERINPUTWINDOW_H_
//==============================
// forward declared dependencies
//==============================
// included dependencies
#include "hdr/userinterface/Window.h"

//==============================
// the actual class

class UserInputWindow: public Window {
	friend class Human;
public:
	UserInputWindow(const Board& board);
	virtual ~UserInputWindow();
private:
	QPushButton* enterMove;
	Move getMoveFromUser(vector<Move*> moveList);
};

#endif /* USERINPUTWINDOW_H_ */
