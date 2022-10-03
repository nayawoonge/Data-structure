#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//INT_MAX  : +2,147,483,647  Maximum value for an int
//INT_MIN  : -2,147,483,648  Minimum value for an int


typedef struct _TreeNode 
{
    int data;
    struct _TreeNode* left, * right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p) 
{
    if (top < SIZE - 1) stack[++top] = p;
}

TreeNode* pop() 
{
    TreeNode* p = NULL;
    if (top >= 0) p = stack[top--];
    return p;
}

void inorder_iter(TreeNode* root) 
{
    while (1) 
    {
        for (;root;root = root->left) push(root);
        root = pop();
        if (!root) break;
        printf("[%d]", root->data);
        root = root->right;
    }
}

int numOfNonTerminals(TreeNode* node) 
{
    int count = 0;
    if (node == NULL) 
    {
        return 0;
    }
    else if (node->left == NULL && node->right == NULL) 
    {
        return 0;
    }
    else 
    {
        count += 1 + numOfNonTerminals(node->left) + numOfNonTerminals(node->right);
    }
    return count;
}

int isEqual(TreeNode* p, TreeNode* q)
{
    if (p == NULL && q == NULL)
        return 1;
    else if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        return 0;
    else if (p->data == q->data)
        return (isEqual(p->left, q->left)&&isEqual(p->right,q->right));
    else
        return 0;
}


int min_val(TreeNode* p) 
{
    int min = p->data;
    if (p == NULL) return 2147483647;
    while (1) {
        for (;p;p = p->left) push(p);
        p = pop();
        if (!p) break;
        if (min > p->data) min = p->data;
        p = p->right;
    }
    return min;
}

int get_height(TreeNode* node)
{
    int height = 0;
    if (node != NULL)
        height = 1 + max(get_height(node->left), get_height(node->right));
    return height;
}

int isBalanced(TreeNode* node)
{
    int b;
    if (node == NULL) return 1;
    b = get_height(node->left) - get_height(node->right);
    if (b > 1 || b < -1)
        return 0;
    else
        return (isBalanced(node->left) && isBalanced(node->right));
}

int get_sum(TreeNode* node) 
{
    int sum = 0;
    if (node != NULL) 
    {
        sum += node->data + get_sum(node->left) + get_sum(node->right);
    }
    return sum;
}

int havingOneChild(TreeNode* node) 
{
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return 0;
    else if (node->left == NULL && node->right != NULL)
        return 1 + havingOneChild(node->right);
    else if (node->left != NULL && node->right == NULL)
        return 1 + havingOneChild(node->left);
    else if (node->left != NULL && node->right != NULL)
        return havingOneChild(node->left) + havingOneChild(node->right);
    return 0;
}

void decrement(TreeNode* node) 
{
    if (node != NULL) 
    {
        node->data -= 1;
        decrement(node->left);
        decrement(node->right);
    }
}

int main() 
{

    TreeNode n1 = { 1,NULL,NULL };  //          15
    TreeNode n2 = { 4,&n1,NULL };   //         4    20
    TreeNode n3 = { 16,NULL,NULL }; //      1       16  25
    TreeNode n4 = { 25,NULL,NULL };
    TreeNode n5 = { 20,&n3,&n4 };
    TreeNode n6 = { 15,&n2,&n5 };
    TreeNode* root1 = &n6;

    //TreeNode r1 = { 1,NULL,NULL };
    TreeNode r2 = { 4,NULL,NULL };  //          15
    TreeNode r3 = { 16,NULL,NULL }; //      4       20
    TreeNode r4 = { 25,NULL,NULL }; //          16      25
    TreeNode r5 = { 20,&r3,&r4 };
    TreeNode r6 = { 15,&r2,&r5 };
    TreeNode* root2 = &r6;

    printf(" root1 노드 : ");    
    inorder_iter(root1);
    printf(" root2 노드 :");
    inorder_iter(root2);
    printf("\n 비단말 노드 개수 : %d", numOfNonTerminals(root1));
    printf("\n 구조가 같은가 ? : %d", isEqual(root1, root2));
    printf("\n root2 노드 중 최소값 : %d", min_val(root2));
    printf("\n root2 모든 노드의 합 : %d", get_sum(root2));
    printf("\n 자식이 하나만 있는 노드 수 : %d", havingOneChild(root1));
    decrement(root1);
    printf("\n 키 값을 1 낮춘root1 노드 : ");    inorder_iter(root1);
    return 0;
}