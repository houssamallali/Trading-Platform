#include <spdlog/spdlog.h> // Include spdlog header
#include "trade.h"

int main() {
    // Logging initialization message
    spdlog::info("Trading Platform Initialized!");

    Trade trade;

    // Logging trade setup
    spdlog::info("Setting up a trade for BTC/USD with quantity 0.1");
    trade.setSymbol("BTC/USD");
    trade.setQuantity(0.1);

    // Logging trade execution
    spdlog::info("Executing Buy Trade...");
    trade.executeBuy();

    // Logging trade view
    spdlog::info("Viewing all trades:");
    trade.viewTrades();

    spdlog::info("Trading Platform execution completed.");
    return 0;
}
