# Lab 5 - Hash Table

This lab focused on implementing and analyzing three variations of closed hashing techniques. Linear Probing, Quadratic Probing, and Double Hashing, within the context of a multiplayer snake game with a Bingo competition feature. The lab required designing a polymorphic abstract class `objPosHashTable` and deriving three concrete implementations for the hash table variations. The goal was to optimize the hash table's performance while ensuring correctness and efficiency in gameplay.

The report for this lab was a recorded video aimed at answering questions about the lab.

### Explanation of the Implementations
Abstract Class and Derived Implementations
- **Abstract Class (`objPosHashTable`)**:
  - Designed as a polymorphic interface to minimize code duplication.
  - Provides shared fields like `tableSize` and `myHashTable` (a heap-allocated array).
  - Implements common methods such as `insert`, `remove`, `getLambda`, and `printMe`.
  - Declares pure virtual methods for specialized probing logic, implemented in derived classes.

- **Linear Probing (`objPosLinearHashing`)**:
  - Uses the probing function `h_i(x) = (h(x) + i) mod M`.
  - Resolves collisions by linearly searching for the next available slot.

- **Quadratic Probing (`objPosQuadHashing`)**:
  - Uses the probing function `h_i(x) = (h(x) + i^2) mod M`.
  - Resolves collisions by searching quadratically, reducing clustering compared to linear probing.

- **Double Hashing (`objPosDoubleHashing`)**:
  - Uses the probing function `h_i(x) = (h(x) + i * h2(x)) mod M`, where `h2(x) = 5 - (sum of digits of h(x)) mod 5`.
  - Resolves collisions using a secondary hash function, minimizing primary clustering.


The hashing function for all implementations is:
`h_i(x) = (h(x) + h_c(i)) mod M`
Where:
- `M` is the hash table size, defaulted to 37 (a prime number).
- `h(x)` is the sum of ASCII digits of the prefix and number fields of [`objPos`].
- `h_c(i)` varies based on the probing technique:
  - `i` for Linear Probing.
  - `i^2` for Quadratic Probing.
  - `i * h2(x)` for Double Hashing.


- The hash table tracks each player's Bingo treasure list.
- Treasures are lazily deleted upon collection, and the load factor (`λ`) is updated.
- The game ends when a player's hash table reaches a load factor of `λ = 0.0`.


### Model Code Improvement Objectives
1. Implement the abstract class and all derived hash table modules.
2. Compile the project using `make clean` and [`make`] commands.
3. Test the gameplay by toggling between hash table variations in `Player::Player()` (lines 35–37).
4. Customize the `printMe()` method for compatibility with `MacUILib`.

### Questions Addressed in the Technical Q&A
1. **Why do all three hash table variations deliver identical Θ(1) performance in this setup?**
   - Explanation with examples of probing behavior and hash function efficiency.
2. **Why is the hash table size defaulted to 37?**
   - Mathematical rationale for using a prime number to reduce collisions.
3. **Which variation suffers more from primary clustering?**
   - Analysis of Linear Probing's clustering issues compared to Quadratic and Double Hashing.

### Running the Project
1. Navigate to `/Lab5-ModelCode/src`.
2. Run [`make`] to compile the project.
3. Execute `Project.exe` from `/Lab5-ModelCode/bin` to play the game.