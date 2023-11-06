#ifndef RANDOMIZE_HPP
#define RANDOMIZE_HPP
#include "Queue.hpp"
#include <random>
//#include "Package.hpp"

static thread_local std::mt19937 gen;
void randomize(int n, Queue queue);
bool verify(Package package, Queue &queue);
char randNumber();
char randLetter();

#endif // RANDOMIZE_HPP
