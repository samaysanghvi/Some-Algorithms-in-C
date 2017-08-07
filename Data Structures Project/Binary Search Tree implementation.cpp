#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>
#define NUM 23
/** List of Global Variable */
COORD coord = {0,0}; /// top-left corner of window
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
typedef struct employeebintag{
	struct employeebintag *ptr;
	int level;
	char name[50];
	struct employeebintag *left;
	struct employeebintag *right;
}bintype;

typedef struct employeeavltag{
	bintype *pptr;
	char name[50];
	struct employeeavltag *left;
	struct employeeavltag *right;

}avltype;
int height(avltype *root)
 {
 	int retval=-1;
 	if(root!=NULL)
 	{
 		if(root->left==NULL && root->right==NULL)
 		{
 			retval=0;
		 }
		 else
		 {
		 	int left_ht,right_ht;
		 	left_ht=height(root->left)+1;
		 	right_ht=height(root->right)+1;
		 	if(left_ht>right_ht)
		 	{
		 		retval=left_ht;
			 }
			 else
			 {
			 	retval=right_ht;
			 }
		 }
	 }
	 return retval;
 }
 int heightbin(bintype *root)
 {
 	int retval=-1;
 	if(root!=NULL)
 	{
 		if(root->left==NULL && root->right==NULL)
 		{
 			retval=1;
		 }
		 else
		 {
		 	int left_ht,right_ht;
		 	left_ht=heightbin(root->left)+1;
		 	right_ht=heightbin(root->right)+1;
		 	if(left_ht>right_ht)
		 	{
		 		retval=left_ht;
			 }
			 else
			 {
			 	retval=right_ht;
			 }
		 }
	 }
	 return retval;
 }
int getBalance(avltype *N)
{
    if (N == NULL)
        return 0;
    return (height(N->left)-height(N->right));
}
 	
	

avltype *leftrotate(avltype *p)
{
	avltype *temp=p;
	if(p==NULL)
	{
		printf("Error\n");
	}
	else if(p->right==NULL)
	{
		printf("\ncannot rotate\n");
	}
	else
	{
		temp=p->right;
		p->right=temp->left;
		temp->left=p;
	}
 return temp;	
}

avltype *rightrotate(avltype *p)
{
	avltype *temp=p;
	if(p==NULL)
	{
		printf("Error\n");
	}
	else if(p->left==NULL)
	{
		printf("\ncannot rotate\n");
	}
	else
	{
		temp=p->left;
		p->left=temp->right;
		temp->right=p;
	}
 return temp;	
}

 
bintype *addbin(char str[50],bintype *nptr)
{
	bintype *sptr;
	sptr=(bintype *)malloc(sizeof(bintype));
	strcpy(sptr->name,str);
	if(nptr==NULL)
	{
		sptr->level=1;
		sptr->left=sptr->right=NULL;
		sptr->ptr=sptr;
	}
	else
	{
		if(nptr->left==NULL)
		{
			nptr->left=sptr;
			sptr->ptr=nptr;
			sptr->level=nptr->level+1;
			sptr->left=sptr->right=NULL;	
		}
		else if(nptr->right==NULL)
		{
			nptr->right=sptr;
			sptr->ptr=nptr;
			sptr->level=nptr->level+1;
			sptr->left=sptr->right=NULL;
		}
		else{
			printf("\n\nAlready two employees exist for %s\n\n",nptr->name);
			free(sptr);
			exit(0);
		}
	}
	return sptr;
}

avltype *addavl(char str[50],avltype *root,bintype *ptr)
{
	avltype *p=root;
	avltype *nptr,*retval;
	retval=root;
	if(p==NULL)
	{
		nptr=(avltype *)malloc(sizeof(avltype));
		strcpy(nptr->name,str);	
		nptr->left=nptr->right=NULL;
		nptr->pptr=ptr;
		retval=nptr;
		
	}
	else
	{
	
	while(p!=NULL)
	{
		if(strcmp(p->name,str)<0)
		{
			if(p->right!=NULL)
			{
			p=p->right;
			}
			else
			{
				nptr=(avltype *)malloc(sizeof(avltype));
				strcpy(nptr->name,str);
				nptr->left=nptr->right=NULL;
				nptr->pptr=ptr;
				
				p->right=nptr;
				break;
			}
		}
		else if(strcmp(p->name,str)>0)
		{
		
			if(p->left!=NULL)
			{
			p=p->left;
			}
			else
			{
				nptr=(avltype *)malloc(sizeof(avltype));
				strcpy(nptr->name,str);
				nptr->left=nptr->right=NULL;
				nptr->pptr=ptr;
				p->left=nptr;
				break;
			}
		}
		else
		{
			printf("\n\nRepeated data not allowed\n\n");
			break;
		}
	}

	int balance = getBalance(root);
 	
 // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        retval=rightrotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftrotate(root->left);
        retval=rightrotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        retval=leftrotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightrotate(root->right);
        retval=leftrotate(root);
    }
}
 	
    return retval;
}   

avltype *checkboss(char str[50],avltype *root)
{
	avltype *p=root;
	while(p!=NULL && strcmp(str,p->name)!=0)
	{
		if(strcmp(p->name,str)<0)
		{
			p=p->right;
		}
		else 
		{
			p=p->left;
		}
	}
	return p;
}
avltype *findpar(char str[50],avltype *root)
{
	avltype *p=root;
	avltype *prev,*retval=root;
	while(p!=NULL && strcmp(str,p->name)!=0)
	{
		if(strcmp(p->name,str)<0)
		{
			prev=p;
			p=p->right;
		}
		else 
		{
			prev=p;
			p=p->left;
		}
	}
	
	return prev;
}

void preorderbin(bintype *ptr)
{
	bintype *p=ptr;
	if(p!=NULL)
	{
		printf("%s",p->name);
		preorderbin(p->left);
		preorderbin(p->right);
	}
}
void preorderavl(avltype *ptr)
{
	avltype *p=ptr;
	if(p!=NULL)
	{
		printf("%s",p->name);
		preorderavl(p->left);
		preorderavl(p->right);
	}
}
void updatelevel(bintype *root)
{
	bintype *p=root;
	if(p!=NULL)
	{
		p->level=p->ptr->level;
		updatelevel(p->left);
		updatelevel(p->right);
	}
}

int numnodesavl(avltype *root)
{
	int retval;
	if(root==NULL)
	{
		retval=0;
	}
	else
	{
		retval=1+numnodesavl(root->left)+numnodesavl(root->right);
	}
	return retval;
}



 
/* Print nodes at a given level */
void printGivenLevel(bintype *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
		printf("\nEmployee is %s",root->name);
		if(root->left==NULL && root->right==NULL)
		{
			printf("Employee has no children\n\n");
		}
        if(root->left!=NULL)
        {
        	printf(":%s",root->left->name);
		}
		if(root->right!=NULL)
        {
        	printf(":%s",root->right->name);
		}
	}
	else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void bindelete(char str[50],bintype *root)
{
	bintype *q,*p=root;
	if(p->right!=NULL && p->left!=NULL)
	{
		printf("\nCannot delete,%s has 2 children\n",str);
		exit(0);
	}
	else
	{
		if(p->right==NULL)
		{
			if(p->ptr->right==p)
			{
				p->ptr->right=p->left;
				q=p->left;
				q->ptr=p->ptr;
				updatelevel(p->left);
				free(p);
			}
			else
			{
				p->ptr->left=p->left;
				q=p->left;
				q->ptr=p->ptr;
				updatelevel(p->left);
				free(p);
			}
		}
		else
		{
			if(p->ptr->right==p)
			{
				p->ptr->right=p->right;
				q=p->right;
				q->ptr=p->ptr;
				updatelevel(p->right);
				free(p);
			}
			else
			{
				p->ptr->left=p->right;
				q=p->right;
				q->ptr=p->ptr;
				updatelevel(p->right);
				free(p);
			}
		}
	}
}

avltype* avldelete(char str[50],avltype *root,avltype *lptr)
{
   avltype *prev,*q,*retval;
   retval=lptr;
      
		
        if (root->left == NULL && root->right != NULL)
        {
            q= root->right;
            free(root);
        }
        else if (root->right == NULL && root->left!=NULL)
        {
          q = root->left;
          	free(root);  
        }
        else if(root->right == NULL && root->left==NULL)
        {
        	
        	q=NULL;
			free(root);
		}
        else
        {
        	for(prev=q=root->left;q->right!=NULL;)
        	{
        		prev=q;
        		q=q->right;
			}
			if(prev==q)
			{
				q->right=root->right;
				free(root);
			}
			
			else
			{
			prev->right=q->left;
			q->left=root->left;
			q->right=root->right;
			free(root);
            }
		}
 	return q;
}

avltype *balanceavl(avltype *lptr)
{
	avltype*retval=lptr;
	int balance = getBalance(lptr);
 	
 // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(lptr->left) >= 0)
    	retval=rightrotate(lptr);
 
    // Left Right Case
    if (balance > 1 && getBalance(lptr->left) < 0)
    {
        lptr->left =  leftrotate(lptr->left);
        retval=rightrotate(lptr);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(lptr->right) <= 0)
        retval=leftrotate(lptr);
 
    // Right Left Case
    if (balance < -1 && getBalance(lptr->right) > 0)
    {
        lptr->right = rightrotate(lptr->right);
        retval=leftrotate(lptr);
    }
	return retval;
}

void bossintersec(bintype *rptr,bintype *sptr)
{
	if(strcmp(rptr->name,sptr->name)==0)
	{
		printf("\n\nThe common boss is the employee itself i.e %s\n\n",rptr->name);
	}
	else
	{
	  while(strcmp(rptr->name,sptr->name)!=0)
	  {
			if(rptr->level==sptr->level)
			{
			 rptr=rptr->ptr;
			 sptr=sptr->ptr;
			 if(strcmp(rptr->name,sptr->name)==0)
			 {
			 	printf("\n\nThe common boss is %s\n\n",rptr->name);
				 }	
			}
			else
			{
				  if(rptr->level>sptr->level)
				{
					
				 rptr=rptr->ptr;
				 if(strcmp(rptr->name,sptr->name)==0)
				 {
				 	printf("\n\nThe common boss is %s\n\n",rptr->name);
				 }	
				}
			
				else
				{
					sptr=sptr->ptr;
				 	if(strcmp(rptr->name,sptr->name)==0)
				 {
				 	printf("\n\nThe common boss is %s\n\n",rptr->name);
					 }	
				}
			}
		
		}
			
		}	
	}

main()
{
	 int option,another,i=0,j=0,flag=0,num=0,avlnodes=0,level,high,k;
	 char s[50],string[50];
	 avltype *avlroot,*ptr,*paptr,*mptr,*parptr;
	 bintype *binroot,*lptr,*cptr,*temp2;
	 avlroot=NULL;
	 binroot=NULL;
	 paptr=NULL;
	 FILE *fp1;
	 char line[50];
	 while(1)
    {
        system("cls"); ///clear the console window
        gotoxy(45,0);
        printf("DSPD ASSIGNMENT");
        gotoxy(36,2);
        printf("Done By Samay Sanghvi(BT15CSE074)");
        gotoxy(28,4);
        printf("------------------------------------------------");
        gotoxy(30,6);
        printf("1. Read the name of CEO");/// option for calling a function
        gotoxy(30,8);
        printf("2. Insert Boss-Employee Pair"); /// option for returning from a function
        gotoxy(30,10);
        printf("3. Print all employees at level L"); /// option for printing longest chain
        gotoxy(30,12);
        printf("4. Print direct or indirect boss of employee k");/// exit from the program
        gotoxy(30,14);
        printf("5. Remove employee C");
        gotoxy(30,16);
        printf("6. Print common Boss of employees G and F");
        gotoxy(30,18);
        printf("7. Print number of nodes in left and right subtree");
        gotoxy(30,20);
        printf("8. Exit");
        gotoxy(28,22);
        printf("------------------------------------------------");
        gotoxy(30,24);
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4
        fflush(stdin); /// flush the input buffer
        scanf("%d",&option); /// get the input from keyboard
		switch(option){
			case 1:
				system("cls");
				
				if(num==0)
				{
				
				fp1=fopen("input.txt","r");
				fgets(line,sizeof line,fp1);
				binroot=addbin(line,binroot);
				avlroot=addavl(line,avlroot,binroot);
				cptr=binroot;
				printf("\n\n The CEO is %s\n\n",line);
				strcpy(string,line);
				num=1;
				fclose(fp1);
			}
			else
			{
				printf("\n\n CEO is already appointed\n\n");
			}
				printf("\n\nPress q to return to home screen - ");
    	    	another=getche();
				break;
			case 2:
				system("cls");
				if(num==1)
				{
					fp1=fopen("input.txt","r");
						fgets(line,sizeof line,fp1);
					
					for(i=2;i<=NUM-6;i++)
					{
						
						fgets(line,sizeof line,fp1);
						paptr=checkboss(line,avlroot);
						if(paptr==NULL)
						{
							printf("\n Some Boss is not present!Please check the file!\n\n");
							exit(0);
						}
						else
						{
							fgets(line,sizeof line,fp1);
							lptr=addbin(line,paptr->pptr);
							avlroot=addavl(line,avlroot,lptr);
						}
						i++;
					}
					printf("Avl tree is \n\n");
					preorderavl(avlroot);
					printf("\nBin tree is \n\n");
					preorderbin(cptr);
					printf("-----------------\n");
				
					printf("\n Total %d Employees were added\n",(NUM-7)/2);
					num=2;
					fclose(fp1);
				}
				else if(num==2)
				{
					printf("\nEmployees are already inserted\n\n");
				}
				else
				{
					printf("\nPerfrom 1st function first\n\n");
				}
				printf("\n\nPress q to return to home screen - ");
    	    	another=getche();
				break;
				case 3:
					system("cls");
					if(num==2)
					{	
						fp1=fopen("input.txt","r");
						for(j=1;j<=NUM-6;j++)
						{
						fgets(line,sizeof line,fp1);
						}
						fgets(line,sizeof line,fp1);
						level=atoi(line);
						high=heightbin(cptr);
						if(high<level)
						{
							printf("\n\nThe given level is beyond the height of tree!\n\n");
							exit(0);
						}
						printGivenLevel(cptr,level);
						fclose(fp1);
					}
					else
					{
						printf("\nFirst insert employee-boss pair\n");
					}
					printf("\n\nPress q to return to home screen - ");
	    	    	another=getche();
					break;
				case 4:
					system("cls");
					if(num==2)
					{		
						fp1=fopen("input.txt","r");
						for(k=1;k<=NUM-5;k++)
							{
							 fgets(line,sizeof line,fp1);
							}
							
							fgets(line,sizeof line,fp1);
							
							paptr=checkboss(line,avlroot);
							temp2=paptr->pptr->ptr;
							if(paptr==NULL)
							{
								printf("\n\nThe employee is not present in tree!\n\n");
								exit(0);
							}
							else
							{
								printf("{%s}",paptr->name);
								printf("The List of bosses starting with immediate one are - \n");
								while(strcmp(temp2->name,cptr->name)!=0)
								{
									printf("%s",temp2->name);
									temp2=temp2->ptr;
								}
								printf("%s",temp2->name);
							}
							
								fclose(fp1);
					}
					else
					{
						printf("\nFirst insert employee-boss pair\n");
					}
					printf("\n\nPress q to return to home screen - ");
    	    		another=getche();
					break;
				case 5:
					system("cls");
					if(flag==0)
					{
					if(num==2)
					{
					fp1=fopen("input.txt","r");
					for(i=1;i<=NUM-4;i++)
					{
						fgets(line,sizeof line,fp1);
					}
					fgets(line,sizeof line,fp1);
					paptr=checkboss(line,avlroot);
					mptr=paptr;
					if(paptr==NULL)
					{
						printf("\n\nThe Boss is not present in tree!\n\n");
						exit(0);
					}
					else
					{
						
						fgets(line,sizeof line,fp1);
						paptr=checkboss(line,avlroot);
						if(paptr->pptr->ptr!=mptr->pptr)
						{
							printf("Wrong input the boss employee pair is not true\n");
							exit(0);
						}
						if(paptr==NULL)
						{
							printf("\n\nThe employee is not present in tree!\n\n");
							exit(0);
						}
						else
						{
						parptr=findpar(line,avlroot);
						bindelete(line,paptr->pptr);
						if(strcmp(parptr->name,line)==0)
						{
							avlroot=avldelete(line,paptr,avlroot);
						}
						else
						{
							if(parptr->left!=NULL)
							{
								if(strcmp(parptr->left->name,line)==0)
								{
									parptr->left=avldelete(line,paptr,avlroot);
								}
								else
							{
								parptr->right=avldelete(line,paptr,avlroot);
							}
								
							}
							else
							{
								parptr->right=avldelete(line,paptr,avlroot);
							}
						}
						
					    avlroot=balanceavl(avlroot);	
						printf("Avl tree after deletion \n\n");
						preorderavl(avlroot);
						printf("\nBin tree after deletion is \n\n");
						preorderbin(cptr);
						}
					}
					fclose(fp1);
					flag=1;
				}
				else
				{
					printf("\nFirst insert employee-boss pair\n");
				}
			}
			else
			{
				printf("\n\nAlready deleted\n\n");
			}
				printf("\n\nPress q to return to home screen - ");
    	    	another=getche();
				break;
				case 6:
						system("cls");
						if(num==2)
						{
						fp1=fopen("input.txt","r");
						for(i=1;i<=NUM-2;i++)
						{
							fgets(line,sizeof line,fp1);
						}
						fgets(line,sizeof line,fp1);
						paptr=checkboss(line,avlroot);
						mptr=paptr;
						if(paptr==NULL)
						{
							printf("\n\nThe employee %s is not present in tree!\n\n",line);
							exit(0);
						}
						fgets(line,sizeof line,fp1);
						paptr=checkboss(line,avlroot);
						if(paptr==NULL)
						{
							printf("\n\nThe employee %s is not present in tree!\n\n",line);
							exit(0);
						}
						printf("{%s%s}",mptr->name,paptr->name);
						bossintersec(mptr->pptr,paptr->pptr);
						fclose(fp1);
					}
					else
					{
						printf("\nFirst insert employee-boss pair\n");
					}
						printf("\n\nPress q to return to home screen - ");
		    	    	another=getche();
						break;
				case 7:
					system("cls");
					if(num!=0)
					{
					avlnodes=numnodesavl(avlroot->left);
					printf("\nNumber of nodes in left subtree are - %d",avlnodes);
					avlnodes=numnodesavl(avlroot->right);
					printf("\nNumber of nodes in right subtree are - %d",avlnodes);
					printf("\n\nAvl tree is \n\n");
					printf("-----------------\n");
					preorderavl(avlroot);
					printf("-----------------\n");
				}
				else
				{
					printf("\n\nPerform 1st function first\n\n");
				}
				printf("\n\nPress q to return to home screen - ");
    	    	another=getche();
				break;
				case 8: ///Exit from Loop
                	exit(0);
				}
		}
}

