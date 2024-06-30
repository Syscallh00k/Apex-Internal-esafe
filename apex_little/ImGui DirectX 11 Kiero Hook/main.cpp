#include "menu.hpp"
#include <iostream>
#include "kiero/minhook/include/MinHook.h"

void CreateConsole()
{

	if (!AllocConsole()) {
		return;
	}

	FILE* fDummy;
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	std::cout.clear();
	std::clog.clear();
	std::cerr.clear();
	std::cin.clear();

	HANDLE hConOut = CreateFile(("CONOUT$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE hConIn = CreateFile(("CONIN$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	SetStdHandle(STD_OUTPUT_HANDLE, hConOut);
	SetStdHandle(STD_ERROR_HANDLE, hConOut);
	SetStdHandle(STD_INPUT_HANDLE, hConIn);
	std::wcout.clear();
	std::wclog.clear();
	std::wcerr.clear();
	std::wcin.clear();
}



uintptr_t VMTHook(void* base, size_t index, uintptr_t hookPtr) {
	uintptr_t table = *(uintptr_t*)(base);
	uintptr_t functionPtr = table + index * sizeof(uintptr_t);
	uintptr_t original = *(uintptr_t*)(functionPtr);

	DWORD old;
	VirtualProtect((LPVOID)functionPtr, sizeof(uintptr_t), PAGE_EXECUTE_READWRITE, &old);
	*(uintptr_t*)(functionPtr) = (uintptr_t)hookPtr;
	VirtualProtect((LPVOID)functionPtr, sizeof(uintptr_t), old, &old);

	return original;
}
 typedef uintptr_t(__stdcall*  CreateMove)(uintptr_t*, int, float, bool);
inline CreateMove oCreateMove;

inline uintptr_t __stdcall CreateMove_(uintptr_t* input, int sequence, float inputSampleTime, bool active)
{
	printf("Hooked");
	return oCreateMove(input, sequence, inputSampleTime, active);
}

inline bool DidHook(void* hookfunc)
{
	(uintptr_t)hookfunc ? printf("Hooked -> 0x%i\n", (uintptr_t)hookfunc) : printf("Hook Fail\n");
	return true;
}

inline bool createhooks()
{

	uintptr_t CreateMoveAddress = *reinterpret_cast<uintptr_t*>((uintptr_t)GetModuleHandle("r5apex.exe") + 0xA4B660); //0xA4B660 0X21B9620
	if (CreateMoveAddress)
		printf("CreateMove : %i\n", CreateMoveAddress);
	(reinterpret_cast<void**>(CreateMoveAddress)) == (reinterpret_cast<void**>(CreateMove_));
	
	return true;
}
//bullet trace 0x22271A8

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	//CreateConsole();
	//std::cout << "[eSafe.Prv] Init" << std::endl;
	//createhooks();
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		if (GetModuleHandle("r5apex.exe") == GetModuleHandle(NULL) || GetModuleHandle("r5apex.exe") != NULL)
		{
			DisableThreadLibraryCalls(hMod);
			CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		}
		else {
			kiero::shutdown();
			exit(0);
		}
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}