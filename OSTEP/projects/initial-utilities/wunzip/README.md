# wunzip

## Core Tools Use

### `fread()`
Get a block of data from file wzipped.

### `fwrite()`
Directly write to `stdout` to avoid frequently `realloc()`.

## Program Design

| Component | Responsibility |
| :--- | :--- |
| **`unzip`** | Decode and directly write to `stdout` buffer. |
| **`process_file`** | Use `fread()` to retrive data from file. |
| **`main`** | Handling files `fopen` and `fclose` |

---

**Note:** `putc` is a better option for single character!
