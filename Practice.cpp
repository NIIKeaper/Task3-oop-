#include <iostream>
#include "Messanger.h"

int main()
{
    //message check
    Text_Message text(1,3,true,"Kek");
    Img_Message img;
    Audio_Message audio(2,5,true,66,"Important text");

    text.print(std::cout);
    img.print(std::cout);
    audio.print(std::cout);

    std::cout << std::endl;


    // chat cheeck
    Chat myChat(1, "user1", 123456789);

    std::unique_ptr<Message> textMessage = std::make_unique<Text_Message>(1, 100, false, "Hello, how are you?");
    myChat.addMessage(std::move(textMessage));

    std::unique_ptr<Message> audioMessage = std::make_unique<Audio_Message>(2, 101, false, 123, "voice1212.mp3");
    myChat.addMessage(std::move(audioMessage));

    std::unique_ptr<Message> imgMessage = std::make_unique<Img_Message>(3, 102, false, 456);
    myChat.addMessage(std::move(imgMessage));

    std::cout << "Unread messages:" << std::endl;
    myChat.printUnreadMessages();


    // messanger check 
    Messenger messenger;

    Chat chat1(1, "user1", 12345);
    Chat chat2(2, "user2", 67890);
    Chat chat3(3, "user3", 54321);

    messenger.addChat(chat1);
    messenger.addChat(chat2);
    messenger.addChat(chat3);

    std::cout << messenger;

    std::cout << "Accessing chat for user2:" << std::endl;
    std::cout << messenger["user2"].getLogin() << std::endl;

    return 0;
}