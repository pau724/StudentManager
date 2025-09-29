# 🎓 Student Manager (C++)


---

## ✨ Features
- ➕ Add a student (ID, name, career)
- 📋 List all students
- 🔍 Search student by ID
- 🗑️ Delete student by ID
- ✏️ Update student by ID
- 💾 Persistent storage using `students.txt`

---

## 🛠 Tech Stack
- C++17 (works with Clang/Apple Clang on macOS, GCC on Linux, MSVC on Windows)
- Console application
- File-based persistence

---

## 📂 Project Structure
StudentManager/
├── main.cpp
├── students.txt # data file (auto-created when running)
---

---

## ▶️ How to Run

### Compile
```bash
g++ main.cpp -o manager
Run
./manager
📖 Example Session
=== STUDENT MANAGER ===
1. Add student
2. List students
3. Search student by ID
4. Delete student by ID
5. Update student by ID
0. Exit
Choose: 1
Enter ID: 1
Enter name: Paula
Enter career: Computer Science
✅ Student added successfully!🗺️ Roadmap / Next Steps
Input validation improvements
Support for saving in CSV/JSON
Unit tests
Optional GUI (Qt) or Web API version
👩🏻‍💻 Author: Paula Espinoza — Computer Science student
This project is part of my portfolio for Werkstudent positions.
