//declarations for function in class DBentry
#ifndef _DBENTRY_H
#define _DBENTRY_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class DBentry {
private:
	string name;
	unsigned int IPaddress;
    bool active;

public:
	// the default constructor
	DBentry();

	// constructor that sets members when called
    DBentry (string _name, unsigned int _IPaddress, bool _active);

	// destructor
 	~DBentry();

	// sets the domain name, which we will use as a key.
	void setName(string _name);

	// sets the IPaddress data.
	void setIPaddress(unsigned int _IPaddress);

    // sets whether or not this entry is active.
    void setActive (bool _active);

    // returns the name.
	string getName() const;

	// returns the IPaddress data.
	unsigned int getIPaddress() const;

    // returns whether or not this entry is active.
    bool getActive() const;
};

#endif
