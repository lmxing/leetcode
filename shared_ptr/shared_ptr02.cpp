#include <iostream>
using namespace std;

shared_ptr<string> factory(const char* p){
    return make_shared<string>(p);
}

void use_factory(){
    shared_ptr<string> p = factory("helloworld"); 
    cout<<*p<<endl;　　　　　　　　　　//!离开作用域时，p引用的对象被销毁。

} 
shared_ptr<string> return_share_ptr()
{ 
　　shared_ptr<string> p = factory("helloworld"); 
　　cout<<*p<<endl; 
　　return p; 　　　　　　　　　　　　　　//!返回p时，引用计数进行了递增操作。 
} 　　　　　　　　　　　　　　　　　　　　 //!p离开了作用域，但他指向的内存不会被释放掉。 



int main() 
{ 
　　use_factory(); 
　　auto p = return_share_ptr(); 
　　cout<<p.use_count()<<endl; 
}
