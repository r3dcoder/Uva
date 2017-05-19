# Uva

#include <bits/stdc++.h>

using namespace std;
vector<string>s;

struct node
{
    bool endmark;
    int cnt = 0;
    node* next[10 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }
} * root;

void insert(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt++;
    }
    curr->endmark = true;
}

int search(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        curr = curr->next[id];
    }
    return curr->cnt;
}

void del(node* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        bool flag = 0;
        root = new node();
        int num;
        cin >> num;
        for (int i = 1; i <= num; i++)
        {
            string str;
            cin>>str;
            s.push_back(str);
            insert(str, str.size());
        }

        for (int i = 0; i < s.size(); i++)
        {
            if ( search(s[i], s[i].size()) > 1 )
                flag = 1;
        }
        if( flag == 1 )
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        del(root);
        for(int i = 0; i<s.size(); i++)
        {
            s[i].clear();
        }

    }
    return 0;
}


