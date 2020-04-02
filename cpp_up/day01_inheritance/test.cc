//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Person{
//  public:
//    Person(){
//      cout<<"Person()"<<endl;
//    }
//  private:
//    string _name="peter";
//    int _age=18;
//};
//
//class Student:public  Person{
//  public:
//    Student(){
//      cout<<"Student()"<<endl;
//    } 
//  private:
//    int _stuid;
//};
//
//int main(){
//  Student stu;
//  return 0;

//
//#include<iostream>
//#include<string>
//
//
//using namespace std;
//class Person
//{
//  public:
//      void Print()
//      {
//            cout << "name:" << _name << endl;
//                cout << "age:" << _age << endl;
//                  
//      }
//  protected:
//        string _name = "peter"; // 姓名
//          int _age = 18; // 年龄
//
//};
// // 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。
// //  //这里体现出了Student和Teacher复用了Person的成员。
// //   //下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。
// //    //调用Print可以看到成员函数的复用。
//class Student : public Person  //继承了Person 的内容
//{
//  protected:
//    int _stuid= 4170903; // 学号
//};
//
//class Teacher : public Person
//{
//  protected:
//    int _jobid=147632; // 工号
//};
//int main(){
//  Person p;
//  Student s;
//  Teacher t;
//  p.Print();
//  s.Print();
//  t.Print();
//  return 0;
//}
//


//#include<iostream>
//
//using namespace std;
//
//class Parent{
//
//  public:
//    void Print(){
//      cout<<"In Parent!"<<endl;
//    }
//    int sum=1;
//};
//
//class child1:public Parent{
//  public:
//    void Print(){
//      cout<<"In child1!"<<endl;
//    }
//    int sum=2;
//};
//int main(){
//  Parent p;
//  child1 c1;
//  p.Print();
//  c1.Print();
//  c1.Parent::Print();
//  cout<<"p.sum="<<p.sum<<endl;
//  cout<<"c1.sum="<<c1.sum<<endl;
//  cout<<"c1.Person::sum="<<c1.Parent::sum<<endl;
//  cout<<"c1.child1::sum="<<c1.child1::sum<<endl;
//  return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Person{
//  public:
//    void Add(){
//      cout<<"Add()"<<endl;
//    }
//  private:
//  protected:
//    //收到基类保护的成员函数或者成员变量
//    //在派生类中进行public访问的时候也访问不到
//    void Print(){
//      cout<<"Print()"<<endl;
//    }
//};
//
//class Student:private  Person{
//  public:
//
//    Person p;
//  private:
//  protected:
//
//};
//int main(){
// Student s;
// s.Add();
//  return 0;
//}


#include<iostream>

using namespace std;

class Person{

  public:
    Person(){
      cout<<"Person()"<<endl;
    }
    int num=10;
    void Print(){
      cout<<"Peron()"<<endl;
    }
};


class Student:protected Person{

  public:
    Student(){
      cout<<"Student()"<<endl;
    }
  private:
};
int main(){

  Student s;//先调用基类的构造函数再调用派生类的
  //cout<<s.num<<endl;
  //当派生类以public方式继承的时候,Person中的num可以被访问到
  //当以protected方式继承的时候就不可以方位基类中的public属性的变量和函数

  return 0;
}
