# 📘 Computer Graphics
This repository contains implementations of basic Computer Graphics algorithms developed for a laboratory course using Programmig Language and OpenGL. It includes line and curve drawing algorithms, 2D and 3D transformations, clipping, hidden surface removal, and basic OpenGL drawing techniques, providing a practical understanding of core computer graphics concepts.

---

📌 Contents

1. DDA Line Algorithm
2. Bresenham’s line drawing algorithm
3. Mid Point Circle Algorithm
4. Mid Point Ellipse Algorithm

---

## 📘 DDA Line Drawing Algorithm

### 🔍 Overview

DDA (Digital Differential Analyzer) is a scan-conversion line drawing algorithm used in computer graphics to draw a straight line between two given points.

#### 🗝️ Key idea
A straight line can be drawn by incrementally calculating intermediate pixel positions between two endpoints using floating-point arithmetic.
The algorithm works by:
- Finding how much x and y change from one pixel to the next
- Repeatedly plotting pixels until the destination point is reached

---

### 🧠 Algorithm

1. Start
2. Read the coordinates of the first point (x1, y1)
3. Read the coordinates of the second point (x2, y2)
4. Initialize the graphics mode
5. Calculate
	- dx = x2 - x1
	- dy = y2 - y1
6. If |dx| > |dy|
	- steps = |dx|
	Else
	- steps = |dy|
7. Calculate the increment values
	- x_inc = dx / steps
	- y_inc = dy / steps
8. Set initial values
	- x = x1
	- y = y1
9. Repeat for i = 0 to steps:
	- Plot pixel at (round(x), round(y))
	- x = x + x_inc
	- y = y + y_inc
	- Add a small delay (for visualization)
10. Display the output until a key is pressed
11. Close graphics mode
12. Stop

---

### 🦾 Advantages
- Simple and easy to understand
- Works for all line slopes
- Good for educational purposes

---

### 🚩 Disadvantages
- Uses floating-point calculations
- Slower than Bresenham’s algorithm
- Accumulated rounding errors

----

## 📘 Bresenham’s Line Drawing Algorithm

### 🔍 Overview

Bresenham’s Line Drawing Algorithm is an efficient raster line drawing algorithm used in computer graphics to draw a straight line between two given endpoints.

#### 🗝️ Key idea

Unlike DDA, Bresenham’s algorithm:
- Uses only integer arithmetic
- Avoids floating-point calculations
- Decides which pixel is closer to the actual line using a decision parameter
Because of this, it is faster and more accurate than the DDA algorithm.

--- 

### 🧠 Algorithm
1. Start
2. Read the coordinates of the first point (x1, y1)
3. Read the coordinates of the second point (x2, y2)
4. Initialize the graphics mode
5. Calculate
	- dx = |x2 - x1|
	- dy = |y2 - y1|
6. Initialize the decision parameter
	- p = 2dy − dx
7. Set the starting pixel
	- x = x1
	- y = y1
8. Plot the starting pixel (x, y)
9. While x < x2, repeat:
	- Increment x by 1
	- If p < 0:
		- p = p + 2dy
	Else:
		- Increment y by 1
		- p = p + 2dy − 2dx
	- Plot the pixel (x, y)
	- Add a small delay for visualization
10. Display the output until a key is pressed
11. Close graphics mode
12. Stop

---

### 🦾 Advantages
- Uses only integer calculations
- Faster than DDA algorithm
- More accurate line rendering
- Suitable for real-time graphics

### 🚩 Disadvantages
- Original version works only for 0 < slope < 1
- Needs modification for other slopes and directions

---

## 📘 Midpoint Circle Drawing Algorithm

### 🔍 Overview

The Midpoint Circle Drawing Algorithm is an efficient rasterization algorithm used in computer graphics to draw a circle of a given center and radius.

#### 🗝️ Key idea

Instead of calculating all points of the circle the midpoint algorithm:
- Uses integer arithmetic
- Decides the next pixel based on a decision parameter
- Exploits the 8-way symmetry of a circle to reduce computation

---

### 🧠 Algorithm
1. Start
2. Read the center coordinates (xc, yc)
3. Read the radius r
4. Initialize the graphics mode
5. Initialize
	- x = 0
	- y = r
	- p = 1 − r
6. Plot the initial points using 8-way symmetry
7. While x < y, repeat:
	- Increment x by 1
	- If p < 0:
		- p = p + 2x + 1
	Else:
		- Decrement y by 1
		- p = p + 2(x − y) + 1
	- Plot the symmetric points in all 8 octants
	- Add a small delay for visualization
8. Display the output until a key is pressed
9. Close graphics mode
10. Stop

---

### 🦾 Advantages
- Uses only integer arithmetic
- Faster than parametric circle methods
- Exploits symmetry to reduce calculations
- Accurate circle representation

---

### 🚩 Disadvantages
- Limited to raster displays
- Requires separate handling for other shapes

---

## 📘 Midpoint Ellipse Drawing Algorithm

### 🔍 Overview

The Midpoint Ellipse Drawing Algorithm is a raster graphics algorithm used to draw an ellipse with a given center and x-radius and y-radius.

#### 🗝️ Key idea

The midpoint algorithm:
- Uses decision parameters to choose the next pixel
- Exploits the symmetry of an ellipse
- Divides the ellipse into two regions for efficient plotting

---

### 🧠 Algorithm
1. Start
2. Read the center coordinates (xc, yc)
3. Read the x-radius rx and y-radius ry
4. Initialize the graphics mode
5. Region 1 initialization:
	- x = 0
	- y = ry
	- p1 = ry² − rx²·ry + (1/4)·rx²
6. While (2·ry²·x) ≤ (2·rx²·y):
	- Plot the symmetric points (±x + xc, ±y + yc)
	- If p1 < 0:
		- x = x + 1
		- p1 = p1 + 2·ry²·x + ry²
	Else:
	- x = x + 1
	- y = y − 1
	- p1 = p1 + 2·ry²·x − 2·rx²·y + ry²
7. Region 2 initialization:
	- p2 = ry²(x + 0.5)² + rx²(y − 1)² − rx²·ry²
8. While y ≥ 0:
	- Plot the symmetric points (±x + xc, ±y + yc)
	- If p2 > 0:
		- y = y − 1
		- p2 = p2 − 2·rx²·y + rx²
	Else:
	- x = x + 1
	- y = y − 1
	- p2 = p2 + 2·ry²·x − 2·rx²·y + rx²
9. Display the output until a key is pressed
10. Close graphics mode
11. Stop

---

### 🦾 Advantages
- Efficient and fast
- Uses incremental calculations
- Accurate ellipse generation
- Exploits symmetry

---

### 🚩 Disadvantages
- Slightly complex compared to circle algorithm
- Uses floating-point calculations (for decision parameters)

---

## 📘 Boundary Fill Algorithm

### 🔍 Overview

The Boundary Fill Algorithm is an area-filling algorithm used in computer graphics to fill a closed region with a specified color, starting from a given seed point inside the region.

#### 🗝️ Key idea

The algorithm:
- Starts filling from a seed point
- Continues filling neighboring pixels
- Stops when a boundary color is encountered

It is commonly used to fill regions bounded by a single-colored boundary.

---

### 🧠 Algorithm
1. Start
2. Read the top-left corner (x1, y1) of the rectangle
3. Read the bottom-right corner (x2, y2) of the rectangle
4. Read the seed point (x, y) inside the region
5. Initialize the graphics mode
6. Draw the boundary of the region using the rectangle function
7. Call boundaryFill(x, y, fillColor, boundaryColor)
8. In the boundary fill function:
	- a. Get the color of the current pixel
	- b. If the current color is not equal to the boundary color and not equal to the fill color:
		- Fill the current pixel with fill color
		- Recursively call boundary fill for:
			- (x+1, y)
			- (x−1, y)
			- (x, y+1)
			- (x, y−1)
9. Continue until all pixels inside the boundary are filled
10. Display the output until a key is pressed
11. Close graphics mode
12. Stop

---

### 🦾 Advantages
- Simple and easy to implement
- Works well for closed regions
- Can fill complex shapes
- Suitable for recursive implementation

---

### 🚩 Disadvantages
- Stack overflow may occur for large regions
- Requires a continuous boundary
- Slower compared to scan-line fill

---

## 📘 Flood Fill Algorithm

### 🔍 Overview

The Flood Fill Algorithm is an area filling algorithm used in computer graphics to replace a given color inside a closed region with a new color, starting from a seed point.

#### 🗝️ Key idea

Flood fill:
- Starts from a seed pixel
- Replaces all connected pixels having the same old color
- Continues until pixels of a different color are encountered

It is widely used in applications such as the paint bucket tool in drawing software.

---

### 🧠 Algorithm
1. Start
2. Read the top-left corner (x1, y1) of the rectangle
3. Read the bottom-right corner (x2, y2) of the rectangle
4. Read the seed point (x, y) inside the region
5. Initialize the graphics mode
6. Draw the boundary of the region using the rectangle function
7. Get the color of the seed pixel and store it as oldColor
8. Call floodFill(x, y, oldColor, newColor)
9. In the flood fill function:
	- a. Get the color of the current pixel
	- b. If the current color is equal to oldColor and not equal to newColor:
		- Fill the pixel with newColor
		- Recursively call flood fill for:
			- (x+1, y)
			- (x−1, y)
			- (x, y+1)
			- (x, y−1)
10. Continue until all connected pixels of the old color are filled
11. Display the output until a key is pressed
12. Close graphics mode
13. Stop

---

### 🦾 Advantages
- Easy to implement
- Works well for uniform color regions
- Useful for color replacement
- Widely used in graphics editors

---

### 🚩 Disadvantages
- Stack overflow for large areas
- Slower for complex regions
- Requires uniform region color

---

## 📘 2D Geometric Transformations

### 🔍 Overview

2D Geometric Transformations are fundamental operations in computer graphics used to modify the position, orientation, or size of objects in a 2D plane.

This program demonstrates three core transformations applied to a **triangle**:
- **Translation** — moving the shape
- **Rotation** — rotating the shape around a point
- **Scaling** — resizing the shape

Each transformation draws the **original triangle in white** and the **transformed triangle in a different color** for visual comparison.

---

### 📘 Translation

#### 🔍 Overview

Translation moves every point of an object by a fixed distance in the x and y directions. It does not change the shape or orientation of the object.

##### 🗝️ Key idea

Each point (x, y) of the object is shifted to a new position by adding translation factors (tx, ty):

```
x' = x + tx
y' = y + ty
```

---

#### 🧠 Algorithm

1. Start
2. Read the three vertices of the triangle: (x1, y1), (x2, y2), (x3, y3)
3. Initialize the graphics mode
4. Draw the original triangle in white
5. Read the translation factors: tx, ty
6. Calculate the new coordinates:
   - x1' = x1 + tx, y1' = y1 + ty
   - x2' = x2 + tx, y2' = y2 + ty
   - x3' = x3 + tx, y3' = y3 + ty
7. Draw the translated triangle in **red**
8. Display the output until a key is pressed
9. Close graphics mode
10. Stop

---

#### 🦾 Advantages

- Simplest of all transformations
- Uses only addition — very fast
- Preserves the shape and size of the object

---

#### 🚩 Disadvantages

- Does not rotate or scale the object
- Cannot be used to center an object at the origin directly

---

### 📘 Rotation

#### 🔍 Overview

Rotation moves every point of an object around a fixed rotation point (pivot) by a specified angle. The shape and size of the object remain unchanged.

##### 🗝️ Key idea

Each point (x, y) is rotated about a center point (cx, cy) by an angle θ using the rotation formulas:

```
x' = cx + (x - cx) * cos(θ) - (y - cy) * sin(θ)
y' = cy + (x - cx) * sin(θ) + (y - cy) * cos(θ)
```

The angle is converted from degrees to radians before applying the formula.

---

#### 🧠 Algorithm

1. Start
2. Read the three vertices of the triangle: (x1, y1), (x2, y2), (x3, y3)
3. Initialize the graphics mode
4. Draw the original triangle in white
5. Read the rotation angle in degrees and the rotation point (cx, cy)
6. Convert the angle to radians:
   - rad = angle × (π / 180)
7. Calculate the new coordinates for each vertex using the rotation formula
8. Draw the rotated triangle in **green**
9. Display the output until a key is pressed
10. Close graphics mode
11. Stop

---

#### 🦾 Advantages

- Rotates object about any arbitrary point
- Preserves shape and size of the object
- Fundamental operation in animation and graphics

---

#### 🚩 Disadvantages

- Uses floating-point trigonometric calculations (slower)
- Accumulated rounding errors for repeated rotations
- Requires conversion of degrees to radians

---

### 📘 Scaling

#### 🔍 Overview

Scaling changes the size of an object by multiplying each coordinate by a scaling factor. It can enlarge or shrink an object along the x and/or y axis independently.

##### 🗝️ Key idea

Each point (x, y) is scaled by factors sx and sy:

```
x' = x * sx
y' = y * sy
```

If sx = sy, it is **uniform scaling**. If sx ≠ sy, it is **differential scaling**.

---

#### 🧠 Algorithm

1. Start
2. Read the three vertices of the triangle: (x1, y1), (x2, y2), (x3, y3)
3. Initialize the graphics mode
4. Draw the original triangle in white
5. Read the scaling factors: sx, sy
6. Calculate the new coordinates:
   - x1' = x1 × sx, y1' = y1 × sy
   - x2' = x2 × sx, y2' = y2 × sy
   - x3' = x3 × sx, y3' = y3 × sy
7. Draw the scaled triangle in **yellow**
8. Display the output until a key is pressed
9. Close graphics mode
10. Stop

---

#### 🦾 Advantages

- Simple multiplication-based transformation
- Can scale independently along x and y axes
- Useful for zoom in/out effects

---

#### 🚩 Disadvantages

- Scaling about the origin may shift the object's position
- Non-uniform scaling distorts the shape
- Requires a fixed reference point for accurate results

---

### 📊 Comparison Table

| Feature             | Translation     | Rotation              | Scaling             |
|---------------------|-----------------|-----------------------|---------------------|
| Operation           | Addition        | Trigonometry          | Multiplication      |
| Shape preserved     | ✅ Yes          | ✅ Yes                | ⚠️ Only if uniform  |
| Size preserved      | ✅ Yes          | ✅ Yes                | ❌ No               |
| Angle preserved     | ✅ Yes          | ✅ Yes                | ⚠️ Only if uniform  |
| Output color        | 🔴 Red          | 🟢 Green              | 🟡 Yellow           |
| Parameters needed   | tx, ty          | angle, cx, cy         | sx, sy              |

---

## 📘 Painter's Algorithm

### 🔍 Overview

The Painter's Algorithm is a hidden surface removal technique used in computer graphics to handle the visibility of overlapping objects in a 3D scene rendered on a 2D screen.

It gets its name from the way a painter works — painting the background first and then layering objects from farthest to nearest on top of each other.

##### 🗝️ Key idea

The algorithm:
- Assigns a **depth value** to each object (higher depth = farther from viewer)
- **Sorts** all objects from farthest to nearest based on their depth
- **Draws** objects in that order so closer objects naturally paint over farther ones

This program demonstrates the algorithm using filled rectangles, where each rectangle has coordinates, a depth value, and a color.

---

### 🧠 Algorithm

1. Start
2. Read the number of rectangles: n
3. For each rectangle i from 0 to n−1:
   - Read the coordinates (x1, y1, x2, y2)
   - Read the depth value
   - Assign a color based on index
4. Sort the rectangles from farthest to nearest using depth:
   - For each pair (i, j), if obj[i].depth < obj[j].depth, swap them
   - (Higher depth value = farther from viewer = drawn first)
5. Initialize the graphics mode
6. For each rectangle in sorted order (back to front):
   - Set the fill style and color
   - Draw the filled rectangle using `bar()`
   - Add a small delay for visualization
7. Display the output until a key is pressed
8. Close graphics mode
9. Stop

---

### 🦾 Advantages

- Simple and easy to implement
- Works well for non-overlapping or partially overlapping objects
- No complex geometric calculations required
- Good for educational and introductory purposes in 3D graphics

---

### 🚩 Disadvantages

- Fails for **cyclically overlapping** objects (e.g., three objects each partially in front of the other)
- Sorting overhead increases with number of objects
- Does not handle **interpenetrating** objects correctly
- Not suitable for real-time complex 3D rendering

---

## Final Note

Computer Graphics is where **mathematics meets creativity** and **logic turns into visuals**.  
Every algorithm implemented here represents a step toward understanding how pixels become meaningful images.

Keep experimenting, keep learning, and keep building.  
**Strong fundamentals create powerful visuals.** 🚀  

Happy Coding! 🎨💻

---