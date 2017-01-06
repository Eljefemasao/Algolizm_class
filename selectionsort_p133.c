//selectionsort



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//#define MAXN 100

//int A[MAXN],n;
int n,*data,test,limit;

int inputdata();
int selectionsort(int,int);
int swap(int,int);
int printdata();


int main(){
  printf("============================================\n");
  
  printf("\n*selectionsort*\n");
  inputdata();
  clock_t start,end;
  start = clock();
  selectionsort(1,n);
  end = clock();
  printdata();
  printf("\n");
  printf("\nTime of sort = %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
  printf("\n============================================\n");


}

int selectionsort(p,q)
     int p,q;
{
  int i,j,cmin;
  for(j=p; j<=q; j++){
    cmin  = j;
    for(i=j+1;i<=q;i++)
      if(data[cmin]>data[i]) cmin = i;
    swap(j,cmin);
  }
  return 0;
}

int inputdata(){
  int i;
  printf("Please fill in number of data\n");
  scanf("%d",&n);
  data = (int *)malloc(sizeof(int)*n);
  if(data == NULL){
    printf("There are no memory which can secure\n");
    exit(1);
  }
  
  printf("Please fill in maxmum of random numbers\n");
  scanf("%d",&limit);
  srand(1);
  
  printf("Would you display an elements on the scerean?? Yes = 1 or No = 0 \n");
  scanf("%d",&test);
  if(test == 1){
    printf("\n");
    printf("Display an elements \n");
  }else{
    printf("\n");
    printf("Don't display an elementsn\n");
  }
  for(i=1;i<=n;i++){
    data[i]=rand()%limit+1;
    if(test == 1){
      printf("/%3d",data[i]);
      if(i%5==0) printf("/\n");

    }

  }
  return 0;
}


int printdata(){
  int i;
  printf("\n");
  printf("\nAll data was sorted\n");
  if(test == 1){
    
    for(i = 1;i<=n;i++){
    printf("/%3d",data[i]);
  if(i%5 == 0) printf("/\n");
  }
}
free(data);
return 0;
}


int swap(x,y){
  int tmp;
  
  tmp = data[x];
  data[x] = data[y];
  data[y] = tmp;
  return 0;
}

