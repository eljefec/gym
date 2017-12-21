#pragma once

#include <string>
#include <iostream>

class DBRunner
{
public:
	void RunCommands(std::istream& input, std::ostream& output);
};