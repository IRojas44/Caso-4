#include<iostream>

#ifndef TREENODE

#define TREENODE 1

class TreeNode {
private:
  int value;
  int distancia;
  int cantMinerales;
  TreeNode * left;
  TreeNode * right;

public:
  TreeNode() {
    value = 0;
    distancia = 0; 
    cantMinerales = 0;
    left = NULL;
    right = NULL;
  }

  void setValue(int pValue){
    value = pValue;
  }  
  
  void setCantMin(int pCant){
    cantMinerales = pCant;
  }  

  void setDistancia(int pDis){
    distancia = pDis;
  }  

  void setRight(TreeNode * node){
    right = node;
  }

  void setLeft(TreeNode * node){
    left = node;
  }

  int getValue(){
    return value;
  } 

  int getDistancia(){
    return distancia;
  }

  int getCantidad(){
    return cantMinerales;
  }

  TreeNode * getRight(){
    return right;
  }

  TreeNode * getLeft(){
    return left;
  }


  
};

#endif