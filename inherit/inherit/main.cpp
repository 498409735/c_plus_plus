#include <iostream>
#include <vector>

using namespace std;

//class animall
//{
//public:
//    animall(const string name_tmp)
//        :name(name_tmp){
//        cout<<"创建"<<this->name<<endl;
//    }
//    virtual void play() = 0;
//    string name;
//};
//class elephant:public animall
//{
//public:
//    elephant(const string name_tmp):animall(name_tmp){}
//    void play(){
//        cout<<this->name<<" play water spray!"<<endl;
//    }
//};
//class lion:public animall
//{
//public:
//    lion(const string name_tmp):animall(name_tmp){}
//    void play(){
//        cout<<this->name<<" play jump fire ring!"<<endl;
//    }
//};
//class dolphin:public animall
//{
//public:
//    dolphin(const string name_tmp):animall(name_tmp){}
//    void play(){
//        cout<<this->name<<" play swimming!"<<endl;
//    }
//};
//class trainer{
//public:
//    trainer(const string name_tmp)
//        :name(name_tmp),len(0){
//        cout<<"创建驯兽员"<<this->name<<endl;
//    }
//    void add_animal(animall* an){
//        this->str.push_back(an);
//        this->len++;
//        cout<<"添加"<<an->name<<endl;
//        cout<<"当前"<<this->len<<"只动物"<<endl;
//    }
//    void delete_animal(){
//        it = str.end()-1;
//        cout<<(*it)->name<<"删除"<<endl;
//        this->str.pop_back();
//        this->len--;
//        cout<<"当前"<<this->len<<"只动物"<<endl;
//    }
//    void play_all(){
//       for(it=str.begin();it!=str.end();it++){
//           (*it)->play();
//       }
//    }
//    string name;
//    int len;
//    vector<animall*> str;
//     vector<animall*> ::iterator it;
//};
//int main(){
//    lion lion("lion");
//    dolphin dolphin("dolphin");
//    elephant elephant("elephant");
//    trainer jack("jack");
//    jack.add_animal(&lion);
//    jack.add_animal(&dolphin);
//    jack.add_animal(&elephant);
//    jack.play_all();
//    jack.delete_animal();
//}

//class Stu
//{
//public:
//    Stu(const string name_tmp)
//        :name(name_tmp){
//        cout<<"创建一个学生:"<<this->name<<endl;
//    }
//    void examination(){
//        cout<<"let's have test"<<endl;
//    }
//    string name;
//};
//class stu_h :public Stu{
//public:
//    stu_h(string name_tmp)
//        :Stu(name_tmp){
//            cout<<"创建考神"<<endl;
//    }
//};
//class stu_l:public Stu
//{
//public:
//    stu_l(string name_tmp)
//        :Stu(name_tmp){
//        cout<<"创建渣渣"<<endl;
//    }
//    void examination(const stu_h name_tmp){
//        cout<<name_tmp.name<<"开始替"<<this->name<<"考试"<<endl;
//    }
//};
//int main(){
//    stu_h jack("jack");
//    stu_l rose("rose");
//    rose.examination(jack);
//}
//template <typename T>
//class Myarry{
//private:
//    T data[20];
//    int len;
//public:
//    Myarry();
//    T indexof(const int index);
//    void addvalue(const T value);
//};
//template <typename T>
//Myarry<T>::Myarry():len(0){
//    cout<<"array initila"<<endl;
//}
//template <typename T>
//T Myarry<T>::indexof(const int index){
//    return data[index];
//}
//template <typename T>
//void Myarry<T>::addvalue(const T value){
//    data[len] = value;
//    len++;
//}
//int main(){
//    Myarry<double> jack;
//    for(int i=0;i<10;i++){
//        jack.addvalue(i+0.12f);
//        cout<<"index i ="<<jack.indexof(i)<<endl;
//    }
//    return  0;
//}

//class Point
//{
//public:
//    Point(const int x_tmp,const int y_tmp)
//        :x(x_tmp),y(y_tmp){

//    }
//    int x,y;
//};
//class Fig{
//public:
//    Fig(){
//        cout<<"构建基本图形类"<<endl;
//    }
//    virtual void ondraw()=0;
//};
//class triangle:public Fig
//{
//public:
//    triangle(Point a_tmp,Point b_tmp,Point c_tmp)//三个点坐标,暂不考虑三点共线问题
//        :a(a_tmp),b(b_tmp),c(c_tmp) {
//        cout<<"triangle initial:"<<endl;
//    }
//    void ondraw() override{
//        cout<<"this is a triangle"<<endl;
//        cout<<"point a.x="<<this->a.x<<"a.y="<<this->a.y<<endl;
//        cout<<"point b.x="<<this->b.x<<"b.y="<<this->b.y<<endl;
//        cout<<"point c.x="<<this->c.x<<"c.y="<<this->c.y<<endl;
//    }
//    Point a;
//    Point b;
//    Point c;
//};
//class round:public Fig
//{
//public:
//    round(Point a_tmp,const int radiu_tmp = 1)//圆心,半径
//        :a(a_tmp),radiu(radiu_tmp) {
//        cout<<"triangle initial:"<<endl;
//    }
//    void ondraw() override{
//        cout<<"this is a round"<<endl;
//        cout<<"point a.x="<<this->a.x<<"a.y="<<this->a.y<<endl;
//        cout<<"randiu ="<<this->radiu<<endl;
//    }
//    Point a;
//    int radiu;
//};
//int main(){
//    triangle jack(Point(1,1),Point(2,3),Point(3,4));
//    round rose(Point(1,1),2);
//    jack.ondraw();
//    rose.ondraw();
//}
/*******************************************
 *          A
 *        B   C
 *          D
 */
//class A{
//public:
//    A(const int a_tmp):a(a_tmp){
//        cout<<"构造A"<<endl;
//    }
//    void fun(){
//        cout<<"class A fun"<<endl;
//    }
//    int a;
//};
//class B:virtual public A
//{
//public:
//    B(const int a_tmp,const int b_tmp):A(a_tmp),b(b_tmp){
//        cout<<"构造B"<<endl;
//    }
//    ~B(){
//        cout<<"析构B"<<endl;
//    }
//    int b;
//};
//class C:virtual public A
//{
//public:
//    C(const int a_tmp,const int c_tmp):A(a_tmp),c(c_tmp){
//        cout<<"构造C"<<endl;
//    }
//    ~C(){
//        cout<<"析构C"<<endl;
//    }
//    int c;
//};
//class D:public B,public C
//{
//public:
//    D(const int a_tmp,const int b_tmp,const int c_tmp,const int d_tmp)
//        :A(a_tmp),B(a_tmp,b_tmp),C(a_tmp,c_tmp),d(d_tmp){
//        cout<<"构造D"<<endl;
//    }
//    ~D(){
//        cout<<"析构D"<<endl;
//    }
//    int d;
//};
//int main(){
//    D dd(1,2,3,4);
//    dd.fun();
//}
/******************************************
 * V继承  A       B
 *        *     *
 *          * *
 *           C
*/
//class A
//{
//public:
//    A(const int a_tmp):a(a_tmp) {
//        cout<<"构造A"<<endl;
//    }
//     void play(){
//        cout<<"A play"<<endl;
//    }
//     void seta(const int a_tmp){
//        this->a = a_tmp;
//     }
//     int geta()const{
//        return this->a;
//     }
//     void print(){
//        cout<<"A::a"<<this->a<<endl;
//     }
////    virtual ~A(){
////        cout<<"析构A"<<endl;
////    }
//private:
//     int a;
//};
//class B
//{
//public:
//    B(const int b_tmp):b(b_tmp) {
//        cout<<"构造B"<<endl;
//    }
//    void setb(const int b_tmp){
//        this->b = b_tmp;
//    }
//    int geta()const{
//        return this->b;
//    }
//    void play(){
//        cout<<"B:play:"<<this->b<<endl;
//    }
////    virtual ~B(){
////        cout<<"析构B"<<endl;
////    }
//private:
//    int b;
//};
//class C:public A,public B
//{
//public:
//    C(const int a_tmp,const int b_tmp,const int c_tmp)
//        :A(a_tmp),B(b_tmp),c(c_tmp) {
//        cout<<"构造C"<<endl;
//    }
//    void play(){
//       cout<<"C:play"<<this->c<<endl;
//    }
//    ~C(){
//        cout<<"析构C"<<endl;
//    }
//private:
//    int c;
//};
//int main(){
//    C c(1,2,3);
//      c.play();
//    cout<<"hello"<<endl;
//    return 0;
//}
//class appliances
//{
//public:
//    appliances(int temp_t = 25):temp(temp_t){
//        cout<<"initial appliance temp ="<<temp<<endl;
//    }
//    virtual void changetemp() =0;
//    int temp;
//};
//class cooler:public appliances
//{
//public:
//    cooler(const int temp_t = 25):appliances(temp_t){}
//    void changetemp(){
//        this->temp--;
//       cout<<"cooler changetemp ="<<temp<<endl;

//    }
//};
//class warmer : public appliances
//{
//public:
//    warmer(const int temp_t = 25):appliances(temp_t){}
//    void changetemp(){
//        this->temp++;
//       cout<<"warmer changetemp ="<<temp<<endl;

//    }
//};
//class Conditional:public cooler,public warmer
//{
//public:
//    Conditional(const int temp_t = 25):cooler(temp_t),warmer(temp_t){}
//    void tempup(){
//        warmer::changetemp();
//    }
//    void tempdown(){
//        cooler::changetemp();
//    }
//};
//int main(){
//    Conditional air(23);
//    air.tempup();
//    air.tempdown();
//    return  0;
//}
//class Fig
//{
//public:
//    Fig(string name_tmp):figname(name_tmp){
//        cout<<"Fig initial:"<<figname<<endl;
//    }
//    virtual void ondraw() =0;
//    string figname;
//};
//class Point{
//public:
//   Point(int x_tmp = 0,int y_tmp =0):x(x_tmp),y(y_tmp){
//       cout<<"new point ("<<this->x<<","<<this->y<<")"<<endl;
//   }
//   ~Point(){
//       // cout<<"point delete"<<endl;
//   }
//   int x;
//   int y;
//};
//class Rectangle:public Fig{
//public:
//   Rectangle(Point& lt_tmp,Point& rb_tmp,string name_tmp):LTpoint(lt_tmp),RBpoint(rb_tmp),Fig(name_tmp){
//       cout<<"new rectangle initial:"<<figname<<endl;
//   }
//   ~Rectangle(){
//       cout<<"rectangle delete"<<endl;
//   }
//   void ondraw(){
//       int length = abs(this->LTpoint.x-this->RBpoint.x);
//       int high = abs(this->LTpoint.y-this->RBpoint.y);
//       cout<<"length ="<<length<<endl;
//       cout<<"high="<<high<<endl;
//   }
//   void set_LT(Point lt_tmp);
//   void set_RB(Point rb_tmp);
//   Point get_lt();
//   Point get_rb();
//   double area();
//private:
//   Point LTpoint;
//   Point RBpoint;
//};
//void Rectangle::set_LT(Point lt_tmp=(0,0)){
//   this->LTpoint = lt_tmp;
//}
//void Rectangle::set_RB(Point rb_tmp=(1,1)){
//   this->RBpoint = rb_tmp;
//}
//Point Rectangle::get_lt(){
//   Point tmp = this->LTpoint;
//   return tmp;
//}
//Point Rectangle::get_rb(){
//   Point tmp = this->RBpoint;
//   return tmp;
//}
//double Rectangle::area(){
//   int length = abs(this->LTpoint.x-this->RBpoint.x);
//   int high = abs(this->LTpoint.y-this->RBpoint.y);
//   double area = length* high;
//   return area;
//}
//int main(){
//   Point p1(1,1),p2(4,4);
//   Rectangle tom(p1,p2,"rectangle");
//   cout<<"area:"<<tom.area()<<endl;
//   tom.ondraw();

//   return 0;
//}
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
///*******************************************************************
// *    父类:    公有成员       保护成员        私有成员
// * 公有继承     类外访问       类内访问         父类接口访问
// * 保护继承     类内访问       类内访问         父类接口访问
// * 私有继承     类内访问        类内访问        父类接口访问
// * /
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
