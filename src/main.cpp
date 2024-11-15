#include <iostream>
#include "trade.h"

int main() {
    std::cout << "Trading Platform Initialized!" << std::endl;

    Trade trade;

    trade.setSymbol("BTC/USD");
    trade.setQuantity(0.1);
    trade.executeBuy();

    std::cout << "Viewing all trades:" << std::endl;
    trade.viewTrades();

    return 0;
}