#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
void print(double& Ele){
    cout<<Ele<<",";
}
 
//模板函数Out遍历输出优先队列中的值
template<class T>void Out(priority_queue<T,deque<T>,less<T> >& p){
    while(!p.empty()){   //遍历优先队列
        cout<<p.top()<<",";
        p.pop();  //弹出队列
    }
    cout<<endl;
}
 
//和上一个模板函数基本一致，改变了优先队列排列元素的规则
template<class T>void OutG(priority_queue<T,deque<T>,greater<T> >& p){
    while(!p.empty()){   //遍历优先队列
        cout<<p.top()<<",";
        p.pop();  //弹出队列
    }
    cout<<endl;
}
 
int main()
{
    priority_queue<double,deque<double>,less<double> >p1,p2;
    p1.push(1.1);p1.push(2.2);p1.push(3.3);p1.push(4.4);
    p2=p1;
    Out(p1);
    priority_queue<double,deque<double>,greater<double> >p3;
    while(p2.size()){   //遍历优先队列p2
        p3.push(p2.top());
        p2.pop();
    }
    OutG(p3);
    return 0;
}