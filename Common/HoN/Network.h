#pragma once
#include <Windows.h>

//!  Namespace for network functions and structures
namespace Network {
	//!  Class used for Writing and Reading game packets
	class EnetPacket {
	public:
		/// The header of the packet.
		BYTE header;
		/// Boolean if the packet should be blocked.
		bool bBlock;
		/// Size of the Packet.
		int size;
		/// Position of the reading pointer.
		int pos;
		/// Channel
		int channel;
		/// Flags
		int flags;
		/// Default LoL Packet constructor.
		EnetPacket(BYTE bHeader);

		/// Blocks the packet.
		void Block();
		/// Hide the packet from subsequent callbacks.
		void Hide();

		/// Add the offset to the reading pointer.
		void Skip(__in int iOffset);
		/// Get the count of remaining bytes.
		void GetRemaining();
		/// Set the position of the reading pointer.
		void SetPos(__in int iPos);

		/// Writes 1 byte to the packet as int.
		void Encode1(__in BYTE bValue);
		/// Writes 2 byte to the packet as int.
		void Encode2(__in WORD wValue);
		/// Writes 4 byte to the packet as int.
		void Encode4(__in DWORD dwValue);
		/// Writes 4 byte to the packet as float.
		void EncodeF(__in float fValue);
		/// Writes a null terminator string to the packet.
		void EncodeStr(__in string bValue);

		/// Reads 1 byte from the packet as int.
		BYTE Decode1();
		/// Reads 2 byte from the packet as int.
		WORD Decode2();
		/// Reads 4 byte from the packet as int.
		DWORD Decode4();
		/// Reads 4 byte from the packet as float.
		float DecodeF();
		/// Reads a null terminator string from the packet.
		string DecodeStr();

		/// Replaces 1 byte to the packet as int.
		void Replace1(__in BYTE bValue, __in_opt int iPos = 0);
		/// Replaces 2 byte to the packet as int.
		void Replace2(__in WORD wValue, __in_opt int iPos = 0);
		/// Replaces 4 byte to the packet as int.
		void Replace4(__in DWORD dwValue, __in_opt int iPos = 0);
		/// Replaces 4 byte to the packet as float.
		void ReplaceF(__in float fValue, __in_opt int iPos = 0);
		/// Replaces a null terminator string to the packet.
		void ReplaceStr(__in string bValue, __in_opt int iPos = 0);
	};
	void SendPacket(EnetPacket packet);
	void RecvPacket(EnetPacket packet);
}