#include <stdlib.h>
int main(void)
{
    int rc;
    rc = system("pwd; ls; cd dir1; pwd; ls; cd dir4 ; pwd; ls; cd ../..");
    rc = system("cd dir2; pwd; ls; cd dir5 ;pwd; ls; cd ../.. ");
    rc = system("cd dir3; pwd; ls");
    exit(0);
}
