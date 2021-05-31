#include <Crypto.h>

// You can change the value to have a powerful key
// I usually use 32 or 64
const byte length_msg = 16;
// The value depends on the context
// If you want to encode char you need to increase
// because 26 + 10 = 36. Also you need to add a conversion
const byte change_array = 32;

Crypto cryp(change_array, length_msg, analogRead(A0));

byte keyC[change_array];
byte keyM[length_msg];


void setup() {
  Serial.begin(115200);
  Serial.println();

  // Create two keys
  cryp.createCkey(keyC);
  cryp.createMkey(keyM);
  
  // Print them
  Serial.print("byte keyC[");
  Serial.print(change_array);
  Serial.print("] = {");
  for (byte i = 0; i < change_array; i++) {
    Serial.print("0x");
    Serial.print(keyC[i], HEX);
    if(i != change_array-1){
      Serial.print(", ");
    }
  }
  Serial.println("};");

  Serial.print("byte keyM[");
  Serial.print(length_msg);
  Serial.print("] = {");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(keyM[i], HEX);
    if(i != length_msg-1){
      Serial.print(", ");
    }
  }
  Serial.println("};");
}
void loop() {
  //
}
