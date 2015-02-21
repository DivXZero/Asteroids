
#ifndef SHAREDOBJECT_H
#define SHAREDOBJECT_H

class SharedObject
{
public:
	virtual ~SharedObject() {}

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif