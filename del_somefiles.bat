@echo off
set path=C:\Users\wwx632569\Desktop\a
for /f "delims=" %%i in ('dir %path% /a-d /b /s') do (
   if not %%~nxi==1.txt (del /s /a /q "%%~fi")

)
::删除空目录
for /f "delims=" %%j in ('dir %path% /ad /s /b') do rd "%%~sj"
pause
