#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

class Student {
public:
    int id;
    string name;
    string career;

    Student(int id, string name, string career) {
        this->id = id;
        this->name = name;
        this->career = career;
    }
};

vector<Student> students;

// Save all students to file
void saveToFile() {
    ofstream file("students.txt");
    if (!file) {
        cout << "❌ Error opening file for writing.\n";
        return;
    }
    for (auto &s : students) {
        file << s.id << "," << s.name << "," << s.career << "\n";
    }
    file.close();
}

// Load students from file
void loadFromFile() {
    students.clear();
    ifstream file("students.txt");
    if (!file) {
        return; // no students yet
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        if (pos1 != string::npos && pos2 != string::npos) {
            int id = stoi(line.substr(0, pos1));
            string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string career = line.substr(pos2 + 1);
            students.push_back(Student(id, name, career));
        }
    }
    file.close();
}

void addStudent() {
    int id;
    string name, career;

    cout << "Enter ID: ";
    while (!(cin >> id)) { // validar número
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Invalid ID. Enter a number: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter career: ";
    getline(cin, career);

    students.push_back(Student(id, name, career));
    saveToFile();
    cout << "✅ Student added successfully!\n";
}

void listStudents() {
    cout << "\n=== Student List ===\n";
    if (students.empty()) {
        cout << "No students registered yet.\n";
        return;
    }
    for (auto &s : students) {
        cout << "ID: " << s.id << " | Name: " << s.name << " | Career: " << s.career << endl;
    }
}

void findStudentById() {
    int id;
    cout << "Enter student ID to search: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Invalid ID. Enter a number: ";
    }

    bool found = false;
    for (auto &s : students) {
        if (s.id == id) {
            cout << "✅ Found: ID: " << s.id << " | Name: " << s.name << " | Career: " << s.career << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "❌ Student with ID " << id << " not found.\n";
    }
}

void deleteStudentById() {
    int id;
    cout << "Enter student ID to delete: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Invalid ID. Enter a number: ";
    }

    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            cout << "🗑️ Deleting student: " << it->name << " (" << it->career << ")\n";
            students.erase(it);
            saveToFile();
            cout << "✅ Student deleted successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "❌ Student with ID " << id << " not found.\n";
    }
}

void updateStudentById() {
    int id;
    cout << "Enter student ID to update: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Invalid ID. Enter a number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;
    for (auto &s : students) {
        if (s.id == id) {
            cout << "Editing student: " << s.name << " (" << s.career << ")\n";

            cout << "Enter new name (leave empty to keep current): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) s.name = newName;

            cout << "Enter new career (leave empty to keep current): ";
            string newCareer;
            getline(cin, newCareer);
            if (!newCareer.empty()) s.career = newCareer;

            saveToFile();
            cout << "✅ Student updated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "❌ Student with ID " << id << " not found.\n";
    }
}

int main() {
    loadFromFile();
    int option;
    do {
        cout << "\n=== STUDENT MANAGER ===\n";
        cout << "1. Add student\n";
        cout << "2. List students\n";
        cout << "3. Search student by ID\n";
        cout << "4. Delete student by ID\n";
        cout << "5. Update student by ID\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: findStudentById(); break;
            case 4: deleteStudentById(); break;
            case 5: updateStudentById(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (option != 0);

    return 0;
}
