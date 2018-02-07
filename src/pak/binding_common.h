#ifndef MTR_PAK_BINDING_COMMON_H
#define MTR_PAK_BINDING_COMMON_H

MTR_FUNC(int, MTR_PakFunctionSupported, const char *);
MTR_FUNC(bool, MTR_PakInit, void);
MTR_FUNC(bool, MTR_PakMount, const char *filename, const char *mountPoint);
MTR_FUNC(bool, MTR_PakUnmount, const char *filename);
MTR_FUNC(bool, MTR_PakQuit, void);
MTR_FUNC(MTR_FopenFunc, MTR_PakGetFopen, void);
MTR_FUNC(MTR_FcloseFunc, MTR_PakGetFclose, void);
MTR_FUNC(MTR_FeofFunc, MTR_PakGetFeof, void);
MTR_FUNC(MTR_FtellFunc, MTR_PakGetFtell, void);
MTR_FUNC(MTR_FseekFunc, MTR_PakGetFseek, void);
MTR_FUNC(MTR_RewindFunc, MTR_PakGetRewind, void);
MTR_FUNC(MTR_FreadFunc, MTR_PakGetFread, void);
MTR_FUNC(MTR_FwriteFunc, MTR_PakGetFwrite, void);
MTR_FUNC(MTR_FprintfFunc, MTR_PakGetFprintf, void);
MTR_FUNC(MTR_FreadableFunc, MTR_PakGetFreadable, void);
MTR_FUNC(MTR_FwritableFunc, MTR_PakGetFwritable, void);

#endif
