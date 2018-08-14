#ifndef ITEMPRICINGRULES_H
#define ITEMPRICINGRULES_H

#include <map>
#include "./IItemPricingRules.h"

class ItemPricingRules : public IItemPricingRules
{
private:
    std::map<char, IPricingRulePtr> itemToPricingRuleMap;

protected:
    ItemPricingRules();

public:
    static IItemPricingRulesPtr create();

    // IItemPricingRules interface
public:
    virtual void addItemPricingRule(char itemCode, IPricingRulePtr pricingRule) override;
    virtual int priceFor(char itemCode, int quantity) const override;
};

#endif // ITEMPRICINGRULES_H
