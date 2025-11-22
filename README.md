# Assignment

## Assignment 1: Print Name Without Semicolon

### Program: `nameWithoutSemicolon.c`

**Goal:** Write a C program that prints your name without using a semicolon.

### How It Works:

The program shows a clever way to avoid using a semicolon after `printf` by using these ideas:

1. **What `printf` Returns:** The `printf` function gives back a number that shows how many letters it printed.

2. **Using If Statement:** The program uses an `if` statement to check what `printf` returns. Since `printf("Raghvendra Singh\n")` prints 17 letters (including the new line), it returns 17, which means "true" in C.

3. **Empty Action:** The `if` statement has empty braces `{}`, so nothing extra happens. But the semicolon rule is followed because it belongs to the `if` statement, not directly to `printf`.

### Code Explanation:
```c
if (printf("Raghvendra Singh\n")) {}
```
- `printf("Raghvendra Singh\n")` runs and prints the name
- Returns how many letters were printed (17)
- The `if` checks this number (17 means true)
- Empty braces do nothing
- The semicolon belongs to the `if` statement, not to `printf`

### Output:
```
Raghvendra Singh
```

This smart solution shows you understand:
- What functions return
- How if statements work
- Different ways to write C code

---

## Assignment 2: ASCII Art Hut

### Program: `hut.c`

**Goal:** Write a C program that draws a hut using text characters with loops and if statements.

### How It Works:

The program shows how to use loops and conditions to make pictures with text:

1. **Split Into Parts:** The program has two functions - `roof()` and `body()` - to make the code easier to read and understand.

2. **Making the Roof:** Uses loops inside loops to create a triangle roof with:
    - Spaces to center it
    - Empty space inside (between the stars)
    - Solid top and bottom edges

3. **Making the Body:** Creates the main house with:
    - Walls on left and right sides
    - Two windows placed evenly
    - A door in the middle with frame
    - Solid bottom floor

### Code Parts:

#### Roof Function:
```c
void roof()
```
- Makes a 5-row triangle roof
- Uses math to center each row: `roof_height - i`
- Creates hollow look by choosing when to place stars

#### Body Function:
```c
void body()
```
- Draws a 9-row rectangle building
- Uses many if checks for:
  - Wall edges (`j == 1 || j == width`)
  - Window spots (left: columns 7-10, right: columns 24-28)
  - Door frame and opening (columns 13-21)
  - Floor bottom (`i == height`)

### Output:
```
    *************************************
   *                                     *
  *                                       *
 *                                         *
*********************************************
      *                               *
      *     ****              ****    *
      *     ****  *********   ****    *
      *     ****  *       *   ****    *
      *     ****  *       *   ****    *
      *           *       *           *
      *           *       *           *
      *           *       *           *
      *********************************
```

This program shows:
- How to control nested loops
- Using complex if statements
- Making pictures with text
- Breaking code into smaller functions

---

## Assignment 3: Recursive Catalan Number Calculator

### Program: `mcmRecursion.c`

**Goal:** Write a C program that calculates Catalan numbers using a recursive function with the formula: P(N) = Σ(k=1 to N-1)[P(k) × P(N-k)].

### How It Works:

The program demonstrates recursion by computing Catalan numbers, which appear in many counting problems like the number of ways to parenthesize matrix multiplication.

1. **Base Cases:** When N is 0 or 1, the function returns 1. These are the simplest cases that stop the recursion.

2. **Recursive Formula:** For any N greater than 1, the function calculates the sum by:
   - Looping through k from 1 to N-1
   - Calling P(k) and P(N-k) recursively
   - Multiplying these results and adding to the total

3. **How Recursion Works:** Each call to P(n) creates multiple smaller calls until reaching the base cases, then combines the results going back up.

### Code Explanation:

```c
int P(int n) {
    // Base case: stop recursion
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int result = 0;
    
    // Sum up all combinations
    for (int k = 1; k <= n - 1; k++) {
        result += P(k) * P(n - k);
    }
    
    return result;
}
```

### Mathematical Formula:

$$P(N) = \sum_{k=1}^{N-1} P(k) \times P(N-k)$$

Where:
- P(0) = 1
- P(1) = 1
- P(N) = sum of products of smaller P values

### Example Calculation:

```
P(3) = P(1)×P(2) + P(2)×P(1)
     = 1×1 + 1×1
     = 2

P(4) = P(1)×P(3) + P(2)×P(2) + P(3)×P(1)
     = 1×2 + 1×1 + 2×1
     = 5
```

### Catalan Numbers Sequence:

| N | P(N) | Meaning |
|---|------|---------|
| 0 | 1 | Base case |
| 1 | 1 | Base case |
| 2 | 2 | Two ways |
| 3 | 5 | Five ways |
| 4 | 14 | Fourteen ways |
| 5 | 42 | Forty-two ways |

### Output Example:
```
Enter value of N: 4

P(4) = 14
```

### Real-World Applications:

Catalan numbers count:
- Ways to parenthesize matrix multiplications
- Number of binary search trees with N nodes
- Valid combinations of balanced parentheses
- Ways to triangulate a polygon
- Paths in a grid that don't cross the diagonal

### Important Notes:

**Time Complexity:** This pure recursive approach has exponential time complexity O(2^N) because it recalculates the same subproblems multiple times. For example, when computing P(5), the value P(2) might be calculated dozens of times.

**Performance:** The program works well for small values (N ≤ 15), but becomes very slow for larger inputs. For better performance, you could use:
- Memoization (caching results)
- Dynamic programming (bottom-up approach)
- Direct Catalan formula: C(n) = (2n)! / ((n+1)! × n!)

This program demonstrates:
- Recursive function design
- Mathematical formula implementation
- Loop and recursion combination
- Base case importance in recursion
- Exponential time complexity concepts

---

## Assignment 4: Income Tax Calculator

### Program: `taxCalculator.c`

**Goal:** Write a C program that calculates income tax for Financial Year 2025-26 based on both Old and New tax regimes.

### How It Works:

The program helps users calculate their income tax liability by choosing between two different tax calculation methods available in India.

1. **Two Tax Regimes:** India offers two ways to calculate tax:
   - **Old Regime:** Lower standard deduction but allows various exemptions and deductions
   - **New Regime:** Higher standard deduction but no exemptions allowed

2. **Standard Deduction:** Amount automatically subtracted from income before tax calculation:
   - Old Regime: ₹50,000
   - New Regime: ₹75,000

3. **Tax Slabs:** Different income ranges are taxed at different rates, with higher income being taxed more.

4. **Section 87A Rebate:** Special benefit for low-income taxpayers:
   - Old Regime: No tax up to ₹5.5 lakhs
   - New Regime: No tax up to ₹12.75 lakhs

### Code Structure:

#### Old Regime Function:
```c
double calculate_old_regime(double income)
```
**Tax Slabs:**
- Up to ₹2.5 lakhs: 0%
- ₹2.5L to ₹5L: 5%
- ₹5L to ₹10L: 20%
- Above ₹10L: 30%

**Standard Deduction:** ₹50,000

#### New Regime Function:
```c
double calculate_new_regime(double income)
```
**Tax Slabs:**
- Up to ₹4 lakhs: 0%
- ₹4L to ₹8L: 5%
- ₹8L to ₹12L: 10%
- ₹12L to ₹16L: 15%
- ₹16L to ₹20L: 20%
- ₹20L to ₹24L: 25%
- Above ₹24L: 30%

**Standard Deduction:** ₹75,000

#### Cess Calculation:
```c
double calculate_cess(double tax)
```
Adds 4% Health and Education Cess on the calculated tax amount.

### Example Calculation:

**For ₹10,00,000 income under New Regime:**

```
Gross Income:           ₹10,00,000
Standard Deduction:     -   ₹75,000
Taxable Income:         ₹9,25,000

Tax Calculation:
₹0 to ₹4L:      ₹0      (0%)
₹4L to ₹8L:     ₹20,000 (5% of ₹4L)
₹8L to ₹9.25L:  ₹12,500 (10% of ₹1.25L)

Base Tax:       ₹32,500
Less: Rebate:   -₹32,500 (under Section 87A)
Tax:            ₹0
Cess (4%):      ₹0

Total Tax:      ₹0
```

### Output Example:
```
=====================================
   Income Tax Calculator FY 25-26   
=====================================

Enter your annual income (Rs): 1000000

Select Tax Regime:
1. Old Regime
2. New Regime
Enter your choice (1 or 2): 2

=====================================
        Tax Calculation Summary      
=====================================

Regime: NEW REGIME
Standard Deduction: Rs. 75,000
Taxable Income: Rs. 925,000.00

Income Tax: Rs. 0.00
Health & Education Cess (4%): Rs. 0.00
-------------------------------------
Total Tax Liability: Rs. 0.00

* You are eligible for tax rebate under Section 87A
* Income up to Rs. 12.75 Lakhs - 0 Tax

=====================================
Note: Calculations exclude surcharge
=====================================
```

### Tax Comparison Table:

| Income (₹) | Old Regime Tax | New Regime Tax | Better Choice |
|-----------|----------------|----------------|---------------|
| 5,00,000  | 0              | 0              | Both Same     |
| 8,00,000  | 36,400         | 0              | New Regime    |
| 10,00,000 | 88,400         | 0              | New Regime    |
| 15,00,000 | 2,38,400       | 78,000         | New Regime    |
| 20,00,000 | 3,88,400       | 1,82,000       | New Regime    |

### Key Features:

1. **Interactive Input:** User enters their income and selects preferred regime
2. **Automatic Calculations:** Program handles all tax slab calculations
3. **Rebate Application:** Automatically applies Section 87A benefits
4. **Cess Inclusion:** Adds 4% Health and Education Cess
5. **Clear Summary:** Shows breakdown of all tax components

### Important Points:

**When to Choose Old Regime:**
- If you have large deductions (80C, 80D, HRA, etc.)
- If your total deductions exceed the tax benefit of New Regime
- Generally better for income with many investments

**When to Choose New Regime:**
- If you have minimal or no deductions
- For income up to ₹12.75 lakhs (zero tax)
- Simpler calculation with higher exemption limit
- Better for most salaried employees without investments

### Limitations:

- Does not calculate surcharge (for very high income)
- Assumes no other deductions in Old Regime
- Simplified calculation for educational purposes
- Does not handle TDS (Tax Deducted at Source)

This program demonstrates:
- Function-based modular design
- Financial calculations and algorithms
- Conditional logic for tax slabs
- Real-world application of programming
- User input validation and formatting
- Mathematical progression in tax rates

---


