#include "pch.h"
#include "CppUnitTest.h"

#include "CustomString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// see: Test-Api
// https://docs.microsoft.com/de-de/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference?view=vs-2019#general_are_same

namespace CustomStringTests
{
    TEST_CLASS(TestCustomString)
    {
    public:

        TEST_METHOD(TestEmptyConstructors)
        {
            auto myString = CustomString();

            Assert::AreEqual(myString.GetSize(), size_t(0));
            Assert::AreEqual(myString.Begin(), myString.End());
            Assert::IsTrue(myString.IsEmpty());
        }

        TEST_METHOD(TestFilledConstructors)
        {
            char* content = "Content";
            auto myString = CustomString(content);

            Assert::AreNotEqual(myString.GetSize(), size_t(0));
            Assert::AreEqual(myString.GetSize(), sizeof(content));
            Assert::IsFalse(myString.IsEmpty());
        }

        TEST_METHOD(TestCopyConstructors)
        {
            char* content = "Content";
            auto myString = CustomString(content);
            auto myString2 = CustomString(myString);

            Assert::AreEqual(myString.GetSize(), myString2.GetSize());
        }

        TEST_METHOD(TestClearMethod)
        {
            char* content = "Content";
            auto myString = CustomString(content);

            Assert::IsFalse(myString.IsEmpty());
            myString.Clear();
            Assert::IsTrue(myString.IsEmpty());
        }

        TEST_METHOD(TestToUpperMethod)
        {
            auto myString = CustomString("Content");
            myString.ToUpper();

            Assert::AreEqual(myString.Begin(), "CONTENT");

            myString = CustomString("0123456789");
            Assert::AreEqual(myString.Begin(), "0123456789");
        }
    };
}
