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




## Assignment 2: Income Tax Calculator

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

## Assignment 3: ASCII Art Hut

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

## Assignment 4: Matrix Chain Multiplication usingh Recursion

### Program: `mcmRecursion.c`

**Goal:** Write a C program that calculates in how many ways a Maxtric Chain can Multiplied using a recursive function with the formula: P(N) = Σ(k=1 to N-1)[P(k) × P(N-k)].

### How It Works:

The program demonstrates recursion by computing the number of ways to parenthesize matrix multiplication.

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

### Example Sequence:

| N | P(N) | Meaning |
|---|------|---------|
| 1 | 1 | Base case |
| 2 | 1 | Base case |
| 3 | 2 | Two ways |
| 4 | 5 | Five ways |
| 5 | 14 | Fourteen ways |
| 6 | 42 | Forty-two ways |

### Output Example:
```
Enter value of N: 5

P(5) = 14
```


**Performance:** The program works well for small values (N ≤ 15), but becomes very slow for larger inputs. For better performance, you could use:
- Direct formula: P(n+1) = (2n)! / ((n+1)! × n!)

This program demonstrates:
- Recursive function design
- Mathematical formula implementation
- Loop and recursion combination
- Base case importance in recursion

---

## Assignment 5: 3D Spinning Donut (Donut.c)

### Program: `donut.c`

**Goal:** Create the famous spinning 3D ASCII donut animation using mathematics, trigonometry, and 3D graphics concepts.

### Overview:

This is one of the most famous C programs on the internet, created by Andy Sloane. It renders a rotating 3D torus (donut shape) in the terminal using only ASCII characters. The program demonstrates advanced concepts like 3D mathematics, projection, lighting, and animation.

### How It Works - Step by Step:

#### Step 1: Understanding the Torus (Donut Shape)

A torus is created by rotating a circle around an axis. We need two angles:
- **Theta (θ)**: Angle around the tube (0 to 2π)
- **Phi (φ)**: Angle around the donut hole (0 to 2π)

**3D Coordinates:**
```
x = (R2 + R1*cos(θ)) * cos(φ)
y = R1 * sin(θ)
z = (R2 + R1*cos(θ)) * sin(φ)

Where:
R1 = radius of the tube (1)
R2 = distance from center to tube (2)
```

#### Step 2: Rotation in 3D Space

To make the donut spin, we rotate it around X and Y axes using rotation angles A and B:

**Rotation around X-axis (angle A):**
```
y' = y*cos(A) - z*sin(A)
z' = y*sin(A) + z*cos(A)
```

**Rotation around Z-axis (angle B):**
```
x' = x*cos(B) - y*sin(B)
y' = x*sin(B) + y*cos(B)
```

#### Step 3: 3D to 2D Projection

Project 3D coordinates onto a 2D screen:
```
K1 = screen distance (40)
K2 = distance from viewer (5)

screen_x = K1 * x / (z + K2)
screen_y = K1 * y / (z + K2)
```

The further away a point is (larger z), the smaller it appears on screen.

#### Step 4: Z-Buffer (Depth Testing)

To determine which surface is in front:
- Keep a Z-buffer array storing the depth of each pixel
- Only draw a point if it's closer than what's already there
- This ensures correct occlusion (near surfaces hide far ones)

#### Step 5: Lighting and Shading

Calculate how bright each surface point should be:
- Compute the surface normal vector (perpendicular to surface)
- Calculate angle between normal and light direction
- Choose ASCII character based on brightness:
  ```
  Darkest → Brightest:
  . , - ~ : ; = ! * # $ @
  ```

### Code Breakdown:

#### Key Variables:
```c
float A = 0, B = 0;     // Rotation angles (change over time)
float z[1760];          // Z-buffer (80 x 22 = 1760 pixels)
char b[1760];           // Character buffer for display
```

#### Main Loop Structure:
```c
for(;;) {  // Infinite animation loop
    1. Clear buffers
    2. Generate donut points
    3. Apply rotations
    4. Project to 2D
    5. Calculate lighting
    6. Update Z-buffer and character buffer
    7. Display frame
    8. Increment rotation angles
    9. Sleep briefly (for animation speed)
}
```

#### The Magic Formula:

For each point on the donut surface:
```c
// Calculate position after rotation
float D = 1 / (c * h * e + f * g + 5);  // Depth reciprocal

// Project to screen coordinates
int x = 40 + 30 * D * (l * h * m - t * n);
int y = 12 + 15 * D * (l * h * n + t * m);

// Calculate luminance (brightness)
int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
```

Where each variable represents pre-calculated sine/cosine values to optimize performance.

### Mathematical Concepts Used:

1. **Parametric Equations**: Define torus surface using two parameters
2. **Trigonometry**: sin(), cos() for circular motion
3. **3D Rotation Matrices**: Rotate objects in 3D space
4. **Perspective Projection**: Make 3D look realistic on 2D screen
5. **Dot Product**: Calculate surface lighting (N · L)
6. **Z-buffering**: Handle depth and occlusion

### Building From Scratch - Tutorial:

#### Version 1: Basic Circle (2D)
```c
// Draw a simple circle
for(float j = 0; j < 6.28; j += 0.1) {
    int x = 40 + 20 * cos(j);
    int y = 12 + 10 * sin(j);
    buffer[x + y * 80] = '*';
}
```

#### Version 2: Add Second Circle (Torus)
```c
// Two circles to form torus
for(float j = 0; j < 6.28; j += 0.07) {      // Outer circle
    for(float i = 0; i < 6.28; i += 0.02) {  // Inner circle
        float x = (2 + cos(i)) * cos(j);
        float y = sin(i);
        float z = (2 + cos(i)) * sin(j);
        // Project and display...
    }
}
```

#### Version 3: Add Rotation
```c
// Rotate using angles A and B
float x_rotated = x * cos(B) - y * sin(B);
float y_rotated = x * sin(B) + y * cos(B);
// Then project to screen...
```

#### Version 4: Add Lighting
```c
// Calculate surface normal and lighting
float N = calculate_normal(...);
char shade = ".,-~:;=!*#$@"[N];  // Pick character
```

#### Version 5: Add Z-Buffer
```c
// Only draw if closer than previous
if(D > z[index]) {
    z[index] = D;
    b[index] = shade;
}
```

### Key Techniques:

1. **Double Buffering**: Write to buffer first, then display all at once
2. **ANSI Escape Codes**: `\x1b[2J` (clear), `\x1b[H` (home cursor)
3. **Frame Rate Control**: `usleep(30000)` for ~33 FPS
4. **Memory Optimization**: Use 1D array for 2D screen
5. **Pre-calculation**: Store sin/cos values to avoid redundant calculation

### Output:
```
The program displays an infinitely spinning 3D donut made of ASCII characters,
with proper lighting, depth, and rotation. It looks like this:

          .............
       .................
     .....................
    .....,-~:;=!*#$@:~-,...
   ....,:=!*###$$###*!=:,...
  ....;=*#$$@@@@@@@@$$#*=;....
  ...;!*#$@@          @@$#*!;...
  ..,=*#$@              @$#*=,..
  ..:!*#$@              @$#*!:..
  ..;=*#$@@          @@$#*=;...
   ..,;!*#$$@@@@@@@@$$#*!;,..
    ...,:=!*###$$###*!=:,...
     ....,-~:;=!*#$@:~-,...
       .................
          .............

(Rotates continuously in 3D)
```

### How to Compile and Run:

```bash
# Compile (needs math library)
gcc donut.c -o donut -lm

# Run
./donut

# Stop with Ctrl+C
```

### Why This Program is Famous:

1. **Compact**: Does complex 3D graphics in ~40 lines
2. **No Graphics Library**: Pure terminal output
3. **Educational**: Teaches 3D graphics fundamentals
4. **Beautiful**: Mesmerizing rotating animation
5. **Mathematical**: Perfect blend of art and mathematics

### Performance Optimizations:

The original code optimizes by:
- Pre-calculating sin/cos values
- Using reciprocal (1/z) instead of division
- Combining rotation matrices into single operations
- Using character arithmetic for brightness
- Minimizing function calls

### Learning Path:

1. **Start**: Understand parametric equations for circles/torus
2. **Practice**: Draw static 2D shapes with ASCII
3. **Learn**: 3D rotation matrices and projection
4. **Implement**: Z-buffer for depth
5. **Add**: Lighting calculations
6. **Animate**: Continuous rotation with frame rate control

### Mathematical Beauty:

This program proves that:
- Complex visuals don't need expensive graphics hardware
- Mathematics can create art
- Understanding fundamentals > using libraries
- Simple rules create complex beauty

### Extensions You Can Try:

1. Add color using ANSI color codes
2. Adjust rotation speeds (change A and B increments)
3. Modify R1 and R2 for different donut sizes
4. Add user controls for rotation
5. Draw other 3D shapes (sphere, cone, cylinder)
6. Add multiple light sources
7. Implement different shading models

This program demonstrates:
- Advanced 3D mathematics and trigonometry
- Rotation matrices and transformations
- Perspective projection
- Z-buffer depth testing
- Lighting and shading algorithms
- Animation and frame rate control
- Memory buffer management
- ANSI terminal control
- Performance optimization techniques
- The beauty of mathematical programming

---
