/*
level wise input
print level wise
inorder
postorder
preorder
height
*/

#include <bits/stdc++.h>
// #define EXIT_SUCCESS 0;
using namespace std;

template <typename T>
class binaryTree
{
public:
    T data;
    binaryTree<T> *left;
    binaryTree<T> *right;

    binaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binaryTree()
    {
        delete left;
        delete right;
    }
};

binaryTree<int> *levelwiseinput()
{
    cout << "enter the root data" << endl;
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1)
    {
        cout << "WARNING: root data required" << endl;
    }
    else
    {
        queue<binaryTree<int> *> pendingnode;
        binaryTree<int> *root = new binaryTree<int>(rootdata);
        pendingnode.push(root);
        while (pendingnode.size() != 0)
        {
            binaryTree<int> *current = pendingnode.front();
            pendingnode.pop();

            // taking left child

            cout << "left child data of " << current->data << endl;
            int leftchilddata;
            cin >> leftchilddata;
            if (leftchilddata != -1)
            {
                binaryTree<int> *leftchild = new binaryTree<int>(leftchilddata);
                current->left = leftchild;
                pendingnode.push(leftchild);
            }

            // taking right child
            cout << "right child data of " << current->data << endl;
            int rightchilddata;
            cin >> rightchilddata;
            if (rightchilddata != -1)
            {
                binaryTree<int> *rightchild = new binaryTree<int>(rightchilddata);
                current->right = rightchild;
                pendingnode.push(rightchild);
            }
        }
        return root;
    }
}

void printlevelwise(binaryTree<int> *root)
{
    if (root == NULL)
    {
        cout << "******* no tree found *******" << endl;
        return;
    }
    else
    {
        queue<binaryTree<int> *> pendingnode;
        pendingnode.push(root);
        while (pendingnode.size() != 0)
        {
            binaryTree<int> *current = pendingnode.front();
            pendingnode.pop();
            cout << current->data << ":";
            if (current->left)
            {
                pendingnode.push(current->left);
                cout << "L:" << current->left->data;
            }
            else
            {
                cout << "L:-1";
            }
            cout << ",";

            if (current->right)
            {
                pendingnode.push(current->right);
                cout << "R:" << current->right->data << endl;
            }
            else
            {
                cout << "R:-1" << endl;
            }
        }
    }
}

void preorder(binaryTree<int> *root)
{
    if (root == NULL)
    {
        // cout << "******* no tree found *******" << endl;
        return;
    }
    else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(binaryTree<int> *root)
{
    if (root == NULL)
    {
        // cout << "******* no tree found *******" << endl;
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void inorder(binaryTree<int> *root)
{
    if (root == NULL)
    {
        // cout << "******* no tree found *******" << endl;
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

/*void height(binaryTree<int> *root)
{
    if (root == NULL)
        return;
    int leftHeight = -1, rightHeight = -1;
    if (root->left)
    {
        leftHeight = height(root->left);
    }
    if (root->right)
        rightHeight = height(root->right);

    return  (max(leftHeight, rightHeight) + 1) ;
}*/
bool findnode(binaryTree<int> *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == x)
    {
        return true;
    }
    else
    {
        return findnode(root->left, x) || findnode(root->right, x);
    }
}

binaryTree<int> *getlargestnode(binaryTree<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    binaryTree<int> *maxlargestNode = root;

    if (root->left != NULL)
    {
        binaryTree<int> *leftlargestdata = getlargestnode(root->left);
        if (maxlargestNode->data < leftlargestdata->data)
        {
            maxlargestNode = leftlargestdata;
        }
    }

    if (root->right != NULL)
    {
        binaryTree<int> *rightmaxdata = getlargestnode(root->right);
        if (maxlargestNode->data < rightmaxdata->data)
        {
            maxlargestNode = rightmaxdata;
        }
    }
    return maxlargestNode;
}
void statement()
{

    cout << "-----------------------------------------" << endl;
    cout << "                                         " << endl;
    cout << "                                         " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|                                  |" << endl;
    cout << "|                                  |" << endl;
    cout << "|  1: Enter data Level wise"
         << "        |" << endl;
    cout << "|  2: print data level wise"
         << "        |" << endl;
    cout << "|  3: Inorder              "
         << "        |" << endl;
    cout << "|  4: preorder             "
         << "        |" << endl;
    cout << "|  5: postorder            "
         << "        |" << endl;
    cout << "|  6: Find Node in tree    "
         << "        |" << endl;
    cout << "|  7: largest data         "
         << "        |" << endl;
    cout << "|  8: Mirror               "
         << "        |" << endl;
    cout << "|  9: Diameter             "
         << "        |" << endl;
    cout << "|  10: Height               "

         << "        |" << endl;
    cout << "|  11: Exit                 "
         << "        |" << endl;
    cout << "|                                  |" << endl;
    cout << "|                                  |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "                                         " << endl;
    cout << "                                         " << endl;
    cout << "-----------------------------------------" << endl;
}
void bahar()
{
    cout << "thanks you.....!!( happy Coding );" << endl;
    EXIT_SUCCESS;
}
void mirror(binaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    binaryTree<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
int height(binaryTree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int diameter(binaryTree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftdiameter = diameter(root->left);
    int rightdiameter = diameter(root->right);

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return max(max(leftdiameter, rightdiameter), leftheight + rightheight + 1);
}
int main()
{
    // cout << "enter the data in the tree" << endl;
    binaryTree<int> *root;                 // use to take input element
    binaryTree<int> *largestdatainthetree; // for largest node
    int n;
    // statement();
    do
    {
        statement();
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "enter the data in the tree" << endl;
            cout << "          " << endl;
            root = levelwiseinput();
            break;
        case 2:
            printlevelwise(root);
            cout << "\n";
            break;
        case 3:
            inorder(root);
            cout << "\n";
            break;
        case 4:
            preorder(root);
            cout << "\n";
            break;
        case 5:
            postorder(root);
            cout << "\n";
            break;
        case 6:
            cout << "enter the data you want to search" << endl;
            int x;
            cin >> x;
            findnode(root, x);
            cout << "\n";
            break;
        case 7:
            largestdatainthetree = getlargestnode(root);
            cout << "the largest data in the tree is " << endl;
            cout << largestdatainthetree->data << endl;
            break;
        case 8:
            mirror(root);
            cout << "to print the tree press 2" << endl;
            break;

        case 9:
            cout << diameter(root);
            break;
        case 10:
            cout << "the height of the tree is" << endl;
            cout << height(root) << endl;
        case 11:
            bahar();
            break;
        default:
            cout << "please enter valid input" << endl;
            cout << "\n";
        }

    } while (n != -1);
}
