#include<bits/stdc++.h>
using namespace std;
class BinaryTreeNode{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
BinaryTreeNode *binaryTreeNodeInput(){
    int rootData;
    cout<<"Enter Root Data: ";
    cin>>rootData;
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*> queueItem;
    queueItem.push(root);
    while(!queueItem.empty()){
        BinaryTreeNode *frontNode = queueItem.front();
        queueItem.pop();
        int leftChildData,rightChildData;
        cout<<"Enter Left Child Data of "<<frontNode->data<<": ";
        cin>>leftChildData;
        cout<<"Enter Right Child Data of "<<frontNode->data<<": ";
        cin>>rightChildData;
        if(leftChildData!=-1){
            BinaryTreeNode *leftNode = new BinaryTreeNode(leftChildData);
            frontNode->left = leftNode;
            queueItem.push(leftNode);
        }
        if(rightChildData!=-1){
            BinaryTreeNode *rightNode = new BinaryTreeNode(rightChildData);
            frontNode->right = rightNode;
            queueItem.push(rightNode);
        }
    }
    return root;
}
BinaryTreeNode *treeBuilderHelper(int *inorder,int *postorder,int inorderStart, int inorderEnd, int postorderStart, int postorderEnd){
    if(inorderStart>inorderEnd){
        return NULL;
    }
    int rootData = postorder[postorderEnd];
    int rootIndex = -1;
    for(int i=inorderStart;i<=inorderEnd; i++){
        if(inorder[i]==rootData){
            rootIndex = i;
            break;
        }
    }
    int rightinorderStart = rootIndex + 1;
    int rightinorderEnd = inorderEnd;
    int rightpostorderEnd = postorderEnd - 1;
    int rightpostorderStart = rightpostorderEnd-(rightinorderEnd-rightinorderStart);
    int leftinorderStart = inorderStart;
    int leftinorderEnd = rootIndex - 1;
    int leftpostorderStart = postorderStart;
    int leftpostorderEnd =  rightpostorderStart - 1;
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    root->left = treeBuilderHelper(inorder,postorder,leftinorderStart,leftinorderEnd,leftpostorderStart,leftpostorderEnd);
    root->right = treeBuilderHelper(inorder,postorder,rightinorderStart,rightinorderEnd,rightpostorderStart,rightpostorderEnd);
    return root;
}
BinaryTreeNode *treeBuilder(int *inorder,int *postorder, int sizeOfArray){
    return treeBuilderHelper(inorder,postorder,0,sizeOfArray-1,0,sizeOfArray-1);
}
void binaryTreeDisplay(BinaryTreeNode *root){
    if(root==NULL)
        return;
    queue<BinaryTreeNode *> queueItem;
    queueItem.push(root);
    while(!queueItem.empty()){
        BinaryTreeNode *frontNode = queueItem.front();
        queueItem.pop();
        cout<<frontNode->data<<": ";
        if(frontNode->left!=NULL){
            cout<<"L->"<<frontNode->left->data;
            queueItem.push(frontNode->left);
        }
        if(frontNode->right!=NULL){
            cout<<" R->"<<frontNode->right->data;
            queueItem.push(frontNode->right);
        }
        cout<<endl;
    }
}
int main(){
    //BinaryTreeNode *root = binaryTreeNodeInput();
    int inorder[] = {4,8,2,5,1,6,3,7};
    int postorder[] = {8,4,5,2,6,7,3,1};
    BinaryTreeNode *root = treeBuilder(inorder,postorder,8);
    binaryTreeDisplay(root);
}

