// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPS_Shooter/FPS_Player.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPS_Player() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	FPS_SHOOTER_API UClass* Z_Construct_UClass_AFPS_Player();
	FPS_SHOOTER_API UClass* Z_Construct_UClass_AFPS_Player_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FPS_Shooter();
// End Cross Module References
	void AFPS_Player::StaticRegisterNativesAFPS_Player()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFPS_Player);
	UClass* Z_Construct_UClass_AFPS_Player_NoRegister()
	{
		return AFPS_Player::StaticClass();
	}
	struct Z_Construct_UClass_AFPS_Player_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraFPS_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraFPS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HandsMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HandsMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerMappingInput_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerMappingInput;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovementAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementAction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPS_Player_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_FPS_Shooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_Player_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPS_Player_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FPS_Player.h" },
		{ "ModuleRelativePath", "FPS_Player.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPS_Player_Statics::NewProp_CameraFPS_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Camera Character//\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPS_Player.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera Character" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPS_Player_Statics::NewProp_CameraFPS = { "CameraFPS", nullptr, (EPropertyFlags)0x001000000009001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPS_Player, CameraFPS), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_Player_Statics::NewProp_CameraFPS_MetaData), Z_Construct_UClass_AFPS_Player_Statics::NewProp_CameraFPS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPS_Player_Statics::NewProp_HandsMesh_MetaData[] = {
		{ "Category", "Body" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Mesh Hands//\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPS_Player.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mesh Hands" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPS_Player_Statics::NewProp_HandsMesh = { "HandsMesh", nullptr, (EPropertyFlags)0x001000000009001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPS_Player, HandsMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_Player_Statics::NewProp_HandsMesh_MetaData), Z_Construct_UClass_AFPS_Player_Statics::NewProp_HandsMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPS_Player_Statics::NewProp_PlayerMappingInput_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Mapping Input//\n" },
#endif
		{ "ModuleRelativePath", "FPS_Player.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mapping Input" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPS_Player_Statics::NewProp_PlayerMappingInput = { "PlayerMappingInput", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPS_Player, PlayerMappingInput), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_Player_Statics::NewProp_PlayerMappingInput_MetaData), Z_Construct_UClass_AFPS_Player_Statics::NewProp_PlayerMappingInput_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPS_Player_Statics::NewProp_MovementAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Actions player input//\n" },
#endif
		{ "ModuleRelativePath", "FPS_Player.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Actions player input" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPS_Player_Statics::NewProp_MovementAction = { "MovementAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPS_Player, MovementAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_Player_Statics::NewProp_MovementAction_MetaData), Z_Construct_UClass_AFPS_Player_Statics::NewProp_MovementAction_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFPS_Player_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPS_Player_Statics::NewProp_CameraFPS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPS_Player_Statics::NewProp_HandsMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPS_Player_Statics::NewProp_PlayerMappingInput,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPS_Player_Statics::NewProp_MovementAction,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPS_Player_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPS_Player>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFPS_Player_Statics::ClassParams = {
		&AFPS_Player::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFPS_Player_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_Player_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_Player_Statics::Class_MetaDataParams), Z_Construct_UClass_AFPS_Player_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_Player_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AFPS_Player()
	{
		if (!Z_Registration_Info_UClass_AFPS_Player.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFPS_Player.OuterSingleton, Z_Construct_UClass_AFPS_Player_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFPS_Player.OuterSingleton;
	}
	template<> FPS_SHOOTER_API UClass* StaticClass<AFPS_Player>()
	{
		return AFPS_Player::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPS_Player);
	AFPS_Player::~AFPS_Player() {}
	struct Z_CompiledInDeferFile_FID_Users_celso_Documents_Projetos_Pessoais_LidioRepository_GitHub_FPS_Shooter_Unreal_FPS_Shooter_Source_FPS_Shooter_FPS_Player_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_celso_Documents_Projetos_Pessoais_LidioRepository_GitHub_FPS_Shooter_Unreal_FPS_Shooter_Source_FPS_Shooter_FPS_Player_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFPS_Player, AFPS_Player::StaticClass, TEXT("AFPS_Player"), &Z_Registration_Info_UClass_AFPS_Player, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFPS_Player), 308319825U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_celso_Documents_Projetos_Pessoais_LidioRepository_GitHub_FPS_Shooter_Unreal_FPS_Shooter_Source_FPS_Shooter_FPS_Player_h_2430994354(TEXT("/Script/FPS_Shooter"),
		Z_CompiledInDeferFile_FID_Users_celso_Documents_Projetos_Pessoais_LidioRepository_GitHub_FPS_Shooter_Unreal_FPS_Shooter_Source_FPS_Shooter_FPS_Player_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_celso_Documents_Projetos_Pessoais_LidioRepository_GitHub_FPS_Shooter_Unreal_FPS_Shooter_Source_FPS_Shooter_FPS_Player_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
