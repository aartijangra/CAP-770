//student coming one by one on cash counter we need to calculate the dues and deposit the cash
//balance amt input krana h
//paid amount
#include <iostream>
#include <queue>

using namespace std;

class Student {
public:
    string name;
    int dues;

    Student(string name, int dues) {
        this->name = name;
        this->dues = dues;
    }
};

class Cashier {
public:
    queue<Student> studentQueue;
    int totalCashCollected;

    Cashier() {
        totalCashCollected = 0;
    }

    void addStudent(string name, int dues) {
        studentQueue.push(Student(name, dues));
    }

    void serveStudents() {
        while (!studentQueue.empty()) {
            Student student = studentQueue.front();
            studentQueue.pop();

            cout << "Student " << student.name << " needs to pay $" << student.dues << "." << endl;
            cout << "Student " << student.name << " paid $" << student.dues << "." << endl;

            totalCashCollected += student.dues;
        }

        cout << "Total cash collected: $" << totalCashCollected << endl;
    }
};

int main() {
    Cashier cashier;

    cashier.addStudent("Alice", 10);
    cashier.addStudent("Bob", 15);
    cashier.addStudent("Charlie", 20);

    cashier.serveStudents();

    return 0;
}

