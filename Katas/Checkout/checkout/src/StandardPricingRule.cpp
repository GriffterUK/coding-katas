#include "../include/StandardPricingRule.h"

StandardPricingRule::StandardPricingRule(int unitPrice)
    : unitPrice(unitPrice)
{

}

IPricingRulePtr StandardPricingRule::create(int unitPrice)
{
    return IPricingRulePtr(new StandardPricingRule(unitPrice));
}

int StandardPricingRule::priceFor(int quantity) const
{
    return unitPrice * quantity;
}

