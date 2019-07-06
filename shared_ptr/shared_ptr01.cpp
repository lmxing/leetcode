#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
    public:
        Node() {}
        Node(int val) {
            value = val;
        }
    public:
        int value;
};

int main()
{　　
　　/*---------空指针------------*/
　　 shared_ptr<string> p1;
    if(!p1)                     　　　　//!默认初始化的智能指针中保存着一个空指针！并不是""空字符串
        cout<<"p1==NULL"<<endl;

　　/*---------初始化------------*/

　　shared_ptr<string> p2(new string); 
　　if(p2&&p2->empty()){ 　　　　　　　　//！需要注意的时empty时属于string的成员函数。 
　　　　*p2="helloworld"; 
　　　　cout<<*p2<<endl;
　　}

//    shared_ptr<int> pa = new int(1);//！error:不允许以暴露裸漏的指针进行赋值操作。

　　//一般的初始化方式
    shared_ptr<string> pint(new string("normal usage!"));
    cout<<*pint<<endl;

    //推荐的安全的初始化方式
    shared_ptr<string> pint1 = make_shared<string>("safe uage!");
    cout<<*pint1<<endl;

    Node * node = new Node();
    node->value = 2;
    cout<< node->value << endl;
    
    std::vector< std::shared_ptr<Node> > node_list;
    for (int i= 1; i < 5; ++i) {
        auto node_auto = make_shared<Node>();
        node_auto->value = i;
        node_list.push_back(node_auto);
    }
    for (auto iter = node_list.begin(); iter != node_list.end(); ++iter) {
        cout<< (*iter)->value << endl;
    }
    auto node01 = std::make_shared<Node>(22);
    cout<< node01->value<<endl;
    return 1;
}
