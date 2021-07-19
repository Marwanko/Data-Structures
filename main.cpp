//the project run on clion
//******************************
//the project run on clion
//******************************
//the project run on clion
//******************************
//the project run on clion
//******************************
//the project run on clion
//******************************
#include "User.h"
#include <fstream>
#include <sstream>
#include <string>
using std::ifstream;
using namespace std;
int main() {
    LinkedList users;
    /*User* user1= new User("soad91","Soad Saber","soad91@gmail.com");
    User* user2= new User("olaa100","Ola Kamel","olaa100@yahoo.com");
    User* user3= new User("emadsalem1","Emad Salem","emadsalem1@gmail.com");
    User* user4= new User("abdoamr","Abdelkarim Amr","abdoamr@gmail.com");
    User* user5= new User("fatoom","Fatma Omar","fatoom@yahoo.com");
    User* user6= new User("mony34","Mona Hamed","mony34@gmail.com");
    User* user7= new User("emy2000","Iman Kareem","emy2000@gmail.com");
    User* user8= new User("talaat3000","Talaat Mahmoud","talaat3000@gmail.com");
    User* user9= new User("samir22","Samir Abdelshakoor","samir22@gmail.com");
    users.addNode(user1);
    users.addNode(user2);
    users.addNode(user3);
    users.addNode(user4);
    users.addNode(user5);
    users.addNode(user6);
    users.addNode(user7);
    users.addNode(user8);
    users.addNode(user9);
    user8->addFriend("emadsalem1",users);
    user5->addFriend("olaa100",users);
    user2->addFriend("mony34",users);
    user3->addFriend("abdoamr",users);
    user7->addFriend("mony34",users);
    user9->addFriend("talaat3000",users);*/
    //read the users
    ifstream allUsers("all-users.in");
    string str;
    while (getline(allUsers, str)) {
        int pos1 = str.find(",") ;
        int pos2 = str.find(",",pos1+1);
        string username = str.substr(0,pos1);
        string name = str.substr(pos1+2,pos2-pos1-2);
        string email = str.substr(pos2+2);
        User* usertmp = new User(username, name, email);
        users.addNode(usertmp);
    }
    allUsers.close();
    //read the users' relation
    ifstream usersAdd("all-users-relations.in");
    string str2;
    while (getline(usersAdd, str2)) {
        int pos1 = str2.find(",") ;
        string username1 = str2.substr(0,pos1);
        string username2 = str2.substr(pos1+2);
        User* user1 = users.searchUserList(username1);
        user1->addFriend(username2,users);
    }
    usersAdd.close();
    //---------------------------------------------------------------
    cout<<"Social networking App\n"
          "---------------------\n";
    int ch1;
    string username,username1;
    User* user;
    while (true){
        cout<<"Enter what you want to do\n"
              "1- login\n"
              "2- Exit\n";
        cin>>ch1;
        if(ch1 == 2){
            break;
        } else if(ch1 == 1){
            cout<<"enter user name:";
            cin>>username;
            user = users.login(username);
            if (user == nullptr){
                cout<<"wrong username\n";
                continue;
            }else{
                while(true){
                    cout<<"Enter what you want to do\n"
                          "1- List all friends\n"
                          "2- Search by username\n"
                          "3- Add friend\n"
                          "4- Remove friend\n"
                          "5- People you may know\n"
                          "6- logout\n";
                    cin>>ch1;
                    if (ch1 == 6){
                        break;
                    } else if (ch1 == 1){
                        user->listFriends();
                    } else if (ch1 == 2){
                        cout<<"enter username:";
                        cin>>username1;
                        user->searchUser(username1, users);
                    } else if (ch1 == 3){
                        cout<<"enter username:";
                        cin>>username1;
                        if(user->addFriend(username1,users)){
                            cout<<"You are now friends"<<endl;
                        }else{
                            cout<<"You are already friends"<<endl;
                        }
                    } else if(ch1 == 4){
                        cout<<"enter username:";
                        cin>>username1;
                        user->removeFriend(username1,users);
                    } else if(ch1 == 5){
                        user->peopleYouMayKnow(user,users);
                    }
                }
            }

        } else{
            cout<<"wrong input\n";
            continue;
        }

    }


}

