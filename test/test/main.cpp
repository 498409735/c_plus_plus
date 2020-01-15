#include <iostream>

using namespace std;
class Car
{
public:
    Car(const int wheel_tmp = 4,const string brand_tmp ="maX",const int price_tmp =10)
        :wheel(wheel_tmp),brand(brand_tmp),price(price_tmp){
        cout<<"new car added"<<endl;
    }
    ~Car(){
        cout<<"car delete"<<endl;
    }
    int getwheel()const{
        return this->wheel;
    }
    void setprice(const int price_tmp = 10 ){
        this->price = price_tmp;
    }
    inline void print(){
        cout<<"wheel="<<this->wheel<<" brand= "<<this->brand<<" price="<<this->price<<endl;
    }
private:
    int wheel;
    string brand;
    int price;
};
int main(){
    Car sanlun(3,"feiniao",30);
    cout<<"new car wheel ="<<sanlun.getwheel()<<endl;
    sanlun.print();
    sanlun.setprice(12);
    sanlun.print();
    return 0;
}
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
