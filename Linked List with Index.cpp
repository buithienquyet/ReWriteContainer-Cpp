#include <cstdio>
#include <iostream>

using namespace std;

struct node
{
    node *left=NULL;
    int n;
    node *right=NULL;
};

struct myList
{
private:
    int numNode=400; // 400 elements have an index
    int cnt=0;
    node* xP[400]; // pointer array
    node* lastP=NULL;

    node* getPointer(int stt)
    {
        if (stt>cnt)
            return NULL;
        stt--;
        int segIdx=stt/numNode;
        int offset=stt%numNode;
        node* p=xP[segIdx];
        while (offset!=0)
        {
            offset--;
            p=p->right;
        }
        return p;
    }
public:
    void add(int a) //add an integer number to the back
    {
        int segIdx=cnt/numNode;
        int offset=cnt%numNode;
        node *newNode= new node;
        newNode->n=a;
        newNode->left=lastP;
        if (lastP!=NULL)
            lastP->right=newNode;
        lastP=newNode;
        if (offset==0)
        {
            xP[segIdx]=newNode;
        }
        cnt++;
    }
    void pop(int index) //print and delete an element by index (index start at 1)
    {
        node* p= getPointer(index);
        if (p==NULL)
            printf("none\n");
        else
        {
            index--;
            int segIdx=index/numNode;
            int offset=index%numNode;
            printf("%d\n",p->n);
            int start=(offset==0?segIdx:segIdx+1);
            for (int i=start; i<=(cnt-1)/numNode; i++) //update pointer array
            {
                xP[i]=xP[i]->right;
            }
            if (index==cnt-1)//if pop last element
            {
                if (lastP->left!=NULL)
                    {
                        lastP=lastP->left;
                        lastP->right=NULL;
                    }
                else lastP=NULL;
            }
            if (p->left!=NULL) //update link between two node
            {
                p->left->right=p->right;
            }
            if (p->right!=NULL)
            {
                p->right->left=p->left;
            }
            delete p;
            cnt--;
        }
    }
    int getSize()
    {
        return cnt;
    }
    int at(int index)
    {
        node* p= getPointer(index);
        if (p!=NULL)
            return p->n;
        return -1;
    }
};

int main()
{
    myList L;
    L.add(1);
    L.add(2);
    L.add(3);
    L.add(10);
    for (int i=1;i<=L.getSize();i++)
        cout<<L.at(i)<<endl;
    cout<<"print and pop: "<<endl;
    L.pop(1);
    L.pop(2);
    cout<<"after popped: "<<endl;
    for (int i=1;i<=L.getSize();i++)
        cout<<L.at(i)<<endl;
    return 0;
}
