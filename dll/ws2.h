#pragma once

#include "types.h"

// macOS defines these as macros
#undef htons
#undef ntohs

struct WSADATA {
	WORD wVersion;
	WORD wHighVersion;
	CHAR szDescription[257];
	CHAR szSystemStatus[129];
	WORD iMaxSockets;
	WORD iMaxUdpDg;
	GUEST_PTR lpVendorInfo;
};

namespace ws2 {

int WINAPI WSAStartup(WORD wVersionRequired, WSADATA *lpWSAData);
int WINAPI WSACleanup();
int WINAPI WSAGetLastError();
int WINAPI gethostname(LPSTR name, int namelen);
GUEST_PTR WINAPI gethostbyname(LPCSTR name);
UINT WINAPI socket(int af, int type, int protocol);
int WINAPI connect(UINT s, const void *name, int namelen);
int WINAPI send(UINT s, const char *buf, int len, int flags);
int WINAPI recv(UINT s, char *buf, int len, int flags);
int WINAPI shutdown(UINT s, int how);
int WINAPI closesocket(UINT s);
WORD WINAPI htons(WORD hostshort);
WORD WINAPI ntohs(WORD netshort);
ULONG WINAPI inet_addr(LPCSTR cp);
GUEST_PTR WINAPI inet_ntoa(ULONG in);
int WINAPI __WSAFDIsSet(UINT fd, LPVOID set);
int WINAPI select(int nfds, LPVOID readfds, LPVOID writefds, LPVOID exceptfds, const void *timeout);

} // namespace ws2
