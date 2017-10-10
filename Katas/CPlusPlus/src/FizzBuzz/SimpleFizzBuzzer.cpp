#include "./SimpleFizzBuzzer.h"

SimpleFizzBuzzer::SimpleFizzBuzzer() { }
SimpleFizzBuzzer::~SimpleFizzBuzzer() { }

FizzBuzzerPtr SimpleFizzBuzzer::create()
{
    return FizzBuzzerPtr(new SimpleFizzBuzzer());
}

std::string SimpleFizzBuzzer::forValue(unsigned int value) const
{
    std::string fizzBuzzValue = "";
    if ( value %  3 == 0 ) fizzBuzzValue.append("Fizz");
    if ( value %  5 == 0 ) fizzBuzzValue.append("Buzz");
    return fizzBuzzValue.length() ? fizzBuzzValue : std::to_string(value);
}
