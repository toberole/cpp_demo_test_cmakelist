#ifndef DEMO_TEST_SON_P_H
#define DEMO_TEST_SON_P_H

#include <string>
#include "P.h"

class Son_P : public P {
private:
    std::string son_name;
public:
    int key;

public:
    Son_P();

    Son_P(const Son_P &son_p);

    Son_P &operator=(Son_P &son_p);

    virtual ~Son_P();

    Son_P(std::string &name, int age);

    Son_P(std::string &name, int key, int age);

    Son_P(std::string &son_name, int key, int age, std::string name);
};


#endif //DEMO_TEST_SON_P_H
