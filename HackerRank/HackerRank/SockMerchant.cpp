// https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

int sockPositionInPile(vector<int>& _lookedAtSocks, const int _sockToLookFor) {
	for (int i = 0; i < _lookedAtSocks.size(); ++i) {
		if (_lookedAtSocks[i] == _sockToLookFor) {
			return i;
		}
	}
	return -1;
}

// Complete the sockMerchant function below.
int sockMerchant(const int n, vector<int>& ar) {
	int pairs{ 0 };
	vector<int> lookedAtSocks;
	for (auto& sock : ar) {
		if (!lookedAtSocks.empty()) {
			//check that the sock isn't already in the vector
			const auto sockPosition = sockPositionInPile(lookedAtSocks, sock);
			if (sockPosition != -1) {
				lookedAtSocks.erase(lookedAtSocks.begin() + sockPosition);
				pairs++;
			} else {
				lookedAtSocks.emplace_back(sock);
			}

		} else {
			lookedAtSocks.emplace_back(sock);
		}
	}
	return pairs;
}

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string ar_temp_temp;
	getline(cin, ar_temp_temp);

	vector<string> ar_temp = split_string(ar_temp_temp);

	vector<int> ar(n);

	for (int i = 0; i < n; i++) {
		int ar_item = stoi(ar_temp[i]);

		ar[i] = ar_item;
	}

	int result = sockMerchant(n, ar);

	//cout << result << std::endl;
	fout << result << "\n";

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
		return x == y and x == ' ';
		});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
