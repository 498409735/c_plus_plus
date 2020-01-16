#include <iostream>

using namespace std;

class Fig
{
public:
    Fig(string name_tmp):figname(name_tmp){
        cout<<"Fig initial:"<<figname<<endl;
    }
    virtual void ondraw() =0;
    string figname;
};
class Point{
public:
   Point(int x_tmp = 0,int y_tmp =0):x(x_tmp),y(y_tmp){
       cout<<"new point ("<<this->x<<","<<this->y<<")"<<endl;
   }
   ~Point(){
       // cout<<"point delete"<<endl;
   }
   int x;
   int y;
};
class Rectangle:public Fig{
public:
   Rectangle(Point& lt_tmp,Point& rb_tmp,string name_tmp):LTpoint(lt_tmp),RBpoint(rb_tmp),Fig(name_tmp){
       cout<<"new rectangle initial:"<<figname<<endl;
   }
   ~Rectangle(){
       cout<<"rectangle delete"<<endl;
   }
   void ondraw(){
       int length = abs(this->LTpoint.x-this->RBpoint.x);
       int high = abs(this->LTpoint.y-this->RBpoint.y);
       cout<<"length ="<<length<<endl;
       cout<<"high="<<high<<endl;
   }
   void set_LT(Point lt_tmp);
   void set_RB(Point rb_tmp);
   Point get_lt();
   Point get_rb();
   double area();
private:
   Point LTpoint;
   Point RBpoint;
};
void Rectangle::set_LT(Point lt_tmp=(0,0)){
   this->LTpoint = lt_tmp;
}
void Rectangle::set_RB(Point rb_tmp=(1,1)){
   this->RBpoint = rb_tmp;
}
Point Rectangle::get_lt(){
   Point tmp = this->LTpoint;
   return tmp;
}
Point Rectangle::get_rb(){
   Point tmp = this->RBpoint;
   return tmp;
}
double Rectangle::area(){
   int length = abs(this->LTpoint.x-this->RBpoint.x);
   int high = abs(this->LTpoint.y-this->RBpoint.y);
   double area = length* high;
   return area;
}
int main(){
   Point p1(1,1),p2(4,4);
   Rectangle tom(p1,p2,"rectangle");
   cout<<"area:"<<tom.area()<<endl;
   tom.ondraw();

   return 0;
}
//class myfrection{
//public:
//    myfrection(const int a_tmp,const int b_tmp):a(a_tmp),b(b_tmp){
//        cout<<"生成分数:"<<this->a<<"/"<<this->b<<endl;
//    }
//    void print(){
//        cout<<"当前分数为:"<<this->a<<"/"<<this->b<<endl;
//    }
//    void reduc(){
//        int i ;
//        int biger = (this->a>this->b)?this->a:this->b;
//        int smaller = (this->a<this->b)?this->a:this->b;
//        for( i = smaller;i>0;i--){
//            if(biger%i==0&&smaller%i==0)break;
//        }
//        this->a /= i;
//        this->b /= i;
//        cout<<"约分之后为:"<<this->a<<"/"<<this->b<<endl;
//    }
//    int a,b;
//};
//int main(){
//    myfrection fre(36,81);
//    fre.print();
//    fre.reduc();
//    fre.print();
//}

//class instru
//{
//public:
//    instru(const string name_tmp):name(name_tmp){
//        cout<<"构造了乐器:"<<this->name<<endl;
//    }
//    virtual void play() =0;
//    string name;
//};
//class piano:public instru
//{
//public:
//    piano(const string name_tmp):instru(name_tmp){
//        cout<<"构造了钢琴"<<endl;
//    }
//    void play(){

//        cout<<"piano::play"<<endl;
//    }
//};
//class newpiano:public piano
//{
//public:
//    newpiano(const string name_tmp):piano(name_tmp){
//        cout<<"构造了新钢琴"<<endl;
//    }
//    void play(){
//        cout<<"newpiano::play...."<<endl;
//    }
//};
//void tune(instru&t){
//    t.play();
//}
//int main(){

//    piano a("yamaha");
//    tune(a);
//    newpiano newp("bentian");
//    tune(newp);
//    cout<<""<<endl;
//}
//class Ball
//{
//public:
//    Ball() {}
//    virtual void play(){
//        cout<<"Ball::play----"<<endl;
//    }
//};
//class football:public Ball{
//public:
//    football(){
//        cout<<"构造了一个足球"<<endl;
//    }
//    void play(){
//        cout<<"football::play----"<<endl;
//    }
//};
//class Volleyball:public Ball{
//public:
//    Volleyball(){
//        cout<<"构造了一个足球"<<endl;
//    }
//    void play(){
//        cout<<"Volleyball::play----"<<endl;
//    }
//};
//void tune(Ball&b){
//    b.play();
//}
//int main(){
//    football a;
//    tune(a);
//    Volleyball v;
//    tune(v);
//    cout<<""<<endl;
//    return 0;
//}

//class A
//{
//public:
//    A() {}
//    int a =100;

//};
//class B:public A
//{
//public:
//    int b=222;
//};
//int main(){
///***************************************/
////    A* pa = new B;                    //派生类指针赋值基类可行
////    cout<<"pa-a="<<pa->a<<endl;
///*************************************/
//    B b;
//    A a1 = b;                   //派生类赋值基类
//    cout<<"a1.a"<<a1.a<<endl;
////    A a2;
////    B b2 = a2;                //基类无法赋值给派生类
////    cout<<"b2.a="<<b2.a<<endl;
///*********************************************/
////    A a2;
////    B &refa = a2;                     //派生类无法引用基类
////    cout<<"refa.a="<<refa.a<<endl;
//      B b2;
//      A &refa = b2;                     //基类可引用派生类
//      cout<<"refa.a="<<refa.a<<endl;
////    delete pa;
//}
//class People{
//public:
//     string m_name;
//    People(string name_tmp,string gender_tmp,int age_tmp =12)
//        :m_name(name_tmp),m_gender(gender_tmp),m_age(age_tmp){
//        cout<<"create people"<<endl;
//    }
//    void set_age(const int& age_tmp){
//        this->m_age = age_tmp;
//    }
//    int get_age(){
//        return this->m_age;
//    }
//    string get_name()const{
//        return this->m_name;          //protect
//    }
//    string get_gender()const{
//        return this->m_gender;          //protect
//    }
//protected:
//    string m_gender;
//private:
//    int m_age;
//};
//class STU:private People
//{
//public:
//    STU(string name_tmp,string gender_tmp,int age_tmp=12,double score_tmp =98.2)
//        :People(name_tmp,gender_tmp,age_tmp),score(score_tmp){
//        cout<<"stu added"<<endl;
//        cout<<"----name:"<<this->m_name<<endl;
//        cout<<"----gender:"<<this->m_gender<<endl;
//        cout<<"----score:"<<this->score<<endl;
////        cout<<"----age:"<<this->m_age<<endl;
//    }
//    string stu_get_name()const{
//        cout<<__FUNCTION__<<","<<__LINE__<<endl;
//        return m_name;
//    }
//    string stu_get_gender()const{
//        cout<<__FUNCTION__<<","<<__LINE__<<endl;
//        return m_gender;          //protect
//    }
//    float stu_get_score()const{
//        cout<<__FUNCTION__<<","<<__LINE__<<endl;
//        return score;
//    }
//    int stu_get_age(){
//        cout<<__FUNCTION__<<","<<__LINE__<<endl;
//        return  get_age();
//    }
//private:
//    double score;
//};


//int main()
//{
//    STU stu1("jack","M",23,89.2);

///********************************************/
//    cout<<stu1.stu_get_name()<<endl;
//    cout<<stu1.stu_get_gender()<<endl;
//    cout<<stu1.stu_get_age()<<endl;
//    cout<<stu1.stu_get_score()<<endl;
//    return 0;
//}
//class People{
//public:
//     string m_name;
//    People(string name_tmp,string gender_tmp,int age_tmp =12)
//        :m_name(name_tmp),m_gender(gender_tmp),m_age(age_tmp){
//        cout<<"create people"<<endl;
//    }
//    void set_age(const int& age_tmp){
//        this->m_age = age_tmp;
//    }
//    int get_age(){
//        return this->m_age;
//    }
//    string get_name()const{
//        return this->m_name;          //protect
//    }
//    string get_gender()const{
//        return this->m_gender;          //protect
//    }
//protected:
//    string m_gender;
//private:
//    int m_age;
//};
//class STU:protected People
//{
//public:
//    STU(string name_tmp,string gender_tmp,int age_tmp=12,float score_tmp =98.2)
//        :People(name_tmp,gender_tmp,age_tmp),score(score_tmp){
//        cout<<"stu added"<<endl;
//        cout<<"----name:"<<this->m_name<<endl;
//        cout<<"----gender:"<<this->m_gender<<endl;
//        cout<<"----score:"<<this->score<<endl;
////        cout<<"----age:"<<this->m_age<<endl;
//    }
////error    int get_age()const{         //父类私有成员不能继承
////error        return this->m_age;      //private
////error    }
//    string get_name()const{
//        cout<<__FUNCTION__<<","<<__LINE__<<endl;
////        cout<<__FUNCTION__<<People::get_name()<<endl;
//        return this->m_name;
//    }
//    string stu_get_gender()const{
//        cout<<__FUNCTION__<<","<<__LINE__<<endl;
//        return this->m_gender;          //protect
//    }
//    float stu_get_score()const{
//        cout<<__FUNCTION__<<","<<__LINE__<<endl;
//        return this->score;
//    }
//private:
//    float score;
//};


//int main()
//{
//    STU stu1("jack","M",23,89.2);
////    stu1.set_age(13);
////    cout<<"age:"<<stu1.get_age()<<endl;
////     cout<<stu1.get_age()<<endl;     //私有成员    不继承   不访问
////    cout<<stu1.m_name<<endl;           //公有成员    继承    任意访问
///*    cout<<stu1.m_gender<<endl;       //保护成员    继承    类内访问
//    cout<<stu1.get_name()<<endl;
//    cout<<stu1.get_gender()<<endl;
//********************************************/
//    cout<<stu1.get_name()<<endl;
//    cout<<stu1.stu_get_gender()<<endl;
//    cout<<stu1.stu_get_score()<<endl;
//    return 0;
//}
//class People{
//public:
//     string m_name;
//    People(string name_tmp,string gender_tmp,int age_tmp =12)
//        :m_name(name_tmp),m_gender(gender_tmp),m_age(age_tmp){
//        cout<<"create people"<<endl;
//    }
//    void set_age(const int& age_tmp){
//        this->m_age = age_tmp;
//    }
//    int get_age(){
//        return this->m_age;
//    }
//protected:
//    string m_gender;
//private:
//    int m_age;
//};
//class STU:public People
//{
//public:
//    STU(string name_tmp,string gender_tmp,int age_tmp=12,float score_tmp =98.2)
//        :People(name_tmp,gender_tmp,age_tmp),score(score_tmp){
//        cout<<"stu added:"<<this->m_name<<" "<<" "<<this->m_gender<<" "<<this->score<<endl;
//    }
////error    int get_age()const{         //父类私有成员不能继承
////error        return this->m_age;      //private
////error    }
//    string get_gender()const{
//        return this->m_gender;          //protect
//    }
//    float get_score()const{
//        return this->score;
//    }
//private:
//    float score;
//};


//int main()
//{
//    STU stu1("jack","M",23,89.2);
//    stu1.set_age(13);
//    cout<<"age:"<<stu1.get_age()<<endl;
////     cout<<stu1.get_age()<<endl;     //私有成员    不继承   不访问
//    cout<<stu1.m_name<<endl;           //公有成员    继承    任意访问
////    cout<<stu1.m_gender<<endl;       //保护成员    继承    类内访问
//    cout<<stu1.get_gender()<<endl;
//    cout<<stu1.get_score()<<endl;
//    return 0;
//}
