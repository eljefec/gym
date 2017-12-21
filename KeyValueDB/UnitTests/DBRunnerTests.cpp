#include "stdafx.h"
#include "CppUnitTest.h"
#include "../StaticLib/DBRunner.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(DBRunnerTests)
	{
	public:

		/*
		TEST_METHOD(RunCommands)
		{
			const char* commands = "SET a 10\
\nSET b 10\
\nNUMWITHVALUE 10\
\nNUMWITHVALUE 20\
\nSET b 30\
\nNUMWITHVALUE 10\
\nEND";

			DBRunner runner;
			runner.RunCommands(commands);

			const char* expected = "2\
\n0\
\n1\
";

			Assert::AreEqual(expected, runner.GetFullOutput().c_str());
		}
		*/
	};
}