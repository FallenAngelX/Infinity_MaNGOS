@echo off
:quick
rem Quick install section
rem This will automatically use the variables below to install the world and scriptdev2 databases without prompting then optimize them and exit
rem To use: Set your environment variables below and change 'set quick=off' to 'set quick=on' 
set quick=off
if %quick% == off goto standard
echo (( Custom DB Quick Installer ))
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
goto Begin

:patherror
echo Cannot find required files, please ensure you have fully clone from github source
echo.
pause
goto :eof

:Begin
if %quick% == off echo.
if %quick% == off echo This Will Install All Custom Data and Spawn All Custom Content
                  echo.
if %quick% == off set /p yesno=Do you wish to continue? (y/n)
if %quick% == off if %yesno% neq y if %yesno% neq Y goto JumpStart

echo.
echo Installing Custom Data

for %%i in (%dbpath%\*.sql) do if %%i neq %dbpath%\scriptdev2.sql if %%i neq %dbpath%\characters.sql if %%i neq %dbpath%\realmd.sql echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %wdb% < %%i

:JumpStart
if %quick% == off echo.
if %quick% == off echo This Will Install Northren JumpStart Data for the Server
                  echo.
if %quick% == off set /p yesno=Do you wish to continue? (y/n)
if %quick% == off if %yesno% neq y if %yesno% neq Y goto Remove

echo.
echo Installing JumpStart Data

for %%i in (%dbpath1%\*.sql) do if %%i neq %dbpath%\scriptdev2.sql if %%i neq %dbpath%\characters.sql if %%i neq %dbpath%\realmd.sql echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %wdb% < %%i

:Remove
if %quick% == off echo.
if %quick% == off echo This Will Remove All Custom Content Data and Spawns
                  echo.
if %quick% == off set /p yesno=Do you wish to continue? (y/n)
if %quick% == off if %yesno% neq y if %yesno% neq Y goto done

echo.
echo Removing Custom Data and Spawns

for %%i in (%dbpath2%\*.sql) do if %%i neq %dbpath%\scriptdev2.sql if %%i neq %dbpath%\characters.sql if %%i neq %dbpath%\realmd.sql echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %wdb% < %%i

:done
echo.
echo Done :)
echo.
pause