@echo off

tortoiseproc /command:update /nodlg /noui /path:. /closeonend:2
@if not errorlevel 0 goto Fail

call %~dp0protocol\generateprotocol_CSharp.bat
xcopy %~dp0protocol\*.cs %~dp0..\client\ds\Assets\Script\NetProtocal\ /y/d/q

goto End
:Fail

echo 貌似出错了，检查一下前面的输出
pause
 
:End