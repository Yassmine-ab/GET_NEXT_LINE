*This activity has been created as part of the 42 curriculum by yaabdall.*

# get_next_line

## Description

`get_next_line` is a 42 C project where the goal is to implement a function that reads from a file descriptor and returns one line at a time.

The function must:
- Return the next line, including the trailing `\n` when present.
- Keep internal state between calls so reading continues exactly where the previous call stopped.
- Return `NULL` on EOF (when nothing remains) or on error.

This project focuses on low-level I/O (`read`), dynamic memory management, and robust edge-case handling.

## Instructions

### Requirements

- C compiler (`cc`/`gcc`)
- Unix-like environment (Linux/macOS)

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

Note: this repository does not provide a required `main.c` for evaluation. The compile lines above assume you use your own local test `main.c`.

## Algorithm: Detailed Explanation and Justification

### Selected approach

The implementation uses a **static remainder buffer**:
- After each `read`, data is appended to `remainder`.
- When a full line is available, the function extracts that line.
- The leftover data after that line is stored back into `remainder` for the next call.

### Why this algorithm

This is the standard and most reliable design for `get_next_line` because:
- `read` returns arbitrary chunk sizes, not line-sized chunks.
- A line can span multiple reads.
- A read can contain multiple lines; extra bytes must be preserved for future calls.

A persistent buffer between calls is therefore mandatory for correctness.

### Step-by-step behavior

1. Validate input (`fd >= 0`, `BUFFER_SIZE > 0`).
2. Allocate a temporary read buffer of size `BUFFER_SIZE + 1`.
3. While `remainder` does not contain `\n` and `read` still returns bytes:
- Read into temporary buffer.
- Null-terminate the chunk.
- Concatenate chunk to `remainder`.
4. If `remainder` is empty after reading, return `NULL`.
5. Extract one line from `remainder`:
- Copy chars up to `\n` (included when present).
- Build the returned line.
6. Duplicate the part after the extracted line into a new remainder.
7. Free temporary allocations and return the extracted line.

### Correctness notes

- Handles files with or without trailing newline.
- Handles empty files.
- Handles very long lines (across many reads).
- Keeps unread bytes for next call.
- Frees stored state on read error to avoid leaks/stale state.

### Complexity

- Time: linear in total input size read.
- Space: proportional to current stored remainder plus temporary read buffer.

This is an appropriate trade-off for line-based streaming from file descriptors.

## Technical Choices

- Custom utility functions (`ft_strlen_gnl`, `ft_strchr_gnl`, `ft_strdup`, `ft_strjoin_free`) to keep dependencies explicit and controlled.
- `ft_strjoin_free` frees previous remainder to simplify ownership and reduce leaks.
- Header-level `BUFFER_SIZE` supports easy tuning and can be overridden with `-D BUFFER_SIZE=...`.

## Resources

- 42 project subject (`en.subject.pdf`) in this repository.
- Linux `read(2)` manual: https://man7.org/linux/man-pages/man2/read.2.html
- C memory management overview: https://en.cppreference.com/w/c/memory
- Static storage duration in C: https://en.cppreference.com/w/c/language/storage_duration

### AI Usage

AI assistance (GitHub Copilot / GPT-5.3-Codex) was used for:
- README drafting and wording refinement.
- Requirement compliance check for README sections.

AI was **not used to generate or modify the C implementation logic** in this repository.
