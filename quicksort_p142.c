/*
  quicksort
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n,*data,test,limit;

int inputdata();
int quicksort(int,int);
int printdata();
int swap(int,int);
int insertionsort(int,int);


int main(){
  printf("======================================\n");
  printf("\n*quicksort*\n");
  inputdata();
  clock_t start,end;
  start = clock();
  data[0] = -999999999;
  quicksort(1,n);
  end = clock();
  printdata();
  printf("\n");
  printf("\nTime of sort = %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
  printf("\n=======================================\n");

}

int find_median3(left,right)
     int left, right;
{
  int center,p;
  center = (left+right)/2;
  if(data[left]>data[center])swap(left,center);
  if(data[left]>data[right])swap(left,right);
  if(data[center]>data[right])swap(center,right);
  
  p= data[center];
  swap(center,right);
  return(p);
}
int partition(left,right,q)
     int left,right,q;
{
  int i,j;
  i = left -1; j=right;
  do{
    do i= i+1; while(data[i]<q);
    do j= j-1; while(data[j]>q);
  }while(i<j);
  swap(i,right);
  return(i);
}

int inputdata(){
  int i;
  printf("Please fill in number of data\n");
  scanf("%d",&n);
  data = (int *)malloc(sizeof(int)*n);
  if(data==NULL){
    printf("There are no memory\n");
    exit(1);
  }
  printf("Please fill in maximum of random numbers\n");
  scanf("%d",&limit);
  srand(1);
  printf("Would you display an elements on the screan? Yes=1 No=2\n");
  scanf("%d",&test);
  if(test == 1) printf("\nDisplay an elements\n");
  else printf("\nDon't display an elements\n");
  
  for(i=1; i<=n; i++){
    data[i] = rand()%limit+1;
    if(test == 1){
      printf("/%3d",data[i]);
      if(i%5==0) printf("/\n");
    }
  }
  return 0;
}
int quicksort(left,right)
     int left, right;
{
  int cutoff,privot,i;
  cutoff=10;
  if((right-left)<cutoff)insertionsort(left,right);
  else{
    privot = find_median3(left,right);
    i= partition(left,right,privot);
    quicksort(left,1);
    quicksort(i+1,right);
  }
  return 0;
}

int insertionsort(p,q)
  int p,q;
  {
    int i,j,c;
    for(j=p+1;j<=q;j++){
      c=data[j]; i=j;
      while(i>p&&data[i-1]>c){
	data[i]=data[i-1];i=i-1;
      }
      data[i] = c;
    }
    return 0;
  }

 
int swap(x,y){
    int tmp;
    tmp = data[x];
    data[x] = data[y];
    data[y] = tmp;
    return 0;
  }

int printdata(){
  int i;
  printf("\n");
  printf("\nAll data was sorted\n");
  if(test ==1){
    for(i=1;i<=n;i++){
      printf("/%3d",data[i]);
      if(i%5 == 0) printf("/\n");
    }
  }
  free(data);
  return 0;

}



//クイックソートのプログラム例
