#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    virtual QString toString() const = 0;
    virtual ~Person() = default;
};

#endif
