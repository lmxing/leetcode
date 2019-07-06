#include <iostream>
#include <boost/regex.hpp>
 
using namespace std;
int main(int argc, char* argv[])
{    //( 1 )   ((  3  )  2 )((  5 )4)(    6    )   
    //(\w+)://((\w+\.)*\w+)((/\w*)*)(/\w+\.\w+)?
    //^协议://网址(x.x...x)/路径(n个\字串)/网页文件(xxx.xxx)
    const char *szReg = "(\\w+)://((\\w+\\.)*\\w+)((/\\w*)*)(/\\w+\\.\\w+)?";
    const char *szStr = "http://www.cppprog.com/2009/0112/48.html";
 
    //练习代码...
        boost::regex reg( szReg );
    bool r=boost::regex_match( szStr , reg);
    cout << r << endl;
    return 1;   
}
