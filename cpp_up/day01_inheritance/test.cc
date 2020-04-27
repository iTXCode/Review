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


//#include<iostream>
//
//using namespace std;
//
//class Person{
//
//  public:
//    Person(){
//      cout<<"Person()"<<endl;
//    }
//    int num=10;
//    void Print(){
//      cout<<"Peron()"<<endl;
//    }
//};
//
//
//class Student:protected Person{
//
//  public:
//    Student(){
//      cout<<"Student()"<<endl;
//    }
//  private:
//};
//int main(){
//
//  Student s;//先调用基类的构造函数再调用派生类的
//  //cout<<s.num<<endl;
//  //当派生类以public方式继承的时候,Person中的num可以被访问到
//  //当以protected方式继承的时候就不可以方位基类中的public属性的变量和函数
//
//  return 0;
//}


#include<iostream>



using namespace std;
class Person{
  public:
      int _id=123;

};

class Student:public Person   //单继承
{
  public:
    const char *name="peter";

};
class Teacher : public Person  //单继承
{
    public:
    const char* sex="男";

};

class Assistant:public Student,public Teacher   //多继承
{
  public:
      int age=20;

};
//以上的所有继承关系构成了菱形继承
/*
       Person
       /   \
      /     \
   Student  Teacher
      \      /
       \    /
      Assistant
   菱形继承的二义性:Assistant类既继承自Student,又继承自Teacher
   当访问Student和Teacher共同的基类Person中的成员时产生二义性
   菱形继承的数据冗余:Assistant类既继承自Student,又继承自Teacher
   则Assistant中就有两份来自Person类中的资源 
 */

void test(){
  Assistant ast;
  std::cout << ast.name << std::endl;
  std::cout << ast.sex << std::endl;
  std::cout << ast.age << std::endl;
  //std::cout << ast._id << std::endl;//提示_id访问不明确
  std::cout <<ast.Student::_id << std::endl;
  std::cout << ast.Teacher::_id << std::endl;
  // 需要显示指定访问哪个父类的成员可以解决二义性问题，
  //但是数据冗余问题无法解决

}
int main(){
  test();
  return 0;
}


