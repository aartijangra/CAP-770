//bst basic code having functions insertion traversing searching and deletion
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class bst
{
    node *root;

public:
    bst()
    {
        root = NULL;
    }
    void insert(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            node *current = root;
            node *parent = NULL;
            while (1)
            {
                parent = current;
                if (data < parent->data)
                {
                    current = current->left;
                    if (current == NULL)
                    {
                        parent->left = temp;
                        return;
                    }
                }
                else
                {
                    current = current->right;
                    if (current == NULL)
                    {
                        parent->right = temp;
                        return;
                    }
                }
            }
        }
    }
    void inorder(node *temp)
    {
        if (temp != NULL)
        {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }
    void preorder(node *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }
    void postorder(node *temp)
    {
        if (temp != NULL)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " ";
        }
    }
    void display()
    {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
    node *search(int data)
    {
        node *current = root;
        cout << "Visiting elements: ";
        while (current->data != data)
        {
            if (current != NULL)
                cout << current->data << " ";
            if (current->data > data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
            if (current == NULL)
            {
                return NULL;
            }
        }
        return current;
    }
    void deleteNode(int data)
    {
        node *current = root;
        node *parent = root;
        bool isLeft = true;
        while (current->data != data)
        {
            parent = current;
            if (current->data > data)
            {
                isLeft = true;
                current = current->left;
            }
            else
            {
                isLeft = false;
                current = current->right;
            }
            if (current == NULL)
            {
                cout << "Element not found" << endl;
                return;
            }
        }
        if (current->left == NULL && current->right == NULL)
        {
            if (current == root)
            {
                root = NULL;
            }
            if (isLeft)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        else if (current->right == NULL)
        {
            if (current == root)
            {
                root = current->left;
            }
            else if (isLeft)
            {
                parent->left = current->left;
            }
            else
            {
                parent->right = current->left;
            }
        }
        else if (current->left == NULL)
        {
            if (current == root)
            {
                root = current->right;
            }
            else if (isLeft)
            {
                parent->left = current->right;
            }
            else
            {
                parent->right = current->right;
            }
        }
        else
        {
            node *successor = getSuccessor(current);
            if (current == root)
            {
                root = successor;
            }
            else if (isLeft)
            {
                parent->left = successor;
            }
            else
            {
                parent->right = successor;
            }
            successor->left = current->left;
        }
    }
    node *getSuccessor(node *delNode)
    {
        node *successor = delNode;
        node *successorParent = delNode;
        node *current = delNode->right;
        while (current != NULL)
        {
            successorParent = successor;
            successor = current;
            current = current->left;
        }
        if (successor != delNode->right)
        {
            successorParent->left = successor->right;
            successor->right = delNode->right;
        }
        return successor;
    }
};

