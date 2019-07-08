#ifndef DEMO_TEST_P_H
#define DEMO_TEST_P_H

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


};


#endif //DEMO_TEST_P_H
