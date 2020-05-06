### 快速排序

#### 1.在要排序的区间内选择一个基准值

- 具体方法:

> - 1.选择区间最后边这个数array[right]

#### 2.遍历整个区间,做一些数据交换,
- 达到的效果:比基准值小的数放在基准值左侧
- 比基准值大的数放在基准值右侧

#### 3.分治算法(把一个问题变成两个同样的小问题)

- 将区间[left,right]分成下面两个区间==(div:基准值)==
> - 1.[left,div-1]        
> - 2.[div+1,right]

#### 4.分治算法用递归(或者非递归)

- [ ] 终止条件(两个)
> - 1.分出来的区间没有数 分出的区间 size==0
> - 2.分出来的小区间已经有序了,区间size==1;

##### Pation()部分

- 用于将区间中的值进行分割(以基准值为界进行大小分割)

##### 方法一:(hoare法)
```cpp
int Partion(int* array,int left,int right){
  int begin=left;
  int end=right;  //不能从right-1开始

  while(begin<end){
    while(begin<end && array[begin]<=array[right]){
      begin++;
      //在遍历过程中对大于基准值的元素进行定位
      //此处的array[begin]<=array[right]中的"=" 必须存在
      //如果不存在的话会造成基准值右边区间的死循环
    }
    

    while(begin<end && array[end]>=array[right]){
      end--;
      //在遍历过程中对小于基准值的元素进行定位
    }

    if(begin!=end){  
      Swap(array+begin,array+end); 
    }//当begin和end两个数相同的时候,两者指向相同的值,所以不需要交换
  }

  Swap(array+begin,array+right);
    //返回当前基准值所在位置,
    return begin;
}


void _QuickSort(int *array,int left,int right){
 //终止条件:size==0 || size==1
 //left ==right 区间内还剩一个数
 //left > right 区间内没有数
  if(left==right){
    return ;
  }
  if(left>right){
    return;
  }

  int div;//比基准值小的放其左边,大的放到后面去,基准值所在的下标
  div=Partion(array,left,right);//遍历array[left,right]区间,把夏普的放左,大的放右面
  _QuickSort(array,left,div-1);//分治解决左边的小区间
  _QuickSort(array,div+1,right);//分治解决右边的小区间
}
```

##### 方法二:(填坑法)

- 1.从left到begin都比基准值小
- 2.从end到right都比基准值大
- 3.直到begin和end相遇
- 4.最后把基准值和较大部分的第一个交换

```cpp
int  Partion_wakeng(int *array,int left,int right){
  int begin=left;
  int end=right;

  int flag=array[right]; //保存基准值,用来挖坑腾空间
  while(begin<end){

    while(begin<end && array[begin]<= flag){
      begin++;
    }

    //右侧坑
    array[end]=array[begin];

    while(begin<end && array[end] >= flag ){
      end--;
    }
   //左侧坑
   array[begin]=array[end];
  } 
  array[begin]=flag;
  return begin;
}

void _QuickSort_wakeng(int *array,int left,int right){
 //终止条件:size==0 || size==1
 //left ==right 区间内还剩一个数
 //left > right 区间内没有数
  if(left==right){
    return ;
  }
  if(left>right){
    return;
  }

  int div;
  //比基准值小的放其左边,大的放到后面去,基准值所在的下标
  div=Partion_wakeng(array,left,right);
  //遍历array[left,right]区间,把夏普的放左,大的放右面
  _QuickSort_wakeng(array,left,div-1);//分治解决左边的小区间
  _QuickSort_wakeng(array,div+1,right);//分治解决右边的小区间
}


//快速排序
//要排序的区间是array[left,right]

void QuickSort_wakeng(int* array,int size){
  _QuickSort_wakeng(array,0,size-1);
}

```

##### 方法三:前后下标版本

```cpp
int Partion_Point(int *array,int left,int right){
  int d=left;

  for(int i=left;i<right;i++){
    if(array[i]<array[right]){
      Swap(array+d,array+i);
      d++;
    }
  }
  Swap(array+d,array+right);
  return d;
}



void _QuickSort_Point(int *array,int left,int right){
 //终止条件:size==0 || size==1
 //left ==right 区间内还剩一个数
 //left > right 区间内没有数
  if(left==right){
    return ;
  }
  if(left>right){
    return;
  }

  int div;
  //比基准值小的放其左边,大的放到后面去,基准值所在的下标
  div=Partion_Point(array,left,right);
  //遍历array[left,right]区间,把夏普的放左,大的放右面
  _QuickSort_Point(array,left,div-1);//分治解决左边的小区间
  _QuickSort_Point(array,div+1,right);//分治解决右边的小区间
}


//快速排序
//要排序的区间是array[left,right]

void QuickSort_Point(int* array,int size){
  _QuickSort_Point(array,0,size-1);
}
```

###### 选择基准值办法
- 只有最右侧(或者最左侧)选为基准值很容易情况(数列有序 或者 逆序)
###### 其他选择基准值的办法
- 1.三数取中
mid=(left+right)/2
array[left],array[mid],array[right]
选择大小是中间的一个数为基准值
选出基准值之后,还是把基准值交换到最右侧/左侧
再Partition
- 2.随机,从left 到 right 随机选一个下标
