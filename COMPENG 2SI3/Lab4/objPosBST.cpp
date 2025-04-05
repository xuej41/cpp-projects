#include "objPosBST.h"

#include <queue>
#include <iomanip>

#include <iostream>
using namespace std;

objPosBST::objPosBST()
{
    // Constructor (Check Lecture Notes for Implementation, Simple)
    objPos tree;
    root = nullptr;
}

objPosBST::~objPosBST()
{
    // Destructor
    // Invoke delete tree, then set root to NULL
    deleteTree();
    root = nullptr;
}

void objPosBST::deleteTree(const TNode* thisNode)
{
	// Delete all nodes in the tree

    // Question from Class - Which Traversal Order should you use for this method?
    //   WARNING - using the wrong one will result in potential heap error.
    if (thisNode != nullptr){
        deleteTree(thisNode->left);
        deleteTree(thisNode->right);
        delete thisNode;
    }
}

// Public Interface, Implemented
void objPosBST::deleteTree()
{
    deleteTree(root); // recursive call on the private helper function
    root = nullptr;
}

bool objPosBST::isEmptyTree() const
{
    // Check if tree is empty
    //  Really simple, think about how.
    if (root == nullptr)
        return true;
    else
        return false;
}


bool objPosBST::isLeaf(const objPos &thisPos, const TNode* thisNode) const
{
    // Check if thisPos in a Leaf Node.
    //  Remember, tree nodes are inserted using the Prefix member of objPos

    // Algorithm Suggestion:
    // 1. if the node is NULL, just return false
    // 2. Otherwise, compare Prefix of the data of the current node
    //    against the Prefix of thisPos
    //      - If not equal, follow the BST search rules
    //      - If equal, check if the node is a leaf node

    // Remember, leaf nodes do not have children nodes
    if (thisNode == nullptr)
        return false;
    else if (thisPos.getPF() == thisNode->data.getPF())
    {
        return thisNode->left == nullptr && thisNode->right == nullptr;
    }
    else if (thisPos.getPF() < thisNode->data.getPF())
    {
        return isLeaf(thisPos, thisNode->left);
    }
    else
    {
        return isLeaf(thisPos, thisNode->right);
    }
}

bool objPosBST::isLeaf(const objPos &thisPos) const
{   
    return isLeaf(thisPos, root);
}


void objPosBST::printTree(const TNode* thisNode) const  // private recursive
{
    // Print the entire tree content using **In-Order Traversal**

    // print in the format of Prefix + Number
    // e.g.  N30 P25 etc.

    // DO NOT use printObjPos() as it will mess up the game display.
    if (thisNode != nullptr){
        printTree(thisNode->left);
        cout << thisNode->data.getPF() << thisNode->data.getNum() << " ";
        printTree(thisNode->right);
    }
}

void objPosBST::printTree() const  // public interface
{    
    if(root == NULL)
    {
        cout << "[Empty]";
        return;
    }
    printTree(root);
}


int objPosBST::getHeight(const TNode* thisNode) const //not modified
{
    // Tree Height Calculation Algorithm 

    // 1. If thisNode is null, height is zero.

    // 2. Otherwise, recursively invoke getHeight for the left and right subtree, and save
    //    the returned heights.

    // 3. Compare the two returned heights, and return the larger one.
    if (thisNode == nullptr)
        return 0;
    int leftHeight = getHeight(thisNode->left);
    int rightHeight = getHeight(thisNode->right);

    return 1 + max(leftHeight, rightHeight);
}

void objPosBST::printCurrentLevel(const TNode* thisNode, const int level) const
{
    // Recursive Level-Order Tree-Printing Algorithm 
    
    // 1. First check if at leaf node.  If yes, do not print anything

    // 2. Then, check if level is 1.  If yes, print the Prefix field only (specified in manual)

    // 3. Otherwise, invoke recursively printCurrentLevel for left subtree with one less level, then
    //                                                        right subtree with one less level
    //    "if I'm not at the level, keep on searching into the left and the right subtrees"

    // You may add other character formatting features to make the tree more readable.
    // (you will be asked to demo this feature during the lab demo!!)
    if (thisNode == nullptr)
        return;
    else if (level == 1)
        cout << thisNode->data.getPF() << " ";
    else
    {
        printCurrentLevel(thisNode->left, level - 1);
        printCurrentLevel(thisNode->right, level - 1);
    }
}

// Public Interface.
void objPosBST::printTreeLevel() const
{
    // Interface to the Recursive Version of Level-Order Tree-Printing Algorithm 

    // 1. Get the height of the tree
    // 2. For each level (bounded by height), invoke the recursive tree-printing algorithm.

    // You may add other character formatting features to make the tree more readable.
    // (you will be asked to demo this feature during the lab demo!!)
    if (!root) {
        cout << "[Empty Tree]" << endl;
        return;
    }

    int height = getHeight(root);
    int maxWidth = (1 << height) - 1; // Max number of nodes at last level
    queue<const TNode*> q;
    
    q.push(root);
    
    for (int level = 1; level <= height; level++) {
        int nodeSpacing = maxWidth / (1 << level); // Spaces between nodes
        int leadingSpaces = maxWidth / (1 << (level + 1)); // Spaces before first node

        // Print leading spaces before first node of this level
        cout << string(leadingSpaces, ' ');

        int levelSize = q.size(); // Number of nodes at this level
        
        for (int i = 0; i < levelSize; i++) {
            const TNode* node = q.front();
            q.pop();

            if (node) {
                cout << node->data.getPF(); // Print the node value
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << " "; // Print space if node is null
                q.push(nullptr);
                q.push(nullptr);
            }

            // Print space between nodes
            cout << string(nodeSpacing, ' ');
        }
        cout << endl;
    }
}

bool objPosBST::isInTree(const objPos& thisPos, const TNode* thisNode) const
{
    // Check if thisPos in in the tree.
    //  Remember, tree nodes are inserted using the Prefix member of objPos

    // Algorithm Suggestion:
    // 1. if the node is NULL, just return false
    // 2. Otherwise, compare Prefix of the data of the current node
    //    against the Prefix of thisPos
    //      - If not equal, follow the BST search rules
    //      - If equal, return true
    if (thisNode == nullptr)
        return false;
    else if (thisPos.getPF() == thisNode->data.getPF())
        return true;
    else if (thisPos.getPF() < thisNode->data.getPF())
        return isInTree(thisPos, thisNode->left);
    else
        return isInTree(thisPos, thisNode->right);
}

// Public Interface, Implemented
bool objPosBST::isInTree(const objPos &thisPos) const
{
    return isInTree(thisPos, root); // recursive call on the private helper function
}

// insert OR update!!
void objPosBST::insert(const objPos &thisPos, TNode* &thisNode)
{
    // Insert objPos as a Node into the BST

    // Check Lecture Notes for general implementation
    //  Hint: Algorithm similar to isInTree.

    // Modification: 
    //   If the node is already in the tree (i.e. Prefix match found)
    //   Add the number member of thisPos to the number member of the objPos data at the node
    //   (DO NOT JUST IGNORE.  ADD NUMBERS!!)
    if (thisNode == nullptr)
    {
        thisNode = new TNode(thisPos);
    }
    else if (thisPos.getPF() == thisNode->data.getPF())
    {
        int num = thisNode->data.getNum()+thisPos.getNum();
        thisNode->data.setNum(num);
    }
    else if (thisPos.getPF() < thisNode->data.getPF())
    {
        insert(thisPos, thisNode->left);
    }
    else
    {
        insert(thisPos, thisNode->right);
    }
}

// Public Interface, Implemented
void objPosBST::insert(const objPos &thisPos)
{
    insert(thisPos, root); // recursive call on the private helper function
}


const TNode* objPosBST::findMin(const TNode* thisNode) const
{
	// Find the node with the smallest prefix in the subtree from thisNode

    // Used as part of remove() algorithm

    // Check Lecture Notes for implementation
    if (thisNode == nullptr)
        return nullptr;

    while (thisNode->left != nullptr)
    {
        thisNode = thisNode->left;
    }

    return thisNode;
}


void objPosBST::remove(const objPos &thisPos, TNode* &thisNode)
{
	// Remove the node with matching prefix of thisPos from the subtree thisNode

    // *IMPORTANT* Check Lecture Notes for general implementation
    //  Remember the three removal case scenarios

    // Case 1 and 2 both can be handled with one algorithm (Lecture Notes)

    // Case 3 - Delete the node with 2 children
    //   You can use either methods (check lecture notes)
    if (thisNode == nullptr)
        return;
    else if (thisPos.getPF() < thisNode->data.getPF())
    {
        remove(thisPos, thisNode->left);
    }
    else if (thisPos.getPF() > thisNode->data.getPF())
    {
        remove(thisPos, thisNode->right);
    }
    else if (thisNode->left != nullptr && thisNode->right != nullptr)
    {
        thisNode->data = findMin(thisNode->right)->data;
        remove(thisNode->data,thisNode->right);
    }
    else
    {
        TNode*oldnode = thisNode;
        thisNode=(thisNode->left!=NULL) ? thisNode->left:thisNode->right;
    }
}

// Public Interface, Implemented
void objPosBST::remove(const objPos &thisPos)
{
    remove(thisPos, root); // recursive call on the private helper function
}

bool objPosBST::findGreater(const int numThreshold, const TNode* thisNode) const
{
    // Determine whether any nodes in the tree has the NUMBER field of objPos data member greater than numThreshold

    // WARNING - this one is not as straightforward.

    // Algorithm Suggestion
    //  1. If tree empty, just return false
    //  2. Recursively check if the any number on the LEFT subtree is greater than numThreshold
    //  3. Recursively check if the any number on the RIGHT subtree is greater than numThreshold
    //  4. Then, check if the number field of the objPos data in the current node is greater than numThreshold
    //  5. If any of the results from item 2, 3, and 4 is TRUE, return true.
    //     Otherwise, return false.

    // HINT:  If you do this right, the algorithm is less than 10 lines.
    if (thisNode == nullptr)
        return false;

    bool left = findGreater(numThreshold,thisNode->left);
    bool right = findGreater(numThreshold,thisNode->right);
    bool current = (thisNode->data.getNum()>numThreshold);

    if (right)
        return true;
    else if (left)
        return true;
    else if (current)
        return true;
    else 
        return false;
}

bool objPosBST::findGreater(const int numThreshold) const
{
    return findGreater(numThreshold, root);
}
