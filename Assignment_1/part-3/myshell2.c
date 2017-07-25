#include <stdlib.h>
int main(void)
{
    int rc;
    rc = system("mkdir dir1; mkdir dir2; mkdir dir3 ; touch file1; touch file2");
    rc = system("cd dir1; mkdir dir4; cd dir4; touch file4");
    rc = system("cd ../..");
    rc = system("cd dir2 ; mkdir dir5; cd .. ; cd dir3; touch file3 ; cd .. ; cd dir2/dir5 ; ln -s ../../dir3/file3 link1 ");

    exit(0);
}
