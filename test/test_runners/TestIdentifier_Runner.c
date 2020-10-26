#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Identifier)
{
  RUN_TEST_CASE(Identifier, StartWithLetter);
  RUN_TEST_CASE(Identifier, StartWithDigit);
  RUN_TEST_CASE(Identifier, StartWithSpecialCharacter);
  RUN_TEST_CASE(Identifier, OnlyDigitsAndLetters);
  RUN_TEST_CASE(Identifier, HasSpecialCharacter);
  RUN_TEST_CASE(Identifier, EmptyString);
  RUN_TEST_CASE(Identifier, ShortValidString);
  RUN_TEST_CASE(Identifier, LongValidString);
  RUN_TEST_CASE(Identifier, LongInvalidString);
  RUN_TEST_CASE(Identifier, StartWithCapitalLetter);
  RUN_TEST_CASE(Identifier, HasCapitalLetter);
}
