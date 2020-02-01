#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


//class Car{
//private:
//    string brand;
//    double price;
//public:
//    Car(const string brand_tmp = "benz",const double price_tmp=3.3)
//        :brand(brand_tmp),price(price_tmp){
//        cout<<"new car:"<<this->brand<<" "<<this->price<<endl;
//    }
//    void running(){
//        cout<<"my car "<<this->brand<<" "<<this->price<<"running"<<endl;
//    }
//    double get_price()const{
//        return this->price;
//    }
//};
//bool car_compare(const Car& c1,const Car& c2){
//    return c1.get_price()>c2.get_price();
//}
//int main(void){
//    vector<Car> str;
//    vector<Car>::iterator point;
//    str.push_back(Car("zs",1.1));
//    str.push_back(Car("ls",2.2));
//    str.push_back(Car("ws",3.3));
//    str.push_back(Car("zl",4.4));
//    cout<<"unsort"<<endl;
//    for(point=str.begin();point!=str.end();point++){
//        (*point).running();
//    }
//    cout<<endl;
//    sort(str.begin(),str.end(),car_compare);
//    cout<<"sort"<<endl;
//    for(point=str.begin();point!=str.end();point++){
//        (*point).running();
//    }
//    cout<<endl;
//}
/*********************************************************************
 *�޲ι��캯��,Ĭ�ϲ������캯��
 */
//class Date
//{
//public:
//    Date () {
//        year = 2010;
//        month = 6;
//        day = 17;
//    }
//    Date(const int year_tmp= 2010,const int month_tmp=6,const int day_tmp=17)//����Ĭ�ϲ���
//        :year(year_tmp),month(month_tmp),day(day_tmp){

//    }
//    void display(){
//        cout<<"taday:"<<this->year<<"/"<<this->month<<"/"<<this->day<<endl;
//    }
//    friend ostream& operator<<(ostream& out,Date& other);
//    int year;
//    int month;
//    int day;
//};
//ostream& operator<<(ostream& out,Date& other){
//        out<<other.year<<"/"<<other.month<<"/"<<other.day<<endl;
//        return  out;
//}
//int main(){
//    Date d1;
//    d1.display();
//    Date d2(2020,1,20);
//    d2.display();
//    cout<<d1<<d2;
//}
/*****************************************************************
 *�Զ��� string ��
 */
class mystring{
public:
    /***************ԭʼ����,�ɲ�������**************************/
    mystring(const char* pdata_tmp = NULL){
        if(pdata_tmp==NULL){
            this->pdata = new char[1]();
            cout<<"empty mystring initial"<<endl;
        }else {
            this->pdata = new char[strlen(pdata_tmp)+1];
            strcpy(this->pdata,pdata_tmp);
            cout<<"mystring initial:"<<this->pdata<<endl;
        }
    }
    /**************���ƹ���,���Ʋ���������һ��mystring ������ͬ�Ķ���***********/
    mystring(const mystring& other){
        // if(strcmp(this->pdata,other.pdata)==0)return;
        this->pdata = new char[strlen(other.pdata)+1];
        strcpy(this->pdata,other.pdata);
        cout<<"copy mystring initial:"<<this->pdata<<endl;
    }
    /*************'='����,�ַ���ֱ�Ӹ�ֵ****************************************/
    mystring& operator=(const char* pdata_tmp){
        delete []this->pdata;
        this->pdata = new char[strlen(pdata_tmp)+1];
        strcpy(this->pdata,pdata_tmp);
        cout<<"operator'='reload,char* to mystring:"<<this->pdata<<endl;
        return *this;
    }
    /**************'='����,����mystring����ֵ����ǰstring����*********************************/
    mystring& operator=(const mystring& other){
        delete []this->pdata;
        this->pdata = new char[strlen(other.pdata)+1];
        strcpy(this->pdata,other.pdata);
        cout<<"operator'='reload,string to string:"<<this->pdata<<endl;
        return *this;
    }
    /**************'+'����,����string���**********************************************/
    mystring operator+(const mystring &other){
        mystring tmp;
        delete [] tmp.pdata;
        tmp.pdata = new char[strlen(this->pdata)+strlen(other.pdata)+1];
        strcpy(tmp.pdata,this->pdata);
        strcat(tmp.pdata,other.pdata);
        return tmp;
    }
    char&operator[](const unsigned int i){
        if(i<strlen(this->pdata))return this->pdata[i];
        else {
            cerr<<"argument is over size or less than zero"<<endl;;
            return this->pdata[0];
        }
    }
    mystring& operator+=(mystring& other){
        char*tmp = new char[strlen(this->pdata)+strlen(other.pdata)+1]();
        strcpy(tmp,this->pdata);
        strcat(tmp,other.pdata);
        delete []this->pdata;
        this->pdata = tmp;
        return *this;
    }
    friend ostream& operator<<(ostream& out,mystring&other);
    friend istream& operator>>(istream& in,mystring&other);
    ~mystring(){
        delete [] pdata;
    }
    char* pdata;
};
ostream& operator<<( ostream& out,mystring&other){
    // if(other.pdata==NULL)return out;
    out<<other.pdata<<endl;
    return out;
}
istream& operator>>(istream& in,mystring&other){
    delete []other.pdata;
    other.pdata = new char[1024];
    in>>other.pdata;
    return in;
}
int main()
{
    cout<<"nomal initial-----------------"<<endl;
    mystring rose("hellow");
    cout<<rose;
    cout<<"------------------------------"<<endl;
    cout<<"copy initial------"<<endl;
    mystring jack=rose;
    cout<<jack;
    cout<<"------------------------------"<<endl;
    mystring zs;
    cout<<"operator = reload------"<<endl;
    zs = rose;
    zs ="hhhhhh";
    cout<<"------------------------------"<<endl;
    cout<<"operator + reload-------"<<endl;
    mystring zzl;
    zzl = jack+rose;
    cout<<zzl;
    cout<<"------------------------------"<<endl;
    zs = zs+rose+"hello world!!!"+jack;
    cout<<zs;
    cout<<"------------------------------"<<endl;
    cout<<"operator []reload"<<endl;
    cout<<zs[-1];
    cout<<"------------------------------"<<endl;
    cout<<"operator +=reload-------------"<<endl;
    zs+=jack;
    cout<<zs;
    cout<<"------------------------------"<<endl;
//    cin>>zs;
//    cout<<zs;
    return 0;
}

//template<typename T>
//int seqsearch(const T* list,int len,T key){
//    int i;
//    for(i =0;i<len;i++){
//        if(key==*(list+i))break;
//    }
//    if(i==len)return -1;
//    else return i;
//}
//int main()
//{
//    int i;
//    int inte[]={1,2,3,4,5,6};
//    double dou[]={1.1,2.2,3.3,4.4,5.5,6.6f};
//    char carac[]={'a','b','c','d','e','f'};
//    cout<<"ԭʼ����:"<<flush;
//    for(i=0;i<(int)(sizeof(inte)/sizeof(int));i++){
//        cout<<inte[i]<<" "<<flush;
//    }
//    cout<<endl;
//    cout<<"����key=5,Ԥ�ڷ���ֵ:4,ʵ�ʷ���ֵ:"<<seqsearch(inte,(int)(sizeof(inte)/sizeof(int)),5)<<endl;
//    cout<<endl;
//    cout<<"ԭʼ����:"<<flush;
//    for(i=0;i<(int)(sizeof(dou)/sizeof(double));i++){
//        cout<<dou[i]<<" "<<flush;
//    }
//    cout<<endl;
//    cout<<"����key=2.2,Ԥ�ڷ���ֵ:1,ʵ�ʷ���ֵ:"<<seqsearch(dou,(int)(sizeof(dou)/sizeof(double)),2.2)<<endl;
//    cout<<endl;
//    cout<<"ԭʼ����:"<<flush;
//    for(i=0;i<(int)(sizeof(carac)/sizeof(char));i++){
//        cout<<carac[i]<<" "<<flush;
//    }
//    cout<<endl;
//    cout<<"����key='f',Ԥ�ڷ���ֵ:f,ʵ�ʷ���ֵ:"<<seqsearch(carac,(int)(sizeof(carac)/sizeof(char)),'f')<<endl;
//    cout<<endl;
//    return 0;
//}


//int main(){
//    int i;
//    vector<int> str;
//    vector<int>::iterator point;
//    for(i=0;i<10;i++){
//        str.push_back(rand()%100);//�����������
//    }
//    cout<<std::left<<setw(10)<<"old:  "<<flush;
//    for(point=str.begin();point!=str.end();point++){
//        cout<<(*point)<<" "<<flush;
//    }
//    cout<<endl;
//    point = str.begin()+3;
//    str.insert(point,66);
//    cout<<std::left<<setw(10)<<"insert:"<<flush;
//    for(point=str.begin();point!=str.end();point++){
//        cout<<(*point)<<" "<<flush;
//    }
//    cout<<endl;

//    point = str.begin()+5;
//    str.erase(point);
//    cout<<std::left<<setw(10)<<"erase:"<<flush;
//    for(point=str.begin();point!=str.end();point++){
//        cout<<(*point)<<" "<<flush;
//    }
//    cout<<endl;
//}
//template <typename T>
//T* InsertOrder(T* str, int* len, T elem){
//    int i,j,tmp;
//    T* str_tmp = new T[(*len)+1];
//    for(i=0;i<*len;i++){
//        if(elem<str[i])break;   //����ֵ���뵽��i-1��λ��
//    }
//    if(i!=(*len)){
//        tmp = i;
//        for(j=0;j<tmp;j++){
//            str_tmp[j] = str[j];
//        }
//        str_tmp[tmp] = elem;     //����ֵ���뵽��i-1��λ��
//        for(j=tmp;j<(*len);j++){
//            str_tmp[j+1] = str[j];
//        }
//    }else{
//        for(j=0;j<(*len);j++){
//            str_tmp[j] = str[j];
//        }
//        str_tmp[(*len)] = elem;   //����ֵ���뵽ĩβ
//    }
//    delete []str;
//    (*len)++;
//    return str_tmp;
//}
//template <typename T>
//void sort(T*str,const int len){
//    T tmp;
//    for(int i=0;i<len-1;i++){
//        for(int j=0;j<len-1;j++){
//            if(*(str+j)>*(str+j+1)){
//                tmp         = *(str+j);
//                *(str+j)    = *(str+j+1);
//                *(str+j+1)  = tmp;
//            }
//        }
//    }
//}
//int main(){
//    int i;
//    int len =10;
//    int* str = new int[len];
//    for(i=0;i<10;i++){
//        str[i] =rand()%100;//�����������
//    }
//     cout<<"ԭʼ����:"<<flush;
//    for(i=0;i<len;i++){
//        cout<<str[i]<<" "<<flush;
//    }
//    cout<<endl;

//    sort(str,len);
//    cout<<"�����:  "<<flush;
//    for(i=0;i<len;i++){
//        cout<<str[i]<<" "<<flush;
//    }
//    cout<<endl;

//    str = InsertOrder(str,&len,66);
//    cout<<"�����  :"<<flush;
//   for(i=0;i<len;i++){
//       cout<<str[i]<<" "<<flush;
//   }
//   cout<<endl;
//   str = InsertOrder(str,&len,99);
//   cout<<"�����  :"<<flush;
//  for(i=0;i<len;i++){
//      cout<<str[i]<<" "<<flush;
//  }
//  cout<<endl;
//}
//bool mycompare(const int& a1,const int& a2){
//    return a1>a2;       //��д�ȽϺ���
//}
//int main(){
//    int i;
//    vector<int> str;
//    for(i=0;i<10;i++){
//        str.push_back(rand()%100);//�����������
//    }
//    cout<<"ԭʼ����:"<<flush;
//    for(i=0;i<10;i++){
//        cout<<str[i]<<" "<<flush;
//    }
//    cout<<endl;
//    sort(str.begin(),str.end(),mycompare);
//    cout<<"�����:  "<<flush;
//    for(i=0;i<10;i++){
//        cout<<str[i]<<" "<<flush;
//    }
//    cout<<endl;
//}
//class Stu
//{
//public:
//    Stu(const string name_tmp,const int id_tmp,const float score_tmp)
//    :name(name_tmp),id(id_tmp),score(score_tmp){
//        cout<<"new student added name:"<<this->name<<" "<<this->id<<" "<<this->score<<endl;
//    }
//    friend void set_score_class(const float score_tmp);
//    string name;
//    int id;
//    float score;
//};
//void set_score_class(const float score_tmp){
//    string class_flag;
//    class_flag = (score_tmp>=90)?"��":((score_tmp>=80)?"��":((score_tmp>=70)?"��":((score_tmp>=60)?"����":"������")));
//    cout<<"�ɼ�Ϊ:"<<class_flag<<endl;
//}
//int main(){
//    string name_in;
//    int id_in=190800;
//    float score_in;
//    vector<Stu*> str;
//    vector<Stu*>::iterator it;
//    char ch;
//    for(;;){
//        cout<<"���ѧ���밴1,�˳��밴����"<<endl;
//        cin>>ch;
//        if(ch=='1'){
//            cout<<"����ѧ������,����,�ÿո����"<<endl;
//            cin>>name_in>>score_in;
//            Stu* stu_tmp = new Stu(name_in,id_in+1,score_in);
//            str.push_back(stu_tmp);
//        }else break;
//    }
//    float total =0;
//    for(it=str.begin();it!=str.end();it++){
//        cout<<" "<<(*it)->name<<" "<<flush;
//        set_score_class((*it)->score);
//        total += (*it)->score;
//    }
//    cout<<"total ="<<total<<endl;
//    for(it=str.begin();it!=str.end();it++){
//          delete (*it);
//    }
//}
//template <typename T>
//void sort(T*str,const int len){
//    T tmp;
//    for(int i=0;i<len-1;i++){
//        for(int j=0;j<len-1;j++){
//            if(*(str+j)>*(str+j+1)){
//                tmp         = *(str+j);
//                *(str+j)    = *(str+j+1);
//                *(str+j+1)  = tmp;
//            }
//        }
//    }
//}
//int main(){
//    int i ;
//    cout<<"test for int:"<<endl;
//    int a[10] = {9,8,7,6,5,4,3,2,1,0};
//    for( i =0;i<10;i++){
//        cout<<*(a+i)<<" "<<flush;
//    }
//    cout<<endl;
//    sort(a,10);
//    for( i =0;i<10;i++){
//        cout<<*(a+i)<<" "<<flush;
//    }
//    cout<<endl;
//    cout<<"test for double:"<<endl;
//    double dou[10] = {0.9f,8.3f,0.7f,6.2f,5.1f,0.4f,0.3f,2.1f,1.2f,0.1f};
//    for( i =0;i<10;i++){
//        cout<<*(dou+i)<<" "<<flush;
//    }
//    cout<<endl;
//    sort(dou,10);
//    for( i =0;i<10;i++){
//        cout<<*(dou+i)<<" "<<flush;
//    }
//    cout<<endl;
//    cout<<"test for string:"<<endl;
//    string st[10] = {"hello","world","abc","bdc","cdb","follow","me","ellen","identify","stri"};
//    for( i =0;i<10;i++){
//        cout<<*(st+i)<<" "<<flush;
//    }
//    cout<<endl;
//    sort(st,10);
//    for( i =0;i<10;i++){
//        cout<<*(st+i)<<" "<<flush;
//    }
//    cout<<endl;
//}
/*********************************************************************
 *
 */
//class Employee{
//public:
//    Employee(const string name_tmp,const int id_tmp)
//        :name(name_tmp),ID(id_tmp){}
//    string name;
//    int ID;
//    virtual void pay() =0;
//};

//class  Technician:public Employee{
//public:
//    Technician(const string name_tmp,const int id_tmp)
//        :Employee(name_tmp,id_tmp){
//        cout<<"��������Ա:"<<this->name<<"\t"<<this->ID<<endl;
//    }
//    void pay() override{
//        cout<<"ÿ�η�1��"<<endl;
//    }
//};
//class SalesMan:public Employee{
//public:
//    SalesMan(const string name_tmp,const int id_tmp)
//        :Employee(name_tmp,id_tmp){
//        cout<<"��������Ա:"<<this->name<<"\t"<<this->ID<<endl;
//    }
//    void pay() override{
//        cout<<"ÿ�η�10��"<<endl;
//    }
//};
//void getSalary(Employee* em){//���������������ø��ഫ�θ���ȫ��Ч
//    em->pay();
//}
//int main(){
//    Technician jack("jack",190801);
//    SalesMan rose("rose",1909);
//    getSalary(&jack);
//    getSalary(&rose);
//    return 0;
//}
/*****************************************************************
 *�Զ���vector��
 */
//template<typename T>
//class myvector{
//public:
//    myvector(const int len_tmp = 1,const T num_tmp = 0)
//        :len(len_tmp),num(num_tmp){
//        if(len>0){
//            str = new T[len];
//            for(int i=0;i<len;i++){
//                str[i] = num;
//            }
//        }else {
//            cerr<<"lenth is less 0"<<endl;
//            return;
//        }
//    }
//    void insert(const int point,const T elem){
//        if(point>(this->len-1))return;
//        int i;
//        T* str_new = new T[this->len+1];
//        for(i=0;i<point;i++){
//            str_new[i] = str[i];
//        }
//        str_new[point] = elem;
//        for(i=point;i<this->len;i++){
//            str_new[i+1] = str[i];
//        }
//        this->len++;
//        delete [] str;
//        str = str_new;

//    }
//    void erease(const int point){
//        if(point>(this->len-1))return;

//        int i;
//        T* str_new = new T[this->len-1];
//        for(i=0;i<point;i++){
//            str_new[i] = str[i];
//        }
//        for(i=point;i<this->len-1;i++){
//            str_new[i] = str[i+1];
//        }
//        this->len--;
//        delete [] str;
//        str = str_new;
//    }
//    void revise(const int point,const T elem){
//        str[point] = elem;
//    }
//    int serch(const T elem){
//        int i;
//        for(i=0;i<this->len;i++){
//            if(str[i]==elem)break;
//        }
//        if(i==this->len)return -1;
//        else return i;
//    }
//    void push(T num_tmp){
//        T* newstr = new T[this->len+1];     //��������,���ڶ������¿ռ����ԭ�ռ�
//        for(int i=0;i<this->len;i++){       //�ɿռ����ݸ�ֵ���¿ռ�
//            newstr[i] = str[i];
//        }
//        newstr[this->len] = num_tmp;        //��ֵ���,���ȼ�1,�ͷžɿռ�,�滻
//        this->len++;
//        delete []str;
//        str = newstr;
//    }
//    T pop(){
//        T tmp;
//        tmp = str[this->len-1];
//        this->len--;
//        return tmp;
//    }
//    T& operator[](const int i){
//        return str[i];
//    }
//    void show(){
//        for(int i=0;i<this->len;i++){
//            cout<<str[i]<<" "<<flush;
//        }
//        cout<<endl;
//    }
//    ~myvector(){
//        delete []str;
//    }
//    int len;
//    T num;
//    T* str;
//};
//int main(){
//    cout<<"����int ����"<<endl;
//    myvector<int> in(5,66);
//    in.show();
//    in.insert(2,77);
//    in.show();
//    in.insert(5,77);
//    in.show();
//    in.erease(5);
//    in.show();
//    in.revise(2,44);
//    in.show();
//    cout<<in.serch(44)<<endl;
//    cout<<endl;

//    cout<<"����double ����"<<endl;
//    myvector<double> doub(5,1.23f);
//    doub.show();
//    doub.push(2.44f);
//    doub.show();
//    cout<<"ȡ��һ����ֵ:"<<doub.pop()<<endl;
//    doub.show();
//    cout<<endl;

//    cout<<"����char ����"<<endl;
//    myvector<char> ch(5,'x');
//    ch.show();
//    ch.push('y');
//    ch.show();
//    cout<<"ȡ��һ����ֵ:"<<ch.pop()<<endl;
//    ch.show();
//    cout<<endl;

//    cout<<"����string ����"<<endl;
//    myvector<string> str(5,"hello");
//    str.show();
//    str.push("world");
//    str.show();
//    str.insert(3,"hhh");
//    str.show();
//    str.erease(5);
//    str.show();
//    str.revise(2,"xxx");
//    str.show();
//    cout<<str.serch("xxx")<<endl;
//    cout<<"ȡ��һ����ֵ:"<<str.pop()<<endl;
//    str.show();
//    cout<<endl;

//}
/*****************************************************************
 *
 */
//class operation{
//protected:
//    double a;
//    double b;
//public:
//    void set_a(){
//        double a_tmp;
//        cout<<"������һ��������"<<endl;
//        cin>>a_tmp;
//        this->a = a_tmp;
//        cout<<"�����������Ϊ:"<<this->a<<endl;
//    }
//    void set_b( ){
//        double b_tmp;
//        cout<<"��������һ��������"<<endl;
//        cin>>b_tmp;
//        this->b = b_tmp;
//        cout<<"�����������Ϊ:"<<this->b<<endl;
//    }
////    virtual void getresult();
//};
//class add:public operation{
//public:
//    double getresult()const{
//        return this->a+this->b;
//    }
//};
//class minu:public operation{
//public:
//    double getresult()const{
//        return this->a-this->b;
//    }
//};
//class mutiply:public operation{
//public:
//    double getresult()const{
//        return this->a*this->b;
//    }
//};
//class divise:public operation{
//public:
//    double getresult()const{
//        if(this->b==0){
//            cout<<"divise number error"<<endl;
//            return 0;
//        }
//        return this->a/this->b;
//    }
//};

//int main(){
//    char ch;

//    cout<<"�����������"<<endl;
//    cin>>ch;

//    switch (ch) {
//    case '+':
//        {
//            add jack;
//            jack.set_a();
//            jack.set_b();
//            cout<<"���Ϊ:"<<jack.getresult()<<endl;
//            break;
//        }

//    case '-':
//    {
//        minu jack;
//        jack.set_a();
//        jack.set_b();
//        cout<<"���Ϊ:"<<jack.getresult()<<endl;
//        break;
//    }
//        break;
//    case '*':
//    {
//        mutiply jack;
//        jack.set_a();
//        jack.set_b();
//        cout<<"���Ϊ:"<<jack.getresult()<<endl;
//        break;
//    }
//        break;
//    case '/':
//    {
//        divise jack;
//        jack.set_a();
//        jack.set_b();
//        cout<<"���Ϊ:"<<jack.getresult()<<endl;
//        break;
//    }
//        break;
//    default:
//        break;
//    }
//}

//class Role
//{
//public:
//    Role(const string name_tmp,const int blood_tmp=100,const int damage_tmp = 2)
//        :name(name_tmp),blood(blood_tmp),damage(damage_tmp){
//        cout<<"�½���ɫ����:"<<this->name<<"\tblood:"<<this->blood<<"\tdamage:"<<this->damage<<"\t"<<flush;
//    }
//    virtual void attack() =0;
//    string name;
//    int blood;
//    int damage;
//};
//class Warrior:public Role
//{
//public:
//    Warrior(const string name_tmp,const int blood_tmp=100,const int damage_tmp = 2)
//        :Role(name_tmp,blood_tmp,damage_tmp){
//        cout<<"�½�սʿ"<<endl;
//    }
//    void attack() override{
//        cout<<"սʿ����һ��,�˺�:"<<this->damage<<endl;
//        cout<<"��ǰѪ��:"<<this->blood<<endl;
//    }
//};
//class Enchanter:public Role{
//public:
//    Enchanter(const string name_tmp,const int blood_tmp = 100,const int damage_tmp = 2)
//        :Role(name_tmp,blood_tmp,damage_tmp){
//        cout<<"�½�ħ��ʦ"<<endl;
//    }
//    void attack() override{
//        cout<<"ħ��ʦ����һ��,�˺�:"<<this->damage<<endl;
//        cout<<"��ǰѪ��:"<<this->blood<<endl;
//    }
//};
//int main(){
//    Warrior jack("jack",102,3);
//    Enchanter rose("rose",980,4);
//    jack.attack();
//    rose.attack();
//    return 0;
//}
//class Bird{
//public:
//    virtual void fly()=0;
//};
//class WildGoose:public Bird{
//public:
//    WildGoose(const string name)
//        :m_name(name){
//        cout<<"�����˸���"<<m_name<<endl;
//    }
//    void fly() {
//        cout<<"����"<<m_name<<"������"<<endl;
//    }
//private:
//    string m_name;
//};
//class Parrot: public Bird{
//public:
//    Parrot(const string name)
//        :m_name(name){
//        cout<<"����������"<<m_name<<endl;
//    }
//    void fly() {
//        cout<<"����"<<m_name<<"������"<<endl;
//    }
//private:
//    string m_name;
//};

//class BirdCage{
//public:
//    void addBird(Bird*brd_tmp){
////        this->brd[len++] = brd;
//        this->brd.push_back(brd_tmp);
//        len++;
//        cout<<"�ؽ�����һֻ�� len="<<len<<endl;
//    }
//    Bird*getBird(const int index){
////        cout<<"getbird len ="<<len<<endl;
//        return  this->brd[index];

//    }
//    int getlen()const{
//        return len;
//    }
//private:
//    static int len;
////    Bird*brd[10];
//    vector<Bird*> brd;
//};
//int BirdCage::len =0;
//int main(){
//    WildGoose WG1("wg1"),WG2("wg2");
//    Parrot P1("P1"),P2("P2");
//    BirdCage BC;

//    BC.addBird(&WG1);
//    BC.addBird(&WG2);
//    BC.addBird(&P1);
//    BC.addBird(&P2);
//    for(int i= 0;i<BC.getlen();i++){
//        BC.getBird(i)->fly();
//    }
//}
//int main(){
//    vector <string> a(10,"ab");
//    vector<string> ::iterator iter;
//    for(iter=a.begin();iter<a.end();iter++){
//        cout<<*iter<<" ";
//    }
//    cout<<endl;
//    iter = a.begin();
//    a.insert(iter+2,"cd");
//    for(iter=a.begin();iter<a.end();iter++){
//        cout<<*iter<<" ";
//    }
//    cout<<endl;
////    vector <char> a;
////    char ch;
////    while (1) {
////        cin>>ch;
////        cin.ignore();
////        if(ch=='q')break;
////        a.push_back(ch);
////        cout<<"a.capacity="<<a.capacity()<<"\t"<<a.size()<<endl;
////    }
//    exit(0);
//}

//    int b[]={1,2,3,4,5,6,7,8};

//    vector<int> a(b,b+8);
//    for(int i=0;i<(int)a.size();i++){
//        cout<<"0x"<<hex<<a.at(i)<<",";
//        cout<<"0x"<<dec<<a[i]<<",";
//    }
//    cout<<endl;
//    vector<int> c;
//    c.push_back(33);
//    cout<<"c.capacity="<<c.capacity()<<"\t"<<c.size()<<endl;
//    c.push_back(44);
//    cout<<"c.capacity="<<c.capacity()<<"\t"<<c.size()<<endl;
//    c.push_back(55);
//    cout<<"c.capacity="<<c.capacity()<<"\t"<<c.size()<<endl;
//    c.push_back(66);
//    cout<<"c.capacity="<<c.capacity()<<"\t"<<c.size()<<endl;
//    c.push_back(77);
//    cout<<"c.capacity="<<c.capacity()<<"\t"<<c.size()<<endl;
//}
/***************************************************************
 *
 */
//class Mystring{
//public:
//    Mystring(const char* str = NULL){
//        if(str==NULL){
//            pData = new char[1];
//        }else{
//            pData = new char[strlen(str)+1];
//            strcpy(pData,str);
//        }
//        cout<<"mystring initial"<<endl;
//    }
//    Mystring(const Mystring&other){
//        if(strcmp(this->pData,other.pData)==0)return;
//        this->pData = new char[strlen(other.pData)+1];
//        strcpy(this->pData,other.pData);
//        cout<<"copy string"<<endl;
//    }
//    char *getData()const{
//        cout<<this->pData<<endl;
//        return pData;
//    }
//    Mystring operator +(const Mystring&other){
//        Mystring tmp;
//        delete []tmp.pData;
//        int len = strlen(this->pData)+strlen(other.pData)+1;
//        tmp.pData = new char[len];
//        strcpy(tmp.pData,this->pData);
//        strcat(tmp.pData,other.pData);
//        return tmp;
//    }
//    Mystring&operator=(const Mystring&other){
//        strcpy(this->pData,other.pData);
//        return *this;
//    }
//    char operator[](int n){
//        return this->pData[n];
//    }
//    Mystring operator +=(const Mystring&other){
//        Mystring tmp;
//        delete []tmp.pData;
//        int len = strlen(this->pData)+strlen(other.pData)+1;
//        tmp.pData = new char[len];
//        strcpy(tmp.pData,this->pData);
//        strcat(this->pData,other.pData);
//        return tmp;
//    }
//    bool operator>(const Mystring&other){
//        if(strcmp(this->pData,other.pData)>0)return true;
//        else return false;
//    }
//    bool operator>=(const Mystring&other){
//        if(strcmp(this->pData,other.pData)<0)return false;
//        else return true;
//    }
//    bool operator<(const Mystring&other){
//        if(strcmp(this->pData,other.pData)<0)return true;
//        else return false;
//    }
//    bool operator<=(const Mystring&other){
//        if(strcmp(this->pData,other.pData)>0)return false;
//        else return true;
//    }
//    friend istream&operator>>(istream &in,Mystring&other);
//    friend ostream& operator<<(ostream&out,Mystring&other);
//    ~Mystring(){
//        cout<<"mystring delete"<<endl;
//        delete []pData;
//    }
//private:
//    char* pData;
//};
//ostream& operator<<(ostream&out,Mystring&other){
//    out<<other.pData<<endl;
//    return  out;
//}
//istream&operator>>(istream &in,Mystring&other){
//    delete []other.pData;
//    other.pData = new char[100];
//    in>>other.pData;
//    strcat(other.pData,"\n");
//    return in;
//}
//int main(){
//    Mystring st1;
//    cin>>st1;
//    cout<<st1;
//}

/*********************************************************
 *          file stream- infile or out file
 */
//class Stu
//{
//public:
//    Stu(const string name_tmp,const int num_tmp,const float score_tmp)
//        :name(name_tmp),num(num_tmp),score(score_tmp){
//        cout<<"student added.name:"<<this->num<<"\tnum:"<<this->num<<"\tscore:"<<this->score<<endl;
//    }
//    void show(){
//        cout<<"student info:"<<this->name<<"\t"<<this->num<<"\t"<<this->score<<endl;
//    }
//    void info_in(const string path_tmp){
//        string name_tmp;int num_tmp;float score_tmp;
//        cout<<"please input student info"<<endl;
//        cin>>name_tmp>>num_tmp>>score_tmp;
//        this->name = name_tmp;this->num = num_tmp;this->score = score_tmp;
//        cout<<"input info:"<<this->name<<"\t"<<this->num<<"\t"<<this->score<<endl;
//        ofstream into_file;
//        into_file.open(path_tmp);
//        into_file<<this->name<<this->num<<this->score;
//        into_file.close();
//    }
//private:
//    string name;
//    int num;
//    float score;
//};
//int main(){
//    string path ="./log.txt";
//    Stu jack("jack",1902,89.2);
//    jack.show();
//    jack.info_in(path);
//    return 0;

//}
//class STU{
//public:
//    STU(const int num_tmp,const string name_tmp,const float score_tmp)
//        :num(num_tmp),name(name_tmp),score(score_tmp){
//        cout<<"����ѧ��: "<<this->name<<" "<<this->num<<" "<<this->score<<endl;
//    }
//    void info_in(){
//        int num_tmp;
//        string name_tmp;
//        float score_tmp;
//        cout<<"��������������,ѧ��,�ɼ�"<<endl;
//        cin>>name_tmp>>num_tmp>>score_tmp;
//        cout<<"���������ϢΪ:\t"<<name_tmp<<"\t"<<num_tmp<<"\t"<<score_tmp<<endl;
//        ofstream outfile("E:\\Qt-pro\\c_plus_plus\\fstream\\fstream\\log.txt");
//        if(outfile.is_open()){
//            outfile<<name_tmp<<" "<<num_tmp<<" "<<score_tmp;
//        }else {
//            cerr<<"file in error"<<endl;
//        }
//        outfile.close();
//    }
//    void info_out(){
//        int num_tmp;
//        string name_tmp;
//        float score_tmp;
//        int i=0;
//        ifstream infile("E:\\Qt-pro\\c_plus_plus\\fstream\\fstream\\log.txt");
//        if(infile.is_open()){
//            while (!infile.eof()) {
//                cout<<i++<<endl;
//                infile>>name_tmp>>num_tmp>>score_tmp;
//                cout<<"��ȡѧ����ϢΪ:\t"<<name_tmp<<"\t"<<num_tmp<<"\t"<<score_tmp<<endl;
//            }

//         }else{
//            cerr<<"open error"<<endl;
//        }
//        infile.close();
//    }
//    int num;
//    string name;
//    float score;
//};
//int main(){
//    STU zhangsan(1908,"zhangsan",98.2);
//     zhangsan.info_in();
//     zhangsan.info_out();
//}
//int main(){
//    ofstream file1("E:\\Qt-pro\\c_plus_plus\\fstream\\fstream\\log.txt",ios_base::app);
////    file.open("E:\\Qt-pro\\c_plus_plus\\fstream\\fstream\\log.txt");
//    if(file1.is_open()){
//        cout<<"�ļ��ɹ���"<<endl;
//        file1<<"jack, "<<"M, "<<"22, "<<endl;
//    }else{
//        cout<<"δ�ܴ�"<<endl;
//    }

//    file1.close();
//    cout << "Hello World!" << endl;

//    ifstream file;
//    file.open("E:\\Qt-pro\\c_plus_plus\\fstream\\fstream\\log.txt");
//    if(file.is_open()){
//        string name;
//        char gender;
//        int age;
//        cout<<"���ļ��ɹ�..."<<endl;
//        file>>name>>gender>>age;
//        cout<<name<<"\t"<<gender<<"\t"<<age<<endl;
//    }else {
//        cerr<<"���ļ�ʧ��"<<endl;
//        return 0;
//    }
//    return 0;
//}


//int main()
//{
//    ofstream file("E:\\Qt-pro\\c_plus_plus\\fstream\\fstream\\log.txt",ios_base::app);
////    file.open("E:\\Qt-pro\\c_plus_plus\\fstream\\fstream\\log.txt");
//    if(file.is_open()){
//        cout<<"�ļ��ɹ���"<<endl;
//        file<<"jack "<<"M "<<"22 "<<endl;
//    }else{
//        cout<<"δ�ܴ�"<<endl;
//    }

//    file.close();
//    cout << "Hello World!" << endl;
//    return 0;
//}
