
# Trading Platform Simulator

## Description
A simple, lightweight trading platform simulator written in C++ that uses a JSON file to manage trades. 

---

## Features
- Simulates basic trading actions (`buy` and `sell`).
- Stores trades persistently in a local JSON file (`trades.json`).
- Allows viewing of trade history.
- Uses the lightweight [nlohmann/json](https://github.com/nlohmann/json) library for JSON handling.

---

## Requirements
- C++ compiler with C++17 support (e.g., GCC, Clang, or MSVC).
- CMake (version 3.10 or newer).

---

## Project Structure


```trading-platform/
├── CMakeLists.txt         # CMake configuration file
├── src/
│   ├── main.cpp           # Entry point of the application
│   ├── trade.cpp          # Implementation of trading logic
│   ├── trade.h            # Header file for Trade class
├── data/
│   └── trades.json        # JSON file storing trade history
├── third_party/
│   └── nlohmann/          # JSON library (single-header)
│       └── json.hpp
├── build/                 # Build directory (created after running CMake)
```


## Setup Instructions

### 1. Clone the Repository
```bash
git clone https://github.com/your-username/trading-platform-simulator.git
cd trading-platform-simulator
```

### 2. Build the Project
1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

2. Generate the build files using CMake:
   ```bash
   cmake ..
   ```

3. Build the project:
   ```bash
   cmake --build .
   ```

### 3. Run the Program
After building, run the executable:
```bash
./TradingPlatform
```

---

## How to Use

### 1. Execute a Trade
To execute a new trade, modify the `main.cpp` file to set the desired symbol and quantity:
```cpp
trade.setSymbol("BTC/USD"); // Specify the trading pair
trade.setQuantity(0.1);     // Specify the quantity to trade
trade.executeBuy();         // Execute the buy action
```

Rebuild and run the program to execute the trade.

### 2. View Trade History
The program automatically saves all executed trades to `data/trades.json`. Use the `viewTrades()` function to display the full history:
```cpp
trade.viewTrades();
```

### 3. Inspect or Edit the JSON File
You can manually inspect or modify the `data/trades.json` file. A typical example of the file looks like this:
```json
{
    "trades": [
        {
            "symbol": "BTC/USD",
            "quantity": 0.1,
            "action": "buy",
            "timestamp": "2024-11-15T10:00:00Z"
        }
    ]
}
```

---

## Testing the Project
Currently, the project supports manual testing through:
1. Running the executable and verifying console outputs.
2. Checking the contents of `data/trades.json` after executing trades.

---

## Example Outputs

### Running the Program
```plaintext
Trading Platform Initialized!
Trade executed successfully! Trade: {
    "symbol": "BTC/USD",
    "quantity": 0.1,
    "action": "buy"
}
Viewing all trades:
{
    "symbol": "BTC/USD",
    "quantity": 0.1,
    "action": "buy"
}
```

### Updated JSON File
After running the program, the `data/trades.json` file will look like this:
```json
{
    "trades": [
        {
            "symbol": "BTC/USD",
            "quantity": 0.1,
            "action": "buy",
            "timestamp": "2024-11-15T10:00:00Z"
        }
    ]
}
```

---

## Troubleshooting

### 1. Missing or Malformed `trades.json` File
If `data/trades.json` is missing or contains invalid JSON, the program will initialize it with an empty structure:
```json
{
    "trades": []
}
```

### 2. Compilation Issues
Ensure your compiler supports C++17 and CMake is installed. Run:
```bash
g++ --version
cmake --version
```

If dependencies like `nlohmann/json` are missing, ensure the file `third_party/nlohmann/json.hpp` exists.

---

## Future Enhancements
- Add more trading actions (e.g., limit orders, stop-loss).
- Implement a CLI or GUI interface for better user interaction.
- Add automated tests using a testing framework (e.g., Google Test).

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
```

---

You can now copy this directly, and add the project structure section manually as required. Let me know if you need further adjustments!
