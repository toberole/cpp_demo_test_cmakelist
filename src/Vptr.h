#ifndef DEMO_TEST_VPTR_H
#define DEMO_TEST_VPTR_H
class Vptr {
public:
    int n;
public:
    virtual void test() = 0;
    virtual ~Vptr();
};


#endif //DEMO_TEST_VPTR_H
