# **Trading Platform Simulator Tutorial**

## **Introduction**

Welcome to the **Trading Platform Simulator**! This tutorial provides step-by-step guidance on setting up, running, and interacting with the simulator. The simulator supports basic trading actions like `buy` and `sell`, while persisting trade data into a JSON file.

---

## **Setting Up the Project**

### **1. Prerequisites**
- Ensure you have a C++17-compatible compiler (e.g., GCC, Clang, or MSVC).
- Install CMake (version 3.10 or newer).
- Clone the project repository:
  ```bash
  git clone https://github.com/your-username/Trading-Platform.git
  cd Trading-Platform
  ```

### **2. Building the Project**
1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

2. Generate build files using CMake:
   ```bash
   cmake ..
   ```

3. Compile the project:
   ```bash
   cmake --build .
   ```

### **3. Running the Program**
After building, execute the program from the `build` directory:
```bash
./TradingPlatform
```

---

## **Using the Simulator**

### **1. Executing Trades**
To execute a new trade, the program allows you to specify the following:
- **Symbol:** The trading pair (e.g., BTC/USD).
- **Quantity:** The amount to trade.

Modify `src/main.cpp` with the desired values:
```cpp
trade.setSymbol("BTC/USD");
trade.setQuantity(0.1);
trade.executeBuy();
```

Rebuild and run the program to execute the trade.

### **2. Viewing Trade History**
The program logs all executed trades into `data/trades.json`. Use the `viewTrades()` function to display the full trade history:
```cpp
trade.viewTrades();
```

### **3. JSON Trade File**
You can manually inspect or modify the `data/trades.json` file. A sample structure looks like this:
```json
{
    "trades": [
        {
            "symbol": "BTC/USD",
            "quantity": 0.1,
            "action": "buy",
            "timestamp": "2024-12-11T10:00:00Z"
        }
    ]
}
```

---

## **Running Tests**
This project includes unit tests to validate key functionalities. To run the tests:
1. Build the project with tests:
   ```bash
   cmake --build .
   ```

2. Execute the unit test binary:
   ```bash
   ./build/UnitTests
   ```

The output will confirm if all tests pass.

---

## **Customizing the Simulator**
Feel free to expand the simulator by:
- Adding new trading actions (e.g., `sell`, `limit orders`).
- Enhancing the trade JSON structure.
- Adding a CLI or GUI for better interaction.

---
