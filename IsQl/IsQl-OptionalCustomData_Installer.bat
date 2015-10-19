@echo off
:quick
rem Quick install section
rem This will automatically use the variables below to install the world and scriptdev2 databases without prompting then optimize them and exit
rem To use: Set your environment variables below and change 'set quick=off' to 'set quick=on' 
set quick=off
if %quick% == off goto standard
echo (( PSDB Quick Installer ))
rem -- Change the values below to match your server --
set svr=localhost
set user=root
set pass=
set port=3306
set wdb=mangos
rem -- Don't change past this point --
set yesno=y
goto install

:standard
rem Standard install section
color C
echo.
echo IIII   i         i           i       i     iiii        iiii       iiiii 
echo  II    ii       ii           ii      i    i    i      i    i     i     i
echo  II    ii       ii           i i     i   i      i    i      i   i       i
echo  II    i i     i i    iiii   i i     i  i           i        i  i        
echo IIII   i i     i i   i    i  i  i    i  i           i        i   i       
echo        i  i   i  i  i     i  i   i   i  i           i        i    iii    
echo        i  i   i  i      iii  i   i   i  i    iiiii  i        i       iii 
echo        i   i i   i   iii  i  i    i  i  i        i  i        i          i
echo        i   i i   i  i     i  i     i i  i        i  i        i          i
echo        i   i i   i  i     i  i     i i   i      i    i      i   i       i
echo        i    i    i  i    ii  i      ii    i    i      i    i     i     i 
echo        i    i    i   iiii i  i       i     iiii        iiii       iiiii  
echo.
echo             IsQl CUSTOM Databases Importer Version 0.5
echo.
echo.
set /p svr=What is your MySQL host name?           [localhost]   : 
if %svr%. == . set svr=localhost
set /p user=What is your MySQL user name?           [root]        : 
if %user%. == . set user=root
set /p pass=What is your MySQL password?            [ ]           : 
if %pass%. == . set pass=
set /p port=What is your MySQL port?                [3306]        : 
if %port%. == . set port=3306
set /p wdb=What is your World database name?       [mangos]      : 
if %wdb%. == . set wdb=mangos

:install
set dbpath=Custom\Custom
set dbpath1=Custom\Northrend_JumpStart
set dbpath2=Custom\RemoveData
set mysql=.\Development

:checkpaths
if not exist %dbpath% then goto patherror
if not exist %mysql%\mysql.exe then goto patherror
goto create

:patherror
echo Cannot find required files, please ensure you have fully clone from github source
echo.
pause
goto :eof

:Begin


:done
echo.
echo Done :)
echo.
pause