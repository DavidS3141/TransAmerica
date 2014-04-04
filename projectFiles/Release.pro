######################################################################
# .pro to use if qmake --project is not working   
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . \
              ../src \
              ../hdr \
              .. \
              ../src/ai \
              ../src/game \
              ../src/logger \
              ../src/userinterface \
              ../hdr/ai \
              ../hdr/game \
              ../hdr/logger \
              ../hdr/userinterface \
              ../src/game/boardSettings/standard \
              ../hdr/game/boardSettings/flyeurope \
              ../hdr/game/boardSettings/standard
INCLUDEPATH += . \
               ../hdr/logger \
               ../hdr/game \
               ../hdr/game/boardSettings/standard \
               ../hdr/ai \
               ../hdr/userinterface

# Input
HEADERS += ../hdr/ai/AIList.h \
           ../hdr/ai/DavidAI.h \
           ../hdr/ai/debuggerAI.h \
           ../hdr/ai/MyAIHelper.h \
           ../hdr/ai/NBSimpleAI.h \
           ../hdr/ai/templateAI.h \
           ../hdr/ai/testKI.h \
           ../hdr/game/AI.h \
           ../hdr/game/Board.h \
           ../hdr/game/City.h \
           ../hdr/game/Connection.h \
           ../hdr/game/Constants.h \
           ../hdr/game/Coordinate.h \
           ../hdr/game/Counter.h \
           ../hdr/game/Game.h \
           ../hdr/game/Human.h \
           ../hdr/game/Move.h \
           ../hdr/game/Pawn.h \
           ../hdr/game/PlayingOrder.h \
           ../hdr/game/Round.h \
           ../hdr/game/Simulation.h \
           ../hdr/game/State.h \
           ../hdr/game/Vector.h \
           ../hdr/logger/GameLogger.h \
           ../hdr/logger/RoundLogger.h \
           ../hdr/logger/SimulationLogger.h \
           ../hdr/logger/StatisticsLogger.h \
           ../hdr/userinterface/datawidget.h \
           ../hdr/userinterface/DynamicState.h \
           ../hdr/userinterface/GameExec.h \
           ../hdr/userinterface/GUIBoard.h \
           ../hdr/userinterface/Initialize.h \
           ../hdr/userinterface/MainWindow.h \
           ../hdr/userinterface/QConstants.h \
           ../hdr/userinterface/ShowSimulationWindow.h \
           ../hdr/userinterface/styletransamerica.h \
           ../hdr/userinterface/UserInputWindow.h \
           ../hdr/userinterface/Window.h \
           ../hdr/game/boardSettings/flyeurope/flyeuropeConstants.h \
           ../hdr/game/boardSettings/standard/standardConstants.h
SOURCES += ../Main.cpp \
           ../src/ai/AIList.cpp \
           ../src/ai/DavidAI.cpp \
           ../src/ai/debuggerAI.cpp \
           ../src/ai/MyAIHelper.cpp \
           ../src/ai/NBSimpleAI.cpp \
           ../src/ai/templateAI.cpp \
           ../src/ai/testKI.cpp \
           ../src/game/AI.cpp \
           ../src/game/Board.cpp \
           ../src/game/City.cpp \
           ../src/game/Connection.cpp \
           ../src/game/Constants.cpp \
           ../src/game/Coordinate.cpp \
           ../src/game/Counter.cpp \
           ../src/game/Game.cpp \
           ../src/game/Human.cpp \
           ../src/game/iterator.cpp \
           ../src/game/Move.cpp \
           ../src/game/Pawn.cpp \
           ../src/game/PlayingOrder.cpp \
           ../src/game/PlayingOrderElement.cpp \
           ../src/game/Round.cpp \
           ../src/game/Simulation.cpp \
           ../src/game/State.cpp \
           ../src/game/Vector.cpp \
           ../src/logger/GameLogger.cpp \
           ../src/logger/RoundLogger.cpp \
           ../src/logger/SimulationLogger.cpp \
           ../src/logger/StatisticsLogger.cpp \
           ../src/userinterface/datawidget.cpp \
           ../src/userinterface/DynamicState.cpp \
           ../src/userinterface/GameExec.cpp \
           ../src/userinterface/GUIBoard.cpp \
           ../src/userinterface/Initialize.cpp \
           ../src/userinterface/MainWindow.cpp \
           ../src/userinterface/QConstants.cpp \
           ../src/userinterface/ShowSimulationWindow.cpp \
           ../src/userinterface/styletransamerica.cpp \
           ../src/userinterface/UserInputWindow.cpp \
           ../src/userinterface/Window.cpp \
           ../src/game/boardSettings/standard/standardConstants.cpp
