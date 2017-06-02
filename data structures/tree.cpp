#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int x;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        TreeNode *x;
        Node *next;
    };

// public member
public:
    // constructor
    LinkedList(){
        head = NULL; // set head to NULL
        tail = NULL;
    }


    // returns the first element in the list and deletes the Node.
    TreeNode popFront(){ 
        
        if (head == NULL){//LinkedList is empty case
            TreeNode *ret;
            return *ret;
        }
        Node *n = head;
        TreeNode *ret = n->x;

        head = head->next;
        if (head == NULL){ //LinkedList is now empty
            tail = NULL;
        }
        delete n;
        return *ret;
    }
    
    bool empty(){
        if (head == NULL){
            return true;
        }
        else {
            return false;
        }
    }

    void pushBack(TreeNode *val){
        Node *n = new Node();
        n->x = val;
        n->next = NULL; //end of list
        if (tail == NULL){ //LinkedList was empty
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            tail = n;
        }
    }

// private member
private:
    Node *head; // this is the private member variable. It is just a pointer to the first Node
    Node *tail; //pointer to the last node
};



class binaryTree{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.

// public member
public:
    // constructor
    binaryTree(){
        root = NULL; // set head to NULL
    }

    // Recursive insert method left to right ascending order
    void insertNode(TreeNode *treeNode, int val, TreeNode *parent=NULL){
        if (treeNode == NULL){
            treeNode = new TreeNode();
            treeNode->x = val;
            treeNode->left = NULL;
            treeNode->right = NULL;
            treeNode->parent = parent;
            if (root == NULL){
               root = treeNode;
            }
            else {
                if (parent->x > val){
                    parent->left = treeNode;
                }
                else {
                    parent->right = treeNode;
                }
            }
            
            cout << val << endl;
            
        }
        else {
            if (val < treeNode->x){
                insertNode(treeNode->left, val, treeNode);
                cout << val << endl;
            }
            else {
                insertNode(treeNode->right, val, treeNode);
                cout << val << endl;
            }
        }
        
    }

    void insertNodeValue(int val){
        insertNode(root, val);
    }

    void inOrder(){
        inOrderTraversal(root);
    }

    void preOrder(){
        preOrderTraversal(root);
    }

    void postOrder(){
    	postOrderTraversal(root);
    }

    void level(){
        levelTraversal(root);
    }

    TreeNode find(int val){
    	TreeNode ret = findValue(root, val);
    	return ret;
    }

    vector<TreeNode> rangeSearch(int low, int high){
    	vector<TreeNode> list;
    	list = rangeSearchValue(low, high, root);
    	return list;
    }


    // Depth-first searches
    void inOrderTraversal(TreeNode *treeNode){
        if (treeNode == NULL){
            return;
        }
        inOrderTraversal(treeNode->left);
        cout << treeNode->x << endl;
        inOrderTraversal(treeNode->right);

    }

    void preOrderTraversal(TreeNode *treeNode){
        if (treeNode == NULL){
            return;
        }
        cout << treeNode->x << endl;
        preOrderTraversal(treeNode->left);
        preOrderTraversal(treeNode->right);
    }

    void postOrderTraversal(TreeNode *treeNode){
    	if (treeNode == NULL){
            return;
        }
        postOrderTraversal(treeNode->left);
        postOrderTraversal(treeNode->right);
        cout << treeNode->x << endl;
    }

    //Breadth-first search
    void levelTraversal(TreeNode *treeNode){
        if (treeNode == NULL){
            return;
        }
        LinkedList list;
        list.pushBack(treeNode);

        while (!list.empty()){
            TreeNode treeNode = list.popFront();
            cout << treeNode.x << endl;
            if (treeNode.left != NULL){
                list.pushBack(treeNode.left);
            }
             if (treeNode.right != NULL){
                list.pushBack(treeNode.right);
            }
        }
    }

    TreeNode findValue(TreeNode *treeNode, int val){
    	if (treeNode->x == val){
    		return *treeNode;
    	}
    	else if (treeNode->x > val){
    		if (treeNode->left != NULL){
    			return findValue(treeNode->left, val);
    		}
    	}    	
    	else {
    		if (treeNode->right != NULL){
    			return findValue(treeNode->right, val);
    		}

    	}
    	return *treeNode; //returns closest node if not found
    }

    TreeNode next(TreeNode *treeNode){
    	if (treeNode->right != NULL){
    		return leftDescendant(treeNode->right);
    	}
    	else {
    		return rightAncestor(treeNode);
    	}
    }

    TreeNode leftDescendant(TreeNode *treeNode){
    	if (treeNode->left == NULL){
    		return *treeNode;
    	}	
    	else {
    		return leftDescendant(treeNode->left);
    	}
    }

    TreeNode rightAncestor(TreeNode *treeNode){
    	if (treeNode == NULL){ //handles if recursion goes back to root
    		return *root;
    	}
    	if (treeNode->x < treeNode->parent->x){
    		return *treeNode->parent;
    	}
    	else {
    		return rightAncestor(treeNode->parent);
    	}
    }

    vector<TreeNode> rangeSearchValue(int low, int high, TreeNode *treeNode){
    	vector<TreeNode> list;
    	TreeNode node;
    	node = find(low);
    	while (node.x <= high){
    		if (node.x >= low){
    			list.push_back(node);
    		}
    		node = next(&node);
    	}
    	return list;
    }

    // WIP !!!
    void deleteNode(int val){
    	TreeNode treeNode = find(val);
    	if (treeNode.right == NULL){
    		TreeNode *leftNode = treeNode.left;
    		leftNode->parent = treeNode.parent;
    		if (treeNode.parent->x > leftNode->x){
    		    cout << "FAIL" << endl;
    			treeNode.parent->left = leftNode; 
    		}
    		else {
    			treeNode.parent->right = leftNode;
    		}
    		delete treeNode;
    	}
    	// else {
    	// 	TreeNode node = next(treeNode);
    	// 	node.parent->left = node.right;
    	// 	node.right->parent = node.parent;
  			// //Note that node.left = null due to next fcn
  			// node.parent = treeNode->parent;
  			// node.right = treeNode->right;
  			// if (treeNode->parent->x > node.x){
    	// 		treeNode->parent->left = &node; 
    	// 	}
    	// 	else {
    	// 		treeNode->parent->right = &node;
    	// 	}
    	// 	delete treeNode;

    	// }
    }



// private member
private:
    TreeNode *root; // this is the private member variable. It is just a pointer to the first Node

};

int main() {
    binaryTree tree;
    TreeNode node;
    vector<TreeNode> list;

    tree.insertNodeValue(5);
    tree.insertNodeValue(3);
    tree.insertNodeValue(2);
    tree.insertNodeValue(4);
    tree.insertNodeValue(1);
    tree.insertNodeValue(7);
    tree.insertNodeValue(6);
    tree.insertNodeValue(8);
    tree.insertNodeValue(9);

    tree.inOrder();    
    tree.preOrder();
    tree.postOrder();
    tree.level();

    node = tree.find(6);
    cout << node.x << endl;

    node = tree.next(&node);
    cout << node.x << endl;

    list = tree.rangeSearch(3, 7);
    for (vector<TreeNode>::iterator it = list.begin(); it != list.end(); ++it){
        cout << "LOL " << (*it).x << endl;
    }
    
    //test delete
    // tree.deleteNode(2);
    // tree.inOrder();

    return 0;
}



   // void insert(int val){
   //      cout << "FAIL" << endl;
   //  	if (root == NULL){
   //  		TreeNode *treeNode = new TreeNode();
   //  		treeNode->x = val;
   //  		treeNode->left = NULL;
   //  		treeNode->right = NULL;
   //  		treeNode->parent = NULL;
   //  		root = treeNode;
   //          cout << "FAIL" << endl;
   //  	}
   //  	TreeNode node = find(val);
   //  	if (node.x > val){
   //  		TreeNode *treeNode = new TreeNode();
   //  		treeNode->x = val;
   //  		treeNode->left = NULL;
   //  		treeNode->right = NULL;
   //  		treeNode->parent = &node;
   //  		node.left = treeNode;
   //  	}
   //  	else {
   //  		TreeNode *treeNode = new TreeNode();
   //  		treeNode->x = val;
   //  		treeNode->left = NULL;
   //  		treeNode->right = NULL;
   //  		treeNode->parent = &node;
   //  		node.right = treeNode;
   //  	}
   //  }