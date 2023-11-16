#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<map>

using namespace std;

class User {
public:
    string username;
    string password;
};

class Agenda {
public:
    vector<string> tasks;
    vector<string> reminders;
    vector<string> notes;
    vector<int> test_scores;
    vector<int> quiz_scores;
    vector<string> deadlines;
};

vector<User> users;
Agenda agenda;

void registerUser() {
    User user;
    cout << "Enter a username: ";
    cin >> user.username;
    cout << "Enter a password: ";
    cin >> user.password;
    users.push_back(user);
}

User* login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].username == username && users[i].password == password) {
            return &users[i];
        }
    }
    return NULL;
}

void displayMenu() {
    cout << "1. Add task\n";
    cout << "2. Remove task\n";
    cout << "3. Add reminder\n";
    cout << "4. Remove reminder\n";
    cout << "5. Add note\n";
    cout << "6. Remove note\n";
    cout << "7. Add test score\n";
    cout << "8. Remove test score\n";
    cout << "9. Add quiz score\n";
    cout << "10. Remove quiz score\n";
    cout << "11. Add deadline\n";
    cout << "12. Remove deadline\n";
    cout << "13. Save data\n";
    cout << "14. Load data\n";
    cout << "15. Exit\n";
}

void addTask() {
    string task;
    cout << "Enter task: ";
    cin >> task;
    agenda.tasks.push_back(task);
}

void removeTask() {
    int index;
    cout << "Enter index of task to remove: ";
    cin >> index;
    agenda.tasks.erase(agenda.tasks.begin() + index);
}

void addReminder() {
    string reminder;
    cout << "Enter reminder: ";
    cin >> reminder;
    agenda.reminders.push_back(reminder);
}

void removeReminder() {
    int index;
    cout << "Enter index of reminder to remove: ";
    cin >> index;
    agenda.reminders.erase(agenda.reminders.begin() + index);
}

void addNote() {
    string note;
    cout << "Enter note: ";
    cin >> note;
    agenda.notes.push_back(note);
}

void removeNote() {
    int index;
    cout << "Enter index of note to remove: ";
    cin >> index;
    agenda.notes.erase(agenda.notes.begin() + index);
}

void addTestScore() {
    int score;
    cout << "Enter test score: ";
    cin >> score;
    agenda.test_scores.push_back(score);
}

void removeTestScore() {
    int index;
    cout << "Enter index of test score to remove: ";
    cin >> index;
    agenda.test_scores.erase(agenda.test_scores.begin() + index);
}

void addQuizScore() {
    int score;
    cout << "Enter quiz score: ";
    cin >> score;
    agenda.quiz_scores.push_back(score);
}

void removeQuizScore() {
    int index;
    cout << "Enter index of quiz score to remove: ";
    cin >> index;
    agenda.quiz_scores.erase(agenda.quiz_scores.begin() + index);
}

void addDeadline() {
    string deadline;
    cout << "Enter deadline: ";
    cin >> deadline;
    agenda.deadlines.push_back(deadline);
}

void removeDeadline() {
    int index;
    cout << "Enter index of deadline to remove: ";
    cin >> index;
    agenda.deadlines.erase(agenda.deadlines.begin() + index);
}

void saveData() {
    ofstream file("data.csv");
    for (int i = 0; i < agenda.tasks.size(); i++) {
        file << "task," << agenda.tasks[i] << endl;
    }
    for (int i = 0; i < agenda.reminders.size(); i++) {
        file << "reminder," << agenda.reminders[i] << endl;
    }
    for (int i = 0; i < agenda.notes.size(); i++) {
        file << "note," << agenda.notes[i] << endl;
    }
    for (int i = 0; i < agenda.test_scores.size(); i++) {
        file << "test_score," << agenda.test_scores[i] << endl;
    }
    for (int i = 0; i < agenda.quiz_scores.size(); i++) {
        file << "quiz_score," << agenda.quiz_scores[i] << endl;
    }
    for (int i = 0; i < agenda.deadlines.size(); i++) {
        file << "deadline," << agenda.deadlines[i] << endl;
    }
    file.close();
}

map<string, vector<string> > loadData() {
    ifstream file("data.csv");
    string line;
    map<string, vector<string> > loadedData;

    while (getline(file, line)) {
        string type, data;
        int commaIndex = line.find(",");
        type = line.substr(0, commaIndex);
        data = line.substr(commaIndex + 1);

        if (type == "task") {
            loadedData["Tasks"].push_back(data);
        } else if (type == "reminder") {
            loadedData["Reminders"].push_back(data);
        } else if (type == "note") {
            loadedData["Notes"].push_back(data);
        } else if (type == "test_score") {
            loadedData["Test Scores"].push_back(data);
        } else if (type == "quiz_score") {
            loadedData["Quiz Scores"].push_back(data);
        } else if (type == "deadline") {
            loadedData["Deadlines"].push_back(data);
        }
    }

    file.close();

    if (loadedData.empty()) {
        cout << "No data loaded from file." << endl;
    } else {
        cout << "Data loaded successfully." << endl;
    }

    return loadedData;
}

int main() {
    int choice;
    User* currentUser = NULL;
    while (true) {
        if (currentUser == NULL) {
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "3. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            if (choice == 1) {
                registerUser();
            }
            else if (choice == 2) {
                currentUser = login();
                if (currentUser == NULL) {
                    cout << "Invalid username or password\n";
                }
            }
            else if (choice == 3) {
                break;
            }
            else {
                cout << "Invalid choice\n";
            }
        }
        else {
            displayMenu();
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                addReminder();
                break;
            case 4:
                removeReminder();
                break;
            case 5:
                addNote();
                break;
            case 6:
                removeNote();
                break;
            case 7:
                addTestScore();
                break;
            case 8:
                removeTestScore();
                break;
            case 9:
                addQuizScore();
                break;
            case 10:
                removeQuizScore();
                break;
            case 11:
                addDeadline();
                break;
            case 12:
                removeDeadline();
                break;
            case 13:
                saveData();
                break;
            case 14:
                loadData();
                break;
            case 15:
                currentUser = NULL;
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
        }
    }
    return 0;
}