This is a README for Sufyan Shaikh's Lab 3 C++ code.
*** NOTE ***
Was unable to get code to work properly. 


Lines 1-4 are self explanatory. Including libraries needed for the code and using namespace std.

Lines 6-24 are defining class Pancake.
	I've used protected over private to be able to access these values through different derived classes
	I have 6 specific functions in my public.
	first is the required flip_pancake which flips the pancake if called. 
	The following 4 are to get values from main and set them, those being if pancake is burnt and size of pancake.
	the last function is a function that combines the two set functions just because why not.

Lines 32-74 are for defining class PancakePile which is derived from Pancake.
	again using protected values
	I have 5 main functions
		1. printPile() - this allows me to print the contents of a pile.
		2. pancake_burnt_down() - flip all pancakes to burnt facing down
		3. virtual pancake_burnt_up() - flips all pancakes to burnt facing up. virtual bc derived class will use same function
		4. AddToPile() - Adds an object pancake to an array named pile.
		5. PrintResultsPile() - opens the output file to be written to and adds one pile to output.txt

Lines 77-94 - EncodedPancakePiles. two functions. get_code and pancake_burnt_up. Was not able to get it to work properly. Keep getting segmentation fault if uncommented.

Lines 96-170 are for defining class MPancakePiles which is derived from PancakeFile
	again using protected values
	I have 5 main functions
		1. printPlate() - print the contents of the plate from columns of every row
		2. rearrange_interior() - rearranges interior of plate such that all inner values of the  matrix are flipped facing down. This function utilizes pancake_burnt_down() from class Pancake Pile.
		3. rearrange_exterior() - rearranges exterior of plate such that all outer values of the matrix are flipped facing up. this function utilizes pancake_burnt_up() from class PancakePile.
		4. AddToPlate() - Adds an object pile to a plate, a 2D array. 
		5. PrintResultsPlate() - calls printResultsPile and adds all piles to output.txt
		6. rearrange last_row() - rearranges last row such that code is implemented and pancakes flip accordingly.

Lines 175-212 is the main()
	The first couple lines are to instantiate variables and objects.
	THere is a line to open a file for reading, where the values for the lab are gathered from.
	the next line is set up so that the first three valus in the text file are put into X, Y and Z. This is done because in the text value, the first three values are the row length, column length and Z is the number of pancakes per pile.
	Line 189-203 are the main chunks of the code
		It is composed of three for loops. The innermost loop is to parse through the lines of the text file adding pancakes to a pile enough to create one full pile of size Z. 
		The second loop and third loop are to add these piles to its proper space in the 2D array. from filling up the column values first then incrementing the row and rinse and repeating.
	Call the destructor to deallocate any memory.

END
