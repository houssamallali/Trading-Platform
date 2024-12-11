// trade.h
#ifndef TRADE_H
#define TRADE_H

#include <string>
#include <vector>
#include </Users/allalihoussam/Downloads/Trading-Platform/src/json.hpp>

class Trade {
public:
    void setSymbol(const std::string& symbol);
    void setQuantity(double quantity);
    void executeBuy();
    void viewTrades();

    // New methods for unit testing
    std::string getSymbol() const;
    double getQuantity() const;
    std::vector<nlohmann::json> getTradeHistory() const;

private:
    std::string symbol;
    double quantity;
    std::vector<nlohmann::json> tradeHistory;
};

#endif // TRADE_H
