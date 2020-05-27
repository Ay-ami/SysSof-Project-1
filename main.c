#include <stdio.h>
#include <stdlib.h>

struct instruct{
    int op; // opcode
    int  l; // L lexigraphical level
    int  m; // M
}instruct;

FILE *openFile(char fileName[], char mode[], FILE *fp)
{
    fp=fopen(fileName, mode);
    if(fp==NULL)
    {
        printf("Could not open %s\n", fileName);
        exit(0);
    }
    printf("file opened\n");
    return fp;
}

int main()
{
    FILE*fp;

    fp=openFile("D:\\Codebloks\\SysSof1\\input.txt", "r", fp);

    struct instruct in[20]; //20 is a place holder size, I aught to make it dynamic later

    // scan in and print out what has just been scanned
    // again, this is only hard coded because I don't want to figure out the dynamic at this moment
    fscanf(fp, "%d %d %d", &in[0].op, &in[0].l, &in[0].m);
    printf("%d %d %d\n", in[0].op, in[0].l, in[0].m);

    fscanf(fp, "%d %d %d", &in[1].op, &in[1].l, &in[1].m);
    printf("%d %d %d\n", in[1].op, in[1].l, in[1].m);

    fscanf(fp, "%d %d %d", &in[2].op, &in[2].l, &in[2].m);
    printf("%d %d %d\n", in[2].op, in[2].l, in[2].m);
    close(fp);

    return 0;
}
