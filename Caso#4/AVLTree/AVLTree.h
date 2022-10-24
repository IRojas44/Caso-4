#include<iostream>
#include "TreeNode.h"

#ifndef TREE

#define TREE 1
#define SPACE 10
using namespace std;

class AVLTree {
private:
  TreeNode * root;

public:
  AVLTree() {
    root = NULL;
  }

  TreeNode * getRoot(){
    return root;
  }

  void setRoot(TreeNode * r){
    root = r;
  }

  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
  // Get Height  
  int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r->getLeft());
      int rheight = height(r->getRight());

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }

  // Get Balance factor of node N  
  int getBalanceFactor(TreeNode * n) {
    if (n == NULL)
      return -1;
    return height(n->getLeft()) - height(n->getRight());
  }

  TreeNode * rightRotate(TreeNode * y) {
    TreeNode * x = y->getLeft();
    TreeNode * T2 = x->getRight();

    // Perform rotation  
    x -> setRight(y);
    y -> setLeft(T2);

    return x;
  }

  TreeNode * leftRotate(TreeNode * x) {
    TreeNode * y = x -> getRight();
    TreeNode * T2 = y -> getLeft();

    // Perform rotation  
    y -> setLeft(x);
    x -> setRight(T2);

    return y;
  }

   TreeNode * insert(TreeNode * r, TreeNode * newNode, int distancia, int cantMinerales) {
    if (r == NULL) {
      r = newNode;
      r->setDistancia(distancia);
      r->setCantMin(cantMinerales);
      return r;
    }

    if (newNode->getValue() < r->getValue()) {
      r->setLeft(insert(r->getLeft(),newNode,distancia,cantMinerales));
    } else if (newNode->getValue() > r->getValue()) {
      r->setRight(insert(r->getRight(),newNode,distancia,cantMinerales));
    } else {
      cout << "No duplicate values allowed!" << endl;
      return r;
    }

    int bf = getBalanceFactor(r);
    // Left Left Case  
    if (bf > 1 && newNode->getValue() < r->getLeft()->getValue())
      return rightRotate(r);

    // Right Right Case  
    if (bf < -1 && newNode->getValue() > r->getRight()->getValue())
      return leftRotate(r);

    // Left Right Case  
    if (bf > 1 && newNode->getValue() > r->getLeft()->getValue()) {
      r->setLeft(leftRotate(r->getLeft()));
      return rightRotate(r);
    }

    // Right Left Case  
    if (bf < -1 && newNode->getValue() < r->getRight()->getValue()) {
      r->setRight(rightRotate(r->getRight()));
      return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;

  }

  TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current->getLeft() != NULL) {
      current = current->getLeft();
    }
    return current;
  }
  
  int obtenerDisTotalDer(){
    //TreeNode * current = node;
    int resu = 0;
    
    while (root -> getRight() != NULL) {
      resu = resu + root->getRight()->getDistancia();
    }
    return resu;
  }

  int obtenerDisTotalIzq(){
    //TreeNode * current = node;
    int resu = 0;
    
    while (root -> getLeft() != NULL) {
      resu = resu + root->getLeft()->getDistancia();
    }
    return resu;
  }
  
  TreeNode * deleteNode(TreeNode * r, int value) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (value < r ->getValue()) {
      r->setLeft(deleteNode(r->getLeft(),value));
      
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (value > r -> getValue()) {
      r->setRight(deleteNode(r->getRight(),value));
      
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r->getLeft() == NULL) {
        TreeNode * temp = r -> getRight();
        delete r;
        return temp;
      } else if (r -> getRight() == NULL) {
        TreeNode * temp = r -> getLeft();
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValueNode(r -> getRight());
        // Copy the inorder successor's content to this node 
        r->setValue(temp->getValue());
     
        // Delete the inorder successor 
        r->setRight(deleteNode(r->getRight(),temp->getValue()));
        
        //deleteNode(r->right, temp->value); 
      }
    }

    int bf = getBalanceFactor(r);
    // Left Left Imbalance/Case or Right rotation 
    if (bf == 2 && getBalanceFactor(r -> getLeft()) >= 0)
      return rightRotate(r);
    // Left Right Imbalance/Case or LR rotation 
    else if (bf == 2 && getBalanceFactor(r -> getLeft()) == -1) {
      r->setLeft(leftRotate(r->getLeft()));
      
      return rightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation	
    else if (bf == -2 && getBalanceFactor(r -> getRight()) <= -0)
      return leftRotate(r);
    // Right Left Imbalance/Case or RL rotation 
    else if (bf == -2 && getBalanceFactor(r -> getRight()) == 1) {
      r->setRight(rightRotate(r->getRight()));
      
      return leftRotate(r);
    }

    return r;
  }

  
  

  TreeNode * search(int v) {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> getValue()) {
          return temp;
        } else if (v < temp -> getValue()) {
          temp = temp -> getLeft();
        } else {
          temp = temp -> getRight();
        }
      }
      return NULL;
    }
  }

  

};

#endif