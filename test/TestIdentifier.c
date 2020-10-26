#include "identifier.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Identifier);

TEST_SETUP(Identifier)
{
}

TEST_TEAR_DOWN(Identifier)
{
}

TEST(Identifier, StartWithLetter)
{
    char string[] = "abcd";
    TEST_ASSERT_EQUAL(0, identifier(string));
}

TEST(Identifier, StartWithDigit)
{
    char string[] = "1abc5";
    TEST_ASSERT_EQUAL(1, identifier(string));
}

TEST(Identifier, StartWithSpecialCharacter)
{
    char string[] = "@abc5";
    TEST_ASSERT_EQUAL(1, identifier(string));
}

TEST(Identifier, OnlyDigitsAndLetters)
{
    char string[] = "abc53";
    TEST_ASSERT_EQUAL(0, identifier(string));
}

TEST(Identifier, HasSpecialCharacter)
{
    char string[] = "abc@5";
    TEST_ASSERT_EQUAL(1, identifier(string));
}

TEST(Identifier, EmptyString)
{
    char string[] = "";
    TEST_ASSERT_EQUAL(1, identifier(string));
}

TEST(Identifier, ShortValidString)
{
    char string[] = "a";
    TEST_ASSERT_EQUAL(0, identifier(string));
}

TEST(Identifier, LongValidString)
{
    char string[] = "abcd12";
    TEST_ASSERT_EQUAL(0, identifier(string));
}

TEST(Identifier, LongInvalidString)
{
    char string[] = "abcd123";
    TEST_ASSERT_EQUAL(1, identifier(string));
}

TEST(Identifier, StartWithCapitalLetter)
{
    char string[] = "Abcd12";
    TEST_ASSERT_EQUAL(0, identifier(string));
}

TEST(Identifier, HasCapitalLetter)
{
    char string[] = "aBcd12";
    TEST_ASSERT_EQUAL(0, identifier(string));
}

