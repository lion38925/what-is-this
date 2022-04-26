#ifndef USERR_H
#define USERR_H
#include <bits/stdc++.h>
using namespace std;

class user
{
private:
    string name;
    string email;
    string contact;
    string id;
    /* data */
    
public:
    user();
    user(string name_, string email_, string contact_, string id_);
    string getId();
    void setId(string id_);

    string getName();
    void setName(string name_);

    string getEmail();
    void setEmail(string email_);

    string getContact();
    void setContact(string contact_);
};


#endif