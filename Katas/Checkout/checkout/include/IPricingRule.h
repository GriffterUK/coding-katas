#ifndef IPRICINGRULE_H
#define IPRICINGRULE_H

#include <memory>

class IPricingRule
{
public:
    IPricingRule() { }
    virtual ~IPricingRule() { }

public:
    virtual int priceFor(int quantity) const = 0;
};

typedef std::shared_ptr<IPricingRule> IPricingRulePtr;

#endif // IPRICINGRULE_H
