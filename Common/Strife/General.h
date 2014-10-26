#pragma once

//!  Anonymous namespace with default functions
namespace CoreFunctions {
	/// Enables the debug console
	void ShowConsole();
	/// Prints a string to the debug console
	void dprint(string szPrint);
	/// Sets the clipboard text
	void SetClipboardText(string szText);
	/// Returns the clipboard text
	string GetClipboardText();
	/// Enables or Disables the game key processing
	void AllowKeyInput(bool bAllow);
	/// Enables or Disables the game camera movement
	void AllowCameraInput(bool bAllow);
	/// Sets the game chat window status
	void SetChatStatus(bool bOpen);
	/// Outputs a string to DbgView
	void OutputDebugString(string szOutput);

	/// Returns the local player
	Unit GetLocalPlayer();
	/// Returns the target unit
	Unit GetTarget();

	/// Returns the computer tick count
	DWORD GetTickCount();
	/// Returns if the key is down
	bool IsKeyDown(BYTE bKey);
	/// Returns if the key is pressed
	bool IsKeyPressed(BYTE bKey);


	/// Prints text to the local chat
	void PrintToChat(string szText);
	/// Send a packet to the game server
	void SendPacket(Packet packet);

	/// Returns the game cursor position
	D3DXVECTOR3 GetCursor();
	/// Draws text to the screen
	void DrawText(string szText,int fontSize,float x,float y,int iColor);
	/// Draws a circle to the game screen
	void DrawCircle(float fX, float fY, float fRange);
	/// Translate world positions to screen
	D3DXVECTOR3 WorldToScreen(D3DXVECTOR3 vIn);
	/// Issues a move command for the local unit
	void MoveTo(float x,float y);
	/// Attacks a unit give UID
	void Attack(DWORD uid);


};