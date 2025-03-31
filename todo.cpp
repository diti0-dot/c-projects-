#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<pair<int, string>> tasks;

// Function to add a task with priority
void added(string work, char priority) {
    int prio = (priority == 'h') ? 1 : (priority == 'm') ? 2 : 3;
    tasks.push_back({prio, work});
    tasks.sort(); 
    cout << "Task added: " << work << " (Priority: " << priority << ")\n";
}

// Function to delete a task
void del(string work) {
    auto it = find_if(tasks.begin(), tasks.end(), [&](const pair<int, string>& t) {
        return t.second == work;
    });

    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task deleted: " << work << endl;
    } else {
        cout << "Task not found: " << work << endl;
    }
}

// Function to print tasks sorted by priority
void printTasks() {
    if (tasks.empty()) {
        cout << "To-do list is empty.\n";
        return;
    }
    
    cout << "Your To-Do List (Sorted by Priority):\n";
    for (const auto& task : tasks) {
        string priorityLabel = (task.first == 1) ? "🔥 High" : (task.first == 2) ? "⚡ Medium" : "💤 Low";
        cout << " - " << priorityLabel << ": " << task.second << endl;
    }
}

int main() {
    string name, cmd, work;
    char priority;

    cout << "Enter list name: ";
    cin >> name;
    cout << "You created " << name << endl;

    cout << "Commands:\n"
         << " - add <priority> <task> (e.g., add h sleep, add l talk)\n"
         << " - del <task> (e.g., del sleep)\n"
         << " - p (print the sorted to-do list)\n"
         << " - exit (quit the program)\n";

    cin.ignore(); 

    while (true) {
        cout << "Enter command: ";
        getline(cin, cmd);

        if (cmd.find("add ") == 0 && cmd.length() > 6) {
            priority = cmd[4]; 
            work = cmd.substr(6); 
            if (priority == 'h' || priority == 'm' || priority == 'l') {
                added(work, priority);
            } else {
                cout << "Invalid priority! Use h (high), m (medium), or l (low).\n";
            }
        } 
        else if (cmd.find("del ") == 0) {
            work = cmd.substr(4);
            del(work);
        } 
        else if (cmd == "p") {
            printTasks();
        } 
        else if (cmd == "exit") {
            break;
        } 
        else {
            cout << "Invalid command. Try again.\n";
        }
    }

    return 0;
}
