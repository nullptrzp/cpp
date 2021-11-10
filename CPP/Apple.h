#ifndef _APPLE_H
#define _APPLE_H
class Apple
{
public:
	Apple():apple_Number(0),var(0) {};
	Apple(int num) :apple_Number(num), var(0) {};
	void take(int num) const;
	void add(int num);
	void add(int num) const;
	int getCount() const;

private:
	int var;
	const int apple_Number=10;
};

#endif // !_APPLE_H
