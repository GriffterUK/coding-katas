#include <gtest/gtest.h>

#include "./FizzBuzzExpectationBuilder.h"

#include "../../src/FizzBuzz/FizzBuzzer.h"
#include "../../src/FizzBuzz/SimpleFizzBuzzer.h"


// FIZZ-BUZZ KATA

// http://codingdojo.org/kata/FizzBuzz/

// Return a string that represents the input value, unless
//  * the input value is divisible by three, in which case return the word "Fizz"
//  * the input value is divisible by five, in which case return the word "Buzz"
//  * the input value is divisible by three and five, in which case return the word "FizzBuzz"

// e.g.
// 1
// 2
// Fizz
// 4
// Buzz
// Fizz
// 7
// 8
// Fizz
// Buzz
// 11
// Fizz
// 13
// 14
// FizzBuzz
// 16
// 17
// Fizz
// 19
// Buzz
// ... etc up to 100


// ************************ The Tests ***************************

class TesFizzBuzzShould: public ::testing::Test {

    std::list<FizzBuzzerPtr> fizzBuzzImplementations;

public:
    void SetUp(void) {
        fizzBuzzImplementations.push_back(SimpleFizzBuzzer::create());
    }

public:
    FizzBuzzExpectationBuilderPtr fizzBuzzBuilder() {
        return FizzBuzzExpectationBuilder::create(fizzBuzzImplementations);
    }
};


TEST_F(TesFizzBuzzShould, GiveFizzWhenValueIsMultipleOfThree)
{
    fizzBuzzBuilder()->forMultipleOf(3).
                       expectValueToBe("Fizz").build();
}

TEST_F(TesFizzBuzzShould, GiveBuzzWhenValueIsMultipleOfFive)
{
    fizzBuzzBuilder()->forMultipleOf(5).
                       expectValueToBe("Buzz").build();
}

TEST_F(TesFizzBuzzShould, GiveFizzBuzzWhenValueIsMultipleOfFifteen)
{
    fizzBuzzBuilder()->forMultipleOf(15).
                       expectValueToBe("FizzBuzz").build();
}

TEST_F(TesFizzBuzzShould, GiveNumberWhenValueIsNotMultipleOfThreeOrFive)
{
    fizzBuzzBuilder()->excludingMultiplesOf(3).
                       excludingMultiplesOf(5).
                       expectValueToBeTheNumber().build();
}

// ************************ End Of Tests **************************



