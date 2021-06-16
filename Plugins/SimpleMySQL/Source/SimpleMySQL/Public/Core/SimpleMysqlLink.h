// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "SimpleMysqlLinkType.h"
#include "MySQL/mysql.h"

struct  FSimpleMysqlLink :public TSharedFromThis<FSimpleMysqlLink>
{
	FSimpleMysqlLink(const FString& InUser,
		const FString& InHost,
		const FString& InPawd,
		const FString& InDB,
		const uint32   InPort,
		const FString& InUnix_Socket = TEXT(""),
		const TArray<ESimpleClientFlags> InClientFlag = TArray<ESimpleClientFlags>());

	~FSimpleMysqlLink();

	void InitMysqlOptions() {}

	bool QueryLink(const FString& SQL,FString& ErrMesg);


	bool CreateDataBase(const FString& DataBaseName, EMysqlCharset Charset, FString& ErrorMsg);

	bool CreateAndSelectDataBase(const FString &DataBaseName, EMysqlCharset Charset, FString &ErrorMsg);

	bool DropDataBase(const FString& DataBaseName, FString& ErrorMsg);

	//������
	bool CreateTable(const FString& TableName, const TMap<FString, FMysqlFieldType>& InFields, const TArray<FString>& InPrimaryKeys, const FMysqlCreateTableParam& Param, FString& ErrorMsg);
	//����ѡ���
	bool SelectNewDB(const FString &NewDB, FString &ErrMesg);
protected:
	uint32 ToMySqlClientFlag(ESimpleClientFlags ClientFlags) const;
private:
	const FString User;			//�û�
	const FString Host;			//localhoust
	const FString Pawd;			//����
		  FString DB;			//���ݿ�db
	const FString Unix_Socket;//
	const uint32  Port;			//�˿�
	uint16 ClientFlag;


	MYSQL Mysql;
};


