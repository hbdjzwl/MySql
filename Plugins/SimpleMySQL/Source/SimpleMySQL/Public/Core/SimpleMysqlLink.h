// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "SimpleMysqlLinkType.h"
#include "MySQL/mysql.h"

struct  FSimpleMysqlLink :public TSharedFromThis<FSimpleMysqlLink>
{
	//构造函数初始化 MYSQL 对象
	FSimpleMysqlLink(const FString& InUser,
		const FString& InHost,
		const FString& InPawd,
		const FString& InDB,
		const uint32   InPort,
		const FString& InUnix_Socket = TEXT(""),
		const TArray<ESimpleClientFlags> InClientFlag = TArray<ESimpleClientFlags>());

	~FSimpleMysqlLink();	//析构函数关闭 MYSQL对象




	void InitMysqlOptions() {}


	//立刻查询传入的SQL语句
	bool QueryLink(const FString& SQL,FString& ErrMesg);

	//获取结果集
	bool GetStoreResult(TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug = FSimpleMysqlDebugResult());

	//获取结果集
	bool GetUseResult(TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug = FSimpleMysqlDebugResult());

	//查询并获取结果
	bool QueryLinkStoreResult(const FString& SQL, TArray<FSimpleMysqlResult> &Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug);

	//查询并获取结果
	bool QueryLinkUseResult(const FString& SQL, TArray<FSimpleMysqlResult> &Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug);

	//创建DB数据库
	bool CreateDataBase(const FString& DataBaseName, EMysqlCharset Charset, FString& ErrorMsg);

	//创建DB数据库并选择
	bool CreateAndSelectDataBase(const FString &DataBaseName, EMysqlCharset Charset, FString &ErrorMsg);

	//删除DB数据库
	bool DropDataBase(const FString& DataBaseName, FString& ErrorMsg);

	//创建表
	bool CreateTable(const FString& TableName, const TMap<FString, FMysqlFieldType>& InFields, const TArray<FString>& InPrimaryKeys, const FMysqlCreateTableParam& Param, FString& ErrorMsg);
	
	//设置选择表
	bool SelectNewDB(const FString &NewDB, FString &ErrMesg);

	//打印结果集
	bool PrintResult(const TArray<FSimpleMysqlResult>& Results, bool bPrintToScreen = true, bool bPrintToLog = true);

protected:
	uint32 ToMySqlClientFlag(ESimpleClientFlags ClientFlags) const;

	//获取查询所有行结果
	void GetResult(MYSQL_RES *RES, TArray<FSimpleMysqlResult> &Results);
private:
	const FString User;			//用户
	const FString Host;			//localhoust
	const FString Pawd;			//密码
		  FString DB;			//数据库db
	const FString Unix_Socket;//
	const uint32  Port;			//端口
	uint16 ClientFlag;


	MYSQL Mysql;				//MySQL官方封装的对象
};


