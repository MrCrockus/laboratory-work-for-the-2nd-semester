#include <iostream>

#include <vector>

using namespace std;

void cod(vector <int> message, vector <int> key, int code[], const int n) {
	int a;
	int b;

	for (int i = 0; i < message.size(); i++) {
		a = ((message[i] + key[i]) % n);
		b = ((message[i] + key[i]) % n) % 26 + 65;
		code[i] = a;
		cout << char(b);
	}
}

void decod(vector <int> message, int code[], char decode[], const int n, vector <int> key) {
	int a;

	for (int i = 0; i < message.size(); i++) {
		a = ((code[i] + n - key[i]) % n);
		decode[i] = a;
	}

}

int main() {
	const int n = 255;
	char a_input[255];
	char key_input[255];
	int a_coder[255];
	char a_decoder[255];
	vector<int> message;
	vector<int> key;
	int64_t i, num;

	cout << "Enter the message: ";
	cin >> a_input;

	for (int i = 0; a_input[i]; i++) {
		message.push_back(static_cast<int>(a_input[i]));
	}

	cout << "\nEnter the key:     ";
	cin >> key_input;

	for (int i = 0; key_input[i]; i++) {
		key.push_back(static_cast<int>(key_input[i]));
	}

	if (key.size() < message.size()) {
		for (i = 0; key.size() < message.size(); i++) {
			num = key[i];
			key.push_back(num);
		}
	}

	else

		if (key.size() > message.size()) {
			while (key.size() > message.size()) {
				key.pop_back();
			}
		}

	cout << "\nResulte of crypt:  ";
	cod(message, key, a_coder, n);
	cout << endl;
	

	cout << endl << "\nResult of decrypt: ";
	decod(message, a_coder, a_decoder, n, key);

	for (i = 0; i < message.size(); i++) {
		cout << a_decoder[i];
	}
	cout << "\n\n\n";
}