#include <iostream>
struct control_block
{
    int refcount = 0;
    // 추가로 자원에 대한 다양한 정보...(삭제자등)
};
template <typename T>
class Ptr
{
    T *obj;
    control_block *cb;

public:
    Ptr(T *p = nullptr) : obj(p)
    {
        cb = new control_block;
        cb->refcount = 1;
    }
    T *operator->() { return obj; }
    T &operator*() { return *obj; }
    ~Ptr(
        if (--(cb->refcount) == 0) { delete obj; 
        delete cb; })
        Ptr(const Prt &other) : obj{other.obj},
    cb{other.cb}
    {
        if (cb != nullptr)
        {
            ++cb->refcount;
        }
    }
};

int main()
{
    Ptr<int> p1 = new int;
    *p1 = 20;
    Ptr<int> p2 = p1;
}
