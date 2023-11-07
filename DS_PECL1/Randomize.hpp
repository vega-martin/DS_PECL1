// THIS WHOLE FILE IS NOT MANDATORY SINCE WE ONLY HAVE METHODS IMPLEMENTED HERE
// We are going to keep it for file organisation purposes

#ifndef RANDOMIZE_HPP
#define RANDOMIZE_HPP
#include <random>

static thread_local std::mt19937 gen;
char randNumber();
char randLetter();

#endif // RANDOMIZE_HPP
