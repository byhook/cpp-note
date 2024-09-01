
# UniquePtr

1、在任何一个给定的时刻，只能有一个指针管理内存

2、当指针超出作用域时，内存将自动释放

3、该类型指针不可Copy，只能Move

# 创建方式

1、通过已有裸指针创建
2、通过new来创建
3、通过std::make_unique创建(推荐)

unique_ptr可以通过get()获取地址
