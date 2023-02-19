//干掉间谍
//先思考核心代码


#include<stdio.h>
typedef struct spy //链表项
{
    char*name;
    struct spy* next; //下一个间谍，用指针
}spy,*p_spy;


p_spy head=NULL;

spy A = {"A",NULL};
spy B = {"B",NULL};
spy C = {"C",NULL};
spy D = {"D",NULL};

void insert_spy(p_spy newspy) //插入间谍函数
{
    p_spy last;
    if (head == NULL)
    {
        head = newspy;
        newspy->next = NULL;
    }
    else
    {
        last = head;
        while(last)
        {
        if (last->next == NULL)
                break;
        else
                last = last->next;//如果不是就从进入下一个间谍
        }
        
        last->next = newspy;//让最后一项的的下一位
        newspy->next=NULL;
    }
}

void remove_spy(p_spy oldspy)   //删除间谍函数
{   
    p_spy left;

    if(head == oldspy)
    {
        head = oldspy->next;
    }
    else
    {
        left = head;
        while(left)
        {
            if (left->next == oldspy)
            {
                break;
            }
            else
            {
                left = left->next;
            }
            
        }
        if(left)
        {
            left->next = oldspy->next;
        }
    }
}

void print_SPY(void)    //打印间谍函数
{
    p_spy tmp = head;
        while(tmp)
    {
        printf("%s\r\n",tmp->name);
        tmp = tmp->next;
    }

}

int main()
{
    #if 1
    insert_spy(&A);
    insert_spy(&B);
    insert_spy(&C);
    insert_spy(&D);
    #endif
    #if 0
    A.next = &B;
    B.next = &C;
    C.next = NULL;
    #endif
    print_SPY();
    remove_spy(&B);
    puts("remove spy B");
    print_SPY();


    return 0;
}

