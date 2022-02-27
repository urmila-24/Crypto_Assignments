//Urmila Rathore
//201951164(CSE)

//Please run all the cipher types code different times and compare the output.i have written the code in the same file.

//Playfair cipher
// C program to implement Playfair Cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

// Function to convert the string to lowercase
void toLowerCase(char plain[], int ps)
{
	int i;
	for (i = 0; i < ps; i++) {
		if (plain[i] > 64 && plain[i] < 91)
			plain[i] += 32;
	}
}

// Function to remove all spaces in a string
int removeSpaces(char* plain, int ps)
{
	int i, count = 0;
	for (i = 0; i < ps; i++)
		if (plain[i] != ' ')
			plain[count++] = plain[i];
	plain[count] = '\0';
	return count;
}

// Function to generate the 5x5 key square
void generateKeyTable(char key[], int ks, char keyT[5][5])
{
	int i, j, k, flag = 0, *dicty;

	// a 26 character hashmap
	// to store count of the alphabet
	dicty = (int*)calloc(26, sizeof(int));
	for (i = 0; i < ks; i++) {
		if (key[i] != 'j')
			dicty[key[i] - 97] = 2;
	}

	dicty['j' - 97] = 1;

	i = 0;
	j = 0;

	for (k = 0; k < ks; k++) {
		if (dicty[key[k] - 97] == 2) {
			dicty[key[k] - 97] -= 1;
			keyT[i][j] = key[k];
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}

	for (k = 0; k < 26; k++) {
		if (dicty[k] == 0) {
			keyT[i][j] = (char)(k + 97);
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}
}

// Function to search for the characters of a digraph
// in the key square and return their position
void search(char keyT[5][5], char a, char b, int arr[])
{
	int i, j;

	if (a == 'j')
		a = 'i';
	else if (b == 'j')
		b = 'i';

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 5; j++) {

			if (keyT[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (keyT[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}

// Function to find the modulus with 5
int mod5(int a) { return (a % 5); }

// Function to make the plain text length to be even
int prepare(char str[], int ptrs)
{
	if (ptrs % 2 != 0) {
		str[ptrs++] = 'z';
		str[ptrs] = '\0';
	}
	return ptrs;
}

// Function for performing the encryption
void encrypt(char str[], char keyT[5][5], int ps)
{
	int i, a[4];

	for (i = 0; i < ps; i += 2) {

		search(keyT, str[i], str[i + 1], a);

		if (a[0] == a[2]) {
			str[i] = keyT[a[0]][mod5(a[1] + 1)];
			str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
		}
		else if (a[1] == a[3]) {
			str[i] = keyT[mod5(a[0] + 1)][a[1]];
			str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
		}
		else {
			str[i] = keyT[a[0]][a[3]];
			str[i + 1] = keyT[a[2]][a[1]];
		}
	}
}

// Function to encrypt using Playfair Cipher
void encryptByPlayfairCipher(char str[], char key[])
{
	char ps, ks, keyT[5][5];

	// Key
	ks = strlen(key);
	ks = removeSpaces(key, ks);
	toLowerCase(key, ks);

	// Plaintext
	ps = strlen(str);
	toLowerCase(str, ps);
	ps = removeSpaces(str, ps);

	ps = prepare(str, ps);

	generateKeyTable(key, ks, keyT);

	encrypt(str, keyT, ps);
}

int main()
{
	char str[SIZE], key[SIZE];

	// Key to be encrypted
	strcpy(key, "Monarchy");
	printf("Key text: %s\n", key);

	// Plaintext to be encrypted
	strcpy(str, "instruments");
	printf("Plain text: %s\n", str);

	// encrypt using Playfair Cipher
	encryptByPlayfairCipher(str, key);

	printf("Cipher text: %s\n", str);

	return 0;
}


//another one

#include <stdio.h>

int main()
{
   int i, x;
   char str[100];

   printf("\nPlease enter a string:\t");
   gets(str);

   printf("\nPlease choose following options:\n");
   printf("1 = Encrypt the string.\n");
   printf("2 = Decrypt the string.\n");
   scanf("%d", &x);

   //using switch case statements
   switch(x)
   {
   case 1:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 3; //the key for encryption is 3 that is added to ASCII value

      printf("\nEncrypted string: %s\n", str);
      break;

   case 2:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3; //the key for encryption is 3 that is subtracted to ASCII value

      printf("\nDecrypted string: %s\n", str);
      break;

   default:
      printf("\nError\n");
   return 0;
}   }



//caesar cipher
//Encryption code
#include<stdio.h>
int main()
{
int i, key;
char a[100], c1;
// take message for encryption
printf("Enter a message for encryption: ");
scanf("%s",&a);
printf("Enter key value: ");
scanf("%d", &key);
for(i = 0; a[i] != '\0'; i++)
{
c1 = a[i];
if(c1 >= 'a' && c1 <= 'z')
{
c1 = c1 + key;
if(c1 > 'z')
{
c1 =c1-'z'+'a'-1;
}
a[i] =c1;
}
else if(c1 >= 'A' && c1 <= 'Z')
{
c1 = c1+key;
if(c1 > 'Z')
{
c1 = c1-'Z'+'A'-1;
}
a[i] = c1;
}
}
// output the encrypted message
printf("Encrypted message is: %s", a);
return 0;
}


//Decryption code
#include<stdio.h>
int main()
{
int i, key;
char a[100], b;
//take message for decryption
printf("Enter message to decrypt: ");
scanf("%s",&a);
printf("Enter key value: ");
scanf("%d", &key);
for(i = 0; a[i] != '\0'; ++i)
{
b =a[i];
if(b >= 'a' && b <= 'z'){
b = b-key;
if(b < 'a')
{
b = b+'z'-'a'+1;
}
a[i] = b;
}
else if(b >= 'A' && b <= 'Z')
{
b =b-key;
if(b < 'A')
{
b =b+'Z'-'A'+1;
}
a[i] = b;
}
}
//output the decrypted message
printf("Decrypted message is: %s", a);
return 0;
}







