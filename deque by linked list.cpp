#include <iostream>

using namespace std;

struct data
{
    data *lP=NULL;
    int n=0;
    data *rP=NULL;
};

struct myDeque
{
private:
    data *lP=NULL;
    data *rP=NULL;
    int maxN=0;
    int cnt=0;
public:
    myDeque(int maxCap)
    {
        maxN=maxCap;
    }
    void pushLeft(int a)
    {
        if (cnt==maxN)
            cout<<"The queue is full"<<endl;
        else
        {
            cout<<"Pushed in left: "<<a<<endl;
            data *ne= new data;
            ne->n=a;
            if (lP==NULL)
            {
                rP=ne;
            }
            else
            {
                lP->lP=ne;
                ne->rP=lP;
            }
            lP=ne;
            cnt++;
        }
    }
    void pushRight(int a)
    {
        if (cnt==maxN)
            cout<<"The queue is full"<<endl;
        else
        {
            cout<<"Pushed in right: "<<a<<endl;
            data *ne= new data;
            ne->n=a;
            if (rP==NULL)
            {
                lP=ne;
            }
            else
            {
                rP->rP=ne;
                ne->lP=rP;
            }
            rP=ne;
            cnt++;
        }
    }
    void popLeft()
    {
        if (cnt==0)
            cout<<"The queue is empty"<<endl;
        else
        {
            cout<<"Popped from left: "<<lP->n<<endl;
            cnt--;
            data *p = lP;
            if (lP->rP==NULL)
            {
                lP=rP=NULL;
            }
            else
            {
                lP=lP->rP;
                lP->lP=NULL;
            }
            delete p;
        }
    }
    void popRight()
    {
        if (cnt==0)
            cout<<"The queue is empty"<<endl;
        else
        {
            cout<<"Popped from right: "<<rP->n<<endl;
            cnt--;
            data *p = rP;
            if (rP->lP==NULL)
            {
                lP=rP=NULL;
            }
            else
            {
                rP=rP->lP;
                rP->rP=NULL;
            }
            delete p;
        }
    }
    int getSize()
    {
        return cnt;
    }
};

using namespace std;

int main()
{
    myDeque a(100);
    a.pushLeft(4);
    a.pushRight(5);
    cout<<"Size: "<<a.getSize()<<endl;
    a.popLeft();
    a.popRight();
    cout<<"Size: "<<a.getSize()<<endl;
    return 0;
}
