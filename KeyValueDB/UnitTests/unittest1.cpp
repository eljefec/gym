#include "stdafx.h"
#include "CppUnitTest.h"
#include "../StaticLib/Add.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(AddWorks)
		{
			Assert::AreEqual(3, add(1, 2));
		}

	};
}