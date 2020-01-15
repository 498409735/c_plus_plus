#include <iostream>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

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
     int write_info(char*data){
         int size;
         size = write(this->fd,data,strlen(data));
         return size;
     }
     static void removeInstance(Singleton*p){
         if(instance==NULL){
             p = NULL;
             return;
         }else {
             delete instance;
             p = NULL;
             instance =NULL;
         }
     }

private:
     Singleton(){
         total++;
         fd = open("log.txt",O_CREAT|O_RDWR<0666);
         cout<<"fd = "<<fd<<endl;
         cout<<"single initial total="<<total<<endl;
     }
     Singleton(const Singleton&other){
         total++;
         cout<<"copy initail"<<endl;
     }
     ~Singleton(){
         total--;
         close(fd);
         cout<<"xigou total="<<total<<endl;
     }
    static int total;
    int fd;
    static Singleton*instance;
};
int Singleton::total = 0;
Singleton* Singleton::instance =NULL;
void * thread_fun1(void*arg){
    int len;
    Singleton*pThread1 = Singleton::getInstance();
    int i =5;
    while (i--) {
        len = pThread1->write_info("thread1");
        cout<<"thread1 w"<<len<<"byte  to log.txt"<<endl;
        sleep(1);
    }
    Singleton::removeInstance(pThread1);
    return NULL;
}
void *thread_fun2(void*arg){
    int len;
    Singleton*pThread2 = Singleton::getInstance();
    int i =5;
    while (i--) {
        len = pThread2->write_info("thread2");
        cout<<"thread2 w "<<len<<" byte  to log.txt"<<endl;
        sleep(1);
    }
    Singleton::removeInstance(pThread2);
    return NULL;
}
int main()
{
    pthread_t thread[2];
    pthread_create(&thread[0],NULL,thread_fun1,NULL);
    sleep(1);
    pthread_create(&thread[1],NULL,thread_fun2,NULL);
    sleep(1);
    Singleton*Pmain = Singleton::getInstance();
    int len;
    int i=10;
    while (i--) {
      len = Pmain->write_info("main");
      cout<<"main w "<<len<<" byte  to log.txt"<<endl;
      sleep(1);
    }
    Singleton::removeInstance(Pmain);
    return 0;
}
//class  Singleton
//{
//public:
//     static Singleton* getInstance(){
//         if(instance==NULL){
//             instance= new Singleton();
//         }
//         return instance;
//     }
//     static void removeInstance(){
//         if(instance==NULL){
//             return;
//         }else {
//             delete instance;
//             instance =NULL;
//         }
//     }

//private:
//     Singleton(){
//         total++;
//         cout<<"single initial total="<<total<<endl;
//     }
//     Singleton(const Singleton&other){
//         total++;
//         cout<<"copy initail"<<endl;
//     }
//     ~Singleton(){
//         total--;
//         cout<<"xigou total="<<total<<endl;
//     }
//    static int total;
//    static Singleton*instance;
//};
//int Singleton::total = 0;
//Singleton* Singleton::instance =NULL;
//int main()
//{
//    Singleton* pSingle1 = Singleton::getInstance();
//    Singleton* pSingle2 = Singleton::getInstance();
//    Singleton* pSingle3 = Singleton::getInstance();
//    cout<<"&pSingle1"<<pSingle1<<endl;
//    cout<<"&pSingle2"<<pSingle2<<endl;
//    cout<<"&pSingle3"<<pSingle3<<endl;
//    Singleton::removeInstance();
//    Singleton::removeInstance();
//    Singleton::removeInstance();
//    cout<<"&pSingle1"<<pSingle1<<endl;
//    cout<<"&pSingle2"<<pSingle2<<endl;
//    cout<<"&pSingle3"<<pSingle3<<endl;
//    return 0;
//}
