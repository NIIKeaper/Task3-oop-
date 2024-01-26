#pragma once
#include "Message.h"
#include <vector>

class Chat
{
private:
    int id;
    std::string login;
    int phone_number;
    std::vector<std::unique_ptr<Message>> messages;

public:
    Chat()
    { this->id = 0, this->login = "FEW", this->phone_number = 0; 
    }

    explicit Chat(int id, std::string login, int phone_number)
    {
        this->id = id, this->login = login, this->phone_number = phone_number;
    }

    ~Chat() { }


    Chat(Chat& other): id(other.id), login(other.login), phone_number(other.phone_number)
    {
        for (const auto& message : other.messages) {
            messages.push_back(std::make_unique<Message>(*message));
        }
    }

     Chat(Chat&& other) noexcept : id(other.id), login(other.login), phone_number(other.phone_number), messages(std::move(other.messages))
    {
        other.id = 0;
        other.phone_number = 0;
    }

    //getters and setters 
     void setId(int id)
     {
         this->id = id; 
     }
     void setLogin(std::string login) 
     { 
         this->login = login; 
     }
     void setPhone_number(int phone_number) 
     { 
         this->phone_number = phone_number; 
     }

     int getId() 
     { 
         return this->id; 
     }

     std::string getLogin() const
     { 
         return this->login; 
     }

     int getPhone_number() 
     {
         return this->phone_number; 
     }



     Chat& operator=(const Chat&) { return *this; }

    //methods
    void addMessage(std::unique_ptr<Message> message)
    {
        messages.push_back(std::move(message));
    }

    void printUnreadMessages()
    {
        for (const auto& message : messages) {
            if (!message->getIs_checked()) {
                message->print(std::cout);
                
                message->setIs_checked(true);
            }
        }
    }

};
