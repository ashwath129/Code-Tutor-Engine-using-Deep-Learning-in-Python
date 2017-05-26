//#include<stdio.h>
//#include<string.h>
 
int main() {
   int loc;
	int i, j, firstOcc;
   i = 0, j = 0; 
   char source[] = "maharashtra";
   char target[] = "sht";
 
   while (src[i] != '\0') {
 
      while (src[i] != str[0] && src[i] != '\0')
         i++;
 
      if (src[i] == '\0')
      {
	loc=-1;
	break;
	}
 
      firstOcc = i;
 
      while (src[i] == str[j] && src[i] != '\0' && str[j] != '\0') {
         i++;
         j++;
      }
 
      if (str[j] == '\0')
      {
	  loc=firstOcc;
	break;
	}
      if (src[i] == '\0')
      {
	 loc = -1;
	break;
	}
 
      i = firstOcc + 1;
      j = 0;
   }
 
   if (loc == -1)
      printf("\nNot found");
   else
      printf("\nFound at location %d", loc + 1);
 
   return (0);
}
 
