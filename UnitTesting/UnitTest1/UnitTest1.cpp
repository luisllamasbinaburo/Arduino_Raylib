#include "pch.h"
#include "CppUnitTest.h"

#include "../../src/main.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			main();
		}
	};
}
