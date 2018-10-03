#include<stdio.h>

int main()
{
  char *str = "abcdabcdfsssewwl";
  char *first = str;
  int arr[27] = {0};
  int i = 0;
  for(;*str != '\0';str++)
  {
    i = *str-'a';
    arr[i]++;

  }
  str = first;
  for(;*str!='\0';str++)
  {
    if(arr[*str-'a'] == 1)
    {
      printf("%c\n",*str);
      break;
    }
  }
  for(i = 0;i<27;i++)
  {
    int res = arr[i];
    if(res != 0)
    {
      while(res--)
      {
        printf("%c",i+'a');
      }
    }
  }
  printf("\n");
  printf("\n");
  return 0;
}
