#include "Message.h"

Message::Message()
{
	this->id = 0;
	this->time = 0;
	this->is_checked = false;
}

Message::Message(int id, int time, bool is_checked)
{
	this->id = id;
	this->time = time;
	this->is_checked = is_checked;
}

Message::Message(Message& other) : id(other.id), time(other.time), is_checked(other.is_checked)
{

}

Message::Message(Message&& other) noexcept : id(other.id), time(other.time), is_checked(other.is_checked)
{
	other.id = 0;
	other.time = 0;
	other.is_checked = false;
}

Message::~Message()
{
}

void Message::setId(int id)
{
	this->id = id;
}

void Message::setTime(int id)
{
	this->time = time;
}

void Message::setIs_checked(bool is_checked)
{
	this->is_checked = is_checked;
}

int Message::getId() const
{
	return this->id;
}

int Message::getTime() const
{
	return this->time;
}

bool Message::getIs_checked() const
{
	return this->is_checked;
}

void Message::print(std::ostream& os)
{
	os << "Id:" << this->id << " Time:" << this->time << " is_checked:" << this->is_checked << std::endl;
}



// Text_Message
Text_Message::Text_Message()
{
	this->setId(0);
	this->setTime(0);
	this->setIs_checked (false);
	this->text = "Nothing";
}

Text_Message::Text_Message(int id, int time, bool is_checked, std::string text)
{
	this->setId(id);
	this->setTime(time);
	this->setIs_checked(is_checked);
	this->text = text;
}

Text_Message::~Text_Message()
{
}

void Text_Message::setText(std::string text)
{
	this->text = text;
}

std::string Text_Message::getText() const
{
	return this->text;
}

void Text_Message::print(std::ostream& os) 
{
	os << "Text:" << this->text << std::endl;
}




// Img_Message
Img_Message::Img_Message()
{
	this->setId(0);
	this->setTime(0);
	this->setIs_checked(false);
	this->file_id = 0;
}

Img_Message::Img_Message(int id, int time, bool is_checked, int file_id)
{
	this->setId(id);
	this->setTime(time);
	this->setIs_checked(is_checked);
	this->file_id = file_id;

}

Img_Message::~Img_Message()
{
}

void Img_Message::setFile_id(int file_id)
{
	this->file_id = file_id;
}

int Img_Message::getFile_id()
{
	return this->file_id;
}

void Img_Message::print(std::ostream& os)
{
	os << "www.telega.org/img/" << this->file_id << std::endl;
}




Audio_Message::Audio_Message()
{
	this->setId(0);
	this->setTime(0);
	this->setIs_checked(false);
	this->setFile_id(0);
	this->setText("Nothing");

}

Audio_Message::Audio_Message(int id, int time, bool is_checked, int file_id, std::string text)
{
	this->setId(id);
	this->setTime(time);
	this->setIs_checked(is_checked);
	this->setFile_id(file_id);
	this->setText(text);
}

Audio_Message::~Audio_Message()
{

}

void Audio_Message::setFile_id(int file_id)
{
	this->file_id = file_id;
}

void Audio_Message::setText(std::string text)
{
	this->text = text;
}

int Audio_Message::getFile_id()
{
	return this->file_id;
}

std::string Audio_Message::getText() const
{
	return this->text;
}

void Audio_Message::print(std::ostream& os)
{
	os << "www.telega.org/audio/" << this->getFile_id() << " Text:" << this->getText()<< std::endl;

}
