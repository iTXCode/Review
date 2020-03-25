#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;


const char* Strstr(const char* dest,const char* substr);
class String{
 friend ostream& operator<<(ostream& _cout,const String &s );
  

  public:
  typedef char* iterator;
  typedef const char*  const_iterator;  
  String(const char* str="")
      :_size(strlen(str))
      ,_capacity(_size)
      ,_str(new char[_size+1])
    {
      strcpy(_str,str);
    }

    ~String(){
      if(_str){
        _size=0;
        _capacity=0;
        delete[] _str;
        _str=nullptr; 
      }
    }

    void Swap(String& s){
     
      swap(_size,s._size);
      swap(_capacity,s._capacity);
      swap(_str,s._str);
    }


    String(const String& s)
    :_size(0)
     ,_capacity(0)
    ,_str(nullptr)
    {
      String tmp(s._str);
      Swap(tmp);
    }

    //赋值操作符重载【现代写法】
    
    String& operator=(String s){
      Swap(s);
      return *this;
    }

    const char* c_str(){
      return _str;
    }

    void PushBack(const char c){
     // if(_size==_capacity){
     //   //需要增容了
     //   size_t newc=(_capacity==0?15:_capacity*2);
     //   //扩容逻辑：
     //   //如果检测到初始空间为0,增容为15byte
     //   //否则增容两倍
     //   Reserve(newc);
     // }
     // //尾插
     // _str[_size++]=c;
     // _str[_size]='\0';
     
      Insert(_size,c);
    }

    void Reserve(size_t n){
      if(n>=_capacity){
        //增容
        char* tmp=new char(n+1);
        strcpy(tmp,_str);
        delete[] _str;
        _str=tmp;
        _capacity=n;
      }
    }


    //尾删
    void PopBack(){
      //要先判断原串是否为有效的
      assert(_size>0);
      _str[--_size]='\0';
    }
   
    //尾部添加内容
    void Append(const char* str){
     // size_t sz=strlen(str);
     // if(_size+sz>_capacity){
     //   Reserve(_size+sz);
     // }
     // strcpy(_str+_size,str);
     // _size+=sz;
     //
    Insert(_size,str);
    }
  
    //函数功能:
    //若指定的长度小于原有的长度则不做改变
    //若指定的长度等于原有的长度也不改变原串
    //若指定的长度大于原有的长度用指定的字符将多出的空间进行填充
    void Resize(size_t n,char c='\0'){
      assert(n>0);
      if(n>_capacity){
        Reserve(n);
      } 
      if(n>_size){
       // for(int i=_size;i<n;i++){
       //   _str[i]=c;
       // }
       

        memset(_str+_size,c,n-_size);
        //参数一:指定拷贝位置
        //参数2:指定拷贝内容 
        //参数3:指定拷贝大小
      }

      //走到这里的时候不管指定长度与原串的长度,都要将有效长度的最后一位指定为'\0'
      _size=n;
      _str[_size]='\n';
    }
   
    //函数功能
    //指定下标处插入指定字符
    void Insert(size_t pos,const char c){
      //检查插入位置下标的合法性 
      assert(pos<=_size);
      //检查空间是否已经满了
      if(_size==_capacity){
        //空间满了需要扩容了
        size_t newc=(_capacity==0?15:_capacity*2);
        Reserve(newc);
      }

      //执行到这里说明位置合法
      size_t end=_size;
      while(end>pos){
        //需要将数据往后挪动
        _str[end]=_str[end-1];
        --end;
      }

      //在pos插入c
      _str[pos]=c;
      _str[++_size]='\0';//防止内存访问越界
    }
   

    //函数功能:
    //在指定位置插入某个字符串
    
    void Insert(size_t pos,const char* str){
      //检查位置的合法性
      assert(pos<=_size && pos>=0);
      int size=strlen(str);

      if(_size+size>_capacity){
        //插入的位置查过本身的容量
       Reserve(_size+size);
      }

      //从后往前挪动数据
      size_t end=_size+size;
      while(end>pos+size+1){
        //第一个挪动的为'\0'
        _str[end]=_str[end-size];
        --end;
      }

      //从pos位置拷贝str
      for(int i=0;i<size;++i){
        _str[i+pos]=str[i];
      }
      _size+=size;
    }

    void Erase(size_t pos,size_t len){
      //检查释放位置的合法性
      assert(pos<_size&&pos>=0);
      //从pos位置开始向后的字符都要删除
      if(pos+len>_size){
        //位置超过了有效字符的下标
        //说明该位置之后的可以全部删除
        _size=pos;
        _str[_size]='\0';
      }else{
        //执行到此处说明要删除最大下标小于字符串的        //有效位置的下标
        
        size_t start=pos+len;
        while(start<_size){
          _str[pos]=_str[start];
          ++start;
        }
        _size-=len;
        _str[_size]='\0';
      }
    }

    String& operator+=(const String& s){
      Append(s._str);
      return *this;
    }

    String& operator+=(const char c){
      PushBack(c);
      return *this;
    }

    String& operator+=(const char* str){
      Append(str);
      return *this;
    }

    size_t find(const char c){
      for(int i=0;i<(int)_size;++i){
        if(_str[i]==c)
          return i;
    }
      return npos;
    }

    size_t find(size_t pos,const char*str){
    (void) pos;//消除未使用警告
      const char* start=Strstr(_str,str);

      if(start)
        return start-_str;
      else 
        return npos;
    }

    size_t Size(){
      return _size;
    }

    char& operator[](size_t pos){
      //防止内存访问越界
      assert(pos<_size);
      return _str[pos];
    }

    //只读接口,不允许修改.返回const引用
    const char& operator[](size_t pos)const{
      //防止内存访问越界
      assert(pos<_size);
      return _str[pos];
    }

    iterator begin(){
      return _str;
    }

    iterator end(){
      return _str+_size;
    }

    const_iterator begin()const 
    {
      //返回第一个元素的地址
    return _str;
    }

    const_iterator end()const{
      return _str+_size;
    }


  private:
    size_t _size;
    size_t _capacity;
    char *_str;
    static const size_t npos;
};

const size_t String::npos=-1;

const char* Strstr(const char* dest,const char* substr){
  while(*dest){
    //首先判断第一个字符是否相等
    if(*substr==*dest){
      const char* child=substr;
      const char* father=dest;

      while(*child&&*father){
        if(*child!=*father)
          break;
        child++;
        father++;
      }

      //匹配成功,返回substr在dest中的其实位置
      if(*child=='\0'){
        return dest;
      }
    }
    dest++;
  }
  return nullptr;
}

ostream& operator<<(ostream& _cout,const String& s){
  for(auto& e: s){
    _cout<<e;
  }
  return _cout;
}

void PrintString(const String &s ){
  for(auto& e:s){
    cout<<e;  
  }
  cout<<endl;
}



void Testiterator(const String &s){
  String::const_iterator sit=s.begin();
  cout<<"test iterator:";
  while(sit!=s.end()){
    cout<<*sit<<" ";
    ++sit;
  }
  cout<<endl;
}

void TestAdd(String& s){
  s+="hello!";
  Testiterator(s);
}


int main(){
  String s="aaaaaa";
  s.Append("str"); 
  cout<<s[7]<<endl;
  s.Append("str1");
  s.PushBack('$');
  cout<<s.begin()<<endl;
  cout<<s.end()<<endl;
  cout<<s<<endl;
  PrintString(s);
  Testiterator(s);

  return 0;
}
