# My PDP Competition Journey

**37th Panhellenic Programming Competition - Learning C the Hard Way**

So here's the thing - I had literally **zero** experience with C programming when I decided to participate in the PDP competition. Like, I'm talking about learning pointers and memory management while simultaneously trying to solve algorithmic problems. *What could go wrong, right?*

But hey, I'm pretty proud of what I managed to pull off! This repo contains my solutions to the problems I tackled during the competition.

## What I Actually Managed to Solve

| Problem | What I Did | How I Felt About It |
|---------|------------|--------------------|
| **Hiring** | Greedy + Merge Sort | *"Wait, I actually got this working?"* |
| **Polybox** | Big Integer Arithmetic | *"Why are we doing math with strings..."* |
| **Samepizzas** | Sorting + Selection | *"I wouldn't mind a slice of pizza right arround now."* |
| **Shroompath** | Dynamic Programming + Combinatorics | *"How did I even understand this?"* |

## The Technical Stuff (AKA What I Learned)

**Tools I Used:**
- **C** (obviously, and painfully)
- **Xcode** (Awesome coding enviroment for C tbh)
- **A lot of coffee** (not technically a tool, but essential)

**What I Actually Learned:**
- That malloc and free are apparently important *(who knew?)*
- Custom sorting algorithms because apparently `qsort()` wasn't good enough
- The difference between `int` and `long int` *(the hard way)*
- How to debug C code without proper debugging tools *(aka printf debugging)*

## Where Everything Lives

```
solutions/
├── hiring/
│   ├── hiring_solution.c       # The hiring optimization that somehow worked
│   ├── hiring                  # Compiled executable
│   └── test_hiring.in          # Test input file
├── polybox/
│   ├── polybox_solution.c      # Big numbers = big headaches
│   ├── polybox                 # Compiled executable
│   └── test_polybox.in         # Test input file
├── samepizzas/
│   ├── samepizzas_solution.c   # Pizza math (tasty)
│   ├── samepizzas              # Compiled executable
│   └── test_samepizzas.in      # Test input file
└── shroompath/
    ├── shroompath_solution.c   # Mushroom collector (Why couldn't I just keep them all?)
    ├── shroompath              # Compiled executable
    ├── test_shroompath1.in     # Test input file (example 1)
    └── test_shroompath2.in     # Test input file (example 2)
```

## The Problems I Tackled (And How I Survived)

### 1. **Hiring** - *"How do you even optimize hiring contracts?"*

**What it was about:** You've got pizza maker candidates with different performance levels for bronze, silver, and gold contracts, and you need to maximize total performance while staying within budget limits for each contract type.

**How I approached it:**
- Implemented my own merge sort because I wanted to sort multiple arrays in parallel *(and because I'm apparently a masochist as said by some which saw my solution)*
- Used a greedy approach - always trying to give the best contract to the best candidate
- Kept track of who already got hired so I wouldn't double-assign

(Honestly I thought this was a great solution but the test cases thought otherwise)

**Time complexity:** O(n log n) *(I think lol... math was never my strong suit)*

### 2. **Polybox** - *"So wait low level languages aren't as easy as python is with numbers?"*

**What it was about:** Calculate the perimeter of stacked boxes, but the numbers are so huge that regular integers just give up.

**How I approached it:**
- Built my own big integer arithmetic functions because apparently normal math wasn't challenging enough
- Treated numbers as strings and did addition/subtraction digit by digit

**Time complexity:** O(n × d) where d is the number of digits *(which could be a lot)*

### 3. **Samepizzas** - *"Tasty!"*

**What it was about:** Given ingredients and their quantities, find the maximum number of identical pizzas you can make using exactly k different ingredients.

**How I approached it:**
- Sort the ingredients by quantity (more merge sort practice!)
- Pick the k-th smallest quantity
- Added some edge case handling because apparently k can be bigger than n *(who knew?)*

**Time complexity:** O(n log n) *(sorting strikes again)*

### 4. **Shroompath** - *"I'm pretty sure this is black magic"*

**What it was about:** Collect mushrooms of two types (a and b) with different weights, but you can only keep one type at a time. Find minimum steps to collect enough weight.

**How I approached it:**
- Generate all possible combinations of moves *(because brute force is a valid strategy, right?)*
- Use dynamic programming to find the optimal path
- Implemented proper memory management *(finally learned why malloc and free exist)*

*(Honestly I think this didn't pass because of how slow it was but im pretty proud of myself for even understanding the problem in the first place)*

**Time complexity:** O(2^n × n) 

## Some Code Snippets I Enjoyed Making

### My Custom Merge Sort
```c
// This sorts two arrays in parallel - pretty neat, right?
void mergeSort(int arr[], int parallelArr[], int left, int right)
```

### Big Integer Math *(AKA string math)*
```c
// Adding very large numbers represented as strings
char* sum(const char *number1, const char *number2)
char* subtract(const char *number1, const char *number2)
```

### Memory Management *(the part that gave me nightmares)*
- Actually remembering to free() what I malloc()
- Using static arrays when I could get away with it
- Learning that string operations in C are... special to say the least

## If You Want to Run This Code

**What you'll need:**
```bash
# Make sure you have GCC installed
gcc --version
```

**Easy way (using pre-compiled executables):**
```bash
# Go to whichever solution you want to try
cd solutions/hiring/

# Just run the executable with the test input
./hiring < test_hiring.in
# Output: 31 (the maximum total performance)
```

**If you want to compile from source:**
```bash
# Go to whichever solution you want to try
cd solutions/hiring/

# Compile it (the -lm flag is for math functions)
gcc -o hiring hiring_solution.c -lm

# Run it with the test input
./hiring < test_hiring.in
```

**Testing all solutions:**
```bash
# Samepizzas - should output 6
cd solutions/samepizzas/
./samepizzas < test_samepizzas.in

# Polybox - should output 30
cd ../polybox/
./polybox < test_polybox.in

# Hiring - should output 31
cd ../hiring/
./hiring < test_hiring.in

# Shroompath - should output 5 and 7 respectively
cd ../shroompath/
./shroompath < test_shroompath1.in  # outputs 5
cp test_shroompath2.in shroompath.in && ./shroompath  # outputs 7
```

**Note about shroompath:** This solution reads from a file named `shroompath.in` instead of stdin, so you'll need to copy your test input to that filename first. This was the way I had to submit my code anyway the others I adjusted to allow this form of data input.

**Test Results (because I actually verified these work):**

| Problem | Test Input | Expected Output | My Output | Official Submission |
|---------|------------|-----------------|-----------|--------------------|
| **Samepizzas** | 3 ingredients: 9, 7, 11 (k=2) | 6 pizzas | 6 | *Some test cases failed* | 
| **Polybox** | 3 boxes: 1×1×1, 2×2×2, 3×3×3 | 30 perimeter | 30 | **100% passed!** | 
| **Hiring** | 5 candidates, 2 gold, 2 silver, 1 bronze | 31 max performance | 31 | *Some test cases failed* | 
| **Shroompath** | Target: 13, weights: 5,3 | 5 steps | 5 | *Some test cases failed* | 
| **Shroompath** | Target: 10, weights: 2,5 | 7 steps | 7 | *Some test cases failed* | 

*Here's the thing - all the example test cases work perfectly, but apparently the competition had some edge cases that broke my solutions. Polybox was the only one that got 100% (probably because big integer math is either right or catastrophically wrong, no in-between). The others... well, let's just say competitive programming has a way of humbling you real quick.*

**File format:**
Each solution expects:
- Input file: `{problem_name}.in` (or stdin for most solutions)
- Output file: `{problem_name}.out` (created automatically)

## What I Actually Learned From This

- **Algorithm design:** How to break down complex problems into smaller, manageable pieces
- **Data structures:** Sometimes you need to build your own because the standard library doesn't have what you need
- **Optimization:** Balancing "does it work?" with "does it work fast enough?"
- **Problem analysis:** Reading a problem statement 50 times until it finally makes sense

## My Development Process (With Photos!)

### Planning & Algorithm Design
![Python code for hiring_solution.c planned on paper](images/python_code_on_paper_planning.png)
*Yes, I actually planned algorithms on paper for some issues*

### Learning & Preparation
![Studying C](images/studying_c.png)
*Me trying to understand basic C while questioning my life choices*

### Implementation & Testing
![Working on the Project During School Breaks](images/working_on_the_project_during_school_breaks.png)
*Coding during school breaks because later in the day I would need to study for the finals*

## About This Whole Thing

This was my first real experience with competitive programming, and honestly, I'm pretty proud of what I managed to achieve with basically no C experience. Sure, the code might not be the most elegant, and I'm sure there are more efficient ways to solve these problems, but some worked and it was pretty fun if i'm being honest!

*P.S. - If you find any bugs in this code, they're not bugs, they're features. Or at least that's what I tell myself.*
