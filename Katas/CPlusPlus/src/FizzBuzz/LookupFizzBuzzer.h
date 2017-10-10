#ifndef FIZZBUZZ_LOOKUPFIZZBUZZER_H
#define FIZZBUZZ_LOOKUPFIZZBUZZER_H

#include "FizzBuzzer.h"

class LookupFizzBuzzer : public FizzBuzzer
{
    LookupFizzBuzzer();

public:
    virtual ~LookupFizzBuzzer();

public:  /* instantiation via static factory method */
    static FizzBuzzerPtr create();

public: /* FizzBuzzer (implementation) */
    virtual std::string forValue(unsigned int value) const;
};

#endif // FIZZBUZZ_LOOKUPFIZZBUZZER_H
