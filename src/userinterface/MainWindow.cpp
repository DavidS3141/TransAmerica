#include "../../hdr/userinterface/MainWindow.h"
#include "../../hdr/userinterface/styletransamerica.h"

MainWindow::MainWindow() {

    QApplication::setStyle(new StyleTransamerica);
	wp = new ShowSimulationWindow(0);
	setCentralWidget(wp);

    createActions();
    createToolBar();
    createStatusBar();

    setUnifiedTitleAndToolBarOnMac(true);

	showMaximized();
//	connect(wp->newGameButton, SIGNAL(released()), this, SLOT(openInit()));
	openInit();

}

void MainWindow::startSimulation(int games, vector<AI*> aiList) {
	myGameExe = new GameExec(wp, aiList, games);
	wp->simulationp = myGameExe->simulationLogger;
	myGameExe->simulateSimulation();
	wp->updateSpinBoxes();
	wp->setZp();
	wp->update();
    wp->showSpielbrett();
	wp->showMaximized();
}

void MainWindow::openInit() {
	Initialize dialog("Initialize Simulation", this);
	if (dialog.exec() == QDialog::Accepted) {
		setWindowTitle(dialog.name());
		vector<AI*> aiList;
		for (int i = 0; i < dialog.aiSelected.size(); i++)
			aiList.push_back(
					createAI(dialog.aiSelected[i]->aiName.toStdString(),
							dialog.aiSelected[i]->color));
		startSimulation(dialog.numberOfGames(), aiList);
	}
	return;
}

void MainWindow::createActions(){
    newSimulationAct = new QAction(QIcon("images/SimulationIcon.png"), tr("&New Simulation"), this);
    newSimulationAct->setStatusTip(tr("Creates a new Simulation with selectable AIs"));
    newSimulationAct->setShortcut(QKeySequence::New);
    connect(newSimulationAct, SIGNAL(triggered()), this, SLOT(openInit()));

    newGameAct = new QAction(QIcon("images/GameIcon.png"), tr("New &Game"), this);
    newGameAct->setStatusTip(tr("Creates a new Game with a human player"));

    showDataAct = new QAction(QIcon("images/DataIcon.png"), tr("Show &Data"), this);
    showDataAct->setStatusTip(tr("Switch to the Data & Statistic of the current Simulation"));
    connect(showDataAct, SIGNAL(triggered()), wp, SLOT(showDataWidget()));

    saveSpielbrettAct = new QAction(QIcon("images/SaveIcon.png"), tr("&Save as image"), this);
    saveSpielbrettAct->setStatusTip(tr("Save the currently displayed board as image"));
    saveSpielbrettAct->setShortcut(QKeySequence::Save);
    connect(saveSpielbrettAct, SIGNAL(triggered()), this, SLOT(saveSpielbrett()));

//    newGameAct->setDisabled(true);
//    showDataAct->setDisabled(true);
//    saveSpielbrettAct->setDisabled(true);
}

void MainWindow::createToolBar(){
    myToolBar = addToolBar("ToolBar");
    myToolBar->addAction(newSimulationAct);
    myToolBar->addAction(newGameAct);
    myToolBar->addAction(showDataAct);
    myToolBar->addSeparator();
    myToolBar->addAction(saveSpielbrettAct);
}
void MainWindow::createStatusBar(){
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::saveSpielbrett(){

}
void MainWindow::displayOnStatusBar(QString string, int time){
    statusBar()->showMessage(string,time);
}

