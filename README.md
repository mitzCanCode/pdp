# 🏆 PDP Competition Solutions

**37th Panhellenic Programming Competition Solutions**

A collection of competitive programming solutions implemented in C, showcasing algorithmic problem-solving skills and optimization techniques.

---

## 📋 Competition Overview

The **Panhellenic Programming Competition (PDP)** is Greece's premier competitive programming contest for high school students. This repository contains my solutions to problems from the 37th edition of the competition.

### 🎯 Problems Solved

| Problem | Difficulty | Algorithm | Status |
|---------|------------|-----------|--------|
| **Hiring** | ⭐⭐⭐ | Greedy + Merge Sort | ✅ Complete |
| **Polybox** | ⭐⭐⭐⭐ | Big Integer Arithmetic | ✅ Complete |
| **Samepizzas** | ⭐⭐ | Sorting + Selection | ✅ Complete |
| **Shroompath** | ⭐⭐⭐⭐⭐ | Dynamic Programming + Combinatorics | ✅ Complete |

---

## 🔧 Technical Implementation

### Core Technologies
- **Language**: C
- **Compiler**: GCC compatible
- **Data Structures**: Arrays, Custom implementations
- **Algorithms**: Merge Sort, Greedy algorithms, Dynamic Programming

### Key Features
- ✅ **Optimized algorithms** for competitive programming constraints
- ✅ **Memory efficient** implementations
- ✅ **Fast I/O** handling for large datasets
- ✅ **Edge case handling** and robust error checking
- ✅ **Clean, readable code** with comprehensive comments

---

## 📁 Repository Structure

```
solutions/
├── hiring/
│   └── hiring_solution.c       # Medal allocation optimization
├── polybox/
│   └── polybox_solution.c      # Big number perimeter calculation
├── samepizzas/
│   └── samepizzas_solution.c   # Resource allocation problem
└── shroompath/
    └── shroompath_solution.c   # Path optimization with constraints
```

---

## 🚀 Problem Solutions

### 1. **Hiring** - Medal Allocation Optimization
**Problem**: Optimize medal distribution among candidates to maximize total performance.

**Approach**: 
- Custom merge sort implementation for parallel array sorting
- Greedy algorithm for optimal medal assignment
- Efficient candidate tracking to avoid duplicates

**Time Complexity**: O(n log n)

### 2. **Polybox** - Big Integer Perimeter Calculation
**Problem**: Calculate perimeter of stacked boxes with very large numbers.

**Approach**:
- Custom big integer arithmetic (addition/subtraction)
- String-based number representation for arbitrary precision
- Efficient memory management for large datasets

**Time Complexity**: O(n × d) where d is digit count

### 3. **Samepizzas** - Resource Allocation
**Problem**: Determine maximum identical items possible with given constraints.

**Approach**:
- Merge sort for ingredient sorting
- K-th element selection algorithm
- Edge case handling for impossible scenarios

**Time Complexity**: O(n log n)

### 4. **Shroompath** - Dynamic Path Optimization
**Problem**: Find minimum steps to collect required mushrooms with type constraints.

**Approach**:
- Combinatorial generation for all possible paths
- Dynamic programming for optimal path selection
- Memory efficient recursion with proper cleanup

**Time Complexity**: O(2^n × n) with optimizations

---

## 💡 Key Algorithmic Insights

### Custom Merge Sort Implementation
```c
// Parallel array sorting for maintaining index relationships
void mergeSort(int arr[], int parallelArr[], int left, int right)
```

### Big Integer Arithmetic
```c
// String-based arithmetic for handling very large numbers
char* sum(const char *number1, const char *number2)
char* subtract(const char *number1, const char *number2)
```

### Memory Management
- Proper dynamic allocation and deallocation
- Static arrays for performance in competitive programming
- Efficient string operations for large datasets

---

## 🏃‍♂️ Running the Solutions

### Prerequisites
```bash
# GCC compiler
gcc --version

# Make utility (optional)
make --version
```

### Compilation & Execution
```bash
# Navigate to solution directory
cd solutions/hiring/

# Compile
gcc -o hiring_solution hiring_solution.c -lm

# Run with input file
./hiring_solution < input.txt > output.txt
```

### Input/Output Format
Each solution expects:
- Input file: `{problem_name}.in`
- Output file: `{problem_name}.out`

---

## 🎓 Learning Outcomes

This competition enhanced my skills in:

- **Algorithm Design**: Implementing efficient solutions under time constraints
- **Data Structures**: Creating custom implementations for specific needs
- **Optimization**: Balancing time and space complexity
- **Problem Analysis**: Breaking down complex problems into manageable components
- **Code Quality**: Writing clean, maintainable code under pressure

---

## 🔍 Code Quality Features

### Documentation
- Comprehensive inline comments explaining logic
- Function documentation with parameter descriptions
- Algorithm complexity analysis

### Error Handling
- File I/O error checking
- Input validation
- Memory allocation verification

### Performance Optimizations
- Efficient sorting algorithms
- Minimal memory allocations
- Optimized I/O operations

---

## 🤝 About the Author

**Developer**: mitzCanCode  
**Competition**: 37th Panhellenic Programming Competition  
**Language**: C  
**Focus**: Competitive Programming & Algorithm Optimization

---

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🌟 Acknowledgments

- **PDP Competition Organizers** for creating challenging and educational problems
- **Competitive Programming Community** for inspiration and learning resources
- **Open Source Contributors** for tools and libraries that made this possible

---

*"Code is like humor. When you have to explain it, it's bad."* - Cory House

**Happy Coding!** 🚀
