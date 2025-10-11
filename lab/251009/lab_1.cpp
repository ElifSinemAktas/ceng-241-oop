// CENG241 - Dynamic Inventory (C++ version with new/delete[])
// -----------------------------------------------------------
// This is a faithful C++ implementation of the lab requirements,
// using *C++-style* dynamic memory management (new/delete[]) instead
// of C's malloc/free. The code is heavily commented so you can learn
// pointers, arrays, and memory management as you go.
//
// Why not std::vector?
// --------------------
// In real C++ projects, you'd prefer std::vector<int> which manages
// memory automatically. But this lab aims to teach the low-level
// concepts: raw pointers, dynamic arrays, and manual resizing.
//
// Key ideas you'll see here:
// - `int* data` holds the *address* of the first element of a dynamic array.
// - `new int[N]` allocates space for N integers. `delete[]` frees it.
// - We track `size` (used slots) and `capacity` (allocated slots).
// - When we need more space, we allocate a bigger array and copy.
//
// Build & Run (example):
// ----------------------
// g++ -std=c++17 -O2 -Wall -Wextra -pedantic inventory.cpp -o inventory
// ./inventory
//
// Author: ChatGPT (C++ rewrite of the lab with explanations)

#include <iostream>
#include <limits>    // for std::numeric_limits
#include <algorithm> // for std::sort, std::swap
#include <iomanip>   // for std::setprecision

struct Inventory {
    int* data;     // pointer to the first element of a dynamic int array
    int  size;     // how many elements are actually used
    int  capacity; // how many elements are allocated
};

// Utility: safely read an integer from std::cin with prompt
int read_int(const char* prompt) {
    int x;
    while (true) {
        std::cout << prompt;
        if (std::cin >> x) return x;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer.\n";
    }
}

// 1) create: allocate array with given initial capacity, set size=0
bool create(Inventory& inv, int initial_capacity) {
    if (initial_capacity <= 0) {
        std::cout << "Initial capacity must be positive.\n";
        inv.data = nullptr;
        inv.size = 0;
        inv.capacity = 0;
        return false;
    }
    // new int[initial_capacity] allocates space for 'initial_capacity' integers.
    inv.data = new (std::nothrow) int[initial_capacity];
    if (!inv.data) {
        std::cout << "Memory allocation failed!\n";
        inv.size = 0;
        inv.capacity = 0;
        return false;
    }
    inv.size = 0;
    inv.capacity = initial_capacity;
    return true;
}

// 2) destroy: free allocated memory and reset members
void destroy(Inventory& inv) {
    // delete[] must match new[]
    delete[] inv.data;
    inv.data = nullptr;
    inv.size = 0;
    inv.capacity = 0;
}

// 3) reserve: pre-allocate capacity (can grow or shrink)
bool reserve(Inventory& inv, int new_capacity) {
    if (new_capacity < 0) {
        std::cout << "New capacity cannot be negative.\n";
        return false;
    }
    if (new_capacity == inv.capacity) {
        return true; // nothing to do
    }
    if (new_capacity == 0) {
        // Free everything
        destroy(inv);
        return true;
    }

    int* new_data = new (std::nothrow) int[new_capacity];
    if (!new_data) {
        std::cout << "Memory reallocation failed!\n";
        return false;
    }
    // Copy as many elements as will fit
    int elements_to_copy = (inv.size < new_capacity) ? inv.size : new_capacity;
    for (int i = 0; i < elements_to_copy; ++i) {
        new_data[i] = inv.data[i];
    }
    delete[] inv.data;
    inv.data = new_data;
    inv.capacity = new_capacity;
    // If we shrank below current size, adjust size
    if (inv.size > new_capacity) {
        inv.size = new_capacity;
    }
    return true;
}

// Internal helper: grow capacity (e.g., double) when full
bool ensure_capacity_for_one_more(Inventory& inv) {
    if (inv.size < inv.capacity) return true;
    int new_capacity = (inv.capacity == 0) ? 1 : inv.capacity * 2;
    return reserve(inv, new_capacity);
}

// 4) append: add item to the end (grow if needed)
bool append(Inventory& inv, int stock) {
    if (!ensure_capacity_for_one_more(inv)) {
        return false;
    }
    inv.data[inv.size++] = stock;
    return true;
}

// 5) insert_at: insert item at index, shift right
bool insert_at(Inventory& inv, int index, int stock) {
    if (index < 0 || index > inv.size) {
        std::cout << "Index out of bounds.\n";
        return false;
    }
    if (!ensure_capacity_for_one_more(inv)) {
        return false;
    }
    // Shift elements [index..size-1] one position to the right
    for (int i = inv.size - 1; i >= index; --i) {
        inv.data[i + 1] = inv.data[i];
    }
    inv.data[index] = stock;
    ++inv.size;
    return true;
}

// 6) delete_at: remove item at index, shift left
bool delete_at(Inventory& inv, int index) {
    if (index < 0 || index >= inv.size) {
        std::cout << "Index out of bounds.\n";
        return false;
    }
    // Shift elements [index+1..size-1] left by one
    for (int i = index + 1; i < inv.size; ++i) {
        inv.data[i - 1] = inv.data[i];
    }
    --inv.size;
    return true;
}

// 7) find: return first index whose value == target, else -1
int find(const Inventory& inv, int target) {
    for (int i = 0; i < inv.size; ++i) {
        if (inv.data[i] == target) return i;
    }
    return -1;
}

// 8) print: dump list with size/capacity
void print_inventory(const Inventory& inv) {
    std::cout << "📦 Stock List (size = " << inv.size
              << " / capacity = " << inv.capacity << "):\n[";
    for (int i = 0; i < inv.size; ++i) {
        std::cout << inv.data[i];
        if (i + 1 < inv.size) std::cout << ", ";
    }
    std::cout << "]\n";
}

// 9) sort_asc: sort from low to high
void sort_asc(Inventory& inv) {
    std::sort(inv.data, inv.data + inv.size);
}

// 10) reverse: in-place reversal
void reverse(Inventory& inv) {
    int i = 0, j = inv.size - 1;
    while (i < j) {
        std::swap(inv.data[i], inv.data[j]);
        ++i;
        --j;
    }
}

// 11) stats: compute min, max, average; return false if empty
bool stats(const Inventory& inv, int& out_min, int& out_max, double& out_avg) {
    if (inv.size == 0) return false;
    int mn = inv.data[0];
    int mx = inv.data[0];
    long long sum = 0; // use wider type to avoid overflow on large arrays
    for (int i = 0; i < inv.size; ++i) {
        if (inv.data[i] < mn) mn = inv.data[i];
        if (inv.data[i] > mx) mx = inv.data[i];
        sum += inv.data[i];
    }
    out_min = mn;
    out_max = mx;
    out_avg = static_cast<double>(sum) / inv.size;
    return true;
}

// 12) show_size_capacity: prints current size/capacity
void show_size_capacity(const Inventory& inv) {
    std::cout << "Size: " << inv.size << ", Capacity: " << inv.capacity << "\n";
}

// 13) print_menu: list the actions
void print_menu() {
    std::cout << "---------------------------------------------------\n";
    std::cout << "1) Create new stock ledger\n";
    std::cout << "2) Add (append) a new product’s stock\n";
    std::cout << "3) Insert product stock at specific position\n";
    std::cout << "4) Remove a product from inventory\n";
    std::cout << "5) Find product by stock quantity\n";
    std::cout << "6) Show current number of products and total capacity\n";
    std::cout << "7) Reverse product list\n";
    std::cout << "8) Display inventory statistics (min / max / average stock)\n";
    std::cout << "9) Adjust reserved capacity\n";
    std::cout << "10) Show all products’ stock values\n";
    std::cout << "11) Sort inventory (ascending by stock)\n";
    std::cout << "0) Exit\n";
    std::cout << "---------------------------------------------------\n";
}

int main() {
    std::cout << "=== Welcome to the Dynamic Stock Ledger System (C++ version) ===\n";
    std::cout << "Manage your store’s product stock easily through the options below.\n";

    Inventory inv{nullptr, 0, 0};
    bool running = true;
    while (running) {
        print_menu();
        int choice = read_int("Enter your choice: ");

        switch (choice) {
            case 1: {
                int cap = read_int("Enter initial stock capacity (number of products to prepare space for): ");
                if (inv.data != nullptr) {
                    std::cout << "Re-initializing: existing inventory will be destroyed.\n";
                    destroy(inv);
                }
                if (create(inv, cap)) {
                    std::cout << u8"✅ New inventory ledger created successfully!\n";
                }
                break;
            }
            case 2: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                int v = read_int("Enter stock quantity for the new product: ");
                if (append(inv, v)) {
                    std::cout << u8"✅ Product added successfully.\n";
                }
                break;
            }
            case 3: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                int idx = read_int("Enter position to insert the new product (0-based index): ");
                int v = read_int("Enter stock quantity for the product: ");
                if (insert_at(inv, idx, v)) {
                    std::cout << u8"✅ Product inserted successfully.\n";
                }
                break;
            }
            case 4: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                int idx = read_int("Enter index of product to remove: ");
                if (delete_at(inv, idx)) {
                    std::cout << u8"✅ Product removed successfully.\n";
                }
                break;
            }
            case 5: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                int v = read_int("Enter stock quantity to search for: ");
                int pos = find(inv, v);
                if (pos >= 0) std::cout << "📦 Found product at index: " << pos << "\n";
                else std::cout << "Not found.\n";
                break;
            }
            case 6: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                show_size_capacity(inv);
                break;
            }
            case 7: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                std::cout << "Reversing product order...\n";
                reverse(inv);
                std::cout << u8"✅ Stock list reversed.\n";
                break;
            }
            case 8: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                int mn, mx;
                double avg;
                if (stats(inv, mn, mx, avg)) {
                    std::cout << "📦 Inventory Statistics:\n";
                    std::cout << "Minimum stock = " << mn << "\n";
                    std::cout << "Maximum stock = " << mx << "\n";
                    std::cout << "Average stock = " << std::fixed << std::setprecision(2) << avg << "\n";
                } else {
                    std::cout << "Inventory is empty.\n";
                }
                break;
            }
            case 9: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                int new_cap = read_int("Enter new capacity to reserve: ");
                if (reserve(inv, new_cap)) {
                    std::cout << u8"✅ Inventory capacity updated to " << inv.capacity << ".\n";
                }
                break;
            }
            case 10: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                print_inventory(inv);
                break;
            }
            case 11: {
                if (!inv.data) {
                    std::cout << "Please create the inventory first (option 1).\n";
                    break;
                }
                std::cout << "Sorting inventory from lowest to highest stock...\n";
                sort_asc(inv);
                std::cout << u8"✅ Inventory sorted successfully.\n";
                break;
            }
            case 0: {
                running = false;
                break;
            }
            default:
                std::cout << "Unknown choice.\n";
        }
    }

    destroy(inv); // Always free memory before exiting

    std::cout << "Goodbye!\n";
    return 0;
}
