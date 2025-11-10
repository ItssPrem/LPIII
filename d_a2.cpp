#include<bits/stdc++.h>
using namespace std;

struct node{
    int freq;
    string ch;
    node *left, *right;

    node(int freq, string ch){
        this->freq = freq;
        this->ch = ch;
        left = right = NULL;
    }
};

struct compare{
    bool operator()(node* a, node* b){
        return a->freq > b->freq;
    }
};

void print(node* root, string code){
    if(!root) return;

    // leaf node
    if(!root->left && !root->right){
        cout << root->ch << " : " << code << endl;
        return;
    }

    print(root->left, code + "0");
    print(root->right, code + "1");
}

int main(){
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<pair<string,int>> v(n);
    cout << "Enter character and its frequency:\n";
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    priority_queue<node*, vector<node*>, compare> pq;

    for(auto &p : v){
        pq.push(new node(p.second, p.first));
    }

    while(pq.size() > 1){
        node* left = pq.top(); pq.pop();
        node* right = pq.top(); pq.pop();

        node* newNode = new node(left->freq + right->freq, "$");
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    node* root = pq.top();
    cout << "\nHuffman Codes:\n";
    print(root, "");
}
