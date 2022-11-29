class Caeser_cipher:
    '''
    The Caeser cipher accepts two inputs: a key and a plaintext or input string. It lowercases the input string and transforms each word in accordance with the key, much like any other monoalphabetic encryption technique before returning ciphered plaintext in uppercase.
    '''

    def __init__(self, key, input_string):
        self.key = key
        self.input_string = input_string

    def encryption(self):
        encrypted_text = ""
        for word in self.input_string:
            encrypted_text += chr((ord(word)-97 + self.key) % 26 + 97)
        return encrypted_text.upper()

    def decryption(self):
        plaintext = ""
        for word in self.input_string:
            plaintext += chr((ord(word)-97 - self.key) % 26 + 97)
        return plaintext.lower()

    #get_user_input method takes plain text input and lowercases.
    @classmethod
    def get_user_input(self):
        try:
            key = int(input('Enter the key value: '))
            input_string = input('Enter the plaintext: ')
            return self(key, input_string.lower())
        except:
            print('Invalid input!')


def main():
    obj = Caeser_cipher.get_user_input()
    print("Note:\n 1.) Encryption \n 2.) Decryption")
    choice = int(input("Enter your choice:")) 
    if choice == 1:
        print("Encrypted text : " + str(obj.encryption()))
    elif choice== 2 :   
        print("Decrypted text : " + str(obj.decryption()))
    else:
        print("Invalid choice")
main()