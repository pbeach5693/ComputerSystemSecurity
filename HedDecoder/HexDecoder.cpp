#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char c[] =  "464c41477b336e436f64316e475f346e445f6433633044316e477d";
	int toCalc[100] = {};
	int a = 0;

	for (int i = 0; i < strlen(c); i++)
	{
        if(c[i] - 48 <= 9)
            toCalc[a] += int(c[i] - 48);
        else
            toCalc[a] += int(c[i] - 87);

        if(i % 2 == 1)
        {
            c[a] = toCalc[a];
            a++;
        }
        else
            toCalc[a] *= 16;
	}

	for (int i = 0; i < strlen(c)/2; i++)
		cout << c[i];

	return 0;
}
