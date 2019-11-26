c11中使用前缀u表示char16_t字符常量和字符串常量
使用U表示char32_t常量

c11中字符串前面加R表示字符串是原始字符串，R"hello \n" 此时\n就不是转义字符

abort终止程序的时，是否刷新文件读写缓冲区取决于编译器的实现
exit终止程序时，会刷新文件读写缓冲区

auto_ptr、unique_ptr、shared_ptr
auto_ptr是C98提供的解决方案，C11已经废弃
智能指针用法：
auto_ptr<xxx_class> s_ptr(new xxx_class);
unique_ptr<xxx_class> s_ptr(new xxx_class);

std::shared_ptr<xxx_class> s_ptr = std::make_shared<xxx_class>();
shared_ptr<xxx_class> s_ptr(new xxx_class);

auto_ptr、unique_ptr采用的所有权模型，同一时刻一个指针只能被引用一次。


浮点数
d.dddE+n 将小数点向右移动N位
d.dddE~n 将小数点向左移动N位

cmake "CMakeLists.txt" 生成makefile
ccmake 添加编译配置
make 构建





