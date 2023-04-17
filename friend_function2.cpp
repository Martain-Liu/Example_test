#include<iostream>
#include<string>
using namespace std;

class Building
{
    friend class GoodGay;//重点语句
public:
    Building();

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

class GoodGay
{
public:
    GoodGay();
    void visit();
    Building *building;
};
/************************************/
GoodGay::GoodGay()
{
    building = new Building;
}

Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}
/************************************/

void GoodGay::visit()
{
    cout<<"正在访问：" <<building->m_SittingRoom <<endl;
    cout<<"正在访问：" <<building->m_BedRoom <<endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
}

int main()
{
    test01();
}