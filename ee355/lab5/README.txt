README for Sufyan Shaikh's Lab5 for EE355
This lab had given us code that was already almost complete. There were certain to do's we had to complete.

For "date.cpp"
	The only to do in this file was to find the bug in the set_date() function. The bug was the non-use of this in the if statement. The fix was implemented by using this, assigning the values of day month and year to that class' values.

For "connection.cpp"
	The first todo was to complete the override function Connection(string filename). To complete properly, call set_connection(filename).
	Secondly we had to complete set_connection(filename). This was the same as the other set_connection with the exception of opening a file, then using the file's contents to load the connection. Used c.str() to be able to open a file given a string.
	Next, we had to complete the operator overload for ==. This was done by comparing rhs fname, lname and bdate with given values. Had to use *birthdate and *rhs.birthdate other wise you'd be getting the address of the birthdate rather than the actual date.
	Lastly, just copied from the date.cpp. This was the != operator override.

For "network.cpp"
	1. completed the destructor. Deleting any pointers called by the constructor.
	2. push_back(). Adding to end of list, therefore next is NULL and previous is tail of list. If tail is null, list is empty and you are now head of list. If not null, now make you tail. Then increment count.
	3. search(). Search for an existing entry. If found, return ptr to where it is in list.
	4. remove(). Call search. If search == Null, return false. If search does return ptr, then we want to delete that ptr, and make it so that the next of prev pointer points to next and prev of next points to prev. We have to account for corner cases. For example if prev of ptr is null, meaning ptr is head and if next of ptr is null, meaning ptr is tail. DELETE PTRS CREATED OR ELSE MEMORY LEAK.
	5. saveDB(). open an output file. create a connection and point to head. As long as ptr->next != null, keep saving connections to the output file. TO save to output file, because of complications with the formatting of date and its existence being a different class altogether, use ->get.date(). Delete ptr.

END


