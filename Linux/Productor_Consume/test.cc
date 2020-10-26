#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_product=PTHREAD_COND_INITIALIZER;
//互斥量和条件变量的静态初始化

struct msg{
  int num;
  msg *next;
};
msg* head=nullptr;
msg *mp=nullptr;

void* Producter(void* arg){
  (void)arg;
  while(1){
    mp=(msg*)malloc(sizeof(msg));
    mp->num=rand()%100+1;
    printf("----producted----%d\n",mp->num);

    pthread_mutex_lock(&mutex);
    mp->next=head;
    head=mp;
    pthread_mutex_unlock(&mutex);

    pthread_cond_signal(&has_product);
    sleep(rand()%3);
  }

  return NULL;
}

void* Consumer(void* arg){
  (void)arg;
  while(1){
    pthread_mutex_lock(&mutex);
    while(head==nullptr){
      pthread_cond_wait(&has_product,&mutex);
    }

    //有内容可取
    mp=head;
    head=mp->next;
    pthread_mutex_unlock(&mutex);
    printf("----consumer----%d\n",mp->num);
    free(mp);
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t ptid,ctid;

  pthread_create(&ptid,NULL,Producter,NULL);
  pthread_create(&ctid,NULL,Consumer,NULL);

  pthread_join(ptid,NULL);
  pthread_join(ctid,NULL);
  return 0;
}
