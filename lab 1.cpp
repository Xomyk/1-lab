#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Faculty {
private:
    string name;
    int departmentCount; // Кол каф

public:
    // Конструктор
    Faculty(const string& n, int count) : name(n), departmentCount(count) {
        cout << "  [+] Создан факультет \"" << name 
             << "\" (кафедр: " << departmentCount << ")" << endl;
    }

    // Деструктор
    ~Faculty() {
        cout << "  [-] Уничтожен факультет \"" << name << "\"" << endl;
    }

    // Метод для вывода информации
    void printInfo() const {
        cout << "    - Факультет: " << name 
             << ", Количество кафедр: " << departmentCount << endl;
    }
};
// Класс "Университет" (Целое)
class University {
private:
    string name;
    vector<Faculty> faculties; 
public:
    // Конструктор
    University(const string& n) : name(n) {
        cout << "=== Создан Университет \"" << name << "\" ===" << endl;
    }

    // Деструктор
    ~University() {
        cout << "=== Университет \"" << name << "\" ликвидируется ===" << endl;
    }

    //  добавления факультета
    void addFaculty(const string& facultyName, int count) {
        faculties.emplace_back(facultyName, count);
    }

    // Вывод инф ун
    void printInfo() const {
        cout << "\n--- Информация об Университете \"" << name << "\" ---" << endl;
        if (faculties.empty()) {
            cout << "  Факультетов пока нет." << endl;
        } else {
            for (const auto& faculty : faculties) {
                faculty.printInfo();
            }
        }
        cout << "--------------------------------------------------\n";
    }
};
// Гл функция
int main() {
    setlocale(LC_ALL, "ru");

    cout << "--- Начало программы ---" << endl;
    
    // Создаем университет
    University myUniversity("МГТУ им. Баумана");

    // Добавляем факультеты (они создаются внутри университета)
    myUniversity.addFaculty("Информатика и системы управления", 5);
    myUniversity.addFaculty("Робототехника и комплексная автоматизация", 4);
    myUniversity.addFaculty("Энергомашиностроение", 3);

    // Выводим информацию
    myUniversity.printInfo();

    cout << "--- Программа подходит к концу (выход из main) ---\n" << endl;
    
    // При выходе из main локальная переменная myUniversity уничтожается.
    // Сначала вызывается деструктор University, затем деструкторы Faculty.
    return 0;
}