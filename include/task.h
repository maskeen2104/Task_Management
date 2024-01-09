#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string& name, int priority);

    void displayTask() const;
    void adjustPriority(int newPriority);
    bool operator<(const Task& other) const;

private:
    std::string name;
    int priority;
};

#endif
