#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_6.2_rec/6.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr1[] = { 1, 2, 3, 4, 5 }; // Найбільший парний елемент - 4, індекс 3
			int expectedIndex1 = 3;
			int actualIndex1 = FindMaxEvenIndexRecursive(arr1, 5);
			Assert::AreEqual(expectedIndex1, actualIndex1);

		}
	};
}
