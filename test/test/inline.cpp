#include <iostream>

using namespace std;

//template <typename T>
//T add(const T& a,const T&b){
//    cout<<"add"<<endl;
//    return a+b;
//}
//template <typename T>
//int compare(const T&a,const T&b){
//    if(a>b)return 1;
//    else if(a<b)return -1;
//    else return 0;
//}
//template <>
//int compare(const string&a,const string&b){
//    cout<<"stirng特化"<<endl;
//    if(a>b)return 1;
//    else if(a<b)return -1;
//    else return 0;
//}
//int main(){
//    int s1 = 2,s2 =3;
//    int s3;
//    s3 = add(s1,s2);
//    cout<<"add="<<s3<<endl;
//    cout<<"compare s1,s2 ="<<compare(s1,s2)<<endl;
//    double d1 = 2.3,d2 = 3.4;
//    double d3 = add(d1,d2);
//    cout<<"double add ="<<d3<<endl;
//    cout<<"compare d1,d2 ="<<compare(d2,d1)<<endl;
//    string str1 ="hello",str2 = "world";
//     cout<<"compare str1,str1 ="<<compare(str1,str1)<<endl;
//    cout<<"compare str1,str2 ="<<compare(str1,str2)<<endl;
//    return 0;
//}
//template <typename T1>
//void bubble(T1* t1,const int len){
//    int i,j;
//    T1 tmp;
//    T1*p = NULL;
//    for(i=0;i<len-1;i++){
//        p = t1;
//        for(j=0;j<len-1;j++){
//            if(*p>*(p+1)){
//                tmp = *p;
//                *p = *(p+1);
//                *(p+1) = tmp;
//            }
//            p++;
//        }
//    }
//}
//template <typename T1>
//void print(T1*t1,const int len){
//    for(int i =0;i<len;i++){
//        cout<<t1[i]<<" "<<flush;
//    }
//    cout<<endl;
//}
//int main(){
//    string num[5]={"hello","word","jaskl","xzmvkaue","oqeu"};
//    print(num,5);
//    bubble(num,5);
//    print(num,5);
//    return 0;
//}
class Complex
{
public:
//    Complex(const int r = 0,const int i=0):
//    real(r),img(i){
//        cout<<"构造了("<<this->real<<","<<this->img<<")"<<endl;
//    }
//    Complex (int r)
//    Complex(const Complex&other){
//        this->real = other.real;
//        this->img = other.img;
//        cout<<"copy 构造了("<<this->real<<","<<this->img<<")"<<endl;
//    }
    Complex operator + (const Complex &other){
        Complex tmp;
        tmp.real = this->real+other.real;
        tmp.img = this->img+other.img;
        return tmp;
    }
    Complex operator +(int&n){
        this->real +=n;
        return *this;
    }
    Complex(const int r = 0,const int i = 0)
        :real(r),img(i){
        cout<<"create ("<<real<<","<<img<<")"<<endl;
    }
    Complex(const Complex&other){
        real = other.real;
        img = other.img;
        cout<<"copy create"<<real<<","<<img<<")"<<endl;
    }
    operator int(){
        return int(this->real);
    }
    operator float(){
        return float(this->real);
    }
    void printinfo()const{
        cout<<"复数("<<this->real<<","<<this->img<<")"<<endl;
    }
private:
    int real,img;
};
int main(){
    Complex c1(1,1);
    Complex c2=Complex(20)+c1;

    c2.printinfo();
    cout<<int(c2)*10<<endl;
    cout<<int(c2)+10.2<<endl;
    Complex c3 = Complex(20);
//    Complex c3 = c1;
//    c2 = c1+20;
//    c2.printinfo();
    return 0;
}
//class Point
//{
//public:
//    Point(const T1 x_tmp =0,T2 y_tmp = 0):
//        x(x_tmp),y(y_tmp){
//        cout<<"构造了("<<this->x<<","<<this->y<<")"<<endl;
//    }
//    Point(const Point& other){
//        x= other.x;y = other.y;
//        cout<<"copy 构造了("<<this->x<<","<<this->y<<")"<<endl;
//    }
//    void prinPoit();
//private:
//    T1 x;
//    T2 y;
//};
//template<class T1,class T2>
//void Point<T1,T2>::prinPoit(){
//    cout<<"点坐标("<<this->x<<","<<this->y<<")"<<endl;
//}
//template<typename T1,typename T2>
//void test(T1 t1,T2 t2){
//    cout<<"模板化 t1 ="<<t1<<"t2="<<t2<<endl;
//}
//template<>
//void test(int t1,int t2){
//    cout<<"全特化 t1 ="<<t1<<"t2="<<t2<<endl;
//}
//template<typename T1>
//void test(T1 t1,int t2){
//    cout<<"偏特化 t1 ="<<t1<<"t2="<<t2<<endl;
//}
//int main(){
//    test<int,int>(10,20);
//    test(10,20);
//    test<float,int>(10.9f,10);
//    test<float,int>(10.9f,20);
////    Point<int,float> p1(1,1);

////    p1.prinPoit();
////    Point <int ,double>p2(2,2);
////    p2.prinPoit();
////    Point<char,int>p3('a',2);
////    p3.prinPoit();
////    return 0;
//}
//class  Point
//{
//public:
//     Point(const int x_tmp =0,const int y_tmp = 0)
//         :x(x_tmp),y(y_tmp) {
//         cout<<"构建点("<<this->x<<","<<this->y<<")"<<endl;
//     }
//     Point(const Point& other){
//         this->x = other.x;
//         this->y  = other.y;
//         cout<<"copy initial ("<<this->x<<","<<this->y<<")"<<endl;
//     }
//     inline void printPoit();
//private:
//     int x,y;
//};
//void Point::printPoit(){
//    cout<<"当前点坐标("<<this->x<<","<<this->y<<")"<<endl;
//}
//int main(){
//    Point p1(1,1);
//    p1.printPoit();
//    return 0;
//}
//class Car
//{
//public:
//    Car(const int wheel_tmp = 4,const string brand_tmp ="maX",const int price_tmp =10)
//        :wheel(wheel_tmp),brand(brand_tmp),price(price_tmp){
//        cout<<"new car added"<<endl;
//    }
//    ~Car(){
//        cout<<"car delete"<<endl;
//    }
//    int getwheel()const{
//        return this->wheel;
//    }
//    void setprice(const int price_tmp = 10 ){
//        this->price = price_tmp;
//    }
//    inline void print(){
//        cout<<"wheel="<<this->wheel<<" brand= "<<this->brand<<" price="<<this->price<<endl;
//    }
//private:
//    int wheel;
//    string brand;
//    int price;
//};
//int main(){
//    Car sanlun(3,"feiniao",30);
//    cout<<"new car wheel ="<<sanlun.getwheel()<<endl;
//    sanlun.print();
//    sanlun.setprice(12);
//    sanlun.print();
//    return 0;
//}
//class Boat;
//class Car{
//public:
//    Car(const string name_tmp,const int weight_tmp)
//        :name(name_tmp),weight(weight_tmp){
//        cout<<"car initial"<<endl;
//    }
//    ~Car(){
//        cout<<"car delete"<<endl;
//    }
//    friend int totalWeight(Car* car_tmp,Boat*boat_tmp);
//private:
//    string name;
//    int weight;
//};
//class Boat{
//public:
//    Boat(const string name_tmp,const int weight_tmp)
//        :name(name_tmp),weight(weight_tmp){
//        cout<<"Boat initial"<<endl;
//    }
//    ~Boat(){
//        cout<<"Boat delete"<<endl;
//    }
//    friend int totalWeight(Car* car_tmp,Boat*boat_tmp);
//private:
//    string name;
//    int weight;
//};
//int totalWeight(Car* car_tmp,Boat*boat_tmp){
//    int total = car_tmp->weight+boat_tmp->weight;
//    return  total;
//}
//int main()
//{
//    Car zs("zs",100);
//    Boat ls("ls",101);
//    cout<<totalWeight(&zs,&ls)<<endl;
//    return 0;
//}
