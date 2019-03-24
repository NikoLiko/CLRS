#include <iostream>
using namespace std;

typedef struct STreeNode* pSTreeNode;
typedef int TreeDataType;

struct STreeNode
{
    TreeDataType data;
    pSTreeNode pFirstChild;
    pSTreeNode pNextBrother;

    STreeNode(TreeDataType Value)
    {
        data = Value;
        pFirstChild = NULL;
        pNextBrother = NULL;
    }
};

class CTree
{
public:
    CTree();
    CTree(TreeDataType Value);
    ~CTree();

public:
    void Insert(TreeDataType parentValue,TreeDataType Value);
    void InsertBrother(pSTreeNode pParentNode,TreeDataType Value);

    pSTreeNode Search(pSTreeNode pNode,TreeDataType Value);

    void Preorder(pSTreeNode pNode);
    void Inorder(pSTreeNode pNode);
    void postorder(pSTreeNode pNode);

    void PrintNode(pSTreeNode pNode);
    void FreeMemory(pSTreeNode pNode);

    public:
    pSTreeNode pRoot;
};

CTree::CTree()
{
    pRoot = NULL;
}
CTree::CTree(TreeDataType Value)
{
    pRoot = new STreeNode(Value);
    if (pRoot == NULL)
        return ;
}
CTree::~CTree()
{
    if(pRoot == NULL)
        return ;
    FreeMemory(pRoot);
}
void CTree::FreeMemory(pSTreeNode pNode)
{
    if (pNode == NULL)
        return;
    if (pNode -> pFirstChild != NULL)
        FreeMemory(pNode->pFirstChild);
}