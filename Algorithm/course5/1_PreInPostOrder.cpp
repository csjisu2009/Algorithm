//time   : 0h 0m

/*review : 
*/
#include <stdio.h>
#include <iostream>
using namespace std;

#define DataType int
int N;
bool bNodesPrinted[100];

class BinNode{
public:
    BinNode* parent;
    BinNode* lChild;
    BinNode* rChild;
    DataType data;
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
    void printNode(BinNode* x);
};

BinNode* BinTree::insertAsLC(BinNode* x, DataType const& e){
    _size++;
    x->insertAsLC(e);
    return x->lChild;
}

BinNode* BinTree::insertAsRC(BinNode* x, DataType const& e){
        _size++;
        x->insertAsRC(e);
        return x->rChild;
}

void BinTree::createTree(BinNode* x, DataType const& e, DataType const& le, DataType const& re){
    if(le== -1 && re == -1) return;// why do not have this line, the example input end at 'E . .'(terminate after this input)??
    if(!x) return;
    if(x->data < -1 || 99 < x->data) return;
    if(x->data == e){
        if(le != -1) x->insertAsLC(le);
        else if(le == -1) x->lChild = NULL;
        if(re != -1) x->insertAsRC(re);
        else if(re == -1) x->rChild = NULL;
        return;
    }
    if(x->lChild) createTree(x->lChild, e, le, re);
    if(x->rChild) createTree(x->rChild, e, le, re);
}

void BinTree::traversePre(BinNode* x){
    if(!x) return;
    if(x->data < -1 || 99 < x->data) return;
    printNode(x);
    traversePre(x->lChild);
    traversePre(x->rChild);
}

void BinTree::traverseIn(BinNode* x){
    if(!x) return;
    if(x->data < -1 || 99 < x->data) return;
    traverseIn(x->lChild);
    printNode(x);
    traverseIn(x->rChild);
}

void BinTree::traversePost(BinNode* x){
    if(!x) return;
    if(x->data < -1 || 99 < x->data) return;
    traversePost(x->lChild);
    traversePost(x->rChild);
    printNode(x);

}

void BinTree::initializeBinTree(int n){
        BinNode* node = new BinNode(0);
        this->initializeRoot(node);

        int root, lc, rc;
        for(int i = 0 ; i < n ; i++){
            //cin >> root >> lc >> rc;
            scanf("%d %d %d", &root, &lc, &rc);//why this input have problem(if input A B C, root : , lc: A, rc: B)
            createTree(node, root, lc, rc);
        }
    }

void BinTree::printNode(BinNode* x){
    bNodesPrinted[x->data] = true;
    printf("%d", x->data);
    for(int i = 0 ; i < N ; i++)
        if(bNodesPrinted[i] == false){
            printf(" ");
            break;
        }
}

void initializebNodePrinted(){
    for(int i = 0 ; i < N ; i++)
        bNodesPrinted[i] = false;
}

int main(){
    scanf("%d", &N);
    BinTree* binTree = new BinTree();

    binTree->initializeBinTree(N);

    initializebNodePrinted();
    binTree->traversePre(binTree->root()); printf("\n");
    initializebNodePrinted();
    binTree->traverseIn(binTree->root()); printf("\n");
    initializebNodePrinted();
    binTree->traversePost(binTree->root()); printf("\n");
    return 0;
}