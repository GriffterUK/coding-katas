#ifndef IITEMPRICINGRULES_H
#define IITEMPRICINGRULES_H

#include <memory>
#include "./IPricingRule.h"

class IItemPricingRules
{
public:
    virtual ~IItemPricingRules() { }

public:
    virtual void addItemPricingRule(char itemCode, IPricingRulePtr pricingRule) = 0;
    virtual int priceFor(char itemCode, int quantity) const = 0;
};

typedef std::shared_ptr<IItemPricingRules> IItemPricingRulesPtr;

#endif // IITEMPRICINGRULES_H
