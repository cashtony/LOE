@echo off
set basepath=%~dp0..\..\client\ds\Assets
set bundlepath=%~dp0..\..\client\ds\bundle
set python=c:\python27\python.exe
set version=version.txt
set outputpath=%bundlepath%
set resourcelevel=1

rem goto next
del %version%

dir %basepath%\$* /s /b > filelist.lst
echo %basepath%\Prefab\ShaderLib.prefab >> filelist.lst
for /f %%i in (filelist.lst) do (
	echo %%i
	for /f "tokens=5,6*" %%j in ('subwcrev %%i ^| find "Last committed at revision"') do (
		echo %%i %%j >> %version%
		rem %python% update_version.py %basepath% %version% %%i.unity3d %%j
	)
)

:next
%python% gen_version.py %basepath% %bundlepath% %version% %basepath%\bundleInfo.xml %outputpath%\bundleInfo.xml %resourcelevel%

