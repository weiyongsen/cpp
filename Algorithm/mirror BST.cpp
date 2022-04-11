#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
       node *l,*r;
};
int a[1005],p1[1005],p2[1005];
int pre=0,preor=0,flag1=1,flag2=1,space1=0,space2=0;
node *create(node *root,int x){
    if(root==NULL){
        root=new node;
        root->data=x;
        root->l=root->r=NULL;
        return root;
    }
    else{
        if(x<root->data)
            root->l=create(root->l,x);
        else
            root->r=create(root->r,x);
    }
    return root;
}
void preorder(node *root)
{
    if(root){
        p1[pre++]=root->data;
        preorder(root->l);
        preorder(root->r);
    }
}
void preorder2(node *root){
    if(root){
        p2[preor++]=root->data;
        preorder2(root->r);
        preorder2(root->l);
    }
}
void finallshow1(node *root){
    if(root){
        finallshow1(root->l);
        finallshow1(root->r);
        if(space1==0){
            cout<<root->data;
            space1=1;
        }
        else
            cout<<" "<<root->data;
    }
}
void finallshow2(node *root){
    if(root){
        finallshow2(root->r);
        finallshow2(root->l);
        if(space2==0){
            cout<<root->data;
            space2=1;
        }
        else
            cout<<" "<<root->data;
    }
}
int main(){
    int n;
    cin>>n;
    node *root=NULL;
    for(int i=0;i<n;i++){
        cin>>a[i];
        root=create(root,a[i]);
    }
    preorder(root);
    preorder2(root);
    for(int i=0;i<n;i++){
        if(a[i]!=p1[i])
        {
            flag1=0;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=p2[i])
        {
            flag2=0;
            break;
        }
    }
    if(flag1){
        cout<<"YES"<<endl;
        finallshow1(root);
    }
    else if(flag2){
        cout<<"YES"<<endl;
        finallshow2(root);
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
