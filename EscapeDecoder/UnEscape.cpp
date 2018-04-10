#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{

	string initialHex;	//Variable declarations
	char choice = 'y';
	int LCO = 87;		//Lower case offset for ASCII
	int IO = 48;		//Integer offset for ASCII
	int numEnd = 57;	//End of integers on the ASCII scheme
	int space = 32;		//ASCII value of the space character

	//Main program loop
	while(choice == 'y' || choice == 'Y')
	{
		//Take user input in string form
		cout << "Enter the Escape code you wish to decode: ";
		cin >> initialHex;

		//copy the string into a vector
		vector<char> c(initialHex.begin(), initialHex.end());

		//Remove any spaces from the vector and set all letters to
		//Lower case
		for(int i = 0; i < c.size(); i++)
		{

			

			if(int(c[i]) == space || c[i] == '%')
				c.erase(c.begin() + i);
			else
				c[i] = tolower(c[i]);
		}


		//Loop to calculate hex value
		for(int i = 0; i < c.size(); i++)
		{
			//Modulus if statement multiplies the first pair by 16
			if(i % 2 == 0)
			{
				if(int(c[i]) <= numEnd)
		         		c[i] = (int(c[i]) - IO) * 16;
		     		else
		          		c[i] = (int(c[i] - LCO)) * 16;
			}
		 	else
		  	{
		      		if(int(c[i]) <= numEnd)
		         		c[i-1] += (int(c[i] - IO));
		     		else
		          		c[i-1] += (int(c[i] - LCO));
		  	}
		}

		cout << "\nResulting String: \n\n";

		//Print the decoded string
		for (int i = 0; i < c.size(); i+= 2)
			cout << c[i];

		cout << "\n\nEnter another string (y/n)? ";
		cin >> choice;
	}
}
