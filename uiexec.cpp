#include "uiexec.h"

#include"AI.h"
#include"testKI.h"
#include"MyFirstKI.h"
#include<iostream>
#include<cassert>


UIEXEC::UIEXEC(){
}
void UIEXEC::doTheMagic(){
    /**
      window implementation
      */
    board = new Board;
    board->Ausgabe();
    testKI virt[] = { testKI(P_YELLOW), testKI(P_BLUE) };
    game1 = new GraphicGame(2, 0, virt, *board);
    game1->spielen();

    wp = new Window(game1);
    wp->setWindowTitle(QObject::tr("Transamerica - Testversion - GITHUB"));
    wp->show();

    //wp->playAutomatically();
//    sound = new QSound("sounds/train-whistle-01.wav");
//    assert(sound->isAvailable());
//    sound->play();

    /**
      call of the game algorithmus
      */


    /**
      connect this shit
      */
    // TODO some connects
     //connect(wp, SIGNAL(requestZp(int)), &(game1->stateList), SLOT(callGet(int)) );
     //connect(&(game1->stateList), SIGNAL(emitGet(Zustand*)), wp, SLOT(setZp(Zustand*)));



}
