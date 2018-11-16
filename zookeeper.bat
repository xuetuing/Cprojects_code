@echo off
cd /d D:\ProgramingTools\zookeeper6\ZooKeeper-3.4.6\bin
start "zkServer" call zkServer.cmd
cd /d D:\ProgramingTools\ZookeeperClient
java -jar com.jzp.zookeeperclient-1.0.0-SNAPSHOT.jar

pause
