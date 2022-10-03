#include "symbol.h"

#include <fstream>
#include <iostream>
#include <string>

Symbol::Symbol() {}

Symbol::~Symbol() {}

void Symbol::set_Symbol(std::string _symbol) { symbol = _symbol; }

std::string Symbol::get_Symbol() { return symbol; }
