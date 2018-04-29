#include<iostream>  
using namespace std;  
template< class K, class V>  
struct AVLTreeNode  
{  
    AVLTreeNode(const K& key, const V& value)  
    :_pLeft(NULL)  
    , _pRight(NULL)  
    , _pParent(NULL)  
    , _key(key)  
    , _value(value)  
    , _bf(0)  
    {}  
    AVLTreeNode<K, V>* _pLeft;  
    AVLTreeNode<K, V>* _pRight;  
    AVLTreeNode<K, V>* _pParent;  
    K _key;  
    V _value;  
    int _bf;  
};  
  
  
template<class K, class V>  
class AVLTree  
{  
public:  
      
    typedef AVLTreeNode<K, V> Node;  
    typedef Node* pNode;  
    AVLTree()  
        :_pRoot(NULL)  
    {}  
      
    bool Insert(const K& key, const V& value)  
    {  
  
        if (_pRoot == NULL)  
        {  
            _pRoot = new Node(key, value);  
            return true;  
        }  
        pNode  pParent = NULL;  
        pNode cur = _pRoot;  
        while (cur)  
        {  
            if (cur->_key == key)  
                return false;  
            else if (cur->_key > key)  
            {  
                pParent = cur;  
                cur = cur->_pLeft;  
  
            }  
            else  
            {  
                pParent = cur;  
                cur = cur->_pRight;  
            }  
  
        }  
        pNode pNewNode = new Node(key, value);  
        if (pParent->_key > key)  
        {  
            pParent->_pLeft = pNewNode;  
            pNewNode->_pParent = pParent;  
        }  
        else  
        {  
            pParent->_pRight = pNewNode;  
            pNewNode->_pParent = pParent;  
        }  
        while (pParent)  
        {  
            if (pParent->_pLeft == pNewNode)  
                pParent->_bf--;  
            else   
                pParent->_bf++;  
            if (pParent->_bf == 0)  
                return true;  
            else if (pParent->_bf == 1 || pParent->_bf == -1)  
            {  
                pNewNode = pParent;  
                pParent = pParent->_pParent;  
            }  
            else if (pParent->_bf == 2 || pParent->_bf == -2)  
            {  
                if (pParent->_bf == 2)//左边的结点比较多    
                {  
                    if (pNewNode->_bf == 1)  
                    {  
                        _RotateL(pParent);//    
                        return true;  
                    }  
                    else  
                    {  
                        _RotateRL(pParent);//右左旋转    
                        return true;  
                    }  
                }  
                if (pParent->_bf == -2)  
                {  
                    if (pNewNode->_bf == -1)  
                    {  
                        _RotateR(pParent);  
                        return true;  
                    }  
                    else  
                    {  
                        _RotateLR(pParent);  
                        return true;  
                    }  
                }  
            }  
        }  
        return true;  
    }  
      
      
    void InOrder()  
    {  
        _InOrder(_pRoot);  
    }  
  
    bool IsBalance()  
    {  
        return _IsBalance(_pRoot);  
    }  
    int Height()  
    {  
        return _Height(_pRoot);  
    }  
    bool IsBalance2()  
    {  
        int depth = 0;  
        return _IsBalance2(_pRoot, depth);  
    }  
private:  
    bool _IsBalance2(pNode pRoot, int depth)  
    {  
        if (NULL == pRoot)  
        {  
            depth = 0;  
            return true;  
        }  
        int leftDepth = 0;  
        int rightDepth = 0;  
        if (_IsBalance2(pRoot->_pLeft, leftDepth) == false)  
        {  
            return false;  
        }  
        if (_IsBalance2(pRoot->_pRight, rightDepth) == false)  
        {  
            return false;  
        }  
        if (rightDepth - leftDepth != pRoot->_bf)  
        {  
            cout << "bf异常" << pRoot->_bf << endl;  
        }  
        depth = leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);  
        return true;  
  
    }  
    bool _IsBalance(pNode pRoot)  
    {  
        if (pRoot == NULL)  
            return true;  
        else  
        {  
            int height = abs(_Height(pRoot->_pRight) - _Height(pRoot->_pLeft));  
            return (height < 2) && _IsBalance(pRoot->_pLeft) && _IsBalance(pRoot->_pRight);  
        }  
    }  
    int _Height(pNode pRoot)  
    {  
        int treeheight = 0;  
        if (pRoot == NULL)  
            return 0;  
        else  
        {  
            int lefttreeheight = _Height(pRoot->_pLeft);  
            int righttreeheight = _Height(pRoot->_pRight);  
            treeheight = lefttreeheight > righttreeheight ? lefttreeheight + 1 : righttreeheight + 1;  
        }  
        return treeheight;  
          
    }  
  
    void _RotateL(pNode pParent)  
    {  
        pNode subR = pParent->_pRight;  
        pNode subRL = subR->_pLeft;  
        pParent->_pRight = subRL;  
        if (subRL)  
            subRL->_pParent = pParent;  
        pNode ppParent = pParent->_pParent;  
        subR->_pLeft = pParent;  
        pParent->_pParent = subR;  
        if (ppParent == NULL)  
        {  
            _pRoot = subR;  
            subR->_pParent = NULL;  
        }  
        else  
        {  
            if (ppParent->_pLeft == pParent)  
            {  
                ppParent->_pLeft = subR;  
                  
            }  
            else  
            {  
                ppParent->_pRight = subR;  
                  
            }  
            subR->_pParent = ppParent;  
  
        }  
        pParent->_bf = subR->_bf = 0;  
          
    }  
      
    void _RotateR(pNode pParent)  
    {  
        pNode subL = pParent->_pLeft;  
        pNode subLR = subL->_pRight;  
        pParent->_pLeft = subLR;  
        if (subLR)  
            subLR->_pParent = pParent;  
        pNode ppParent = pParent->_pParent;  
        subL->_pRight = pParent;  
        pParent->_pParent = subL;  
        if (ppParent == NULL)  
        {  
            _pRoot = subL;  
            subL->_pParent = NULL;  
        }  
        else  
        {  
            if (ppParent->_pLeft == pParent  )  
  
            {  
                ppParent->_pLeft = subL;  
                subL->_pParent = ppParent;  
            }  
            else  
            {  
                ppParent->_pRight = subL;  
                subL->_pParent = ppParent;  
            }  
        }  
        pParent->_bf = subL->_bf = 0;  
    }  
      
    void _RotateRL(pNode pParent)  
    {  
        pNode subR = pParent->_pRight;  
        pNode subRL = subR->_pLeft;  
        int bf = subRL->_bf;  
        _RotateR(subR);  
        _RotateL(pParent);  
        if (bf == 0)  
        {  
            pParent->_bf = subR->_bf = 0;  
        }  
        else if (bf == -1)  
        {  
            subR->_bf = 0;  
            pParent->_bf = -1;  
        }  
        else  
        {  
            subR->_bf = -1;  
            pParent->_bf = 0;  
              
        }  
        subRL->_bf = 0;  
  
    }  
    void _RotateLR(pNode pParent)  
    {  
        pNode subL = pParent->_pLeft;  
        pNode subLR = subL->_pRight;  
        int bf = subLR->_bf;  
        _RotateL(subL);  
        _RotateR(pParent);  
        if (bf == 0)  
        {  
            subL->_bf=pParent->_bf   = 0;  
        }  
        else if (bf == -1)  
        {  
            subL->_bf = -1;  
            pParent->_bf = 0;  
              
        }  
        else  
        {  
            subL->_bf = 0;  
            pParent->_bf = -1;  
              
        }  
        subLR->_bf = 0;  
    }  
      
    void _InOrder(pNode pRoot)  
    {  
      
        if (pRoot)  
        {  
            _InOrder(pRoot->_pLeft);  
            cout << pRoot->_key << " ";  
            _InOrder(pRoot->_pRight);  
        }  
      
    }  
private:  
    pNode _pRoot;  
};  
int main()  
{  
      
    int a[] = { 18, 14, 20, 12, 16, 15 };  
    AVLTree< int, int> bst;  
    for (int i = 0; i < sizeof(a) / sizeof(*a); ++i)  
    {  
        bst.Insert(a[i], i);  
    }  
    bst.InOrder();  
    cout << endl;  
    cout << bst.Height() << endl;  
    if (bst.IsBalance())  
        cout << "平衡" << endl;  
    else  
        cout << "不平衡" << endl;  
    if(bst.IsBalance2())  
        cout<<"平衡"<<endl;  
    else  
        cout<<"不平衡"<<endl;  
    system("pause");  
    return 0;  
}  
