#!/bin/bash

g++ -Wall -I header/ \
  header/roulette/roulette.h \
  header/player/bet.h \
  header/player/strategies/player_strategy.h \
  header/player/strategies/player_strategy_color.h \
  header/player/strategies/player_strategy_high.h \
  header/player/strategies/player_strategy_pair.h \
  header/player/player.h \
  header/controller/roulette_controller.h \
  src/roulette/roulette.cpp \
  src/player/strategies/player_strategy_color.cpp \
  src/player/strategies/player_strategy_high.cpp \
  src/player/strategies/player_strategy_pair.cpp \
  src/player/player.cpp \
  src/player/bet.cpp \
  src/controller/roulette_controller.cpp \
   src/main.cpp \
  -o game