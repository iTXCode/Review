//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Person
//{
//  public:
//    Person(const char* name = "peter")
//      : _name(name)
//      {
//        cout << "Person()" << endl;
//
//      }
//
//    Person(const Person& p)
//      : _name(p._name)
//    {
//      cout << "Person(const Person& p)" << endl;
//
//    }
//
//    Person& operator=(const Person& p)
//    {
//      cout << "Person operator=(const Person& p)" << endl;
//      if (this != &p)
//        _name = p._name;
//
//      return *this;
//
//    }
//
//    ~Person()
//    {
//      cout << "~Person()" << endl;
//
//    }
//  protected:
//    string _name; // 姓名
//
//};
//class Student : public Person
//{
//  public:
//    //完成父类对象的初始化，子类的构造函数先调用基类的构造函数，
//    //再执行子类的构造函数
//    //必须先调用父类的构造函数和拷贝构造进行初始化
//    Student(const char* name, int num)
//      : Person(name)
//        , _num(num)
//  {
//    cout << "Student()" << endl;
//  }
//    //如果子类不显示的调用父类的拷贝构造，则调用父类的默认构造函数
//    //如果子类显示的调用父类类的拷贝构造，就不会再去调用父类的默认构造
//    Student(const Student& s) 
//      //(Student *this,const Student &s)还发生了指针的欺骗。
//      : Person(s)//此处是一个切片的操作，调用父类的拷贝构造
//        , _num(s._num)
//  {
//    cout << "Student(const Student& s)" << endl;
//  }
//    //父类的成员变量可以直接在子类的赋值运算符重载函数长中直接赋值
//    //如果是编译器默认生成的子类赋值运算符重载函数，会调用父类的
//    //赋值运算符重载函数进行赋值
//    Student& operator = (const Student& s)
//    {
//      cout << "Student& operator= (const Student& s)" << endl;
//      if (this != &s)
//      {
//        //operator =(s);不可以这样写
//        Person::operator =(s);//此处调用的this指针为子类对象的this指针
//        _num = s._num;
//      }
//      return *this; //若if中没有显示的写出父类的赋值运算符重载的话，
//      //子类中不会调用父类的赋值运算符重载
//    }
//    //析构函数:不允许显示调用父类的析构函数
//    ~Student()
//    {
//      //~Person();坑:同名隐藏，编译器底层对析构函数的名字做了修改为了使用多条调不动
//      //编辑器将~Student()与~Person()都修改成了~destructor
//      //Person::~Person(); //可以调动
//      cout << "~Student()" << endl;
//    }
//  protected:
//    int _num; //学号
//};
//void Test()
//{
//  Student s1("jack", 18);
//  Student s2(s1);
//  Student s3("rose", 17);
//  s1 = s3;
//}
//int main(){
//  Test();
//  return 0;
//}


#include<iostream>
#include<string>

using namespace std; 

class Person{
  public:
    Person(const char* name="peter")
      :_name(name)
      {
        cout<<"Person()"<<endl;
      }
    Person(const Person& p)
      :_name(p._name)
    {
      cout<<"Person(const Person&)"<<endl;
    }

    Person& operator=(const Person& p){
      cout<<"person& operator=(const Person&)"<<endl;
      if(this!=&p){
        _name=p._name;
      }

      return *this;
    }

    ~Person(){
      cout<<"~person()"<<endl;
    }
  private:
    string _name;
};

class Student:public Person{

  public:
    Student(const char* name,int num)
      :Person(name)
       ,_num(num)
  {
    cout<<"Student()"<<endl;
  }

    Student(const Student& s)
    :Person(s)
    ,_num(s._num)
    {
      cout<<"Student(const Student&)"<<endl;
    }


    Student& operator=(const Student& s){
      cout<<"Student& operator=(const Student&)"<<endl;

      if(this!=&s){
        Person::operator=(s);
        _num=s._num;
      }
      return *this;
    }

    ~Student(){
      //Person::~Person();
      cout<<"~Student()"<<endl;
    }
  private:
    int _num;
};

void Test(){
  Person p("jack");//构造函数
  Person p1=p;  //析构函数

}

void Test1(){
  Student s1("jack",8);
  Student s2(s1);
  Student s3("rose",17);
  s1=s3;
}

int main(){
  Test();
  Test1();
  return 0;
}





