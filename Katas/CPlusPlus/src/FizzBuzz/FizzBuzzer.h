#include <string>
#include <memory>

#ifndef FIZZBUZZ_FIZZBUZZER_H
#define FIZZBUZZ_FIZZBUZZER_H

class FizzBuzzer
{
public:
    virtual ~FizzBuzzer() { }
    virtual std::string forValue(unsigned int value) const = 0;
};

typedef std::shared_ptr<FizzBuzzer> FizzBuzzerPtr;

#endif // FIZZBUZZ_FIZZBUZZER_H
