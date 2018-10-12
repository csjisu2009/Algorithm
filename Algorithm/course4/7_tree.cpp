//time   : 5h 0m

/*review : use array is easy!!
*/
#include <stdio.h>
#include <iostream>
using namespace std;

#define DataType char
#define stature(p) ((p) ? (p)->height : -1)

class BinNode{
public:
    BinNode* parent;
    BinNode* lChild;
    BinNode* rChild;
    DataType data;
    int height;
    int size();

    BinNode();
    BinNode(DataType const& e);
    BinNode* insertAsLC(DataType const& e);
    BinNode* insertAsRC(DataType const& e);
};

int BinNode::size(){
    int s = 1;
    if(lChild) s += lChild->size();
    if(rChild) s += rChild->size();
    return s;
}

BinNode:: BinNode(){
    parent = NULL;
    lChild = NULL;
    rChild = NULL;
}

BinNode:: BinNode(DataType const& e){
    this->data = e;
}

BinNode* BinNode::insertAsLC(DataType const& e){
    return lChild = new BinNode(e);
}

BinNode* BinNode::insertAsRC(DataType const& e){
    return rChild = new BinNode(e);
}

int max(int a, int b){
    if(a <= b) return b;
    else return a;
}

class BinTree{
protected:
    int _size;
    BinNode* _root;
    virtual int updateHeight(BinNode* x);
    void updateHeightAbove(BinNode* x);
public:
    int size() const{return _size;}
    bool empty() const{return !_root;}
    BinNode* root() const{return _root;}
    BinNode* insertAsLC(BinNode* x, DataType const& e);
    BinNode* insertAsRC(BinNode* x, DataType const& e);
    void createTree(BinNode* x, DataType const& e, DataType const& le, DataType const& re);
    void traversePre(BinNode* x);
    void traverseIn(BinNode* x);
    void traversePost(BinNode* x);
    void initializeRoot(BinNode* x){_root = x;}
    void initializeBinTree(int n);
    void printNode(BinNode* x){printf("%c", x->data);}
};

int BinTree::updateHeight(BinNode* x){
    return x->height = 1 + max(stature(x->lChild), stature(x->rChild));
}

void BinTree::updateHeightAbove(BinNode* x){
    while(x){
        updateHeight(x);
        x = x->parent;
    }
}

BinNode* BinTree::insertAsLC(BinNode* x, DataType const& e){
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lChild;
}

BinNode* BinTree::insertAsRC(BinNode* x, DataType const& e){
        _size++;
        x->insertAsRC(e);
        updateHeightAbove(x);
        return x->rChild;
}

void BinTree::createTree(BinNode* x, DataType const& e, DataType const& le, DataType const& re){
    if(le== '.' && re =='.') return;// why do not have this line, the example input end at 'E . .'(terminate after this input)??
    if(!x) return;
    if(x->data < 65 || 90 < x->data) return;
    if(x->data == e){
        //printf("x->data(%c) == e(%c)\n", x->data, e);
        if(le != '.') x->insertAsLC(le);
        else if(le == '.') x->lChild = NULL;
        if(re != '.') x->insertAsRC(re);
        else if(re == '.') x->rChild = NULL;
        return;
    }
    if(x->lChild) createTree(x->lChild, e, le, re);
    if(x->rChild) createTree(x->rChild, e, le, re);
}

void BinTree::traversePre(BinNode* x){
    if(!x) return;
    if(x->data < 65 || 90 < x->data) return;
    printf("%c", x->data);
    traversePre(x->lChild);
    traversePre(x->rChild);
}

void BinTree::traverseIn(BinNode* x){
    if(!x) return;
    if(x->data < 65 || 90 < x->data) return;
    traverseIn(x->lChild);
    printf("%c", x->data);
    traverseIn(x->rChild);
}

void BinTree::traversePost(BinNode* x){
    if(!x) return;
    if(x->data < 65 || 90 < x->data) return;
    traversePost(x->lChild);
    traversePost(x->rChild);
    printf("%c", x->data);
}

 void BinTree::initializeBinTree(int n){
        char ch = 'A';
        BinNode* node = new BinNode(ch);
        this->initializeRoot(node);

        char root, lc, rc;
        for(int i = 0 ; i < n ; i++){
            cin >> root >> lc >> rc;
            //scanf("%c %c %c", &root, &lc, &rc);//why this input have problem(if input A B C, root : , lc: A, rc: B)
            createTree(node, root, lc, rc);
        }
    }

int main(){
    
    int n;
    scanf("%d", &n);
    BinTree* binTree = new BinTree();

    binTree->initializeBinTree(n);

    binTree->traversePre(binTree->root()); printf("\n");
    binTree->traverseIn(binTree->root()); printf("\n");
    binTree->traversePost(binTree->root()); printf("\n");
    return 0;
}