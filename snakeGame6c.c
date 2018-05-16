#include<stdio.h>
#include<stdlib.h>
int a,b;
struct snake
{
    int x;
    int y;
    char value;
    struct snake *next;
};
struct food
{
    int x;
    int y;
    int value;
};
struct snake* CreateSnake(int x,int y,char value)
{
    struct snake *temp = (struct snake*)malloc(sizeof(struct snake));
    temp->x=x;
    temp->y=y;
    temp->value=value;
    temp->next=NULL;
    return temp;
}
void createFood(struct snake *head,struct food *f)
{
    int temp1,temp2,check;
    do
    {
        temp1=(rand())%10;
        temp2=(rand())%10;
        check = checkCoordinates(temp1,temp2,head);
    }
    while(check!=1);
        f->x=temp1;
        f->y=temp2;
        f->value='f';
}
void printArray(char arr[11][11])
{
    int i,j;
     for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
            printf("%c ",arr[i][j]);
        printf("\n");

    }
    printf("\n");
}
void updateArray(char arr[11][11],struct snake* head,struct food* f)
{
    struct snake* temp=head;
    int i,j;
    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
         {
             if(i==0 || j==0 || i==10 || j==10)
                arr[i][j]='+';
             else
            arr[i][j]=' ';
         }
    }
        while(temp!=NULL)
        {
           arr[temp->x][temp->y] = temp->value;
            temp=temp->next;
        }
    arr[f->x][f->y]=f->value;
    system("cls");
}
int SnakeMovementLeft(char arr[11][11],struct snake* current,struct food* f)
{
        int intialX,intialY,a,b,temp,flag=0;
        intialX=current->x;
        intialY=current->y;
        if(intialY == 1)
        {
            current->y = 9;
        }
        else
        {
            temp = current->y;
            temp--;
            int dead = checkCoordinates(current->x,temp,current);
            if(dead == 0)
                exit(0);
            if(current->x == f->x && temp == f->y)
            {
                current->y=temp;
                flag=1;
            }
            else if(arr[current->x][temp]!=' ')
                return -1;
            else
                current->y=temp;
        }
        current = current->next;
        while(current!=NULL)
        {
            a = current->x;
            b = current->y;
            current->x=intialX;
            current->y=intialY;
            intialX=a;
            intialY=b;
            current=current->next;
        }
        if(flag==1)
        return 1;
        else
        return 0;
}
int SnakeMovementRight(char arr[11][11],struct snake* current,struct food* f)
{
        int intialX,intialY,a,b,temp,flag=0;
        intialX=current->x;
        intialY=current->y;
        if(intialY == 9)
        {
            current->y = 1;
        }
        else
        {
            temp=current->y;
            temp++;
            int dead = checkCoordinates(current->x,temp,current);
            if(dead == 0)
                exit(0);
            if(current->x == f->x && temp == f->y)
            {
                current->y=temp;
                flag=1;
            }
            else if(arr[current->x][temp]!=' ')
                return -1;
            else
                current->y=temp;
        }
        current = current->next;
        while(current!=NULL)
        {
            a = current->x;
            b = current->y;
            current->x=intialX;
            current->y=intialY;
            intialX=a;
            intialY=b;
            current=current->next;
        }
        if(flag==1)
        return 1;
    else
        return 0;
}
int SnakeMovementUP(char arr[11][11],struct snake* current,struct food* f)
{
        int intialX,intialY,a,b,temp,flag=0;
        intialX=current->x;
        intialY=current->y;
        if(intialX == 1)
        {
            current->x = 9;
        }
        else
        {
            temp=current->x;
            temp--;
            int dead = checkCoordinates(temp,current->y,current);
            if(dead == 0)
                exit(0);
            if(temp == f->x && current->y == f->y)
            {
                current->x=temp;
                flag=1;
            }
            else if(arr[temp][current->y]!=' ')
                return -1;
            else
                current->x=temp;
        }
        current = current->next;
        while(current!=NULL)
        {
            a = current->x;
            b = current->y;
            current->x=intialX;
            current->y=intialY;
            intialX=a;
            intialY=b;
            current=current->next;
        }
    if(flag==1)
        return 1;
    else
        return 0;
}
int SnakeMovementDown(char arr[11][11],struct snake* current,struct food* f)
{
        int intialX,intialY,temp,flag=0;
        intialX=current->x;
        intialY=current->y;
        if(intialX == 9)
        {
            current->x = 1;
        }
        else
        {
            temp=current->x;
            temp++;
            int dead = checkCoordinates(temp,current->y,current);
            if(dead == 0)
                exit(0);
            if(temp == f->x && current->y == f->y)
            {
                current->x=temp;
                flag=1;
            }
            else if(arr[temp][current->y]!=' ')
                return -1;
            else
                current->x=temp;
        }
        current = current->next;
        while(current!=NULL)
        {
            a = current->x;
            b = current->y;
            current->x=intialX;
            current->y=intialY;
            intialX=a;
            intialY=b;
            current=current->next;
        }
    if(flag==1)
        return 1;
    else
        return 0;
}
int checkCoordinates(int x,int y,struct snake *current)
{
    int flag=0;
    while(current!=NULL)
    {
        if((current->x == x) && (current->y==y)  || (x==0 || y==0))
        {
            flag=1;
            break;
        }
        current=current->next;
    }
    if(flag==1)
    {
        return 0;
    }
    else
        return 1;
}
int snakeMovement(char arr[11][11],struct snake* current,char c,struct food* f,struct food* last)
{
    int ans;
    if(c=='a')
        ans = SnakeMovementLeft(arr,current,f);
    else if(c=='w')
        ans = SnakeMovementUP(arr,current,f);
    else if(c=='s')
        ans = SnakeMovementDown(arr,current,f);
    else if(c=='d')
        ans = SnakeMovementRight(arr,current,f);
    if(ans == 1)
    {
         createFood(current,f);
         return 1;
    }
    else
        return 0;

}
int main()
{
    char arr[11][11],c;
    int i,j,z;
    struct snake *head;
    struct snake *body;
    struct snake *current;
    struct snake *tail;
    struct snake *last=NULL;
    printf("press l for load save game\n");
    scanf("%c",&c);
    if(c == 'l')
    {
        FILE *fptr;
        char ch;
        char str[50];
        int j=0;
        fptr = fopen("saveGame.txt", "r");
        if(fptr == NULL)
        {
            printf("Cannot open file \n");
            exit(0);
        }
        ch = fgetc(fptr);
        while(ch != EOF)
        {
            str[j++] = ch;
            ch = fgetc(fptr);
        }
        fclose(fptr);
        str[j]='\0';
        int k=0;
        while(str[k]!='\0')
        {
            if(str[k+2] == '$')
            {
                struct snake *temp = CreateSnake((str[k]-'0'),(str[k+1]-'0'),str[k+2]);
                k+=3;
                temp->next = NULL;
                head=temp;
            }
            else
            {
                struct snake *temp = CreateSnake((str[k]-'0'),(str[k+1]-'0'),str[k+2]);
                temp->next = NULL;
                k+=3;
                if(head->next == NULL)
                {
                    current = temp;
                    head->next = current;
                }
                else if(str[k] == '\0')
                {
                    tail  = temp;
                    current->next = tail;
                }
                else
                {
                    current->next = temp;
                    current = temp;
                }
            }
        }
    }
    else
    {
        head = CreateSnake(3,1,'$');
        body = CreateSnake(3,2,'-');
        tail = CreateSnake(3,3,'~');
        current=NULL;
        head->next=body;
        body->next=tail;
        tail->next=NULL;
        last=tail;
        current=head;
    }

    struct food *f=(struct food*)malloc(sizeof(struct food));
    createFood(current,f);
    updateArray(arr,current,f);
    printArray(arr);
    while(1)
    {
        scanf("%c",&c);
        printf("q for save\n");
         if(c == 'q')
        {
             FILE *fp;
             char ch;
            fp = fopen("saveGame.txt", "w");
            while(current!=NULL)
            {
                fprintf(fp,"%d%d%c",current->x,current->y,current->value,'#');
                current = current->next;
            }
            fclose(fp);
        }
        current=head;
        z = snakeMovement(arr,current,c,f,last);
        if(z==1)
        {
         struct snake* newNode = CreateSnake(a,b,'~');
         newNode->next=NULL;
         tail->value='-';
         tail->next=newNode;
         tail=newNode;
         z=0;
        }
        updateArray(arr,current,f);
        printArray(arr);
    }
    return 0;
}

