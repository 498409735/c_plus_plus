#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

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
//    in.push(77);
//    in.show();
//    cout<<"ȡ��һ����ֵ:"<<in.pop()<<endl;
//    in.show();
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
