## الـ README نص:
# 🏧 ATM System — Procedural vs OOP

A console-based ATM simulation built in **C++**, developed **twice** — once using **Procedural Programming**, and once refactored using **Object-Oriented Programming** — to demonstrate the real-world impact of OOP design principles on the same project.

---

## 💡 Why Two Versions?

This project was intentionally built in two stages to understand *why* OOP exists — not just *how* to write it.

| | v1 — Procedural | v2 — OOP |
|---|---|---|
| **Data Structure** | `struct StClient` in a `namespace` | `class clsClient` with encapsulation |
| **UI & Logic** | Mixed together in the same functions | Separated — dedicated Screen classes |
| **Navigation** | Recursive function calls → Stack risk | `do-while` loop → Safe & clean |
| **Code Reuse** | Duplicated file-read logic across namespaces | Single `clsClient` handles all file I/O |
| **Extensibility** | Adding a screen = editing `main.cpp` | Adding a screen = new class, nothing else changes |
| **Input Validation** | Manual `while` loops in each function | Centralized `clsInputValidate` template class |

> The same features. The same data file. Two completely different ways of thinking.

---

## 🚀 Features (Both Versions)

### 🔐 Authentication
- Login with Account Number + PIN Code
- Loops until valid credentials are entered

### 💸 Transactions
- **Quick Withdraw** — predefined amounts (20 / 50 / 100 / 200 / 400 / 600 / 800 / 1000)
- **Normal Withdraw** — custom amount, must be a multiple of 5
- **Deposit** — add funds with confirmation prompt
- **Check Balance** — view current account balance
- **Logout** — return to login screen

---

## 📁 v1 — Procedural Version

All logic lives in **one `.cpp` file** with supporting namespaces in header files.

| 📂 File | 📄 Description | |
|---|---|---|
| `Project_ATM_Course_8.cpp` | Entry point + ALL screen logic + navigation | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/Project_ATM_Course_8/Project_ATM_Course_8.cpp) |
| `Client.h` | `MyClient` namespace — `StClient` struct + file I/O | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/Project_ATM_Course_8/Client.h) |
| `Delete.h` | `MyD` namespace — Deposit, Withdraw, Delete, Save | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/Project_ATM_Course_8/Delete.h) |
| `Ubdated.h` | `Upadte` namespace — Update client logic | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/Project_ATM_Course_8/Ubdated.h) |
| `ShowClinte.h` | `MyShow` namespace — Display clients in table format | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/Project_ATM_Course_8/ShowClinte.h) |
| `MyFile.text` | Persistent client data | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/Project_ATM_Course_8/MyFile.text) |

### ⚠️ Known Issues in v1
- `GoBackToMainMenue()` uses **recursive calls** → Stack grows with every action
- UI and business logic are **mixed** in the same functions
- `LoadClientDataFromFile()` is **duplicated** across multiple namespaces
- No input validation — invalid input causes undefined behavior
- Login has **no attempt limit** — infinite tries allowed

---

## 📁 v2 — OOP Version

Logic is split across **dedicated classes**, each with a single responsibility.

| 📂 File | 📄 Description | |
|---|---|---|
| `Project_ATM_OOP.cpp` | Entry point — login loop only | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/Project_ATM_OOP.cpp) |
| `global.h` | Global `Client` session object | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/global.h) |
| `clsClient.h` | Client entity — encapsulated fields + file I/O | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsClient.h) |
| `clsScreen.h` | Base screen class — shared header with date & client name | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsScreen.h) |
| `clsLoginScreen.h` | Login screen — max 3 failed attempts before lockout | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsLoginScreen.h) |
| `clsMainMenueScreen.h` | Main menu — `do-while` loop navigation (no recursion) | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsMainMenueScreen.h) |
| `clsQuickWithdrawScreen.h` | Quick withdraw — predefined amounts via enum | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsQuickWithdrawScreen.h) |
| `clsNormalWithdrawScreen.h` | Normal withdraw — multiples of 5 only | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsNormalWithdrawScreen.h) |
| `clsDepositScreen.h` | Deposit screen — confirmation before saving | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsDepositScreen.h) |
| `clsCheackBalanceScreen.h` | Check balance screen | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsCheackBalanceScreen.h) |
| `clsInputValidate.h` | Template-based centralized input validation | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsInputValidate.h) |
| `clsDate.h` | Date utilities — auto-displayed in every screen header | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsDate.h) |
| `clsString.h` | String helper utilities | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/clsString.h) |
| `MyFile.text` | Persistent client data | [View →](https://github.com/SaiedNasef78/Project_ATM_System/blob/main/ATM_Using_OOP/MyFile.text) |

### ✅ Improvements in v2
- `do-while` loop in Main Menu → **no stack overflow risk**
- Screen classes inherit from `clsScreen` → **shared header, no code duplication**
- `clsInputValidate` templates → **centralized, reusable input handling**
- Login limited to **3 attempts** with lockout
- `clsClient` owns all file I/O → **single source of truth**

---

## 🧱 OOP Concepts Used (v2)

| Concept | Usage |
|---|---|
| **Inheritance** | All screens inherit from `clsScreen` |
| **Encapsulation** | Private fields with `__declspec(property)` accessors in `clsClient` |
| **Static Methods** | All screen operations are static — no object instantiation needed |
| **Enums** | Menu options in Main Menu and Quick Withdraw |
| **Templates** | `clsInputValidate::ReadNumber<T>()` works for any type |
| **Separation of Concerns** | UI in Screen classes, data logic in `clsClient` |

---

## 🗄️ Data File Format

Both versions share the same file format:


AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance


**Example:**

A123#//#23456#//#Khadega Mohamed#//#097543#//#4455.000000




## 🛠️ Build & Run

> Requires a C++ compiler with C++11 or later.
> `__declspec(property)` in v2 is **MSVC-specific** — use Visual Studio for best compatibility.

**Visual Studio:**

Open the .sln file → Build → Run (Ctrl + F5)


**GCC:**
`bash
# v1
g++ Project_ATM_Course_8.cpp -o ATM_Procedural
./ATM_Procedural

# v2
g++ Project_ATM_OOP.cpp -o ATM_OOP
./ATM_OOP




## 📌 Notes

- Console application — no GUI
- All data persisted locally in `MyFile.text` in the working directory
- Uses the **"mark for delete"** pattern before removing records from file
- Passwords stored as plain text — no encryption in either version
- Both versions use the same `MyFile.text` data file and are fully compatible

---

## 🔗 Related Projects

- [🏦 Bank Client Management System](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/tree/main/Project_Banck_System/ShowMainMinue) — A more advanced OOP project with user management, permissions, currency exchange, and transfer logs




## الـ Commit Message للـ Procedural files:

Add ATM procedural version (Project_ATM_Course_8)

- Console-based ATM using functions and namespaces (no OOP)
- Features: login, quick withdraw, normal withdraw, deposit, check balance
- Data persisted in MyFile.text using #//# delimiter format
- First version before OOP refactor — intentionally kept for comparison
```
