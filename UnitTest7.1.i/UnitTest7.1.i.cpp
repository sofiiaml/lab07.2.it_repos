#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.2.it/PR7.2.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71i
{
	TEST_CLASS(UnitTest71i)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** arr1 = new int* [3];
			for (int i = 0; i < 3; i++) {
				arr1[i] = new int[3];
			}
			arr1[0][0] = 3;
			arr1[0][1] = 5;
			arr1[0][2] = 7;
			arr1[1][0] = 9;
			arr1[1][1] = 13;
			arr1[1][2] = 1;
			arr1[2][0] = 34;
			arr1[2][1] = 8;
			arr1[2][2] = 21;
			Sort(arr1, 3,3);
			int** arr2 = new int* [3];
			for (int i = 0; i < 3; i++) {
				arr2[i] = new int[3];
			}
			arr2[0][0] = 3;
			arr2[0][1] = 5;
			arr2[0][2] = 7;
			arr2[1][0] = 9;
			arr2[1][1] = 13;
			arr2[1][2] = 34;
			arr2[2][0] = 1;
			arr2[2][1] = 8;
			arr2[2][2] = 21;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Assert::AreEqual(arr2[i][j], arr1[i][j]);
				}
			}

			for (int i = 0; i < 3; i++) {
				delete[] arr1[i];
				delete[] arr2[i];
			}
			delete[]arr1, arr2;
		}
	};
}
