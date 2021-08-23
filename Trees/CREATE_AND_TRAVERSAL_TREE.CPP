#include<iostream>
#include<queue>
using namespace std;

struct node
{
    node *lchild;
    int data;
    node *rchild;
};

class Tree
{
    node *root;

    public:
        Tree()
        {   
            root = NULL;
        }

        void create();
        void preorder(node *);
        void postorder(node *);
        void inorder(node *);
        void levelorder(node *);
        int height(node *);
        int count(node *);
        int height()
        {
            height(root);
        }
        int count()
        {
            count(root);
        }

        void display(int x)
        {
            if(x == 1)
            {
                cout<<"The preorder traversal is : ";
                preorder(root);

            }
            else if(x == 2)
            {
                cout<<"The postorder traversal is : ";
                postorder(root);
            }
                
            else if(x == 3)
            {
                cout<<"The inorder traversal is : ";
                inorder(root);
            }
                
            else if(x == 4)
            {
                cout<<"The levelorder traversal is : ";
                levelorder(root);
            }
                
        }
};

void Tree :: create()
{
    node *p , *t;
    int x;
    queue<node *> q;
    cout<<"Enter the value of root node = ";
    cin>>x;

    root = new node;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.emplace(root);

    while(!q.empty())
    {
        p = q.front();
        q.pop();

        cout<<"Enter the left child of"<<p->data<<" = ";
        cin>>x;
        if(x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.emplace(t);
        }

        cout<<"Enter the right child of "<<p->data<<" = ";
        cin>>x;
        if(x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.emplace(t);
        }
    }  
}

void Tree :: preorder(node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void Tree :: inorder(node *root)
{
    if(root != NULL)
    {
        preorder(root->lchild);
        cout<<root->data<<" ";
        preorder(root->rchild);
    }
}

void Tree :: postorder(node *root)
{
    if(root != NULL)
    {
        preorder(root->lchild);
        preorder(root->rchild);
        cout<<root->data<<" ";
    }
}

void Tree :: levelorder(node *root)
{
    queue<node *> q;
    cout<<root->data<<" ";
    q.push(root);

    while( !q.empty())
    {
        root = q.front();
        q.pop();

        if(root->lchild)
        {
            cout<<root->lchild->data<<" ";
            q.push(root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data<<" ";
            q.push(root->rchild);
        }
    }
}


int Tree :: height(node *root)
{
    if(root)
    {
        int x , y;
        x = height(root->lchild);
        y = height(root->rchild);
        return max(x , y) +1;
    }
    return 0;
}

int Tree :: count(node *root)
{
    if(root)
    {
        int x , y;
        x = count(root->lchild);
        y = count(root->rchild);
        return x+ y+1;
    }
    return 0;
}


int main(){
    
    Tree T;
    T.create();
    T.display(4);
    cout<<endl<<"The height of the tree is : "<<T.height();
    cout<<endl<<"The no of nodes in the tree is : "<<T.count();
    return 0;
}