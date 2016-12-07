@echo off
echo checking %~dp0cliproto.xml

%~dp0dmgenc.exe -m -F "%~dp0cliproto.xml"
if not "%errorlevel%" == "0" (
            echo error: %~dp0cliproto.xml
            goto Failed
            )

goto End

:Failed
pause

:End
