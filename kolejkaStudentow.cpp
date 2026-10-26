#include<iostream>
#include<vector>
#include<string>

using namespace std;
//#######################################################
class Student{
private:
    string name;   
    int age;
public:
    Student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    string getName() {
        return name;
    };
    int getAge() {
        return age;
    };
};

///#####################################################
class MyStudentsQueue {
private:
    vector<Student> students;
public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }
    Student removeStudent() {
        if (!students.empty()) {
            Student student = students.front();
            students.erase(students.begin());
            return student;
        }
        throw runtime_error("Queue is empty");
    }

    bool isEmpty() {
        return students.empty();
    }    

    string getJSONStudents() {
        string json = "[";
        for (size_t i = 0; i < students.size(); ++i) {
            json += "{ \"name\": \"" + students[i].getName() + "\", \"age\": " + to_string(students[i].getAge()) + " }";
            if (i < students.size() - 1) {
                json += ", ";
            }
        }
        json += "]";
        return json;
    }
    
};


int main() {
    MyStudentsQueue queue;
    queue.addStudent(Student("Alicja", 20));
    queue.addStudent(Student("Roman", 22));
    queue.addStudent(Student("Kasia", 19));

    cout << "Students in queue (JSON format): " << queue.getJSONStudents() << endl; 

    cout<< "Removed student: " << queue.removeStudent().getName() << endl;



    return 0;
}


