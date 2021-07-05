// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "SimpleMysqlLinkType.h"
#include "MySQL/mysql.h"

struct  FSimpleMysqlLink :public TSharedFromThis<FSimpleMysqlLink>
{
	//���캯����ʼ�� MYSQL ����
	FSimpleMysqlLink(const FString& InUser,
		const FString& InHost,
		const FString& InPawd,
		const FString& InDB,
		const uint32   InPort,
		const FString& InUnix_Socket = TEXT(""),
		const TArray<ESimpleClientFlags> InClientFlag = TArray<ESimpleClientFlags>());

	~FSimpleMysqlLink();	//���������ر� MYSQL����




	void InitMysqlOptions() {}


	//����DB���ݿ�
	bool CreateDataBase(const FString& DataBaseName, EMysqlCharset Charset, FString& ErrorMsg);
	//����DB���ݿⲢѡ��
	bool CreateAndSelectDataBase(const FString& DataBaseName, EMysqlCharset Charset, FString& ErrorMsg);
	//ɾ��DB���ݿ�
	bool DropDataBase(const FString& DataBaseName, FString& ErrorMsg);
	//ѡ�����ݿ�
	bool SelectNewDB(const FString& NewDB, FString& ErrMesg);


	//������
	bool CreateTable(const FString& TableName, const TMap<FString, FMysqlFieldType>& InFields, const TArray<FString>& InPrimaryKeys, const FMysqlCreateTableParam& Param, FString& ErrorMsg);
	//����ȫ��ɾ�� �ͷ��ڴ� ��֧�ֻع� Innodb �� MyISAM ȫ�����
	bool DropTable(const FString& TableName, FString& ErrorMsg);
	//����� �ͷ��ڴ� ��֧�ֻع� Innodb �� MyISAM ȫ�����
	bool TruncateTable(const FString& TableName, FString& ErrorMsg);
	//�ɻع�����û���������ͷŵ��ڴ�
	bool DeleteFromTable(const FString& TableName, FString& ErrorMsg);
	//�Ż���:���� DeleteFromTable ����ɾ�����ͷ��ڴ�
	bool OptimiseTable(const FString& TableName, FString& ErrorMsg);
	//����ɾ����
	bool DeleteFromTableWhereData(const FString& TableName, const TArray<FSimpleMysqlComparisonOperator>& Condition, FString& ErrorMsg);


	
	//���±�����
	bool UpdateTableData(const FString& TableName, const TArray<FSimpleMysqlAssignment>& InFields, const TArray<FSimpleMysqlComparisonOperator>& Condition, FString& ErrorMsg);


	

	//��ȡ���ݿ��������
	bool GetSelectTableData(EMysqlQuerySaveType SaveType, const FString& TableName, const TArray<FString>& InFields, const FSimpleMysqlQueryParameters& QueryParam, TArray<FSimpleMysqlResult>& Results, FString& ErrorMes, const FSimpleMysqlDebugResult& Debug = FSimpleMysqlDebugResult());
	//���ٲ�ѯ�����SQL���
	bool QueryLink(const FString& SQL, FString& ErrMesg);
	//
	bool GetSelectTableDataSQL(FString& SQL, const FString& TableName, const TArray<FString>& InFields, const FSimpleMysqlQueryParameters& QueryParam);
	//��ӡ�����
	bool PrintResult(const TArray<FSimpleMysqlResult>& Results, bool bPrintToScreen = true, bool bPrintToLog = true);

protected:
	uint32 ToMySqlClientFlag(ESimpleClientFlags ClientFlags) const;
	//��ȡ��ѯ�����н��
	void GetResult(MYSQL_RES* RES, TArray<FSimpleMysqlResult>& Results);
	bool GetSelectTableDataUR(const FString& TableName, const TArray<FString>& InFields, const FSimpleMysqlQueryParameters& QueryParam, TArray<FSimpleMysqlResult>& Results, FString& ErrorMes, const FSimpleMysqlDebugResult& Debug = FSimpleMysqlDebugResult());
	bool GetSelectTableDataSR(const FString& TableName, const TArray<FString>& InFields, const FSimpleMysqlQueryParameters& QueryParam, TArray<FSimpleMysqlResult>& Results, FString& ErrorMes, const FSimpleMysqlDebugResult& Debug = FSimpleMysqlDebugResult());
private:
	//��ȡ�����
	bool GetStoreResult(TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug = FSimpleMysqlDebugResult());
	//��ȡ�����
	bool GetUseResult(TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug = FSimpleMysqlDebugResult());
	//��ѯ����ȡ���
	bool QueryLinkStoreResult(const FString& SQL, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug);
	//��ѯ����ȡ���
	bool QueryLinkUseResult(const FString& SQL, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug);
private:
	const FString User;			//�û�
	const FString Host;			//localhoust
	const FString Pawd;			//����
		  FString DB;			//���ݿ�db
	const FString Unix_Socket;//
	const uint32  Port;			//�˿�
	uint16 ClientFlag;


	MYSQL Mysql;				//MySQL�ٷ���װ�Ķ���
};


