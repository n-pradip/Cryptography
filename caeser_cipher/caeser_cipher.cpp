#include <iostream>
#include <string.h>
using namespace std;

class Caeser_cipher{
	int key, i;
	char encrypted_char;
	string input_string;
	public:
		string encryption(){
			for(i=0;i<input_string.length();i++){
				encrypted_char = char((tolower(input_string[i])-97 + key) % 26 + 97);
				input_string[i] = char(toupper(encrypted_char));	
			}
			return input_string;
		}
		
		string decryption(){
			int holder;
			for(i=0;i<input_string.length();i++){
				encrypted_char = char(((((tolower(input_string[i])-97 - key) % 26)+ 26)% 26) + 97);
				input_string[i] = encrypted_char;	
			}
			return input_string;
		}
		
		void get_user_input(){
			cout<<"Enter key value : ";
			cin>>key;
			cout<<"Enter the plaintext : ";
			cin>> input_string;
		} 
    };
    
int main(){
	int choice;
	cout<<"Note: \n 1.) Encryption \n 2.) Decryption \n"<<"Enter your choice : ";
	cin>>choice;
	Caeser_cipher obj;
	obj.get_user_input();
	// using switch case to procced with encryption or decription as provided
	switch(choice){
		case 1:
			cout<<"Encrypted text : "<<obj.encryption();
			break;
		case 2:
			cout<<"Decrypted text : "<<obj.decryption();
			break;
		default:
			cout<<"Invalid choice";	
	}
	return 0;
}
