@echo off

echo checking %~dp0dmdserror.xat

%~dp0dmgenc.exe -e -F "%~dp0dmdserror.xat"
if not "%errorlevel%" == "0" (
            echo error: %~dp0dmdserror.xat
            goto Failed
            )

goto End

:Failed
pause

:End
