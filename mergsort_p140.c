/*
 mergesort
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n,*data1,test,limit;

int inputdata();
int merge_sort(int ,int);
int merge(int,int,int);
int printdata();


int main(){
  printf("\n==================================\n");
  printf("\n*mergesort*\n");
  inputdata();
  clock_t start,end;
  start = clock();
  merge_sort(1,n);
  end = clock();
  printdata();
  printf("\n");
  printf("\nTime of sort = %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
  printf("\n===================================\n");
  
}

int merge_sort(p,r)
     int p,r;
{
  int q;
  if(p<r){
    q = (p+r)/2;
    
    merge_sort(p,q);
    merge_sort(q+1,r);
    merge(p,q,r);
  }
  return 0;
}


int inputdata(){
  int i;
  printf("\nPlease fill in number of data\n");
  scanf("%d",&n);
  data1 = (int*)malloc(sizeof(int)*n);
  if(data1 == NULL){
    printf("\nThere are no memory\n");
    exit(1);
  }
  printf("Please fill in maxmum of random numbers\n");
  scanf("%d",&limit);
  srand(1);
  
  printf("Would you display an elements on the screan? Yes=1 No=2\n");
  scanf("%d",&test);
  if(test == 1) printf("\nDisplay an elements on the screan\n");
  else printf("\nDon't display an elements\n");
  
  for(i=1;i<=n;i++){
    data1[i] = rand()%limit+1;
    if(test == 1){
      printf("/%3d",data1[i]);
      if(i%5==0) printf("/\n");
    }

  }
  return 0;

}

int merge(p,q,r)
     int p,q,r;
{

  int i,j,k,*data2;
  data2 = (int*)malloc(sizeof(int)*n);
  if(data2 == NULL){
    printf("\nThere are no memory\n");
    exit(1);
  }
  i=p; j=q+1;
  for(k=p;k<=r;k++){
    if((j>r)||((i<=q)&&(data1[i]<=data1[j]))){
      data2[k] = data1[i]; i=i+1;
    }else{
      data2[k] = data1[j]; j=j+1;
    }
  }
  for(k=p;k<=r;k++) data1[k] = data2[k];
  free(data2);
  return 0;
}

int printdata(){
  int i;
  printf("\n");
  printf("\nAll data was sorted\n");
  if(test==1){
    for(i=1;i<=n;i++){
      printf("/%3d",data1[i]);
      if(i%5 == 0) printf("/\n");
    }
  }
  free(data1);
  return 0;
}

    
  
  //マージソートのプログラム例
