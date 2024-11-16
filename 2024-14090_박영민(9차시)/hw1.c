#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
    int data;
    struct __node *left;
    struct __node *right;
    
}node;

node * insert_node(node *root, int data)
{
    if(root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        if(!root) return NULL; //fail mallocation
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data < root->data) root->left = insert_node(root->left, data);
    else if(data > root->data) root->right = insert_node(root->right, data);
    else printf("Data already exists in the tree");

    return root;

}

void find_distance(node *root, int node1, int node2)
{
    int distance = 0;
    int temp = 0;
    while(1)
    {
        root->data = node1;
        
    }

}

int main()
{
    node *root = NULL;
    int n;
    int num;
    int node1, node2;

    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&num);
        insert_node(root,num);
    }
    scanf("%d %d",&node1, &node2);
    find_distance(root, node1, node2);

    return 0;
}