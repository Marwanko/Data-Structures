#ifndef PROJECT_FRIENDS_H
#define PROJECT_FRIENDS_H
#include <iostream>
#include <cstring>
#include "User.h"
using namespace std;
class User;
class BSTN{
private:
    BSTN* right;
    BSTN* left;
    int priority;
    User* key;
public:
    BSTN(User*);
    void rightRotate(BSTN* &y);
    void leftRotate(BSTN* &x);
    BSTN* insertNode(BSTN* &root, User* key);
    User* searchNode(BSTN* &root, User* key);
    void deleteNode(BSTN* &root, User* key);
    void inorder(BSTN* root);
};


#endif
