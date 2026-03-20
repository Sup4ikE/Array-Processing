#include "pch.h"
#include "CppUnitTest.h"
#include "../ArrayProcessing/functions.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ArrayProcessingTests
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSum)
        {
            vector<int> v = { 1, 2, 3 };

            int result = sumOfElements(v);

            Assert::AreEqual(6, result);
        }

        TEST_METHOD(TestSortAsc)
        {
            vector<int> v = { 3, 1, 2 };

            sortAsc(v);

            vector<int> expected = { 1, 2, 3 };

            for (int i = 0; i < v.size(); i++)
            {
                Assert::AreEqual(expected[i], v[i]);
            }
        }

        TEST_METHOD(TestRemoveDuplicates)
        {
            vector<int> v = { 1, 1, 2, 3, 3 };
            vector<int> unique;

            rmDuplicates(v, unique);

            vector<int> expected = { 1, 2, 3 };

            Assert::AreEqual((int)expected.size(), (int)unique.size());

            for (int i = 0; i < unique.size(); i++)
            {
                Assert::AreEqual(expected[i], unique[i]);
            }
        }
    };
}