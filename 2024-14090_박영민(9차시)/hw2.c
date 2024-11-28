#include <stdio.h>
#include <stdlib.h>


typedef struct tNode
{
    int value;
    struct tNode *left;
    struct tNode *right;
}treeNode;

typedef struct queueNode_t
{
    treeNode *tree_node;
    int depth;
    struct queueNode_t *next;
}QueueNode;

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

void enqueue(QueueNode **front, QueueNode **rear, treeNode *tree_node, int depth)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->tree_node = tree_node;
    newNode->depth = depth;
    newNode->next = NULL;
    if (*rear)
    {
        (*rear)->next = newNode;
    }
    else
    {
        *front = newNode;
    }
    *rear = newNode;
}


QueueNode *dequeue(QueueNode **front, QueueNode **rear) 
{
    if (*front == NULL)
    {
        return NULL;
    }
    QueueNode *temp = *front;
    *front = (*front)->next;
    if (*front == NULL)
    {
        *rear = NULL;
    }
    return temp;
}


void BFS(treeNode *root)
{
    if (root == NULL) return;

    QueueNode *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root, 0);

    int depth = 0;
    int min = 99999, max = -99999;

    printf("%d ", depth); 

    while (front != NULL)
    {
        QueueNode *node = dequeue(&front, &rear);
        treeNode *tree_node = node->tree_node;

        if (node->depth != depth)
        {
            printf("%d %d\n", min, max);

            depth = node->depth;
            min = 99999;
            max = -99999;

            printf("%d ", depth);
        }

        if (tree_node->value < min)
        {
            min = tree_node->value;
        }
        if (tree_node->value > max)
        {
            max = tree_node->value;
        }

        if (tree_node->left)
        {
            enqueue(&front, &rear, tree_node->left, node->depth + 1);
        }
        if (tree_node->right)
        {
            enqueue(&front, &rear, tree_node->right, node->depth + 1);
        }

        free(node); 
    }

    printf("%d %d\n", min, max);
}

int main()
{
    treeNode* tree = NULL;
    int n,num;
    int depth;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num);
        tree = insertNode(tree,num);
    }

    BFS(tree);

    return 0;
}