#!/bin/bash

g++ -std=c++11 -lstdc++fs -Wall -I header/ \
  header/utils/utils.h \
  header/roulette/roulette.h \
  header/player/bet.h \
  header/player/strategies/player_strategy.h \
  header/player/strategies/player_strategy_color.h \
  header/player/strategies/player_strategy_high.h \
  header/player/strategies/player_strategy_even.h \
  header/player/player.h \
  header/controller/roulette_controller.h \
  src/utils.cpp \
  src/roulette/roulette.cpp \
  src/player/strategies/player_strategy_color.cpp \
  src/player/strategies/player_strategy_high.cpp \
  src/player/strategies/player_strategy_even.cpp \
  src/player/player.cpp \
  src/player/bet.cpp \
  src/controller/roulette_controller.cpp \
   src/main.cpp \
  -o game
