#ifndef STANDARDPRICINGRULE_H
#define STANDARDPRICINGRULE_H

#include "./IPricingRule.h"

class StandardPricingRule : public IPricingRule
{
private:
    int unitPrice;

protected:
    StandardPricingRule(int unitPrice);

public:
    static IPricingRulePtr create(int unitPrice);

    // IPricingRule interface
public:
    virtual int priceFor(int quantity) const override;
};

#endif // STANDARDPRICINGRULE_H
