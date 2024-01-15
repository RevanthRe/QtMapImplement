// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the JSONREADER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// JSONREADER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef JSONREADER_EXPORTS
#define JSONREADER_API __declspec(dllexport)
#else
#define JSONREADER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class JSONREADER_API CJsonReader {
public:
	CJsonReader(void);
	// TODO: add your methods here.
};

extern JSONREADER_API int nJsonReader;

JSONREADER_API int fnJsonReader(void);
