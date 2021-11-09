#ifndef PUPIL_H
#define PUPIL_H


#include <iostream>
#include <limits>
using namespace std;

class Pupil {
   protected:
    string m_name;
    int m_age;

   public:
    Pupil(const string, const int);
    string getName() { return m_name; }
    int getAge() { return m_age; }
    friend ostream& operator<<(ostream& out, const Pupil& p);
    virtual ostream& print(ostream& out) const;
    ~Pupil();
};

Pupil::Pupil(const string name = "Ivan", const int age = 6)
    : m_name{name}, m_age{age} {}

Pupil::~Pupil() { m_name.clear(); }

ostream& operator<<(std::ostream& out, const Pupil& p) { return p.print(out); }
ostream& Pupil::print(ostream& out) const {
    out << "Name = " << m_name << endl << "Age = " << m_age << endl;
    return out;
}

#endif