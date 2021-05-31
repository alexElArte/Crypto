/*
  Crypto.h - Library for flashing cryptography code.
  Created by Alexandre.M, May 25, 2021.
  Released into the public domain.
*/

#include "Crypto.h"

Crypto::Crypto(byte lenC, byte lenMsg, int seed) {
  // Something we do when the class is called
  randomSeed(seed);
  _lenC = lenC;
  _lenMsg = lenMsg;
}

void Crypto::encodeC(byte* msg, byte* key) {
  for (byte i = 0; i < _lenMsg; i++) {
    if (msg[i] <= _lenC && msg[i] != 0) {
      msg[i] = key[msg[i]-1];
    } else {
      // If it's other change it to a random number
      _test = false;
      // Test if the number is not a key
      while (_test == false) {
        _key = random(256);
        _test = true;
        for (byte j = 0; j < 36; j++) {
          if (key[j] == _key) {
            _test = false;
            break;
          }
        }
      }
      msg[i] = _key;
    }
  }
}
void Crypto::decodeC(byte* msg, byte* key) {
  // Decode for each byte of the message
  for (byte i = 0; i < _lenMsg; i++) {
    _test = false;
    // Search the number in the key
    for (byte j = 0; j < _lenC; j++) {
      if (key[j] == msg[i]) {
        _test = true;
        msg[i] = j + 1;
        break;
      }
    }
    if (!_test) msg[i] = 0;
  }
}

void Crypto::encodeM(byte* msg, byte* key) {
  byte _msg[_lenMsg];
  // Put the datas in a temporary variable
  for (byte i = 0; i < _lenMsg; i++) {
    _msg[i] = msg[i];
  }
  // Change the place of each data
  // For more information see the README file
  for (byte i = 0; i < _lenMsg; i++) {
    msg[key[i]] = _msg[i];
  }
}
void Crypto::decodeM(byte* msg, byte* key) {
  byte _msg[_lenMsg];
  // Put the datas in a temporary variable
  for (byte i = 0; i < _lenMsg; i++) {
    _msg[i] = msg[i];
  }
  // Do the same thing in reverse
  // See above to compare
  for (byte i = 0; i < _lenMsg; i++) {
    msg[i] = _msg[key[i]];
  }
}

void Crypto::encodeB(byte* msg) {
  for (byte i = 1; i < _lenMsg; i++) {
    msg[i] ^= msg[i-1];
  }
  msg[0] ^= msg[_lenMsg-1];
}

void Crypto::decodeB(byte* msg) {
  msg[0] ^= msg[_lenMsg-1];
  for (byte i = _lenMsg-1; i > 0; i--) {
    msg[i] ^= msg[i-1];
  }
}

void Crypto::createCkey(byte* key) {
  for (byte i = 0; i < _lenC; i++) {
    _test = false;
    // While the key is the same as another repeat the sequence
    while (_test == false) {
      // Get a number between 0 and 255
      _key = random(256);
      _test = true;
      // Test all variable if it is twice in the array
      for (byte j = 0; j < (i+1); j++) {
        if (key[j] == _key) {
          _test = false;
          break;
        }
      }
    }
    // Put the tested number into the array
    key[i] = _key;
  }
}

void Crypto::createMkey(byte* key) {
  for (byte i = 0; i < _lenMsg; i++) {
    _test = false;
    // While the key is the same as another repeat the sequence
    while (_test == false) {
      // Get a number between 0 and the key's length
      _key = random(_lenMsg);
      _test = true;
      // Test all variable if it is twice in the array
      for (byte j = 0; j < i; j++) {
        if (key[j] == _key) {
          _test = false;
          break;
        }
      }
    }
    // Put the tested number into the array
    key[i] = _key;
  }
}
