*This activity has been created as part of the 42 curriculum by yassabda.*

# get_next_line

> This project follows the 42 Norme coding standard. Some implementation choices are intentional: no `for`, no `do...while`, no `switch`, etc.

## Description
`get_next_line` is a 42 C project where the goal is to implement a function that reads from a file descriptor and returns one line at a time.

The function must:
- Return the next line, including the trailing `\n` when present.
- Keep internal state between calls so reading continues exactly where the previous call stopped.
- Return `NULL` on EOF (when nothing remains) or on error.

This project focuses on low-level I/O (`read`), dynamic memory management, and robust edge-case handling.

## Function Prototype

```c
char *get_next_line(int fd);
```

**Parameters:**
- `fd`: The file descriptor to read from.

**Returns:**
- A dynamically allocated string containing the next line (with `\n` if present).
- `NULL` if there is nothing else to read or if an error occurred.

## Algorithm & Data Structure

The implementation uses a **static remainder buffer**:

1. **Initialization**: A static `char *remainder` persists across multiple calls to preserve unread data.

2. **Reading loop**:
   - While the remainder does not contain a newline and `read()` returns bytes:
     - Read up to `BUFFER_SIZE` bytes into a temporary buffer.
     - Append the buffer to the remainder via `ft_strjoin()`.
     - Free old remainder and update it with the concatenated result.

3. **Line extraction**:
   - Once a newline is found (or EOF reached), extract the line up to and including the `\n`.
   - Duplicate the leftover data for the next call.
   - Return the extracted line.

4. **Cleanup**:
   - Free temporary allocations.
   - Maintain the static remainder for the next invocation.

### Key Design Decisions

- **Static variable**: Ensures state persistence across function calls without global variables.
- **Temporary buffer**: Bounds memory reads to `BUFFER_SIZE`, making the function scalable with different buffer sizes.
- **String concatenation**: Uses `ft_strjoin()` to append read chunks, simplifying logic but requiring careful memory management.
- **Efficient line extraction**: The `extract_line()` helper copies only the needed characters and stores the remainder for reuse.
- **Error handling**: Returns `NULL` on `read()` failure or memory allocation failure, freeing all allocated memory to prevent leaks.

## Instructions

### Requirements
- A C compiler (`cc`)
- Standard Unix environment with `read()` syscall

### Compile

With default `BUFFER_SIZE` from `get_next_line.h`:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

With custom `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Run

```bash
./gnl
```

**Note:** This repository does not provide a required `main.c` for evaluation. The compile lines above assume you use your own local test `main.c`.

## Resources

References used for this project:
- Linux `read(2)` manual: https://man7.org/linux/man-pages/man2/read.2.html
- C memory management and dynamic allocation: https://en.cppreference.com/w/c/memory
- Static storage duration in C: https://en.cppreference.com/w/c/language/storage_duration

### AI Usage Disclosure

AI assistance was used for:
- README structure and formatting alignment with project standards.
- Documentation organization and clarity improvements.

AI was not used to generate or modify the C implementation logic in this repository.
