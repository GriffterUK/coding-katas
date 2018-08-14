#include "../include/SteppedSetFizzBuzzer.h"

SteppedSetFizzBuzzer::SteppedSetFizzBuzzer()
{
    for (unsigned int i = 3; i <= 100; i+=3) {
        fizzers.insert(i);
    }
    for (unsigned int i = 5; i <= 100; i+=5) {
        buzzers.insert(i);
    }
}

SteppedSetFizzBuzzer::~SteppedSetFizzBuzzer() { }

FizzBuzzerPtr SteppedSetFizzBuzzer::create()
{
    return FizzBuzzerPtr(new SteppedSetFizzBuzzer());
}

std::string SteppedSetFizzBuzzer::forValue(unsigned int value) const
{
    std::string fizzBuzzValue = "";
    if ( fizzers.find(value) != fizzers.end() ) fizzBuzzValue.append("Fizz");
    if ( buzzers.find(value) != buzzers.end() ) fizzBuzzValue.append("Buzz");
    return fizzBuzzValue.length() ? fizzBuzzValue : std::to_string(value);
}
