
#include "../include/Checkout.h"

Checkout::Checkout(IItemPricingRulesPtr itemPricingRules)
    : itemPricingRules(itemPricingRules)
{    

}

void Checkout::scan(char item)
{
    itemToQuantityMap[item]++;
}

int Checkout::total() const
{
    int priceTotal = 0;
    for (auto itemQuantity = itemToQuantityMap.begin(); itemQuantity != itemToQuantityMap.end(); ++itemQuantity) {
        priceTotal += itemPricingRules->priceFor(itemQuantity->first, itemQuantity->second);
    }

    return priceTotal;
}
