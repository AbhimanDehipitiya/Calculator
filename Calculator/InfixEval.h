#pragma once

#include <string>
#include <stack>
using namespace std;

int precedence(char op);
float applyOp(float a, float b, char op);
float evaluate(string tokens);

