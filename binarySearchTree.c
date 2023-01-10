#include<stdio.h>
#include<stdlib.h>

typedef struct __bst__node
{
int num;
struct __bst__node *left;
struct __bst__node *right;
}BSTNode;

BSTNode *start;

typedef struct __stack__node
{
BSTNode *ptr;
struct __stack__node *next;
}StackNode;

StackNode *stackStart;

typedef struct __queue__node
{
BSTNode *ptr;
struct __queue__node *next;
}QueueNode;

QueueNode *queueStart,*queueEnd;

int getHeightOfTree();

int isQueueEmpty()
{
return queueStart==NULL;
}

void addToQueue(BSTNode *ptr)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->ptr=ptr;
t->next=NULL;
if(queueStart==NULL)
{
queueStart=queueEnd=t;
}
else
{
queueEnd->next=t;
queueEnd=t;
}
}

BSTNode * removeFromQueue()
{
BSTNode *ptr;
QueueNode *t;
ptr=queueStart->ptr;
t=queueStart;
queueStart=queueStart->next;
if(queueStart==NULL)    queueEnd=NULL;
free(t);
return ptr;
}

int isStackEmpty()
{
return stackStart==NULL;
}

void pushOnStack(BSTNode *ptr)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->ptr=ptr;
t->next=NULL;
t->next=stackStart;
stackStart=t;
}

BSTNode * popFromStack()
{
BSTNode *ptr;
StackNode *t;
t=stackStart;
ptr=t->ptr;
stackStart=stackStart->next;
free(t);
return ptr;
}

BSTNode * elementAtTopOfStack()
{
return stackStart->ptr;
}

void insert(int num)
{
BSTNode *t,*j;
t=(BSTNode *)malloc(sizeof(BSTNode));
t->num=num;
t->right=NULL;
t->left=NULL;
if(start==NULL)
{
start=t;
}
else
{
j=start;
while(1)
{
if(num==j->num)
{
printf("%d already exists\n",num);
return;
}
if(num<j->num)
{
if(j->left==NULL)
{
j->left=t;
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
j->right=t;
break;
}
else
{
j=j->right;
}
}
}
}
}

void traverseInOrder()
{
BSTNode *t;
t=start;
while(t!=NULL)
{
pushOnStack(t);
t=t->left;
}
while(!isStackEmpty())
{
t=popFromStack();
printf("%d\n",t->num);
t=t->right;
while(t!=NULL)
{
pushOnStack(t);
t=t->left;
}
}
}

void inOrderTraversal(BSTNode *t)
{
if(t==NULL)    return;
inOrderTraversal(t->left);
printf("%d\n",t->num);
inOrderTraversal(t->right);
}

void traversPreOrder()
{
BSTNode *t;
if(start==NULL)
{
printf("BST is Empty\n");
return;
}
pushOnStack(start);
while(!isStackEmpty())
{
t=popFromStack();
printf("%d\n",t->num);
if(t->right!=NULL)    pushOnStack(t->right);
if(t->left!=NULL)    pushOnStack(t->left);
}
}

void preOrderTraversal(BSTNode *t)
{
if(t==NULL)    return;
printf("%d\n",t->num);
preOrderTraversal(t->left);
preOrderTraversal(t->right);
}

void traversPostOrder()
{
BSTNode *t;
if(start==NULL)
{
printf("BST is Empty\n");
return;
}
t=start;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)    pushOnStack(t->right);
pushOnStack(t);
t=t->left;
}
t=popFromStack();
if(!isStackEmpty() && t->right!=NULL && t->right==elementAtTopOfStack())
{
popFromStack();
pushOnStack(t);
t=t->right;
}
else
{
printf("%d\n",t->num);
t=NULL;
}
if(isStackEmpty())    break;
}
}

void postOrderTraversal(BSTNode *t)
{
if(t==NULL)    return;
postOrderTraversal(t->left);
postOrderTraversal(t->right);
printf("%d\n",t->num);
}

void traversLevelOrder()
{
BSTNode *t;
int howManyAdded,j,inserted,ln,h,e;
if(start==NULL)
{
printf("BST is Empty\n");
return;
}
h=getHeightOfTree();

printf("height : %d\n",h);

addToQueue(start);
inserted=1;
ln=1;
while(!isQueueEmpty())
{
printf("------- Level %d -------\n",ln);
howManyAdded=0;
j=1;
while(j<=inserted)
{
t=removeFromQueue();
printf("%d    ",t->num);
if(t->left)
{
addToQueue(t->left);
howManyAdded++;
}
if(t->right)
{
addToQueue(t->right);
howManyAdded++;
}
j++;
}
printf("\n");
inserted=howManyAdded;
ln++;
h--;
}
}

void levelOrderTraversal(BSTNode *t)
{
if(t==NULL)    return;
printf("%d\n",t->num);
levelOrderTraversal(t->left);
levelOrderTraversal(t->right);
}

int getHeightOfTree()
{
BSTNode *t;
int height,howManyAdded,inserted,j;
if(start==NULL)
{
printf("BST is empty\n");
return 0;
}
addToQueue(start);
inserted=1;
height=0;
while(!isQueueEmpty())
{
height++;
howManyAdded=0;
j=1;
while(j<=inserted)
{
t=removeFromQueue();
if(t->left)
{
addToQueue(t->left);
howManyAdded++;
}
if(t->right)
{
addToQueue(t->right);
howManyAdded++;
}
j++;
}
inserted=howManyAdded;
}
return height;
}

int getHeightOfTreeRecursion(BSTNode *t)
{
int lh,rh;
if(t==NULL)    return 0;
lh=getHeightOfTreeRecursion(t->left);
rh=getHeightOfTreeRecursion(t->right);
if(lh>rh)   return lh+1;
return rh+1;
}

void search(int num)
{
BSTNode *t;
t=start;
while(t!=NULL)
{
if(num==t->num)
{
printf("%d found\n",t->num);
return;
}
if(num<t->num)    t=t->left;
else    t=t->right;
}
printf("%d not found\n",num);
}

void removeFromBST(int num)
{
BSTNode *t,*i,*j,*k,**p2p;
if(start==NULL)
{
printf("BST is empty\n");
return;
}
t=start;
while(t!=NULL)
{
if(num==t->num)    break;
j=t;
if(num<t->num)    t=t->left;
else    t=t->right;
}
if(t==NULL)
{
printf("%d not found\n",num);
return;
}
if(t==start)
{
p2p=&start;
}
else
{
if(t==j->left)    p2p=&(j->left);
else    p2p=&(j->right);
}
if(t->left==NULL && t->right==NULL)    //Leaf Node
{
*p2p=NULL;
}
else
{
if(t->right!=NULL)    //successor
{
k=t->right;
while(k->left!=NULL)
{
i=k;
k=k->left;
}
if(t->right==k)
{
k->left=t->left;
*p2p=k;
}
else
{
i->left=k->right;
k->right=t->right;
k->left=t->left;
*p2p=k;
}
}
else    //predecessor
{
k=t->left;
while(k->right!=NULL)
{
i=k;
k=k->right;
}
if(t->left==k)
{
k->right=t->right;
*p2p=k;
}
else
{
i->right=k->left;
k->left=t->left;
k->right=t->right;
*p2p=k;
}
}
}
free(t);
printf("%d is removed\n",num);
}


int main()
{
int x,pos,ch;
start=NULL;
stackStart=NULL;
queueStart=NULL;
queueEnd=NULL;
while(1)
{
printf("1. Insert Number\n");
printf("2. Traverse (Inorder without recursion)\n");
printf("3. Traverse (Inorder using recursion)\n");
printf("4. Traverse (Preorder without recursion)\n");
printf("5. Traverse (Preorder using recursion)\n");
printf("6. Traverse (Postorder without recursion)\n");
printf("7. Traverse (Postorder using recursion)\n");
printf("8. Traverse (Level order without recursion)\n");
printf("9. Traverse (Level order using recursion)\n");
printf("10. Get Height of Tree (Without recursion)\n");
printf("11. Get Height of Tree (Using recursion)\n");
printf("12. Search Number\n");
printf("13. Remove Number\n");
printf("14. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
if(ch<1 ||ch>14)
{
printf("Invalid Input\n");
continue;
}
if(ch==1)
{
printf("Enter a number : ");
scanf("%d",&x);
fflush(stdin);
insert(x);
}
else if(ch==2)
{
traverseInOrder();
}
else if(ch==3)
{
inOrderTraversal(start);
}
else if(ch==4)
{
traversPreOrder();
}
else if(ch==5)
{
preOrderTraversal(start);
}
else if(ch==6)
{
traversPostOrder();
}
else if(ch==7)
{
postOrderTraversal(start);
}
else if(ch==8)
{
traversLevelOrder();
}
else if(ch==9)
{
levelOrderTraversal(start);
}
else if(ch==10)
{
x=getHeightOfTree();
printf("Height of Tree is : %d\n",x);
}
else if(ch==11)
{
int x=getHeightOfTreeRecursion(start);
printf("Height of tree is : %d\n",x);
}
else if(ch==12)
{
printf("Enter a number to search : ");
scanf("%d",&x);
search(x);
}
else if(ch==13)
{
printf("Enter a number to remove : ");
scanf("%d",&x);
removeFromBST(x);
}
else
{
break;
}
}
return 0;
}