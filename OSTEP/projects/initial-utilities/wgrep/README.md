# wgrep

## Core Tools Used

### `strstr()`
I initially implemented my own search function, but replaced it with `strstr()` for better performance and reliability.

### `getline()`
This was a great exercise in **Pointer Management**. Using `getline()` allow me to:
- Handle lines of any length dynamically.
- Manage memory manually (remember to `free()` the buffer).
- Refresh my understanding of passing pointers by reference (`&lineptr`).



### Program Design
The logic is decomposed into three layers:

| Component | Responsibility |
| :--- | :--- |
| **`main`** | Handles CLI arguments, opens/closes files, and manage `stdin`. |
| **`helper_file_search`** | Iterate through a file line-by-line using `getline()`. |
| **`helper_search`** | A wrapper for `strstr()` that isolates the matching logic. |

---

**Note:** Always ensure the allocated memory is freed!
