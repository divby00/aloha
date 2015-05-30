#ifndef __ALOHA_DEFS_H
#define __ALOHA_DEFS_H

#ifdef WIN32
#ifdef BUILD_DLL
/* DLL export */
#define EXPORT __declspec(dllexport)
#else
/* EXE import */
/*#define EXPORT __declspec(dllimport)*/
#define EXPORT
#endif
#else
#define EXPORT
#endif
#endif
