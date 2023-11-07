#ifndef SHOW_HPP
#define SHOW_HPP
#include "Central.hpp"
#include "Stack.hpp"

void emptyFilledHub(Stack& hub, Queue& hubQueue);
void mainMenu(Central& c, Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq);
void showMenu(Central& c, Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq);
void showCentralStation(Central& central);
void packageExtraction(Central& c, Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq);
void showHub(Stack hub);
void showPackage(std::string labelID, Central c, Stack nw, Stack ne, Stack sw, Stack se, Queue nwq, Queue neq, Queue swq, Queue seq);
bool searchInCentral(std::string labelID, Central c);
bool searchInQueue(std::string labelID, Queue q);
bool searchInStack(std::string labelID, Stack s);
void isAnyHubFull(Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq);

#endif // SHOW_HPP
