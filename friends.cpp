#include "friends.h"


BSTN::BSTN(User* user) {
    this->key = user;
    this->priority = rand() % 100;
    this->left = this->right = nullptr;
}

void BSTN::rightRotate(BSTN* &y) {
    BSTN* L = y->left;
    BSTN* x = y->left->right;
    L->right = y;
    y->left = x;
    y = L;
}

void BSTN::leftRotate(BSTN* &x) {
    BSTN* R = x->right;
    BSTN* y = x->right->left;
    R->left = x;
    x->right = y;
    x = R;
}


BSTN* BSTN::insertNode(BSTN *&root, User *key) {
    if (root == nullptr)
    {
        root = new BSTN(key);
        return root;
    }
    if (key->getUsername().compare(root->key->getUsername())<0)
    {
        root->left = insertNode(root->left, key);
        if (root->left != nullptr && root->left->priority > root->priority) {
            rightRotate(root);
        }
    }
    else {
        root->right = insertNode(root->right, key);
        if (root->right != nullptr && root->right->priority > root->priority) {
            leftRotate(root);
        }
    }
    return root;
}

User* BSTN::searchNode(BSTN *&root, User *key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->key->getUsername() == key->getUsername()) {
        return key;
    }
    if ((key->getUsername().compare(root->key->getUsername()))<0) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);

}

void BSTN::deleteNode(BSTN *&root, User *key) {
    if (root == nullptr) {
        return;
    }
    if ((key->getUsername().compare(root->key->getUsername()))<0) {
        deleteNode(root->left, key);
    }
    else if ((key->getUsername().compare(root->key->getUsername()))>0) {
        deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left && root->right)
        {
            if (root->left->priority < root->right->priority)
            {
                leftRotate(root);
                deleteNode(root->left, key);
            }
            else {
                rightRotate(root);
                deleteNode(root->right, key);
            }
        }
        else {
            BSTN* child = (root->left)? root->left: root->right;
            BSTN* curr = root;
            root = child;
            delete curr;
        }
    }
}

void BSTN::inorder(BSTN *root) {
    if (root == nullptr){return;}
    inorder(root->left);
    cout << root->key->getUsername()<<","<< root->key->getName() << endl;
    inorder(root->right);
}





