#ifndef STUDENT_HPP
#define STUDENT_HPP

#include<string>
#include<odb/core.hxx>
struct student
{
    int id;
    std::string name;
};
#pragma db object(student)
#pragma db member(student::id) id auto column("ID")
#pragma db member(student::name) column("NAME") 
#endif
