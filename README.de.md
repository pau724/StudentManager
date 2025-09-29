# 🎓 Student Manager (C++)



---

## ✨ Funktionen
- ➕ Student hinzufügen (ID, Name, Studienfach)
- 📋 Alle Studenten auflisten
- 🔍 Student nach ID suchen
- 🗑️ Student nach ID löschen
- ✏️ Student nach ID bearbeiten
- 💾 Persistente Speicherung mit `students.txt`

---

## 🛠 Technologie-Stack
- C++17 (kompatibel mit Clang/Apple Clang auf macOS, GCC auf Linux, MSVC auf Windows)
- Konsolenanwendung
- Dateibasierte Persistenz

---

## 📂 Projektstruktur
StudentManager/
├── main.cpp
├── students.txt # Datendatei (wird beim Ausführen automatisch erstellt)
---

## ▶️ Ausführen

### Kompilieren
```bash
g++ main.cpp -o manager
Starten
./manager📖 Beispiel-Session
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
Enter career: Informatik
✅ Student erfolgreich hinzugefügt!
🗺️ Roadmap / Nächste Schritte
Verbesserte Eingabevalidierung
Unterstützung für CSV/JSON-Speicherung
Unit Tests
Optional: GUI (Qt) oder Web-API-Version
👩🏻‍💻 Autorin: Paula Espinoza — Informatik-Studentin
Dieses Projekt ist Teil meines Portfolios für Werkstudent-Stellen.
