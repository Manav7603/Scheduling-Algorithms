#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

typedef struct node
{
    char pn[100];
    int at;
    int bt;
    int pt;
    int temporary;
    struct node *next;
    struct node *prev;
    int ft;
    int tat;
    int wt;
} process;

typedef struct NODE1
{
    char pn[100];
    int at;
    int bt;
    int pt;
    int temporary;
    struct NODE1*next;
    struct NODE1 *prev;
} readyq;

readyq *   qhead = NULL;
readyq *qtail = NULL;

process*create() 
{
 process *o= (process *)malloc(sizeof(process)); 
 return o; 
} 

void create_node (process **head,process** tail, char *name, int at,int bt, int pt ) 
{ 
    process *p = create() , *t=NULL; 
    p->prev = p; 
    p->next = p; 
    strcpy(p->pn, name); 
    p->at=at;
    p->bt=bt;
    p->pt=pt;
    p->tat = -1;
    p->wt = -1;
    p->ft=-1;
    p->temporary = bt;
 if ((*head) == NULL) 
 { 
    (*head) = p; 
    (*tail)= p;  
    return; 
 } 
 else
 {
    // t = (*head)->prev;
    t=(*tail); 
    p->next = NULL; 
    t->next = p; 
    p->prev = t; 
    // (*head)->prev = p; 
    (*tail)=p;
 }
}

void readfile(process ** head,process ** tail)
{
     FILE* fp = fopen("Text.csv", "r");
    if (!fp) {
    printf("Can't open file\n");
    return ;
}
    char p[1000];
    fgets(p,1000,fp);   
    int rt=0;

    while(fgets(p,1000,fp))
    {   
        //  char * token = strtok(p,",");
         char tt[1000];
            // char e[10]={'P','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
            char e[10];
            e[0]='P';
            char *rrr;
            itoa(rt,e+1,10);
            // e[1]=rt-'0';

        //  strcpy(e+1,rrr);
            rt++;
         strcpy(tt,e);
        char *token = strtok(p,",");
        int at=atoi(token);
         token = strtok(NULL,",");
        //  printf("%s\n",token);
        int bt=atoi(token);
        token = strtok(NULL,",");
        // printf("%s\n",token);
        int pt=atoi(token);
        // printf("%s %d %d %d\n",tt,at,bt,pt );
        create_node(head,tail,tt,at,bt,pt );
    }

     fclose(fp);
}

void swap(process **p, process ** q1)
{
    process *cr=(*p), *q=(*q1);
    int temp;
    temp = cr->at;  
    cr->at = q->at;  
    q->at = temp;  
    temp = cr->bt;  
    cr->bt = q->bt;  
    q->bt = temp;  
    temp = cr->pt;  
    cr->pt = q->pt;  
    q->pt = temp;  

     temp = cr->temporary;  
    cr->temporary = q->temporary;  
    q->temporary = temp; 

    char tt[100];
    strcpy(tt,cr->pn);
    strcpy(cr->pn,q->pn);
    strcpy(q->pn,tt);

}

void swap_rq(readyq **p, readyq ** q1)
{
    readyq *cr=(*p), *q=(*q1);
    int temp;
    temp = cr->at;  
    cr->at = q->at;  
    q->at = temp;  
    temp = cr->bt;  
    cr->bt = q->bt;  
    q->bt = temp;  
        temp = cr->pt;  
    cr->pt = q->pt;  
    q->pt = temp;  

     temp = cr->temporary;  
    cr->temporary = q->temporary;  
    q->temporary = temp; 

    char tt[100];
    strcpy(tt,cr->pn);
    strcpy(cr->pn,q->pn);
    strcpy(q->pn,tt);

}

void sortList(process** head)
 {  
    process *current = NULL, *index = NULL;  
    int temp;  
    if((*head) == NULL) 
    {  
        return;  
    }  
    else
     {  
        
        for(current = (*head); current != NULL; current = current->next) 
        {   
            for(index = current->next; index != NULL; index = index->next) 
            {  
                if(current->at > index->at)
                 {  
                    swap(&current,&index);
                }  
              
            }  
        }  
    }  
 }

 void sortList_bbt(readyq** head)
 {  
    readyq *current = NULL, *index = NULL;  
    int temp;  
    if((*head) == NULL) 
    {  
        return;  
    }  
    else
     {  
        
        for(current = (*head); current != NULL; current = current->next) 
        {   
            for(index = current->next; index != NULL; index = index->next) 
            {  
                if(current->bt > index->bt)
                 {  
                    swap_rq(&current,&index);
                }  
                 if(current->bt == index->bt)
                 {  
                    if(current->at > index->at)
                   { swap_rq(&current,&index);
                   }
                } 
            }  
        }  
    }  
 }

 void sortList_bpt(readyq** head)
 {  
    readyq *current = NULL, *index = NULL;  
    int temp;  
    if((*head) == NULL) 
    {  
        return;  
    }  
    else
     {  
        
        for(current = (*head); current != NULL; current = current->next) 
        {   
            for(index = current->next; index != NULL; index = index->next) 
            {  
                if(current->pt > index->pt)
                 {  
                    swap_rq(&current,&index);
                }  

                if(current->pt == index->pt)
                 {  
                    if(current->at > index->at)
                   { swap_rq(&current,&index);
                   }
                } 
                
            }  
        }  
    }  
 }

void desc_sortList_bbt(readyq** head)
 {  
    readyq *current = NULL, *index = NULL;  
    int temp;  
    if((*head) == NULL) 
    {  
        return;  
    }  
    else
     {  
        
        for(current = (*head); current != NULL; current = current->next) 
        {   
            for(index = current->next; index != NULL; index = index->next) 
            {  
                if(current->bt < index->bt)
                 {  
                    swap_rq(&current,&index);
                }  
                    if(current->bt == index->bt)
                 {  
                    if(current->at > index->at)
                   { swap_rq(&current,&index);
                   }
                } 
            }  
        }  
    }  
 }


void demo(process ** head)
{
      process *temp;
      temp=(*head);

      while(temp != NULL)
      {
        printf("%s %d %d %d\n", temp->pn,temp->at, temp->bt, temp->ft);
        temp=temp->next;

      }
    //   printf("%s %d %d %d\n", temp->pn,temp->at, temp->bt, temp->pt);

}

process *chk (process ** head,int i,process ** c)
{
    int y=-1;
    int flag;
    process * temp1=  (*head);
    man:
    flag=0;
    temp1=  (*head);
    for(temp1;temp1 != NULL;temp1=temp1->next)
    {
        if(i<temp1->at)
        {
            y=-2;
            break;
        }

        if((*c)==NULL)
        {
            if(temp1->bt >0)
            {
                (*c)=temp1;
            }
        }

        if(temp1->bt >  0)
        {
            
            if((*c)->bt >= temp1->bt){
                flag=1;
                (*c) = temp1;

            }
        }

    }
    if(flag==0 && (*c)->bt<=0)
    {
        (*c)=NULL;
        goto man;
    }
    // if((*c)==NULL)
    // {
    // return (*head);
    // }

    return (*c);
}

int totalBurstTime(process **head){
    process *temp = (*head);
    int sum = 0;
    for(temp; temp != NULL; temp = temp->next)
    {
        sum += temp->bt;
    }
    return sum;
}

typedef struct NODE
{
    char pn[100];
    struct NODE * next;
} gantt;

gantt * ghead = NULL;
gantt * gtail = NULL;
gantt *newnode1()
{
    gantt *t = (gantt *)malloc(sizeof (gantt));
    t->next=NULL;
    return t;
}
gantt gcreate(char a[]){
    if(ghead == NULL)
    {
        ghead = newnode1();
        gtail = ghead;
        // ghead->pn = 'X';
        strcpy(ghead->pn,a);
    }
    else
    {
        gantt *p = newnode1();
        strcpy(p->pn,a);
        gtail -> next = p;
        gtail = p;
    }
}

void print_gantt1()
{
    for (gantt* i = ghead; i != NULL; i= i->next)
    {
        printf("%s ",i->pn);
    }
    printf("\n");
}

float avrt=0,awt=0;
void printFile(struct node *l,gantt *g,int c){
    FILE *fp;
    fp=fopen("Output.txt","a");
    fprintf(fp,"\n*************************************\n");
    fprintf(fp,"21BCE106 Ekta Kalavadiya\n");
    fprintf(fp,"21BCE143 Manav Pandya\n");
    fprintf(fp,"Result: \n");
    fprintf(fp,"Scheduling Algorithm Used: \n");
    if(c==1)
    {
        fprintf(fp,"First Come First served\n\n");
    }
    else if(c==2)
    {
        fprintf(fp,"Shortest Job First\n\n");
    }
    else if(c==3)
    {
        fprintf(fp,"Round Robbin\n\n");
    }
    else if(c==4)
    {
        fprintf(fp,"Priority Sheduling\n\n");
    }
    else if(c==5)
    {
        fprintf(fp,"Shortest Remaining Time First\n\n");
    }
    else if(c==6)
    {
        fprintf(fp,"Longest Remaining Time First\n\n");
    }
     fprintf(fp,"Table:  \n");
    fprintf(fp,"SR.No.  Process Arrival Final Burst Priority Turnarr Waiting\n");
    int yy=0;
    while (l != NULL)
    {
        yy++;
        fprintf(fp,"%7d %s  %7d %7d %7d %7d %7d %7d\n", yy, l->pn, l->at,l->ft, l->temporary,l->pt, l->tat, l->wt);
        l = l->next;
    }
    fprintf(fp,"\nGantt Chart:- \n");
    while (g != NULL)
    {
        fprintf(fp,"%s ", g->pn);
        g = g->next;
    }
    fprintf(fp,"\nAverage turn arround Time = %f\nAverage waiting Time = %f\n", avrt, awt);
    fprintf(fp,"\n");
    fclose(fp);
}

void print_gantt()
{
    FILE* fp = fopen("result.txt","w");
    fprintf(fp,"21BCE106 Ekta Kalavadiya\n");
    fprintf(fp,"21BCE143 Manav Pandya\n");
    fprintf(fp,"Result: \n");
    fprintf(fp,"Gantt Chart: -\n");
    for (gantt* i = ghead; i != NULL; i= i->next)
    {
        fprintf(fp,"%s ",i->pn);
    }
    fprintf(fp,"\n");
    fclose(fp);
}


void readyQueue(process *temp)
{
    readyq *p = (readyq *)(malloc(sizeof(readyq))) , *t=NULL; 
    p->prev = NULL; 
    p->next = NULL; 
    strcpy(p->pn,temp->pn); 
    p->at= temp-> at;
    p->bt= temp-> bt;
    p->pt= temp-> pt;
    p->temporary = temp-> bt;
 if ((qhead) == NULL) 
 { 
    (qhead) = p; 
    (qtail)= p;  
    return; 
 } 
 else
 {
    // t = (*head)->prev;
    t=(qtail); 
    p->next = NULL; 
    t->next = p; 
    p->prev = t;
    // (*head)->prev = p; 
    (qtail)=p;
 }
}

int allFinished(process ** head)
{
    int flag=1;
    for(process *temp = (*head); temp != NULL; temp = temp->next)
    {
        if(temp->bt != 0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
readyq * ck=NULL;
int total_process=0;
void SRTF(process **head)
{
    sortList(head);
    int chk=0;
            for(process *temp = (*head); temp != NULL; temp = temp->next)
        {
        chk+=1;

        }
    for(int i=0; ;i++)
    {

        for(process *temp = (*head); temp != NULL; temp = temp->next)
        {
        
            if(temp->at == i)
            {
                readyQueue(temp);
                sortList_bbt(&qhead);
                break;
            }
        }

        if(qhead==NULL)
        {
                 char a[2]={'X'};
                gcreate(a);
        }
        else
        {
            gcreate(qhead->pn);
            qhead->bt-=1;
            if(qhead->bt==0)
            {
                ck=qhead;
                total_process+=1;
                qhead=qhead->next;
                free(ck);
            }
        }

        if(total_process==chk)
        {
            total_process=0;
            break;
        }
    }
}

void SJF(process **head)
{
    process  * temp2=(*head);
    sortList(head);
    int chk=0;
            for(process *temp = (*head); temp != NULL; temp = temp->next)
        {
        chk+=1;

        }
    for(int i=0; ;i++)
    {
        int r=0;
        for(process *temp = temp2; temp != NULL; temp = temp->next)
        {
        
            if(temp->at <= i)
            {
                readyQueue(temp);
                sortList_bbt(&qhead);
                temp2=temp->next;
                 r++;
            }
           

        }
        // printf("%s \n",qhead->pn);
        if(qhead==NULL)
        {
                 char a[2]={'X'};
                gcreate(a);
        }
        else
        {
            int k;
            for( k=0;k<((qhead)->bt);k++)
            {
                gcreate(qhead->pn);
            }
            i+=k-1;
            // for(readyq *tt = qhead; tt!=NULL;tt=tt->next)
            // {
            //     printf("%s ",tt->pn);
            // }

            // printf("%d \n",i);
            {
                ck=qhead;
                total_process+=1;
                qhead=qhead->next;
                free(ck);
            }
        }

        if(total_process==chk)
        {
            total_process=0;
            break;
        }
    }
}

void fcfs(process ** head,process ** tail)
{
   sortList(head);
//    demo(head);
    int cnt=0;
          process *temp1=(*head);
        for(; temp1 != NULL; temp1 = temp1->next)
        {
            cnt++;
        }

    // }
    process *temp=(*head);

    for(int i=0;;)
    {
         int cn=0;
        for( ; temp != NULL; temp = temp->next)
        {
            if(i < temp->at)
            {
                 char a[2]={'X'};
                gcreate(a);
                i++;
                break;
            }
            else{
                int j=0;
                // printf("%d %d \n",temp->temporary,i);
                for(j=0;j<temp->temporary;j++)
                {
                    gcreate(temp->pn);
                    (temp->bt)--;
                }
                i+=j;
               
            }
        }

        temp1=(*head);
        for( ; temp1 != NULL; temp1 = temp1->next)
        {
            if(temp1->bt <=0)
            {
                cn+=1;
            }
        }

        if(cnt<=cn || temp==NULL)
        {
            break;
        }

    }
}

void PPSS(process ** head)
{
    sortList(head);
    int chk=0;
            for(process *temp = (*head); temp != NULL; temp = temp->next)
        {
        chk+=1;

        }
    for(int i=0; ;i++)
    {

        for(process *temp = (*head); temp != NULL; temp = temp->next)
        {
        
            if(temp->at == i)
            {
                readyQueue(temp);
                sortList_bpt(&qhead);
                break;
            }
        }

        if(qhead==NULL)
        {
                 char a[2]={'X'};
                gcreate(a);
        }
        else
        {
            gcreate(qhead->pn);
            qhead->bt-=1;
            if(qhead->bt==0)
            {
                ck=qhead;
                total_process+=1;
                qhead=qhead->next;
                free(ck);
            }
        }

        if(total_process==chk)
        {
            total_process=0;
            break;
        }
    }

}

void NPSS(process ** head)
{
    process  * temp2=(*head);
    sortList(head);
    int chk=0;
            for(process *temp = (*head); temp != NULL; temp = temp->next)
        {
        chk+=1;

        }
    for(int i=0; ;i++)
    {
        int r=0;
        for(process *temp = temp2; temp != NULL; temp = temp->next)
        {
        
            if(temp->at <= i)
            {
                readyQueue(temp);
                sortList_bpt(&qhead);
                temp2=temp->next;
                 r++;
            }
           

        }
        // printf("%s \n",qhead->pn);
        if(qhead==NULL)
        {
                 char a[2]={'X'};
                gcreate(a);
        }
        else
        {
            int k;
            for( k=0;k<((qhead)->bt);k++)
            {
                gcreate(qhead->pn);
            }
            i+=k-1;
            for(readyq *tt = qhead; tt!=NULL;tt=tt->next)
            {
                printf("%s ",tt->pn);
            }

            printf("%d \n",i);
            {
                ck=qhead;
                total_process+=1;
                qhead=qhead->next;
                free(ck);
            }
        }

        if(total_process==chk)
        {
            total_process=0;
            break;
        }
    }
}
process * cpy(readyq * temp)
{
    process * t=create();
    t->at=temp->at;
     t->bt=temp->bt;
      t->pt=temp->pt;
       t->temporary=temp->temporary;
        strcpy(t->pn,temp->pn);

    return t;
}

void RRS(process ** head)
{
    int m;
    printf("Enter the value of the time quanta: ");
    scanf("%d",&m);
    printf("\n");
     process  * temp2=(*head);
    sortList(head);
    int chk=0;
            for(process *temp = (*head); temp != NULL; temp = temp->next)
        {
        chk+=1;

        }
        for(int i=0; ;i++)
        {
            int r=0;
            // printf("%d \n",i);
            for(process *temp = temp2; temp != NULL; temp = temp->next)
            {
            
                if(temp->at <= i)
                {
                    readyQueue(temp);
                    // sortList_bbt(&qhead);
                    temp2=temp->next;
                    r++;
                    // break;
                }
            

            }
            // printf("%s \n",qhead->pn);
            if(qhead==NULL)
            {
                    char a[2]={'X'};
                    gcreate(a);
            }
            else
            {
                int k;
                for( k=0;k<m;k++)
                {
                    gcreate(qhead->pn);
                    ((qhead)->bt)--;
                    if(qhead->bt<=0)
                    {
                        k++;
                        break;
                    }
                }
                i+=k-1;
                // for(readyq *tt = qhead; tt!=NULL;tt=tt->next)
                // {
                //     printf("%s ",tt->pn);
                // }
                 for(process *temp = temp2; temp != NULL; temp = temp->next)
            {
            
                if(temp->at <= i)
                {
                    readyQueue(temp);
                    // sortList_bbt(&qhead);
                    temp2=temp->next;
                    r++;
                    // break;
                }
            

            }

                // printf("%d \n",i);
                if(qhead->bt ==0)
                {
                    ck=qhead;
                    total_process+=1;
                    qhead=qhead->next;
                    free(ck);
                }
                else
                {
                    ck=qhead;
                    qhead=qhead->next;
                    readyQueue(cpy(ck));
                }
            }

            if(total_process==chk)
            {
                total_process=0;
                break;
            }
            printf("%d ",i);
        }
  
}

void trr ()
{

    for(readyq * yt=qhead;yt!=NULL;yt=yt->next)
    {
        printf("%s ",yt->pn);

    }
    printf("\n");
}

void LRTF(process ** head)
{
    process* temp2=(*head);
    sortList(head);
    int chk=0;
            for(process *temp = (*head); temp != NULL; temp = temp->next)
        {
            chk+=1;

        }

    for(int i=0; ;i++)
    {
        printf("%d \n",total_process);
        desc_sortList_bbt(&qhead);
       
        printf("\nFor %dth sec: \n",i);
         printf("1: Premptive\n");
        printf("2: Non-Premptive\n");
        printf("Enter: ");
        int u;
        scanf("%d",&u);
        
            
        if(u==1)
        {
                int rr=chk;
                while(rr--)
                {
                     desc_sortList_bbt(&qhead);
            if(qhead !=NULL)
            {
            if(qhead->bt<=0)
                {
                    ck=qhead;
                    total_process+=1;
                    qhead=qhead->next;
                    free(ck);
                  
                }
                else
                {
                    break;
                }

            }
                }
                if(total_process>=chk)
                {
                    total_process=0;
                    break;
                }
            
            for(process *temp = temp2; temp != NULL; temp = temp->next)
            {
            
                if(temp->at <= i)
                {
                    readyQueue(temp);
                    desc_sortList_bbt(&qhead);
                    temp2=temp->next;
                    // break;
                }
            }
            desc_sortList_bbt(&qhead);
            if(qhead==NULL)
            {
                    char a[2]={'X'};
                    gcreate(a);
            }
            else
            {
                gcreate(qhead->pn);
                qhead->bt-=1;
                if(qhead->bt<=0)
                {
                    ck=qhead;
                    total_process+=1;
                    qhead=qhead->next;
                    free(ck);
                }
            }
         }
            else if(u==2)
            {
            

                if(qhead==NULL)
            {
                    char a[2]={'X'};

                    gcreate(a);
            }
             else
             {   
                if(qhead->bt>=1)
                {
                gcreate(qhead->pn);
                qhead->bt--;
                }
                else
                {
                    char a[2]={'X'};
                    gcreate(a);
                      ck=qhead;
                    total_process+=1;
                    qhead=qhead->next;
                    free(ck);
                }
             }
              if(total_process==chk)
            {
                total_process=0;
                break;
            }
                 for(process *temp = temp2; temp != NULL; temp = temp->next)
            {
            
                if(temp->at <= i)
                {
                    readyQueue(temp);
                    desc_sortList_bbt(&qhead);
                    temp2=temp->next;
                    // break;
                }
            }
                desc_sortList_bbt(&qhead);

            }
            else
            {
                printf("INVALID INPUT\n");
                i--;
            }

            if(total_process==chk)
            {
                total_process=0;
                break;
            }
             trr();
             for(process *temp = temp2; temp != NULL; temp = temp->next)
            {
            
                if(temp->at <= i)
                {
                    readyQueue(temp);
                    desc_sortList_bbt(&qhead);
                    temp2=temp->next;
                    // break;
                }
            }
    }
}


void CALC(process **head, gantt **ghead)
{
    FILE* fp = fopen("result.txt","a");
    process *temp = (*head);
    float avgtat=0,avgwt=0,n=0;

    int i=0;
    for(temp; temp!= NULL; temp = temp->next)
    {
        gantt *gtemp = (*ghead);
        int c=0;
        i=0;
        for(gtemp; gtemp!= NULL; gtemp = gtemp->next)
        {
            i++;
            if(!(strcmp(gtemp->pn, temp->pn)))
            {
                c=i;
            }
        }

        temp->ft=c;
        // printf("%d\n",temp->ft);
        temp->tat = c-(temp->at);
        temp->wt = temp->tat - (temp->temporary);
        avgtat += temp->tat;
        avgwt += temp->wt;
        n++;
    }
    avgtat /= n;
    avgwt /= n;
    fprintf(fp,"Average Turnaround Time: %0.2f\n",avgtat);
    fprintf(fp,"Average Waiting Time: %0.2f",avgwt);
    avrt=avgtat;
    awt=avgwt;
    fclose(fp);
}

    void wm()
{
    system("cls");
    printf("\n \n");
    printf("\n\t\t\t-------------------------------------------------------------------------------\n");
    printf("\t\t\t###############################################################################");
    printf("\n\t\t\t############              OS Innovative:      Made by :            ############");
    printf("\n\t\t\t############              Manav Pandya        21BCE143             ############");
    printf("\n\t\t\t############              Ekta Kalavadiya     21BCE106             ############");
    printf("\n\t\t\t###############################################################################");
    printf("\n\t\t\t-------------------------------------------------------------------------------\n");

}
int main()
{

    wm();
    // printf("\n************ Welcome ***********\n");
    // printf("\n21BCE106 Ekta Kalavadiya\n");
    // printf("\n21BCE143 Manav Pandya\n");
        printf("\n");
    while(1)
    {
        process *head = NULL, *tail = NULL;     
        printf("\n********************************\n");
        printf("Main Menu \n");
        printf("1. First-Come First-Served\n");
        printf("2. Shortest Job First\n");
        printf("3. Round Robin Scheduling\n");
        printf("4. Priority Scheduling\n");
        printf("5. Shortest Remaining Time First\n");
        printf("6. Longest remaining time first\n");
        printf("7. Exit\n");
        printf("Select: \n");
        int n;
        scanf("%d",&n);
        
        readfile(&head,&tail);
        // demo(&head);

        sortList(&head);

        //   demo(&head);

        
        if(n==5)
        {
            // srtf(&head,&tail);
            SRTF(&head);
            printf("\n");

            print_gantt();
            CALC(&head,&ghead);
        }
       else if(n==1)
        {

            fcfs(&head,&tail);
            printf("\n");
            print_gantt();
            CALC(&head,&ghead);
        }
       else if(n==4)
        {
            printf("1: Premptive\n");
            printf("2: Non-Premptive\n");
            printf("Enter: ");
            int u;
            scanf("%d",&u);
            switch (u)
            {
                case 1 :
                PPSS(&head);
                break;
                case 2:
                NPSS(&head);
                break;
                default:
                printf("\nInvalid Input :( \n");
            }
            printf("\n");
            print_gantt();
            CALC(&head,&ghead);
        }
        else if(n==3)
        {
            // rrs(&head,&tail);
            RRS(&head);
            printf("\n");
            print_gantt();
            CALC(&head,&ghead);
        }
        else  if(n==2)
        {
            // sjf(&head,&tail);
            SJF(&head);
            printf("\n");
            print_gantt();
            CALC(&head,&ghead);
        }
        else  if(n==6)
        {
            LRTF(&head);
            printf("\n");
            print_gantt();
            CALC(&head,&ghead);
        }
        else if(n==7)
        {
            printf("\n***************************\n");
            printf("Thank You :) \n\n");
            return 0;
        }
        else
        {
            printf("Invalid Input !!\n");
            printf("Please Re-Enter the number :)\n");
            continue;
        }
        // demo(&head);
                printf("\nThe result has been generated and has been stored in Output.txt file.\n");
                printf("\n********************************\n");
        printFile(head,ghead,n);
        sortList(&head);
        ghead=NULL;
        gtail=NULL;
        }
        return 0;
}