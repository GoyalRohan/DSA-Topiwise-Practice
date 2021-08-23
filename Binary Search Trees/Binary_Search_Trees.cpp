#include<iostream>
using namespace std;

struct node
{
    int data;
    node *lchild;
    node *rchild;
};

class BST
{

    public:
        node *root;
        BST()
        {
            root = NULL;
        }

        void insert(int key);
        node* Rinsert(node *p , int key);
        node *Delete(node *p , int key);
        int height(node *p);
        node *inPre(node *p);
        node *inSuc(node *p);
        
        node* search(node *root , int key)
        {
            if(root == NULL)
                return NULL;

            node *t = root;
            while(t != NULL)
            {
                if(key == t->data)
                    return t;
                else if(key <t->data)
                    t = t->lchild;
                else
                    t = t->rchild;
            }
            return NULL;
        }

        void inorder(node* root)
        {
            if(root)
            {
                inorder(root->lchild);
                cout<<root->data<<" ";
                inorder(root->rchild);
            }
        }

        
};

void BST :: insert(int key)
{
    node *p , *t = root , *r = NULL;
    if(root == NULL)
    {
        p = new node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while(t != NULL)
    {
        r = t;
        
       
       
        if(t->data > key)
            t = t->lchild;
        else if(t->data<key)
            t = t->rchild;
        else
            return;
    }


    p = new node;
    p->data = key;
    p->lchild = p->rchild = NULL; 
    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
    
}


node* BST :: Rinsert(node *p , int key)
{
    node *t = NULL;
    if(p == NULL)
    {
        t = new node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key <p->data)
        p->lchild = Rinsert(p->lchild , key);

    else if(key >p->data)
        p->rchild = Rinsert(p->rchild , key);

    return p;
}

int BST :: height(node *p)
{
    if(p == NULL)
        return NULL;

    int x , y;
    x = height(p->lchild);
    y = height(p->rchild);

    if(x>y)     return x+1;
    else        return y+1;
}

node * BST :: inPre(node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

node * BST :: inSuc(node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;

    return p;
}

node * BST :: Delete(node *p , int key)
{
    node *q;
    if(p == NULL)
        return NULL;

    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        root=NULL;
        free(p);
        return NULL;
    }

    if(key < p->data)
        p->lchild = Delete(p->lchild , key);

    else if(key > p->data)
        p->rchild = Delete(p->rchild , key);

    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild , q->data);
        }

        else
        {
            q = inSuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild , q->data);
        }

    }
    return p;
}




int main(){
    BST tree1;

    tree1.root = tree1.Rinsert(tree1.root ,50);
    tree1.Rinsert(tree1.root , 10);
    tree1.Rinsert(tree1.root , 40);
    tree1.Rinsert(tree1.root , 20);
    tree1.Rinsert(tree1.root , 30);

    tree1.inorder(tree1.root);

    tree1.Delete(tree1.root , 20);

    cout<<endl;
    tree1.inorder(tree1.root);

    node *temp;
    temp = tree1.search(tree1.root, 5);
    cout<<endl;
    if(temp)
        cout<<"ELEMENT"<<temp->data <<" IS FOUND";
    else
        cout<<"ELEMENT IS NOT FOUND";

    return 0;
}