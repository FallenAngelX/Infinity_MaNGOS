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
color 3
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
echo             ( Infinity_MaNGOS DataBase Project )
echo                 ( Credits for DB Installer )
echo                  (PSMDB and FallenAngelX )
echo             IsQl Databases Importer Version 2.0
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
set /p cdb=What is your Characters database name?  [characters]  : 
if %cdb%. == . set cdb=characters
set /p rdb=What is your Realmd database name?      [realmd]      : 
if %rdb%. == . set rdb=realmd

:install
set dbpath=Development\World
set dbpath1=Development\Characters
set dbpath2=Development\Realmd
set dbpath3=Development\Updates
set dbpath4=Development
set optim=Tools\DB_Optimizer
set mysql=.\Development

:checkpaths
if not exist %dbpath% then goto patherror
if not exist %optim% then goto patherror
if not exist %mysql%\mysql.exe then goto patherror
goto create

:patherror
echo Cannot find required files, please ensure you have fully clone from github source
echo.
pause
goto :eof

:Create
if %quick% == off echo.
if %quick% == off echo Do u need to create new databases (*This will wipe your current Databases 
                  echo and create the needed empty folders*)
                  echo.
if %quick% == off set /p yesno=Do you wish to continue? (y/n)
if %quick% == off if %yesno% neq y if %yesno% neq Y goto World

echo.
echo Creating Databases

for %%i in (%dbpath4%\*.sql) do if %%i neq %dbpath3%\*.sql if %%i neq %dbpath1%\*.sql if %%i neq %dbpath2%\*.sql echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% < %%i

:world
if %quick% == off echo.
if %quick% == off echo This will wipe out your current World database data and replace it with new data.
if %quick% == off set /p yesno=Do you wish to continue? (y/n) 
if %quick% == off if %yesno% neq y if %yesno% neq Y goto updates

echo.
echo Importing World database

for %%i in (%dbpath%\*.sql) do if %%i neq %dbpath%\scriptdev2.sql if %%i neq %dbpath%\characters.sql if %%i neq %dbpath%\realmd.sql echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %wdb% < %%i

:updates
if %quick% == off echo.
if %quick% == off echo This will add Updates to current World DataBase.
if %quick% == off set /p yesno=Do you wish to continue? (y/n)
if %quick% == off if %yesno% neq y if %yesno% neq Y goto :characters

echo.
echo Importing World database updates

for %%i in (%dbpath3%\*.sql) do if %%i neq %dbpath3%\*.sql if %%i neq %dbpath1%\*.sql if %%i neq %dbpath2%\*.sql echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %wdb% < %%i

:characters
echo.
echo This will wipe out your current Characters database and replace it.
set /p yesno=Do you wish to continue? (y/n) 
if %yesno% neq y if %yesno% neq Y goto realm

echo.
echo Importing Characters database

for %%i in (%dbpath1%\*.sql) do if %%i neq %dbpath%\*.sql if %%i neq %dbpath1%\*.sql if %%i neq %dbpath2%\*.sql echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %cdb% < %%i

:realm
echo.
echo This will wipe out your current Realm database and replace it.
set /p yesno=Do you wish to continue? (y/n) 
if %yesno% neq y if %yesno% neq Y goto optimize

echo.
echo Importing Realm database

for %%i in (%dbpath2%\*.sql) do if %%i neq %dbpath%\*.sql if %%i neq %dbpath1%\*.sql if %%i neq %dbpath3%\*.sql echo %%i & %mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %rdb% < %%i

:optimize
if %quick% == off echo.
if %quick% == off echo This will optimize your current database.
if %quick% == off set /p yesno=Do you wish to continue? (y/n) 
if %quick% == off if %yesno% neq y if %yesno% neq Y goto done

echo.
echo Optimizing database

%optim%\Optimizer.exe
copy %optim%\scriptdev2_optimize.sql . >nul
echo World
%mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %wdb% < optimize.sql >nul
echo ScriptDev2
%mysql%\mysql -q -s -h %svr% --user=%user% --password=%pass% --port=%port% %wdb% < scriptdev2_optimize.sql >nul
del optimize.sql
del scriptdev2_optimize.sql

if %quick% neq off goto :eof

:done
echo.
echo Done :)
echo.
pause