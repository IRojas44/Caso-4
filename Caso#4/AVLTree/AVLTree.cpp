#include<iostream>
#include "AVLTree.h"

#define SPACE 10

using namespace std;





int main() {
  AVLTree obj;
  int option, val;
  
  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal AVL Tree values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "AVL INSERT" << endl;
      cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
      cin >> val;
      new_node->setValue(val);
      obj.setRoot(obj.insert(obj.getRoot(),new_node,10,6));
      new_node->setValue(7);
      obj.setRoot(obj.insert(obj.getRoot(),new_node,18,3));
      new_node->setValue(11);
      obj.setRoot(obj.insert(obj.getRoot(),new_node,12,9));
      new_node->setValue(9);
      obj.setRoot(obj.insert(obj.getRoot(),new_node,15,6));
      //obj.root = obj.insert(obj.root, new_node);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
      cin >> val;
      new_node = obj.search(val);
      //new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;

    case 3:
      
    case 4:
      cout << "PRINT 2D: " << endl;
      //obj.print2D(obj.root, 5);
      cout << endl;
      //cout <<"Print Level Order BFS: \n";
      //obj.printLevelOrderBFS(obj.root);
      //cout <<endl;
      //	      cout <<"PRE-ORDER: ";
      //	      obj.printPreorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"IN-ORDER: ";
      //	      obj.printInorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"POST-ORDER: ";
      //	      obj.printPostorder(obj.root);
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.getRoot()) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
  
  return 0;
}
