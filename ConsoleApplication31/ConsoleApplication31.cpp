#include <iostream>
#include <string>

using namespace std;
/// <summary>
/// This class provides functionality to store and manage date information in the format day, month, year.
/// The methods allow you to set and retrieve day, month, and year values.
/// Examples of use:
///     Date myDate;
///     myDate.SetDay(15);
///     myDate.SetMonth(10);
///     myDate.SetYear(2023);
///     int day = myDate.GetDay();
/// </summary>
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() {
        SetDay(1);
        SetMonth(1);
        SetYear(1990);
    }

    void SetDay(day) {
        this->day = day;
    }
    int GetDay() const {
        return day;
    }
    void SetMonth(month) {
        this->month = month;
    }
    int GetMonth() const {
        return month;
    }
    void SetYear(year) {
        this->year = year;
    }
    int GetYear() const {
        return year;
    }
};
/// <summary>
/// This class holds information about a student, including personal
///  details (name, surname, date of birth, address, phone number) and grades in various subjects.
/// Key methods of the class:
///    - SetBirthDate: sets the student's date of birth.
///    - GetBirthDate: retrieves the student's date of birth.
///    - SetHomeAddress: sets the student's home address.
///    - GetHomeAddress: retrieves the student's home address.
///    - SetPhoneNumber: sets the student's phone number.
///    - GetPhoneNumber: retrieves the student's phone number.
///    - GetMathGrade: retrieves a math grade for a specific subject.
///    - AddChemistryGrade: adds a chemistry grade for a specific subject.
///    - GetChemistryGrade: retrieves a chemistry grade for a specific subject.
/// </summary>
class Student {
private:
    string last_name;
    string first_name;
    string middle_name;
    Date birth_date;
    string home_address;
    string phone_number;
    int* grades_math;
    int* grade_physica_education;
    int* grade_chemistry;

public:
    Student(string first, string last, int max) : first_name(first), last_name(last)
    {
        grades_math = new int[max]();
        grade_physica_education = new int[max]();
        grade_chemistry = new int[max]();
    }

    void SetBirthDate(const Date& date) {
        birth_date = date;
    }

    Date GetBirthDate() const {
        return birth_date;
    }

    void SetHomeAddress(const string& address) {
        home_address = address;
    }

    string GetHomeAddress() const {
        return home_address;
    }

    void SetPhoneNumber(const string& phone) {
        phone_number = phone;
    }

    string GetPhoneNumber() const {
        return phone_number;
    }

    void SetLastName(const string& last) {
        last_name = last;
    }

    string GetLastName() const {
        return last_name;
    }

    void AddMathGrade(int subject_index, int grade) {
        if (subject_index >= 0) {
            grades_math[subject_index] = grade;
        }
    }

    int GetMathGrade(int subject_index) const {
        if (subject_index >= 0) {
            return grades_math[subject_index];
        }
        return -1;
    }

    void AddPhysicalEducationGrade(int subject_index, int grade) {
        if (subject_index >= 0) {
            grade_physica_education[subject_index] = grade;
        }
    }

    int GetPhysicalEducationGrade(int subject_index) const {
        if (subject_index >= 0) {
            return grade_physica_education[subject_index];
        }
        return -1;
    }

    void AddChemistryGrade(int subject_index, int grade) {
        if (subject_index >= 0) {
            grade_chemistry[subject_index] = grade;
        }
    }

    int GetChemistryGrade(int subject_index) const {
        if (subject_index >= 0) {
            return grade_chemistry[subject_index];
        }
        return -1;
    }

    void ShowStudentInfo() const {
        cout << "Фамилия: " << last_name << endl;
        cout << "Имя: " << first_name << endl;
        cout << "Отчество: " << middle_name << endl;
        cout << "Дата рождения: " << birth_date.GetDay() << "." << birth_date.GetMonth() << "." << birth_date.GetYear() << endl;
        cout << "Домашний адрес: " << home_address << endl;
        cout << "Телефонный номер: " << phone_number << endl;

        cout << "Оценки по математике: ";
        for (int i = 0; i < 100; i++) {
            cout << grades_math[i] << " ";
        }
        cout << endl;

        cout << "Оценки по физкультуре: ";
        for (int i = 0; i < 100; i++) {
            cout << grade_physica_education[i] << " ";
        }
        cout << endl;

        cout << "Оценки по химии: ";
        for (int i = 0; i < 100; i++) {
            cout << grade_chemistry[i] << " ";
        }
        cout << endl;
    }


    ~Student() {
        delete[] grades_math;
        delete[] grade_physica_education;
        delete[] grade_chemistry;
    }
};

int main() {
    setlocale(LC_ALL, "");

    Student student("Антон", "Васильев");

    student.SetBirthDate(Date(2000, 1, 1));
    student.SetHomeAddress("ул. Добровольского, 123");
    student.SetPhoneNumber("+38(097)264-18-54");

    student.AddMathGrade(0, 95);
    student.AddMathGrade(1, 88);

    student.AddPhysicalEducationGrade(0, 85);
    student.AddPhysicalEducationGrade(1, 90);

    student.AddChemistryGrade(0, 75);
    student.AddChemistryGrade(1, 80);

    student.ShowStudentInfo();

    student.SetLastName("Петров");
    student.SetPhoneNumber("+38(097)234-13-24");

    cout << "Измененная фамилия: " << student.GetLastName() << endl;
    cout << "Измененный телефонный номер: " << student.GetPhoneNumber() << endl;

    return 0;
}