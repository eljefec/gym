// RunDB.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "../StaticLib/DBRunner.h"

int main(int argc, char** argv)
{
	DBRunner runner;

	runner.RunCommands(std::cin, std::cout);
    
	return 0;
}

