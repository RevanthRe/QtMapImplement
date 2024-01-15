// JsonReader.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "JsonReader.h"


// This is an example of an exported variable
JSONREADER_API int nJsonReader=0;

// This is an example of an exported function.
JSONREADER_API int fnJsonReader(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CJsonReader::CJsonReader()
{
    return;
}
