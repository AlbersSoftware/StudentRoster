#pragma once
#include <string>
using namespace std;

enum EnumDegreeProgram { SECURITY, NETWORK, SOFTWARE };
//  degrees in parallel array, use degree type as an index
static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
// the goal here is get strings to output based on what enum values are.