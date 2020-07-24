#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <set>

class Stu_X {
public:
    virtual ~Stu_X() {
        std::cout << "~Stu_X()" << std::endl;
    }
};

class Stu_XX : public Stu_X {
public:
    virtual ~Stu_XX() {
        std::cout << "~Stu_XX()" << std::endl;
    }
};

/**
 * vector
 * 连续存储的元素<vector>

Vector<int>c;

c.back()    传回最后一个数据，不检查这个数据是否存在。

c.clear()     移除容器中所有数据。

c.empty()   判断容器是否为空。

c.front()     传回地一个数据。

c.pop_back() 删除最后一个数据。

c.push_back(elem)  在尾部加入一个数据。

c[i] 等同于 c.at(i);
 */
// std::vector
void test_stl_main2() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // 获取第一个元素
    int front = v.front();
    // 获取最后一个元素
    int back = v.back();

    std::cout << "front: " << front << " back: " << back << std::endl;

    // 删除最后一个元素
    v.pop_back();

    // 删除第一个元素[需要使用迭代器]
    v.erase(v.begin());

    for (int i = 0; i < v.size(); ++i) {
        std::cout << "v: " << v[i] << std::endl;
    }
}

// std::list
void test_stl_main3() {
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
        std::cout << "l: " << *it << std::endl;
    }
}

// map
void test_stl_main4() {
    std::map<std::string, int> m;
    m["hello"] = 1;
    m["world"] = 2;

    // 使用auto 遍历
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << "first: " << it->first << " second: " << it->second << std::endl;
    }
}

void test_stl_main5() {
    Stu_X stu_x;
}

void test_stl_main6() {
    Stu_XX stu_xx;
}

void test_stl_main7() {
    Stu_X *stu_x = new Stu_XX();
    delete (stu_x);
}

// stack
//s.empty();  //判断stack是否为空，为空返回true，否则返回false
//s.size();   //返回stack中元素的个数
//s.pop();    //删除栈顶元素，但不返回其值
//s.top();    //返回栈顶元素的值，但不删除此元素
//s.push(item);   //在栈顶压入新元素item
void test_stl_main8() {
    std::stack<int> s;
    s.push(1);
    s.push(2);

    while (!s.empty()) {
        int i = s.top();
        s.pop();
        std::cout << "i: " << i << std::endl;
    }
}

// queue
//queue<int> q; //priority_queue<int> q;
//q.empty();  //判断队列是否为空
//q.size();   //返回队列长度
//q.push(item);   //对于queue，在队尾压入一个新元素

//对于priority_queue，在基于优先级的适当位置插入新元素

//queue only:
//q.front();  //返回队首元素的值，但不删除该元素
//q.back();   //返回队尾元素的值，但不删除该元素

//priority_queue only:
//q.top();    //返回具有最高优先级的元素值，但不删除该元素
void test_stl_main9() {
    std::queue<int> q;
    q.push(1);
    q.push(2);

    while (!q.empty()) {
        int i = q.front();
        std::cout << "i: " << i << std::endl;
        q.pop();
    }
}

void test_stl_main10() {
    std::set<int> s;
    s.insert(1);

    for (auto it = s.begin(); it != s.end(); it++) {
        std::cout << "*it: " << *it << std::endl;
    }
}


int main() {
    std::cout << "stl_main2.cpp" << std::endl;

    test_stl_main10();
    new Stu_X;

    return 0;
}
