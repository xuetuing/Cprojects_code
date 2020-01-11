@echo off

set carsPath=D:\ProgramingTools\OpenAS_Tomcat7\webapps\bes.cars
cd /d D:/CodeLibary/cepcloud/build
call compile.bat

::del the ole .car file
@echo off
for /f "delims=" %%i in ('dir %carsPath% /a-d /b /s') do (
   if not %%~nxi==com.huawei.bes.common.base.nucleus-2.510.0.car (del /s /a /q "%%~fi")

)
::del the empty directory
for /f "delims=" %%j in ('dir %carsPath% /ad /s /b') do rd "%%~sj"

::copy .car files to wabapp/bes.cars
echo copying files...
for /f "tokens=*" %%i in ('dir/s/b/a-d D:\CodeLibary\cepcloud\*.car') do copy "%%i"  D:/ProgramingTools/OpenAS_Tomcat7/webapps/bes.cars/ /y

echo copy done!

pause
