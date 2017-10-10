#ifndef FIZZBUZZ_STEPPEDSETFIZZBUZZER_H
#define FIZZBUZZ_STEPPEDSETFIZZBUZZER_H

#include "FizzBuzzer.h"
#include <set>

class SteppedSetFizzBuzzer : public FizzBuzzer
{
    SteppedSetFizzBuzzer();

public:
    virtual ~SteppedSetFizzBuzzer();

public:  /* instantiation via static factory method */
    static FizzBuzzerPtr create();

public: /* FizzBuzzer (implementation) */
    virtual std::string forValue(unsigned int value) const;

protected:
    std::set<unsigned int> fizzers;
    std::set<unsigned int> buzzers;
    std::set<unsigned int> fizzBuzzers;
};

#endif // FIZZBUZZ_STEPPEDSETFIZZBUZZER_H
