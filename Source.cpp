#include <iostream>
#include <vector>

using namespace std;



/*
Jersey Roster program that coaches can use to add, remove,
update, and output players information. 
*/

int main() {
	
	vector<int> jerseyVec; // vector to store jersey numbers
	vector<int> rankingVec; // vector to store ranking numbers
		
	int i;
	int tempNum;
	
	char menuNum;

	for(i = 0; i < 5; i++) { // loop started, storing values in vectors.

		cout << "Enter player " << i + 1 << "'s jersey number (1-99):" << endl;
		cin >> tempNum;
		jerseyVec.push_back(tempNum); // storing values in jersey vector

		cout << "Enter player " << i + 1 << "'s rating (1-9):" << endl;
		cin >> tempNum;
		rankingVec.push_back(tempNum); // storing values in ranking vector

		cout << endl;
		
	}

	cout << "ROSTER:" << endl; 
	for(i = 0; i < 5; i++) {      // Displays each players jersey # and ranking #
		
		cout << "Player " << i + 1 << "-- Jersey number:" 
		<< jerseyVec.at(i) << ", Rating:" << rankingVec.at(i) << endl;
	}
	
	do // Menu of options, do while loop
	{

		cout << "\nMENU" << endl;
		cout << "a - Add player" << endl;
		cout << "d - Remove player" << endl;
		cout << "u - Update player rating" << endl;
		cout << "r - Output players above a rating" << endl;
		cout << "o - Output roster" << endl;
		cout << "q - Quit" << endl << endl;
		cout << "Choose an option:" << endl;

		cin >> menuNum;
		cout << endl;

		switch (menuNum) // Switch statement starts. Parameters contain letter user selected from the menu.

		{
		case 'a':
			cout << "Enter another players jersey number (1-99): \n";
			cin >> tempNum;
			
			if (tempNum > 0 && tempNum < 99) {
				jerseyVec.push_back(tempNum); // adding  player option.
				
			}

			cout << "Enter another players rating (1-9): \n";
			cin >> tempNum;

			if (tempNum > 0 && tempNum < 10) {
				rankingVec.push_back(tempNum); // adding ranking option
				break;
			}
			break;

		case 'o':
			cout << "ROSTER" << endl; // option to display current Roster.
			for (i = 0; i < jerseyVec.size(); i++) 
				cout << "Player " << i + 1 << " -- " << "Jersey number: " << jerseyVec.at(i) << ", Rating: " << rankingVec.at(i) << endl;
			break;

		case 'd':
			cout << "Enter the jersey number:" << endl; // Remove player option.
			cin >> tempNum; 
			
			for (i = 0; i < jerseyVec.size(); i++) {
				if (jerseyVec.at(i) == tempNum) { // tempNum is the number user just inputed.
					jerseyVec.erase(jerseyVec.begin() + i); // jersey number is erased.
					rankingVec.erase(rankingVec.begin() + i); // ranking number is erased.
					break;
				}
			}
			break;

		case 'u':
			cout << "Enter the jersey number:" << endl;  // updates player ranking number.
			cin >> tempNum;

			for (i = 0; i < jerseyVec.size(); i++) {
				if (jerseyVec.at(i) == tempNum) {
					cout << "Enter new rating number:" << endl;
					cin >> tempNum;

					rankingVec.at(i) = tempNum; // ranking number updated.
					break;

				}
			}
			break;

		case 'r':
			cout << "Enter a rating number:" << endl; // output all players above a selected rating. 
			cin >> tempNum;
			cout << "ABOVE " << tempNum << endl;
			for(i = 0; i < rankingVec.size(); i++) {
				if(rankingVec.at(i) > tempNum) { // if ranking is above what user inputed..
					cout << "Player " << i + 1 << " -- Jersey number: " << jerseyVec.at(i)
						<< ", Rating: " << rankingVec.at(i) << endl;
				}
			}
			break;
		}

	} while (menuNum != 'q'); // while portion of do while loop. 'q' terminates program.

	system("pause");
	return 0;

}







