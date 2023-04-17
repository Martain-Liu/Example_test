#include<iostream>
using namespace std;

class Task
{
public:
    void updatetask()
    {
        UpdateCommand();
    }
protected:
    virtual void UpdateCommand()
    {
        cout<<"Task_UpdateCommand" <<endl;
    }
};

class Bodypostask : public Task
{
public:

protected:
    virtual void UpdateCommand()
    {
        cout<<"Bodypostask_UpdateCommand" <<endl;
    }

};

void test01()
{
    void* body_pos_task ;

    body_pos_task = new Bodypostask;

    static_cast<Bodypostask*>(body_pos_task)->updatetask();
    //static_cast是一个强制类型转换操作符
}

int main()
{
    test01();
}