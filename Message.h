#pragma once
#include <string>
#include <iostream>

class Message 
{
private:
	int id;
	int time;
	bool is_checked;
public:
	Message();
	explicit Message(int id, int time, bool is_checked);
	Message(Message& other);
	Message(Message&& other) noexcept;

	~Message();

	void setId(int id);
	void setTime(int id);
	void setIs_checked(bool is_checked);

	int getId() const;
	int getTime() const;
	bool getIs_checked() const;

	virtual void print(std::ostream& os);
};



class Text_Message : public Message {
private:
	std::string text;
public:
	Text_Message();
	explicit Text_Message(int id, int time, bool is_checked, std::string text);

	~Text_Message();

	void setText(std::string text);

	std::string getText() const;

	void print(std::ostream& os) override;
};



class Img_Message : public Message {
private:
	int file_id;
public:
	Img_Message();
	explicit Img_Message(int id, int time, bool is_checked, int file_id);

	~Img_Message();


	void setFile_id(int file_id);

	int getFile_id();

	void print(std::ostream& os) override;
};



class Audio_Message : public Message {
private:
	std::string text;
	int file_id;
public:
	Audio_Message();
	explicit Audio_Message(int id, int time, bool is_checked, int file_id, std::string text);
	~Audio_Message();

	void setFile_id(int file_id);
	void setText(std::string text);

	int getFile_id();
	std::string getText() const;

	void print(std::ostream& os) override;
};
