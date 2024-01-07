// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
// };
// struct Node *createNode(int data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

//     newNode->data = data;
//     newNode->right = NULL;
//     newNode->left = NULL;
//     return newNode;
// }

// struct Node *insertNode(struct Node *root, int data)
// {
//     if (root == NULL)
//     {
//         return createNode(data);
//     }
//     else if (data < root->data)
//     {
//         root->left = insertNode(root->left, data);
//     }
//     else
//     {
//         root->right = insertNode(root->right, data);
//     }
//     return root;
// }

// void inorder(struct Node *root)
// {
//     if (root != NULL)
//     {
//         inorder(root->left);
//         printf("%d ", root->data);
//         inorder(root->right);
//     }
// }
// void preorder(struct Node *root)
// {
//     if (root != NULL)
//     {
//         printf("%d ", root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }
// void postorder(struct Node *root)
// {
//     if (root != NULL)
//     {
//         postorder(root->left);
//         postorder(root->right);
//         printf("%d ", root->data);
//     }
// }
// struct Node *find_min(struct Node *root)
// {

//     struct Node *temp = root;
//     while (root->left != NULL)
//     {
//         root = root->left;
//     }
//     return root;
// }
// struct Node *deleteNode(struct Node *root, int data)
// {
//     if (root == NULL)
//     {
//         return root;
//     }
//     if (data > root->data)
//     {
//         root->right = deleteNode(root->right, data);
//     }
//     else if (data < root->data)
//     {
//         root->left = deleteNode(root->left, data);
//     }
//     else
//     {
//         struct Node *temp;
//         if (root->right == NULL && root->left == NULL)
//         {

//             free(root);
//             return NULL;
//         }
//         else if (root->left == NULL)
//         {
//             temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL)
//         {
//             temp = root->left;
//             free(root);
//             return temp;
//         }
//         else
//         {
//             temp = find_min(root->right);
//             root->data = temp->data;
//             root->right = deleteNode(root->right, temp->data);
//         }
//         return root;
//     }
// }
// int main()
// {
//     int choice, data;
//     struct Node *root = NULL;
//     while (choice != 6)
//     {
//         printf("\nBinary Search Tree Menu:\n");
//         printf("1. Insert\n");
//         printf("2. Inorder Traversal\n");
//         printf("3. Preorder Traversal\n");
//         printf("4. Postorder Traversal\n");
//         printf("5. Delete\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter the node data to insert: ");
//             scanf("%d", &data);
//             root = insertNode(root, data);
//             break;
//         case 2:
//             inorder(root);
//             printf("\n");
//             break;
//         case 3:
//             preorder(root);
//             printf("\n");
//             break;
//         case 4:
//             postorder(root);
//             printf("\n");
//             break;
//         case 5:
//             printf("Enter the node data to deleteNode: ");
//             scanf("%d", &data);
//             root = deleteNode(root, data);
//             break;
//         case 6:
//             choice == 6;
//             break;
//         default:
//             break;
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *rchild, *lchild;
} *root;

struct Node *Search(struct Node *t, int key)
{
    if (t == NULL)
    {
        return NULL;
    }
    else if (key == t->data)
    {
        return t;
    }
    else if (key > t->data)
    {
        return Search(t->rchild, key);
    }
    else if (key < t->data)
    {
        return Search(t->lchild, key);
    }
}

struct Node *Rinsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    else if (key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }
    return p;
}

struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

int Height(struct Node *root)
{
    int x, y;
    if (root == NULL)
    {
        return 0;
    }
    x = Height(root->lchild);
    y = Height(root->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *rdelete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            free(p);
            return NULL;
        }
        free(p);
        return NULL;
    }
    if (key < p->data)
    {
        p->lchild = rdelete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rdelete(p->rchild, key);
    }
    else
    {
        if (p->lchild != NULL)
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = rdelete(p->lchild, key);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = rdelete(p->rchild, key);
        }
    }
    return p;
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

struct Node *mirrorImage(struct Node *root)
{
    struct Node *temp;
    if (root)
    {
        mirrorImage(root->lchild);
        mirrorImage(root->rchild);

        // Swap the left and right children
        temp = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;
    }
    return root;
}

int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
}

int countInternalNodes(struct Node *root)
{
    if (root == NULL || (root->lchild == NULL && root->rchild == NULL))
    {
        return 0;
    }
    return 1 + countInternalNodes(root->lchild) + countInternalNodes(root->rchild);
}

void displayMenu()
{
    printf("\nBinary Search Tree Operations:");
    printf("\n1. Insert");
    printf("\n2. Search");
    printf("\n3. Delete");
    printf("\n4. Inorder Traversal");
    printf("\n5. Preorder Traversal");
    printf("\n6. Mirror Image");
    printf("\n7. Height of the Tree");
    printf("\n8. Count Leaf Nodes");
    printf("\n9. Count Internal Nodes");
    printf("\n0. Exit");
    printf("\nEnter your choice: ");
}

int main()
{
    int choice, key;
    struct Node *temp;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            root = Rinsert(root, key);
            break;

        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            temp = Search(root, key);
            if (temp != NULL)
            {
                printf("Element %d is found\n", temp->data);
            }
            else
            {
                printf("Not found\n");
            }
            break;

        case 3:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            root = rdelete(root, key);
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            root = mirrorImage(root);
            printf("Mirror Image created.\n");
            break;

        case 7:
            printf("Height of the Tree: %d\n", Height(root));
            break;

        case 8:
            printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
            break;

        case 9:
            printf("Number of Internal Nodes: %d\n", countInternalNodes(root));
            break;

        case 0:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
