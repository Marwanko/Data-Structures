#include "User.h"

User::User(string u, string n, string e) {
    username = u;
    name = n;
    email = e;
    friends = nullptr;
}

void User::setUsername(string u) {
    username = u;
}

string User::getUsername() {
    return username;
}

void User::setName(string n) {
    name = n;
}

string User::getName() {
    return name;
}

void User::setEmail(string e) {
    email = e;
}

string User::getEmail() {
    return email;
}

void User::listFriends() {
    this->friends->inorder(friends);
}


void User::searchUser(string username, LinkedList users) {
    User* tmp = users.searchUserList(username);
    tmp = friends->searchNode(friends, tmp);
    if (tmp == nullptr){
        cout<<"not found"<<endl;
    }
    else{
        cout<<tmp->getUsername()<<","<<tmp->getName()<<","<<tmp->getEmail()<<endl;
    }
}
//user1.addfrinf(tydfytf,fu)
bool User::addFriend(string username, LinkedList users) {
    User* tmp = users.searchUserList(username);
    if (tmp == nullptr){return false;}
    User* tmp2 = this->friends->searchNode(friends,tmp);
    if (tmp2 != nullptr){
        return false;
    }
    else {
        this->friends->insertNode(friends, tmp);
        tmp->friends->insertNode(tmp->friends, this);
        return true;
    }
}

void User::removeFriend(string username,LinkedList users) {
    User* tmp = users.searchUserList(username);
    if (tmp == nullptr){return;}
    User* tmp2 = this->friends->searchNode(friends,tmp);
    if (tmp2 == nullptr){
        return;
    }
    else{
        this->friends->deleteNode(friends,tmp);
        tmp->friends->deleteNode(tmp->friends,this);
        cout<<"Done"<<endl;
    }

}

void User::peopleYouMayKnow(User* user,LinkedList users){
    Node* head = users.getHead();
    Node* tail = users.getTail();
    int i =0;
    while (i<5){
        if(user->getUsername()!=head->getUser()->getUsername() && user->friends->searchNode(user->friends,head->getUser())==
                                                                  nullptr){
            cout<<head->getUser()->getUsername()<<","<<head->getUser()->getName()<<endl;
            i=i+1;
        }
        if(head == tail){
            return;
        }
        head = head->getNext();
    }


}

BSTN *User::getFriends() {
    return this->friends;
}


Node::Node() {
    next = nullptr;
}


Node::Node(User* u, Node *n) {
    next = n;
    this->user = u;
}


void Node::setNext(Node *n) {
    this->next = n;
}


Node* Node::getNext() {
    return next;
}


void Node::setUser(User* u) {
    user = u;
}


User* Node::getUser() {
    return user;
}


LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}



Node* LinkedList::getHead()
{
    return head;
}

Node* LinkedList::getTail()
{
    return tail;
}


void LinkedList::setHead(Node* newHead)
{
    head = newHead;
}

void LinkedList::setTail(Node* newTail)
{
    tail = newTail;
}


void LinkedList::addNode(User* user) {
    Node* tmp = new Node(user, nullptr);
    if(head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->setNext(tmp);
        tail = tail->getNext();

    }

}


User* LinkedList::searchUserList(string username) {
    Node* current = head;
    while (current != NULL)
    {
      if (current->getUser()->getUsername() == username)
            return current->getUser();
        current = current->getNext();
    }
    return nullptr;
}

User* LinkedList::login(string username) {
    User* tmp = this->searchUserList(username);
    if (tmp == nullptr){
        return nullptr;
    }
    else{return tmp;}
}







