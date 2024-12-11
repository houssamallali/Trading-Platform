// trade.cpp
#include "trade.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

void Trade::setSymbol(const std::string& symbol) {
    this->symbol = symbol;
}

void Trade::setQuantity(double quantity) {
    this->quantity = quantity;
}

std::string Trade::getSymbol() const {
    return symbol;
}

double Trade::getQuantity() const {
    return quantity;
}

std::vector<json> Trade::getTradeHistory() const {
    return tradeHistory;
}

void Trade::executeBuy() {
    json tradesData;

    // Attempt to read and parse the JSON file
    try {
        std::ifstream inputFile("data/trades.json");
        if (!inputFile.is_open()) {
            tradesData = {{"trades", json::array()}};
        } else {
            inputFile >> tradesData; // Parse JSON file
        }
        inputFile.close();
    } catch (const json::parse_error& e) {
        std::cerr << "Error reading JSON file: " << e.what() << std::endl;
        tradesData = {{"trades", json::array()}}; // Reset to default
    }

    // Add a new trade
    json newTrade = {
        {"symbol", symbol},
        {"quantity", quantity},
        {"action", "buy"}
    };
    tradesData["trades"].push_back(newTrade);

    // Update internal trade history
    tradeHistory.push_back(newTrade);

    // Write back to the file
    std::ofstream outputFile("data/trades.json");
    outputFile << tradesData.dump(4); // Save with 4-space indentation
    outputFile.close();

    std::cout << "Trade executed successfully! Trade: " << newTrade.dump(4) << std::endl;
}

void Trade::viewTrades() {
    json tradesData;

    // Attempt to read and parse the JSON file
    try {
        std::ifstream inputFile("data/trades.json");
        if (!inputFile.is_open()) {
            std::cerr << "Trade history file not found!" << std::endl;
            return;
        }
        inputFile >> tradesData; // Parse JSON file
        inputFile.close();
    } catch (const json::parse_error& e) {
        std::cerr << "Error reading trade history: " << e.what() << std::endl;
        return;
    }

    // Display trade history
    std::cout << "Trade History:" << std::endl;
    for (const auto& trade : tradesData["trades"]) {
        std::cout << trade.dump(4) << std::endl;
        tradeHistory.push_back(trade);
    }
}
