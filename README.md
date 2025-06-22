# 🧮 Qt Calculator

A simple yet feature-rich calculator built with **Qt 6** and **C++** using the Qt Widgets module. This project is ideal for beginners learning Qt and GUI programming.

---

## ✨ Features

- 🔢 Supports basic arithmetic operations: `+`, `−`, `*`, `/`
- ⌨️ Fully controllable with both mouse and keyboard
- 🌓 Light and dark theme toggle button
- ❌ Clear button (`C`) to reset the display
- ✅ Error handling:
  - Shows a message when dividing by zero
  - Ignores repeated operator input (e.g., `++`, `--`)
  - Replaces the last operator if a new one is entered
- 🔁 Repeats the last calculation when pressing `=` multiple times
- 🧩 Read-only input field with styled font and alignment
- 🪟 Custom window title and application icon

---

## 🛠️ Technologies Used

| Technology       | Purpose                      |
|------------------|------------------------------|
| **C++ (C++17)**   | Core programming language     |
| **Qt 6 Widgets**  | GUI, event handling           |
| **QJSEngine**     | Parsing and evaluating input  |
| **QMessageBox**   | Error dialogs                 |
| **Qt Designer**   | UI design (.ui file)          |
| **Git + GitHub**  | Version control and hosting   |

---

## 🚀 Build and Run Instructions

> ⚠️ Requires **Qt 6** and **Qt Creator** installed.

1. Clone the repository:
   git clone https://github.com/Karen2485/qt-calculator.git
   cd qt-calculator
2. Open the project in **Qt Creator**:
   * Go to **File → Open File or Project**
   * Select `calculator.pro` or the main `.cpp` file
3. Press **Ctrl + R** or click the green play ▶️ button to build and run

---

## 📁 Project Structure

```
qt-calculator/
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
├── resources.qrc
├── icon.png
├── README.md
└── .gitignore
```

---

## 👤 Author

**Karen** — [GitHub Profile](https://github.com/Karen2485)

---

## 📄 License

This project is licensed under the MIT License. Feel free to use, share, and modify.

```
