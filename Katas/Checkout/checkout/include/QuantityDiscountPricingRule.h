#ifndef QUANTITYDISCOUNTPRICINGRULE_H
#define QUANTITYDISCOUNTPRICINGRULE_H

#include "./IPricingRule.h"

class QuantityDiscountPricingRule : public IPricingRule
{
private:
    int standardPrice;
    int specialPrice;
    int quantityRequiredForSpecialPrice;

protected:
    QuantityDiscountPricingRule(int standardPrice, int specialPrice, int forQuantity);

public:
    static IPricingRulePtr create(int standardPrice, int specialPrice, int forQuantity);

    // IPricingRule interface
public:
    virtual int priceFor(int quantity) const override;
};

#endif // QUANTITYDISCOUNTPRICINGRULE_H
