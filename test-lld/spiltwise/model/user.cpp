#include "user.h"
using namespace std;

user::user(){

};

user::user(string name_, string email_, string contact_, string id_)
{
    this->name = name_;
    this->email = email_;
    this->contact = contact_;
    this->id = id_;
}

string user::getId() { return id; }
void user::setId(string id_) { id = id_; }

string user::getContact() { return contact; }
void user::setContact(string contact_) { contact = contact_; }

string user::getName() { return name; }
void user::setName(string name_) { name = name_; }

string user::getEmail() { return email; }
void user::setEmail(string email_) { email = email_; }
