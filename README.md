# Rubik's Cube Solver

A terminal-based Rubik's Cube solver that implements Korf's optimal solving algorithm. This solver can find optimal solutions for any scrambled cube using iterative-deepening depth-first search combined with A* (IDA*).

## Features

- **Optimal Solutions**: Implements Korf's algorithm to find solutions in 20 moves or fewer
- **Terminal Interface**: Simple command-line interface for easy use
- **Standard Notation**: Uses standard Rubik's Cube notation for input and output
- **Cross-Platform**: Works on any system with a terminal

## Rubik's Cube Notation

This solver uses standard twist notation:

- **U, L, F, R, B, D**: 90-degree clockwise twists of the Up, Left, Front, Right, Back, and Down faces
- **U', L', F', R', B', D'**: Counter-clockwise twists (apostrophe indicates reverse)
- **U2, L2, F2, R2, B2, D2**: 180-degree twists (2 indicates double turn)

**Examples:**
- `U` = Turn upper face 90° clockwise
- `R'` = Turn right face 90° counter-clockwise  
- `F2` = Turn front face 180°

## How to Use

1. **Start the program**
2. **Enter your scramble** using cube notation (space-separated moves)
   ```
   Enter scramble: R U R' U' F2 D' L2 B
   ```
3. **Get the solution** - the program will output the optimal sequence of moves
   ```
   Solution: B' L2 D F2 U R U' R'
   Solution length: 8 moves
   ```

## Building and Running

### Prerequisites
- C++ compiler (g++, clang++, etc.)
- CMake
- Make

### Compilation
```bash
# Navigate to the build directory
cd build

# Generate build files
cmake ..

# Build the project
make
```

### Running
```bash
./cube_solver
```

## Algorithm Details

This solver implements **Korf's Algorithm**, which uses:

- **IDA* (Iterative Deepening A*)**: Combines the optimality guarantee of breadth-first search with the memory efficiency of depth-first search
- **Heuristic Search**: Uses admissible heuristics to guide the search and prune impossible branches
- **Optimal Solutions**: Guaranteed to find solutions in 20 moves or fewer

### How it Works

1. **Iterative Deepening**: Searches for solutions of increasing depth (1 move, 2 moves, 3 moves, etc.)
2. **A* Heuristic**: Estimates the minimum moves needed from current state to solved state
3. **Pruning**: Eliminates branches that cannot lead to optimal solutions
4. **Move Optimization**: Removes redundant moves (e.g., R R = R2, R R' = no move)

## Performance Notes

- **Search Time**: May take longer for complex scrambles (15+ moves to solve)
- **Memory Usage**: Efficient memory usage compared to breadth-first approaches
- **Optimality**: Always finds the shortest possible solution

## Example Session

```
Rubik's Cube Solver
==================

Enter scramble: R U2 R' D' R U' R' D
Solving...

Solution: D' R U R' D R U2 R'
Solution length: 8 moves
Time taken: 0.234 seconds

Enter scramble: F R U' R' F' U2 F R U R' F'
Solving...

Solution: F R U' R' F' U2 F R U R' F'
Solution length: 11 moves
Time taken: 1.456 seconds
```

## Limitations

- No visual representation (terminal-based only)
- No pattern databases implemented (may result in longer solve times)
- Single-threaded implementation

## Technical Implementation

- **Language**: C++
- **Algorithm**: Korf's IDA* with admissible heuristics
- **Data Structures**: Efficient cube state representation
- **Search Strategy**: Iterative deepening depth-first search

## Future Improvements

- [ ] Pattern databases for faster solving
- [ ] Multi-threading support
- [ ] Graphical interface
- [ ] Alternative solving algorithms (Thistlethwaite, etc.)
- [ ] Cube state visualization

## References

- Korf, Richard E. *Finding Optimal Solutions to Rubik's Cube Using Pattern Databases*
- Standard Rubik's Cube notation and algorithms
