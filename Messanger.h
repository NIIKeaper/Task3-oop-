#pragma once

#include "Chat.h"
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Messenger {
private:
    std::map<std::string, Chat> chats; 

public:
    // Добавление нового чата
    void addChat(const Chat& chat) {
        chats[chat.getLogin()] = chat;
    }

    Chat& operator[](const std::string& login) {
        return chats[login];
    }

    const Chat& operator[](const std::string& login) const {
        return chats.at(login);
    }

    friend std::ostream& operator<<(std::ostream& os, const Messenger& messenger) {
        std::vector<std::string> logins;
        for (const auto& pair : messenger.chats) {
            logins.push_back(pair.first);
        }
        std::sort(logins.begin(), logins.end());

        for (const auto& login : logins) {
            os << "Chat with " << login << std::endl;
        }
        return os;
    }
};
