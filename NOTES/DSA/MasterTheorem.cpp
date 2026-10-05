/*
MASTER THEOREM : Used to find Time Complexity of many Divide & Conquer recursive algorithms.
Does NOT apply to every recurrence. It mainly applies to :

General form: T(n) = aT(n/b) + f(n)
where,
a = number of recursive calls
b = factor by which input is divided
f(n) = extra work outside recursion


STEP 1) Calculate: n^(log_b(a))

STEP 2) Compare it with f(n).

CASE 1:
If f(n) is polynomially SMALLER: T(n) = Θ(n^(log_b(a)))

CASE 2:
If f(n) is SAME order: T(n) = Θ(n^(log_b(a)) log n)

CASE 3:
If f(n) is polynomially LARGER: T(n) = Θ(f(n))

------------------------------------------------
EXAMPLES

1. Binary Search: T(n) = T(n/2) + O(1)
→ Θ(log n)

2. Merge Sort: T(n) = 2T(n/2) + O(n)
→ Θ(n log n)

3. T(n) = 4T(n/2) + O(n)

        a = 4, b = 2

        n^(log₂4) = n²

        n < n²

        → Case 1

        → Θ(n²)

------------------------------------------------
QUICK REMEMBER

        Calculate n^(log_b(a))
                  ↓
        Compare with f(n)
                  ↓
        Smaller → Case 1
        Same    → Case 2
        Larger  → Case 3
*/