# BWS-V2

## Overview
BWS-V2 is a C++ application designed to calculate and predict player rankings based on their performance and how old is their badge. The application uses a neural network to dynamically generate weight predictions and store them in a cache for efficient data processing.

## Features
- **Player Data Parsing**: Reads player data from a file and parses it into structured objects.
- **Date Utilities**: Provides functions to handle date calculations and manipulations.
- **Neural Network**: Implements a simple neural network to predict weights based on player features.
- **Dynamic Weight Calculation**: Calculates dynamic weights based on the number of badges a player has.
- **Cache Mechanism**: Stores and loads weight predictions to and from a cache file for efficient processing.
- **Unit Tests**: Comprehensive unit tests to ensure the correctness of the application.

## File Structure
```
BWS-V2/
├── include/
│   ├── Date.hpp
│   ├── DateUtils.hpp
│   ├── MathUtils.hpp
│   ├── Parser.hpp
│   ├── Player.hpp
│   └── WeightGenerator.hpp
├── src/
│   ├── Date.cpp
│   ├── DateUtils.cpp
│   ├── MathUtils.cpp
│   ├── Parser.cpp
│   ├── Player.cpp
│   ├── WeightGenerator.cpp
│   ├── main.cpp
│   ├── player_data.txt
│   └── results.txt
├── tests/
│   ├── DateTests.cpp
│   ├── DateUtilsTests.cpp
│   ├── MathUtilsTests.cpp
│   ├── ParserTests.cpp
│   ├── PlayerTests.cpp
│   └── WeightGeneratorTests.cpp
└── README.md
```

## Getting Started

### Prerequisites
- C++ compiler (e.g., g++)

### Building the Project
To build the project, navigate to the `src` directory and compile the source files:
```
cd src
g++ main.cpp DateUtils.cpp MathUtils.cpp Player.cpp Parser.cpp Date.cpp WeightGenerator.cpp -o BWSV2
```

### Running the Application
After building the project, you can run the application:
```
./BWSV2
```

### Running Unit Tests
To run the unit tests, ensure you have Google Test installed and compile the test files:
```
cd tests
g++ -std=c++11 -isystem /path/to/googletest/include -pthread DateTests.cpp DateUtilsTests.cpp MathUtilsTests.cpp ParserTests.cpp PlayerTests.cpp WeightGeneratorTests.cpp -o runTests -L /path/to/googletest/lib -lgtest -lgtest_main
./runTests
```

## Usage
1. Place the player data in `src/player_data.txt` in the specified format.
2. Run the application to parse the data, calculate the BWS ranks, and save the results in `src/results.txt`.
3. The application will also save the weight predictions in `weight_cache.txt` for future use.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Authors

[Mihal Dimo](https://github.com/mhdimo)
