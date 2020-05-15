#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>


using namespace std;


struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int value)
    {
        data= value;
        next = NULL;
        prev = NULL;
    }
};

class CircularList
{
    private:
        Node* root;
    public:
        CircularList()
        {
            root = NULL;
            //size = 0;
        }

        void appendList(int value)
        {
            if(root == NULL)
            {
                root = new Node(value);
                root->next = root;
                root->prev = root;
            }
            else
            {
                Node *temp = root;
                while(temp->next != root)
                {
                    temp = temp->next;
                }
                Node *newNode = new Node(value);
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = root;
            }
        }
        void insertToList(int value, int pos)
        {
            pos = pos-1;
            for(int i = 0; i < pos; i++)
            {
                root = root->next;
            }
            Node *newNode = new Node(value);
            newNode->prev = root;
            newNode->next = root->next;
            root->next = newNode;
            root = newNode;
        }
        void deleteOffList(int position)
        {
            position--;
            for(int i = 0; i < position; i++)
            {
                root = root->next;
            }
            root->prev->next = root->next;
            root->next->prev = root->prev;
            root = root->next;       
            //delete temp;
        }
        void printList(int pos)
        {
            pos--;
            for(int i = 0; i<pos; i++)
            {
                root= root->next;
            }
            cout<<root->data<<endl;
        }
};

int main()
{
    int n, option,q;
    int num;
    CircularList c;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>num;
        c.appendList(num);
    }
    cin>>q;

    for (int i = 0; i < q; i++)
    {
        cin>>option;

        if(option == 1)
        {
            int pos;
            int val;
            cin>>pos;
            cin>>val;
            c.insertToList(val,pos);
        }

        if (option == 2)
        {
            int pos;
            cin>>pos;
            c.deleteOffList(pos);
        }

        if (option == 3)
        {
            int pos;
            cin>>pos;
            c.printList(pos);
        }
    }
    return 0;
}