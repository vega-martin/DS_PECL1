#ifndef SHOW_HPP
#define SHOW_HPP
#include "Central.hpp"
#include "Stack.hpp"

void mainMenu(Central c, Stack nw, Stack ne, Stack sw, Stack se, Queue nwq, Queue neq, Queue swq, Queue seq);
void showMenu(Central c, Stack nw, Stack ne, Stack sw, Stack se, Queue nwq, Queue neq, Queue swq, Queue seq);
void showCentralStation(Central central);
void showHub(Stack hub);
void showPackage();

#endif // SHOW_HPP

