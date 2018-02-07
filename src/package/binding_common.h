#ifndef MTR_PACKAGE_BINDING_COMMON_H
#define MTR_PACKAGE_BINDING_COMMON_H

MTR_FUNC(int, MTR_PackageFunctionSupported, const char *);
MTR_FUNC(bool, MTR_PackageInit, void);
MTR_FUNC(bool, MTR_PackageMount, const char *filename, const char *mountPoint);
MTR_FUNC(bool, MTR_PackageUnmount, const char *filename);
MTR_FUNC(bool, MTR_PackageQuit, void);
MTR_FUNC(MTR_FopenFunc, MTR_PackageGetFopen, void);
MTR_FUNC(MTR_FcloseFunc, MTR_PackageGetFclose, void);
MTR_FUNC(MTR_FeofFunc, MTR_PackageGetFeof, void);
MTR_FUNC(MTR_FtellFunc, MTR_PackageGetFtell, void);
MTR_FUNC(MTR_FseekFunc, MTR_PackageGetFseek, void);
MTR_FUNC(MTR_RewindFunc, MTR_PackageGetRewind, void);
MTR_FUNC(MTR_FreadFunc, MTR_PackageGetFread, void);
MTR_FUNC(MTR_FwriteFunc, MTR_PackageGetFwrite, void);
MTR_FUNC(MTR_FprintfFunc, MTR_PackageGetFprintf, void);
MTR_FUNC(MTR_FreadableFunc, MTR_PackageGetFreadable, void);
MTR_FUNC(MTR_FwritableFunc, MTR_PackageGetFwritable, void);

#endif
