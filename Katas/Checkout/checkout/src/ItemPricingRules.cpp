#include "../include/ItemPricingRules.h"

ItemPricingRules::ItemPricingRules()
{

}

IItemPricingRulesPtr ItemPricingRules::create()
{
    return IItemPricingRulesPtr(new ItemPricingRules());
}

void ItemPricingRules::addItemPricingRule(char itemCode, IPricingRulePtr pricingRule)
{
    itemToPricingRuleMap[itemCode] = pricingRule;
}

int ItemPricingRules::priceFor(char itemCode, int quantity) const
{
    auto itemPricingRule = itemToPricingRuleMap.find(itemCode);
    if ( itemPricingRule != itemToPricingRuleMap.end() ) {
        IPricingRulePtr pricingRule = itemPricingRule->second;
        return pricingRule->priceFor(quantity);
    }

    return 0;
}
