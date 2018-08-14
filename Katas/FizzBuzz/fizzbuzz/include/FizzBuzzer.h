#ifndef FIZZBUZZ_FIZZBUZZER_H
#define FIZZBUZZ_FIZZBUZZER_H

#include <string>
#include <memory>

class FizzBuzzer
{
public:
    virtual ~FizzBuzzer() { }
    virtual std::string forValue(unsigned int value) const = 0;
};

typedef std::shared_ptr<FizzBuzzer> FizzBuzzerPtr;

#endif // FIZZBUZZ_FIZZBUZZER_H
