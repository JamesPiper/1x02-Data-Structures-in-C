/////////////////////////////////////////////////////////////////////////////////////
// 2017.01.20 by James Piper, james@jamespiper.com
//
// 1x02 Data Structures in C (Library).c
//
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
/////////////////////////////////////////////////////////////////////////////////////

void GetUserInputs(char* input, int max_length) {

	/////////////////////////////////////////////////////////////////////////////////////
	// Take user typed-in data from terminal and stores the string of inputs in
	// a string array, input, of max_length.
	//
	// Using scanf("%s", Inputs) doesn't work when there's whitespace.
	// It will only put first chunk of text into Inputs.
	//
	// There's many things said about overflows and how it can crash a program or worse.
	// Certainly if you try to store text with n chars into a char array defined with
	// m chars and m is less than n, you'll overwrite memory beyond the array or
	// you'll get a segmentation fault.
	//
	// Risks
	// 1. User inputs more text than max_length.
	//    Circumvent by ingoring text entereded after max_length and not storing data
	//    in array past max_length.
	//
	// 2. String doesn't end with '\0'.
	//
	// 3. scanf("%s", Inputs) on first entry.
	//    The computer will take a chunk of text until the whitespace is encountered
	//    and put it in Inputs.
	//    Possible overflow in writing to Inputs array if this chunk is longer.
	//    Use scanf("%ns", Inputs) to limit chars put into Inputs to n chars.
	//    Coding to vary this specifier based on max_length.
	//
	/////////////////////////////////////////////////////////////////////////////////////
	//
	// Example
	//
	// max_length: 10
	// Note: String defined in caller as str[10]
	//       10 = 9 chars + 1 of '\0'
	//
	// Enter text: 'here is some text' <enter>
	//              01234567890123456
	//
	// 1. input = "here" + \0
	// 2. i = 5
	// 3. get additional char until enter key hit
	// 4. add if not before max_length
	// 5. input = "here is s" + '\0'
	//             012345678     9
	//
	/////////////////////////////////////////////////////////////////////////////////////

	// First chunk of non-whitespace user input.
	// Using fixed length to simplify code.
	// Use more temp memory for less cycles.
	// If user enters more than 1024 chars, the code will likely cause problems.
	// Low risk of overflow.
	// Issue if piping in file as input.
	char UserInput[1024];
	scanf("%1023s", UserInput);
	strncpy(input, UserInput, max_length - 1);
	//*(input + max_length - 1) = '\0';

	// Initial chunk of text--cut off from first whitespace.
	int i = strlen(input);
	char c;

	do {
		// Get additional text one character at a time.
        scanf("%c", &c);

		// Keep adding text as long before max_length.
        if (i < max_length)
            input[i++] = c;

		// Need to continue looping until '\n' is reached
		// because additional text input will be processed.
		// It would be good to stop the scan process but I
		// don't know how to do that.
	} while (c != '\n');

	// Terminate string array.
	if (i < max_length)
		input[i - 1] = '\0';
	else
		input[max_length - 1] = '\0';

}
