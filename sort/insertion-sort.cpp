#include <iostream>
#include <ctime>
#include <iomanip>


void insertionSort(int, int*);

int main(){
int n,i;
std::cin>>n;
int *mas = new int [n];
for (i=0;i<n;i++){
    std::cin>>mas[i];
}
insertionSort(n, mas);
for (i=0;i<n;i++){
    std::cout<<mas[i]<<" ";
}
delete [] mas;
return 0;
}
void insertionSort (int n, int* mas) {
    int i,j,k,c;
for (i=1;i<n;i++){
    j=i-1;
    while ((mas[j]>mas[i])&&(j>=0)){
        j=j-1;
    }
    c=mas[i];
    for (k=i-1;k>j;k--){
        mas[k+1]=mas[k];
    }
    mas[j+1]=c;
}
}
