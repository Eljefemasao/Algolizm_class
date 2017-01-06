//insertiosort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n,*data,test,limit;

int inputdata();
int insertionsort(int,int);
int printdata();



int main(){
  printf("\n===================================\n");
  printf("\n*insertionsort*\n");
  inputdata();
  clock_t start,end;
  start = clock();
  insertionsort(1,n);
  end = clock();
  printdata();
  printf("\n");
  printf("\nTime of sort = %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
  printf("\n====================================\n");
}
int insertionsort(p,q)
  int p,q;
  {
    int i,j,c;
    for(j=p+1;j<=q;j++){
      c=data[j];i=j;
      while(i>p &&data[i-1]>c){
	data[i]=data[i-1]; i=i-1;
      }
      data[i]=c;
    }
    return 0;
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
  printf("Please fill in maxmum of random numbers\n");
  scanf("%d",&limit);
  srand(1);
  printf("Would you display an elements on the screan ?Yes = 1 No = 2\n");
  scanf("%d",&test);
  if( test == 1)printf("\nDisplay an elements\n");
  else printf("\nDon't display on screan\n");
  
  for(i=1; i<=n; i++){
    data[i] = rand()%limit+1;
    if(test == 1){
      printf("/%3d",data[i]);
      if(i%5 == 0) printf("/\n");
    }
  }
  return 0;
}


int printdata(){
  int i;
  printf("\n");
  printf("\nAll data was sorted\n");
  if(test == 1){
    for(i=1;i<=n;i++){
      printf("/%3d",data[i]);
      if(i%5 == 0) printf("/\n");
    }
  }
  free(data);
  return 0;

}



  
  //挿入法のプログラム例
