#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	string arr[50];
	char str []="3x^2+2x-1";
    char *ptr;
  
  ptr = strtok (str,"-+");
  int i = 0;
  while (ptr != NULL)
  {
  	arr[i] = ptr;
    cout<<"\n"<<arr[i];
    ptr = strtok (NULL, "-+");
    i++;
  }
  return 0;
}
