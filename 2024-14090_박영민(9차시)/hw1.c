#include <stdio.h>
#include <stdlib.h>

int check = 0;

typedef struct tNode
{
    int value;
    struct tNode *left;
    struct tNode *right;
}treeNode;

treeNode *insertNode(treeNode *root, int value)
{
    if(root == NULL)
    {
        root = (treeNode *) malloc(sizeof(treeNode));
        if(root == NULL)
        {
            return root;
        }
        root->value = value;
        root->left = root->right = NULL;
    }
    else
    {
        if(root->value >= value)
        {
            root->left = insertNode(root->left, value);
        }
        else
        {
            root->right = insertNode(root->right, value);
        }
    }
    return root; 
}

treeNode *findNode(treeNode *root, int value)
{
    if(!root)
    {
        printf("-1\n");
        check ++;
        return NULL;
    }
    if(root->value == value)
    {
        // printf("find value %d location\n",root);
        return root;
    }
    else
    {
        if(root -> value > value)
        {
            return findNode(root->left, value);
        }
        else
        {
            return findNode(root->right, value);
        }        
    }

}

treeNode *findLCA(treeNode *root, treeNode *firstnum, treeNode *secondnum)
{
    if(!firstnum || !secondnum || !root)
    {
        return root;
    }
    if(root->value > firstnum->value && root->value > secondnum->value)
    {
        return findLCA(root->left,firstnum,secondnum);
    }
    if(root->value < firstnum->value && root->value < secondnum->value)
    {
        return findLCA(root->right,firstnum,secondnum);
    }
    return root;
}

int calculateDistance(treeNode *root, treeNode *target, int dist)
{
    if (root == NULL) return -1; // 타겟을 찾을 수 없을 때
    if (root->value == target->value) return dist;

    if (target->value < root->value) return calculateDistance(root->left, target, dist + 1);
    else return calculateDistance(root->right, target, dist + 1);
}

int distance(treeNode *root, treeNode *firstnum, treeNode *secondnum)
{
    treeNode *lca = findLCA(root, firstnum, secondnum);
    int dis1 = calculateDistance(lca, firstnum, 0);
    int dis2 = calculateDistance(lca, secondnum, 0);

    return dis1 + dis2;
}



int main()
{
    treeNode* tree = NULL;
    treeNode* first = NULL;
    treeNode* second = NULL;
    int n,num;
    int n1,n2;
    int dis;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num);
        tree = insertNode(tree,num);
    }
    scanf("%d %d",&n1,&n2);
    // printf("n1 start\n");
    first = findNode(tree,n1);
    if(check != 0) return 0; // fin program
    // printf("n2 start\n");
    second = findNode(tree,n2);
    if(check != 0) return 0; // fin program
    // printf("n2 fin");
    // printf("location %d %d %d\n",first,second,tree);
    // printf("start calculate\n");

    dis = distance(tree,first,second);
    // printf("dis fin\n");
    printf("%d",dis);

    return 0;
}