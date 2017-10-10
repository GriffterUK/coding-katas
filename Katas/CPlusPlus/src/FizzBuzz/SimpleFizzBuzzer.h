#ifndef FIZZBUZZ_SIMPLEFIZZBUZZER_H
#define FIZZBUZZ_SIMPLEFIZZBUZZER_H

#include "FizzBuzzer.h"

class SimpleFizzBuzzer : public FizzBuzzer
{
    SimpleFizzBuzzer();

public:
    virtual ~SimpleFizzBuzzer();

public:  /* instantiation via static factory method */
    static FizzBuzzerPtr create();

public: /* FizzBuzzer (implementation) */
    virtual std::string forValue(unsigned int value) const;
};

#endif // FIZZBUZZ_SIMPLEFIZZBUZZER_H
