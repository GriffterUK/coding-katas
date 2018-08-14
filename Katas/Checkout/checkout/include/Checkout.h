#pragma once

#include <map>
#include "./IItemPricingRules.h"

class Checkout
{
private:
    IItemPricingRulesPtr itemPricingRules;
    std::map<char, int> itemToQuantityMap;

public:
    Checkout(IItemPricingRulesPtr itemPricingRules);

public:
    void scan(char item);
    int total() const;
};
