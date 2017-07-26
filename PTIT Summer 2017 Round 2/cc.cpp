#include <stdio.h>
#include <string.h>

int main()
{

   char buff[1024];

   memset( buff, '\0', sizeof( buff ));

   fprintf(stdout, "Chuan bi buffer\n");
   setvbuf(stdout, buff, _IOFBF, 1024);
      fflush( stdout );

   fprintf(stdout, "Hoc C co ban va nang cao tai VietJack !!!\n");
   fprintf(stdout, "Ket qua nay se duoc dem\n");
   fflush( stdout );

   return(0);
}
