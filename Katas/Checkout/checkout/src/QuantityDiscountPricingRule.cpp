#include "../include/QuantityDiscountPricingRule.h"
#include <stdexcept>

QuantityDiscountPricingRule::QuantityDiscountPricingRule(int standardPrice, int specialPrice, int forQuantity)
    : standardPrice(standardPrice), specialPrice(specialPrice), quantityRequiredForSpecialPrice(forQuantity)
{
    if ( quantityRequiredForSpecialPrice <= 0) {
        throw std::invalid_argument("Quantity for special price must be positive non-zero value");
    }
}

IPricingRulePtr QuantityDiscountPricingRule::create(int standardPrice, int specialPrice, int forQuantity)
{
    return IPricingRulePtr(new QuantityDiscountPricingRule(standardPrice, specialPrice, forQuantity));
}

int QuantityDiscountPricingRule::priceFor(int quantity) const
{
    int multiplesOfSpecialPrice = quantity / quantityRequiredForSpecialPrice;
    int numItemsAtStandardPrice = quantity % quantityRequiredForSpecialPrice;

    return (multiplesOfSpecialPrice * specialPrice) + (numItemsAtStandardPrice * standardPrice);
}

