#include <stdio.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

 struct book{
 char title[MAXTITL];
 char author[MAXAUTL];
 float value;};
 
 void fun(struct book library[],struct book temp[],int st,int end,int key);
 void fun_sort(struct book library[],struct book temp[],int st,int end,int key);
 
 int main()
 {
     struct book library[MAXBKS];
     struct book temp[MAXBKS];
     int count=0;
     int index;

     puts("Please enter the book title.");
     puts("Press [enter] at the start of a line to stop.");

     while(count<MAXBKS&&gets(library[count].title)!=NULL&&library[count].title[0]!='\0')
     {
         puts("Now enter the author.");
         gets(library[count].author);
         puts("Now enter the value.");
         scanf("%f",&library[count++].value);
         while(getchar()!='\n')
            continue;
         if(count<MAXBKS)
            puts("Enter the next title.");
     }
     if(count>0)
     {
         puts("Here is the list of your books: ");
         for(index=0;index<count;index++)
            printf("%s by %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
         fun(library,temp,0,count-1,1);
         putchar('\n');
         for(index=0;index<count;index++)
            printf("%s by %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
         fun(library,temp,0,count-1,2);
         putchar('\n');
         for(index=0;index<count;index++)
            printf("%s by %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
     }
     else
        puts("No books? Too bad.\n");
     return 0;
 }


 void fun(struct book library[],struct book temp[],int st,int end,int key)
 {
     int mid=0;
     if(st<end)
     {
         mid=(st+end)/2;
         fun(library,temp,st,mid,key);
         fun(library,temp,mid+1,end,key);
         fun_sort(library,temp,st,end,key);
     }
 }

 void fun_sort(struct book library[],struct book temp[],int st,int end,int key)
 {
     int i,j,k,mid;
     i=st;
     mid=(st+end/2);
     j=mid+1;
     k=st;
     while(i!=mid+1&&j!=end+1)
     {
         if(key==1)
            if(library[i].title[0]-library[j].title[0]>0)
                temp[k++]=library[j++];
            else
                temp[k++]=library[i++];
        else if(key==2)
            if(library[i].value>library[j].value)
                temp[k++]=library[j++];
            else
                temp[k++]=library[i++];
     }
     while(i!=mid+1)
        temp[k++]=library[i++];
     while(j!=end+1)
        temp[k++]=library[j++];
     for(i=st;i<=end;i++)
        library[i]=temp[i];
 }
