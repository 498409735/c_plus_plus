#include <iostream>

using namespace std;
class Boat;
class Car{
public:
    Car(const string name_tmp,const int weight_tmp)
        :name(name_tmp),weight(weight_tmp){
        cout<<"car initial"<<endl;
    }
    ~Car(){
        cout<<"car delete"<<endl;
    }
    friend int totalWeight(Car* car_tmp,Boat*boat_tmp);
private:
    string name;
    int weight;
};
class Boat{
public:
    Boat(const string name_tmp,const int weight_tmp)
        :name(name_tmp),weight(weight_tmp){
        cout<<"Boat initial"<<endl;
    }
    ~Boat(){
        cout<<"Boat delete"<<endl;
    }
    friend int totalWeight(Car* car_tmp,Boat*boat_tmp);
private:
    string name;
    int weight;
};
int totalWeight(Car* car_tmp,Boat*boat_tmp){
    int total = car_tmp->weight+boat_tmp->weight;
    return  total;
}
int main()
{
    Car zs("zs",100);
    Boat ls("ls",101);
    cout<<totalWeight(&zs,&ls)<<endl;
    return 0;
}
