#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Create Class Template: Memory Calculate
template <typename T>
class MemoryCalculate {
private:
    T id;
    std::string name;

public:
    // A constructor to initialize the id and name
    MemoryCalculate(T studentId, std::string studentName) : id(studentId), name(studentName) {}

    // A method to display the student's details
    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << std::endl;
    }

    T getId() const {
        return id;
    }
};

void displayMenu() {
    std::cout << "\n--- Student Management System ---" << std::endl;
    std::cout << "1. Add a Student" << std::endl;
    std::cout << "2. Display All Students" << std::endl;
    std::cout << "3. Remove a Student by ID" << std::endl;
    std::cout << "4. Search for a Student by ID" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    // Vector of Template Class objects
    std::vector<MemoryCalculate<int>> students;
    int choice;

    do {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Exiting." << std::endl;
            break;
        }

        switch (choice) {
            case 1: {
                int id;
                std::string name;
                std::cout << "Enter Student ID: ";
                std::cin >> id;
                std::cin.ignore(); // Clear newline from buffer
                std::cout << "Enter Student Name: ";
                std::getline(std::cin, name);
                
                // Use push_back() to add a student to the vector
                students.push_back(MemoryCalculate<int>(id, name));
                std::cout << "Student added successfully." << std::endl;
                break;
            }
            case 2: {
                if (students.empty()) {
                    std::cout << "No students in the list." << std::endl;
                } else {
                    std::cout << "\nList of Students:" << std::endl;
                    // Iterate through the vector to display all students
                    for (const auto& student : students) {
                        student.display();
                    }
                }
                break;
            }
            case 3: {
                int searchId;
                std::cout << "Enter Student ID to remove: ";
                std::cin >> searchId;
                
                // Search the vector for a student by ID and remove the student if found
                auto it = std::find_if(students.begin(), students.end(), [searchId](const MemoryCalculate<int>& s) {
                    return s.getId() == searchId;
                });

                if (it != students.end()) {
                    students.erase(it);
                    std::cout << "Student with ID " << searchId << " removed successfully." << std::endl;
                } else {
                    std::cout << "Student with ID " << searchId << " not found." << std::endl;
                }
                break;
            }
            case 4: {
                int searchId;
                std::cout << "Enter Student ID to search: ";
                std::cin >> searchId;
                
                // Search and display the student with the given ID
                auto it = std::find_if(students.begin(), students.end(), [searchId](const MemoryCalculate<int>& s) {
                    return s.getId() == searchId;
                });

                if (it != students.end()) {
                    std::cout << "Student found: ";
                    it->display();
                } else {
                    std::cout << "Student with ID " << searchId << " not found." << std::endl;
                }
                break;
            }
            case 5:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
