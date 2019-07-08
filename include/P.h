#ifndef DEMO_TEST_P_H
#define DEMO_TEST_P_H

#include <iostream>
#include <string>

class P {
private:
    int age;
public:
    std::string name;
public:
    P();

    P(const P &p);

    P &operator=(P &p);

    virtual ~P();

    P(int age, std::string name);

    virtual void print() {
        std::cout << "父类的print" << std::endl;
    }
};


#endif //DEMO_TEST_P_H
