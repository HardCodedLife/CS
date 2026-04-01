# wzip

## Core Tools Used

### `fgetc()`
Get a character and compare it with the previous one stores in `units`.

### `realloc()`
Keep reallocating memory at `zip()` for self-define structure `Unit`. Needs double-pointer to modify the `units` correctly, rather than the copy of it.

### `fwrite()`
Learning how to deal with binary form of data. Recognizing operator `->` has higher precedence than `&` and `*`.

## Program Design

| Component | Responsibility |
| :--- | :--- |
| **`Unit`** | `struct { int n; char c; }` — The binary data model. |
| **`main`** | Iterate through `argv`; performs the *Final Flush* after the last file. |
| **`zip`** | Logic for RLE; handles `realloc` and cross-file state management |

--- 

**Note:** Multiple files need to be considered as a single file!
