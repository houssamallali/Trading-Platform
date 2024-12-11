#include <gtest/gtest.h>
#include "/Users/allalihoussam/Downloads/Trading-Platform/src/trade.h"

TEST(TradeTest, SetSymbolTest) {
    Trade trade;
    trade.setSymbol("BTC/USD");
    EXPECT_EQ(trade.getSymbol(), "BTC/USD");
}

TEST(TradeTest, SetQuantityTest) {
    Trade trade;
    trade.setQuantity(0.5);
    EXPECT_DOUBLE_EQ(trade.getQuantity(), 0.5);
}

TEST(TradeTest, ExecuteBuyTest) {
    Trade trade;
    trade.setSymbol("BTC/USD");
    trade.setQuantity(0.1);
    trade.executeBuy();

    auto history = trade.getTradeHistory();
    ASSERT_EQ(history.size(), 1);
    EXPECT_EQ(history[0]["action"], "buy");
    EXPECT_EQ(history[0]["symbol"], "BTC/USD");
    EXPECT_DOUBLE_EQ(history[0]["quantity"], 0.1);
}
