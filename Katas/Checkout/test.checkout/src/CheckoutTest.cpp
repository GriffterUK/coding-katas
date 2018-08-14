#include <gmock/gmock.h>

#include <string>

#include "checkout/include/Checkout.h"
#include "checkout/include/ItemPricingRules.h"
#include "checkout/include/StandardPricingRule.h"
#include "checkout/include/QuantityDiscountPricingRule.h"

#define THREE_FOR(x) x, 3
#define TWO_FOR(x) x, 2

// BACK TO THE CHECKOUT KATA

// http://codekata.com/kata/kata09-back-to-the-checkout/

// Implement code for a supermarket checkout that calculates the total price of
// a number of items. In a normal supermarket, things are identified using
// Stock Keeping Units, or SKUs. In our store, we’ll use individual letters of
// the alphabet (A, B, C, and so on). Our goods are priced individually.
// In addition, some items are multipriced: buy n of them, and they’ll cost you
// y cents. For example, item ‘A’ might cost 50 cents individually, but this week
// we have a special offer: buy three ‘A’s and they’ll cost you $1.30.
// In fact this week’s prices are:
//
// Item   Unit      Special
//        Price     Price
// --------------------------
//   A     50       3 for 130
//   B     30       2 for 45
//   C     20
//   D     15
//
// Our checkout accepts items in any order, so that if we scan a B, an A, and
// another B, we’ll recognize the two B’s and price them at 45 (for a total price
// so far of 95). Because the pricing changes frequently, we need to be able to pass
// in a set of pricing rules each time we start handling a checkout transaction.
//
// The interface to the checkout should look like:
//
// co = CheckOut.new(pricing_rules)
// co.scan(item)
// co.scan(item)
//     :    :
// price = co.total

class TestCheckout : public testing::Test
{
public:
    virtual void SetUp() {

        itemPricingRules = ItemPricingRules::create();
        itemPricingRules->addItemPricingRule('A', QuantityDiscountPricingRule::create(50, THREE_FOR(130)));
        itemPricingRules->addItemPricingRule('B', QuantityDiscountPricingRule::create(30, TWO_FOR(45)));
        itemPricingRules->addItemPricingRule('C', StandardPricingRule::create(20));
        itemPricingRules->addItemPricingRule('D', StandardPricingRule::create(15));
    }

    virtual void TearDown() {

    }

    int priceOf(std::string itemList) {

        Checkout checkout(itemPricingRules);
        for (unsigned int i = 0; i < itemList.size(); i++) {
            checkout.scan(itemList[i]);
        }

        return checkout.total();
    }

    IItemPricingRulesPtr theItemPricingRules() {
        return itemPricingRules;
    }

protected:
    IItemPricingRulesPtr itemPricingRules;

};


TEST_F (TestCheckout, ShouldTallyItemTotals) {

    ASSERT_EQ(  0, priceOf(""));
    ASSERT_EQ( 50, priceOf("A"));
    ASSERT_EQ( 80, priceOf("AB"));
    ASSERT_EQ(115, priceOf("CDBA"));

    ASSERT_EQ(100, priceOf("AA"));
    ASSERT_EQ(130, priceOf("AAA"));
    ASSERT_EQ(180, priceOf("AAAA"));
    ASSERT_EQ(230, priceOf("AAAAA"));
    ASSERT_EQ(260, priceOf("AAAAAA"));

    ASSERT_EQ(160, priceOf("AAAB"));
    ASSERT_EQ(175, priceOf("AAABB"));
    ASSERT_EQ(190, priceOf("AAABBD"));
    ASSERT_EQ(190, priceOf("DABABA"));
}

TEST_F (TestCheckout, ShouldTallyItemsIncrementally) {

      Checkout checkout(theItemPricingRules());
      ASSERT_EQ(0, checkout.total());
      checkout.scan('A');   ASSERT_EQ( 50, checkout.total());
      checkout.scan('B');   ASSERT_EQ( 80, checkout.total());
      checkout.scan('A');   ASSERT_EQ(130, checkout.total());
      checkout.scan('A');   ASSERT_EQ(160, checkout.total());
      checkout.scan('B');   ASSERT_EQ(175, checkout.total());
}
