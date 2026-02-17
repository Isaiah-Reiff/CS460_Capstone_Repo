

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "pal_icushim.h"

#define PER_FUNCTION_BLOCK(fn, lib) __typeof(fn)* fn##_ptr;
FOR_ALL_ICU_FUNCTIONS
#undef PER_FUNCTION_BLOCK

static void* libicuuc = NULL;
static void* libicui18n = NULL;

#define VERSION_PREFIX_NONE ""
#define VERSION_PREFIX_SUSE "suse"

#define MaxICUVersionStringLength (sizeof(VERSION_PREFIX_SUSE) + 33)

#ifdef __APPLE__

static int FindICULibs(const char* versionPrefix, char* symbolName, char* symbolVersion)
{
#ifndef OSX_ICU_LIBRARY_PATH
    c_static_assert_msg(false, "The ICU Library path is not defined");
#endif 

    
    libicuuc = dlopen(OSX_ICU_LIBRARY_PATH, RTLD_LAZY);

    if (libicuuc == NULL)
    {
        return FALSE;
    }

    
    libicui18n = libicuuc;

    return TRUE;
}

#else 

#define MinICUVersion  U_ICU_VERSION_MAJOR_NUM
#define MaxICUVersion  (MinICUVersion + 20)
#define MinMinorICUVersion  1
#define MaxMinorICUVersion  5
#define MinSubICUVersion 1
#define MaxSubICUVersion 5

static void GetVersionedLibFileName(const char* baseFileName, int majorVer, int minorVer, int subVer, const char* versionPrefix, char* result)
{
    assert(majorVer != -1);

    int nameLen = sprintf(result, "%s.%s%d", baseFileName, versionPrefix, majorVer);

    if (minorVer != -1)
    {
        nameLen += sprintf(result + nameLen, ".%d", minorVer);
        if (subVer != -1)
        {
            sprintf(result + nameLen, ".%d", subVer);
        }
    }
}

static int FindSymbolVersion(int majorVer, int minorVer, int subVer, char* symbolName, char* symbolVersion)
{
    
    
    if (dlsym(libicuuc, "u_strlen") == NULL)
    {
        
        sprintf(symbolVersion, "_%d", majorVer);
        sprintf(symbolName, "u_strlen%s", symbolVersion);
        if ((dlsym(libicuuc, symbolName) == NULL) && (minorVer != -1))
        {
            
            sprintf(symbolVersion, "_%d_%d", majorVer, minorVer);
            sprintf(symbolName, "u_strlen%s", symbolVersion);
            if ((dlsym(libicuuc, symbolName) == NULL) && (subVer != -1))
            {
                
                sprintf(symbolVersion, "_%d_%d_%d", majorVer, minorVer, subVer);
                sprintf(symbolName, "u_strlen%s", symbolVersion);
                if (dlsym(libicuuc, symbolName) == NULL)
                {
                    return FALSE;
                }
            }
        }
    }

    return TRUE;
}

static int OpenICULibraries(int majorVer, int minorVer, int subVer, const char* versionPrefix, char* symbolName, char* symbolVersion)
{
    char libicuucName[64];
    char libicui18nName[64];

    c_static_assert_msg(sizeof("libicuuc.so") + MaxICUVersionStringLength <= sizeof(libicuucName), "The libicuucName is too small");
    GetVersionedLibFileName("libicuuc.so", majorVer, minorVer, subVer, versionPrefix, libicuucName);

    c_static_assert_msg(sizeof("libicui18n.so") + MaxICUVersionStringLength <= sizeof(libicui18nName), "The libicui18nName is too small");
    GetVersionedLibFileName("libicui18n.so", majorVer, minorVer, subVer, versionPrefix, libicui18nName);

    libicuuc = dlopen(libicuucName, RTLD_LAZY);
    if (libicuuc != NULL)
    {
        if (FindSymbolVersion(majorVer, minorVer, subVer, symbolName, symbolVersion))
        {
            libicui18n = dlopen(libicui18nName, RTLD_LAZY);
        }
        if (libicui18n == NULL)
        {
            dlclose(libicuuc);
            libicuuc = NULL;
        }
    }

    return libicuuc != NULL;
}

static int FindLibUsingOverride(const char* versionPrefix, char* symbolName, char* symbolVersion)
{
    char* versionOverride = getenv("CLR_ICU_VERSION_OVERRIDE");
    if (versionOverride != NULL)
    {
        int first = -1;
        int second = -1;
        int third = -1;

        int matches = sscanf(versionOverride, "%d.%d.%d", &first, &second, &third);
        if (matches > 0)
        {
            if (OpenICULibraries(first, second, third, versionPrefix, symbolName, symbolVersion))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

static int FindLibWithMajorVersion(const char* versionPrefix, char* symbolName, char* symbolVersion)
{
    
    

    
    if (OpenICULibraries(MinICUVersion, -1, -1, versionPrefix, symbolName, symbolVersion))
    {
        return TRUE;
    }

    
    for (int i = MaxICUVersion; i > MinICUVersion; i--)
    {
        if (OpenICULibraries(i, -1, -1, versionPrefix, symbolName, symbolVersion))
        {
            return TRUE;
        }
    }

    return FALSE;
}

static int FindLibWithMajorMinorVersion(const char* versionPrefix, char* symbolName, char* symbolVersion)
{
    for (int i = MaxICUVersion; i >= MinICUVersion; i--)
    {
        for (int j = MaxMinorICUVersion; j >= MinMinorICUVersion; j--)
        {
            if (OpenICULibraries(i, j, -1, versionPrefix, symbolName, symbolVersion))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

static int FindLibWithMajorMinorSubVersion(const char* versionPrefix, char* symbolName, char* symbolVersion)
{
    for (int i = MaxICUVersion; i >= MinICUVersion; i--)
    {
        for (int j = MaxMinorICUVersion; j >= MinMinorICUVersion; j--)
        {
            for (int k = MaxSubICUVersion; k >= MinSubICUVersion; k--)
            {
                if (OpenICULibraries(i, j, k, versionPrefix, symbolName, symbolVersion))
                {
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

static int FindICULibs(const char* versionPrefix, char* symbolName, char* symbolVersion)
{
    return FindLibUsingOverride(versionPrefix, symbolName, symbolVersion) ||
           FindLibWithMajorVersion(versionPrefix, symbolName, symbolVersion) ||
           FindLibWithMajorMinorVersion(versionPrefix, symbolName, symbolVersion) ||
           FindLibWithMajorMinorSubVersion(versionPrefix, symbolName, symbolVersion);
}

#endif 

int32_t GlobalizationNative_LoadICU()
{
    char symbolName[128];
    char symbolVersion[MaxICUVersionStringLength + 1] = "";

    if (!FindICULibs(VERSION_PREFIX_NONE, symbolName, symbolVersion))
    {
#ifndef __APPLE__
        if (!FindICULibs(VERSION_PREFIX_SUSE, symbolName, symbolVersion))
#endif
        {
            return FALSE;
        }
    }

    
#define PER_FUNCTION_BLOCK(fn, lib) \
    c_static_assert_msg((sizeof(#fn) + MaxICUVersionStringLength + 1) <= sizeof(symbolName), "The symbolName is too small for symbol " #fn); \
    sprintf(symbolName, #fn "%s", symbolVersion); \
    fn##_ptr = (__typeof(fn)*)dlsym(lib, symbolName); \
    if (fn##_ptr == NULL) { fprintf(stderr, "Cannot get symbol %s from " #lib "\nError: %s\n", symbolName, dlerror()); abort(); }

    FOR_ALL_ICU_FUNCTIONS
#undef PER_FUNCTION_BLOCK

#ifdef __APPLE__
    
    libicui18n = NULL;
#endif 

    return TRUE;
}

int32_t GlobalizationNative_GetICUVersion()
{
    int32_t version;
    u_getVersion((uint8_t *) &version);
    return version;
}

__attribute__((destructor))
void ShutdownICUShim()
{
    if (libicuuc != NULL)
    {
        dlclose(libicuuc);
        libicuuc = NULL;
    }

    if (libicui18n != NULL)
    {
        dlclose(libicui18n);
        libicui18n = NULL;
    }
}

