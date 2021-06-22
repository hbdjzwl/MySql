// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Core/SimpleMysqlLink.h"
#include "SimpleMySQLibrary.generated.h"

class USimpleMysqlObject;

UCLASS(meta = (BlueprintThreadSafe, ScriptName = "MySQLLibrary"))
class SIMPLEMYSQL_API USimpleMySQLLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (Keywords = "SimpleMySQL sample test testing"), Category = "SimpleMySQLTesting")
		static void MySqlMain();

	//Mysql�������
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", Category = "SimpleMySQL"))
		static USimpleMysqlObject* CreateMysqlObject(
			UObject* WorldContextObject,
			const FString &InUser,
			const FString &InHost,
			const FString &InPawd,
			const FString &InDB,
			const int32  InPort,
			const TArray<ESimpleClientFlags>& InClientFlag,
			const FString &Unix_Socket = TEXT("")
			);

	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool QueryLink(USimpleMysqlObject *Object, const FString &SQL, FString &ErrMesg);

	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool QueryLinkStoreResult(USimpleMysqlObject *Object, const FString& SQL, TArray<FSimpleMysqlResult> &Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug);

	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool QueryLinkUseResult(USimpleMysqlObject *Object, const FString& SQL, TArray<FSimpleMysqlResult> &Results, FString& ErrMesg, const FSimpleMysqlDebugResult& Debug);

	//�������ݿ�DB
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool CreateDataBase(USimpleMysqlObject *Object, const FString &DataBaseName, EMysqlCharset Charset, FString &ErrorMsg);

	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool CreateAndSelectDataBase(USimpleMysqlObject *Object, const FString &DataBaseName, EMysqlCharset Charset, FString &ErrorMsg);

	//ɾ�����ݿ�DB
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool DropDataBase(USimpleMysqlObject *Object, const FString &DataBaseName, FString &ErrorMsg);

	//������
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool CreateTable(USimpleMysqlObject *Object, const FString &TableName, const TMap<FString, FMysqlFieldType> &InFields, const TArray<FString> &InPrimaryKeys, const FMysqlCreateTableParam &Param, FString &ErrorMsg);

// 	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
// 	static bool DropTemporaryTable(USimpleMysqlObject* Object, const FString& TemporaryTableName, FString& ErrorMsg);

	//����ȫ��ɾ�� �ͷ��ڴ� ��֧�ֻع� Innodb �� MyISAM ȫ�����
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool DropTable(USimpleMysqlObject* Object, const FString& TableName, FString& ErrorMsg);

	//����� �ͷ��ڴ� ��֧�ֻع� Innodb �� MyISAM ȫ�����
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool TruncateTable(USimpleMysqlObject* Object, const FString& TableName, FString& ErrorMsg);

	//�ɻع�����û���������ͷŵ��ڴ�
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool DeleteFromTable(USimpleMysqlObject* Object, const FString& TableName, FString& ErrorMsg);

	//���� DeleteFromTable ����ɾ�����ͷ��ڴ�
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool OptimiseTable(USimpleMysqlObject* Object, const FString& TableName, FString& ErrorMsg);

	//����ɾ����
 	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool DeleteFromTableWhereData(USimpleMysqlObject* Object, const FString& TableName, const FString& Condition, FString& ErrorMsg);

	//ѡ���
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool SelectNewDB(USimpleMysqlObject *Object, const FString &NewDB, FString &ErrMesg);

	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool GetStoreResult(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult> &Results, const FSimpleMysqlDebugResult& Debug, FString &ErrMesg);
	
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool GetUseResult(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult> &Results, const FSimpleMysqlDebugResult& Debug,FString &ErrMesg);

	//��ӡ�����
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool PrintResult(USimpleMysqlObject *Object, const TArray<FSimpleMysqlResult>& Results, bool bPrintToScreen = true, bool bPrintToLog = true);

	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool GetSelectTableDataSR(USimpleMysqlObject* Object, const FString& TableName, const TArray<FString>& InFields, const FSimpleMysqlQueryParameters& QueryParam, TArray<FSimpleMysqlResult>& Results, FString& ErrorMes, const FSimpleMysqlDebugResult& Debug);
	
	UFUNCTION(BlueprintCallable, meta = (Category = "SimpleMySQL"))
	static bool GetSelectTableDataUR(USimpleMysqlObject* Object, const FString& TableName, const TArray<FString>& InFields, const FSimpleMysqlQueryParameters& QueryParam, TArray<FSimpleMysqlResult>& Results, FString& ErrorMes, const FSimpleMysqlDebugResult& Debug);
};