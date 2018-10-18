//#include <stdio.h>
main()
{
	char ch;
	while ((ch=getchar())!= EOF)
	{
 		if ((ch >= 'A') && (ch <= 'Z'))
 			ch += 'a'-'A'; 
 		putchar(ch);
 	}
}
