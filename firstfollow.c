#include <stdio.h>
#include <string.h>
char g[20][50];
char first[10][20],follow[10][20];
int n,fc[10],flc[10];
int nt(char c)
{
 return c>='A'&&c<='Z';
}
int pos(char a[],int n,char c)
{
 for(int i=0;i<n;i++)
 if(a[i]==c) return 1;
 return 0;
}
void add(char a[],int *n,char c)
{
 if(!pos(a,*n,c))
 a[(*n)++]=c;
}
int index(char c)
{
 for(int i=0;i<n;i++)
 if(g[i][0]==c) return i;
 return -1;
}
void FIRST()
{
int change=1;
 while(change)
 {
 change=0;
 for(int i=0;i<n;i++)
 {
 char *p=strstr(g[i],"->")+2;
 char *q=strtok(p,"|");
 while(q)
 {
 char c=q[0];
 int old=fc[i];
 if(nt(c))
 {
 int k=index(c);
 for(int j=0;j<fc[k];j++)
 add(first[i],&fc[i],first[k][j]);
 }
 else
 add(first[i],&fc[i],c);
 if(old!=fc[i]) change=1;
 q=strtok(NULL,"|");
 }
 }
 }
}
void FOLLOW()
{
 int change=1;
 add(follow[0],&flc[0],'$');
 while(change)
 {
 change=0;
 for(int i=0;i<n;i++)
 {
 char *p=strstr(g[i],"->")+2;
 char *q=strtok(p,"|");
 while(q)
 {
 int len=strlen(q); for(int j=0;j<len;j++)
 {
 if(nt(q[j]))
 {
 int b=index(q[j]);
 int old=flc[b];
 if(j+1<len)
 {
if(nt(q[j+1]))
 {
 int k=index(q[j+1]);
 for(int x=0;x<fc[k];x++)
 add(follow[b],&flc[b],first[k][x]);
 }
 else
 add(follow[b],&flc[b],q[j+1]);
 }
 else
 {
 for(int x=0;x<flc[i];x++)
 add(follow[b],&flc[b],follow[i][x]);
 }
 if(old!=flc[b]) change=1;
 }
 }
 q=strtok(NULL,"|");
 }
 }
 }
}
void print(char a[],int n)
{
 for(int i=0;i<n;i++)
 {
 if(a[i]=='i')
 printf("id ");
 else
 printf("%c ",a[i]);
 }
}
int main()
{
 FILE *fp;

char file[50];
 printf("Enter file name: ");
 scanf("%s",file);
 fp=fopen(file,"r");
 if(!fp)
 {
 printf("File not found\n");
 return 1;
 }
 while(fgets(g[n],50,fp))
 {
 g[n][strcspn(g[n],"\n")]=0;
 n++;
 }
 fclose(fp);
 FIRST();
 FOLLOW();
 printf("\nFIRST\n");
 for(int i=0;i<n;i++)
 {
 printf("FIRST(%c) = { ",g[i][0]);
 print(first[i],fc[i]);
 printf("}\n");
 }
 printf("\nFOLLOW\n");
 for(int i=0;i<n;i++)
 {
 printf("FOLLOW(%c) = { ",g[i][0]);
 print(follow[i],flc[i]);
 printf("}\n");
 }
 return 0;
}
