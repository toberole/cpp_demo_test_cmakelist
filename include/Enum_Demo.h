//
// Created by Apple on 2019/7/4.
//

#ifndef DEMO_TEST_ENUM_DEMO_H
#define DEMO_TEST_ENUM_DEMO_H
// C98 枚举
enum day {
    day1, day2
};

enum day1 {
    day11 = 10, day22 = 20
};

// c11 枚举 底层默认采用int实现
enum class day2 {
    day21, day22 = 20, day23 = 30
};

// 底层设置采用short实现
enum class day4 : short {
        day31, day32 = 20, day33 = 30
};

#endif //DEMO_TEST_ENUM_DEMO_H
