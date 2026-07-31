#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(vector<double> &scores)
{

    if (scores.empty())
        return 0.0;

    double sum = 0;
    for (int i = 0; i < scores.size(); i++)
    {
        sum += scores[i];
    }
    return sum / scores.size();
}

void showMenu()
{
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

void addStudent(vector<Student> &students)
{

    Student s;
    cout << "Student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 1; i <= numScores; i++)
    {
        double score;
        cout << "Enter score " << i << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayAllStudents(vector<Student> &students)
{

    if (students.empty())
    {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << "\n"
         << left
         << setw(20) << "Name"
         << setw(12) << "ID"
         << setw(30) << "Scores"
         << setw(10) << "Average"
         << endl;
    cout << string(72, '-') << endl;

    for (int i = 0; i < students.size(); i++)
    {

        string scoresStr = "";
        for (int j = 0; j < students[i].scores.size(); j++)
        {
            scoresStr += to_string((int)students[i].scores[j]);
            if (j < students[i].scores.size() - 1)
            {
                scoresStr += "  ";
            }
        }

        double avg = calculateAverage(students[i].scores);

        cout << left
             << setw(20) << students[i].name
             << setw(12) << students[i].id
             << setw(30) << scoresStr
             << fixed << setprecision(2) << avg
             << endl;
    }
}

void calculateStudentAverage(vector<Student> &students)
{

    if (students.empty())
    {
        cout << "No students on record." << endl;
        return;
    }

    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == searchId)
        {
            double avg = calculateAverage(students[i].scores);
            cout << fixed << setprecision(2);
            cout << students[i].name
                 << "'s average score: "
                 << avg << endl;
            return;
        }
    }

    cout << "Error: Student with ID " << searchId << " not found." << endl;
}

int main()
{

    vector<Student> students;
    int choice;

    while (true)
    {

        showMenu();
        cin >> choice;

        if (choice == 1)
        {
            addStudent(students);
        }
        else if (choice == 2)
        {
            displayAllStudents(students);
        }
        else if (choice == 3)
        {
            calculateStudentAverage(students);
        }
        else if (choice == 4)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter 1-4." << endl;
        }
    }

    return 0;
}