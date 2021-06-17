#include <Crypto.h>

// You can change the value to have a powerful key
// I usually use 32 or 64
const byte length_msg = 16;
// The value depends on the context
// If you want to encode char you need to increase
// because 26 + 10 = 36. Also you need to add a conversion
// The number will be encode between 1 and change_array
// 0 is null and considered as none data type
const byte change_array = 32;

Crypto cryp(change_array, length_msg);

byte keyC[change_array];
byte keyM[length_msg];
byte msg1[16] = {
  0, 1, 2, 3,
  4, 5, 6, 7,
  8, 9, 10, 11,
  12, 13, 14, 15
};


void setup() {
  Serial.begin(115200);
  Serial.println("Example to show you the functions");
  
  // Init library
  cryp.init(analogRead(A0));
  
  /***********************KEYM***********************/
  // Create a key
  cryp.createMkey(keyM);

  Serial.print("keyM: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println();

  Serial.print("nocode: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println();

  // Encode
  cryp.encodeM(msg1, keyM);

  Serial.print("encode: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println();

  // Decode
  cryp.decodeM(msg1, keyM);

  Serial.print("decode: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println('\n');

  /***********************KEYC***********************/
  // Create a key
  cryp.createCkey(keyC);

  Serial.print("keyC: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println();

  Serial.print("nocode: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println();

  // Encode
  cryp.encodeC(msg1, keyC);

  Serial.print("encode: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println();

  // Decode
  cryp.decodeC(msg1, keyC);

  Serial.print("decode: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println('\n');

  /*********************NOKEY***********************/
  Serial.println("This function doesn't need any key");
  
  Serial.print("nocode: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println();

  // Encode
  cryp.encodeB(msg1);

  Serial.print("encode: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println();

  // Decode
  cryp.decodeB(msg1);

  Serial.print("decode: ");
  for (byte i = 0; i < length_msg; i++) {
    Serial.print("0x");
    Serial.print(msg1[i], HEX);
    Serial.print(' ');
  }
  Serial.println('\n');

}
void loop() {
  //
}
