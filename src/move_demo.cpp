#include <iostream>

/**
 * 移动语义demo
 */
class Move_Data {
public:
    Move_Data() {
        std::cout << "Move_Data()" << std::endl;
    }

    Move_Data(const Move_Data &move_data) {
        std::cout << "拷贝构造" << std::endl;
    }

    Move_Data &operator=(Move_Data &move_data) {
        std::cout << "赋值运算符" << std::endl;
    };

    /**
     *  如果不实现移动构造函数
     *  在使用std::move的时候会调用拷贝构造函数
     */
    Move_Data(Move_Data &&move_data) {
        std::cout << "移动拷贝构造" << std::endl;
    }

    ~Move_Data() {
        std::cout << "析构函数" << std::endl;
    }
};

