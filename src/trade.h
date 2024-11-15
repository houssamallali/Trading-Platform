#ifndef TRADE_H
#define TRADE_H

#include <string>

class Trade {
public:
    void setSymbol(const std::string& symbol);
    void setQuantity(double quantity);
    void executeBuy();
    void viewTrades();

private:
    std::string symbol;
    double quantity;
};

#endif // TRADE_H