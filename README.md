# Ex4‑Container

A generic C++ container class supporting multiple traversal orders via custom iterators.

## 🚀 Features

- **Dynamic array** backing, automatically expands.
- Supports **comparable types** (`operator<`, `operator>`, `operator==`).
- Multiple iterator orders:
  - **Ascending** (`begin_ascending_order()` / `end_ascending_order()`)
  - **Descending** (`begin_descending_order()` / `end_descending_order()`)
  - **Side‑Cross** (`begin_side_cross_order()` / `end_side_cross_order()`)  
    *(smallest, largest, 2nd-smallest, 2nd-largest, …)*
  - **Reverse** (from end to start)
  - **Natural Insertion Order**
  - **Middle‑Out** (center, left, right, …)
- Streaming support: `operator<<` prints the container in `[a, b, c]` format.
- `removeElement(x)` removes all occurrences of `x` (throws if none found).

## 🛠 Usage

### Clone & build

```bash
git clone https://github.com/yoavnach/Ex4-Contianer.git
cd Ex4-Contianer
make          # builds `program` and `test`
```

### API Overview (`MyContainer.hpp`)

```cpp
MyContainer<int> c;
c.addElement(7);
c.addElement(2);
c.addElement(15);

// size
int n = c.size();  // 3

// print
std::cout << c;   // [7, 2, 15]

// ascending
for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
    std::cout << *it << ' ';
}
// prints: 2 7 15

// descending
for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
    std::cout << *it << ' ';
}
// prints: 15 7 2

// side‑cross
for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
    std::cout << *it << ' ';
}
// prints: 2 15 7
```

### Testing

A `doctest`‑based test suite is included (`tests.cpp`).  
To run:

```bash
make test
```

## 🎯 Design Highlights

- All iterator classes are **nested templates** inside `MyContainer<T>`, sharing access to the raw `data` array.
- Iterators maintain an `order[]` index buffer to avoid mutating the container.
- Clean single-header implementation: all generic/template code lives in `MyContainer.hpp`.

## ✅ To Do / Improvements

- **Replace raw `new[]`/`delete[]`** with `std::vector<int>` for exception safety and clarity.
- Consider implementing **bidirectional iterators** (`operator--`, etc.).
- Add support for C++20 **concepts** (e.g. `std::totally_ordered`) to enforce comparable types.
- (Optional) Add `const_iterator` overloads and `operator==`.

## 📚 License

This project is available under the MIT License, but you're welcome to tailor it for coursework or personal use.