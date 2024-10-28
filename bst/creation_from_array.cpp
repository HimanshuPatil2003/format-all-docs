#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Node* insertIntoBst(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data<root->data){
        root->left=insertIntoBst(root->left,data);
    }
    else{
        root->right=insertIntoBst(root->right,data);
    }
    return root;
}
void takeinput(Node*&root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBst(root,data);
        cin>>data;
    }
}
int minValue(Node* root){
    
    Node* temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp->left !=NULL){
        temp=temp->left;
    }
    return temp->data;
    
}
int maxValue(Node* root){
    
    Node* temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp->right !=NULL){
        temp=temp->right;
    }
    return temp->data;
    
}
Node* findNode(Node* root,int key){
    //base case
    cout<<"all received for "<<root->data<<endl;
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return findNode(root->left,key);
    }else{
        return findNode(root->right,key);
    }
    return root;
}

void levelordertraversal(Node*& root){
if(root==NULL) return ;
queue<Node*> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
Node* temp=q.front();
q.pop();
if(temp==NULL){
cout<<endl;
if(!q.empty()){
q.push(NULL);
}
}
else{
cout<<temp->data<<" ";
if(temp->left){
q.push(temp->left);
}
if(temp->right){
q.push(temp->right);
}
}
}
}
Node* deleteNode(Node* root,int target){
    if(root==NULL)
        return NULL;
    if(root->data==target){

        //4 csaes exist
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            Node* child=root->left;
            delete root;
            return child;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* child=root->right;
            delete root;
            return child;
        }else{
            //both child exists
            int inopre=maxValue(root->left);
            root->data=inopre;
            root->left=deleteNode(root->left,inopre);
            return root;
        }
    }else{
        if(root->data>target){
            root->left=deleteNode(root->left,target);
        }else{
            root->right=deleteNode(root->right,target);
        }
    }
    return root;
}
bool validBST(Node* root,int lower,int upper){
    if(root==NULL){
        return true;
    }
    if(root->data>lower && root->data<upper){
        bool leftans=validBST(root->left,lower,root->data);
        bool rightans=validBST(root->right,root->data,upper);
        return leftans&&rightans;
    }else{
        return false;
    }
}
Node* lcaBST(Node* root, int p,int q){
    if(root==NULL){
        return NULL;
    }
    if(root->data>p && root->data>q){
        return lcaBST(root->left,p,q);
    }
    else if(root->data<p && root->data<q){
        return lcaBST(root->right,p,q);
    }else 
    return root;

}
void inorder(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);

}
int kthelement(Node* root,int k){
    vector<int> ans;
    inorder(root,ans);
    return ans[k-1];
}
int main(){
    cout<<"aenter input"<<endl;
    Node* root=NULL;
    takeinput(root);
    levelordertraversal(root);
    // cout<<endl<<"min value :"<< minValue(root)<<endl;
    // cout<<endl<<"max value :"<< maxValue(root)<<endl;
    
    
    
    // root=deleteNode(root,100);
    cout<<endl;
    levelordertraversal(root);
    cout<<endl<<validBST(root,INT_MIN,INT_MAX)<<endl;
    Node* newnode=lcaBST(root,25,125);
    cout<<"LCA is "<<newnode->data<<endl;

    cout<<"Kth element is "<<kthelement(root,9)<<endl;
return 0;
}