#include<iostream>
using namespace std;

class Java
{
public:
    void header()
    {
        cout << "首页，公开课，登录，注册．．．(公共头部)" << endl;
    }
    void footer()
    {
        cout << "帮助　中心　交流　合作(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java python,,,（公共分类列表）" << endl;
    }
    void content()
    {
        cout << "Java学科视频" << endl;
    }
};

void test01()
{
    cout << "Java下载视频页面如下：" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
}

int main()
{
    test01();
}