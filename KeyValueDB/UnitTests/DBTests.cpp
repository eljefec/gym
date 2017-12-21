#include "stdafx.h"
#include "CppUnitTest.h"
#include "../StaticLib/DB.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(DBTests)
	{
	public:

		const std::string c_anyName = "AnyName";
		const std::string c_anyValue = "AnyValue";

		TEST_METHOD(SetThenGet)
		{
			DB db;
			db.Set(c_anyName, c_anyValue);
			Assert::AreEqual(c_anyValue, *db.Get(c_anyName));
		}

		TEST_METHOD(UnsetThenGet)
		{
			DB db;
			db.Set(c_anyName, c_anyValue);
			db.Unset(c_anyName);

			Assert::IsNull(db.Get(c_anyName));
		}

		TEST_METHOD(SetSetThenGet)
		{
			const std::string c_newValue("NewValue");

			DB db;
			db.Set(c_anyName, c_anyValue);
			db.Set(c_anyName, c_newValue);

			Assert::AreEqual(c_newValue, *db.Get(c_anyName));
		}

		TEST_METHOD(NumWithValue)
		{
			const size_t c_expectedCount = 5;

			DB db;
			
			for (int i = 0; i < c_expectedCount; i++)
			{
				db.Set(c_anyName + to_string(i), c_anyValue);
			}

			Assert::AreEqual(c_expectedCount, db.NumWithValue(c_anyValue));
		}

		TEST_METHOD(NumWithValueAfterUnset)
		{
			const size_t c_expectedCount = 5;

			DB db;

			for (int i = 0; i < c_expectedCount; i++)
			{
				db.Set(c_anyName + to_string(i), c_anyValue);
			}

			db.Unset(c_anyName + to_string(0));

			Assert::AreEqual(c_expectedCount - 1, db.NumWithValue(c_anyValue));
		}
	};
}