#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public: 
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }
};

TreeNode<int>* createlevel(){
    int rootval;
    cout<<"Enter data : ";
    cin>>rootval;
    TreeNode<int>* root = new TreeNode<int>(rootval);
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        TreeNode<int>*front = pendingnodes.front();
        pendingnodes.pop();
        int n;
        cout<<"Enter the number of children : ";
        cin>>n;
        for(int i =0; i<n; i++){
            int childval;
            cout<<"Enter the "<<i<<"th child value : ";
            cin>>childval;
            TreeNode<int>*child = new TreeNode<int>(childval);
            pendingnodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}


void PrintLevel(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!= 0){
        TreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<" : ";
        for(int i =0; i<front->children.size(); i++){
            cout<<front->children[i]->data<<" , ";
            pendingnodes.push(front->children[i]);
        }
        cout<<endl;
    }
}


int numNodes(TreeNode<int>* root){
    int num = 1;
    for(int i =0; i<root->children.size(); i++){
        num += numNodes(root->children[i]);
    }
    return num;
}

void amazon(TreeNode<int>* root, int maxSum, TreeNode<int>* &Node){
    if(root->children.size()==0){
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
     int sum = 0;
    while(!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        sum +=front->data;
        for(int i = 0; i<front->children.size(); i++){
            q.push(front->children[i]);
        }
    }
    sum = sum/numNodes(root);
    if(sum > maxSum){
        maxSum= sum;
        Node = root;
    }
    for(int i = 0; i<root->children.size(); i++){
        amazon(root->children[i], maxSum, Node);
    }
}
TreeNode<int>* amazon(TreeNode<int>* root){
    TreeNode<int>* Node = NULL;
    int maxSum = 0;
    amazon(root, maxSum, Node);

    return Node;
}


int main(){
    // TreeNode<int>* root =  createlevel();
    TreeNode<int>*root = new TreeNode<int>(20);
    TreeNode<int>* child1 = new TreeNode<int>(12);
    TreeNode<int>* child2 = new TreeNode<int>(18);
    TreeNode<int>* child11 = new TreeNode<int>(2);
    TreeNode<int>* child12 = new TreeNode<int>(4);
    TreeNode<int>* child13 = new TreeNode<int>(3);
    TreeNode<int>* child21 = new TreeNode<int>(15);
    TreeNode<int>* child22 = new TreeNode<int>(8);
    // TreeNode<int>* child2 = new TreeNode<int>(15);

    root->children.push_back(child1);
    root->children.push_back(child2);
    child1->children.push_back(child11);
    child1->children.push_back(child12);
    child1->children.push_back(child13);
    child2->children.push_back(child21);
    child2->children.push_back(child22);
    
    
    // PrintLevel(root);


    TreeNode<int>* x =  amazon(root);
    PrintLevel(x);
}