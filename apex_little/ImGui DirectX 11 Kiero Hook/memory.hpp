#pragma once
#include <Windows.h>

template<typename T = uintptr_t, typename A>
T& read(A address) {
	auto addresss = (DWORD64)address;
	if (addresss > 0x40000 && (addresss + sizeof(T)) < 0x7FFFFFFF0000)
		return *(T*)addresss;

	auto n = nullptr;
	return reinterpret_cast<T&>(n);
}

template <typename T>
void write(uintptr_t address, T data) {
	if (address > 0x40000 && (address + sizeof(T)) < 0x7FFFFFFF0000)
		*(T*)(address) = data;
}