#pragma once

#include <string>
#include <iostream>

struct Student
{
    std::string name;
    int score;

    bool operator<(const Student& other) {
        return score != other.score ? score < other.score : name < other.name;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << "Student: " << s.name << " " << s.score << std::endl;
        return os;
    }
};
