# Food Court Queue Optimizer (C++) 🍔⏱️

![Build Status](https://github.com/Aaditya0815/food-court-optimizer/actions/workflows/build.yml/badge.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B11-00599C?logo=c%2B%2B)
![DSA](https://img.shields.io/badge/Data%20Structures-Greedy%20%7C%20Queue-3fb950)

This project is a terminal-based Food Court Management Simulator written entirely in standard C++. It was developed as the capstone project for **UMT 404 — Data Structures & Algorithms** at Thapar Institute of Engineering & Technology.

The system dynamically models customer queues across multiple distinct food stalls and implements a greedy algorithm to automatically balance customer load, minimizing total waiting time.

## 🛠️ Data Structures & Algorithms Used

- **`std::queue`:** Used to model strict FIFO (First-In-First-Out) customer serving lines at each stall.
- **`std::vector`:** Dynamic array management for tracking active stalls and real-time waiting metrics.
- **Greedy Load Balancing:** The auto-allocation algorithm assigns incoming customers to the stall with the *minimum cumulative wait time*, ensuring optimal throughput and preventing queue starvation.

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (e.g., `g++` via MinGW on Windows, or standard GCC on Linux/Mac).

### Compilation
Compile the source code using:
```bash
g++ food_court_optimizer.cpp -o optimizer -std=c++11
```

### Execution
Run the executable to start the interactive CLI simulator:
```bash
# Windows
.\optimizer.exe

# Linux/macOS
./optimizer
```

## 📖 Usage Instructions
Once the simulator launches in your terminal, you will be presented with a menu:
1. **Initialize Stalls:** Create your food stalls (e.g., Pizza, Burgers) and assign base preparation times.
2. **Add Customers:** Add a customer either manually to a specific stall, or let the **Auto-Allocate** greedy algorithm place them optimally.
3. **Serve Customers:** Process the queue to serve the person at the front.
4. **View Queues:** Print the current state of all queues, including real-time waiting metrics.

## 📁 Included Files
- `food_court_optimizer.cpp`: The core C++ source code (229 lines).
- `Food_Court_Optimizer_DSA_REPORT.docx`: The full mathematical and structural documentation presented alongside the live demonstration.
