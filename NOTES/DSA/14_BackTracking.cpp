// Backtracking : Try a choice → Explore it → Undo the choice
// Basic Template
void solve(state)
{
    // Base Case
    if (done)
    {
        ans.push_back(...);
        return;
    }

    for (each choice)
    {
        if (valid(choice))
        {
            // Choose
            make(choice);

            // Explore
            solve(newState);

            // Undo → Backtrack
            undo(choice);
        }
    }
}

// Complexity : Usually exponential, because we explore many possible choices.
// Typical form :
// TC → O(branches ^ depth)
// SC → O(depth) + auxiliary data

// Common Backtracking Problems :
// Rat in a Maze
// N-Queens
// Sudoku
// Permutations
// Subsets
// Combination Sum