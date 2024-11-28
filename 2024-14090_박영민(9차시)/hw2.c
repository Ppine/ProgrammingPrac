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

int main()
{
    treeNode* tree = NULL;
    int n,num;
    int n1,n2;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num);
        tree = insertNode(tree,num);
    }

    return 0;
}