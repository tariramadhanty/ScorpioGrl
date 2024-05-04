#include <stdio.h>
#include <string.h>
 {
  if (strlen(cardNumber) != 16 && strlen(cardNumber) != 13) {
    return 0;
  }
  int sum = 0;
  int length = strlen(cardNumber);
  for (int i = length - 1; i >= 0; i--) { 
    int digit = cardNumber[i] - '0';
    if (i % 2 != 0) {
      digit *= 2;
      if (digit > 9) {
        digit -= 9;
      }
    }
    sum += digit;
  }
  return sum % 10 == 0;
}
int main() {
  char cardNumber[17]; 
  printf("Masukkan nomor kartu: ");
  scanf("%s", cardNumber);
if (isValidCardNumber(cardNumber)) {
    // Determine card type
    if (cardNumber[0] == '4') {
      printf("Nomor kartu anda: %s\n", cardNumber);
      printf("Tipe kartu anda: VISA\n");
    } else if (strncmp(cardNumber, "51", 2) == 0 || strncmp(cardNumber, "52", 2) == 0 ||
               strncmp(cardNumber, "53", 2) == 0 || strncmp(cardNumber, "54", 2) == 0 ||
               strncmp(cardNumber, "55", 2) == 0) {
      printf("Nomor kartu anda: %s\n", cardNumber);
      printf("Tipe kartu anda: MASTERCARD\n");
    } else {
      printf("Nomor kartu anda: %s\n", cardNumber);
      printf("Tipe kartu anda: TIDAK DIKETAHUI\n");
    }
int checksum = 0;
    int length = strlen(cardNumber);
    for (int i = 0; i < length; i++) {
      checksum += cardNumber[i] - '0';
    }
    
     printf("Checksum: %d\n", checksum);
  } else {
    printf("Nomor kartu anda: %s\n", cardNumber);
    printf("Tipe kartu anda: TIDAK VALID\n");
  }
  return 0;
}
