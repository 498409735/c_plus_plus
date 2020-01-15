#include <iostream>

using namespace std;

class  Singleton
{
public:
     static Singleton* getInstance(){
         if(instance==NULL){
             instance= new Singleton();
         }
         return instance;
     }
     static void removeInstance(){
         if(instance==NULL){
             return;
         }else {
             delete instance;
             instance =NULL;
         }
     }

private:
     Singleton(){
         total++;
         cout<<"single initial total="<<total<<endl;
     }
     Singleton(const Singleton&other){
         total++;
         cout<<"copy initail"<<endl;
     }
     ~Singleton(){
         total--;
         cout<<"xigou total="<<total<<endl;
     }
    static int total;
    static Singleton*instance;
};
int Singleton::total = 0;
Singleton* Singleton::instance =NULL;
int main()
{
    Singleton* pSingle1 = Singleton::getInstance();
    Singleton* pSingle2 = Singleton::getInstance();
    Singleton* pSingle3 = Singleton::getInstance();
    cout<<"&pSingle1"<<pSingle1<<endl;
    cout<<"&pSingle2"<<pSingle2<<endl;
    cout<<"&pSingle3"<<pSingle3<<endl;
    Singleton::removeInstance();
    Singleton::removeInstance();
    Singleton::removeInstance();
    cout<<"&pSingle1"<<pSingle1<<endl;
    cout<<"&pSingle2"<<pSingle2<<endl;
    cout<<"&pSingle3"<<pSingle3<<endl;
    return 0;
}
