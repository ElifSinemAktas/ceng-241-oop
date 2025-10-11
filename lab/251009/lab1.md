# CENG 241 — Lab Exercises 1

## Overview
This program defines a single structure that represents the store’s **dynamic stock list**.  
It holds a **1-dimensional dynamic array** for storing product stock quantities, along with two numbers — **size** and **capacity** — that describe how much of the array is used and how much memory is available.

### Structure Fields
- **int *data;** — Pointer to a 1D dynamic integer array storing stock quantities.  
  Each element represents the number of units available for a specific product.

- **int size;** — Current number of products (number of elements actually used).

- **int capacity;** — Total number of elements the array can hold before more memory must be allocated.

Together, these fields enable the program to store, expand, and manage product stock dynamically during execution.

---

## Functions to Implement

### 1. `create`
- Initializes an empty inventory with a given initial capacity.  
- Receives: initial capacity and a reference to the inventory.  
- Returns: success/failure.  
- Allocates memory and sets `size = 0` so the array is ready to store stock counts.

### 2. `destroy`
- Safely closes the inventory.  
- Receives: a reference to the inventory.  
- Returns: nothing.  
- Frees all allocated memory and nulls pointers to prevent memory leaks.

### 3. `reserve`
- Pre-allocates shelf space for more products.  
- Receives: new capacity and the inventory.  
- Returns: success/failure.  
- Uses reallocation to increase capacity without altering the current product count.

### 4. `append`
- Adds a new product’s stock count at the end.  
- Receives: inventory and integer stock quantity.  
- Returns: success/failure.  
- Grows capacity automatically if needed and increments product count.

### 5. `insert_at`
- Inserts a new product at a specific position.  
- Receives: inventory, target index, and stock quantity.  
- Returns: success/failure.  
- Shifts later items to the right to maintain order and increases size by one.

### 6. `delete_at`
- Removes a product from a given position.  
- Receives: inventory and index.  
- Returns: success/failure.  
- Shifts remaining items left and decreases size.

### 7. `find`
- Locates the first product whose stock equals a target value.  
- Receives: inventory and target integer.  
- Returns: index of first match or `-1` if not found.  
- Performs a linear search.

### 8. `print`
- Shows a snapshot of the inventory.  
- Receives: inventory.  
- Returns: nothing.  
- Prints stock quantities, current size, and capacity.

### 9. `sort_asc`
- Orders products from lowest to highest stock.  
- Receives: inventory.  
- Returns: nothing.  
- Sorts the array to highlight low-stock items for replenishment.

### 10. `reverse`
- Flips the order of products.  
- Receives: inventory.  
- Returns: nothing.  
- Performs an in-place reversal to get a high-to-low view after sorting.

### 11. `stats`
- Computes quick KPIs over stock levels.  
- Receives: inventory and output holders for min, max, and average.  
- Returns: success/failure (fails if empty).  
- Reports the lowest, highest, and mean stock.

### 12. `show_size_capacity`
- Reports inventory health.  
- Receives: inventory.  
- Returns: nothing.  
- Prints the number of products tracked and total capacity.

### 13. `print_menu`
- Displays the operator menu.  
- Receives: nothing.  
- Returns: nothing.  
- Lists available actions for the menu-driven interface.

---

## 🧩 Sample Run

```
=== Welcome to the Dynamic Stock Ledger System ===
Manage your store’s product stock easily through the options below.
---------------------------------------------------
1) Create new stock ledger
2) Add (append) a new product’s stock
3) Insert product stock at specific position
4) Remove a product from inventory
5) Find product by stock quantity
6) Show current number of products and total capacity
7) Reverse product list
8) Display inventory statistics (min / max / average stock)
9) Adjust reserved capacity
10) Show all products’ stock values
11) Sort inventory (ascending by stock)
0) Exit
---------------------------------------------------
Enter your choice: 1
Enter initial stock capacity (number of products to prepare space for): 4
✅ New inventory ledger created successfully!

Enter your choice: 2
Enter stock quantity for the new product: 25
✅ Product added successfully.

Enter your choice: 2
Enter stock quantity for the new product: 12
✅ Product added successfully.

Enter your choice: 2
Enter stock quantity for the new product: 40
✅ Product added successfully.

Enter your choice: 2
Enter stock quantity for the new product: 18
✅ Product added successfully.

Enter your choice: 10
📦 Current Stock List (size = 4 / capacity = 4):
[25, 12, 40, 18]

Enter your choice: 3
Enter position to insert the new product (0-based index): 1
Enter stock quantity for the product: 99
✅ Product inserted successfully.

Enter your choice: 10
📦 Updated Stock List (size = 5 / capacity = 8):
[25, 99, 12, 40, 18]

Enter your choice: 5
Enter stock quantity to search for: 40
📦 Found product at index: 3

Enter your choice: 8
📦 Inventory Statistics:
Minimum stock = 12
Maximum stock = 99
Average stock = 38.8

Enter your choice: 11
Sorting inventory from lowest to highest stock...
✅ Inventory sorted successfully.

Enter your choice: 10
📦 Sorted Stock List:
[12, 18, 25, 40, 99]

Enter your choice: 7
Reversing product order...
✅ Stock list reversed.

Enter your choice: 10
📦 Reversed Stock List:
[99, 40, 25, 18, 12]

Enter your choice: 4
Enter index of product to remove: 2
✅ Product removed successfully.

Enter your choice: 10
📦 Updated Stock List:
[99, 40, 18, 12]

Enter your choice: 9
Enter new capacity to reserve: 16
✅ Inventory capacity updated to 16.
```