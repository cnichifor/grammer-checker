# Grammer-Checker

A simple C++ tool that loads an English word list into a custom hash-table and checks each word in a hard‑coded sentence for existence.

---

## Project Structure

* **has.h** — Declarations for the `Dictionary` struct, `getIdx`, `newDictionary`, and `isCorrect`.
* **has.cpp** — Implements loading `words.data`, the djb2a hash function with chaining, performance stats (`showPerformance`), and lookup logic.
* **main.cpp** — Builds the dictionary, shows performance metrics, and tests a hard‑coded sentence.
* **words.data** — Plain text file with one English word per line.
* **README.md** — This file.

---

## Requirements

* A C++17‑compatible compiler (e.g. `g++`, `clang++`)
* No external dependencies

---

## Build

Compile the project with:

```bash
g++ -std=c++17 -O2 has.cpp main.cpp -o grammer_checker
```

This will produce the `grammer_checker` executable in the current directory.

---

## Usage

Run the tool without any arguments (it uses `words.data` from the working directory and a hard‑coded test sentence):

```bash
./grammer_checker
```

Sample output:

```
Loaded 100000 words.
Load factor: 0.19
Empty buckets: 20000
Max chain length: 5

Checking: "Hello world!"
All words are valid.

Checking: "Thiss is mispelled."
Missing words:
 - Thiss
 - mispelled
```

---

## Next Steps & Extensions

* **Punctuation stripping:** Use a regex pass to remove non-letter characters before lookup.
* **Command‑line input:** Add `argc/argv` parsing to supply custom sentences or files.
* **Suggestions:** Implement a Levenshtein distance or BK-tree to propose close matches for missing words.
* **Memory safety:** Integrate smart pointers (`std::unique_ptr`) and clean up nodes on exit.
* **Unit tests:** Add Google Test or Catch2 for automated verification of loading and lookup.

---

## License

This project is licensed under the MIT License — see `LICENSE` if included, or add one if not.
