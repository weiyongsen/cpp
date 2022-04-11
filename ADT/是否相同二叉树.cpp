#include<iostream>
#include<string>
using namespace std;
struct Node {
	int v;
	Node*l, *r;
};
typedef Node* ptrnode;
ptrnode build(ptrnode Root, int X) {
	if (!Root) {
		Root = new Node();
		Root->l = NULL;
		Root->r = NULL;
		Root->v = X;
	}
	else if (Root->v > X)Root->l = build(Root->l, X);
	else if (Root->v < X)Root->r = build(Root->r, X);
	return Root;
}
void preorder(ptrnode bt, string &s1) {
	if (bt) {
		s1 += to_string(bt->v);
		preorder(bt->l, s1);
		s1 += to_string(bt->v);
		preorder(bt->r, s1);
	}
}
int main() {
	int N, M, value;
	while (1) {
		ptrnode tree = NULL;
		scanf("%d", &N);
		if (N == 0)
			return 0;
		scanf(" %d", &M);
		for (int i = 0; i < N; i++) {
			scanf("%d", &value);
			tree = build(tree, value);
		}
		ptrnode temp;
		for (int i = 0; i < M; i++) {
			temp = NULL;
			for (int j = 0; j < N; j++) {
				scanf("%d", &value);
				temp = build(temp, value);
			}
			//еп╤о
			if (tree->v != temp->v)printf("No\n");
			else {
				string s1, s2;
				preorder(tree, s1);
				preorder(temp, s2);
				if (s1 == s2)printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}

