#include <iostream>
#include <queue>
#include <string>

class Task {
public:
    Task(const std::string& description, int priority)
        : description(description), priority(priority) {}

    void displayTask() const {
        std::cout << "Task: " << description << "\tPriority: " << priority << "\n";
    }

    // Overload the less-than operator for priority comparison
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }

private:
    std::string description;
    int priority;
};

int main() {
    std::priority_queue<Task> taskQueue;

    char choice;
    do {
        std::string description;
        int priority;

        std::cout << "Enter task description: ";
        std::getline(std::cin, description);

        std::cout << "Enter task priority: ";
        std::cin >> priority;
        std::cin.ignore(); // Consume the newline character left in the stream

        // Create a new task and add it to the priority queue
        Task newTask(description, priority);
        taskQueue.push(newTask);

        std::cout << "Task added to the queue.\n";

        std::cout << "Do you want to add another task? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character left in the stream

    } while (choice == 'y' || choice == 'Y');

    // Display tasks in priority order
    std::cout << "\nTasks in priority order:\n";
    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.top();
        currentTask.displayTask();
        taskQueue.pop();
    }

    return 0;
}
