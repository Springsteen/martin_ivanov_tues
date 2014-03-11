#include <iostream>
#include <string.h>

using namespace std;

class String {
	int capacity_;
	int size_;
	char* buffer_;
	
	friend ostream& operator<<(ostream&, const String&);
	
	void ensure_capacity(int cap) {
		if(capacity_>=cap) {
			return;
		}
		char* tmp = buffer_;
		capacity_ = cap;
		buffer_ = new char[capacity_];
		strcpy(buffer_, tmp);
		delete [] tmp; 
	}
			
public:

	explicit String(int capacity)
	: capacity_(capacity), 
	size_(0),
	buffer_(new char[capacity_])
	{
		buffer_[0] = '\0';	  	
	}
	
	String(const char* str)
	: capacity_(0),
	size_(0),
	buffer_(0)
	{
		size_=strlen(str);
		capacity_= size_+1;
		buffer_ = new char[capacity_];
		strcpy(buffer_, str);
	}
	
	int size() const {
		return size_;
	}
	
	int length() const {
		return size_;
	}
	
	int capacity() const {
		return capacity_;
	}

	String& append(const String& other){
		return *this += other;
	}

	void push_back(char ch) {
		buffer_[size_] = ch;
		buffer_[size_+1] = '\0';
		size_++;
	}

	String& operator+=(const String& s) {
		ensure_capacity(size_ + s.size_ +1);
		strcat(buffer_, s.buffer_);
		size_+=s.size_;
		return *this;
	}
	
	

	~String() {
		delete [] buffer_;
	}

};

ostream& operator<<(ostream& out, const String& s) {
	out << s.buffer_;
	return out;
}

int main() {
	String s1("Hello");
	String s2("World");

	cout << s1 << endl;
	cout << s2 << endl;

	s1+=s2;
	cout << s1  << endl;

	String s3 ("Hello");
	s3 += " ";
	s3 += s2;
	cout << s3 << endl;

	String s4("Pesho");
	s4.append(s2);
	
	cout << s4 << endl;

	return 0;
}







