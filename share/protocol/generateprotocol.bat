@echo off

if exist %~dp0protocolgen.lock goto WaitLock

rem generate lock file
(echo hi) > %~dp0protocolgen.lock 

rem perform protocol generation
for /f %%i in ('dir %~dp0*proto*.xml /b ') do (
	echo checking %%i
	start /wait /D%~dp0 %~dp0coderex.exe %%i %~dp0
	if errorlevel 1 (
		echo error: %%i
		goto Failed
	)
)

call generatemsg_cliproto.bat

del %~dp0protocolgen.lock 
goto End

:WaitLock
rem wait 1 second
ping localhost -n 2 > nul

if exist %~dp0protocolgen.lock goto WaitLock
goto End


:Failed
del %~dp0protocolgen.lock 
pause

:End
