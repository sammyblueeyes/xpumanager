//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by Resource.rc

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE 101
#define _APS_NEXT_COMMAND_VALUE 40001
#define _APS_NEXT_CONTROL_VALUE 1001
#define _APS_NEXT_SYMED_VALUE 101
#endif
#endif

#define VER_VERSION_MAJOR 1
#define VER_VERSION_MINOR 2
#define VER_VERSION_PATCH 11
#define VER_VERSION_BUILD 0

#ifndef VER_FILEVERSION
#define VER_FILEVERSION VER_VERSION_MAJOR, VER_VERSION_MINOR, VER_VERSION_PATCH, VER_VERSION_BUILD
#endif
#ifndef VER_PRODUCTVERSION
#define VER_PRODUCTVERSION VER_FILEVERSION
#endif

#define _STR(v) #v
#define _VER_TWO_CONCAT(x, y) _STR(x.y)
#define _VER_THREE_CONCAT(x, y, z) _STR(x.y.z)
#define _VER_FOUR_CONCAT(x, y, z, w) _STR(x.y.z.w)
#define VER_VERSION_MAJORMINOR_STR _VER_TWO_CONCAT(VER_VERSION_MAJOR, VER_VERSION_MINOR)
#define VER_VERSION_MAJORMINORPATCH_STR _VER_THREE_CONCAT(VER_VERSION_MAJOR, VER_VERSION_MINOR, VER_VERSION_PATCH)
#define VER_VERSION_MAJORMINORPATCHBUILD_STR _VER_FOUR_CONCAT(VER_VERSION_MAJOR, VER_VERSION_MINOR, VER_VERSION_PATCH, VER_VERSION_BUILD)

#ifndef VER_FILEVERSION_STR
#define VER_FILEVERSION_STR TEXT(VER_VERSION_MAJORMINORPATCHBUILD_STR)
#endif

#define VER_COMMIT_VERSION VER_VERSION_MAJORMINORPATCH_STR
#ifndef VER_COMMIT_VERSION_TEMP
#define VER_PRODUCTVERSION_STR VER_FILEVERSION_STR
#else
#define VER_COMMIT_VERSION VER_COMMIT_VERSION_TEMP
#define VER_PRODUCTVERSION_STR TEXT(VER_COMMIT_VERSION)
#endif
