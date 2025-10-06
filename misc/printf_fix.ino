// once again *NOT REQUIRED IN ANY PROJECT*

// this leverages changes in the AVR-specific C standard library
// note that this is architecture-specific, Arduino Uno uses an AVR chip

#include <stdio.h>
int put(char c, FILE *f) {
  Serial.write(c);
  return 0;
}

void fix_printf() {
  fdevopen(&put, 0);
}

void setup() {
  Serial.begin(9600);
  fix_printf();

  const int num_accounts = 70;
  const char* insult = "Fool";
  printf("You %s! I have %d Alternative Accounts!\n", insult, num_accounts);
 
  // serial still works
  Serial.println("You will never know my main!");
}

void loop() {
  
}
