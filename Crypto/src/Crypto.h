/*
	Crypto.h - Library for flashing cryptography function.
	Created by alexELArte, May 25, 2021.
	Released into the public domain.
*/

#ifndef Crypto_h
#define Crypto_h

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class Crypto {
	public:
		Crypto(byte lenC, byte lenMsg, int seed);

		// Encode a message with a key
		void encodeC(byte* msg, byte* key);
		void encodeM(byte* msg, byte* key);

		// Decode a message with a key
		void decodeC(byte* msg, byte* key);
		void decodeM(byte* msg, byte* key);

		// Special function without the need of a key
		// For more information see the README file
		void encodeB(byte* msg);
		void decodeB(byte* msg);

		// Create keys
		void createCkey(byte* key);
		void createMkey(byte* key);
		
	private:
		byte _lenC;   // 
		byte _lenMsg; // Packet's length
		byte _key;
		bool _test;
};

#endif