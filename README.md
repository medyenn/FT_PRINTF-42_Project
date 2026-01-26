*This project has been created as part of the 42 curriculum by Mohamed ENNIH.*

# 🖨️ ft_printf — Reimplementation of the C Standard Output Formatter

# Description

**ft_printf** is a systems-level programming project that consists of recreating the standard C `printf()` function from scratch. The objective is not only to replicate its observable behavior, but also to deeply understand how **variadic functions**, **calling conventions**, and **formatted output pipelines** operate at the ABI (Application Binary Interface) and memory-layout levels.

This project builds advanced mastery in:

- **Variadic function mechanics** and runtime argument traversal
- **CPU calling conventions**, including register passing and stack spillover
- **Memory layout of function arguments**, including type promotion rules
- **Floating-point vs integer calling paths**, and why they are treated differently
- **Low-level formatted output pipelines**, without relying on libc buffering
- **Parser design**, dispatch logic, and extensible formatting architecture

Ultimately, `ft_printf` reproduces the behavior of one of the most widely used functions in C while reinforcing a deep understanding of how compilers, runtimes, and operating systems cooperate to support flexible function interfaces.

---

## 🧠 Variadic Functions: Memory Model & ABI-Level Behavior

### 🔹 How Variadic Arguments Are Passed in Memory

In C, variadic functions such as `printf(const char *fmt, ...)` accept a variable number of arguments whose types and count are unknown at compile time. Their handling depends on the **platform ABI** (e.g., System V AMD64 ABI on Linux/macOS x86_64), but follows a consistent conceptual pipeline:

1. **Register Passing (Fast Path)**  
   - The first arguments are passed via CPU registers:
     - Integer and pointer types → general-purpose registers
     - Floating-point types → SIMD/FPU registers (e.g., XMM registers)

2. **Register Save Area**  
   - When a variadic function is entered, the compiler copies the argument registers into a memory region known as the **register save area** so they can be accessed sequentially by the variadic mechanism.

3. **Overflow Argument Area**
   - Once register slots are exhausted, additional arguments are passed via the **stack** and accessed through the **overflow save area**.

4. **Stack Memory**
   - The stack ultimately serves as the fallback storage when argument registers are depleted, maintaining alignment and calling convention guarantees.

---

### 🔹 Why Floating-Point Types Are Treated Differently

Floating-point values (`float`, `double`) are passed through **floating-point registers**, not integer registers. However:

- In variadic functions, **default argument promotions** apply:
  - `float` → promoted to `double`
  - `char` / `short` → promoted to `int`

This means:
- The callee always retrieves floating-point arguments as `double`
- The ABI separates integer and floating-point argument streams
- The variadic mechanism must track **two independent register classes**

This dual-register model is why variadic handling is significantly more complex than fixed-arity function calls.

---

## 🧬 `va_list` Internals & Variadic Macros

The `va_list` type is an opaque structure that internally stores:

- A pointer to the **current argument position**
- Offsets into:
  - The **general-purpose register save area**
  - The **floating-point register save area**
  - The **overflow argument area**

Although implementation-dependent, it conceptually tracks where the *next unread argument* resides.

---

### 🔹 `va_start(ap, last_param)`

Initializes the `va_list` object:
- Sets internal pointers to the first unnamed argument
- Captures the starting offsets for register and stack traversal
- Uses `last_param` to determine where fixed arguments end

---

### 🔹 `va_arg(ap, type)`

Retrieves the next argument:
- Determines whether the requested type belongs to:
  - Integer/pointer class
  - Floating-point class
- Pulls the value from:
  - Register save area (if available)
  - Overflow stack area (otherwise)
- Advances internal offsets accordingly

This macro embodies the core runtime logic of variadic traversal.

---

### 🔹 `va_copy(dest, src)`

Creates an independent copy of a `va_list`:
- Required when arguments need to be iterated multiple times
- Ensures both lists maintain independent traversal states

---

### 🔹 `va_end(ap)`

Finalizes the `va_list`:
- Invalidates internal state
- Required for correctness and portability, even if it performs no operation on some platforms

---

## 🖨️ printf as a Case Study in Variadic Function Design

`printf()` is one of the most widely used variadic functions in systems programming. Reimplementing it provides mastery over:

- **Parsing runtime type descriptors** embedded in format strings
- **Dynamic type dispatch** using `va_arg`
- **Integer formatting**, base conversion, and sign handling
- **Pointer encoding**, including hexadecimal formatting
- **Character and string output**
- **Output count tracking**, required for correct return values

In `ft_printf`, the implementation reproduces these behaviors independently, without relying on libc buffering, reinforcing understanding of both formatting logic and I/O system calls.

---

## 🧩 Algorithm & Data Structure Design

### 🔹 Parsing Algorithm

The format string is processed using a **single-pass linear parser**:

1. Iterate over each character in the format string
2. On `%`, enter a conversion state
3. Parse the specifier (`cspdiuxX%`)
4. Dispatch to the corresponding handler function
5. Retrieve the correct argument using `va_arg`
6. Convert it to its textual representation
7. Write output directly using `write()`

This yields:

- **Time Complexity:** O(n), where n is format string length
- **Space Complexity:** O(1) auxiliary memory (excluding output buffers)

---

### 🔹 Dispatcher Architecture

Each conversion specifier is mapped to a dedicated formatting function:


 `%c`        :  Character output 
 `%s`        :  String output 
 `%p`        :  Pointer hexadecimal formatting 
 `%d` / `%i` :  Signed decimal integer formatting 
 `%u`        :  Unsigned decimal integer formatting 
 `%x` / `%X` :  Hexadecimal conversion 
 `%%`        :  Literal percent output 

This **function-dispatch table** design:

- Improves modularity
- Simplifies extension (bonus flags, width, precision)
- Separates parsing from formatting logic

---

### 🔹 Data Structures Used

- **No heap-heavy containers** are required
- Formatting is performed using:
  - Stack-local buffers
  - Recursive digit emission
  - Iterative base conversion

This design minimizes memory usage while preserving correctness and extensibility.

---

# ⚙️ Instructions

### 📌 Compilation

```bash
make
```
### 🧹 Cleanup 
make clean    : Removes object files
make fclean   : Removes object files and libftprintf.a
make re       : Rebuilds everything


# 📚 Resources

📖 Technical Documentation

ISO C Standard (C99/C11) — Variadic Functions

System V AMD64 ABI Specification

man 3 printf

man 3 stdarg

GNU libc manual — Variadic Functions

Computer Systems: A Programmer’s Perspective — Bryant & O’Hallaron