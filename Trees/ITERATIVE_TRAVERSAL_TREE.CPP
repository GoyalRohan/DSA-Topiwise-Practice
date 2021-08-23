#include<iostream>
#include<queue>
#include<stack>
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
        void iter_preorder(node *);
        void iter_postorder(node *);
        void iter_inorder(node *);
        void levelorder(node *);

        void display(int x)
        {
            if(x == 1)
            {
                cout<<"The preorder traversal is : ";
                iter_preorder(root);

            }
            else if(x == 2)
            {
                cout<<"The postorder traversal is : ";
                iter_postorder(root);
            }
                
            else if(x == 3)
            {
                cout<<"The inorder traversal is : ";
                iter_inorder(root);
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

void Tree :: iter_preorder(node *t)
{
    stack<node *> st;
    while( t != NULL || !st.empty())
    {
        if(t != NULL)
        {
            cout<<t->data<<" ";
            st.push(t);
            t = t->lchild;
        }
        else
        {
            t = st.top();
            st.pop();
            t = t->rchild;
        }
    }
}

void Tree :: iter_inorder(node *t)
{
   stack<node *> st;
    while( t != NULL || !st.empty())
    {
        if(t != NULL)
        {
            st.push(t);
            t = t->lchild;
        }
        else
        {
            t = st.top();
            st.pop();
            cout<<t->data<<" ";
            t = t->rchild;
        }
    }
}

void Tree :: iter_postorder(node *root)
{
    stack<node *>s1;
    stack<node *>s2;
    s1.push(root);

    while(!s1.empty())
    {
        node *temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->lchild)
            s1.push(temp->lchild);
        if(temp->rchild)
            s1.push(temp->rchild);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
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




int main(){
    
    Tree T;
    T.create();
    T.display(2);
    return 0;
}