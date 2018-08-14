#ifndef FIZZBUZZEXPECTATIONBUILDER_H
#define FIZZBUZZEXPECTATIONBUILDER_H

#include <memory>
#include <list>
#include <string>

#include "../../fizzbuzz/include/FizzBuzzer.h"

class FizzBuzzExpectationBuilder;
typedef std::shared_ptr<FizzBuzzExpectationBuilder> FizzBuzzExpectationBuilderPtr;

class FizzBuzzExpectationBuilder
{
private:
    const unsigned int MaxExpectationChecks = 100;

private:
    unsigned int multiplier = 1;
    std::string expectedValue = "";
    std::list<unsigned int> excludedMultplies;

    std::list<FizzBuzzerPtr> fizzBuzzerImplementations;

    FizzBuzzExpectationBuilder(const std::list<FizzBuzzerPtr>&  fizzBuzzerImplementations)
        : fizzBuzzerImplementations(fizzBuzzerImplementations)
    {}

public:
    static FizzBuzzExpectationBuilderPtr create(const std::list<FizzBuzzerPtr>&  fizzBuzzerImplementations)
    {
        return FizzBuzzExpectationBuilderPtr(new FizzBuzzExpectationBuilder(fizzBuzzerImplementations));
    }

public:

    FizzBuzzExpectationBuilder& expectValueToBe(const std::string& expectedValue)
    {
        this->expectedValue = expectedValue;
        return *this;
    }

    FizzBuzzExpectationBuilder& expectValueToBeTheNumber()
    {
        this->expectedValue = "";
        return *this;
    }

    FizzBuzzExpectationBuilder& forMultipleOf(unsigned int multiplier)
    {
        this->multiplier = multiplier;
        return *this;
    }

    FizzBuzzExpectationBuilder& excludingMultiplesOf(unsigned int multiplierToExclude)
    {
        this->excludedMultplies.push_back(multiplierToExclude);
        return *this;
    }

    void build()
    {
        for ( FizzBuzzerPtr fizzBuzzerImplementation : fizzBuzzerImplementations ) {

            for (unsigned int value = multiplier; value < MaxExpectationChecks; value += multiplier) {

                if ( shouldCheckForValue(value) ) {
                    std::string expectedResultForThisValue = expectedValue.length() > 0 ? expectedValue : std::to_string(value);
                    ASSERT_TRUE(fizzBuzzerImplementation->forValue(value).find(expectedResultForThisValue) != std::string::npos );
                }
            }
        }
    }

protected:

    bool shouldCheckForValue(int value)
    {
        for (unsigned int excludedMultiple : excludedMultplies) {
            if ( value % excludedMultiple == 0 ) return false;
        }

        return true;
    }
};

#endif // FIZZBUZZEXPECTATIONBUILDER_H
