#include <iostream>

using namespace std;

class  Singleton
{
public:
     static Singleton &getInstance() {
        static Singleton instance;
        return instance;
     }
     ~Singleton(){
         total--;
         cout<<"xigou total ="<<total<<endl;
     }

private:
     Singleton(){
         total++;
         cout<<"gouzao total="<<total<<endl;
     }
     Singleton(const Singleton&other){
         total++;
         cout<<"copy total="<<endl;
     }
     static int total;
};
int Singleton::total = 0;
int main()
{
    Singleton ref;
    cout<<"ref ="<<&ref<<endl;
    Singleton &ref1 = Singleton::getInstance();
    Singleton &ref2 = Singleton::getInstance();
    Singleton &ref3 = Singleton::getInstance();
    cout<<"&ref1 ="<<&ref1<<endl;
    cout<<"&ref2 ="<<&ref2<<endl;
    cout<<"&ref3 ="<<&ref3<<endl;
    return 0;
}
