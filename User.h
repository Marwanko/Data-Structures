#ifndef PROJECT_USER_H
#define PROJECT_USER_H
#include <iostream>
#include <cstring>
#include "friends.h"
using namespace std;
class BSTN;
class Node;
class LinkedList;
class User{
private:
    string username;
    string name;
    string email;
    BSTN* friends;
public:
    User(string,string,string);
    void setUsername(string);
    string getUsername();
    void setName(string);
    string getName();
    void setEmail(string);
    string getEmail();
    BSTN* getFriends();
    bool addFriend(string username,LinkedList users);
    void searchUser(string, LinkedList);
    void removeFriend(string,LinkedList);
    void listFriends();
    void peopleYouMayKnow(User*,LinkedList);
};


class Node{
private:
    User* user=nullptr;
    Node* next=nullptr;
public:
    Node();
    Node(User* user,Node* n);
    void setNext(Node*);
    Node* getNext();
    void setUser(User* user);
    User* getUser();
};


class LinkedList{
private:
    Node* head;
    Node* tail;
public:
    LinkedList();
    Node* getHead();
    Node* getTail();
    void setHead(Node* newHead);
    void setTail(Node* newTail);
    void addNode(User* user);
    User* searchUserList(string);
    User* login(string);



};


#endif
